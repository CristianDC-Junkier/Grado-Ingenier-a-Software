#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <chrono> // Necesaria para utilizar std::chrono

// Función para generar un vector de n elementos aleatorios sin números repetidos
std::vector<int> generarVectorAleatorio(int n) {
    std::vector<int> vec;
    for (int i = 0; i < n; ++i) {
        vec.push_back(i + 1); // Llena el vector con números del 1 al n
    }
    std::random_shuffle(vec.begin(), vec.end()); // Mezcla los números aleatoriamente
    return vec;
}

// Función para realizar una búsqueda secuencial en un vector
bool busquedaSecuencial(const std::vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return true; // Si se encuentra el elemento, devuelve true
        }
    }
    return false; // Si no se encuentra el elemento, devuelve false
}

int main() {
    srand(time(0)); // Inicializa la semilla para generar números aleatorios

    std::ofstream archivo("resultados.csv");
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    archivo << std::fixed << std::setprecision(0); // Fijar precisión decimal a 0

    archivo << "Tamano del Vector;Mejor Tiempo (us);Peor Tiempo (us);Tiempo Medio (us)" << std::endl;

    for (int n = 1000; n <= 10000; n += 1000) {
        std::vector<int> vectorAleatorio = generarVectorAleatorio(n);

        double tiempo_total = 0.0;
        double mejor_tiempo = DBL_MAX;
        double peor_tiempo = 0.0;

        // Realiza 100 búsquedas aleatorias y mide el tiempo
        for (int i = 0; i < 100; ++i) {
            int valorAleatorio = rand() % n + 1; // Genera un número aleatorio entre 1 y n

            auto inicio = std::chrono::high_resolution_clock::now();
            bool encontrado = busquedaSecuencial(vectorAleatorio, valorAleatorio);
            auto fin = std::chrono::high_resolution_clock::now();

            double tiempo_busqueda = std::chrono::duration<double, std::micro>(fin - inicio).count();
            tiempo_total += tiempo_busqueda;

            mejor_tiempo = std::min(mejor_tiempo, tiempo_busqueda);
            peor_tiempo = std::max(peor_tiempo, tiempo_busqueda);
        }

        // Calcula y guarda el tiempo medio, mejor y peor tiempo de búsqueda en el archivo
        double tiempo_medio = tiempo_total / 100;
        archivo << n << ";" << mejor_tiempo << ";" << peor_tiempo << ";" << tiempo_medio << std::endl;
    }

    archivo.close();
    std::cout << "Los resultados se han guardado en el archivo 'resultados.csv'." << std::endl;

    return 0;
}
