//Delgado Cruz Cristian 
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>
#include <set>

int burbujabandera(std::vector<int>& vec, int n) //Ordena y luego los ve 1 en 1
{
	int OE;
	bool bandera;
	OE = 3; //Asignacion, comparacion y resta
	for (int i = 0; i < n - 1; i++) {
		OE++;//Asignacion
		bandera = true;
		OE = OE + 4;//Asignacion, comparacion, dos restas
		for (int j = 0; j < n - i - 1; j++) {
			OE = OE + 4;//Comparacion dos accesos una suma
			if (vec[j] > vec[j + 1]) {
				OE = OE + 10;//cuatro Igualaciones cuatro accesos dos sumas
				int tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;
				bandera = false;
			}
			//Vuelta del for: dos restas una comparacion una suma y una asignacion
			OE = OE + 5;
		}
		OE = OE + 1;//Comparacion
		if (bandera) {
			break;
		}
		//Vuelta del for: una resta una comparacion una suma  una asignacion y return
		OE = OE + 4;
	}
	OE = OE + 2;

	std::cout << "Burbuja B Vector Ordenado: ";

	for (int i = 0; i < n; i++)
	{
		//Mirarlo (Solo cuenta 1 OE)
		OE = OE + 1;
		std::cout << vec[i] << " ";
		//Vuelta for
		OE = OE + 2;
	}

	std::cout << std::endl;

	//return
	OE = OE++;

	std::cout << "Burbuja Bandera: " << vec.size() << " - " << OE << std::endl;

	return OE;
}

int busquedaSecuencial(const std::vector<int>& vec, int n) {

	int OE = 1;//asig
	int vMenor = INT_MAX;
	OE += 2;//Asig y comparacion
	for (int i = 0; i < n; ++i) {//n para no tener que usar el metodo vec.size()
		OE = OE + 2;// Acceso a vector y Comparación
		if (vec[i] < vMenor) {
			OE = OE + 2;//Acceso al vector y asignacion
			vMenor = vec[i];
		}
		OE = OE + 3; //Comparacion y Asignacion + suma del bucle
	}
	//Mirarlo (Solo cuenta 1 OE)
	OE = OE + 1;

	OE = OE + 1;//Return
	std::cout << "Secuencial: " << vec.size() << " - " << OE << std::endl;
	return OE;
}

//Mostrarlos//Mostrarlos//Mostrarlos//Mostrarlos//Mostrarlos
void generarVector(std::vector<int>& v, int tam, unsigned int semilla) {
	std::mt19937 gen(semilla); // Inicializar el generador de números aleatorios con una semilla única

	// Generar valores únicos y almacenarlos en el conjunto
	while (v.size() < tam) {
		std::uniform_int_distribution<> dis(1, 1000000);
		v.push_back(dis(gen));
	}

	std::cout << "Vector Inicial: ";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}


int main() {
	std::ofstream archivo("resultados.csv");

	archivo << std::fixed << std::setprecision(8); // Establecer precisión decimal
	archivo.imbue(std::locale("")); // Para cambiar el separador de miles a la configuración local

	archivo << "Numeros;Busqueda Secuencial;Burbuja Bandera;Ganador\n";

	std::vector<int> semillas = { 1234567, 2335670, 45663, 4567123, 5671234, 6712345, 7123456, 567890, 678901, 789056 };

	double OETotalBurbujaBandera = 0.0;
	double OETotalSecuencial = 0.0;
	double OEAUXSecuencial = 0.0;
	int ganador;
	std::vector<int> v;
	std::vector<int> v2;


	for (int j = 1; j <= 10; ++j)
	{
		OETotalBurbujaBandera = 0.0;
		OETotalSecuencial = 0.0;

		v.clear();
		v2.clear();

		generarVector(v, j, semillas[j - 1]);
		generarVector(v2, j, semillas[j - 1]);

		OETotalBurbujaBandera = burbujabandera(v, j);

		for (int k = j; k > 0; k--)//Cuando encuentre el más pequeño nos queda 1 menos
		{
			int valorAleatorio = v[rand() % k];// Genera un número aleatorio entre 1 y n
			OETotalSecuencial += busquedaSecuencial(v2, k);
		}




		if (OETotalBurbujaBandera > OETotalSecuencial)
		{
			ganador = +1;
		}
		else {
			ganador = -1;
		}


		archivo << j << ";" << OETotalSecuencial << ";" << OETotalBurbujaBandera << ";" << ganador << "\n";
	}



	archivo.close();
	std::cout << "Resultados guardados en 'resultados.csv'.\n";
	return 0;
}
