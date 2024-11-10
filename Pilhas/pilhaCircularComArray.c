#include <stdio.h>
#define TAMANHO 5

typedef struct {
    int itens[TAMANHO];
    int topo;
} PilhaCircular;

void inicializarPilha(PilhaCircular *pilha) {
    pilha->topo = -1;
}

int estaCheia(PilhaCircular *pilha) {
    return ((pilha->topo + 1) % TAMANHO == 0 && pilha->itens[0] != -1);
}

int estaVazia(PilhaCircular *pilha) {
    return (pilha->topo == -1);
}

void empilhar(PilhaCircular *pilha, int valor) {
    if (estaCheia(pilha)) {
        printf("Pilha cheia!\n");
    } else {
        pilha->topo = (pilha->topo + 1) % TAMANHO;
        pilha->itens[pilha->topo] = valor;
        printf("Empilhado: %d\n", valor);
    }
}

int desempilhar(PilhaCircular *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        int valor = pilha->itens[pilha->topo];
        pilha->itens[pilha->topo] = -1; 
        pilha->topo = (pilha->topo - 1 + TAMANHO) % TAMANHO;
        return valor;
    }
}

int consultarTopo(PilhaCircular *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha->itens[pilha->topo];
    }
}

int main() {
    PilhaCircular pilha;
    inicializarPilha(&pilha);

    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);

    printf("Topo da pilha: %d\n", consultarTopo(&pilha));

    desempilhar(&pilha);
    printf("Topo após desempilhar: %d\n", consultarTopo(&pilha));

    return 0;
}
