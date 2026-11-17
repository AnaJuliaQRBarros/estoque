#include <stdio.h>
#include "produto.h"

int main(){
    Produto* p = criar_produto(101, "Batata", 14.50, -1);
    if (p)
        printf("%s : R$ %.2f\n", p->nome, p->preco);
    else
        puts("Produto não cadastrado");

    return 0;
}

// gcc produto.c main.c -o main