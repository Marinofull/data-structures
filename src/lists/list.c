#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int n;
    struct list *prox;
}list, *plist;

void initialize(plist *y);
plist find(plist l, int x);
int insert(plist *l, int x);
int delete(plist *l, int x);
void print(plist l);

int main() {
    plist head;
    char op;
    int num;

    for(;;){
        //printf("type")
        scanf("%c\n", &op);
        switch(op){
            case 'n':
                //initialize
                initialize(&head);
            break;
            case 's':
                scanf("%d\n", &num);
                find(head, num);
                //search
            break;
            case 'i':
                scanf("%d\n", &num);
                insert(&head, num);
                //insert
            break;
            case 'd':
                scanf("%d\n", &num);
                delete(&head, num);
                //delete
            break;
            case 'e':
                //exit
                return 0;
            break;
            default:
                //invalid op
                //printf("op invalid\n");
                break;
        }
    }
}

void initialize(plist *y) {
    *y = NULL;
}

plist find(plist l, int x) {
    for(; l && l->n != x; l=l->prox);
    return l;
}

int insert(plist *l, int x) {
    return 0;
}

int delete(plist *l, int x) {
    return 0;
}

void print(plist l) {
}
