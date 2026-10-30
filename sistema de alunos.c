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
    int vCod_mat[tfa];
    int op, tla = 0, pos, tld = 0, cod_teste, i;
    int tlm = 0;

    float vNota1[tfa], vNota2[tfa], vMedia[tfa];
    float media;

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
                if(tla < tfa)
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
                            if(tlm == 0)
                            {
                                strcpy(vRa_mat[tlm],ra_teste);
                                vCod_mat[tlm] = cod_teste;
                                
                                printf("Digite a 1° nota:\n");
                                scanf("%f", &vNota1[tlm]);
                                printf("Digite a 2° nota:\n");
                                scanf("%f", &vNota2[tlm]);
                                vMedia[tlm] = (vNota1[tlm] + vNota2[tlm]) / 2;
                                tlm++;

                                printf("Notas adicionadas!\n");
                            }
                            else
                            {
                                int posNota = 0;

                                while (posNota < tlm &&
                                    (strcmp(vRa_mat[posNota], ra_teste) != 0 ||
                                        vCod_mat[posNota] != cod_teste)) {
                                    posNota++;
                                }

                                if (posNota < tlm) 
                                    printf("Já existem notas para esse aluno nessa disciplina.\n");
                                else 
                                {
                                    strcpy(vRa_mat[tlm],ra_teste);
                                    vCod_mat[tlm] = cod_teste;
                                
                                    printf("Digite a 1° nota:\n");
                                    scanf("%f", &vNota1[tlm]);
                                    printf("Digite a 2° nota:\n");
                                    scanf("%f", &vNota2[tlm]);
                                    vMedia[tlm] = (vNota1[tlm] + vNota2[tlm]) / 2;
                                    tlm++;

                                    printf("Notas adicionadas!\n");
                                }
                            }
                        }
                        printf("Diciplina não cadastrada!\n");
                    }
                    else
                        printf("Aluno não encontrado!\n");
                }
                break;
            }
            case 4:
            {
                printf("Digite o RA:\n");
                fflush(stdin);
                gets(ra_teste);

                pos = 0;
                while(pos < tla && strcmp(vRa[pos],ra_teste) != 0)
                    pos++;

                if(pos < tla)
                {
                    for(int j = pos; j < tla - 1; j++){
                        strcpy(vAluno[j], vAluno[j + 1]);
                        strcpy(vRa[j], vRa[j + 1]);
                    }
                    tla--;

                    int j = 0;

                    while (j < tlm) 
                    {
                        if (strcmp(vRa_mat[j], ra_teste) == 0) 
                        {
                            for (int k = j; k < tlm - 1; k++) {
                                strcpy(vRa_mat[k], vRa_mat[k + 1]);
                                vCod_mat[k] = vCod_mat[k + 1];
                                vNota1[k] = vNota1[k + 1];
                                vNota2[k] = vNota2[k + 1];
                                vMedia[k] = vMedia[k + 1];
                            }

                            tlm--;
                        } 
                        else
                            j++;
                    }
                    printf("Aluno e seus lançamentos foram excluídos.\n");
                }
                else
                    printf("Aluno não encontrado!\n");

                break;
            }
            case 5:
            {
                if(tlm == 0)
                    printf("Ainda não há lançamentos!\n");
                else
                {
                    printf("Listagem de notas:\n");
                    for(i = 0; i < tlm; i++){
                        printf("Aluno: %s | Diciplina: %d | Nota1: %.2f Nota2: %.2f | Média: %.2f\n", vRa_mat[i], vCod_mat[i], 
                        vNota1[i], vNota2[i], vMedia[i]);
                    }
                }
                break;
            }
            case 6:
            {
                for (i = 0; i < tlm; i++) 
                {
                    if (vCod_mat[i] == cod_teste && vMedia[i] >= 6.0) 
                    {
                        printf("RA: %s | Média: %.2f\n",
                        vRa_mat[i], vMedia[i]);
                    }
                }
                break;
            }
            case 7:
            {
                for (i = 0; i < tlm; i++) 
                {
                    if (vMedia[i] < 6.0) 
                    {
                        printf("RA: %s | Código da disciplina: %d | Média: %.2f\n",
                        vRa_mat[i], vCod_mat[i], vMedia[i]);
                    }
                }
                break;
            }
        }
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
    }
    return 0;
}