//Delgado Cruz Cristian 
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>
#include <memory> // Para medir el uso de memoria




void ordena( std::vector<int>& vec)
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



// Función para generar vectores con diferentes distribuciones
void generarVector(std::vector<int>& v, int tam, std::string distribucion, unsigned int semilla) {
    std::mt19937 gen(semilla); // Inicializar el generador de números aleatorios con una semilla única

    if (distribucion == "ascendente") {
        for (int i = 0; i < tam; ++i) {
            v.push_back(i);
        }
    }
    else if (distribucion == "descendente") {
        for (int i = tam - 1; i >= 0; --i) {
            v.push_back(i);
        }
    }
    else if (distribucion == "uniforme") {
        std::uniform_int_distribution<> dis(0, 1000000);
        for (int i = 0; i < tam; ++i) {
            v.push_back(dis(gen));
        }
    }
    else if (distribucion == "gaussiana") {
        std::normal_distribution<> dis(500000, 100000);
        for (int i = 0; i < tam; ++i) {
            v.push_back(dis(gen));
        }
    }
    else {
        // Otros casos de distribución
    }
}

// Función para medir el tiempo de ejecución de ordenación
double medirTiempo(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    ordena(v);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

// Función para medir el uso de memoria (aproximado)
double medirMemoria(std::vector<int>& vec)
{
     // dependerá de la estructura de datos, en un vector lineal es el tamaño por ekl contenido de cada celda
    return vec.size()*sizeof(int);
   
  
}


int main() {
    std::ofstream archivo("resultados.csv");
 
    archivo << std::fixed << std::setprecision(8); // Establecer precisión decimal
    archivo.imbue(std::locale("")); // Para cambiar el separador de miles a la configuración local

    archivo << "Distribución;Tamaño;Mejor Tiempo;Peor Tiempo;Tiempo Medio;Uso de Memoria (bytes)\n";

    std::vector<std::string> distribuciones = { "ascendente", "descendente", "uniforme", "gaussiana" };
    std::vector<int> tamaños = { 1000, 2000, 3000, 4000, 5000};// , 15000, 20000, 25000, 30000, 35000, 40000 };
    std::vector<int> semillas = { 12345,23451, 34512, 45123, 51234 };
  //  unsigned int semilla = 42; // Semilla única para la generación de números aleatorios
    // std::mt19937 gen(semilla);
    for (const std::string& distribucion : distribuciones) {
        for (int tam : tamaños) {
            double mejorTiempo = std::numeric_limits<double>::max();
            double peorTiempo = std::numeric_limits<double>::min();
            double tiempoTotal = 0.0;
            double memoria_usada = 0.0;
          

            for (int i = 0; i < 5; ++i) {
                std::vector<int> v;
                generarVector(v, tam, distribucion, semillas[i]);

                double tiempo = medirTiempo(v); 
                mejorTiempo = std::min(mejorTiempo, tiempo);
                peorTiempo = std::max(peorTiempo, tiempo);
                tiempoTotal += tiempo;

                // Medir el uso de memoria
                memoria_usada = medirMemoria(v);

             
                
            }

            double tiempoMedio = tiempoTotal / 5.0;
            archivo << distribucion << ";" << tam << ";" << mejorTiempo << ";" << peorTiempo << ";" << tiempoMedio << ";" << memoria_usada  << "\n";
        }
    }

    archivo.close();
    std::cout << "Resultados guardados en 'resultados.csv'.\n";
    return 0;
}
