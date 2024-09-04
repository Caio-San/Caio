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
    int qPartidario;
    int qtEleitoSuplente[2];
    int indiceEleitos[24];
    int indiceSuplentes[50];
    int impresso;

} TipoFederacao;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMAÇOES DAS FEDERAÇÕES

typedef struct{
    char nomePartido[50];
    char siglaPartido[5];
    int votos;
    int qPartidario;
    int qtEleitoSuplente[2];
    int indiceEleitos[24];
    int indiceSuplentes[50];
    int impresso;
} TipoPartido;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMAÇÕES DOS PARTIDOS

typedef struct{
    char nomeCandidato[50];
    int idade;
    char digitos[6];
    char siglaPartido[5]; //MODIFICAR FUNÇÃO DE CADASTRO
    int votos;

} TipoCandidato;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMÇOES DE CADA CANDIDATO

// typedef struct{
//     int nPartidos;
//     int nCandidatos;
//     int nFederacoes;
//     int nEleitos; //PRECISA ZERAR TD
//     int nSuplentes;

// } TipoBase;

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
    printf("* | p | a | r | t | e |   | D | O | I | S | *\n");
    printf("*                                           *\n");
    printf("* ----------------------------------------- *\n");
    for (i = 0; i< nCandidatos; i++){
        printf("\nCandidato(a): %s", candidatos[i].nomeCandidato);
        printf("\nVotos recebidos: %d\n", candidatos[i].votos);
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
    printf("*   | p | a | r | t | e |   | U | M |   *\n");
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
    printf("* | p | a | r | t | e |   | T | R | E | S | *\n");
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
    printf("* | p | a | r | t | e |   | Q | U | A | T | R | O | *\n");
    printf("*                                                   *\n");
    printf("* ------------------------------------------------- *\n");

    for (i = 0; i< nF; i++){
        printf("\nFederacao: %s", ptr2[i].nomeFederacao);
        ptr2[i].qPartidario = quocientePartidario(qEleitoral ,ptr2[i].votos);
        printf("\nQuociente partidario: %d\n", ptr2[i].qPartidario);
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
            ptr1[i].qPartidario = quocientePartidario(qEleitoral ,ptr1[i].votos);
            printf("\nQuociente partidario: %d\n", ptr1[i].qPartidario);
        }
    }
}

void imprimirSecao5(TipoCandidato* candidatos, TipoPartido* partidos, TipoFederacao* federacoes, int nP, int nF){
    /* Função responsável por imprimir a Seção 5 do relatório.
    Dados a serem impressos: Nome dos candidatos eleitos e o nome dos seus respectivos partidos.

    Parâmetros:
        
        TipoCandidato* eleitos: TipoCandidato* candidatos: ponteiro para vetor que armazena os dados dos candidatos eleitos.
    */
    int i, j, k,h, afiliado;
    
    printf("\n* --------------------------------------------- *\n");
    printf("*                                               *\n");
    printf("*     | r | e | l | a | t | o | r | i | o |     *\n");
    printf("*                                               *\n");
    printf("* | p | a | r | t | e |   | c | i | n | c | o | *\n");
    printf("*                                               *\n");
    printf("*         | E | L | E | I | T | O | S |         *\n");
    printf("*                                               *\n");
    printf("* --------------------------------------------- *\n");

    for(i=0; i<nP; i++){ //CHECA TODOS OS PARTIDOS
        afiliado = 0;
        for(j=0; j<nF; j++){ // CHECA TODAS AS FEDERAÇÕES
            for(k=0; k<federacoes[j].nAfiliados; k++){ //CHECA TODOS OS AFILIADOS DE UMA FEDEÇÃO
                if(strcmp(partidos[i].siglaPartido, federacoes[j].siglaAfiliados[k]) == 0){ //ENTRA SE O PARTIDO FOR AFILIADO
                    afiliado = 1;
                    break;    
                }
            }if (afiliado && !federacoes[j].impresso){
                printf("\nFederacao: %s\n", federacoes[j].nomeFederacao);
                for(h=0; h< federacoes[j].qtEleitoSuplente[0]; h++){
                    printf("\nCandidato: %s", candidatos[federacoes[j].indiceEleitos[h]].nomeCandidato);
                }federacoes[j].impresso = 1;
            }else if(!afiliado && !partidos[i].impresso){
                for(h=0; h< partidos[i].qtEleitoSuplente[0]; h++){
                    printf("\nCandidato: %s", candidatos[partidos[i].indiceEleitos[h]].nomeCandidato);
                }
            }    
        }
    }
}

