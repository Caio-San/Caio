#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct{
    char nomeFederacao[50];
    char siglaFederacao[5];
    char siglaAfiliados[50][5];
    int nAfiliados;
    int votos;

} TipoFederacao;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMAÇOES DAS FEDERAÇÕES

typedef struct{
    char nomePartido[50];
    char siglaPartido[5];
    int votos;
    int eleitos;
} TipoPartido;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMAÇÕES DOS PARTIDOS

typedef struct{
    char nomeCandidato[50];
    int idade;
    char digitos[5];
    char partido[50];
    int votos;

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
    
    printf("\n* ------------------------------------- *\n");
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

    printf("\n* ------------------------------------- *\n");
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
    /* Função responsável por imprimir o título da seção "Afiliados". 
    */
    printf("\n* ------------------------------------ *\n");
    printf("*                                      *\n");
    printf("* | a | f | i | l | i | a | d| o | s | *\n");
    printf("*                                      *\n");
    printf("* ------------------------------------ *\n");
    printf("\nNota: Afilie um partido por vez\n");
}

void imprimeSecao2(TipoCandidato* candidatos, int nCandidatos){
    /* Função responsável por imprimir a Seção 2 do relatório.
    Dados a serem impressos: Nome do candidato e a quantidade de votos que obteve.

    Parâmetros:
        TipoCandidato* candidatos: ponteiro para vetor que armazena os dados dos candidatos cadastrados;
        int nCandidatos:  quantidade de candidatos cadastrados;
    */
    
    int i;
    printf("\n* ----------------------------------------- *\n");
    printf("*                                           *\n");
    printf("*   | r | e | l | a | t | o | r | i | o |   *\n");
    printf("*                                           *\n");
    printf("* | p | a | r | t | e |   | d | o | i | s | *\n");
    printf("*                                           *\n");
    printf("* ----------------------------------------- *");
    for (i = 0; i< nCandidatos; i++){
        printf("\n");
        printf("\nCandidato(a): %s", candidatos[i].nomeCandidato);
        printf("\nVotos recebidos: %d", candidatos[i].votos);
    }
    
}

void auxSecao1(int qtvotos){
    /* Função responsável por verificar quantos dígitos a quantidade de votos tem.

    Parâmetros:
        int qtVotos: quantidade de votos a ser analisada;
    Retorno:
        char* aux2: ponteiro para char que guarda a quantidade de espaços necessários para regular a tabela.
    */
    char aux[10];
    int i;
    sprintf(aux,"%d", qtvotos);
    for(i=0; i<16 - (int)(strlen(aux)); i++){
        printf(" ");
    }
}

