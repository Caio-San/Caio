#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct{
    char nomeFederacao[50];
    char siglaFederacao[5];
    char siglaAfiliados[50][5];
    int votos;

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
    // função que imprime todos os votos dos candidatos
    
    int i;
    printf("\n* --------------------------------------- *\n");
    printf("*                                           *\n");
    printf("*   | r | e | l | a | t | o | r | i | o |   *\n");
    printf("* | p | a | r | t | e |   | d | o | i | s | *\n");
    printf("*                                           *\n");
    printf("* ----------------------------------------- *\n");
    for (i = 0; i< nCandidatos; i++){
        printf("\n");
        printf("Candidato(a): %s\n", candidatos[i].nomeCandidato);
        printf("Numero: %s\n", candidatos[i].digitos);
        printf("Quantidade de votos recebidos: %d\n", candidatos[i].votos);
        printf("\n");
    }
    
}

char* auxSecao1(int qtvotos){
    /* Função responsável por verificar quantos dígitos a quantidade de votos tem.

    Parâmetros:
        int qtVotos: quantidade de votos a ser analisada;
    Retorno:
        char* aux2: ponteiro para char que guarda a quantidade de espaços necessários para regular a tabela.
    */
    char aux[10];
    char *aux2 = NULL;
    int i;
    sprintf(aux,"%d", qtvotos);
    aux2 = (char *) malloc((16-strlen(aux))*sizeof(char));
    for(i=0; i<(int)(strlen(aux2)); i++){
        // strcpy(aux2[i], ' ');
        aux2[i] = ' ';
    }
    return aux2;

}

