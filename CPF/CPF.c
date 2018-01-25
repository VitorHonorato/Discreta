/*  Murillo Henrique da Silva e Silva    Turma:CC
    Vitor Honorato da Silva              Turma:CC
*/

#include <stdio.h>

int main()
{
    int i, cpf[11], prim_dig = 0, seg_dig = 0, aux;
    char n[2];

    do
    {

        printf("Insira o numero do CPF sem tracos: \n\n");
        for (i = 0; i < 11; i++)
        {
            n[0] = getche();
            cpf[i] = atoi(n);
        }

        for(i = 0; i < 9; i++)
        {
            prim_dig += cpf[i] * (i+1);
        }

        prim_dig %= 11;

        if (prim_dig == 10) prim_dig = 0;

        for(i = 0; i < 10; i++)
        {
            seg_dig += cpf[i] * i;
        }

        seg_dig %= 11;

        if (seg_dig == 10) seg_dig = 0;

        if (prim_dig == cpf[9] && seg_dig == cpf[10])
        {
            printf("\n\nCPF valido\n\n");
        }
        else
        {
            printf("\n\nCPF invalido\n\n");
        }

        printf("Deseja continuar:\n\nDigite 1 caso sim\nDigite 0 caso nao\n\n");
        scanf("%d",&aux);

        prim_dig = 0;
        seg_dig = 0;

    }
    while(aux != 0);

    return 0;
}
