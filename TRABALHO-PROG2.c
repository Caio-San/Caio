#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


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
    printf("* (2) Encerrar votacao                  *\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
}

void imprimeMenuConfirmacao(){
    /* Função responsável por imprimir o menu de confirmação do 
    */

    printf("* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* | c | o | n | f | i | r | m | a | r | *\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* (1) Confirmar voto                    *\n");
    printf("*                                       *\n");
    printf("* (2) Retornar                          *\n");
    printf("*                                       *\n");
    printf("* (3) Votar em branco                   *\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");

}

int caracteresValidos(char aux[]){
    /* A função verifica se a string inserida possui caracteres inválidos.
    Caracteres válidos são letras maiúsculas e minúsculas.

    Parâmetros:
        char aux[]: String a ser verificada;
    Retorno (int):
        1: Há caracteres inválidos;
        0: Não há caracteres inválidos;
    */
    int i;
    for (i=0; i < (int)(strlen(aux)); i++){
        //ENTRA NO IF SE O CARACTERE NÃO CORRESPONDER A UMA LETRA DE ACORDO COM A TABELA ASCII
        if (((int)(aux[i]) < 65 && (int)(aux[i]) > 90) || ((int)(aux[i]) < 97 && (int)(aux[i]) > 122) || (int)(aux[i]) != 32){
            return 1; 
        }       
    }
    return 0;
}

