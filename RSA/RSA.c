#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void codificar(void);
int verifica_primo(int);
int coprimo(int, int, int);
int acha_d(int, int);
void decodificar(void);

int main()
{
    int op;
    do
    {
        printf("Informe a opcao desejada:\n");
        printf("(1) Codificar\n");
        printf("(2) Decodificar\n");
        printf("(0) Sair\n");
        printf("Opcao: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            system("cls");
            codificar();
            break;
        case 2:
            system("cls");
            decodificar();
            break;
        default:
            break;
        }
    }
    while(op != 0);

    return 0;
}

void codificar(void)
{
    int p, q, n, e, fin, i, d, len, j = 0, v[100] , c[100];
    double aux1, aux2;
    char s[100];

    do{
        printf("Informe os primos p e q: ");
        scanf("%d %d",&p,&q);
        if (verifica_primo(p) == 0 || verifica_primo(q) == 0){
            printf("Os valores nao sao validos\n");
        }
    }while(verifica_primo(p) == 0 || verifica_primo(q) == 0);

    n = p * q;
    fin = (p-1) * (q-1);
    e = coprimo(fin, p, q);
    d = acha_d(fin, e);

    printf("Informe a frase a ser criptografada: ");
    scanf(" %99[^\n]s", s);

    len = strlen(s);

    strupr(s);

    for(i = 0; i < len; i++){
        v[i] = s[i];
    }

    for(i = 0; i < len; i++){
        c[j]= v[i] / 10;
        j++;
        c[j] = v[i] % 10;
        j++;
    }

    for(i = 0; i < j; i++){
        c[i] = potencia(c[i], e, n);
    }

    printf("\nSuas chaves sao (%d,%d)\n",d,n);

    printf("\nA frase criptografada e: ");
    for (i = 0; i < j; i++){
        printf("%02d",c[i]);
    }
    printf("\n\n");
}

void decodificar(void)
{
    int d, n, i, c[100], j = 0, k = 0;
    char aux[2], m[100];

    printf("Informe as suas chaves: ");
    scanf("%d %d", &d, &n);

    printf("\nInforme o codigo a ser decodificado (espaco para finalizar):\n");
    for (i = 0; i < 100; i++){
        aux[0] = getche();
        c[i] = atoi(aux);
        j++;
        if (aux[0] == ' ') break;
    }

    for(i = 0; i < j; i += 2){
        c[i] = c[i] * 10 + c[i+1];
        c[k] = c[i];
        k++;
    }


    j = k - 1;

    for(i = 0; i < j; i++){
        c[i] = potencia(c[i], d, n);
    }

    k = 0;

    for(i = 0; i < j; i += 2){
        c[i] = c[i] * 10 + c[i+1];
        c[k] = c[i];
        m[k] = c[k];
        k++;
    }

    for (i = 0; i < k; i++){

    }

    printf("\nFrase descriptografada: ");
    for (i = 0; i < k; i++){
        printf("%c",m[i]);
    }
    printf("\n\n");
}

int verifica_primo(int i){

    int j;

    for(j = 2; j < i; j++){
		if(i % j == 0)
			return 0;
	}

	return 1;
}

int coprimo(int fin, int p, int q)
{
    int i;

    for (i = 2; i < fin; i++){
        if((fin % i != 0) && (verifica_primo(i) == 1) && (i != p) && (i != q)){
			return i;
		}
	}
}

int acha_d(int fin, int e)
{
    int aux = 1;

	while(1) {

		aux += fin;

		if(aux % e == 0 && (aux/e) != e){
		    return(aux / e);
		}
    }
}

int potencia (int a, int e, int n)
{
    long long A = a, P = 1, E = e;

	while(1){

		if(E == 0)
			return P;

		else if(E%2 != 0){
			P = (A * P)%n;
			E = (E-1)/2;
		}

		else{
			E = E/2;
		}
		A = (A*A)%n;
	}
}
