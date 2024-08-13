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



void combine(std::vector<int>& v, std::vector<int>& c, int primero, int medio, int ultimo, double& OE)
{
	OE += 6; //3 asignaciones 2 comparaciones y 1 suma
	int i = primero, j = medio + 1, k = primero;
	while (i <= medio && j <= ultimo)
	{
		OE += 3; // 2 Accesos y 1 Comparación
		if (v[i] < v[j]) {
			c[k++] = v[i++];
			OE += 7; // 2 accesos 3 asignacion 2 sumas 
		}
		else {
			c[k++] = v[j++];
			OE += 7; // 2 accesos 3 asignacion 2 sumas 
		}
		OE += 2; //2 comparaciones (vuelta del while)
	}
	OE++;//1 Comparacion
	while (i <= medio) {
		OE += 7;// 2 accesos 3 asignacion 2 sumas 
		c[k++] = v[i++];
		OE++; //1 comparacion (vuelta del while)
	}
	OE++; //1 Comparacion
	while (j <= ultimo) {
		OE += 7;// 2 accesos 3 asignacion 2 sumas 
		c[k++] = v[j++];
		OE++; //1 comparacion (vuelta del while)
	}


	OE += 2;//Asignacion, comparacion
	for (i = primero; i < k; i++) {
		OE += 3; //1 asignacion 2 accesos
		v[i] = c[i];
		OE += 3; //1 comparacion 1 asignacion 1 suma(vuelta del for)
	}
}


void mergesort(std::vector<int>& v, std::vector<int>& c, int primero, int ultimo, double& OE)
{
	OE += 1;//Comparación

	if (primero < ultimo) {
		OE += 3;//Suma, Division e Asignacion
		int medio = (primero + ultimo) / 2;

		OE += 4;//Llamada a los metodos más una suma
		mergesort(v, c, primero, medio, OE);
		mergesort(v, c, medio + 1, ultimo, OE);
		combine(v, c, primero, medio, ultimo, OE);
	}
}

double mergesort(std::vector<int>& v, int primero, int ultimo)
{
	double OE = 0;
	std::vector<int> c(v.size());
	mergesort(v, c, primero, ultimo, OE);
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
    std::ofstream archivo("resultados.csv");

    

    archivo << std::fixed << std::setprecision(8); // Establecer precisión decimal
    archivo.imbue(std::locale("")); // Para cambiar el separador de miles a la configuración local

    archivo << "Distribucion;Tamaño;Mejor OE;Peor OE;OE Medio;Uso de Memoria (bytes)\n";

    std::vector<std::string> distribuciones = { "ascendente", "descendente", "uniforme", "gaussiana" };
    std::vector<int> tamanos = { 500, 1000, 1500, 2000, 2500 };// , 15000, 20000, 25000, 30000, 35000, 40000 };
    std::vector<int> semillas = { 12345,23451, 34512, 45123, 51234 };

    //unsigned int semilla = 42; // Semilla única para la generación de números aleatorios
    //std::mt19937 gen(semilla);
    for (const std::string& distribucion : distribuciones) {
        for (int tam : tamanos) {
            double mejorOE = DBL_MAX;
            double peorOE = DBL_MIN;
            double OETotal = 0.0;
            double memoria_usada = 0.0;


            for (int i = 0; i < 5; ++i) {
                std::vector<int> v;
                generarVector(v, tam, distribucion, semillas[i]);

                double OE = mergesort(v, 0, v.size() - 1);
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
    std::cout << "Resultados guardados en 'resultados.csv'.\n";
    return 0;
}