//DelgadoCruzCristian
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>

typedef unsigned long long int largo;

// Función para calcular a^n
largo potencia1(int a, int n, int& OE) {

	OE = 1; //Asignacion de r
	largo r = 1;

	OE += 2;//Asignacion y comparacion del for
	for (int i = 1; i <= n; ++i) {
		OE += 2;//Asignacion y multiplicacion
		r *= a;
		OE += 3;//Asignacion, suma, y comparacion de la vuelta del for
	}
	return r; // Devuelve el resultado final
}

// Función recursiva para calcular a^n 
largo potencia2(int a, int n, int& OE) {
	OE++;//Comparacion
	if (n == 0) {
		return 1; // Caso base: cualquier número elevado a 0 es 1
	}
	else {
		OE += 2;//Llamada y resta
		return a * potencia2(a, n - 1, OE);
	}
}

// Función recursiva para calcular a^n utilizando la técnica de divide y vencerás
largo potencia3(int a, int n, int& OE) {
	OE++; //Comparacion
	if (n == 0) {
		return 1; // Caso base: cualquier número elevado a 0 es 1
	}
	else {
		OE += 3;//Asignacion, division y llamada
		largo half = potencia3(a, n / 2, OE);
		OE += 2;//Comparacion, resto
		if (n % 2 == 0) {// Si n es par
			OE++;//Multiplicacion
			return half * half;
		}
		else {// Si n es impar
			OE += 2; //Doble Multiplicacion 
			return a * half * half;
		}
	}
}


// Función para medir el tiempo de ejecución de ordenación
double medirTiempoOE(int base, int exponente, int tipo, largo& resultado, int& OE) {

	int OEx = 0;

	if (tipo == 0) {
		auto start = std::chrono::high_resolution_clock::now();
		resultado = potencia1(base, exponente, OEx);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		OE = OEx;
		return elapsed.count();
	}
	else if (tipo == 1) {
		auto start = std::chrono::high_resolution_clock::now();
		resultado =  potencia1(base, exponente, OEx);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		OE = OEx;
		return elapsed.count();
	}
	else {
		auto start = std::chrono::high_resolution_clock::now();
		resultado =  potencia1(base, exponente, OEx);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		OE = OEx;
		return elapsed.count();
	}




}



int main() {

	std::ofstream file("resultados.csv", std::ios::out);
	if (!file) {
		std::cerr << "Error al abrir el archivo!" << std::endl;
		return 1;
	}

	file << "Tipo;" << "exponente (n);" << "OE;" << "Tiempo;" << "\n";

	std::srand(42);//Semilla 42

	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 10; j++)
		{

			//Generamos aleatoriamente los números
			int base = std::rand() % 20 + 1;
			int exponente = std::rand() % 20 + 1;

			//Tiempo y OE
			int OE = 0;
			largo resultado = 0;
			double tiempo = medirTiempoOE(base, exponente, i, resultado ,OE);

			// Visualización por pantalla de las variables
			std::cout << "-----------------------------------------------------------------" << std::endl;
			std::cout << "Metodo: potencia" << i+1 << std::endl;
			std::cout << "a: " << base << std::endl;
			std::cout << "n: " << exponente << std::endl;
			std::cout << "Resultado: " << resultado << std::endl;
			std::cout << "Numero de operaciones elementales: " << OE << std::endl;
			std::cout << "Tiempo de ejecucion en milisegundos: " << tiempo*1000 << " ms" << std::endl;
			
			switch (i)
			{
			case 0:
				file << "Iterativa;" << exponente << ";" << OE << ";" << tiempo * 1000 << "\n";
				break;
			case 1:
				file << "Recursiva;" << exponente << ";" << OE << ";" << tiempo * 1000 << "\n";
				break;
			case 2:
				file << "Divide y venceras;" << exponente << ";" << OE << ";" << tiempo * 1000 << "\n";
				break;
			}


		}

	}

	std::cout << "-----------------------------------------------------------------" << std::endl;
	file.close();
	std::cout << "Resultados guardados en 'resultados.csv'.\n";
	return 0;
}
