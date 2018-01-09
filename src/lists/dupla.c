#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int n;
    struct list *ant, *prox;
}list, *plist;

void initialize(plist *y);
plist* find(plist l, int x);
int insert(plist *l, int x);
int delete(plist *l, int x);
void print(plist l);

int main() {
    plist head, *duo;
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
                duo = find(head, num);
                if (duo[1])
                    printf("%d\n", duo[1]->n);
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

plist* find(plist l, int x) {
    plist *duo;

    for(; (l) && (l->n != x); l->ant = l, l = l->prox);
    duo[0] = l->ant;
    duo[1] = l;

    return duo;
}

int insert(plist *l, int x) {
    plist novo, *t;
    novo = (plist)malloc(sizeof(list));

    if (!(*l)){
        if (novo){
            novo->n = x;
            novo->prox = NULL;
            novo->ant = NULL;
            *l = novo;
            return 1;
        }
    }
    else {
        t = find(*l, x);
        if (!(t[1])){ //se não for nulo é pq ja ta la então passa
            if (novo){
                novo->n = x;
                novo->prox = NULL;
                novo->ant = t[0];
                t[0]->prox = novo;
                return 1;
            }
        }
        return 0;
    }
}

int delete(plist *l, int x) {
    plist *t;

    t = find(*l, x);
    if (t[1]){
        if (t[0]){
            if (t[1]->prox->ant)
                t[1]->prox->ant = t[1]->ant;
            t[1]->ant->prox = t[1]->prox;
        }
        else{
            *l = t[1]->prox;
            (*l)->ant = NULL;
        }
        free(t[1]);
        return 1;
    }

    return 0;
}

void print(plist l) {
    for(; (l); l = l->prox){
        printf("end %ld:[%ld <- %d -> %ld]\n", (long int)l, (long int)l->ant, l->n, (long int)l->prox);
    }
}
