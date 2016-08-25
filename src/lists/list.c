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
int menor(list *l);
int nImpares(list *l);
double media(list *l);
int somaValores(list *l);
int somaQuadrados(list *l);

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
    	    case 'm':
                printf("%d\n",menor(head));
                //printf("passou aki print\n");
                break;
            case 'o': // o = odd (impar)
                printf("%d\n", nImpares(head));
                break;
            case 'k': // excluir kesimo numero
                scanf(" %d\n", &num);
                printf("%d\n", eliminaKEsimo(head, &num));
                break;
            case 'k': // excluir kesimo numero
                scanf(" %d\n", &num);
                printf("%d\n", eliminaKEsimo(head, &num));
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
    // tuple t;
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
        // t = find(*l, x);
        plist p;
        for (p=*l; p->prox; p=p->prox);
        // if (!(t.desired)){
            if (novo){
                novo->n = x;
                novo->prox = NULL;

                p->prox = novo;
                return 1;
            }
        // }
        return 0;
    }

}
int delete(plist *l, int x) {
    plist ant, p;

    // t = find(*l, x);
    for(ant = NULL, p = *l; (p) && (p->n != x); ant = p, p = p->prox);

    if (p){
        if (ant)
            ant->prox = p->prox;
        else
            *l = p->prox;
        free(p);
        return 1;
    }

    return 0;
}

int eliminaKEsimo(plist *l, int k){
    int i;
    plist ant, p;
    for (i = 0, ant=NULL, p=*l; i < k && (p); ++i, ant=p, p = p->prox);
        if (p){
            if (ant)
                ant->prox = p->prox;
            else
                *l = p->prox;
            free(p);
            return 1;
        }

    return 0;
}

int retiraMaior(plist *l){
    int i;
    plist p, ant, antMaior, maior = l;

    for(ant = NULL, antMaior  = NULL, p = *l; (p); ant = p, p=p->prox)
        if (p->n > maior->n){
            antMaior = ant;
            maior = p;
        }

    if (p){
        if(antMaior)
            antMaior->prox = maior->prox;
        else
            *l = maior->prox;
        free(maior);
        return 1;
    }

    return 0;
}

void print(plist l) {
    for(; (l); l = l->prox){
        printf("endereço %ld:[%d -> %ld]\n", (long int)l, l->n, (long int)l->prox);
    }
}

int menor(plist l){
	int menor = l->n;
	for(; (l); l = l->prox)
		if(l->n < menor)
			menor = l->n;
	return menor;
}

int nImpares(plist l){
    int soma=0;
    for (; (l); soma += (l->n%2), l= l->prox);
    return soma;
}

int somaValores(plist l){
    int soma=0;
    for (;(l); soma+=l->n, l = l->prox);
        return soma;
}

int somaQuadradosValores(plist l){
    int soma=0;
    for (;(l); soma+=(l->n)*2, l = l->prox);
        return soma;
}
