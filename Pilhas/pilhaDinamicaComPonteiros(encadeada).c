#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int estaVazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

void empilhar(Pilha *pilha, int valor) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro de memória!\n");
        return;
    }
    novoNo->valor = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    printf("Empilhado: %d\n", valor);
}

int desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        No *temp = pilha->topo;
        int valor = temp->valor;
        pilha->topo = temp->proximo;
        free(temp);
        return valor;
    }
}

int consultarTopo(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha->topo->valor;
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
