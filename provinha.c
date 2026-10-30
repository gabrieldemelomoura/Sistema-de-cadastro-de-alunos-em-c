#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define tfa 100
#define tfn 30
#define tfd 8

int main()
{
    char vRa[tfa][tfn];
    char ra_teste[tfn];
    char vAluno[tfa][tfn];
    char vDiciplina[tfd][tfn];
    char vRa_mat[tfa][tfn];

    int cod_diciplina[tfd];
    int vCod_mat[tfd];
    int op, tla = 0, pos, tld = 0, cod_teste, i;
    int tlvRa = 0, tlvCod = 0, tlNota = 0;

    float vNota1[tfa], vNota2[tfa];
    float media,

    printf("=========================\n");
    printf("Escolha uma das opções:\n");
    printf("=========================\n");
    printf("1 - Cadastro de alunos\n");
    printf("2 - Cadastro de diciplinas\n");
    printf("3 - Lançar notas\n");
    printf("4 - Excluir aluno\n");
    printf("5 - Mostrar relatório geral\n");
    printf("6 - Mostrar relatório Aprovados\n");
    printf("7 - Mostrar relatório Reprodos\n");
    printf("0 - sair");
    scanf("%d", &op);

    while(op > 0 && op <= 7)
    {
        switch (op)
        {
            case 1:
            {
                if(tla < tf)
                {
                    if(tla == 0)
                    {
                        printf("Digite o RA:\n");
                        fflush(stdin);
                        gets(vRa[tla]);

                        printf("Digite o nome do aluno:\n");
                        fflush(stdin);
                        gets(vAluno[tla]);

                        tla++;
                    }
                    else
                    {
                        printf("Digite o RA:\n");
                        fflush(stdin);
                        gets(ra_teste);

                        pos = 0;
                        while(pos < tla && strcmp(vRa[pos],ra_teste) != 0)
                            pos++;

                        if(pos < tla)
                            printf("Alunos já cadastrado!\n");
                        else
                        {
                            strcpy(vRa[tla],ra_teste);
                            printf("Digite o nome do aluno:\n");
                            fflush(stdin);
                            gets(vAluno[tla]);
                            tla++;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                if(tld < tfd)
                {
                    if(tld == 0)
                    {
                        printf("Digite o código da matéria:\n");
                        scanf("%d", &cod_diciplina[tld]);

                        printf("Digite o nome da diciplina:\n");
                        fflush(stdin);
                        gets(vDiciplina[tld]);

                        tld++;
                    }
                    else
                    {
                        printf("Digite o código da diciplina:\n");
                        scanf("%d", &cod_teste);

                        pos = 0;
                        while(pos < tld && cod_diciplina[pos] != cod_teste)
                            pos++;

                        if(pos < tld)
                            printf("Diciplina já cadastrada!");
                        else
                        {
                            cod_diciplina[tld] = cod_teste;

                            printf("Digite o nome da diciplina:\n");
                            fflush(stdin);
                            gets(vDiciplina[tld]);

                            tld++;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                if(tla == 0 && tld == 0)
                {
                    printf("Ainda não à alunos e nem diciplinas cadastradas!\n");
                }
                else
                {
                    printf("Digite o RA:\n");
                    fflush(stdin);
                    gets(ra_teste);

                    pos = 0;
                    while(pos < tla && strcmp(vRa[pos],ra_teste) != 0)
                        pos++;
                    
                    if(pos < tla)
                    {
                        printf("Digite o código da diciplina:\n");
                        scanf("%d", &cod_teste);

                        pos = 0;
                        while(pos < tld && cod_diciplina[pos] != cod_teste)
                            pos++;

                        if(pos < tld)
                        {
                            if(tlvCod == 0 && tlvRa == 0)
                            {
                                strcpy(vRa_mat[tlvRa],ra_teste);
                                vCod_mat[tlvCod] = cod_teste;
                                tlvCod++;
                                tlvRa++;
                                
                                printf("Digite a 1° nota:\n");
                                scanf("%f", &vNota1[tlNota]);
                                printf("Digite a 2° nota:\n");
                                scanf("%f", &vNota2[tlNota]);
                                tlNota++;

                                printf("Notas adicionadas!\n");

                                media = (vNota1[tlNota] + vNota2[tlNota]) / 2;
                            }
                            else
                            {
                                
                            }

                        }
                        printf("Diciplina não cadastrada!\n");
                    }
                    else
                        printf("Aluno não encontrado!\n");
                }
            }
        }
    }
}