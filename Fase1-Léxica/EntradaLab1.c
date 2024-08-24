/* Função que realiza operações aritméticas */
int operacoes_aritmeticas(int a, int b, float c, float d) {
    int soma = a + b;
    int subtracao = a - b;
    int multiplicacao = a * b;
    int divisao = a / b;  /* Assumindo que b != 0 */
    int resto = a % b;    /* Assumindo que b != 0 */
    float expression = c + d * d / (c+d);
    printf("Soma: %d\n", soma);
    printf("Subtracao: %d\n", subtracao);
    printf("Multiplicacao: %d\n", multiplicacao);
    printf("Divisao: %d\n", divisao);
    printf("Resto da divisao: %d\n", resto);
    printf("Expressão: %f\n", expression);

    
    return soma;
}

/* Função que realiza operações de comparação */
void operacoes_comparacao(int x, int y) {
    if (x < y) {
        printf("%d é menor que %d\n", x, y);
    } else{
        printf("%d é maior ou igual a %d\n", x, y);
    }

    if (x != y) {
        printf("%d é diferente de %d\n", x, y);
    }
}

/* Função que realiza operações lógicas */
void operacoes_logicas(int x, int y) {
    if (x > 0 && y > 0) {
        printf("Ambos os números são positivos.\n");
    } else{
        printf("Nenhum ou pelo menos um dos números é positivo.\n");
    } 

    if (!(x > 0)) {
        printf("%d não é positivo.\n", x);
    }
}

/* Função principal */
int main() {
    
    int a = 10;
    int b = 5;
    
    int array[2];
    array[0] = 5;
    array[1] = 10;
    
    int c = operacoes_aritmeticas(a, b, array[0], array[1]);

    /* Exemplo de atribuição */
    int x = 20;
    int y = 15;

    /* Chamando funções
    operacoes_comparacao(x, y);
    operacoes_logicas(x, y);

    /* Controle de fluxo com while */
    int i = 0;
    while (i < 2) {
        printf("array[%d] = %d\n", i, array[i]);
        i+=1;
    }

    return 0;
}
