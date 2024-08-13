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



// Funci�n para generar vectores con diferentes distribuciones
void generarVector(std::vector<int>& v, int tam, std::string distribucion, unsigned int semilla) {
    std::mt19937 gen(semilla); // Inicializar el generador de n�meros aleatorios con una semilla �nica

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
        // Otros casos de distribuci�n
    }
}

// Funci�n para medir el tiempo de ejecuci�n de ordenaci�n
double medirTiempo(std::vector<int>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    ordena(v);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

// Funci�n para medir el uso de memoria (aproximado)
double medirMemoria(std::vector<int>& vec)
{
     // depender� de la estructura de datos, en un vector lineal es el tama�o por ekl contenido de cada celda
    return vec.size()*sizeof(int);
   
  
}


int main() {
    std::ofstream archivo("resultados.csv");
 
    archivo << std::fixed << std::setprecision(8); // Establecer precisi�n decimal
    archivo.imbue(std::locale("")); // Para cambiar el separador de miles a la configuraci�n local

    archivo << "Distribuci�n;Tama�o;Mejor Tiempo;Peor Tiempo;Tiempo Medio;Uso de Memoria (bytes)\n";

    std::vector<std::string> distribuciones = { "ascendente", "descendente", "uniforme", "gaussiana" };
    std::vector<int> tama�os = { 1000, 2000, 3000, 4000, 5000};// , 15000, 20000, 25000, 30000, 35000, 40000 };
    std::vector<int> semillas = { 12345,23451, 34512, 45123, 51234 };
  //  unsigned int semilla = 42; // Semilla �nica para la generaci�n de n�meros aleatorios
    // std::mt19937 gen(semilla);
    for (const std::string& distribucion : distribuciones) {
        for (int tam : tama�os) {
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