int jaExistePartido(int* n, char aux[], TipoPartido* ptr, char tipo[]){
    /* Função responsável por verificar o nome/sigla do partido já existe.
    
    Parâmetros:
        int* n: número de partidos cadastrados;
        char aux[]: nome/sigla a ser verificada;
        TipoPartido* ptr: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        char tipo[]: identificador de operação ("nome"/"sigla").

    Retorno:
        int 0: não existe;
        int 1: existe.
    */

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
    /* A função tem o objetivo de cadastrar novos partidos.
    Caso o partido inserido não exista e os dados sejam válidos, 
    atribui os respectivos valores a ptr[]

    Parâmetros:
        TipoPartido* ptr: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        int* nPartidos: ponteiro para inteiro que guarda a quantidade de partidos cadastrados;
        int* tam: ponteiro para inteiro que guarda o tamanho atual do vetor;
    Retorno:
        int 0: novo cadastro concluído com sucesso;
        int 1: novo cadastro falhou. 
    */ 

    int flag=1;
    char partidoAux[50], siglaAux[5];
    if (nPartidos >= tam){
        *tam = (*tam)*2;
        ptr = (TipoPartido *) realloc(ptr,(*tam)*sizeof(TipoPartido));
    }
    while(flag){
        printf("\nDigite o nome do partido: ");
        //ENTRA NO IF SE A LEITURA FOR VÁLIDA (CARACTERES)
        if((scanf("%[^\n]", partidoAux)) > 0){
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

int verificaractere(char *nome){
    int i;
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '\n') {
            return 0;
        }
    }
    return 1; 
}
//     VERIFICA CARCTERES ULTILIANDO A FUNÇÃO !ISALPHA

int verificaNome(TipoCandidato *candidatos, int tam, char *nome) {
    int i;
    for (int i = 0; i < tam; i++) {
        if (strcmp(candidatos[i].nome, nome) == 0) {
            return 1;
        }
    }
    return 0;
}
// VERIFICA O NOME DO CANDIDATO SE JÁ EXISTE
int verificanumeros(char *aux[]){
    int i;
    for (i=0; i < (int)(strlen(aux)); i++){
        //ENTRA NO IF SE O CARACTERE NÃO CORRESPONDER A UMA LETRA DE ACORDO COM A TABELA ASCII
        if ((int)(aux[i]) < 48 || (int)(aux[i]) > 57){
            return 1; 
        }       
    }
    return 0;
    // VERIFICA SE FOI DIGITADO NUMEROS DE 0 A 9
}







int cadastraCandidato(TipoCandidato *candidatos,TipoPartido *partidos, int *tam, int nCandidatos){
    char nomeaux[50],aux[50],digitosaux[50];
    int posiçao=0,i,idadeaux=0;
    if (nCandidatos >= tam){
        *tam = (*candidatos)*2;
        candidatos = (TipoCandidato *) realloc(candidatos,(*tam)*sizeof(TipoCandidatos));
    }


    while(1){
        printf("Digite o partido do candidato: \n");
        getchar();
        fgets(aux, 50, stdin);
        
        if (verificaractere(aux)) == 1{
            printf("Digite caracteres válidos!\n");
        }else{
            for(i=0;i<tam;i++){
                if (strcmp(aux, partidos[i].nomePartido)) == 0{
                    printf("Partido escolhido com sucesso!");
                    break;
                }
            }
            printf("Partido digitado não é válido!");
        }
    }

    //Escolhe um partido e verfica se é válido
    
    while(1){
        printf("Digite um nome para seu candidato: \n")
        fgets(nomeaux, 50, stdin);
        
        if (verificaractere(nomeaux)) == 1{
            printf("Digite caracteres válidos!\n");
        }else{
            if (verificaNome(candidatos, tam, nomeaux)) == 1
                printf("Nome do candidato já existente!\n");
            }else{
                strcpy(nomeaux , ptr[posiçao]);
                }

    }
    // Escolhe um nome para o candidato e verifica se é valido
    while(1){
        printf("Digite a idade do candidato: \n")
        scanf("%d", &idadeaux);
        if (idadeaux <= 0){
            printf("Digite uma idade válida");
        }else{
            candidato[nCandidatos].idade = idadeaux;
            break;
        }



    }
    // DEFINE A IDADE DO QUANDIDATO E VERIFICA SE É VÁLIDO
    while(1){
        printf("Digite os digitos do candidato: \n")
        fgets(digitosaux, 5, stdin);
        if (verificanumeros(digitosaux) == 1) {
            printf("Digite digitos válidos!");
        }else{
            candidato[nCandidatos].digitos = digitosaux;
            break;
        }



    }
    // DEFINE OS DIGITOS DO CANDIDATO E VERIFICA SE É VALIDO
    
    return 0;
}














// void registrarVoto(int * qtvotosVal, int * qtvotosBran, int * qtvotosNul){
//     // função responsavel por registrar o voto, e contabilizar o voto, mesmo sendo valido, nulo ou em branco.
// }
// int cadastraCandidato(){

// }
    

int main(){
    int opcao, nPartidos=0,nCandidatos = 0, flag=1, tam = 50;
    // int opcao, nPartidos=0, flag=1, tam = 50, qtvotosVal = 0, qtvotosBran = 0, qtvotosNul = 0;
    TipoPartido *partidos = NULL;
    TipoFederacao *federacoes = NULL;
    TipoCandidato *candidatos = NULL;
    candidatos = (TipoCandidato *) malloc(tam*sizeof(TipoCandidato));
    partidos = (TipoPartido *) malloc(tam*sizeof(TipoPartido));
    federacoes = (TipoFederacao *) malloc(tam*sizeof(TipoFederacao));

    //CADASTROS

    while (flag){
    //O WHILE DEVE ENCERRAR QUANDO O USUARIO ESCOLHER O OPÇÃO 4 'ENCERRAR ETAPA DE CADASTROS'
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
                    if ((cadastraCandidato(candidatos, &nCandidatos, &tam) == 0)){
                        printf("\nCandidato cadastrado com sucesso!\n");
                    }else{
                        printf("\nO procedimento falhou.\n");

                    }
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
    
    // imprimeMenuVotacao();
    // printf("escolha uma das opcoes acima: ");
    // do{
    //     // do while deve encerrar quando a variavel opcao ser igual a 2.
    //     scanf("%d",opcao);
    //     if (opcao == 1){
    //         registrarVoto(&qtvotosVal,&qtvotosBran,&qtvotosNul);
    //     }
    // }while(opcao != 2);

    //VOTAÇÃO
    flag = 1;    
    while (flag){
        imprimeMenuVotacao();

        printf("Selecione uma opcao: ");
        if ((scanf("%d", &opcao)) > 0){
            switch (opcao){
                case 1:
                    // registrarVoto(&qtvotosVal,&qtvotosBran,&qtvotosNul);
                    // break;
                case 2:
                    flag = 0;
                    break;
                default:
                //MENSAGEM DE ERRO
                //SOLICITAR A OPÇÃO NOVAMENTE
                //CASO NECESSÁRIO, AJEITAR LOOP PARA ISSO SER POSSÍVEL
                break;
            }
        }else{
            printf("\nOpcao invalida. Tente novamente!\n");
            getchar();
        }
    }
        

// // RELATORIO
//     //ADICIONAR PASSOS ANTERIORES NECESSÁRIOS
//     imprimeRelatorio();
//     //CONTÉM FUNÇÕES DESCRITAS NA PLANILHA

    free(candidatos);
    free(partidos);
    free(federacoes);
    return 0;
}