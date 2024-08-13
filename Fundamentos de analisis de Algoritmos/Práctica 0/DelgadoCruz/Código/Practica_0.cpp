#include "Operaciones.h"
#include <iostream>
using namespace std;

int main()
{
    Operaciones cjt;
    cjt.Vaciar();
    int opcion = 1;
    while (opcion != 0)
    {
        system("cls");
        cout << "Aplicacion operaciones con arrays" << endl << endl;
        cout << "Opciones: " << endl;
        cout << "\n1.- Insertar_valores.";
        cout << "\n2.- Buscar un valor en el vector. ";
        cout << "\n3.- Mostrar_vector.";
		cout << "\n4.- Ordenar_vector.";
        cout << "\n5.- Vaciar vector.";
        cout << "\n0. -Salir\n" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 0: break;
		case 1: {
			int valor;
			cout << "Insertar el valor ";
			cin >> valor;
			cjt.Insertar(valor);			// lo almacena en el array
			cout << "Insertado el " << valor << endl;
			break;
		}
		case 2: {
			int valor;
			cout << "Insertar el valor a buscar ";
			cin >> valor;
			cout << "Se encuentra en la posicion= " << cjt.Busqueda_lineal(valor) << endl;
			break;
		}
		case 3: {
			cout << "Visualizacion del vector: " << endl;
			cjt.Visualizar();
			cout << endl;
			break;
		}
		case 4: {
			cout << "Ordenacion del vector: " << endl; cjt.Visualizar(); cout << endl;
			cjt.Ordena(MAXIMO);
			cout << "Vector ordenado: " << endl; cjt.Visualizar(); cout << endl;
			break;
		}
		case 5: {
			cout << "Vaciar el vector: " << endl; cjt.Visualizar(); cout << endl;
			cjt.Vaciar();
			cout << "Vector inicializado (tamano=0): " << endl; cjt.Visualizar(); cout << endl;
			break;
		}
		default: {
			cout << "Opcion no " << opcion << " no valida. " << endl;

		}
		}
		system("pause");
	}
    return 0;
}