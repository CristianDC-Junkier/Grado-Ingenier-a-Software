//Delgado Cruz Cristian 
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>


double insercion(std::vector<int>& vec)
{
    double OE = 0;
    OE = OE + 2; //Asignacion  + Acceso al vector;
    int n = vec.size();
    OE = OE + 2; //Asignacion  + Compracion del bucle;
    for (int i = 1; i < n; ++i) {
        OE = OE + 2; //Asignacion  + Acceso a posicion del vector;
        int clave = vec[i];
        OE = OE + 2; //Asignacion  + Resta;
        int j = i - 1;
        OE = OE + 3; //2 Comparaciones  + Acceso a posicion del vector de inicio del bucle while;
        while (j >= 0 && vec[j] > clave) {
            OE = OE + 4; //Asignacion  + 2 Acceso a posicion del vector + 1 suma;
            vec[j + 1] = vec[j];
            OE = OE + 2; //Asignacion  + Resta;
            --j;
            OE = OE + 3; //2 Comparaciones  + Acceso a posicion del vector del bucle while;
        }
        OE = OE + 3; //Acceso a posicion del vector  + Suma + Asignacion;
        vec[j + 1] = clave;
        OE = OE + 3; //Comparacion  + Igualacion + Suma del bucle;
    }
    OE = OE + 1; //Return 
    return OE;
}

template <typename elem>
int partition(std::vector <elem>& T, int e, int d, int& OE) {
    OE += 2;	//igualacion  + acceso
    elem x = T[e];
    OE += 2;	//igualacion  + resta
    int i = e - 1;
    OE += 2;	//igualacion  + suma
    int j = d + 1;
    while (true) {
        OE += 4;	//comparacion, resta, asignacion y acceso
        while (x < T[--j]);
        OE += 4;	//comparacion, resta, asignacion y acceso
        while (T[++i] < x);
        OE++;	//comparacion
        if (i >= j) return j;
        OE += 3;	//llamada y dos accesos
        std::swap(T[i], T[j]);
    }
}

template <typename elem>
void quick_sort(std::vector <elem>& T, int e, int d, int& OE) {

    OE++;	//comparacion 
    if (e < d) {
        //PIVOTE
        OE++;	//igualacion + llamada 
        int q = partition(T, e, d, OE);
        //PRIMERA PARTICION
        OE++;
        quick_sort(T, e, q, OE);
        //SEGUNDA PARTICION
        OE += 2;	//llamada  + suma
        quick_sort(T, q + 1, d, OE);

    }
}

template <typename elem>
int quick_sort(std::vector <elem>& T) {

    int OE = 3;//2 llamadas y una recta
    quick_sort(T, 0, T.size() - 1, OE);
    return OE;
}


// Función para generar vectores con la distribución uniforme
void generarVector(std::vector<int>& v, int tam, unsigned int semilla) {
    std::mt19937 gen(semilla);

    std::uniform_int_distribution<> dis(0, 1000000);
    for (int i = 0; i < tam; ++i) {
        v.push_back(dis(gen));
    }
}


int main() {
    std::ofstream archivo("resultados.csv");

    archivo << std::fixed << std::setprecision(8); // Establecer precisión decimal
    archivo.imbue(std::locale("")); // Para cambiar el separador de miles a la configuración local

    archivo << "Semilla;Tamaño;QuickSort;Insercion;Ganador\n";

    std::vector<int> tamanos = { 500, 1000, 1500, 2000, 2500 };
    std::vector<int> semillas = { 12345, 23451, 34521, 45123 };

    for (int tam : tamanos) {
        for (int semilla : semillas) {
            double OETotalI = 0.0;
            double OETotalQ = 0.0;
            std::vector<int> v;
            std::vector<int> v2;

            generarVector(v, tam, semilla);
            OETotalQ = quick_sort(v);

            generarVector(v2, tam, semilla);
            OETotalI = insercion(v2);

            int ganador = (OETotalI > OETotalQ) ? 1 : -1;

            archivo << semilla << ";" << tam << ";" << OETotalQ << ";" << OETotalI << ";" << ganador << "\n";
        }
    }

    archivo.close();
    std::cout << "Resultados guardados en 'resultados.csv'.\n";
    return 0;
}
