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

void imprimeTituloAfiliados(){
    printf("\n* ------------------------------------ *\n");
    printf("*                                      *\n");
    printf("* | a | f | i | l | i | a | d| o | s | *\n");
    printf("*                                      *\n");
    printf("* ------------------------------------ *\n");
    printf("\nNota: Afilie um partido por vez\n");
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
        if (((int)(aux[i]) < 65 || (int)(aux[i]) > 90) && ((int)(aux[i]) < 97 || (int)(aux[i]) > 122) && (int)(aux[i]) != 32){
            printf("%d",aux[i]);
            printf("i: %d", i);
            return 1; 
        }       
    }
    return 0;
}

int jaExistePartido(int n, char aux[], TipoPartido* ptr, char tipo[]){
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
    for(i=0; i<n; i++){   //VERIFICA SE O PARTIDO JÁ EXISTE
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

    char nomeAux[50], siglaAux[5];
    if (*nPartidos >= *tam){
        *tam = (*tam)*2;
        ptr = (TipoPartido *) realloc(ptr,(*tam)*sizeof(TipoPartido));
    }
    while(1){
        printf("\nDigite o nome do partido: ");
        //ENTRA NO IF SE A LEITURA FOR VÁLIDA (CARACTERES)
        if((scanf("%[^\n]", nomeAux)) > 0){
            getchar();
            if (caracteresValidos(nomeAux) == 0){   //VERIFICA SE TODOS OS CARACTERES SÃO VÁLIDOS
                if (jaExistePartido(*nPartidos, nomeAux, ptr, "nome") == 1){   //VERIFICA SE O PARTIDO JÁ EXISTE
                    printf("\nPartido já existente.\n");
                    return 1;
                }else{
                    break;
                }
            }else{
                printf("\nCaracteres invalidos. Tente novamente!");
            }
        }else{
            printf("\nEntrada inálida. Tente novamente!");
            getchar();
        }
    }
    while(1){
        printf("\nDigite a sigla do partido (maximo 5 caracteres): ");
        if(scanf("%s", siglaAux) > 0){
            getchar();
            if (caracteresValidos(siglaAux) == 0){
                if (jaExistePartido(*nPartidos, siglaAux, ptr, "sigla") == 1){
                    printf("\nSigla ja existente. Tente novamente!");
                }else{
                    break;
                }
            }else{
                printf("\nCaracteres invalidos. Tente novamente!");
            }
        }else{
            printf("\nEntrada invalida. Tente novamente!");
            getchar();
        }                  
    }

    strcpy(ptr[*nPartidos].nomePartido, nomeAux);
    strcpy(ptr[*nPartidos].siglaPartido, siglaAux);
    *nPartidos = *nPartidos +1;
    return 0;   
   
}   

int jaExisteAfiliado(int n, int nFederacoes, char aux[], TipoFederacao* ptr){
    
    int i;
    for(i=0; i<n; i++){
        if((strcmp(aux, ptr[nFederacoes].siglaAfiliados[i])) == 0){   //ENTRA SE O AFILIADO JA ESTIVER CADASTRADO
            return 1;
        }
    }
    return 0;
}

void registraAfiliados(TipoFederacao *ptr1, TipoPartido* ptr2, int nPartidos, int nFederacoes, int i){
    /*
    */
    char siglaAux[5];
    int opcao;
    
    while(1){
        printf("\nDigite a sigla do partido a ser afiliado: ");
        //ENTRA NO IF SE A LEITURA FOR VÁLIDA (CARACTERES)
        if((scanf("%s", siglaAux)) > 0){
            getchar();
            if (caracteresValidos(siglaAux) == 0){   //VERIFICA SE TODOS OS CARACTERES SÃO VÁLIDOS
                if (jaExistePartido(nPartidos, siglaAux, ptr2, "sigla") == 1){   //VERIFICA SE O PARTIDO EXISTE
                    if((jaExisteAfiliado(i, nFederacoes, siglaAux, ptr1)) == 0){
                        printf("\nPartido afiliado com sucesso.\n");
                        strcpy(ptr1[nFederacoes].siglaAfiliados[i], siglaAux);
                        break;
                    }else{
                        printf("\nO partido inserido ja esta cadastrado como afiliado.");
                        break;
                    }
                    
                }else{
                    printf("\nA sigla inserida não pertence a um partido existente.\n");
                    break;
                }
            }else{
                printf("\nCaracteres invalidos. Tente novamente!");
            }
        }else{
            printf("\nEntrada invalida. Tente novamente!");
            getchar();
        }
    }
    printf("\nDeseja inserir outro partido?");
    while(1){
        printf("\n(1) Sim\n(2) Nao\nSelecione uma opcao: ");
        if ((scanf("%d", &opcao)) > 0){
            getchar();
            switch (opcao){
                case 1:
                    return registraAfiliados(ptr1, ptr2, nPartidos, nFederacoes, i+1);
                case 2:
                    return;
                default:
                    printf("\nOpcao invalida. Tente novamente!\n");
                    break;
            }
        }else{
            printf("\nOpcao invalida. Tente novamente!\n");
            getchar();
        }
    }
    
}

int jaExisteFederacao(int* n, char aux[], TipoFederacao* ptr, char tipo[]){

    int i;
    for(i=0; i<*n; i++){   //VERIFICA SE O PARTIDO JÁ EXISTE
        if((strcmp(tipo, "nome")) == 0){
            if((strcmp(aux, ptr[i].nomeFederacao)) == 0){   //ENTRA SE O PARTIDO JÁ EXISTIR
                return 1;
            }
        }else{
            if((strcmp(aux, ptr[i].siglaFederacao)) == 0){   //ENTRA SE A SIGLA JÁ EXISTIR
                return 1;
            }
        }
    }
    return 0;
}

int registraFederacao(TipoFederacao *ptr , int* nFederacoes, int* tam){
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

    char nomeAux[50], siglaAux[5];
    if (*nFederacoes >= *tam){
        *tam = (*tam)*2;
        ptr = (TipoFederacao *) realloc(ptr,(*tam)*sizeof(TipoFederacao));
    }
    while(1){
        printf("\nDigite o nome da federacao: ");
        //ENTRA NO IF SE A LEITURA FOR VÁLIDA (CARACTERES)
        if((scanf("%[^\n]", nomeAux)) > 0){
            getchar();
            if (caracteresValidos(nomeAux) == 0){   //VERIFICA SE TODOS OS CARACTERES SÃO VÁLIDOS
                if (jaExisteFederacao(nFederacoes, nomeAux, ptr, "nome") == 1){   //VERIFICA SE A FEDERACAO JÁ EXISTE
                    printf("\nFederacao já existente.\n");
                    return 1;
                }else{
                    break;
                }
            }else{
                printf("\nCaracteres invalidos. Tente novamente!");
            }
        }else{
            getchar();
            printf("\nEntrada invalida. Tente novamente!");
        }
    }
    //SE A FEDERAÇÃO AINDA NAO EXISTIR:
    while(1){
        printf("\nDigite a sigla da federacao (maximo 5 caracteres): ");
        if(scanf("%s", siglaAux) > 0){
            getchar();
            if (caracteresValidos(siglaAux) == 0){
                if (jaExisteFederacao(nFederacoes, siglaAux, ptr, "sigla")){
                    printf("\nSigla já existente. Tente novamente!\n");
                }else{
                    break;
                }
            }else{
                printf("\nCaracteres invalidos. Tente novamente!\n");
            }
        }else{
            getchar();
            printf("\nEntrada inálida. Tente novamente!\n");
        }                  
    }

    strcpy(ptr[*nFederacoes].nomeFederacao, nomeAux);
    strcpy(ptr[*nFederacoes].siglaFederacao, siglaAux);
    *nFederacoes = *nFederacoes +1;
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
        if (strcmp(candidatos[i].nomeCandidato, nome) == 0) {
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

    
// NOTAS: ATUALIZAR A FUNÇÃO DE VERIFICAR CARACTERES NAS FUNÇÕES DE CADASTRAR PARTIDO E FEDERACAO
int main(){
    int opcao, flag=1;
    // int nPartidos=0, tamp=50, nFederacoes=0, tamf=50;
    int nPartidos=0, tamp=50, nFederacoes=0, tamf=50, nCandidatos=0, tamc=50;
    // int qtvotosVal = 0, qtvotosBran = 0, qtvotosNul = 0;
    TipoPartido *partidos = NULL;
    TipoFederacao *federacoes = NULL;
    TipoCandidato *candidatos = NULL;
    candidatos = (TipoCandidato *) malloc(tamc*sizeof(TipoCandidato));
    partidos = (TipoPartido *) malloc(tamp*sizeof(TipoPartido));
    federacoes = (TipoFederacao *) malloc(tamf*sizeof(TipoFederacao));

    //CADASTROS

    while (flag){
    //O WHILE DEVE ENCERRAR QUANDO O USUARIO ESCOLHER O OPÇÃO 4 'ENCERRAR ETAPA DE CADASTROS'
        imprimeMenuCadastro(); //FUNÇÃO QUE IMPRIME O MENU
        printf("\nSelecione uma opcao: ");
        if ((scanf("%d", &opcao)) > 0){
            switch (opcao){
                case 1:
                    getchar();
                    if((cadastraPartido(partidos, &nPartidos, &tamp)) == 0){
                        printf("\nPartido cadastrado com sucesso!\n");
                    }else{
                        printf("\nO procedimento falhou.\n");
                    }
                    break;
                case 2:
                    // getchar();
                    printf("2");
                    if ((cadastraCandidato(candidatos, &nCandidatos, &tamc) == 0)){
                        printf("\nCandidato cadastrado com sucesso!\n");
                    }else{
                        printf("\nO procedimento falhou.\n");

                    }
                    break;
                case 3:
                    getchar();
                    if(nPartidos< 2){
                        printf("\nCadastre ao menos 2 partidos para registrar uma Federacao.\n");
                        break;
                    }else{
                        registraFederacao(federacoes, &nFederacoes, &tamf);
                        imprimeTituloAfiliados();
                        registraAfiliados(federacoes, partidos, nPartidos, nFederacoes, 1);
                    }
                    break;
                case 4:
                    getchar();
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