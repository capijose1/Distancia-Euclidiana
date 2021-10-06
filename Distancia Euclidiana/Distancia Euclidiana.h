// Distancia Euclidiana.h: archivo de inclusión para archivos de inclusión estándar del sistema,
// o archivos de inclusión específicos de un proyecto.

#pragma once

#include <iostream>
#include <random>
#include <math.h>
using namespace std;

int dimensiones[6] = { 2,5,10,15,20,25 };
int puntos = 20000;
float suma(float*& arreglo_1, float*& arreglo_2, int n_dimensiones) {
    float suma = 0;
    for (int i = 0; i < n_dimensiones; i += 1) {
        suma = suma + (pow((arreglo_1[i] - arreglo_2[i]), 2));
    }
    return sqrt(suma);
}
float** crear_n_puntos(int n_puntos, int n_dimensiones) {
    srand(time(NULL));
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 1000);
    float** a = new float* [n_puntos];
    for (int i = 0; i < n_puntos; i++) {
        *(a + i) = new float[n_dimensiones];
        float* temp = *(a + i);
        for (int j = 0; j < n_dimensiones; j++) {
            temp[j] = distrib(gen);
        }
    }
    return a;
}
void contando(float* distancia, int* contadores, float maximo, int dimension) {
    float topes[10];
    float incremento = 0.1;
    for (int i = 0; i < 10; i++) {
        contadores[i] = 0;
        topes[i] = incremento;
        incremento += 0.1;
    }
    int cont = 0;

    for (int i = 0; i < puntos; i++) {
        if (topes[cont] * maximo > distancia[i]) {
            contadores[cont] += 1;
        }
        else
        {
            cont += 1;
        }

    }
    cout << endl << "/////////////////////////" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Porcentaje " << topes[i] << ": ->" << contadores[i] << " en la dimension " << dimension << endl;
    }
    cout << endl << "/////////////////////////" << endl;
}
float distancia_max(float** arreglo, int n_dimensiones, int n_puntos, float* guardar_distancia) {
    float max = 0;
    for (int i = 0; i < n_puntos; i++) {
        guardar_distancia[i] = suma(arreglo[0], arreglo[i], n_dimensiones);
        if (guardar_distancia[i] > max) {
            max = guardar_distancia[i];
        }
    }
    return max;
}

// TODO: Haga referencia aquí a los encabezados adicionales que el programa requiere.
