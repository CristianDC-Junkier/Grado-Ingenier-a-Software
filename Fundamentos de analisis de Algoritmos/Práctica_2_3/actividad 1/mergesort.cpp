//DelgadoCruzCristian
#include <iostream>
#include <vector>
#include <algorithm>


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

		//Mostrar el vector actual
		std::cout << "Vector que llega: [";
		for (int i = primero; i <= ultimo; ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << "]\n";
		//-------------------------

		OE += 4;//Llamada a los metodos más una suma
		mergesort(v, c, primero, medio, OE);
		mergesort(v, c, medio + 1, ultimo, OE);
		combine(v, c, primero, medio, ultimo, OE);


		//Mostrar el pivote
		std::cout << "\tPivote: " << v[medio] << "\n";
		//-----------------

		//Mostrar la particion de la izquierda
		std::cout << "Particion izquierda: [";
		for (int i = primero; i <= medio; ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << "]\n";
		//-------------------------------------

	    //Mostrar la particion de la derecha
		std::cout << "Particion derecha: [";
		for (int i = medio + 1; i <= ultimo; ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << "]\n";
		//-------------------------------------
	}
}

double mergesort(std::vector<int>& v, int primero, int ultimo)
{
	double OE = 0;
	std::vector<int> c(v.size());
	mergesort(v, c, primero, ultimo, OE);
	return OE;
}




int main() {
	std::vector<int> v{ 10, 14, 12, 24, 93, 2, 45, 56, 76, 23, 45, 87, 32, 75, 1, 3, 5 };
	double OE = mergesort(v, 0, v.size() - 1);
	std::cout << "Número total de OE: " << OE << "\n";

	return 0;
}
