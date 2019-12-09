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

    //Lerá o arquivo para verificar se ele existe
    arquivo_read(lista);

    do{
        opcao = menu(lista);
        if(opcao == 1){
                //opcao que ao ser chamada rodará todo o esquema de adição de funcionario
                system("cls");
                printf("**************************************");
                printf("\n      INSERÇÃO DE FUNCIONÁRIO   ");
                printf("\n**************************************\n\n");
                contato_dados = preenchimento();
                if(insercao(lista, contato_dados)){
                    printf("\nFuncionário inserido com sucesso!\n");
                }else{
                    printf("\nErro ao inserir funcionário!\n");
                }
                printf("\n\n");
                system("pause");
         }
            if(opcao == 2){
                //Chamará a função de relatorio e gerará o relatório
                system("cls");
                search_tool = relatorio(lista);
                printf("**************************************");
                printf("\n           RELATÓRIO GERAL          ");
                printf("\n**************************************\n\n");
                for(i=0; i<tamanho_lista(lista); i++){
                    printf("\n\nNome: %s", search_tool[i].nome);
                    printf("\nCódigo: %d", search_tool[i].codigo);
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
                //Chamará a função que tem como finalidade buscar o funcionario por codigo
                system("cls");
                printf("**************************************");
                printf("\n            BUSCA POR CÓDIGO         ");
                printf("\n**************************************\n\n");
                printf("Insira o código do funcionário: ");
                scanf("%d",&cod);
                if(buscar_codigo(lista, cod, &aux)){
                    printf("\n**************************************");
                    printf("\n\nRelatório do funcionário:\n");
                    printf("Nome: %s", aux.nome);
                    printf("\nEmpresa: %s", aux.empresa);
                    printf("\nDepartamento: %s", aux.departamento);
                    printf("\nTelefone: %s", aux.telefone);
                    printf("\nCelular: %s", aux.celular);
                    printf("\nEmail: %s\n", aux.email);
                }
                else{
                    printf("\nErro ao localizar funcionário!\n");
                }
                printf("\n\n");
                system("pause");
            }
            if(opcao == 4){
                //Chamará a função que tem como finalidade buscar o funcionario por nome
                system("cls");
                printf("**************************************");
                printf("\n            BUSCA POR NOME           ");
                printf("\n**************************************\n\n");
                printf("Insira o nome do funcionário: ");
                getchar();
                fgets(busca_nome, 49, stdin);
                busca_nome[strlen(busca_nome)-1] = '\0';
                aux_busca=0;
                search_tool = buscar_nome(lista, busca_nome, &aux_busca);

                system("cls");
                printf("**************************************");
                printf("\n            BUSCA POR NOME           ");
                printf("\n**************************************\n\n");

                printf("Funcionário encontrados: ");
                for(i=0; i<aux_busca; i++){
                    printf("\n\nNome: %s", search_tool[i].nome);
                    printf("\nCódigo: %d", search_tool[i].codigo);
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
                //Ao pegar o código do funcionário chama a função para alterar o mesmo
                system("cls");
                printf("**************************************");
                printf("\n         ALTERAÇÃO DE DADOS      ");
                printf("\n**************************************\n\n");

                printf("Insira o código do funcionário que será modificado: ");
                scanf("%d",&cod);
                int confirmacao;
                if(buscar_codigo(lista, cod, &aux)){
                    printf("\n**************************************");
                    printf("\n\nRelatório do funcionário:\n");
                    printf("Nome: %s", aux.nome);
                    printf("\nEmpresa: %s", aux.empresa);
                    printf("\nDepartamento: %s", aux.departamento);
                    printf("\nTelefone: %s", aux.telefone);
                    printf("\nCelular: %s", aux.celular);
                    printf("\nEmail: %s\n", aux.email);
                    printf("\nDeseja alterar os dados deste funcionário:");
                    printf("\n\n1 - Sim\n2 - Não\n");
                    printf("Opção: ");
                    scanf("%d",&confirmacao);
                    if(confirmacao == 1){
                        //A alteração só acontecerá caso o usuário confirme a escolha
                        system("cls");
                        printf("**************************************");
                        printf("\n         ALTERAÇÃO DE DADOS      ");
                        printf("\n**************************************\n\n");
                        printf("Insira os novos dados do funcionário:\n");
                        contato_dados = preenchimento_alteracao(aux.codigo);
                        if(alterar_dados(lista, cod, contato_dados)){
                            printf("\nDados do funcionário atualizados com sucesso!\n\n");
                        }
                        else{
                            printf("\nErro ao alterar dados!\n");
                        }
                    }
                    else{
                        printf("Não houve modificação.\n");
                    }
                }
                else{
                    printf("\nErro! Funcionário não encontrado.\n");
                }
                printf("\n");
                system("pause");
            }
            if(opcao == 6){
                //Chamará a função para remover contato, após uma confirmação
                system("cls");
                printf("**************************************");
                printf("\n          REMOÇÃO DE CONTATO      ");
                printf("\n**************************************");

                printf("\n\nDigite o código do contato que será removido:\nCódigo: ");
                scanf("%d",&cod);
                if(buscar_codigo(lista, cod, &aux)){
                    printf("\n**************************************");
                    printf("\n\nRelatório do funcionário:\n");
                    printf("Nome: %s", aux.nome);
                    printf("\nEmpresa: %s", aux.empresa);
                    printf("\nDepartamento: %s", aux.departamento);
                    printf("\nTelefone: %s", aux.telefone);
                    printf("\nCelular: %s", aux.celular);
                    printf("\nEmail: %s\n", aux.email);
                    printf("\nDeseja remover este funcionário:");
                    printf("\n\n1 - Sim\n2 - Não\n");
                    printf("Opção: ");
                    scanf("%d",&confirmacao);
                    if(confirmacao == 1){
                        if(remover_funcionario(lista, cod)){
                            printf("\nFuncionário removido com sucesso!\n");
                        }
                        else{
                            printf("\nErro ao remover funcionário!\n");
                        }
                    }
                    else{
                        printf("Não houve remoção!\n");
                    }
                }
                else{
                    printf("\nErro ao localizar funcionário!\n");
                }
                printf("\n\n");
                system("pause");
            }
    }
    while(opcao != 7);
    //Fecha o arquivo e libera memória
    finalizacao();
    arquivo_save(lista);
    destroi_lista(lista);

    return (0);
}
