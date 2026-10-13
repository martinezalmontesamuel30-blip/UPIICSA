#include <stdio.h>
#include <math.h>

int main() {
    int opc;
    float num1, num2, resultado;

    do {
        printf("\nQue operacion deseas hacer?\n");
        printf("1 = Suma\n");
        printf("2 = Resta\n");
        printf("3 = Multiplicacion\n");
        printf("4 = Division\n");
        printf("5 = Salir\n");
        printf("Opcion: ");
        scanf("%d", &opc);

        if (opc >= 1 && opc <= 4) {
            printf("Ingresa el primer numero: ");
            scanf("%f", &num1);
            printf("Ingresa el segundo numero: ");
            scanf("%f", &num2);
        }

        switch(opc) {
            case 1:
                resultado = num1 + num2;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 2:
                resultado = num1 - num2;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 3:
                resultado = num1 * num2;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %.2f\n", resultado);
                } else {
                    printf("Error: No se puede dividir entre cero.\n");
                }
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intenta de nuevo.\n");
        }

    } while(opc != 5);

    return 0;
}
