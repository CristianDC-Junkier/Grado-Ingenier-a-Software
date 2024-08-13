//Delgado Cruz Cristian
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <algorithm>



// Funci�n para generar un vector de n elementos aleatorios sin n�meros repetidos
std::vector<int> generarVectorAleatorio(int n) {
    std::vector<int> vec;
    for (int i = 0; i < n; ++i) {
        vec.push_back(i + 1); // Llena el vector con n�meros del 1 al n
    }
    std::random_shuffle(vec.begin(), vec.end()); // Mezcla los n�meros aleatoriamente
    return vec;
}

// Funci�n para realizar una b�squeda secuencial en un vector
int busquedaSecuencial(const std::vector<int>& vec, int target, int n) {

    int OE = 2;//i=0 & i < vec.size() (Asignacion y Comparaci�n final)

    for (int i = 0; i < n; ++i) {//n para no tener que usar el metodo vec.size()

        OE = OE + 2;// vec[i] & vec[i] == target (Acceso a vector y Comparaci�n)

        if (vec[i] == target) {
            OE = OE + 1;//Return
            return OE; // Si se encuentra el elemento, devuelve true
        }

        OE = OE + 2; //i = i + 1 & i < vec.size() (Asignaci�n y Comparaci�n del bucle)

    }
    OE = OE + 1;//Return
    return OE; // Si no se encuentra el elemento, devuelve false
}



int main() {


    srand(time(0)); // Inicializa la semilla para generar n�meros aleatorios

    std::ofstream archivo("resultados.csv");
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    archivo << std::fixed << std::setprecision(0); // Fijar precisi�n decimal a 0

    archivo << "Tamano del Vector;Caso mejor(OE);Caso peor (OE);Caso medio (OE)" << std::endl;

    for (int n = 1000; n <= 10000; n += 1000) {

        int OE_total = 0.0;
        int mejor_OE = INT_MAX;
        int peor_OE = 0.0;

        std::vector<int> vectorAleatorio = generarVectorAleatorio(n);
        // Realiza 100 b�squedas aleatorias y mide el tiempo
        for (int i = 0; i < 100; ++i) {

            int valorAleatorio = rand() % n + 1; // Genera un n�mero aleatorio entre 1 y n

            int OE_busqueda = busquedaSecuencial(vectorAleatorio, valorAleatorio, n);
            OE_total += OE_busqueda;

            mejor_OE = std::min(mejor_OE, OE_busqueda);
            peor_OE = std::max(peor_OE, OE_busqueda);
        }

        double OE_medio = OE_total / 100;


        archivo << n << ";" << mejor_OE << ";" << peor_OE << ";" << OE_medio << std::endl;

    }

    std::cout << "Los resultados se han guardado en el archivo 'resultados.csv'." << std::endl;

    archivo.close();

    return 0;
}
