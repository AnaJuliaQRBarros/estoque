
#ifndef HASH_H
#define HASH_H

#include "produto.h"

/*Essa struct vai ser usada para o tratamento de colisões por 
lista encadeada*/

typedef struct Nohash{
    Produto* produto;
    struct Nohash *proximo;
}Nohash;

//Aqui a gente faz a tabela hash em si

#define TAM 101

tabelahash* criar_tabelahash();
int funcaohash(int codigo);

int inserirhash(tabelahash* hash,int codigo);
Produto* buscarhash(tabelahash* hash,int codigo);
void destruir_hash(tabelahash* hash);

#endif