void imprimirSecao6(TipoCandidato* candidatos, TipoPartido* partidos, TipoFederacao* federacoes, int nP, int nF){
    /* Função responsável por imprimir a Seção 6 do relatório.
    Dados a serem impressos: Nome dos candidatos suplentess e o nome dos seus respectivos partidos.

    Parâmetros:
        
        TipoCandidato* suplentes: ponteiro para vetor que armazena os dados dos candidatos suplentes.
    */
    int i, j, k,h, afiliado;
    printf("\n* --------------------------------------------- *\n");
    printf("*                                               *\n");
    printf("*     | r | e | l | a | t | o | r | i | o |     *\n");
    printf("*                                               *\n");
    printf("* | p | a | r | t | e |   | S | E | I | S |     *\n");
    printf("*                                               *\n");
    printf("*     | S | U | P | L | E | N | T | E | S |     *\n");
    printf("*                                               *\n");
    printf("* --------------------------------------------- *\n");

    for(i=0; i<nP; i++){ //CHECA TODOS OS PARTIDOS
        afiliado = 0;
        for(j=0; j<nF; j++){ // CHECA TODAS AS FEDERAÇÕES
            for(k=0; k<federacoes[j].nAfiliados; k++){ //CHECA TODOS OS AFILIADOS DE UMA FEDEÇÃO
                if(strcmp(partidos[i].siglaPartido, federacoes[j].siglaAfiliados[k]) == 0){ //ENTRA SE O PARTIDO FOR AFILIADO
                    afiliado = 1;
                    break;    
                }
            }if (afiliado && !federacoes[j].impresso){
                printf("\nFederacao: %s\n", federacoes[j].nomeFederacao);
                for(h=0; h< federacoes[j].qtEleitoSuplente[0]; h++){
                    printf("\nCandidato: %s", candidatos[federacoes[j].indiceSuplentes[h]].nomeCandidato);
                }
            }else if(!afiliado && !partidos[i].impresso){
                for(h=0; h< partidos[i].qtEleitoSuplente[0]; h++){
                    printf("\nCandidato: %s", candidatos[partidos[i].indiceSuplentes[h]].nomeCandidato);
                }
            }    
        }
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
    ptr[*nPartidos].impresso = 0;
    *nPartidos = *nPartidos +1;
    return 0;   
   
}   

int jaExisteAfiliado(int nFederacoes, char aux[], TipoFederacao* ptr){
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
    for(i=0; i<ptr[i].nAfiliados; i++){
        if((strcmp(aux, ptr[nFederacoes-1].siglaAfiliados[i])) == 0){   //ENTRA SE O AFILIADO JA ESTIVER CADASTRADO
            return 1;
        }
    }
    return 0;
}

void registraAfiliados(TipoFederacao *ptr1, TipoPartido* ptr2, int nPartidos, int nFederacoes, int afiliados){
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
                    if((jaExisteAfiliado( nFederacoes, siglaAux, ptr1)) == 0){
                        strcpy(ptr1[nFederacoes-1].siglaAfiliados[afiliados], siglaAux);
                        ptr1[nFederacoes-1].nAfiliados += 1;
                        printf("\nPartido afiliado com sucesso.\n");
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
    if(ptr1[nFederacoes-1].nAfiliados >= 2){
        printf("\nDeseja afiliar outro partido?");
        getchar();
        while(1){
            printf("\n(1) Sim\n(2) Nao\nSelecione uma opcao: ");
            if ((scanf("%d", &opcao)) > 0){
                switch (opcao){
                    case 1:
                        return registraAfiliados(ptr1, ptr2, nPartidos, nFederacoes, afiliados+1);
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
    }else{
        return registraAfiliados(ptr1, ptr2, nPartidos, nFederacoes, afiliados+1);
    } 
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
    strcpy(ptr[*nFederacoes].nomeFederacao, nomeAux);
    strcpy(ptr[*nFederacoes].siglaFederacao, siglaAux);
    ptr[*nFederacoes].impresso = 0;
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

void zeraVotosPartidos(TipoPartido* partidos, int nPartidos){
    /* Função responsável por zerar o campo de votos das structs TipoCandidato.

    Parâmetros:
        TipoCandidato* candidatos: ponteiro para vetor que armazena os dados dos candidatos cadastrados;
        int nCandidatos: quantidade de candidatos cadastrados.
    */
    int i;
    for(i=0; i<nPartidos; i++){
        partidos[i].votos = 0;
        partidos[i].qtEleitoSuplente[0] = 0;
        partidos[i].qtEleitoSuplente[1] = 0;
    }
}

void zeraVotosFederacoes(TipoFederacao* federacoes, int nFederacoes){
    /* Função responsável por zerar o campo de votos das structs TipoCandidato.

    Parâmetros:
        TipoCandidato* candidatos: ponteiro para vetor que armazena os dados dos candidatos cadastrados;
        int nCandidatos: quantidade de candidatos cadastrados.
    */
    int i;
    for(i=0; i<nFederacoes; i++){
        federacoes[i].votos = 0;
        federacoes[i].qtEleitoSuplente[0] = 0;
        federacoes[i].qtEleitoSuplente[1] = 0;
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

int caracteresVal(char *str) {
    /*Funçao responsavel por verificar se os carecteres inseridos sao letras maiusculas ou minusculas.
    Ultilizando a funçao !isalpha da biblioteca ctype.h para analisar cada carctere da string.
    
        Parametros:
            char *str: ponteiro pra um string que armazena a entrada de carateres do usuario.
            
        Retorno:
                Retorna um inteiro 1 em caso de carctere invalido.
                Caso contrario retorna 0.*/
    for (int i = 0; i < (int)strlen(str); i++) {
        if (!isalpha(str[i]) && !isspace(str[i])) {
            return 1;
        }
    }
    return 0;
}

int verificaN(TipoCandidato *candidatos, int *tam, char *nome) {
    /*Funçao responsavel por verificar se o nome inserido pelo candidato já esta registrado em outro candidato.
    Percorre o vetor de candidatos e compara a entrada com cada nome de candidato armazenado.
    
        Parametros:
            TipoCandidato* candidatos: ponteiro para TipoCandidato que armazena as informações dos candidatos já cadastrados;
            int *tam: ponteiro de inteiro pra variavel que armazena o tamanho do vetor candidatos.
            char *nome: ponteiro para string que recebe o nome do candidato.


        Retorno:
            Retorna um inteiro 1 em caso de nome invalido.
                Caso contrario retorna 0.
            */
    for (int i = 0; i < *tam; i++) {
        if (strcmp(candidatos[i].nomeCandidato, nome) == 0) {
            return 1;
        }
    }
    return 0;
}

int verificaId(int idade) {
    /*Funçao responsavel por verificar se a idade inserida pelo usuario esta dentro do limite permitido.
        Parametros:
                int idade: Variavel de inteiros que armazena a idade.
        Retorno:
            Retorna um inteiro 1 em caso de carctere invalido.
                Caso contrario retorna 0.

    */
    return (idade >= 10 && idade <= 25);
}

int verificanum(char *aux) {
    /*Funçao responsavel por verificar se a entrada inserida são de digitos entre 0 e 9.
    Ultilizando a funçao !isdigit da biblioteca ctype.h e analisando cada caractere da string.

        Parametros:
                char *aux: Ponteiro para string que armazena a entrada do usuario.
        Retorno:
            Retorna um inteiro 1 em caso de carctere invalido.
                Caso contrario retorna 0.

    */
    for (int i = 0; i < (int)(strlen(aux)); i++) {
        if (!isdigit(aux[i])) {
            return 1; 
        }       
    }
    return 0;
}

int numeromax(char *digitos) {
    /*Funçao responsavel por verificar se a entrada do usuario possui exatamente a quantidade de 5 caracteres
    
    
    Parametros:
            char *digitos: Ponteiro para string que recebe a entrada dos digitos do usuario.
    Retorno:
            Retorna um inteiro 1 em caso de entrada invalida.
                Caso contrario retorna 0.        */
    if (digitos == NULL || strlen(digitos) != 5) {
        return 1;
    }
    return 0;
}

int validaNomeCandidato(TipoCandidato *candidatos, int *nCandidatos, char *nomeaux) {
    /*Funçao responsavel por receber a entrada para o nome do candidato , armazenar em uma variavel char e verificar se ela eh valida
    Sempre que a entrada for invalida a funçao vai receber uma nova entrada. Se a entrada for valida vai armazenar o nome no vetor candidato.
    Parametros:
            int* nCandidatos: ponteiro para inteiro que armazena a quantidade de cadidatos cadastrados;
            TipoCandidato* candidatos: ponteiro para TipoCandidato que armazena as informações dos candidatos já cadastrados;
            char *nomeaux: armazena o nome inserido pelo usuario.
            
    Retorno:
        Retorna um inteiro 1 em caso de entrada invalida.
                Caso contrario retorna 0.          */
    while (1) {
        getchar();
        printf("Digite um nome para seu candidato: ");
        fgets(nomeaux, 50, stdin);
        
        if (caracteresVal(nomeaux)) {
            printf("Digite caracteres validos!\n");
        } else if (verificaN(candidatos, nCandidatos, nomeaux) == 1) {
            printf("Nome do candidato ja existente!\n");
        } else {
            strcpy(candidatos[*nCandidatos].nomeCandidato, nomeaux);
            return 0;
        }
    }
}

int validaIdadeCandidato(TipoCandidato *candidatos, int *nCandidatos) {
    /*Funçao responsavel por receber a entrada para a idade do candidato , armazenar em uma variavel int e verificar se ela eh valida
    Sempre que a entrada for invalida a funçao vai receber uma nova entrada. Se a entrada for valida vai armazenara idade no vetor candidato.
    Parametros:
            int* nCandidatos: ponteiro para inteiro que armazena a quantidade de cadidatos cadastrados;
            TipoCandidato* candidatos: ponteiro para TipoCandidato que armazena as informações dos candidatos já cadastrados;
    Retorno:
        Retorna um inteiro 1 em caso de entrada invalida.
                Caso contrario retorna 0.          */
    int idadeaux;
    while (1) {
        printf("Digite a idade do candidato: ");
        if (scanf("%d", &idadeaux) != 1) {
            while (getchar() != '\n');
            printf("\nEntrada invalida! Digite um numero inteiro.\n");
            continue;
        }

        if (verificaId(idadeaux)) {
            printf("Idade do candidato registrada como %d.\n", idadeaux);
            candidatos[*nCandidatos].idade = idadeaux;
            return 0;
        } else {
            printf("\nValor invalido! A idade deve estar entre 10 e 25 anos.\n");
        }
    }
}

int validaDigitosCandidato(TipoCandidato *candidatos, int *nCandidatos) {
    /*Funçao responsavel por receber a entrada para os digitos do candidato , armazenar em uma variavel char e verificar se ela eh valida
    Sempre que a entrada for invalida a funçao vai receber uma nova entrada. Se a entrada for valida vai armazenara idade no vetor candidato.
    A entrada eh invalida em caso de ser inserido uma quantidade diferente de 5 digitos ou caso os digitos ja estejam registrados por outro candidato.
    Parametros:
            int* nCandidatos: ponteiro para inteiro que armazena a quantidade de cadidatos cadastrados;
            TipoCandidato* candidatos: ponteiro para TipoCandidato que armazena as informações dos candidatos já cadastrados;
    Retorno:
        Retorna um inteiro 1 em caso de entrada invalida.
                Caso contrario retorna 0.          */
    char digitosaux[6];
    int digitosencontrado;

    while (1) {
        getchar();
        printf("\nDigite os 5 digitos do candidato: ");
        scanf("%s", digitosaux); 

        if (verificanum(digitosaux)) {
            printf("\nDigite 5 dígitos validos!\n");
        } else if (numeromax(digitosaux)) {
            printf("Deve ser inserido 5 digitos totais!\n");
        } else {
            digitosencontrado = 0;
            for (int i = 0; i < *nCandidatos; i++) {
                if (strcmp(digitosaux, candidatos[i].digitos) == 0) {
                    printf("Esses digitos já foram selecionados por outro candidato!\n");
                    digitosencontrado = 1;
                    break;
                }
            }  
            if (digitosencontrado == 0) {
                strcpy(candidatos[*nCandidatos].digitos, digitosaux);
                return 0;
            }          
        }
    }
}

int validaPartidoCandidato(TipoCandidato *candidatos, TipoPartido *partidos, int nPartidos, int *nCandidatos) {
    /*Funçao responsavel por receber a entrada para a o partido do candidato e verificar se eh valido.
    Se o partido nao existir a entrada sera invalida e o procedimento de cadastro vai falhar.

    Parametros:
            int* nCandidatos: ponteiro para inteiro que armazena a quantidade de cadidatos cadastrados;
            TipoCandidato* candidatos: ponteiro para TipoCandidato que armazena as informações dos candidatos já cadastrados;
            int *tam: ponteiro de inteiro pra variavel que armazena o tamanho do vetor candidatos.
            TipoPartido* partidos: ponteiro para TipoPartido que armazena as informações dos partidos já cadastrados;
    Retorno:
        Retorna um inteiro 1 em caso de entrada invalida.
                Caso contrario retorna 0.          */
    char aux[5];
    int i=0;
    // int partidoencontrado;

    while (1) {
        getchar();
        printf("\nDigite a sigla do partido do candidato: ");
        fgets(aux, 5, stdin);
        aux[strcspn(aux, "\n")] = '\0';

        if (caracteresVal(aux)) {
            printf("Digite caracteres validos!\n");
        } else {
            // partidoencontrado = 0;
            for (i = 0; i < nPartidos; i++) {
                if (strcmp(aux, partidos[i].siglaPartido) == 0) {
                    printf("Partido escolhido com sucesso!\n");
                    strcpy(candidatos[*nCandidatos].siglaPartido, aux);
                    return 0;
                }
            }
            printf("Partido digitado nao existe!\n");
            return -1;
        }
    }
}

int cadastraCandidato(TipoCandidato *candidatos, TipoPartido *partidos, int *tam, int *nCandidatos, int nPartidos) {
    /*Funçao responsavel por receber as entradas paras as informaçoes dos candidatos: nome, idade, digitos e partido.
    Verifica se cada entrada eh valida e se atende aos criterios. Se as entradas forem validas elas serao armazenadas no vetor de candidato.
    E sera contabilizado mais uma candidato cadastrado na eleiçao.
    Se a quantidade de candidatos cadastrados exceder o tamanho do vetor candidatos sera realocado o tamanho do vetor candidatos.

    Parametros:
            int* nCandidatos: ponteiro para inteiro que armazena a quantidade de cadidatos cadastrados;
            TipoCandidato* candidatos: ponteiro para TipoCandidato que armazena as informações dos candidatos já cadastrados;
            int *tam: ponteiro de inteiro pra variavel que armazena o tamanho do vetor candidatos.
            TipoPartido* partidos: ponteiro para TipoPartido que armazena as informações dos partidos já cadastrados;
    Retorno:
        Retorna um inteiro 1 em caso do procedimento falhar(se o usuario tentar se cadastrar em um partido nao existente o cadastro
        ira falhar e o usuario sera redirecionado ao menu inicial.)
                Caso contrario retorna 0.          */
    char nomeaux[50];

    if (*nCandidatos == *tam) {
        *tam = (*tam) * 2;
        candidatos = (TipoCandidato *) realloc(candidatos, (*tam) * sizeof(TipoCandidato));
        if (!candidatos) {
            printf("\nErro na realocacao de memoria!\n");
            return -1;
        }
    }

    if (validaPartidoCandidato(candidatos, partidos, nPartidos, nCandidatos) != 0) return -1;
    if (validaNomeCandidato(candidatos, nCandidatos, nomeaux) != 0) return -1;
    if (validaIdadeCandidato(candidatos, nCandidatos) != 0) return -1;
    if (validaDigitosCandidato(candidatos, nCandidatos) != 0) return -1;
    
    
    (*nCandidatos)++;
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

void Registrarvoto(TipoCandidato *candidatos,TipoPartido *partidos,int nPartidos, int *votoVal, int *votoNul, int *votoBra, int *nCandidatos) {
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
    int i;
    char aux[50];
    while(flag){
        printf("\nDigite o numero do candidato: ");
        if((scanf("%s", auxDigito) > 0)){
            if((verificanumeros(auxDigito)) == 0){
                if((jaExistecandidato(nCandidatos, auxDigito, candidatos, "digito", &indiceCandidato)) == 1){
                    printf("\nCandidato(a): %s\n", candidatos[indiceCandidato].nomeCandidato);
                    strcpy(voto, "val");
                }else{
                    printf("\nVOTO NULO\n");
                    strcpy(voto, "nul");
                }
                imprimeMenuConfirmacao();
                switch(confirmaVoto()){
                    case 1:
                        if((strcmp(voto, "val"))== 0){
                            candidatos[indiceCandidato].votos = candidatos[indiceCandidato].votos + 1;
                            *votoVal = *votoVal +1;

                            strcpy(aux, candidatos[indiceCandidato].siglaPartido);
                            for(i=0;i<nPartidos;i++){
                                if ((strcmp(aux, partidos[i].siglaPartido)) == 0){
                                    partidos[i].votos += 1;
                                    break;
                                }
                            }
                            // Essa estutura está atualizando a quantidade de votos por partido
                        }else{
                            *votoNul = *votoNul +1;
                        }
                        flag=0;
                        break;
                    case 2:
                        return Registrarvoto(candidatos,partidos ,nPartidos, votoVal, votoNul,votoBra,nCandidatos);
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

void calculaVotosFederacao(TipoFederacao *federacoes, TipoPartido *partidos, int nFederacoes, int nPartidos){
    /* Função responsável por calcular os votos de cada Federação.

    Parâmetros:
        TipoFederacao* ptr1: ponteiro para vetor que armazena os dados das federações cadastradas;
        TipoPartido* ptr2: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        int nFederacoes: quantidade de federações cadastradas;
        int nPartidos: quantidade de partidos cadastrados;
    */
    
    int i, j, k;
    for(i=0; i< nFederacoes; i++){
        federacoes[i].votos = 0;
        for(j=0; j<federacoes[i].nAfiliados; j++){ // j< QUANTIDADE DE AFILIADOS CADASTRADOS NA RESPECTIVA FEDERAÇÃO
            for(k=0; k< nPartidos; k++){
                if((strcmp(federacoes[i].siglaAfiliados[j], partidos[k].siglaPartido)) == 0){
                    federacoes[i].votos += partidos[k].votos;
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

void ordenaCandidatos(TipoCandidato* candidatos, int nCandidatos){
    /* Função responsável por ordenar a lista de candidatos em ordem decrescente de quantidade de votos.
    */
    int i, j;
    TipoCandidato auxCandidato;

    //Ordena *candidatos -> decrescente em votos
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
}

void candidatosEleitos(TipoCandidato *candidatos, TipoPartido *partidos, TipoFederacao* federacoes, int QEleitoral, int nCandidatos, int nPartidos,int *QuantidadeEleitos, int vagasTotais, int nFederacoes) {
    /*Funçao responsavel por verificar e o candidato esta eleito: precisa cumprir os criterios de ter quantidade de votos validos
    superior ao produto de 0.1 e do quociente eleitoral , alem de estar dentro do limite de vagas do seu partido.
    
        Parâmetros:
            TipoCandidato *candidatos: ponteiro para o vetor que armazena as informaçoes dos candidatos;
            TipoPartido *partidos :  ponteiro para vetor que armazena os dados dos partidos cadastrados;
            TipoCandidato *eleitos; ponteiro para o vetor que armazena as informaçoes dos candidatos eleitos;
            int QEleitoral: variavel inteira que armazena o quociente eleitoral da eleiçao.
            int nCandidatos: inteiro que armazena a quantidade de cadidatos cadastrados;
            int npartidos: inteiro que armazena a quantidade de partidos cadastrados;
            */
    
    int i, j, k, indiceCandidato = 0, indicePartido = 0, eleito = 0;
    char aux[5] = "";
    int afiliado, indiceFederacao;
    // int eleitos[vagasTotais], suplentes[50];

    //verificaca eleição
    // while (vagasTotais > 0) {
        //verifica se os votos do candidato sao >= a 10% do QEleitoral
    for (i = 0; i < nCandidatos; i++){
        afiliado =0;
        eleito = 0;
        if(candidatos[i].votos >= (0.1 * QEleitoral)){
            eleito++;
            indiceCandidato = i;
            strcpy(aux, candidatos[i].siglaPartido);
        }if(eleito == 1){
            for(j=0; j< nFederacoes; j++){
                for(k=0; k<federacoes[j].nAfiliados; k++){
                    if(strcmp(aux, federacoes[j].siglaAfiliados[k]) == 0){
                        if(federacoes[j].qtEleitoSuplente[0] < federacoes[j].qPartidario){
                            eleito++;
                            afiliado = 1;
                            indiceFederacao = i;
                            break;
                        }
                    }
                }if(afiliado) break;
            }if(!afiliado){
                for(j=0; j<nPartidos; j++){
                    if(strcmp(aux, partidos[j].siglaPartido) == 0){
                        if(partidos[j].qtEleitoSuplente[0] < partidos[j].qPartidario){
                            indicePartido = i;
                            eleito++;
                            break;
                        }
                    }
                }
            }
        }
            // ARMAZENA ELEITOS
        if (eleito == 2) {
            if(afiliado){
                //ERRO?
                federacoes[indiceFederacao].indiceEleitos[federacoes[indiceFederacao].qtEleitoSuplente[0]] = indiceCandidato;
                federacoes[indiceFederacao].qtEleitoSuplente[0]++;
            }else{
                partidos[indicePartido].indiceEleitos[partidos[indicePartido].qtEleitoSuplente[0]] = indiceCandidato;
                partidos[indicePartido].qtEleitoSuplente[0]++;
            }
            (*QuantidadeEleitos)++;
            vagasTotais--; 
        //ARMAZENA SUPLENTES
        }else{
            if(afiliado){
                //ERRO?
                if(federacoes[indiceFederacao].qPartidario > 0){
                    federacoes[indiceFederacao].indiceSuplentes[federacoes[indiceFederacao].qtEleitoSuplente[1]] = indiceCandidato;
                    federacoes[indiceFederacao].qtEleitoSuplente[1]++;
                }
                
            }else{
                if(partidos[indicePartido].qPartidario > 0){
                    partidos[indicePartido].indiceSuplentes[partidos[indicePartido].qtEleitoSuplente[1]] = indiceCandidato;
                    partidos[indicePartido].qtEleitoSuplente[1]++;
                }
            }
        }
    }
}        


int main(){
    /* Função responsável por concatenar todas as outras funções do programa. */
    
    int opcao, flag=1;
    // int nPartidos=0, tamp=50, nFederacoes=0, tamf=50;
    int nPartidos=0, tamp=50, nFederacoes=0, tamf=50, nCandidatos=0, tamc=50;
    int VagasTotais=24, QEleitoral=0, QuantidadeEleitos=0;
    int votosVal = 0, votosBra = 0, votosNul = 0;
    TipoPartido *partidos = NULL;
    TipoFederacao *federacoes = NULL;
    TipoCandidato *candidatos = NULL;
    // int *eleitos = NULL;
    // TipoBase *informacoes = NULL;
    // informacoes = (TipoBase *) malloc(sizeof(TipoBase));
    // eleitos = (int *) malloc(VagasTotais*sizeof(int));
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
                    getchar();
                    if(nPartidos >0){
                        if (cadastraCandidato(candidatos,partidos, &tamc, &nCandidatos, nPartidos)==0){  
                            printf("\nCandidato registrato com sucesso!");                   
                        }else{                                                                  
                            printf("\nO procedimento falhou.\n");  
                            printf("ENTER para seguir.\n");
                            while (getchar() != '\n');
                            imprimeMenuCadastro();                                                                                                  
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
                        federacoes[nFederacoes-1].nAfiliados = 0;
                        imprimeTituloAfiliados();
                        registraAfiliados(federacoes, partidos, nPartidos, nFederacoes,0);
                    }
                    break;
                case 4:
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
    zeraVotosPartidos(partidos, nPartidos);
    zeraVotosFederacoes(federacoes, nFederacoes);  
    while (flag){
        imprimeMenuVotacao();
        printf("Selecione uma opcao: ");

        if ((scanf("%d", &opcao)) > 0){
            switch (opcao){
                case 1:
                    getchar();
                    Registrarvoto(candidatos,partidos,nPartidos ,&votosVal, &votosNul, &votosBra, &nCandidatos);
                    break;
                case 2:
                    getchar();
                    if(votosVal <= 12){
                        printf("quantidade de votos validos nao alcancada! realize mais votos\n");
                        Registrarvoto(candidatos,partidos,nPartidos ,&votosVal, &votosNul, &votosBra, &nCandidatos);
                        break;
                    }
                    else{
                        flag = 0;
                        break;
                    }
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
        
// DADOS AUXILIARES PARA O RELATORIO
    QEleitoral = quocienteEleitoral(votosVal , VagasTotais);
    printf("\nqEleitoral: %d", QEleitoral);
    
    
    calculaVotosFederacao(federacoes, partidos, nFederacoes, nCandidatos);
// RELATORIO

    imprimeSecao1(votosVal, votosNul, votosBra, QEleitoral);
    getchar();
    imprimeSecao2(candidatos, nCandidatos);
    getchar();
    imprimeSecao3(partidos, federacoes, nPartidos, nFederacoes);
    getchar();
    imprimeSecao4(partidos, federacoes, nPartidos, nFederacoes, QEleitoral);
    getchar();
    ordenaCandidatos(candidatos, nCandidatos);
    candidatosEleitos(candidatos, partidos, federacoes, QEleitoral, nCandidatos, nPartidos, &QuantidadeEleitos, VagasTotais, nFederacoes);
    imprimirSecao5(candidatos, partidos, federacoes, nPartidos, nFederacoes);
    getchar();
    imprimirSecao6(candidatos, partidos, federacoes, nPartidos, nFederacoes);

    free(candidatos);
    free(partidos);
    free(federacoes);
    return 0;
}