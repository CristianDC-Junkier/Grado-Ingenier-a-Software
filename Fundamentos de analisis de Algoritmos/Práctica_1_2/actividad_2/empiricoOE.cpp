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


double ordena(std::vector<int>& vec)
{
    double OE = 0;
    OE++; //Asignacion Tam;
    OE++; //vec.size() (Acceso)
    int tam = vec.size();
    OE++;//Asignacion i
    OE++;//Comparacion
    OE++;//Resta
    for (int i = 0; i < tam - 1; i++) {
        OE++;//Asignacion j
        OE++;//Comparacion
        OE++;//Suma
        for (int j = i + 1; j < tam; j++) {
            OE = OE + 2;//Accesos
            OE++;//Comparacion
            if (vec[j] < vec[i]) {
                OE = OE + 4;//Accesos
                OE = OE + 3;//Asignaciones
                int tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
            }
            OE = OE + 1; //Comparacion
            OE = OE + 2; //j++;
        }
        OE = OE + 2; //Comparacion y resta
        OE = OE + 2; //i++;
    }
    OE = OE + 1; //Return 
    return OE;
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

// Función para medir el uso de memoria (aproximado)
double medirMemoria(std::vector<int>& vec)
{
    // dependerá de la estructura de datos, en un vector lineal es el tamaño por ekl contenido de cada celda
    return vec.size() * sizeof(int);
}

int main() {
    std::ofstream archivo("resultadosOE.csv");

    archivo << std::fixed << std::setprecision(8); // Establecer precisión decimal
    archivo.imbue(std::locale("")); // Para cambiar el separador de miles a la configuración local

    archivo << "Distribución;Tamaño;Mejor OE;Peor OE;OE Medio;Uso de Memoria (bytes)\n";

    std::vector<std::string> distribuciones = { "ascendente", "descendente", "uniforme", "gaussiana" };
    std::vector<int> tamaños = { 1000, 2000, 3000, 4000, 5000 };// , 15000, 20000, 25000, 30000, 35000, 40000 };
    std::vector<int> semillas = { 12345,23451, 34512, 45123, 51234 };

    //unsigned int semilla = 42; // Semilla única para la generación de números aleatorios
    //std::mt19937 gen(semilla);
    for (const std::string& distribucion : distribuciones) {
        for (int tam : tamaños) {
            double mejorOE = DBL_MAX;
            double peorOE = DBL_MIN;
            double OETotal = 0.0;
            double memoria_usada = 0.0;


            for (int i = 0; i < 5; ++i) {
                std::vector<int> v;
                generarVector(v, tam, distribucion, semillas[i]);

                double OE = ordena(v);
                mejorOE = std::min(mejorOE, OE);
                peorOE = std::max(peorOE, OE);
                OETotal += OE;

                // Medir el uso de memoria
                memoria_usada = medirMemoria(v);
            }

            double OEMedio = OETotal / 5.0;
            archivo << distribucion << ";" << tam << ";" << mejorOE << ";" << peorOE << ";" << OEMedio << ";" << memoria_usada << "\n";
        }
    }

    archivo.close();
    std::cout << "Resultados guardados en 'resultadosOE.csv'.\n";
    return 0;
}