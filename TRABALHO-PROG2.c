#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char nomeFederacao[50];
    char siglaFederacao[5];
    char siglaAfiliados[50][5];


} TipoFederacao;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMAÇOES DAS FEDERAÇÕES

typedef struct{
    char nomePartido[50];
    char siglaPartido[5];
} TipoPartido;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMAÇÕES DOS PARTIDOS

typedef struct{
    char nomeCandidato[50];
    int idade;
    int digitos[5];
    TipoPartido partido;

} TipoCandidato;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMÇOES DE CADA CANDIDATO
 




void imprimeMenuCadastro(){
    /* Função responsável por imprimir o menu de cadastros
    */

    printf("\n* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* | c | a | d | a | s | t | r | o | s | *\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* (1) Cadastrar novo partido            *\n");
    printf("*                                       *\n");
    printf("* (2) Cadastrar novo candidato          *\n");
    printf("*                                       *\n");
    printf("* (3) Registrar nova Federacao          *\n");
    printf("*                                       *\n");
    printf("* (4) Encerrar etapa de cadastros       *\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
}


void imprimeMenuVotacao(){
    /* Função responsável por imprimir o menu de votação
    */
    
    printf("* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("*     | v | o | t | a | c | a | o |     *\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* (1) Registrar novo voto               *\n");
    printf("*                                       *\n");
    printf("* (2) encerrar votacao                  *\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
}


int caracteresValidos(char aux[]){
    /* A função verifica se a string inserida possui caracteres inválidos.
    Caracteres válidos são letras maiúsculas e minúsculas.

    Parâmetros:
        char aux[]: String;
    Retorno (int):
        1: Há caracteres inválidos;
        0: Não há caracteres inválidos;
    */
    int i;
    for (i=0; i < (int)(strlen(aux)); i++){
        //ENTRA NO IF SE O CARACTERE NÃO CORRESPONDER A UMA LETRA DE ACORDO COM A TABELA ASCII
        if (((int)(aux[i]) < 65 && (int)(aux[i]) > 90) || ((int)(aux[i]) < 97 && (int)(aux[i]) > 122)){
            return 1; 
        }       
    }
    return 0;
}

int jaExistePartido(int* n, char aux[], TipoPartido* ptr, char tipo[]){
    int i;
    for(i=0; i<*n; i++){   //VERIFICA SE O PARTIDO JÁ EXISTE
        if((strcmp(tipo, "nome")) == 0){
            if((strcmp(aux, ptr[i].nomePartido)) == 0){   //ENTRA SE O PARTIDO JÁ EXISTIR
                return 1;
            }
        }else{
            if((strcmp(aux, ptr[i].siglaPartido)) == 0){   //ENTRA SE A SIGLA JÁ EXISTIR
                return 1;
            }
        }
    }
    return 0;
}

int cadastraPartido(TipoPartido *ptr , int* nPartidos, int* tam){
    // FUNÇÃO RESPONSÁVEL POR CADASTRAR PARTIDOS, VAI RECEBER O VETOR DO ´'TIPOPARTIDO' E UMA POSIÇÃO 
    int flag=1;
    char partidoAux[50], siglaAux[5];
    if (nPartidos >= tam){
        *tam = (*tam)*2;
        ptr = (TipoPartido *) realloc(ptr,(*tam)*sizeof(TipoPartido));
    }
    while(flag){
        printf("\nDigite o nome do partido: ");
        //ENTRA NO IF SE A LEITURA FOR VÁLIDA (CARACTERES)
        if((scanf("%s", partidoAux)) > 0){
            if (caracteresValidos(partidoAux) == 0){   //VERIFICA SE TODOS OS CARACTERES SÃO VÁLIDOS
                if (jaExistePartido(nPartidos, partidoAux, ptr, "nome") == 1){   //VERIFICA SE O PARTIDO JÁ EXISTE
                    printf("\nPartido já existente.\n");
                    return 1;
                }else{
                    flag = 0;
                }
            }else{
                printf("\nCaracteres invalidos. Tente novamente!");
            }
        }else{
            printf("\nEntrada inálida. Tente novamente!");
        }
    }
    flag =1;
    while(flag){
        printf("\nDigite a sigla do partido (máximo 5 caracteres): ");
        if(scanf("%s", siglaAux) > 0){
            if (caracteresValidos(siglaAux) == 0){
                if (jaExistePartido(nPartidos, siglaAux, ptr, "sigla") == 1){
                    printf("\nSigla já existente. Tente novamente!");
                }else{
                    flag = 0;
                }
            }else{
                printf("\nCaracteres invalidos. Tente novamente!");
            }
        }else{
            printf("\nEntrada inálida. Tente novamente!");
        }                  
    }

    strcpy(ptr[*nPartidos].nomePartido, partidoAux);
    strcpy(ptr[*nPartidos].siglaPartido, siglaAux);
    *nPartidos = *nPartidos +1;
    return 0;   
   
}    



int main(){

    int opcao, nPartidos=0, flag=1, tam = 50;
    TipoPartido *partidos = NULL;
    TipoFederacao *federacoes = NULL;
    TipoCandidato *candidatos = NULL;
    candidatos = (TipoCandidato *) malloc(tam*sizeof(TipoCandidato));
    partidos = (TipoPartido *) malloc(tam*sizeof(TipoPartido));
    federacoes = (TipoFederacao *) malloc(tam*sizeof(TipoFederacao));

//     //CADASTROS

    while (flag){
//     //O WHILE DEVE ENCERRAR QUANDO O USUARIO ESCOLHER O OPÇÃO 4 'ENCERRAR ETAPA DE CADASTROS'
        imprimeMenuCadastro(); //FUNÇÃO QUE IMPRIME O MENU
        printf("\nSelecione uma opcao: ");
        if ((scanf("%d", &opcao)) > 0){
            switch (opcao){
                case 1:
                    if((cadastraPartido(partidos, &nPartidos, &tam)) == 0){
                        printf("\nPartido cadastrado com sucesso!\n");
                    }else{
                        printf("\nO procedimento falhou.\n");
                    }
                    break;
                case 2:
                    printf("2");
                    // cadastraCandidato();
                    break;
                case 3:
                    printf("3");
                    // registraFederacao();
                    break;
                case 4:
                    printf("4");
                    flag = 0;
                    break;
                default:
                    printf("\nOpcao invalida. Tente novamente!\n");
                    //MENSAGEM DE ERRO
                    //SOLICITAR A OPÇÃO NOVAMENTE
                    //CASO NECESSÁRIO, AJEITAR LOOP PARA ISSO SER POSSIVEL
                    break;
            }
        }else{
            printf("\nOpcao invalida. Tente novamente!\n");
            getchar();
        }

        
    }

// //VOTAÇÃO
//     flag = 1;    
//     while (flag){
//         imprimeMenuVotacao();

//         printf("Selecione uma opção: ");
//         scanf("%d", &opcao);

//         switch (opcao){
//         case 1:
//             registraNovoVoto();
//             break;
//         case 2:
//             flag = 0;
//             break;
//         default:
//             //MENSAGEM DE ERRO
//             //SOLICITAR A OPÇÃO NOVAMENTE
//             //CASO NECESSÁRIO, AJEITAR LOOP PARA ISSO SER POSSÍVEL
//         }
        
//     }

// // RELATORIO
//     //ADICIONAR PASSOS ANTERIORES NECESSÁRIOS
//     imprimeRelatorio();
//     //CONTÉM FUNÇÕES DESCRITAS NA PLANILHA

    free(candidatos);
    free(partidos);
    free(federacoes);
    return 0;
}
