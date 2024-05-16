#include <stdio.h>
#include <conio.h>

#define TAM_CUADRADO 5

void dibujarCuadrado(int, int);
void limpiarPantalla();


int main() {
    int x = 5;
    int y = 5;
    char input;

    do {
        limpiarPantalla();
        dibujarCuadrado(x, y);
        printf("\nUtiliza las teclas 'w', 'a', 's', 'd' para mover el cuadrado. Presiona 'q' para salir.\n");
        input = getch();

        switch(input) {
            case 'w':
                y--;
                break;
            case 'a':
                x -= 2;// Restamos 2 para tener en cuenta el tamaño del cuadrado
                break;
            case 's':
                y++;
                break;
            case 'd':
                x += 2; // Sumamos 2 para tener en cuenta el tamaño del cuadrado
                break;
        }

    } while(input != 'q');

    return 0;
}

void dibujarCuadrado(int x, int y) {
    for (int i = 0; i < TAM_CUADRADO; i++) {
        printf("\033[%d;%dH", y + i, x); // \033[%d;%dH asegura que el cuadrado se dibuje en la posicion correcta 
        for (int j = 0; j < TAM_CUADRADO; j++) {
            printf("* ");
        }
    }
    printf("\n");
}

void limpiarPantalla() {
    printf("\033[2J"); // Código ANSI para limpiar la pantalla
    printf("\033[1;1H"); // Mover el cursor al inicio de la pantalla
}

