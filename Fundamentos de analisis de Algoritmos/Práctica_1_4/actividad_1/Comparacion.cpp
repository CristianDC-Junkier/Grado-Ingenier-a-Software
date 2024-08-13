//Delgado Cruz Cristian 
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>

void burbujabandera(std::vector<int>& vec)
{

	int tam = vec.size();
	bool bandera = false;
	for (int i = 0; i < tam - 1; i++) {
		bandera = true;
		for (int j = 0; j < tam - i - 1; j++) {
			if (vec[j] > vec[j + 1]) {
				int tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;
				bandera = false;
			}
		}
		if (bandera) {
			break;
		}
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


// Función para generar vectores con diferentes distribuciones
void generarVector(std::vector<int>& v, int tam, unsigned int semilla) {
	std::mt19937 gen(semilla); // Inicializar el generador de números aleatorios con una semilla única

	std::uniform_int_distribution<> dis(0, 1000000);
	for (int i = 0; i < tam; ++i) {
		v.push_back(dis(gen));
	}

}

// Función para medir el tiempo de ejecución de ordenación
double medirTiempo(std::vector<int>& v, std::string cual) {

	std::chrono::duration<double> elapsed = 0;

	if (cual == "Burbuja") {
		auto start = std::chrono::high_resolution_clock::now();
		burbuja(v);
		auto end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
	}
	else if (cual == "BurbujaBandera") {
		auto start = std::chrono::high_resolution_clock::now();
		burbujabandera(v);
		auto end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
	}
	return elapsed.count();
}


int main() {
	std::ofstream archivo("resultados.csv");

	archivo << std::fixed << std::setprecision(8); // Establecer precisión decimal
	archivo.imbue(std::locale("")); // Para cambiar el separador de miles a la configuración local

	archivo << "Semilla;Burbuja;BurbujaBandera;Ganador\n";

	std::vector<int> semillas = { 1234567, 2345671, 3456712, 4567123, 5671234, 6712345, 7123456, 567890, 678901, 789056 };
	//  unsigned int semilla = 42; // Semilla única para la generación de números aleatorios
	// std::mt19937 gen(semilla);

	double tiempoTotalBurbuja = 0.0;
	double tiempoTotalBurbujaBandera = 0.0;
	int ganador;
	double tiempo;

	for (int i = 0; i < semillas.size(); ++i) {
		std::vector<int> v;
		std::vector<int> v2;
		generarVector(v, 10000, semillas[i]);
		generarVector(v2, 10000, semillas[i]);

		tiempoTotalBurbuja = medirTiempo(v,"Burbuja");

		tiempoTotalBurbujaBandera = medirTiempo(v2,"BurbujaBandera");
		
		if (tiempoTotalBurbuja < tiempoTotalBurbujaBandera)
		{
			ganador = +1;
		}
		else {
			ganador = -1;
		}

		archivo << semillas[i] << ";" << tiempoTotalBurbuja << ";" << tiempoTotalBurbujaBandera << ";" << ganador <<  "\n";

	}


	archivo.close();
	std::cout << "Resultados guardados en 'resultados.csv'.\n";
	return 0;
}
