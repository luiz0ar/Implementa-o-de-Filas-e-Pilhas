#include <stdio.h>
#define TAMANHO 5

typedef struct {
    int itens[TAMANHO];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int estaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

int estaCheia(Pilha *pilha) {
    return (pilha->topo == TAMANHO - 1);
}

void empilhar(Pilha *pilha, int valor) {
    if (estaCheia(pilha)) {
        printf("Pilha cheia!\n");
    } else {
        pilha->topo++;
        pilha->itens[pilha->topo] = valor;
        printf("Empilhado: %d\n", valor);
    }
}

int desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        int valor = pilha->itens[pilha->topo];
        pilha->topo--;
        return valor;
    }
}

int consultarTopo(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha->itens[pilha->topo];
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);

    printf("Topo da pilha: %d\n", consultarTopo(&pilha));

    desempilhar(&pilha);
    printf("Topo após desempilhar: %d\n", consultarTopo(&pilha));

    return 0;
}
