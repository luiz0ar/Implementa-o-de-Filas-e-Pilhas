#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int estaVazia(Fila *fila) {
    return (fila->inicio == NULL);
}

void enfileirar(Fila *fila, int valor) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro de memória!\n");
        return;
    }

    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novoNo;
    } else {
        fila->fim->proximo = novoNo;
    }
    fila->fim = novoNo;
    printf("Enfileirado: %d\n", valor);
}

int desenfileirar(Fila *fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    }

    int valor = fila->inicio->valor;
    No *temp = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);
    return valor;
}

int consultarInicio(Fila *fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return fila->inicio->valor;
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);

    printf("Início da fila: %d\n", consultarInicio(&fila));

    desenfileirar(&fila);
    printf("Início após desenfileirar: %d\n", consultarInicio(&fila));

    return 0;
}
