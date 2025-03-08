#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h> // función sleep para Windows
#else
#include <unistd.h> // función sleep para Mac
#endif


void esperar(float segundos){
    #ifdef _WIN32
        Sleep((int)(segundos * 1000)); // sleep para Windows
    #else
        usleep((int)(segundos * 1000000)); // sleep para Mac
    #endif
}


void limpiarPantalla() {
    #ifdef _WIN32
        system("cls"); // comando para Windows
    #else
        system("clear"); // comando para Mac
    #endif
}


void inicializaMenosUno(int tabla[100]){
    for (int i = 0; i < 100; i++){
        tabla[i] = -1;
    }
}


void generaCarton(int tabla[100]){
    int asignacion;
    for(int i = 0; i < 20; i++){
        asignacion = rand() %5;
        tabla[(i * 5) + asignacion] = asignacion + (i * 5);
    }
}


void  imprimeCarton(int tabla[100]){
    for (int s = 0; s < 51; s++){ // imprime linea
        printf("_");
    }
    printf("\n");
    for (int i = 0; i < 10; i++) { // filas
        for (int x = 0; x < 10; x++) { // columnas
            if(tabla[i * 10 + x] == 219){
                printf("| %c  ", (char)219); // imprime caracter asci
            } 
            else if (tabla[i * 10 + x] == -1){
                printf("|    ");
            }
            else{
                printf("| %02d ", tabla[i * 10 + x]); // imprime dos digitos
            }      
        }
        printf("|\n"); // cierra la fila
        for (int s = 0; s < 51; s++){ // imprime linea
            printf("_");
        }
        printf("\n");
    }
    printf("\n");
}


void generaNumerosAleatorios(int tabla[100], int *aleatorio){
        do{
            *aleatorio = rand() %100;
        } while (tabla[*aleatorio] != -1);

        tabla[*aleatorio] = *aleatorio;
}


void marcaAciertos(int tabla[100],int numero, int *aciertoscarton){
    if (tabla[numero] == numero){
        tabla[numero] = 219; // si coincide cambia el numero
        (*aciertoscarton)++; // suma uno al contador
    }
}


int main() {
    int carton1[100];
    int carton2[100];
    int bingo[100];

    inicializaMenosUno(carton1);
    inicializaMenosUno(carton2);
    inicializaMenosUno(bingo);


    // imprime carton1, carton2 y bingo
    printf("Carton Jugador 1:\n");
    imprimeCarton(carton1);
    printf("Carton Jugador 2:\n");
    imprimeCarton(carton2);
    printf("Numeros Bingo:\n");
    imprimeCarton(bingo);
    esperar(3);
    limpiarPantalla(); 


    // Generar números
    srand(time(NULL));
    generaCarton(carton1);
    generaCarton(carton2);

    
    // imprime Carton1 y 2
    printf("Carton Jugador 1:\n");
    imprimeCarton(carton1);
    printf("Carton Jugador 2:\n");
    imprimeCarton(carton2);
    esperar(3);
    limpiarPantalla(); 


    // Numeros del bingo
    int numeroBingo, exit, contador1 = 0, contador2 = 0;
    for (int i = 0; i < 100; i++){
        generaNumerosAleatorios(bingo, &numeroBingo);

        printf("Ha salido el %d\n\n", numeroBingo);


        marcaAciertos(carton1,numeroBingo, &contador1);
        marcaAciertos(carton2,numeroBingo, &contador2);

        // imprime carton1 y 2
        printf("Carton Jugador 1:\n");
        imprimeCarton(carton1);
        printf("Carton Jugador 2:\n");
        imprimeCarton(carton2);

        esperar(1);
        if (contador1 == 20 || contador2 == 20){
            break; // finaliza el bucle for
        }
        limpiarPantalla(); 
    } 


    // imprime bingo
    printf("Numeros Bingo:\n");
    imprimeCarton(bingo);

    if (contador1 == 20 && contador2 == 20){
        printf("Ha habido un empate!\n");
    }
    else if (contador1 == 20){
        printf("Ha ganado el jugador 1!\n");
    } 
    else if (contador2 == 20){
        printf("Ha ganado el jugador 2!\n");
    }
}

