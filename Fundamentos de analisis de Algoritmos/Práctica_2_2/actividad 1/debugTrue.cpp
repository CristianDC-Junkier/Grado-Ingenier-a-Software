//Delgado Cruz Cristian

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


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

		std::string cadena_auxiliar = "[";

		//INICIAL
		for (int i = 0; i < T.size(); i++) {

			cadena_auxiliar += std::to_string(T[i]);
			if (i != T.size() - 1) {
				cadena_auxiliar += ",";
			}
		}
		std::cout << std::endl << "Llega el vector:" << cadena_auxiliar << "]";

		//PIVOTE
		OE++;	//igualacion + llamada 
		int q = partition(T, e, d, OE);

		std::cout << " su Pivote es: " << q << std::endl;

		//PRIMERA PARTICION
		OE++;	//llamada 
		quick_sort(T, e, q, OE);

		cadena_auxiliar = "[";
		for (int i = 0; i < T.size(); i++) {

			cadena_auxiliar += std::to_string(T[i]);
			if (i != T.size() - 1) {
				cadena_auxiliar += ",";
			}
		}
		std::cout << "Particion 1:" << cadena_auxiliar << "]" << std::endl;

		//SEGUNDA PARTICION
		OE += 2;	//llamada  + suma
		quick_sort(T, q + 1, d, OE);

		cadena_auxiliar = "[";
		for (int i = 0; i < T.size(); i++) {

			cadena_auxiliar += std::to_string(T[i]);
			if (i != T.size() - 1) {
				cadena_auxiliar += ",";
			}
		}
		std::cout << "Particion 2:" << cadena_auxiliar << "]" << std::endl;
}

template <typename elem>
int quick_sort(std::vector <elem>& T ) {

	int OE = 3;//2 llamadas y una recta
	quick_sort(T, 0, T.size() - 1 , OE);
	return OE;
}



int main()
{
	std::vector <int> T {10, 14, 12, 24, 93, 2, 45, 56, 76, 23, 45, 87, 72, 35, 1, 3, 5};

	std::cout << "Numero de OE: " << quick_sort(T) << std::endl;

	//Mostrar vector ordenado
	std::string cadena_auxiliar = "[";
	for (int i = 0; i < T.size(); i++) {

		cadena_auxiliar += std::to_string(T[i]);
		if (i != T.size() - 1) {
			cadena_auxiliar += ",";
		}
	}
	std::cout << "Vector ordenado: " << cadena_auxiliar << "]";

}

