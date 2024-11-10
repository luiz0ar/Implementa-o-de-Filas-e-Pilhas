#include <stdio.h>
#define TAMANHO 5

typedef struct {
    int itens[TAMANHO];
    int inicio, fim;
} Fila;

void inicializarFila(Fila *fila) {
    fila->inicio = -1;
    fila->fim = -1;
}

int estaCheia(Fila *fila) {
    return ((fila->fim + 1) % TAMANHO == fila->inicio);
}

int estaVazia(Fila *fila) {
    return (fila->inicio == -1);
}

void enfileirar(Fila *fila, int valor) {
    if (estaCheia(fila)) {
        printf("Fila cheia!\n");
    } else {
        if (estaVazia(fila)) {
            fila->inicio = 0;
        }
        fila->fim = (fila->fim + 1) % TAMANHO;
        fila->itens[fila->fim] = valor;
        printf("Enfileirado: %d\n", valor);
    }
}

int desenfileirar(Fila *fila) {
    int valor;
    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        valor = fila->itens[fila->inicio];
        if (fila->inicio == fila->fim) {
            fila->inicio = fila->fim = -1;
        } else {
            fila->inicio = (fila->inicio + 1) % TAMANHO;
        }
    }
    return valor;
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);
    enfileirar(&fila, 40);
    enfileirar(&fila, 50);

    printf("Desenfileirado: %d\n", desenfileirar(&fila));

    enfileirar(&fila, 60);

    return 0;
}
