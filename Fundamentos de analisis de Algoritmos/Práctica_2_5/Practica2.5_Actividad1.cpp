//Delgado Cruz Cristian
#include <iostream>
#include <vector>
#include <algorithm>

// Conjunto de monedas disponibles (en céntimos)
const std::vector<int> C = { 200, 100, 50, 20, 10, 5, 2, 1 };


std::vector<int> DevolverCambio(int P) {
    std::vector<int> X(C.size(), 0);
    int actual = 0; 

    while (actual != P) { 
        // Encontrar el mayor elemento de C tal que C[j] ≤ (P - actual)
        int j = -1;
        for (size_t i = 0; i < C.size(); ++i) {
            if (C[i] <= (P - actual)) {
                j = i;
                break;
            }
        }

        // Si no existe ese elemento, no es posible devolver el cambio
        if (j == -1) {
            std::cout << "No existe solucion" << std::endl;
            return {};
        }

        // Insertar la moneda seleccionada en la solución
        X[j] = (P - actual) / C[j];
        actual += C[j] * X[j];
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
        std::cout << std::endl;
    }

    return 0;
}



