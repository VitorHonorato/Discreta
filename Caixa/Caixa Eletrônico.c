#include <stdio.h>

void uma_cedula(int);
void duas_cedulas(int);
int Switch(int);
int mdc(int, int);

int main()
{
    int valor, qnt_cedulas;
    char x;
    do {
    puts("Qual o valor que deseja sacar?");
    scanf("%d", &valor);
    do {
    puts("Quantas cedulas diferentes deseja usar? 1 ou 2?");
    scanf("%d", &qnt_cedulas);
    } while (qnt_cedulas != 1 && qnt_cedulas != 2);
    if (qnt_cedulas == 1) {
        uma_cedula(valor);
    }
    else {
        duas_cedulas(valor);
    }
    puts("Deseja continuar? s/n");
    scanf(" %c", &x);
    } while (x != 'n');
    return 0;
}

void uma_cedula(int valor)
{
    int cedula, quantd, x;
    puts("Qual cedula deseja usar?");
    printf("1-R$2,00\t3-R$10,00\t5-R$50,00\n2-R$5,00\t4-R$20,00\t6-R$100,00\n");
    scanf("%d", &cedula);
    if ((x = Switch(cedula)) == 1) {
        printf("Opçao de cedula invalida");
    }
    else {
        if (valor % x != 0) {
            puts("Valor impossivel de retirar com nota desejada");
            puts("Tente novamente");
        }
        else {
           quantd = valor / x;
           printf("Para retirar R$%d,00 sao necessarias %d de R$%d,00\n", valor, quantd, x);
        }
    }
}

void duas_cedulas(int valor)
{
    int cedula1, cedula2, x, y, mdc;
    puts("Quais cedulas deseja usar?");
    printf("1-R$2,00\t3-R$10,00\t5-R$50,00\n2-R$5,00\t4-R$20,00\t6-R$100,00\n");
    scanf("%d %d", &cedula1, &cedula2);
    if ((x = Switch(cedula1)) == 1 && (y = Switch(cedula2)) == 1) {
        puts("Opçao invalida");
        puts("Tente novamente");
    }
    else {
        mdc = mdc(x,y);
        if (valor % mdc != 0) {
            puts("Valor impossivel de retirar com as notas desejadas");
            puts("Tente novamente");
        }

    }
}

int Switch(int op)
{
    switch (op) {
    case 1:
            return 2;
    case 2:
            return 5;
    case 3:
            return 10;
    case 4:
            return 20;
    case 5:
            return 50;
    case 6:
            return 100;
    default:
            return 1;
    }
}

int mdc(int x, int y)
{
    int resto, aux;
    if (y > x) {
        aux = x;
        x = y;
        y = aux;
    }
    do {
        resto = x % y;
        x = y;
        y = resto;
    } while (y != 0);
    return x;
}
