#pragma once
// Clase conjunto de enteros con tamaño máximo limitado.
#define MAXIMO 5  // TAMAÑO MÁXIMO 5
class Operaciones
{
private:
    int tamano;
    int datos[MAXIMO];
public:
    void Insertar(int n);
    int Busqueda_lineal(int n);
    void Ordena(int tam);
    void Visualizar(); 
    void Vaciar();
};