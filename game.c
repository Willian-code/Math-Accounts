#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

void jogar();
void mostrarInfo(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);

int pontos = 0;

int main()
{
    //Deve ser chamado apenas 1 vez.
    strnd(time(NULL));
    jogar();
    return(0);
}

void jogar()
{
    Calcular calc;
    int dificuldade;

    printf("Informe o nível de dificuldade desejado [1,2,3 ou 4]:\n");
    scanf("%d", &dificuldade);
    calc.dificuldade = dificuldade;

    //Gera um int randômico entre 0 e 2
    //0 = somar, 1 = diminuir, 2 = multiplicar
    calc.operacao = rand() % 3;

    if(calc.dificuldade == 1)
    {
        //fácil
        calc.valor1 = rand() % 11;//0 a 10
        calc.valor2 = rand() % 11;
    }
}

void mostrarInfo(Calcular calc)
{
    char op[25];

    if(calc.operacao == 0)//0 == Somar
        sprintf(op, "Somar");
    else if(calc.operacao == 1)//1 == Diminuir
        sprintf(op, "Diminuir");
    else if(calc.operacao == 2)//2 == Multiplicar
        sprintf(op, "Multiplicar");
    else
        sprintf(op, "Operção desconhecida");
    printf("Valor 1: %d\nValor 2: %d\nDificuldade: %d\nOperação: %s", calc.valor1, calc.valor2, calc.dificuldade, op);
}

int somar(int resposta, Calcular calc)
{
    int resultado = calc.valor1 + calc.valor2;
    int certo = 0;//0 == errou, 1 == acertou

    calc.resultado = resultado;

    if(resposta == calc.resultado)
    {
        printf("Resposta correta!\n");
        certo = 1;
    }
    else
        printf("Resposta errada!\n");
    printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);

    return(certo);
}

int diminuir(int resposta, Calcular calc)
{
    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    int certo = 0; //0 == errou, 1 == acertou

    if(resposta == calc.resultado)
    {
        printf("Resposta correta!\n");
        certo = 1;
    }
    else
        printf("Resposta errada!\n");
    
    printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);

    return(0);
}

int multiplicar(int resposta, Calcular calc)
{
    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resposta;
    int certo = 0;//0 == errou, 1 == acertou

    if(resposta == calc.resultado)
    {
        printf("Resposta correta!\n");
        certo = 1;
    }
    else
        printf("Resposta errada!\n");
    
    printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);

    return(certo);
}
