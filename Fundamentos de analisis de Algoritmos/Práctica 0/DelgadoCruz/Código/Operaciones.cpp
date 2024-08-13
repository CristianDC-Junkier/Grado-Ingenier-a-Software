#include "Operaciones.h"
#include <iostream>
using namespace std;


void Operaciones::Insertar(int n)
{
    if (tamano < MAXIMO)
        datos[tamano++] = n; // pueden estar repetidos pues no se comprueba si ya está el n
    else
        cerr << "ERROR: el conjunto esta lleno " << endl;
}

int Operaciones::Busqueda_lineal(int n)
{
    int i = 0;
    int Asignaciones = 0, Comparaciones = 0, Ops_Elementales = 0;

    //While primera comparacion
    Comparaciones = Comparaciones + 2;
    Ops_Elementales = Ops_Elementales + 1;

    while (datos[i] != n && i < tamano)
    {
        Comparaciones = Comparaciones + 2;

        i = i + 1;

        Asignaciones = Asignaciones + 1;
        Ops_Elementales = Ops_Elementales + 2;
    }

    Comparaciones = Comparaciones + 1;//datos[i] == n
    Ops_Elementales = Ops_Elementales + 2;//Return y Acceso a datos[i]

    if (datos[i] == n)
        return i;	 // se encuentra el elemento en el array
    else
        return -1;  // no se encuentra el elemento en el array
}

void Operaciones::Ordena(int tam)
{
    int Asignaciones = 0, Comparaciones = 0, Ops_Elementales = 0;

    for (int i = 0; i < tam - 1; i++)
        for (int j = i + 1; j < tam; j++) {

            if (datos[j] < datos[i]) {

                int tmp = datos[i];
                datos[i] = datos[j];
                datos[j] = tmp;

                Asignaciones = Asignaciones + 3;

                Ops_Elementales = Ops_Elementales + 4;
            }
            Comparaciones = Comparaciones + 1;
            Ops_Elementales =  Ops_Elementales + 2;
        }

    Ops_Elementales = Ops_Elementales + Comparaciones + Asignaciones;

    cout << "Asignaciones: " << Asignaciones << "\n"
        << "Comparaciones: " << Comparaciones << "\n"
        << "Ops_Elementales: " << Ops_Elementales << "\n";
}

void Operaciones::Visualizar()
{
    for (int i = 0; i < tamano; i++)
        cout << datos[i] << (i < tamano - 1 ? ", " : "\n");
}

void Operaciones::Vaciar()
{
    tamano = 0;
}
