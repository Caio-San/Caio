#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct TipoFederacao{
    char nomeFederacao[50];
    char siglaFederacao[5];
    // char partidosFederados[?][5] SIGLA


} TipoFederacao;

// CRIA UM TIPO PARA ARMAZENAR AS INFORMAÇOES DAS FEDERAÇÕES

typedef struct TipoCandidato{
    char nomeCandidato[50];
    int idade;
    int digitos;
    //PEDIR PARTIDO?
    //char partido[]; //DECIDIR: NOME OU SIGLA

} TipoCandidato;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMÇOES DE CADA CANDIDATO
 
typedef struct TipoPartido{
    char nomePartido[50];
    char sigla[5];
    //PEDIR FEDERAÇÃO?
    TipoCandidato candidato;
    TipoFederacao federacao;
} TipoPartido;
// CRIA UM TIPO PARA ARMAZENAR AS INFORMAÇÕES DOS PARTIDOS
// OS OUTROS DOIS TIPOS A SEGUR SÃO SUB-TIPOS DESTE


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

// void CadastraPartidos(TipoPartido *ptr , int posicao){
//     // FUNÇÃO RESPONSÁVEL POR CADASTRAR PARTIDOS, VAI RECEBER O VETOR DO ´'TIPOPARTIDO' E UMA POSIÇÃO 
//     printf("Digite o nome do partido: \n");
//     scanf("%s", ptr[posicao].nomePartido);
//     printf("Digite a sigla do seu partido(máximo de 5 letras): \n");
//     scanf("%s", ptr[i].sigla);
    
// }





int main(){
    int opcao, flag =1;
    // int opcao,Npartidos,i=0, flag=1;
//     TipoPartido *partidos = NULL;
    
//     // DECLARA VARIAVEIS DE INTEIROS : opção(opção inserida pelo usuario), Npartidos(Quantidade total de partidos),i(variavel contadora)
//     // DECLARA UM PONTEIRO DO 'TIPOPARTIDOS'  PARA ARMAZENAR CADA PARTIDO BEM COMO SEUS RESPECTIVOS CANDIDATOS

//     printf("Digite a quantidade de partidos:");
//     scanf("%d", &Npartidos);
//     partidos = (TipoPartido *)malloc(Npartidos * sizeof(TipoPartido));
//     // ALOCA UM VETOR DO TIPOPARTIDO DE TAMANHO INSERIDO PELO USUARIO(ESSA ETAPA DO CODIGO É PROVISÓRIA)

//     if (partidos == NULL) {
//         printf("Erro ao alocar memória.\n");
//         return 1;
//     }

//     //CADASTROS

    while (flag){
//     //O WHILE DEVE ENCERRAR QUANDO O USUARIO ESCOLHER O OPÇÃO 4 'ENCERRAR ETAPA DE CADASTROS'
        imprimeMenuCadastro(); //FUNÇÃO QUE IMPRIME O MENU
        printf("\nSelecione uma opcao: \n");
        if ((scanf("%d", &opcao)) > 0){
            switch (opcao){
                case 1:
                    printf("1");
                    // cadastraPartido();
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

//     free(partidos);
    return 0;
}
