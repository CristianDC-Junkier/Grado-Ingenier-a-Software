//Delgado Cruz Cristian 
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <fstream>
#include <random>
#include <iomanip>



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

// Función para generar vectores con la distribución uniforme
void generarVector(std::vector<int>& v, int tam, unsigned int semilla) {
    std::mt19937 gen(semilla);

    std::uniform_int_distribution<> dis(0, 1000000);
    for (int i = 0; i < tam; ++i) {
        v.push_back(dis(gen));
    }
}


int main() {
    std::ofstream archivo("Resultados.csv");

    archivo << std::fixed << std::setprecision(8); // Establecer precisión decimal
    archivo.imbue(std::locale("")); // Para cambiar el separador de miles a la configuración local

    archivo << "Semilla;Tamaño;QuickSort;MergeSort;Ganador\n";

    std::vector<int> tamanos = { 500, 1000, 1500, 2000, 2500 };
    std::vector<int> semillas = { 12345, 23451, 34521, 45123 };

    for (int tam : tamanos) {
        for (int semilla : semillas) {
            double OETotalM = 0.0;
            double OETotalQ = 0.0;
            std::vector<int> v;
            std::vector<int> v2;

            generarVector(v, tam, semilla);
            OETotalQ = quick_sort(v);

            generarVector(v2, tam, semilla);
            OETotalM = mergesort(v2,0,v2.size()-1);

            int ganador = (OETotalM > OETotalQ) ? 1 : -1;

            archivo << semilla << ";" << tam << ";" << OETotalQ << ";" << OETotalM << ";" << ganador << "\n";
        }
    }

    archivo.close();
    std::cout << "Resultados guardados en 'Resultados.csv'.\n";
    return 0;
}
