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
    int qtCandidatos;
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
    char siglaPartido[5]; 
    int votos;

} TipoCandidato;

void imprimeMenuCadastro(){
    /* Função responsável por imprimir o menu de cadastros. */

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
    /* Função responsável por imprimir o menu de votação. */
    
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
    /* Função responsável por imprimir o menu de confirmação do voto. */

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
    /* Função responsável por imprimir o título da seção "Afiliados". */
    printf("\n* ------------------------------------ *\n");
    printf("*                                      *\n");
    printf("* | a | f | i | l | i | a | d| o | s | *\n");
    printf("*                                      *\n");
    printf("* ------------------------------------ *\n");
    printf("\nNota: Afilie um partido por vez\n");
}

void auxSecao1(int qtvotos){
    /* Função responsável por verificar quantos dígitos a 
    quantidade de votos tem.

    Parâmetros:
        int qtVotos: quantidade de votos a ser analisada.
    */
    char aux[10];
    int i;
    sprintf(aux,"%d", qtvotos);
    for(i=0; i<10 - (int)(strlen(aux)); i++){
        printf(" ");
    }
}

void imprimeSecao1(int votosVal, int votosNul, int votosBra, int qEleitoral){
    /* Função responsável por imprimir a Seção 1 do relatório.
    Dados a serem impressos: total de votos, votos válidos, votos nulos, votos 
    brancos e quociente Eleitoral.

    Parâmetros:
        int votosVal: quantidade de votos válidos;
        int votosNul: quantidade de votos nulos;
        int votosBra: quantidade de votos brancos;
        int qEleitoral: quociente eleitoral.
    */

    printf("\n* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* | r | e | l | a | t | o | r | i | o | *\n");
    printf("*                                       *\n");
    printf("*   | p | a | r | t | e |   | U | M |   *\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
    printf("*                                       *\n");
    printf("* Total de votos: %d            ", (votosBra+votosNul+votosVal));
    auxSecao1(votosBra+votosNul+votosVal);
    printf("*\n");
    printf("*                                       *\n");
    printf("* Votos validos: %d             ", votosVal);
    auxSecao1(votosBra+votosNul+votosVal);
    printf("*\n");
    printf("*                                       *\n");
    printf("* Votos nulos: %d                ", votosNul);
    auxSecao1(votosBra+votosNul+votosVal);
    printf("*\n");
    printf("*                                       *\n");
    printf("* Votos brancos: %d              ", votosBra);
    auxSecao1(votosBra+votosNul+votosVal);
    printf("*\n");
    printf("*                                       *\n");
    printf("* Quociente eleitoral: %d        ", qEleitoral);
    auxSecao1(votosBra+votosNul+votosVal);
    printf("*\n");
    printf("*                                       *\n");
    printf("* ------------------------------------- *\n");
}

void imprimeSecao2(TipoCandidato* candidatos, int nCandidatos){
    /* Função responsável por imprimir a Seção 2 do relatório.
    Dados a serem impressos: Nome do candidato e a quantidade de 
    votos que obteve.

    Parâmetros:
        TipoCandidato* candidatos: ponteiro para vetor que armazena 
            os dados dos candidatos cadastrados;
        int nCandidatos: quantidade de candidatos cadastrados.
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
        printf("Votos recebidos: %d\n", candidatos[i].votos);
    }
}

void imprimeSecao3(TipoPartido* partidos, TipoFederacao* federacoes, int nPartidos, int nFederacoes){
    /* Função responsável por imprimir a Seção 3 do relatório.
    Dados a serem impressos: Nome do partido/federação e a quantidade de votos que obteve.

    Parâmetros:
        TipoPartido* partidos: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        TipoFederacao* federacoes: ponteiro para vetor que armazena os dados das federações cadastradas;
        int nPartidos: quantidade de partidos cadastrados;
        int nFederacoes: quantidade de federações cadastradas.
    */
    int i, j, k, afiliado = 0;
    printf("\n* ----------------------------------------- *\n");
    printf("*                                           *\n");
    printf("*   | r | e | l | a | t | o | r | i | o |   *\n");
    printf("*                                           *\n");
    printf("* | p | a | r | t | e |   | T | R | E | S | *\n");
    printf("*                                           *\n");
    printf("* ----------------------------------------- *\n");
    
    for (i = 0; i< nFederacoes; i++){
        printf("\nFederacao: %s", federacoes[i].nomeFederacao);
        printf("\nVotos recebidos: %d\n", federacoes[i].votos);
    }
    for(i=0; i<nPartidos; i++){  //CHECA TODOS OS PARTIDOS
        afiliado = 0;
        for(j=0; j<nFederacoes; j++){  //CHECA TODAS AS FEDERAÇÕES
            for(k=0; k<federacoes[j].nAfiliados; k++){  //CHECA TODOS OS AFILIADOS DE UMA FEDEÇÃO
                //ENTRA SE O PARTIDO FOR AFILIADO
                if(strcmp(partidos[i].siglaPartido, federacoes[j].siglaAfiliados[k]) == 0){ 
                    afiliado = 1;
                    break;    
                }
            }if(afiliado == 1){
                break;
            }
        }if(afiliado == 0){
            printf("\nPartido: %s", partidos[i].nomePartido);
            printf("\nVotos recebidos: %d\n", partidos[i].votos);
        }
    }
}

int quocientePartidario(int QEleitoral ,int votosValidos){
    /*Função que calcula o Quociente Partidário.
    Quociente Partidário: votos válidos por cada partido/federação 
    dividido pelo quociente eleitoral
    
        Parâmetros:
            int QEleitoral: quociente eleitoral da eleição;
            int votosValidos: quantidade de votos válidos 
                recebido por um partido/federação;
            
        Retorno:
            int TotaldeCadeiras: quantidade de cadeiras que o 
                partido/federação terá direito na câmara.
        */
    int TotaldeCadeiras = votosValidos / QEleitoral;
    return TotaldeCadeiras;
}

void imprimeSecao4(TipoPartido* partidos, TipoFederacao* federacoes, int nPartidos, int nFederacoes, int qEleitoral){
    /* Função responsável por imprimir a Seção 4 do relatório.
    Dados a serem impressos: Nome do partido/federação e o seu respectivo quacioente partidário.

    Parâmetros:
        TipoPartido* partidos: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        TipoFederacao* federacoes: ponteiro para vetor que armazena os dados das federações cadastradas;
        int nPartidos: quantidade de partidos cadastrados;
        int nFederacoes: quantidade de federações cadastradas;
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

    for (i = 0; i< nFederacoes; i++){
        printf("\nFederacao: %s", federacoes[i].nomeFederacao);
        federacoes[i].qPartidario = quocientePartidario(qEleitoral ,federacoes[i].votos);
        printf("\nQuociente partidario: %d\n", federacoes[i].qPartidario);
    }
    //CHECA TODOS OS PARTIDOS
    for(i=0; i<nPartidos; i++){ 
        afiliado = 0;
        //CHECA TODAS AS FEDERAÇÕES
        for(j=0; j<nFederacoes; j++){ 
            //CHECA TODOS OS AFILIADOS DE UMA FEDEÇÃO
            for(k=0; k<federacoes[j].nAfiliados; k++){ 
                //ENTRA SE O PARTIDO FOR AFILIADO
                if(strcmp(partidos[i].siglaPartido, federacoes[j].siglaAfiliados[k]) == 0){ 
                    afiliado = 1;
                    break;    
                }
            }
            if(afiliado == 1){
                break;
            }
        }if(afiliado == 0){
            printf("\nPartido: %s", partidos[i].nomePartido);
            partidos[i].qPartidario = quocientePartidario(qEleitoral ,partidos[i].votos);
            printf("\nQuociente partidario: %d\n", partidos[i].qPartidario);
        }
    }
}

void imprimirSecao5(TipoCandidato* candidatos, TipoPartido* partidos, TipoFederacao* federacoes, int nPartidos, int nFederacoes){
    /* Função responsável por imprimir a Seção 5 do relatório.
    Dados a serem impressos: Nome dos candidatos eleitos e o nome dos seus respectivos partidos.

    Parâmetros:
        TipoCandidato* candidatos: ponteiro para vetor que armazena os dados dos candidatos cadastrados;
        TipoPartido* partidos: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        TipoFederacao* federacoes: ponteiro para vetor que armazena os dados das federações cadastradas;
        int nPartidos: quantidade de partidos cadastrados;
        int nFederacoes: quantidade de federações cadastradas.
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

    for(i=0; i<nPartidos; i++){ //CHECA TODOS OS PARTIDOS
        afiliado = 0;
        //CHECA TODAS AS FEDERAÇÕES
        for(j=0; j<nFederacoes; j++){ 
            //CHECA TODOS OS AFILIADOS DE UMA FEDEÇÃO
            for(k=0; k<federacoes[j].nAfiliados; k++){ 
                //ENTRA SE O PARTIDO FOR AFILIADO
                if(strcmp(partidos[i].siglaPartido, federacoes[j].siglaAfiliados[k]) == 0){ 
                    afiliado = 1;
                    break;    
                }
            }if (afiliado && !federacoes[j].impresso){
                printf("\nFederacao: %s", federacoes[j].nomeFederacao);
                printf("\n");
                for(h=0; h< federacoes[j].qtEleitoSuplente[0]; h++){
                    printf("Candidato: %s", candidatos[federacoes[j].indiceEleitos[h]].nomeCandidato);
                }federacoes[j].impresso = 1;
            }else if(!afiliado && !partidos[i].impresso){
                printf("\nPartido: %s\n", partidos[i].nomePartido);
                printf("\n");
                for(h=0; h< partidos[i].qtEleitoSuplente[0]; h++){
                    printf("Candidato: %s", candidatos[partidos[i].indiceEleitos[h]].nomeCandidato);
                }partidos[i].impresso = 1;
            }    
        }
    }
}

void imprimirSecao6(TipoCandidato* candidatos, TipoPartido* partidos, TipoFederacao* federacoes, int nPartidos, int nFederacoes){
    /* Função responsável por imprimir a Seção 6 do relatório.
    Dados a serem impressos: Nome dos candidatos suplentess e o nome dos seus respectivos partidos.

    Parâmetros:
        TipoCandidato* candidatos: ponteiro para vetor que armazena os dados dos candidatos cadastrados;
        TipoPartido* partidos: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        TipoFederacao* federacoes: ponteiro para vetor que armazena os dados das federações cadastradas;
        int nPartidos: quantidade de partidos cadastrados;
        int nFederacoes: quantidade de federações cadastradas.
    */
    int i, j, k,h, afiliado, qtSuplentes = 0;
    printf("\n* --------------------------------------------- *\n");
    printf("*                                               *\n");
    printf("*     | r | e | l | a | t | o | r | i | o |     *\n");
    printf("*                                               *\n");
    printf("* | p | a | r | t | e |   | S | E | I | S |     *\n");
    printf("*                                               *\n");
    printf("*     | S | U | P | L | E | N | T | E | S |     *\n");
    printf("*                                               *\n");
    printf("* --------------------------------------------- *\n");

    for(i=0; i<nPartidos; i++){ //CHECA TODOS OS PARTIDOS
        afiliado = 0;
        //CHECA TODAS AS FEDERAÇÕES
        for(j=0; j<nFederacoes; j++){
            //CHECA TODOS OS AFILIADOS DE UMA FEDEÇÃO 
            for(k=0; k<federacoes[j].nAfiliados; k++){
            //ENTRA SE O PARTIDO FOR AFILIADO
                if(strcmp(partidos[i].siglaPartido, federacoes[j].siglaAfiliados[k]) == 0){ 
                    afiliado = 1;
                    break;    
                }
            }if (afiliado && !federacoes[j].impresso && federacoes[j].qtEleitoSuplente[1] >0){
                printf("\nFederacao: %s\n", federacoes[j].nomeFederacao);
                qtSuplentes = 1;
                for(h=0; h< federacoes[j].qtEleitoSuplente[1]; h++){
                    printf("\nCandidato: %s", candidatos[federacoes[j].indiceSuplentes[h]].nomeCandidato);
                }
            }else if(!afiliado && !partidos[i].impresso && partidos[i].qtEleitoSuplente[1] >0){
                printf("\nPartido: %s\n", partidos[i].nomePartido);
                qtSuplentes = 1;
                for(h=0; h< partidos[i].qtEleitoSuplente[1]; h++){
                    printf("\nCandidato: %s", candidatos[partidos[i].indiceSuplentes[h]].nomeCandidato);
                }
            }    
        }
    }if(!qtSuplentes){
        printf("\nNao ha suplentes.");
    }
}

void zeraPartidos(TipoPartido* partidos, int nPartidos){
    /* Função responsável por inicializar determinados campos 
    da struct TipoPartido em partidos.

    Parâmetros:
        TipoPartido* partidos: ponteiro para vetor que 
            armazena os dados dos partidos cadastrados;
        int nPartidos: quantidade de partidos cadastrados.
    */
    partidos[nPartidos].votos = 0;
    partidos[nPartidos].qtCandidatos = 0;
    partidos[nPartidos].qtEleitoSuplente[0] = 0;
    partidos[nPartidos].qtEleitoSuplente[1] = 0;
    partidos[nPartidos].impresso = 0;
}

void zeraFederacoes(TipoFederacao* federacoes, int nFederacoes){
    /* Função responsável por inicializar determinados campos da struct TipoFederacao em federacoes.

    Parâmetros:
        TipoFederacao* federacoes: ponteiro para vetor que armazena os dados das federações cadastradas;
        int nFederacoes: quantidade de federações cadastradas.
    */
    federacoes[nFederacoes].votos = 0;
    federacoes[nFederacoes].nAfiliados = 0;
    federacoes[nFederacoes].qtEleitoSuplente[0] = 0;
    federacoes[nFederacoes].qtEleitoSuplente[1] = 0;
    federacoes[nFederacoes].impresso = 0;
}

int caracteresVal(char *str) {
    /* Função responsável por verificar se os carecteres inseridos 
    são letras maiúsculas ou minúsculas.

    Parâmetros:
        char *str: ponteiro pra um string que armazena a entrada 
            de carateres do usuario.
        
    Retorno:
        0: Não há caracteres inválidos;
        1: Há caracteres inválidos;
    */
    for (int i = 0; i < (int)strlen(str); i++) {
        if (!isalpha(str[i]) && !isspace(str[i]) && (int)(str[i]) != 10) {
            return 1;
        }
    } return 0;
}

int maiximoSigla(char *sigla){
    /*Função responsável por verificar se a entrada 
    inserida para a sigla possui no máixmo 5 caracteres
    
        Parâmetros:
            char *sigla: Ponteiro para string que recebe 
                a entrada do usuário para a sigla.

        Retorno:
            int 0: entrada aceita.
            int 1: se forem inseridos mais de 5 caracteres.
    */
    if (strlen(sigla) > 5) {
        return 1;
    } return 0;
}

int jaExistePartido(int nPartidos, char aux[], TipoPartido* partidos, char tipo[]){
    /* Função responsável por verificar se o nome/sigla do partido já existe.
    
    Parâmetros:
        int nPartidos: número de partidos cadastrados;
        char aux[]: nome/sigla a ser verificada;
        TipoPartido* partidos: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        char tipo[]: identificador de operação ("nome"/"sigla").

    Retorno:
        int 0: o partido não existe;
        int 1: o partido já existe.
    */
    int i;
    //VERIFICA SE O PARTIDO JÁ EXISTE
    for(i=0; i<nPartidos; i++){   
        if((strcmp(tipo, "nome")) == 0){
            //ENTRA SE O PARTIDO JÁ EXISTIR
            if((strcmp(aux, partidos[i].nomePartido)) == 0){   
                return 1;
            }
        }else{
            //ENTRA SE A SIGLA JÁ EXISTIR
            if((strcmp(aux, partidos[i].siglaPartido)) == 0){   
                return 1;
            }
        }
    } return 0;
}

int cadastraPartido(TipoPartido* partidos , int* nPartidos, int* tam){
    /* A função tem o objetivo de cadastrar novos partidos. Coleta os dados do
    partido e verifica a validade dos dados inseridos. Caso todos os 
    dados sejam válidos, o partido será cadastrado. Se não, será executada 
    uma ação apropriada ao caso.

    Parâmetros:
        TipoPartido* partidos: ponteiro para vetor que armazena os dados 
            dos partidos cadastrados;
        int* nPartidos: ponteiro para inteiro que guarda a quantidade de 
            partidos cadastrados;
        int* tam: ponteiro para inteiro que guarda o tamanho atual do vetor;
    Retorno:
        int 0: novo cadastro concluído com sucesso;
        int 1: novo cadastro falhou. 
    */ 
    char nomeAux[50], siglaAux[5];
    if (*nPartidos >= *tam){
        *tam = (*tam)*2;
        partidos = (TipoPartido *) realloc(partidos,(*tam)*sizeof(TipoPartido));
    }
    while(1){
        printf("\nDigite o nome do partido: ");
        //ENTRA NO IF SE A LEITURA FOR VÁLIDA (CARACTERES)
        if((scanf("%[^\n]", nomeAux)) > 0){
            getchar();
            if (caracteresVal(nomeAux) == 0){   //VERIFICA SE TODOS OS CARACTERES SÃO VÁLIDOS
                if (jaExistePartido(*nPartidos, nomeAux, partidos, "nome") == 1){   //VERIFICA SE O PARTIDO JÁ EXISTE
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
        if(scanf("%[^\n]", siglaAux) > 0){
            getchar();
            if (caracteresVal(siglaAux) == 0){
                if (maiximoSigla(siglaAux) == 0){
                    if (jaExistePartido(*nPartidos, siglaAux, partidos, "sigla") == 1){
                        printf("\nSigla ja existente. Tente novamente!");
                    }else{
                        break;
                    }
                }else{
                    printf("\nInsira no maximo 5 caracteres para a sigla");
                }
            }else{
                printf("\nCaracteres invalidos. Tente novamente!");
            }
        }else{
            printf("\nEntrada invalida. Tente novamente!");
            getchar();
        }                  
    }
    strcpy(partidos[*nPartidos].nomePartido, nomeAux);
    strcpy(partidos[*nPartidos].siglaPartido, siglaAux);
    zeraPartidos(partidos, *nPartidos);
    partidos[*nPartidos].impresso = 0;
    partidos[*nPartidos].qtCandidatos = 0;
    (*nPartidos) ++;
    return 0;     
}   

int jaExisteAfiliado(int nFederacoes, char aux[], TipoFederacao* federacoes){
    /* Função responsável por checar se o partido já está filiado à respectiva federação.

    Parâmetros:
        int nFederacoes: quantidade de federações cadastradas;
        char aux[]: sigla do partido a ser afiliado;
        TipoFederacao* federacoes: ponteiro para vetor que armazena os dados das federacoes cadastradas;
    Retorno:
        int 0: partido já afiliado;
        int 1: partido não afiliado. 
    */
    int i;
    for(i=0; i<federacoes[i].nAfiliados; i++){
        //ENTRA SE O AFILIADO JA ESTIVER CADASTRADO
        if((strcmp(aux, federacoes[nFederacoes-1].siglaAfiliados[i])) == 0){   
            return 1;
        }
    } return 0;
}

void registraAfiliados(TipoFederacao* federacoes, TipoPartido* partidos, int nPartidos, int nFederacoes, int afiliados){
    /* Função responsável por registrar os afiliados na respectiva federação. Coleta a sigla dos 
    partidos a serem afiliados e verifica se a sigla pertence a um partido cadastrado.
    Não é possivel afiliar menos de dois partidos por federação.
    
    Parâmetros:
        TipoFederacao* federacoes: ponteiro para vetor que armazena os dados das federações cadastradas;
        TipoPartido* partidos: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        int nPartidos: quantidade de partidos cadastrados;
        int nFederacoes: quantidade de federações cadastradas;
        int afiliados: quantidade de afiliados cadastrados.
    */
    char siglaAux[5];
    int opcao;
    
    while(1){
        printf("\nDigite a sigla do partido a ser afiliado: ");
        //ENTRA NO IF SE A LEITURA FOR VÁLIDA (CARACTERES)
        if((scanf("%s", siglaAux)) > 0){
            if (caracteresVal(siglaAux) == 0){   //VERIFICA SE TODOS OS CARACTERES SÃO VÁLIDOS
                if (jaExistePartido(nPartidos, siglaAux, partidos, "sigla") == 1){   //VERIFICA SE O PARTIDO EXISTE
                    if((jaExisteAfiliado( nFederacoes, siglaAux, federacoes)) == 0){
                        strcpy(federacoes[nFederacoes-1].siglaAfiliados[afiliados], siglaAux);
                        federacoes[nFederacoes-1].nAfiliados += 1;
                        afiliados ++;
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
    if(federacoes[nFederacoes-1].nAfiliados >= 2){
        printf("\nDeseja afiliar outro partido?");
        getchar();
        while(1){
            printf("\n(1) Sim\n(2) Nao\nSelecione uma opcao: ");
            if ((scanf("%d", &opcao)) > 0){
                switch (opcao){
                    case 1:
                        return registraAfiliados(federacoes, partidos, nPartidos, nFederacoes, afiliados+1);
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
        return registraAfiliados(federacoes, partidos, nPartidos, nFederacoes, afiliados);
    } 
}

int jaExisteFederacao(int* nFederacoes, char aux[], TipoFederacao* federacoes, char tipo[]){
    /* Função responsável por verificar se o nome ou sigla a ser cadastrado já existe 
    no banco de dados.

    Parâmetros:
        int* nFederacoes: quantidade de federações cadastradas;
        char aux[]: string a ser verificada;
        TipoFederacao* federacoes: ponteiro para vetor que armazena os dados das 
            federações cadastradas;
        char tipo[]: string que define se será verificado um nome ou sigla.
    Retorno:
        int 0: não existe;
        int 1: existe..
    */
    int i;
    //VERIFICA SE O PARTIDO JÁ EXISTE
    for(i=0; i<*nFederacoes; i++){   
        if((strcmp(tipo, "nome")) == 0){
            //ENTRA SE O NOME JÁ EXISTIR
            if((strcmp(aux, federacoes[i].nomeFederacao)) == 0){   
                return 1;
            }
        }else{
            //ENTRA SE A SIGLA JÁ EXISTIR
            if((strcmp(aux, federacoes[i].siglaFederacao)) == 0){   
                return 1;
            }
        }
    } return 0;
}

int registraFederacao(TipoFederacao* federacoes, int* nFederacoes, int* tam){
    /* A função tem o objetivo de registrar novas federações. Coleta os dados da
    federação e verifica a validade dos dados inseridos. Caso todos os 
    dados sejam válidos, a federação será registrada.

    Parâmetros:
        TipoFederacao* federacoes: ponteiro para vetor que armazena os dados 
            das federações cadastradas;
        int* nFederacoes: ponteiro para inteiro que guarda a quantidade de 
            federações cadastradas;
        int* tam: ponteiro para inteiro que guarda o tamanho atual do vetor;
    Retorno:
        int 0: novo cadastro concluído com sucesso;
        int 1: novo cadastro falhou. 
    */ 

    char nomeAux[50], siglaAux[5];
    if (*nFederacoes >= *tam){
        *tam = (*tam)*2;
        federacoes = (TipoFederacao *) realloc(federacoes,(*tam)*sizeof(TipoFederacao));
    }
    while(1){
        printf("\nDigite o nome da federacao: ");
        getchar();
        //ENTRA NO IF SE A LEITURA FOR VÁLIDA (CARACTERES)
        if((scanf("%[^\n]", nomeAux)) > 0){
            //VERIFICA SE TODOS OS CARACTERES SÃO VÁLIDOS
            if (caracteresVal(nomeAux) == 0){   
                //VERIFICA SE A FEDERACAO JÁ EXISTE
                if (jaExisteFederacao(nFederacoes, nomeAux, federacoes, "nome") == 1){   
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
        if(scanf("%[^\n]", siglaAux) > 0){
            getchar();
            if (caracteresVal(siglaAux) == 0){
                if (maiximoSigla(siglaAux) == 0){
                    if (jaExisteFederacao(nFederacoes, siglaAux, federacoes, "sigla") == 1){
                        printf("\nSigla ja existente. Tente novamente!");
                    }else{
                        break;
                    }
                }else{
                    printf("\nInsira no maximo 5 caracteres para a sigla");
                }
            }else{
                printf("\nCaracteres invalidos. Tente novamente!");
            }
        }else{
            printf("\nEntrada invalida. Tente novamente!");
            getchar();
        }                  
    }

    strcpy(federacoes[*nFederacoes].nomeFederacao, nomeAux);
    strcpy(federacoes[*nFederacoes].siglaFederacao, siglaAux);
    federacoes[*nFederacoes].impresso = 0;
    zeraFederacoes(federacoes, *nFederacoes);
    (*nFederacoes)++;
    return 0;    
}

int verificaNome(TipoCandidato* candidatos, int* tam, char* nome) {
    /* Função responsável por verificar se o nome inserio pelo candidato 
    já foi cadastrado por outro candidato
    
    Parâmetros: 
        TipoCandidato* candidatos: ponteiro para vetor que armazena os 
            dados dos candidatos cadastrados;
        int* tam: Ponteiro de inteiro para a variável que armazena o 
            tamanho do vetor candidatos.
        char* nome: Ponteiro char para variável que armazena a string 
            com o o nome do candidato.

    Retorno:
        int 0: nome válido;
        int 1: nome inválido.
        */
    int i;
    for (i = 0; i < *tam; i++) {
        if (strcmp(candidatos[i].nomeCandidato, nome) == 0) {
            return 1;
        }
    } return 0;
}

int verificaNum(char* aux) {
    /* Função responsável por verificar se a entrada inserida são de digitos entre 0 e 9.
    Ultiliza a funçao !isdigit da biblioteca ctype.h e analisa cada caractere da string.

    Parâmetros:
        char *aux: Ponteiro para string que armazena a entrada do usuario.
    Retorno:
        int 0: caracteres são válidos;
        int 1: há caractere inválido.
    */
    for (int i = 0; i < (int)(strlen(aux)); i++) {
        if (!isdigit(aux[i])) {
            return 1; 
        }       
    } return 0;
}

void zeraImpresso(TipoFederacao *federacoes, TipoPartido* partidos, int nPartidos, int nFederacoes){
    /*Função responsável por inicializar a variável 'impresso' nos vetores 'federacoes' e 'partidos'
        Parâmetros:
            TipoFederacao* federacoes: ponteiro para vetor que armazena os dados das federações cadastradas;
            int nFederacoes: ponteiro para inteiro que guarda a quantidade de federações cadastradas;
            TipoPartido* partidos: ponteiro para vetor que armazena os dados dos partidos cadastrados;
            int nPartidos: quantidade de partidos cadastrados;
            */
    int i;
    for(i=0; i< nFederacoes; i++){
        federacoes[i].impresso = 0;
    }
    for(i=0; i< nPartidos; i++){
        partidos[i].impresso = 0;
    }
}

int jaExisteCandidato(int* nCandidatos, char aux[], TipoCandidato* partidos, char tipo[], int* indiceCandidato){
    /* Função responsável por verificar se o candidato já existe no banco de dados.

    Parâmetros:
        int* nCandidatos: ponteiro para inteiro que armazena a quantidade de cadidatos cadastrados;
        char aux[]: string a ser verificada;
        TipoCandidato* partidos: ponteiro para TipoCandidato que armazena as informações dos candidatos 
            já cadastrados;
        char tipo[]: char que define o que será verificado.
        int* indiceCandidato: localização do candidato em candidatos.

    Retorno:
        int 0: candidato não existe;
        int 1: candidato já existe.
    */
    int i;
    for(i=0; i<*nCandidatos; i++){ //VERIFICA SE O CANDIDATO JÁ EXISTE
        if((strcmp(tipo, "nome")) == 0){
            //ENTRA SE O CANDIDATO JÁ EXISTIR
            if((strcmp(aux, partidos[i].nomeCandidato)) == 0){   
                return 1;
            }
        }else{
            //ENTRA SE OS DIGITOS JÁ EXISTIREM
            if((strcmp(aux, partidos[i].digitos)) == 0){   
                *indiceCandidato = i;
                return 1;
            }
        }
    } return 0;
}

int verificaId(int idade) {
    /* Função responsável por verificar se a idade inserida pelo usuário 
    está dentro do limite permitido.
        
    Parâmetros:
        int idade: idade inserida pelo usuário.
    Retorno:
        int 0: idade inválida;
        int 1: idade válida.
    */
    return (idade >= 10 && idade <= 25);
}

int numeromax(char* digitos) {
    /* Função responsável por verificar se a entrada do usuario 
    possui exatamente a quantidade de 5 caracteres.
    
    Parâmetros:
        char* digitos: Ponteiro para string que recebe a 
            entrada dos digitos do usuario;

    Retorno:  
        int 0: entrada válida;
        int 1: entrada inválida.
        */
    if (digitos == NULL || strlen(digitos) != 5) {
        return 1;
    } return 0;
}

int validaNomeCandidato(TipoCandidato *candidatos, int nCandidatos, char *nomeaux) {
    /*Função responsável por receber a entrada para o nome do candidato, armazenar em 
    uma variavel char e verificar se ela é válida. Sempre que a entrada for inválida, 
    a funçao vai receber uma nova entrada. Se a entrada for válida, vai armazenar o 
    nome no vetor candidato.
    
    Parâmetros:
        TipoCandidato* candidatos: ponteiro para TipoCandidato que armazena as 
            informações dos candidatos já cadastrados;
        int nCandidatos: quantidade de cadidatos cadastrados;
        char *nomeaux: armazena o nome inserido pelo usuario.
            
    Retorno:
        int 0: validação concluída com sucesso.
    */
    int i,candidatoExistente;
    while (1) {
        candidatoExistente=0;
        getchar();
        printf("Digite um nome para seu candidato: ");
        fgets(nomeaux, 50, stdin);
        
        if (caracteresVal(nomeaux)) {
            printf("Digite caracteres validos!\n");
        }else{
            for (int i = 0; i < nCandidatos; i++) {
                if (strcmp(candidatos[i].nomeCandidato, nomeaux) == 0) {
                    printf("Nome do candidato ja existente!\n");
                    candidatoExistente = 1;
                }
            }    
            if (candidatoExistente == 0){
                strcpy(candidatos[nCandidatos].nomeCandidato, nomeaux);
                return 0;
            }         
        }
    }
}

int validaIdadeCandidato(TipoCandidato* candidatos, int nCandidatos) {
    /*Função responsável por receber a entrada para a idade do candidato, 
    armazenar em uma variavel int e verificar se ela é válida.
    Sempre que a entrada for inválida, a função vai receber uma nova entrada. 
    Se a entrada for válida, vai armazenara idade no vetor candidato.
    
    Parâmetros:
        TipoCandidato* candidatos: ponteiro para TipoCandidato que armazena as 
            informações dos candidatos já cadastrados;
        int nCandidatos: quantidade de 
            cadidatos cadastrados.
        
    Retorno:
        int 0: entrada válida;
        int 1: entrada inválida.
    */
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
            candidatos[nCandidatos].idade = idadeaux;
            return 0;
        } else {
            printf("\nValor invalido! A idade deve estar entre 10 e 25 anos.\n");
        }
    }
}

int validaDigitosCandidato(TipoCandidato *candidatos, int nCandidatos) {
    /* Função responsável por receber a entrada para os digitos do candidato, armazenar 
    em uma variável char e verificar se ela é vélida. Sempre que a entrada for inválida, 
    a função vai receber uma nova entrada. Se a entrada for válida vai armazenar a idade 
    no vetor candidato.
    A entrada é inválida caso seja inserido uma quantidade diferente de 5 dígitos OU 
    caso os digitos já estejam registrados por outro candidato.

    Parâmetros:
        TipoCandidato* candidatos: ponteiro para TipoCandidato que armazena as informações dos 
            candidatos já cadastrados;
        int nCandidatos: quantidade de cadidatos cadastrados;    
    Retorno:
        int 0: validação concluída com sucesso. 
    */
    char digitosaux[6];
    int digitosencontrado;

    while (1) {
        getchar();
        printf("\nDigite os 5 digitos do candidato: ");
        scanf("%s", digitosaux); 

        if (verificaNum(digitosaux)) {
            printf("\nDigite 5 dígitos validos!\n");
        } else if (numeromax(digitosaux)) {
            printf("Deve ser inserido 5 digitos totais!\n");
        } else {
            digitosencontrado = 0;
            for (int i = 0; i < nCandidatos; i++) {
                if (strcmp(digitosaux, candidatos[i].digitos) == 0) {
                    printf("Esses digitos já foram selecionados por outro candidato!\n");
                    digitosencontrado = 1;
                    break;
                }
            }  
            if (digitosencontrado == 0) {
                strcpy(candidatos[nCandidatos].digitos, digitosaux);
                return 0;
            }          
        }
    }
}

int validaPartidoCandidato(TipoCandidato *candidatos, TipoPartido *partidos, int nPartidos, int nCandidatos) {
    /* Função responsável por receber a entrada para a o partido do candidato e verificar se é válido.
    Se o partido não existir, a entrada será inválida e o procedimento de cadastro vai falhar.

    Parâmetros:
        TipoCandidato* candidatos: ponteiro para TipoCandidato que armazena as informações dos candidatos 
            já cadastrados;
        TipoPartido* partidos: ponteiro para TipoPartido que armazena as informações dos partidos 
            já cadastrados;
        int nPartidos: quantidade de partidos cadastrados;
        int nCandidatos: vetor para inteiro que armazena a quantidade de candidatos cadastrados;
    Retorno:
        int 0: entrada válida;
        int -1: entrada inválida.
    */
    char aux[5];
    int i=0;

    while (1) {
        getchar();
        printf("\nDigite a sigla do partido do candidato: ");
        fgets(aux, 5, stdin);
        aux[strcspn(aux, "\n")] = '\0';

        if (caracteresVal(aux)) {
            printf("Digite caracteres validos!\n");
        } else {
      
            for (i = 0; i < nPartidos; i++) {
                if (strcmp(aux, partidos[i].siglaPartido) == 0) {
                    printf("Partido escolhido com sucesso!\n");
                    partidos[i].qtCandidatos = partidos[i].qtCandidatos +1 ;
                    strcpy(candidatos[nCandidatos].siglaPartido, aux);
                    return 0;
                }
            }
            printf("Partido digitado nao existe!\n");
            return -1;
        }
    }
}

int cadastraCandidato(TipoCandidato* candidatos, TipoPartido* partidos, int* tam, int* nCandidatos, int nPartidos) {
    /*Função responsável por receber as entradas paras as informações dos candidatos: nome, idade, dígitos e partido.
    Verifica se cada entrada é valida e se atende aos critérios. Se as entradas forem validas, serão armazenadas no 
    vetor candidatos. Então será contabilizado mais um candidato cadastrado na eleiçao. Se a quantidade de candidatos 
    cadastrados exceder o tamanho do vetor candidatos, o vetor candidatos será realocado.

    Parâmetros:
        TipoCandidato* candidatos: ponteiro para vetor que armazena as informações dos candidatos cadastrados;
        TipoPartido* partidos: ponteiro para vetor que armazena as informações dos partidos cadastrados;
        int* tam: tamanho do vetor 'candidatos;
        int* nCandidatos: ponteiro para inteiro que armazena a quantidade de cadidatos cadastrados;
        int nPartidos: quantidade de partidos cadastrados.
        
    Retorno:
        int 0: procedimento realizado com sucesso;
        int -1: o procedimento falhou.
        */
    char nomeaux[50];

    if (*nCandidatos == *tam) {
        *tam = (*tam) * 2;
        candidatos = (TipoCandidato *) realloc(candidatos, (*tam) * sizeof(TipoCandidato));
        if (!candidatos) {
            printf("\nErro na realocacao de memoria!\n");
            return -1;
        }
    }

    if (validaPartidoCandidato(candidatos, partidos, nPartidos, *nCandidatos) != 0) return -1;
    if (validaNomeCandidato(candidatos, *nCandidatos, nomeaux) != 0) return -1;
    if (validaIdadeCandidato(candidatos, *nCandidatos) != 0) return -1;
    if (validaDigitosCandidato(candidatos, *nCandidatos) != 0) return -1;
    
    candidatos[*nCandidatos].votos = 0;
    (*nCandidatos)++;
    return 0;
}

int confirmaVoto(){
    /* Função responsável por verificar a escolha do usuário e retornar o opção escolhida.
    A função apresenta um laço que recebe a entrada do usuário para uma das 3 opçoes disponiveis.
    Caso seja digitado um valor diferente será impresso que a opção é inválida e será pedida uma nova entrada.

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

void Registrarvoto(TipoCandidato *candidatos,TipoPartido *partidos, int nPartidos, int *votoVal, int *votoNul, int *votoBra, int *nCandidatos) {
    /* Função responsável por registrar o voto do usuário. Caso o número inserido pertença a algum candidato, o voto 
    será contabilizado para o respectivo candidato e, também, ao partido que o candidato pertence.
    Caso contrário, será contabilizado voto nulo ou branco.

    Parâmetros:
        TipoCandidato *candidatos: ponteiro para TipoCandidato que armazena as informações dos candidatos já cadastrados;
        TipoPartido *partidos: ponteiro para TipoPartido que armazena as informações dos partidoss já cadastrados;
        int nPartidos: quantidade de partidos cadastrados;
        int *votoVal: ponteiro para inteiro que armazena a quantidade de votos válidos;
        int *votoNul: ponteiro para inteiro que armazena a quantidade de votos válidos;
        int *votoBra: ponteiro para inteiro que armazena a quantidade de votos válidos;
        int *nCandidatos: ponteiro para inteiro que armazena a quantidade de candidatos já cadastrados;
    */ 
    char auxDigito[5], voto[4], aux[50];
    int indiceCandidato=0, flag =1, i;

    while(flag){
        printf("\nDigite o numero do candidato: ");
        if((scanf("%s", auxDigito) > 0)){
            if((verificaNum(auxDigito)) == 0){
                if((jaExisteCandidato(nCandidatos, auxDigito, candidatos, "digito", &indiceCandidato)) == 1){
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
    Um laço que atualizada quantidade de votos por federaçoes conforme um dos partidos afiliados recebe um novo voto.

    Parâmetros:
        TipoFederacao* federacoes: ponteiro para vetor que armazena os dados das federações cadastradas;
        TipoPartido* partidos: ponteiro para vetor que armazena os dados dos partidos cadastrados;
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
    /* Função responsável por calcular o quociente eleitoral: votos válidos divididos pelo numero de vagas.
    O cálculo está considerando a parte fracionária do quociente eleitoral da seguinte forma:
        Em caso da parte fracionaria maior ou igual a 0.5, o quociente equivale a parte inteira;
        Caso contrario o quocinte equivale a parte inteira somado de 1.
    
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
        //printf("parte inteira %d", parteInteira);
        return parteInteira;

    }else{
        return parteInteira + 1;
    }
}

void ordenaCandidatos(TipoCandidato* candidatos, int nCandidatos){
    /* Função responsável por ordenar o vetor de candidatos em ordem 
    decrescente de quantidade de votos. Ultiliza do algortimo bubble sort para 
    ordenar os candidatos em ordem decrescente de votos, em caso de empate de 
    votos entre os candidatos é considerado o critério de maior idade para desempate.

    Parâmetros:
        TipoCandidato *candidatos: ponteiro para o vetor que armazena as informaçoes 
            dos candidatos;
        int nCandidatos: inteiro que armazena a quantidade de cadidatos cadastrados;
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

void vagasRemanescentes(TipoPartido *partidos, TipoFederacao  *federacoes, int nPartidos,int nFederacoes){
    /* Função que preenche as vagas remanescentes de partidos e federações com suplentes.
    Para cada partido e federação, enquanto houver vagas disponíveis e suplentes disponíveis, os suplentes
    são promovidos para as vagas disponíveis.

    Parâmetros:
        TipoPartido *partidos: ponteiro para vetor que armazena os dados dos partidos cadastrados;
        TipoFederacao *federacoes: ponteiro para vetor que armazena os dados das federações cadastradas;
        int nPartidos: armazena a quantidade de partidos cadastrados;
        int nFederacoes: armazena a quantidade de federacoes cadastradas.    
    */
    int i;
    for (i = 0; i < nPartidos; i++) {
        while (partidos[i].qtEleitoSuplente[0] < partidos[i].qPartidario && partidos[i].qtEleitoSuplente[1] > 0) {
            partidos[i].indiceEleitos[partidos[i].qtEleitoSuplente[0]] = partidos[i].indiceSuplentes[--partidos[i].qtEleitoSuplente[1]];
            partidos[i].qtEleitoSuplente[0]++;
        }
    }

    for (i = 0; i < nFederacoes; i++) {
        while (federacoes[i].qtEleitoSuplente[0] < federacoes[i].qPartidario && federacoes[i].qtEleitoSuplente[1] > 0) {
            federacoes[i].indiceEleitos[federacoes[i].qtEleitoSuplente[0]] = federacoes[i].indiceSuplentes[--federacoes[i].qtEleitoSuplente[1]];
            federacoes[i].qtEleitoSuplente[0]++;
        }
    }
}

void armazenaEleitos(TipoPartido *partidos, TipoFederacao *federacoes,int indiceCandidato,int indicePartido, int indiceFederacao, int afiliado, int eleito){
       /* Função que armazena os candidatos eleitos e os suplentes para partidos e federações. Dependendo do parâmetro 'eleito',
        a função armazena o candidato como eleito ou como suplente. Se eleito for igual a 2 signfica que o candidato atendeu
        aos criterios de eleição, caso contrario o candidato é armazenado como suplente.
        
        Parâmetros:
            TipoPartido *partidos: ponteiro para vetor que armazena os dados dos partidos cadastrados;
            TipoFederacao *federacoes: ponteiro para vetor que armazena os dados das federações cadastradas;
            int indiceCandidato: armazena o indice do candidato referente ao vetor 'candidatos';
            int indicePartido: armazena o indice do partido referente ao vetor 'partidos';
            int indiceFederacao: armazena o indice da federação referente ao vetor 'federacoes';
            int afiliado: define se o partido é afiliado a uma federação ou não;
            int eleito: define se o candidato atendeu aos critérios de eleição ou não.
        */ 

    if (eleito == 2) {
        //ARMAZENA ELEITOS
            if(afiliado){
                federacoes[indiceFederacao].indiceEleitos[federacoes[indiceFederacao].qtEleitoSuplente[0]] = indiceCandidato;
                federacoes[indiceFederacao].qtEleitoSuplente[0]++;
            }else{
                partidos[indicePartido].indiceEleitos[partidos[indicePartido].qtEleitoSuplente[0]] = indiceCandidato;
                partidos[indicePartido].qtEleitoSuplente[0]++;
            }
        //ARMAZENA SUPLENTES
        }else{
            if(afiliado){
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

void candidatosEleitos(TipoCandidato *candidatos, TipoPartido *partidos, TipoFederacao* federacoes, int QEleitoral, int nCandidatos, int nPartidos, int nFederacoes) {
    /* Função responsável por verificar se o candidato está eleito.
    Para ser eleito, precisa cumprir os criterios:
        1. Quantidade de votos maior ou igual a 10% do Quociente Eleitoral;
        2. O partido/federação deve possuir vagas disponíveis;
    Após essa verificação o candidato será armazenado como eleito ou como suplente.
    Por fim, a função verifica quais partidos possuem cadeiras sobrando e promove os candidatos suplentes desse partidos para
    ocuparem essas vagas como candidatos eleitos.
    
    Parâmetros:
        TipoCandidato *candidatos: ponteiro para o vetor que armazena as informaçoes dos candidatos;
        TipoPartido *partidos :  ponteiro para vetor que armazena os dados dos partidos cadastrados;
        TipoCandidato *federacoes; ponteiro para o vetor que armazena as informaçoes das federacoes cadastradas.
        int QEleitoral: variavel inteira que armazena o quociente eleitoral da eleiçao.
        int nCandidatos: inteiro que armazena a quantidade de cadidatos cadastrados;
        int nPartidos: inteiro que armazena a quantidade de partidos cadastrados;
        int nFederacoes: inteiro que armazena a quantidade de federacoes cadastradas;
    */
    int i, j, k, indiceCandidato = 0, indicePartido = 0, eleito = 0;
    char aux[5] = "";
    int afiliado=0, indiceFederacao=0;

    //verificaca eleição

    //verifica cada candidato
    for (i = 0; i < nCandidatos; i++){
        afiliado =0;
        eleito = 0;
        // Verifica se os votos do candidato estão acima de 10% do Quociente Eleitoral
        if(candidatos[i].votos >= (0.1 * QEleitoral)){
            eleito++;
            indiceCandidato = i;
            strcpy(aux, candidatos[i].siglaPartido);
        }if(eleito == 1){
            // verifica se o partido do candidato é afiliado a alguma federacao
            for(j=0; j< nFederacoes; j++){
                for(k=0; k<federacoes[j].nAfiliados; k++){
                    if(strcmp(aux, federacoes[j].siglaAfiliados[k]) == 0){
                        // verifica se ainda há cadeiras disponíveis e salva o indice da federacao
                        if(federacoes[j].qtEleitoSuplente[0] < federacoes[j].qPartidario){
                            eleito++;
                            afiliado = 1;
                            indiceFederacao = j;
                            break;
                        }
                    }
                }if(afiliado) break;
            }if(!afiliado){
                // verifica se ainda há cadeiras disponíveis e salva o indice do partido
                for(j=0; j<nPartidos; j++){
                    if(strcmp(aux, partidos[j].siglaPartido) == 0){
                        if(partidos[j].qtEleitoSuplente[0] < partidos[j].qPartidario){
                            indicePartido = j;
                            eleito++;
                            break;
                        }
                    }
                }
            }
        }
        armazenaEleitos(partidos,federacoes,indiceCandidato,indicePartido,indiceFederacao,afiliado,eleito);    
    }
    vagasRemanescentes(partidos,federacoes, nPartidos, nFederacoes);
}        

int main(){
    /* Função responsável por concatenar todas as outras funções do programa. */
    
    int opcao, flag=1, i, cadastroIncompleto=0;
    // int nPartidos=0, tamp=50, nFederacoes=0, tamf=50;
    int nPartidos=0, tamp=50, nFederacoes=0, tamf=50, nCandidatos=0, tamc=50;
    int vagasTotais=24, QEleitoral=0;
    int votosVal = 0, votosBra = 0, votosNul = 0;
    TipoPartido *partidos = NULL;
    TipoFederacao *federacoes = NULL;
    TipoCandidato *candidatos = NULL;
    candidatos = (TipoCandidato *) malloc(tamc*sizeof(TipoCandidato));
    partidos = (TipoPartido *) malloc(tamp*sizeof(TipoPartido));
    federacoes = (TipoFederacao *) malloc(tamf*sizeof(TipoFederacao));

    //CADASTROS

    while (flag){
        cadastroIncompleto = 0;
    //O WHILE DEVE ENCERRAR QUANDO O USUARIO ESCOLHER O OPÇÃO 4 'ENCERRAR ETAPA DE CADASTROS'
        imprimeMenuCadastro(); //FUNÇÃO QUE IMPRIME O MENU
        printf("\nSelecione uma opcao: ");
        if ((scanf("%d", &opcao)) > 0){
            switch (opcao){
                case 1:
                    getchar();
                    if((cadastraPartido(partidos, &nPartidos, &tamp)) == 0){
                        partidos[nPartidos-1].qtCandidatos =0;
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
                            // imprimeMenuCadastro();                                                                                                  
                        }
                    }else{
                        printf("\nCadastre, ao menos, 1 partido para registrar um Candidato.\n");
                    }                                                                                                                                                                                            
                    break;                                                                  
                case 3:
                    getchar();
                    if(nPartidos< 2){
                        printf("\nCadastre, ao menos, 2 partidos para registrar uma Federacao.\n");
                    }else{
                        printf("\nTodos os partidos que serao afiliados devem ja estar cadastrados.\nDeseja continuar?\nDigite 1 para SIM e 0 para NAO.\n");
                        if(scanf("%d", &opcao) == 1){
                            registraFederacao(federacoes, &nFederacoes, &tamf);
                            imprimeTituloAfiliados();
                            registraAfiliados(federacoes, partidos, nPartidos, nFederacoes,0);
                        }
                    }
                    break;
                case 4:
                // Verifica se há ao menos 1 candidato cadastrado
                    if(nCandidatos > 0){
                        //Verifica se há algum partido sem candidatos cadastrados
                        for(i=0; i<nPartidos; i++){
                            if(partidos[i].qtCandidatos == 0){
                                printf("\nO partido %s nao possui candidatos.", partidos[i].nomePartido);
                                cadastroIncompleto = 1;
                            }
                        }
                    }else{cadastroIncompleto = 1;}
                    if(cadastroIncompleto){
                        printf("\nImpossivel finalizar a etapa de cadastros no momento!\n");
                    }else{
                        flag = 0;
                    }break;
                    
                default:
                    printf("\nOpcao invalida. Tente novamente!\n");
                    break;
            }
        }else{
            printf("\nOpcao invalida. Tente novamente!\n");
            // getchar(); 
        }getchar();
    }

    //VOTAÇÃO
    flag = 1; 
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
    QEleitoral = quocienteEleitoral(votosVal , vagasTotais);
    // printf("\nqEleitoral: %d", QEleitoral);
    
    
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
    candidatosEleitos(candidatos, partidos, federacoes, QEleitoral, nCandidatos, nPartidos, nFederacoes);
    imprimirSecao5(candidatos, partidos, federacoes, nPartidos, nFederacoes);
    getchar();
    zeraImpresso(federacoes, partidos, nPartidos, nFederacoes);
    imprimirSecao6(candidatos, partidos, federacoes, nPartidos, nFederacoes);

    free(candidatos);
    free(partidos);
    free(federacoes);
    return 0;
}