/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    char nome[30];
    char end[40];
    int num;
};
typedef struct pessoa Pessoa; //Apenas foi renomeado a nomeclatura struct pessoa para Pessoa.


// Função Ordenação Bolha (estude isso por conta própria kkkk)
// Parâmetros: v (Ponteiro para struct pessoa), n (Tamanho do Vetor).
// Objetivo: Esta função tem como objetivo ordenar o Vetor de Pessoas em ordem alfabetica
void bubble_sort(Pessoa *v, int n){
    int i, j;
    Pessoa aux;
    
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            
            //Obs 1: strcmp é uma função especifica da biblioteca string.h, ela tem como objetivo comparar duas string e retorna 0 se forem iguais caso contrário retorna um número diferente de 0 se uma é "maior" que a outra
            //Obs 2: strcpy é uma função que cópia o conteúdo de uma string e adiciona na outra string.
            if(strcmp(v[j+1].nome, v[j].nome) < 0){
                strcpy(aux.nome, v[j+1].nome);
                strcpy(v[j+1].nome, v[j].nome);
                strcpy(v[j].nome, aux.nome);
                
                strcpy(aux.end, v[j+1].end);
                strcpy(v[j+1].end, v[j].end);
                strcpy(v[j].end, aux.end);
                
                aux.num = v[j+1].num;
                v[j+1].num = v[j].num;
                v[j].num = aux.num;
            }
        }
    }
}

int main(){
    
    int nPessoa = 5;
    int i;
    
    Pessoa a[nPessoa];
    
    //Nota: Foi utilizado %[^\n]s no scanf para poder pegar os espaçamentos de uma string, normalmente não pega.
    for(i=0; i<nPessoa; i++){
        printf("Digite o nome da %dª pessoa: ", i+1);
        scanf(" %[^\n]s", a[i].nome);
        fflush(stdin);
        
        printf("Digite o endereco da %dª pessoa: ", i+1);
        scanf(" %[^\n]s", a[i].end);
        fflush(stdin);
        
        printf("Digite o numero da %dª pessoa: ", i+1);
        scanf("%d", &a[i].num);
        
        system("clear"); //Limpa a tela em máquinas Linux, no Windows utilize system("cls")
    }
    
    //Chama a função Ordenação Bolha
    bubble_sort(a, nPessoa);
    
    
    //Imprime os nomes das pessoas em ordem alfabetica
    printf("\n***** Nomes das Pessoas *****\n");
    for(i=0; i<nPessoa; i++){
        printf("---> %s\n", a[i].nome);
    }

    return 0;
}
