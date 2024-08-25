#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TipoFederação{
    char nomeFederação[50];
    char siglaFederação[5];


} TipoFederação;

// CRIA UM TIPO PARA ARMAZENAR AS INFORMAÇOES DAS FEDERAÇÕES

typedef struct TipoCandidato{
    char nomeCandidato[50];
    int idade;
    int digitos;

} TipoCandidato;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMÇOES DE CADA CANDIDATO
 
typedef struct TipoPartido{
    char nomePartido[50];
    char sigla[5];
    TipoCandidato candidato;
    TipoFederação federação;
} TipoPartido;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMAÇÕES DOS PARTIDOS
// OS OUTROS DOIS TIPOS A SEGUR SÃO SUB-TIPOS DESTE



int main(){
    int opção,Npartidos,i=0;
    TipoPartido *partidos = NULL;
    
    // DECLARA VARIAVEIS DE INTEIROS : opção(opção inserida pelo usuario), Npartidos(Quantidade total de partidos),i(variavel contadora)
    // DECLARA UM PONTEIRO DO TIPOPARTIDOS  PARA ARMAZENAR CADA PARTIDO BEM COMO SEUS RESPECTIVOS CANDIDATOS

    printf("Digite a quantidade de partidos:");
    scanf("%d", &Npartidos);
    partidos = (TipoPartidos *)malloc(Npartidos * sizeof(TipoPartidos));
    // ALOCA UM VETOR DO TIPOPARTIDOS DE TAMANHO INSERIDO PELO USUARIO(ESSA ETAPA DO CODIGO É PROVISÓRIA)

    if (partidos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }


    while (1){
        // O LOOPING SÓ IRA SE ENCERRAR QUANDO A OPÇÃO 'ENCERRAR VOTAÇÃO' FOR SELECIONADA


        printf("Menu de Cadastros\n");
        printf("Cadastro de Partidos - 1\n");
        printf("Cadastro de Candidatos - 2\n");
        printf("Registro de Federações - 3\n");
        printf("Avançar para Votação - 4\n");
        printf("Selecione uma opção: ");
        // MENU DE CADASTROS INICIAL

        scanf("%d", &opção);
        // USUARIO SELECIONA OPÇÃO


        if (opção == 1){
            CadastraPartidos(vet, i);
            // NESTA OPÇÃO SERÁ CHAMADA UMA FUNÇÃO QUE VAI RECEBER AS INFORMAÇÕES DO PARTIDO E ARMAZENAR EM UMA POSIÇÃO DO VETOR
            // CADA PARTIDO TERÁ UMA POSIÇÃO DO VETOR

        }
        if (opção == 2){
            CadastraCandidatos(vet , i);
            // NESTA OPÇÃO SERÁ CHAMADA UMA FUNÇÃO QUE VAI RECEBER AS INFORMAÇÕES DO CANDIDATO
            // EM SEGUIDA SERÁ VERIFICADO QUAL SEU PARTIDO E SE ESTE PARTIDO EXISTE
            // POR FIM ARMAZENA AS INFORMAÇÕES DO CANDIDATO NA POSIÇÃO DO VETOR CORRESPONDENTE AO PARTIDO 
        }
        if (opção == 3){
            RegistraFederação(vet , i);
            // NESTA OPÇAO SERÁ CHAMADA UMA FUNÇÃO QUE REGISTRA UMA FEDERAÇÃO
            // A FEDERÇÃO DE MAIS DE UM PARTIDO SERÁ CONSIDERADA COMO UM UNICO PARTIDO POLITICO 

        }


        if ( opção == 4){
            // NESTA OPÇÃO O USUÁRIO VAI PODER INSERIR O VOTO E ENCERRAR A VOTAÇÃO
            while (1){
                printf("Menu de Votação:\n");
                printf("Registrar um novo voto - 1\n");
                printf("Encerrar votação - 2\n");
                printf("Selecione uma opção: ");
                scanf("%d", &opção);

                if  ( opção == 1){
                    RegistrarVoto();
                }
                if (opção == 2){
                    EncerrarVotação();

                }
            }  
        }
        
    }
        
    free(partidos);
    return 0;
}