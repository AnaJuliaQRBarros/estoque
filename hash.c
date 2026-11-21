#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int funcaohash(int codigo){
    return codigo % TAM;
}

tabelahash* criar_tabelahash(){
    tabelahash* hash=(tabelahash*) malloc (sizeof(tabelahash));
    if (hash != NULL){
        for(int i=0;i<TAM;i++){
            hash->tabela[i]=NULL;
        }
    }
    return hash;
}

int inserirhash(tabelahash* hash,Produto* p){
    if (hash == NULL || p == NULL){
        return 0;
    } 
    int indice = funcaohash(p->codigo);

    Nohash* novo=(Nohash*) malloc (sizeof(Nohash));
    if (novo==NULL){
        return 0;
    }
    novo->produto=p;
    novo->proximo=hash->tabela[indice];
    hash->tabela[indice]=novo;

    return 1;
}

Produto* buscarhash(tabelahash *hash,int codigo){
    int indice=funcaohash(codigo);

    Nohash *atual=hash->tabela[indice];
    while(atual!=NULL){
        if(atual->produto->codigo==codigo){
            return atual->produto;
        }
        atual=atual->proximo;
    }
    return NULL;
}

void destruir_hash(tabelahash *hash) {
    if (hash == NULL) return;

    for (int i = 0; i < TAM; i++) {
        Nohash *atual = hash->tabela[i];
        while (atual != NULL) {
            Nohash *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(hash);
}

int removerhash(tabelahash *hash, int codigo) {
    if (hash == NULL){
        return 0;
    } 
    int indice = funcaohash(codigo);
    Nohash *atual = hash->tabela[indice];
    Nohash *anterior = NULL;

    while (atual != NULL) {
        if (atual->produto->codigo == codigo) {
            if (anterior == NULL) {
                hash->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0;
}