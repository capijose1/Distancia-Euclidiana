// Distancia Euclidiana.cpp: define el punto de entrada de la aplicación.
//

#include "Distancia Euclidiana.h"

using namespace std;

int main()
{
    int** contadores = new int* [6];
    float*** objetos = new float** [6];
    float** guardar_distancia = new float* [6];
    float* distanciamax = new float[6];
    
    for (int i = 0; i < 6; i++) {
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();
        contadores[i] = new int[10];
        objetos[i] = crear_n_puntos(puntos, dimensiones[i]);
        guardar_distancia[i] = new float[puntos];
        distanciamax[i] = distancia_max(objetos[i], dimensiones[i], puntos, guardar_distancia[i]);
        sort(guardar_distancia[i], guardar_distancia[i] + 20000);
        contando(guardar_distancia[i], contadores[i], distanciamax[i], dimensiones[i]);
        end = std::chrono::high_resolution_clock::now();
        int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); // duration is holding the elapsed time
        cout << "En la dimension "<<dimensiones[i]<<" duro :" << duration << endl;
    }
}