void imprimeSecao1(int votosVal, int votosNul, int votosBra, int qEleitoral){
    /* A função imprime a tabela com os valores: total de votos, votos válidos, 
    votos nulos, votos brancos e quociente Eleitoral.

    Parâmetros:
        int votosVal: quantidade de votos válidos;
        int votosNul: quantidade de votos nulos;
        int votosBra: quantidade de votos brancos;
        int qEleitoral
    */

    printf("\n* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* | r | e | l | a | t | o | r | i | o | *\n");
    printf("*   | p | a | r | t | e |   | u | m |   *\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* Total de votos: %d%s      *\n", (votosBra+votosNul+votosVal), auxSecao1(votosBra+votosNul+votosVal));
    printf("*                                       *\n");
    printf("* Votos válidos: %d%s       *\n", votosVal, auxSecao1(votosVal));
    printf("*                                       *\n");
    printf("* Votos nulos: %d%s         *\n", votosNul, auxSecao1(votosNul));
    printf("*                                       *\n");
    printf("* Votos brancos: %d%s       *\n", votosBra, auxSecao1(votosBra));
    printf("*                                       *\n");
    printf("* Quociente eleitoral: %d%s *\n", qEleitoral,auxSecao1(qEleitoral));
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
        if (isalpha(aux[i]) == 0 && (int)(aux[i]) != 32 && (int)(aux[i]) != 10){
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
        if((strcmp(aux, ptr[nFederacoes].siglaAfiliados[i])) == 0){   //ENTRA SE O AFILIADO JA ESTIVER CADASTRADO
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

int verificaNome(TipoCandidato *candidatos, int *tam, char *nome) {
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

int cadastraCandidato(TipoCandidato* candidatos, TipoPartido *partidos, int *tam, int *nCandidatos){
    char nomeaux[50],aux[50],digitosaux[6];
    int i,idadeaux=0;
    int partidoencontrado = 0;
    if (*nCandidatos >= *tam){
        *tam = (*tam)*2;
        candidatos = (TipoCandidato *) realloc(candidatos,(*tam)*sizeof(TipoCandidato));
        if (!candidatos) { 
            printf("Erro na realocacaoo de memoria!\n");
            return -1;
        }
    }
    while(1){
        printf("Digite o partido do candidato: ");
        fgets(aux, 50, stdin);
        aux[strcspn(aux, "\n")] = '\0';
        
        if (caracteresValidos(aux)){
            getchar();
            printf("\nDigite caracteres válidos!\n");
        }else{
            for(i=0;i<*tam;i++){
                if ((strcmp(aux, partidos[i].nomePartido)) == 0){
                    
                    printf("\nPartido escolhido com sucesso!\n");
                    strcpy(candidatos[*nCandidatos].partido, aux);
                    partidoencontrado = 1;
                    break;
                }
            }
            if (partidoencontrado == 1){
                break;
            }
            getchar();
            printf("\nPartido digitado não existe!\n");
        }
    }
    while(1){
        printf("\nDigite um nome para seu candidato: ");
        fgets(nomeaux, 50, stdin);
        nomeaux[strcspn(nomeaux, "\n")] = '\0';

        if ((caracteresValidos(nomeaux))){
            getchar();
            printf("\nDigite caracteres válidos!\n");
        }else{
            if ((verificaNome(candidatos, nCandidatos, nomeaux)) == 1){
                getchar();
                printf("\nNome do candidato já existente!\n");
            }else{
                getchar();
                strcpy(candidatos[*nCandidatos].nomeCandidato, nomeaux);
                break;
            }
        }
    }
    // Escolhe um nome para o candidato e verifica se é valido
    while(1){
        printf("\nDigite a idade do candidato: ");
        scanf("%d", &idadeaux);
        if (idadeaux <= 0){
            getchar();
            printf("\nDigite uma idade válida!\n");
        }else{
            getchar();
            candidatos[*nCandidatos].idade = idadeaux;
            break;
        }
    }
    // DEFINE A IDADE DO QUANDIDATO E VERIFICA SE É VÁLIDO
    while(1){
        printf("\nDigite os 5 digitos do candidato: ");
        fgets(digitosaux, 5, stdin); //ACRESCENTAR CASO DE ERRO PARA MENOS OU MAIS DE 5 DIGITOS LIDOS
        digitosaux[strcspn(digitosaux, "\n")] = '\0';
        if (verificanumeros(digitosaux)) {
            getchar();
            printf("\nDigite 5 dígitos válidos!\n");
        }else{
            getchar();
            strcpy(candidatos[*nCandidatos].digitos, digitosaux);
            break;
        }
    }
    // DEFINE OS DIGITOS DO CANDIDATO E VERIFICA SE É VALIDO
    (*nCandidatos)++;
    return 0;
}

int confirmaVoto(){
    int opcao;
    while(1){
        printf("\nSelecione uma opcao: ");
        if ((scanf("%d", &opcao)) > 0){
            switch (opcao){
                case 1:
                    getchar();
                    return 1;
                case 2:
                    getchar();
                    return 2;
                case 3:
                    getchar();
                    return 3;
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

void Registrarvoto(TipoCandidato* candidatos, int *votoVal, int *votoNul, int *votoBra, int* nCandidatos) {
    char auxDigito[5], voto[3];
    int indiceCandidato, flag =1;

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
                    printf("oi switch");
                    case 1:
                        if((strcmp(voto, "val"))== 0){
                            candidatos[indiceCandidato].votos = candidatos[indiceCandidato].votos + 1;
                            *votoVal = *votoVal +1;
                        }else{
                            *votoNul = *votoNul +1;
                        }
                        flag=0;
                        break;
                    case 2:
                        return Registrarvoto(candidatos,votoVal, votoNul,votoBra,nCandidatos);
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

void calculaVotosFederacao(TipoFederacao *ptr, int* nFederacoes){

}


int main(){
    // int i; //TESTE
    int opcao, flag=1;
    // int nPartidos=0, tamp=50, nFederacoes=0, tamf=50;
    int nPartidos=0, tamp=50, nFederacoes=0, tamf=50, nCandidatos=0, tamc=50;
    int votosVal = 0, votosBra = 0, votosNul = 0;
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
                    getchar();
                    if(nPartidos >0){
                        if ((cadastraCandidato(candidatos,partidos, &tamc, &nCandidatos) == 0)){                   
                            printf("\nCandidato cadastrado com sucesso!\n");                    
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
                    break;
            }
        }else{
            printf("\nOpcao invalida. Tente novamente!\n");
            getchar();
        }   
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
                    Registrarvoto(candidatos, &votosVal, &votosNul, &votosBra, &nCandidatos);
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
    }
    // TESTES -- NÃO APAGAR
    // printf("\nRESULTADO");
    // for(i=0; i<nCandidatos; i++){
    //     printf("\n%s: %d", candidatos[i].nomeCandidato, candidatos[i].votos);
    // }
    // printf("voto nulo: %d", votosNul);
    // printf("voto branco: %d", votosBra);
    // printf("voto valido: %d", votosVal);
    
        

// RELATORIO

    // imprimeSecao1(votosVal, votosNul, votosBra, qEleitoral);
    // imprimeSecao2(candidatos, nCandidatos);



    free(candidatos);
    free(partidos);
    free(federacoes);
    return 0;
}