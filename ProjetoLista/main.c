#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listaContatos.h"

int main(void){
    setlocale(LC_ALL,"Portuguese");
    Lista *lista = cria_lista();
    informacoes aux, contato_dados, *search_tool;
    char busca_nome[30];
    int opcao, cod, confirmacao, i, aux_busca;

    //Ler� o arquivo para verificar se ele existe
    arquivo_read(lista);

    do{
        opcao = menu(lista);
        if(opcao == 1){
                //opcao que ao ser chamada rodar� todo o esquema de adi��o de funcionario
                system("cls");
                printf("**************************************");
                printf("\n      INSER��O DE FUNCION�RIO   ");
                printf("\n**************************************\n\n");
                contato_dados = preenchimento();
                if(insercao(lista, contato_dados)){
                    printf("\nFuncion�rio inserido com sucesso!\n");
                }else{
                    printf("\nErro ao inserir funcion�rio!\n");
                }
                printf("\n\n");
                system("pause");
         }
            if(opcao == 2){
                //Chamar� a fun��o de relatorio e gerar� o relat�rio
                system("cls");
                search_tool = relatorio(lista);
                printf("**************************************");
                printf("\n           RELAT�RIO GERAL          ");
                printf("\n**************************************\n\n");
                for(i=0; i<tamanho_lista(lista); i++){
                    printf("\n\nNome: %s", search_tool[i].nome);
                    printf("\nC�digo: %d", search_tool[i].codigo);
                    printf("\nEmpresa: %s", search_tool[i].empresa);
                    printf("\nDepartamento: %s", search_tool[i].departamento);
                    printf("\nTelefone: %s", search_tool[i].telefone);
                    printf("\nCelular: %s", search_tool[i].celular);
                    printf("\nEmail: %s\n", search_tool[i].email);
                    printf("\n**************************************");
                }
                free(search_tool);
                printf("\n");
                system("pause");
            }
            if(opcao == 3){
                //Chamar� a fun��o que tem como finalidade buscar o funcionario por codigo
                system("cls");
                printf("**************************************");
                printf("\n            BUSCA POR C�DIGO         ");
                printf("\n**************************************\n\n");
                printf("Insira o c�digo do funcion�rio: ");
                scanf("%d",&cod);
                if(buscar_codigo(lista, cod, &aux)){
                    printf("\n**************************************");
                    printf("\n\nRelat�rio do funcion�rio:\n");
                    printf("Nome: %s", aux.nome);
                    printf("\nEmpresa: %s", aux.empresa);
                    printf("\nDepartamento: %s", aux.departamento);
                    printf("\nTelefone: %s", aux.telefone);
                    printf("\nCelular: %s", aux.celular);
                    printf("\nEmail: %s\n", aux.email);
                }
                else{
                    printf("\nErro ao localizar funcion�rio!\n");
                }
                printf("\n\n");
                system("pause");
            }
            if(opcao == 4){
                //Chamar� a fun��o que tem como finalidade buscar o funcionario por nome
                system("cls");
                printf("**************************************");
                printf("\n            BUSCA POR NOME           ");
                printf("\n**************************************\n\n");
                printf("Insira o nome do funcion�rio: ");
                getchar();
                fgets(busca_nome, 49, stdin);
                busca_nome[strlen(busca_nome)-1] = '\0';
                aux_busca=0;
                search_tool = buscar_nome(lista, busca_nome, &aux_busca);

                system("cls");
                printf("**************************************");
                printf("\n            BUSCA POR NOME           ");
                printf("\n**************************************\n\n");

                printf("Funcion�rio encontrados: ");
                for(i=0; i<aux_busca; i++){
                    printf("\n\nNome: %s", search_tool[i].nome);
                    printf("\nC�digo: %d", search_tool[i].codigo);
                    printf("\nEmpresa: %s", search_tool[i].empresa);
                    printf("\nDepartamento: %s", search_tool[i].departamento);
                    printf("\nTelefone: %s", search_tool[i].telefone);
                    printf("\nCelular: %s", search_tool[i].celular);
                    printf("\nEmail: %s\n", search_tool[i].email);
                    printf("\n**************************************");
                }

                free(search_tool);
                printf("\n\n");
                system("pause");
            }
            if(opcao == 5){
                //Ao pegar o c�digo do funcion�rio chama a fun��o para alterar o mesmo
                system("cls");
                printf("**************************************");
                printf("\n         ALTERA��O DE DADOS      ");
                printf("\n**************************************\n\n");

                printf("Insira o c�digo do funcion�rio que ser� modificado: ");
                scanf("%d",&cod);
                int confirmacao;
                if(buscar_codigo(lista, cod, &aux)){
                    printf("\n**************************************");
                    printf("\n\nRelat�rio do funcion�rio:\n");
                    printf("Nome: %s", aux.nome);
                    printf("\nEmpresa: %s", aux.empresa);
                    printf("\nDepartamento: %s", aux.departamento);
                    printf("\nTelefone: %s", aux.telefone);
                    printf("\nCelular: %s", aux.celular);
                    printf("\nEmail: %s\n", aux.email);
                    printf("\nDeseja alterar os dados deste funcion�rio:");
                    printf("\n\n1 - Sim\n2 - N�o\n");
                    printf("Op��o: ");
                    scanf("%d",&confirmacao);
                    if(confirmacao == 1){
                        //A altera��o s� acontecer� caso o usu�rio confirme a escolha
                        system("cls");
                        printf("**************************************");
                        printf("\n         ALTERA��O DE DADOS      ");
                        printf("\n**************************************\n\n");
                        printf("Insira os novos dados do funcion�rio:\n");
                        contato_dados = preenchimento_alteracao(aux.codigo);
                        if(alterar_dados(lista, cod, contato_dados)){
                            printf("\nDados do funcion�rio atualizados com sucesso!\n\n");
                        }
                        else{
                            printf("\nErro ao alterar dados!\n");
                        }
                    }
                    else{
                        printf("N�o houve modifica��o.\n");
                    }
                }
                else{
                    printf("\nErro! Funcion�rio n�o encontrado.\n");
                }
                printf("\n");
                system("pause");
            }
            if(opcao == 6){
                //Chamar� a fun��o para remover contato, ap�s uma confirma��o
                system("cls");
                printf("**************************************");
                printf("\n          REMO��O DE CONTATO      ");
                printf("\n**************************************");

                printf("\n\nDigite o c�digo do contato que ser� removido:\nC�digo: ");
                scanf("%d",&cod);
                if(buscar_codigo(lista, cod, &aux)){
                    printf("\n**************************************");
                    printf("\n\nRelat�rio do funcion�rio:\n");
                    printf("Nome: %s", aux.nome);
                    printf("\nEmpresa: %s", aux.empresa);
                    printf("\nDepartamento: %s", aux.departamento);
                    printf("\nTelefone: %s", aux.telefone);
                    printf("\nCelular: %s", aux.celular);
                    printf("\nEmail: %s\n", aux.email);
                    printf("\nDeseja remover este funcion�rio:");
                    printf("\n\n1 - Sim\n2 - N�o\n");
                    printf("Op��o: ");
                    scanf("%d",&confirmacao);
                    if(confirmacao == 1){
                        if(remover_funcionario(lista, cod)){
                            printf("\nFuncion�rio removido com sucesso!\n");
                        }
                        else{
                            printf("\nErro ao remover funcion�rio!\n");
                        }
                    }
                    else{
                        printf("N�o houve remo��o!\n");
                    }
                }
                else{
                    printf("\nErro ao localizar funcion�rio!\n");
                }
                printf("\n\n");
                system("pause");
            }
    }
    while(opcao != 7);
    //Fecha o arquivo e libera mem�ria
    finalizacao();
    arquivo_save(lista);
    destroi_lista(lista);

    return (0);
}
