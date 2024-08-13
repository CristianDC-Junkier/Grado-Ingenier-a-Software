//Delgado Cruz Cristian
#include <iostream>
#include <vector>
#include <algorithm>

// Conjunto de monedas disponibles (en céntimos)
const std::vector<int> C = { 200, 100, 50, 20, 10, 5, 2, 1 };

// Máximo número de cada tipo de moneda disponible
std::vector<int> maxDisponibles = { 3, 2, 1, 6, 5, 1, 1, 1 };

// Función para devolver el cambio
std::vector<int> DevolverCambio(int P) {
    std::vector<int> X(C.size(), 0);
    int actual = 0; 

    //Reiniciamos las monedas
    maxDisponibles = { 3, 2, 1, 6, 5, 1, 1, 1 };

    while (actual != P) { // Mientras no se haya alcanzado la cantidad P
        // Encontrar el mayor elemento de C tal que C[j] ≤ (P - actual) y que tenga disponibilidad
        int j = -1;
        for (size_t i = 0; i < C.size(); ++i) {
            if (C[i] <= (P - actual) && maxDisponibles[i] > 0) {
                j = i;
                break;
            }
        }

        // Si no existe ese elemento, no es posible devolver el cambio
        if (j == -1) {
            return {};
        }

        // Calcular la cantidad de monedas de tipo C[j] a utilizar
        int numMonedas = std::min((P - actual) / C[j], maxDisponibles[j]);

        // Insertar la moneda seleccionada en la solución
        X[j] = numMonedas;
        actual += C[j] * numMonedas;

        // Reducir la disponibilidad de la moneda utilizada
        maxDisponibles[j] -= numMonedas;
    }

    return X; 
}

int main() {
    // Lista de cantidades a probar (en céntimos)
    std::vector<int> cantidades = { 345, 1248, 890, 524, 48, 2550 };

    for (int P : cantidades) {
        std::vector<int> resultado = DevolverCambio(P);


        std::cout << "Para devolver " << P << " centimos, se necesitan:" << std::endl;
        for (size_t i = 0; i < resultado.size(); ++i) {
            if (resultado[i] > 0) {
                std::cout << resultado[i] << " moneda(s) de " << C[i] << " centimos" << std::endl;
            }
        }
        if (resultado.size() == 0)
        {
            std::cout << "No existe solucion" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