void imprimeSecao1(int votosVal, int votosNul, int votosBra, int qEleitoral){
    /* A função imprime a tabela com os valores: total de votos, votos válidos, 
    votos nulos, votos brancos e quociente Eleitoral.

    Parâmetros:
        int votosVal: quantidade de votos válidos;
        int votosNul: quantidade de votos nulos;
        int votosBra: quantidade de votos brancos;
        int qEleitoral: quocienteEleitoral
    */

    printf("\n* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* | r | e | l | a | t | o | r | i | o | *\n");
    printf("*                                       *\n");
    printf("*   | p | a | r | t | e |   | u | m |   *\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* Total de votos: %d      ", (votosBra+votosNul+votosVal));
    auxSecao1(votosBra+votosNul+votosVal);
    printf("*\n");
    printf("*                                       *\n");
    printf("* Votos validos: %d       ", votosVal);
    auxSecao1(votosBra+votosNul+votosVal);
    printf("*\n");
    printf("*                                       *\n");
    printf("* Votos nulos: %d         ", votosNul);
    auxSecao1(votosBra+votosNul+votosVal);
    printf("*\n");
    printf("*                                       *\n");
    printf("* Votos brancos: %d       ", votosBra);
    auxSecao1(votosBra+votosNul+votosVal);
    printf("*\n");
    printf("*                                       *\n");
    printf("* Quociente eleitoral: %d ", qEleitoral);
    auxSecao1(votosBra+votosNul+votosVal);
    printf("*\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
}

void imprimeSecao3(TipoPartido* ptr1, TipoFederacao* ptr2, int nP, int nF){
    /* Função responsável por imprimir a Seção 3 do relatório.
    Dados a serem impressos: Nome do partido/federação e a quantidade de votos que obteve.

    Paraâmetros:
        TipoPartido* ptr1: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        TipoFederacao* ptr2: ponteiro para vetor que armazena os dados das federações cadastradas;
        int nP:  quantidade de partidos cadastrados;
        int nF:  quantidade de federações cadastradas;
    */
    int i, j, k, afiliado;
    printf("\n* ----------------------------------------- *\n");
    printf("*                                           *\n");
    printf("*   | r | e | l | a | t | o | r | i | o |   *\n");
    printf("*                                           *\n");
    printf("* | p | a | r | t | e |   | t | r | e | s | *\n");
    printf("*                                           *\n");
    printf("* ----------------------------------------- *\n");
    
    for (i = 0; i< nF; i++){
        printf("\nFederacao: %s", ptr2[i].nomeFederacao);
        printf("\nVotos recebidos: %d\n", ptr2[i].votos);
    }
    for(i=0; i<nP; i++){ //CHECA TODOS OS PARTIDOS
        afiliado = 0;
        for(j=0; j<nF; j++){ // CHECA TODAS AS FEDERAÇÕES
            for(k=0; k<ptr2[j].nAfiliados; k++){ //CHECA TODOS OS AFILIADOS DE UMA FEDEÇÃO
                if(strcmp(ptr1[i].siglaPartido, ptr2[j].siglaAfiliados[k]) == 0){ //ENTRA SE O PARTIDO FOR AFILIADO
                    afiliado = 1;
                    break;    
                }
            }
            if(afiliado == 1){
                break;
            }
        }
        if(afiliado == 0){
            printf("\nPartido: %s", ptr1[i].nomePartido);
            printf("\nVotos recebidos: %d\n", ptr1[i].votos);
        }
    }
    // printf("\n");
    //                 printf("Partido: %s\n", ptr1[i].nomePartido);
    //                 printf("Votos recebidos: %d\n", ptr1[i].votos);
}

int quocientePartidario(int QEleitoral ,int votosValidosPartido){
    /*Funçao que calcula o quociente partidario : votos validos por cada partido dividido pelo quociente eleitoral
    
        Parametro :
            int QEleitoral: quociente eleitoral da eleição.
            int VotosValidosPartido: quantidade de votos validos recebido por um partido/federação
            
        Retorna:
            int TotaldeCadeiras: quantidade de cadeiras que o partido terá direito na eleição
        */
    int TotaldeCadeiras = votosValidosPartido / QEleitoral;
    return TotaldeCadeiras;
}

void imprimeSecao4(TipoPartido* ptr1, TipoFederacao* ptr2, int nP, int nF, int qEleitoral){
    /* Função responsável por imprimir a Seção 4 do relatório.
    Dados a serem impressos: Nome do partido/federação e o seu respectivo quacioente partidário.
    O quociente partidário representa o número de cadeiras disponíveis para o partido/federação.

    Paraâmetros:
        TipoPartido* ptr1: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        TipoFederacao* ptr2: ponteiro para vetor que armazena os dados das federações cadastradas;
        int nP:  quantidade de partidos cadastrados;
        int nF:  quantidade de federações cadastradas;
        int qEleitoral: quociente eleitoral.
    */
    int afiliado, i, j, k;
    
    printf("\n* ------------------------------------------------- *\n");
    printf("*                                                   *\n");
    printf("*       | r | e | l | a | t | o | r | i | o |       *\n");
    printf("*                                                   *\n");
    printf("* | p | a | r | t | e |   | q | u | a | t | r | o | *\n");
    printf("*                                                   *\n");
    printf("* ------------------------------------------------- *\n");

    for (i = 0; i< nF; i++){
        printf("\nFederacao: %s", ptr2[i].nomeFederacao);
        printf("\nQuociente partidario: %d\n", quocientePartidario(qEleitoral ,ptr2[i].votos));
    }
    for(i=0; i<nP; i++){ //CHECA TODOS OS PARTIDOS
        afiliado = 0;
        for(j=0; j<nF; j++){ // CHECA TODAS AS FEDERAÇÕES
            for(k=0; k<ptr2[j].nAfiliados; k++){ //CHECA TODOS OS AFILIADOS DE UMA FEDEÇÃO
                if(strcmp(ptr1[i].siglaPartido, ptr2[j].siglaAfiliados[k]) == 0){ //ENTRA SE O PARTIDO FOR AFILIADO
                    afiliado = 1;
                    break;    
                }
            }
            if(afiliado == 1){
                break;
            }
        }
        if(afiliado == 0){
            printf("\nPartido: %s", ptr1[i].nomePartido);
            printf("\nQuociente partidario: %d\n",quocientePartidario(qEleitoral ,ptr1[i].votos));
        }
    }
}

void imprimirSecao5(TipoCandidato* eleitos){
    /* Função responsável por imprimir a Seção 5 do relatório.
    Dados a serem impressos: Nome dos candidatos eleitos e o nome dos seus respectivos partidos.

    Parâmetros:
        char candidatosEleitos[]: lista com o nome de todos os candidatos eleitos;
        TipoCandidato* ptr: TipoCandidato* candidatos: ponteiro para vetor que armazena os dados dos candidatos cadastrados.
    */
    int i, j;
    printf("\n* --------------------------------------------- *\n");
    printf("*                                               *\n");
    printf("*     | r | e | l | a | t | o | r | i | o |     *\n");
    printf("*                                               *\n");
    printf("* | p | a | r | t | e |   | c | i | n | c | o | *\n");
    printf("*                                               *\n");
    printf("*         | E | L | E | I | T | O | S |         *\n");
    printf("*                                               *\n");
    printf("* --------------------------------------------- *\n");

    for(i=0; i< len(eleitos); i++){
        printf("\nCandidato(a): %s", eleitos[i].nomeCandidato);
        printf("\nLegenda Partidaria: %s\n", eleitos[i].partido);
    }
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
        if (isalpha(aux[i]) == 0 && (int)(aux[i]) != 32 && (int)(aux[i]) != 10){
            // printf("%d",aux[i]); //TESTES
            // printf("i: %d", i);
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
                    printf("\nPartido ja existente.\n");
                    return 1;
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
    /* Função responsável por checar se o partido já está filiado à respectiva federação.

    Parâmetros:
        int n: quantidade de partidos já cadastrados na respectiva federação;
        int nFederacoes: quantidade de federações cadastradas;
        char aux[]: sigla do partido a ser cadastrado;
        TipoFederacao* ptr: ponteiro para vetor que armazena os dados das federacoes cadastradas;
    Retorno:
        int 0: partido já afiliado;
        int 1: partido não afiliado. 
    */
    
    int i;
    for(i=0; i<n; i++){
        if((strcmp(aux, ptr[nFederacoes-1].siglaAfiliados[i])) == 0){   //ENTRA SE O AFILIADO JA ESTIVER CADASTRADO
            return 1;
        }
    }
    return 0;
}

void registraAfiliados(TipoFederacao *ptr1, TipoPartido* ptr2, int nPartidos, int nFederacoes, int i){
    /* Função responsável por registrar os afiliados na respectiva federação.
    
    Parâmetros:
        TipoFederacao* ptr1: ponteiro para vetor que armazena os dados das federacoes cadastradas;
        TipoPartido* ptr2: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        int nPartidos: quantidade de partidos cadastrados;
        int nFederacoes: quantidade de federações cadastradas;
        int i: quantidade de afiliados cadastrados.

    */
    char siglaAux[5];
    int opcao;
    
    while(1){
        printf("\nDigite a sigla do partido a ser afiliado: ");
        //ENTRA NO IF SE A LEITURA FOR VÁLIDA (CARACTERES)
        if((scanf("%s", siglaAux)) > 0){
            if (caracteresValidos(siglaAux) == 0){   //VERIFICA SE TODOS OS CARACTERES SÃO VÁLIDOS
                if (jaExistePartido(nPartidos, siglaAux, ptr2, "sigla") == 1){   //VERIFICA SE O PARTIDO EXISTE
                    if((jaExisteAfiliado(i, nFederacoes, siglaAux, ptr1)) == 0){
                        printf("\nPartido afiliado com sucesso.\n");
                        strcpy(ptr1[nFederacoes-1].siglaAfiliados[i], siglaAux);
                        ptr1[nFederacoes-1].nAfiliados = ptr1[nFederacoes-1].nAfiliados + 1;
                        printf("\nfederacao: %s\nnumero de afiliados: %d",ptr1[nFederacoes-1].nomeFederacao, ptr1[nFederacoes-1].nAfiliados);
                        break;
                    }else{
                        printf("\nO partido inserido ja esta cadastrado como afiliado.");
                        break;
                    }
                    
                }else{
                    printf("\nA sigla inserida nao pertence a um partido existente.\n");
                    break;
                }
            }else{
                printf("\nCaracteres invalidos. Tente novamente!");
            }
        }else{
            printf("\nEntrada invalida. Tente novamente!");
        }
        getchar();
    }
    printf("\nDeseja inserir outro partido?");
    getchar();
    while(1){
        printf("\n(1) Sim\n(2) Nao\nSelecione uma opcao: ");
        if ((scanf("%d", &opcao)) > 0){
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
        }
    }
    getchar();
    
}

int jaExisteFederacao(int* n, char aux[], TipoFederacao* ptr, char tipo[]){
    /* Função responsável por verificar se o nome ou sigla a ser cadastrado já existe no banco de dados.

    Parâmetros:
        int* n: quantidade de federacoes cadastradas;
        char aux[]: string a ser verificada;
        TipoFederacao* ptr1: ponteiro para vetor que armazena os dados das federacoes cadastradas;
        TipoPartido* ptr2: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        char tipo[]: string que define se será verificado um nome ou sigla.
    Retorno:
        int 0: não existe;
        int 1: existe..
    */

    int i;
    for(i=0; i<*n; i++){   //VERIFICA SE O PARTIDO JÁ EXISTE
        if((strcmp(tipo, "nome")) == 0){
            if((strcmp(aux, ptr[i].nomeFederacao)) == 0){   //ENTRA SE O NOME JÁ EXISTIR
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

int registraFederacao(TipoFederacao *ptr, int* nFederacoes, int* tam){
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
            printf("\n1 nomeAux: %s", nomeAux); //TESTE
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
            printf("\nEntrada invalida. Tente novamente!");
        }
        getchar();
    }
    //SE A FEDERAÇÃO AINDA NAO EXISTIR:
    while(1){
        printf("\nDigite a sigla da federacao (maximo 5 caracteres): ");
        if(scanf("%s", siglaAux) > 0){
            printf("\n1 siglaAux: %s", siglaAux); //TESTE
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
            printf("\nEntrada inálida. Tente novamente!\n");
        }
        getchar();                  
    }
    printf("\n2 nomeAux: %s", nomeAux); //TESTE
    strcpy(ptr[*nFederacoes].nomeFederacao, nomeAux);
    printf("\n2 siglaAux: %s", siglaAux); //TESTE
    strcpy(ptr[*nFederacoes].siglaFederacao, siglaAux);
    *nFederacoes = *nFederacoes +1;
    return 0;   
   
}

int verificaNome(TipoCandidato *candidatos, int *tam, char *nome) {
    /*Função responsável por verificar se o nome inserio pelo candidato já foi cadastrado por outro candidato
    
    Parametros: 
        TipoCandidato *candidatos: ponteiro para o vetor que armazena as informações dos candidatos.
        int *tam: Ponteiro de inteiro para a variavel que armazena o tamanho do vetor candidatos.
        char *nome: Ponteiro char para variavel que armazena a string que representa o nome do candidato.
        
        
    Retorno:
        Retorna inteiro 0 em casa de nome válido e retorna inteiro 1 em caso de nome inválido.
        */
    int i;
    for (i = 0; i < *tam; i++) {
        if (strcmp(candidatos[i].nomeCandidato, nome) == 0) {
            return 1;
        }
    }
    return 0;
}
// VERIFICA O NOME DO CANDIDATO SE JÁ EXISTE
int verificanumeros(char *aux){
    int i;
    for (i=0; i < (int)(strlen(aux)); i++){
        // VERIFICA SE FOI DIGITADO NUMEROS DE 0 A 9 DE ACORDO COM A TABELA ASCII
        if (!isdigit(aux[i])){
            return 1; 
        }       
    }
    return 0;
}

void zeraVotosCandidatos(TipoCandidato* candidatos, int nCandidatos){
    /* Função responsável por zerar o campo de votos das structs TipoCandidato.

    Parâmetros:
        TipoCandidato* candidatos: ponteiro para vetor que armazena os dados dos candidatos cadastrados;
        int nCandidatos: quantidade de candidatos cadastrados.
    */
    int i;
    for(i=0; i<nCandidatos; i++){
        candidatos[i].votos = 0;
    }
}

int jaExistecandidato(int* nCandidatos, char aux[], TipoCandidato* ptr, char tipo[], int* indiceCandidato){
    /* Função responsável por verificar se o candidato já existe no banco de dados.

    Parâmetros:
        int* nCandidatos: ponteiro para inteiro que armazena a quantidade de cadidatos cadastrados;
        char aux[]: string a ser verificada;
        TipoCandidato* ptr: ponteiro para TipoCandidato que armazena as informações dos candidatos já cadastrados;
        char tipo[]: char que define o que será verificado.
        int* indiceCandidato: localização do candidato em ptr.

    Retorno:
        0: não existe;
        1: existe.
    */
    int i;
    for(i=0; i<*nCandidatos; i++){   //VERIFICA SE O CANDIDATO JÁ EXISTE
        if((strcmp(tipo, "nome")) == 0){
            if((strcmp(aux, ptr[i].nomeCandidato)) == 0){   //ENTRA SE O CANDIDATO JÁ EXISTIR
                return 1;
            }
        }else{
            if((strcmp(aux, ptr[i].digitos)) == 0){   //ENTRA SE OS DIGITOS JÁ EXISTIREM
                *indiceCandidato = i;
                return 1;
            }
        }
    }
    return 0;
}

int numeromax(char *digitos){
    /* Função responsável por verificar se o usuário digitou exatamente 5 digitos na entrada

    Paramatro: 
        char *digitos: ponteiro tipo char que recebe uma string

    Retorno:
        Retorna um inteiro 1 em casa de entrada inválida e um inteiro 0 em caso de entrada válida;
    */
    if (digitos == NULL){
        return 1;
    }
    if (strlen(digitos) != 5){
        return 1;

    }

    return 0;
}

int cadastraCandidato(TipoCandidato* candidatos, TipoPartido *partidos, int *tam, int *nCandidatos){
    /* Função responsável por receber e armazenar as informações dos candidatos: partido, nome do candidato, idade do candidato , digitos do candidato.
    
        Parametros: 
            TipoCandidato *candidatos: ponteiro para o vetor que armazena as informações dos candidatos.
            TipoPartido *partidos :  ponteiro para vetor que armazena os dados dos partidos cadastrados.
            int *tam: Ponteiro de inteiro para a variavel que armazena o tamanho do vetor candidatos.
            int* nCandidatos: ponteiro para inteiro que armazena a quantidade de cadidatos cadastrados;

        Retorno:
            Retorna um inteiro 0 se todas entradas forem inseridas corretamente.
        */
    char nomeaux[50],aux[50],digitosaux[6];
    int i,idadeaux=0;
    int partidoencontrado = 0,digitosencontrado;
    if (*nCandidatos >= *tam){
        *tam = (*tam)*2;
        candidatos = (TipoCandidato *) realloc(candidatos,(*tam)*sizeof(TipoCandidato));
        if (!candidatos) { 
            printf("\nErro na realocacaoo de memoria!\n");
            return -1;
        }
    }
    while(1){
        printf("\nDigite o partido do candidato: ");
        fgets(aux, 50, stdin);
        aux[strcspn(aux, "\n")] = '\0';
        
        if (caracteresValidos(aux)){
            getchar();
            printf("Digite caracteres validos!\n");
        }else{
            for(i=0;i<*tam;i++){
                if ((strcmp(aux, partidos[i].nomePartido)) == 0){
                    
                    printf("Partido escolhido com sucesso!\n");
                    strcpy(candidatos[*nCandidatos].partido, aux);
                    partidoencontrado = 1;
                    printf("%s", candidatos[*nCandidatos].partido);
                    break;

                }
            }
            if (partidoencontrado == 1){
                break;
            }
            getchar();
            printf("Partido digitado nao existe!\n");
        }
    }
    while(1){
        printf("\nDigite um nome para seu candidato: ");
        fgets(nomeaux, 50, stdin);
        nomeaux[strcspn(nomeaux, "\n")] = '\0';

        if ((caracteresValidos(nomeaux))){
            getchar();
            printf("Digite caracteres validos!\n");
        }else{
            if ((verificaNome(candidatos, nCandidatos, nomeaux)) == 1){
                getchar();
                printf("Nome do candidato já existente!\n");
            }else{
                getchar();
                strcpy(candidatos[*nCandidatos].nomeCandidato, nomeaux);
                break;
            }
        }
    }
    // Escolhe um nome para o candidato e verifica se é valido
    while (1) {
        printf("Digite a idade do candidato: ");
        // Verifica se a entrada é válida
        if (scanf("%d", &idadeaux) != 1) {
            
            while (getchar() != '\n');  // Descarta caracteres até a nova linha
            printf("\nEntrada invalida! Digite um numero inteiro.\n");
            continue;
        }

      
        if (idadeaux <= 0 || idadeaux < 18 || idadeaux > 100) {
            printf("\nValor invalido! A idade valida eh entre 18 e 100 anos.\n");
        } else {
            // Salva a idade no candidato e sai do loop
            candidatos[*nCandidatos].idade = idadeaux;
            printf("Idade do candidato registrada como %d.\n", idadeaux);
            break;
        }
    }

    // DEFINE A IDADE DO QUANDIDATO E VERIFICA SE É VÁLIDO
    while(1){
        printf("\nDigite os 5 digitos do candidato: ");
        scanf("%s", digitosaux); 
        getchar();
        if (verificanumeros(digitosaux)){ 
            printf("\nDigite 5 dígitos validos!\n");
        }else{
            if (numeromax(digitosaux)){
                printf("Deve ser inserido 5 digitos totais!");
            }else{
                digitosencontrado = 0;
                for(i=0;i<*tam;i++){
                    if (strcmp(digitosaux, candidatos[i].digitos) == 0){
                        
                        printf("Esses digitos já foram selecionados por outro candidato!");
                        digitosencontrado = digitosencontrado +1;
                    }
                }  
                if (digitosencontrado == 0){
                    getchar();
                    strcpy(candidatos[*nCandidatos].digitos, digitosaux);
                    break;
                }          
                    
                
                
            }
        }




    }
       
    // DEFINE OS DIGITOS DO CANDIDATO E VERIFICA SE É VALIDO
    *nCandidatos = *nCandidatos + 1 ;
    return 0;
}

int confirmaVoto(){
    /* Função responsável por verificar a escolha do usuário e retornar o opção escolhida.

    Retorno:
        int opcao: opção escolhida pelo usuário.
    */
    int opcao;
    while(1){
        printf("\nSelecione uma opcao: ");
        if ((scanf("%d", &opcao)) > 0){
            switch (opcao){
                case 1:
                    getchar();
                    return opcao;
                case 2:
                    getchar();
                    return opcao;
                case 3:
                    getchar();
                    return opcao;
                default:
                    getchar();
                    printf("\nOpcao invalida. Tente novamente!\n");
                break;
            }
        }else{
            printf("\nOpcao invalida. Tente novamente!\n");
            getchar();
        }
    }   
}

void Registrarvoto(TipoCandidato *candidatos,TipoPartido *partidos,int tamp, int *votoVal, int *votoNul, int *votoBra, int *nCandidatos) {
    /* Função responsável por registrar o voto do usuário.

    Parâmetros:
        TipoCandidato *candidatos: ponteiro para TipoCandidato que armazena as informações dos candidatos já cadastrados;
        TipoPartido *partido: ponteiro para TipoPartido que armazena as informações dos partidoss já cadastrados;
        int tamp:
        int *votoVal: ponteiro para inteiro que armazena a quantidade de votos válidos;
        int *votoNul: ponteiro para inteiro que armazena a quantidade de votos válidos;
        int *votoBra: ponteiro para inteiro que armazena a quantidade de votos válidos;
        int *nCandidatos: ponteiro para inteiro que armazena a quantidade de candidatos já cadastrados;
    */
    
    char auxDigito[5], voto[3];
    int indiceCandidato=0, flag =1;
    int i,p=0;
    char aux[50];
    while(flag){
        printf("\nDigite o numero do candidato: ");
        if((scanf("%s", auxDigito) > 0)){
            if((verificanumeros(auxDigito)) == 0){
                printf("%d", jaExistecandidato(nCandidatos, auxDigito, candidatos, "digito", &indiceCandidato)); //TESTE
                if((jaExistecandidato(nCandidatos, auxDigito, candidatos, "digito", &indiceCandidato)) == 1){
                    printf("\nCandidato(a): %s\n", candidatos[indiceCandidato].nomeCandidato);
                    strcpy(voto, "val");
                }else{
                    printf("\nVOTO NULO\n");
                    strcpy(voto, "nul");
                }
                imprimeMenuConfirmacao();
                switch(confirmaVoto()){
                    printf("oi switch");
                    case 1:
                        if((strcmp(voto, "val"))== 0){
                            candidatos[indiceCandidato].votos = candidatos[indiceCandidato].votos + 1;
                            *votoVal = *votoVal +1;
                            printf("Voto Candidato :");
                            printf("%d", candidatos[indiceCandidato].votos);
                            printf("\nQuantidade de votos do partido _");
                            printf("\n%s",candidatos[indiceCandidato].partido);
                            //TESTES

                            strcpy(aux, candidatos[indiceCandidato].partido);
                            for(i=0;i<tamp;i++){
                                if ((strcmp(aux, partidos[i].nomePartido)) == 0){
                                    partidos[i].votos = partidos[i].votos + 1;
                                    p = i;
                                    break;
                                }
                            }
                            // Essa estutura está atualizando a quantidade de votos por partido
                            printf("\n%d",partidos[p].votos );
                        }else{
                            *votoNul = *votoNul +1;
                        }
                        flag=0;
                        break;
                    case 2:
                        return Registrarvoto(candidatos,partidos ,tamp, votoVal, votoNul,votoBra,nCandidatos);
                    case 3:
                        *votoBra = *votoBra +1;
                        flag=0;
                        break;
                }
            }else{
                printf("\nNumero digitado invalido. Tente novamente!\n");
            }
        }else{
            printf("\nNumero digitado invalido. Tente novamente!\n");
        }  
    }
}

void calculaVotosFederacao(TipoFederacao *ptr1, TipoPartido *ptr2, int nFederacoes, int nPartidos){
    /* Função responsável por calcular os votos de cada Federação.

    Parâmetros:
        TipoFederacao* ptr1: ponteiro para vetor que armazena os dados das federações cadastradas;
        TipoPartido* ptr2: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        int nFederacoes: quantidade de federações cadastradas;
        int nPartidos: quantidade de partidos cadastrados;
    */
    
    int i, j, k;
    for(i=0; i< nFederacoes; i++){
        ptr1[i].votos = 0;
        // for(j=0; j<nCandidatos; j++){
        for(j=0; j<ptr1[i].nAfiliados; j++){ // j< QUANTIDADE DE AFILIADOS CADASTRADOS NA RESPECTIVA FEDERAÇÃO
            for(k=0; k< nPartidos; k++){
                printf("\nsigla afiiado: %s\nsigla partido: %s\n", ptr1[i].siglaAfiliados[j], ptr2[k].siglaPartido); //TESTE
                if((strcmp(ptr1[i].siglaAfiliados[j], ptr2[k].siglaPartido)) == 0){
                    printf("\nantes ptr1[i].votos: %d", ptr1[i].votos);
                    ptr1[i].votos = ptr1[i].votos + ptr2[k].votos;
                    printf("\ndepois ptr1[i].votos: %d", ptr1[i].votos);
                    break;
                }
            }  
        }
    }
}

int quocienteEleitoral(int votosValidos, int Vagas){
    /*Funçao responsavel por calcular o quociente eleitoral: votos válidos divididos pelo numero de vagas.
    
        Parâmetros:
            int votosValidos: quantidade de votos validos;
            int Vagas: quantidade total de vagas da eleição (24 vagas);
            
        Retorno: 
            int parteInteira: Se a parte fracionaria do quociente eleitoral for menor ou igual a meio;
            int parteInteira +1: Se a parte fracionaria do quociente eleitoral for maior que meio
            */
    double QEleitoral = (double)votosValidos / Vagas;
    int parteInteira  = (int)(QEleitoral);
    double parteFracionaria  = QEleitoral - parteInteira;

    if (parteFracionaria <= 0.5){
        printf("parte inteira %d", parteInteira);
        return parteInteira;

    }else{
        return parteInteira + 1;
    }

}

int candidatosEleitos(TipoCandidato *candidatos, TipoPartido *partidos, TipoCandidato *eleitos, int QEleitoral, int nCandidatos, int nPartidos) {
    /*Funçao responsavel por verificar e o candidato esta eleito: precisa cumprir os criterios de ter quantidade de votos validos
    superior ao produto de 0.1 e do quociente eleitoral , alem de estar dentro do limite de vagas do seu partido.
    
        Parâmetros:
            TipoCandidato *candidatos: ponteiro para o vetor que armazena as informaçoes dos candidatos;
            TipoPartido *partidos :  ponteiro para vetor que armazena os dados dos partidos cadastrados;
            TipoCandidato *eleitos; ponteiro para o vetor que armazena as informaçoes dos candidatos eleitos;
            int QEleitoral: variavel inteira que armazena o quociente eleitoral da eleiçao.
            int nCandidatos: inteiro que armazena a quantidade de cadidatos cadastrados;
            int npartidos: inteiro que armazena a quantidade de partidos cadastrados;

        Retorno:
            int 0: Candidato atende aos dois criterios e está eleito;
            int 1: Candidato não está eleito;
            */
    
    int i, j, indiceCandidato = 0, indicePartido = 0, eleito = 0, votoC = 0;
    int QPartidario = 0;
    TipoCandidato auxCandidato;
    char aux[50] = "";
    int QuantidadeEleitos = 0, vagasTotais = 24;

    for (i = 0; i < nCandidatos - 1; i++) {
        for (j = 0; j < nCandidatos - i - 1; j++) {
            if (candidatos[j].votos < candidatos[j + 1].votos ||
                (candidatos[j].votos == candidatos[j + 1].votos && candidatos[j].idade < candidatos[j + 1].idade)) {
                auxCandidato = candidatos[j];
                candidatos[j] = candidatos[j + 1];
                candidatos[j + 1] = auxCandidato;
            }
        }
    }

    while (vagasTotais > 0) {
        eleito = 0;
        for (i = 0; i < nCandidatos; i++) {
            votoC = candidatos[i].votos;
            if (votoC >= (0.1 * QEleitoral)) {
                eleito++;
                indiceCandidato = i;
                strcpy(aux, candidatos[i].partido);
                break;
            }
        }
        for (i = 0; i < nPartidos; i++) {
            if (strcmp(partidos[i].nomePartido, aux) == 0) {
                QPartidario = quocientePartidario(QEleitoral, partidos[i].votos);
                if (partidos[i].eleitos < QPartidario) {
                    eleito++;
                    indicePartido = i;
                    break;
                }
            }
        }

        if (eleito == 2) {  
            eleitos[QuantidadeEleitos] = candidatos[indiceCandidato];
            printf("%s esta eleito!", candidatos[indiceCandidato].nomeCandidato);
            partidos[indicePartido].eleitos++;
            QuantidadeEleitos++;
            vagasTotais--; 
        } else {
            break; 
        }
    }

    return QuantidadeEleitos;  
}


int main(){
    /* Função responsável por concatenar todas as outras funções do programa. */
    
    // int i; //TESTE
    int opcao, flag=1;
    // int nPartidos=0, tamp=50, nFederacoes=0, tamf=50;
    int nPartidos=0, tamp=50, nFederacoes=0, tamf=50, nCandidatos=0, tamc=50, VagasTotais=1, QEleitoral=0;
    int votosVal = 0, votosBra = 0, votosNul = 0;
    TipoPartido *partidos = NULL;
    TipoFederacao *federacoes = NULL;
    TipoCandidato *candidatos = NULL;
    TipoCandidato *eleitos = NULL;
    candidatos = (TipoCandidato *) malloc(tamc*sizeof(TipoCandidato));
    partidos = (TipoPartido *) malloc(tamp*sizeof(TipoPartido));
    federacoes = (TipoFederacao *) malloc(tamf*sizeof(TipoFederacao));
    eleitos = (TipoCandidato *) malloc(tamc*sizeof(TipoCandidato));
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
                    getchar();
                    if(nPartidos >0){
                        if ((cadastraCandidato(candidatos,partidos, &tamc, &nCandidatos) == 0)){                   
                            printf("\nPartido: %s", candidatos[nCandidatos - 1].partido);   //TESTES
                            printf("\nCandidato: %s", candidatos[nCandidatos - 1].nomeCandidato);
                            printf("\nDigitos: %s", candidatos[nCandidatos - 1].digitos);                    
                        }else{                                                                  
                            printf("\nO procedimento falhou.\n");                                                                                                      
                        }
                    }else{
                        printf("\nCadastre, ao menos, 1 partido para registrar um Candidato.\n");
                        break;
                    }                                                                                                                     
                                                                                           
                    break;                                                                  
                case 3:
                    getchar();
                    if(nPartidos< 2){
                        printf("\nCadastre, ao menos, 2 partidos para registrar uma Federacao.\n");
                        break;
                    }else{
                        registraFederacao(federacoes, &nFederacoes, &tamf);
                        imprimeTituloAfiliados();
                        registraAfiliados(federacoes, partidos, nPartidos, nFederacoes, 0);
                    }
                    break;
                case 4:
                    getchar();
                    printf("4");
                    flag = 0;
                    break;
                default:
                    printf("\nOpcao invalida. Tente novamente!\n");
                    break;
            }
        }else{
            printf("\nOpcao invalida. Tente novamente!\n");
            getchar();
        }
        getchar();
    }

    //VOTAÇÃO
    flag = 1;
    zeraVotosCandidatos(candidatos, nCandidatos);    
    while (flag){
        imprimeMenuVotacao();
        printf("Selecione uma opcao: ");

        if ((scanf("%d", &opcao)) > 0){
            switch (opcao){
                case 1:
                    getchar();
                    Registrarvoto(candidatos,partidos,tamp ,&votosVal, &votosNul, &votosBra, &nCandidatos);
                    
                    break;
                case 2:
                    getchar();
                    flag = 0;
                    break;
                default:
                    getchar();
                    printf("\nOpcao invalida. Tente novamente!\n");
                break;
            }
        }else{
            printf("\nOpcao invalida. Tente novamente!\n");
            getchar();
        }
        getchar();
    }
    // TESTES -- NÃO APAGAR
    // printf("\nRESULTADO");
    // for(i=0; i<nCandidatos; i++){
    //     printf("\n%s: %d", candidatos[i].nomeCandidato, candidatos[i].votos);
    // }
    // printf("voto nulo: %d", votosNul);
    // printf("voto branco: %d", votosBra);
    // printf("voto valido: %d", votosVal);
    
        
// DADOS AUXILIARES PARA O RELATORIO
    QEleitoral = quocienteEleitoral(votosVal , VagasTotais);
    printf("\nqEleitoral: %d", QEleitoral);
    
    
    //calculaVotosFederacao(federacoes, partidos, nFederacoes, nCandidatos);
// RELATORIO
    candidatosEleitos(candidatos,partidos,eleitos,QEleitoral,nCandidatos,nPartidos);
    imprimeSecao1(votosVal, votosNul, votosBra, QEleitoral);
    getchar();
    imprimeSecao2(candidatos, nCandidatos);
    getchar();
    imprimeSecao3(partidos, federacoes, nPartidos, nFederacoes);
    getchar();
    imprimeSecao4(partidos, federacoes, nPartidos, nFederacoes, QEleitoral);
    getchar();
    candidatosEleitos(candidatos, partidos, eleitos, QEleitoral, nCandidatos, nPartidos);
    imprimirSecao5(eleitos);
    getchar;

    


    printf("\n votos val: %d",votosVal ); //TESTE
    // testes
    printf("\nVotos fed: %d", federacoes[0].votos); //TESTE



    free(candidatos);
    free(partidos);
    free(federacoes);
    return 0;
}