//Delgado Cruz Cristian 
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>




void insercion(std::vector<int>& vec)
{
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
        int clave = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > clave) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = clave;
    }
}

void burbuja(std::vector<int>& vec)
{
    int tam = vec.size();
    for (int i = 0; i < tam - 1; i++)
        for (int j = i + 1; j < tam; j++)
            if (vec[j] < vec[i]) {
                int tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
            }
}



// Función para generar vectores con la distribución uniforme
void generarVector(std::vector<int>& v, int tam, unsigned int semilla) {
    std::mt19937 gen(semilla); 

    std::uniform_int_distribution<> dis(0, 1000000);
    for (int i = 0; i < tam; ++i) {
        v.push_back(dis(gen));
    }
}

// Función para medir el tiempo de ejecución de ordenación
double medirTiempo(std::vector<int>& v, std::string tipoOrdenacion) {

    std::chrono::duration<double> elapsed;

    if(tipoOrdenacion == "Burbuja"){ 
        auto start = std::chrono::high_resolution_clock::now(); 
        burbuja(v); 
        auto end = std::chrono::high_resolution_clock::now();

        elapsed = end - start;
    }
    else if(tipoOrdenacion == "Insercion"){ 
        auto start_2 = std::chrono::high_resolution_clock::now(); 
        insercion(v); 
        auto end_2 = std::chrono::high_resolution_clock::now();

        elapsed = end_2 - start_2;
    }

    return elapsed.count();
}


int main() {
    std::ofstream archivo("resultados.csv");
 
    archivo << std::fixed << std::setprecision(8); // Establecer precisión decimal
    archivo.imbue(std::locale("")); // Para cambiar el separador de miles a la configuración local

    archivo << "Semilla;Tamaño;Burbuja;Insercion;Ganador\n";

    std::vector<int> tamaños = { 1000, 2000, 3000, 4000, 5000};
    std::vector<int> semillas = { 12345, 23451, 34521, 45123 };

    for (int tam : tamaños) {
        for (int semilla : semillas) {
            double tiempoTotalI = 0.0;
            double tiempoTotalB = 0.0;
            std::vector<int> v;
            std::vector<int> v2;

            generarVector(v, tam, semilla);
            tiempoTotalB = medirTiempo(v, "Burbuja");

            generarVector(v2, tam, semilla);
            tiempoTotalI = medirTiempo(v2, "Insercion");

            int ganador = (tiempoTotalI > tiempoTotalB) ? 1 : -1;

            archivo << semilla << ";" << tam << ";" << tiempoTotalB << ";" << tiempoTotalI << ";" << ganador << "\n";
        }
    }

    archivo.close();
    std::cout << "Resultados guardados en 'resultados.csv'.\n";
    return 0;
}
