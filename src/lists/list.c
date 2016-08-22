#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int n;
    struct list *prox;
}list, *plist;

typedef struct tuple {
    plist ant, desired;
}tuple;

void initialize(plist *y);
tuple find(plist l, int x);
int insert(plist *l, int x);
int delete(plist *l, int x);
void print(plist l);

int main() {
    plist head;
    tuple result;
    char op;
    int num;

    for(;;){
        //printf("type")
        //printf("passou aki antes da op\n");
        scanf(" %c", &op);
        //printf("ai o %c\n", op);
        switch(op){
            case 'n':
                //initialize
                initialize(&head);
                //printf("passou aki inicializou\n");
                break;
            case 's':
                scanf(" %d\n", &num);
                //printf("passou aki leu\n");
                result = find(head, num);
                if (result.desired)
                    printf("%d\n", result.desired->n);
                //search
                //printf("passou aki acho\n");
                break;
            case 'i':
                scanf(" %d\n", &num);
                //printf("passou aki leu\n");
                num = insert(&head, num);
                //insert
                //printf("passou aki inseriu\n");
                break;
            case 'd':
                scanf(" %d\n", &num);
                num = delete(&head, num);
                //delete
                break;
            case 'p':
                print(head);
                //printf("passou aki print\n");
                break;
            case 'e':
                //printf("passou aki exit\n");
                //exit
                return 0;
            default:
                //invalid op
                break;
        }
    }
}

void initialize(plist *y) {
    *y = NULL;
}

tuple find(plist l, int x) {
    plist ant;
    tuple result;

    for(ant = NULL; (l) && (l->n != x); ant = l, l = l->prox);
    result.ant = ant;
    result.desired = l;

    return result;
}

int insert(plist *l, int x) {
    tuple t;
    plist novo;
    novo = (plist)malloc(sizeof(list));

    if (!(*l)){
        if (novo){
            novo->n = x;
            novo->prox = NULL;
            *l = novo;
            return 1;
        }
    }
    else {
        t = find(*l, x);
        if (!(t.desired)){
            if (novo){
                novo->n = x;
                novo->prox = NULL;
                t.ant->prox = novo;
                return 1;
            }
        }
        return 0;
    }

}
int delete(plist *l, int x) {
    tuple t;

    t = find(*l, x);
    if (t.desired){
        t.ant->prox = t.desired->prox;
        free(t.desired);
        return 1;
    }

    return 0;
}

void print(plist l) {
    for(; (l); l = l->prox){
        printf("%ld:[%d -> %ld]\n", (long int)l, l->n, (long int)l->prox);
    }
}
