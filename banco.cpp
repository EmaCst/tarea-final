#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

int generarNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void mostrarCaja(const std::queue<int>& caja, int numeroCaja) {
    std::queue<int> cajaAux = caja;
    std::cout << "Caja " << numeroCaja << ": ";
    while (!cajaAux.empty()) {
        std::cout << cajaAux.front() << " ";
        cajaAux.pop();
    }
    std::cout << std::endl;
}

void mostrarPersonasAtendidas(const std::stack<int>& personasAtendidas) {
    std::stack<int> personasAtendidasAux = personasAtendidas;
    std::cout << "Personas atendidas: ";
    while (!personasAtendidasAux.empty()) {
        std::cout << personasAtendidasAux.top() << " ";
        personasAtendidasAux.pop();
    }
    std::cout << std::endl;
    std::cout << "Cantidad de personas atendidas: " << personasAtendidas.size() << std::endl;
}

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

int main() {
    srand(time(0));

    std::queue<int> caja1;
    std::queue<int> caja2;
    std::queue<int> caja3;
    std::queue<int> caja4;
    std::stack<int> personasAtendidas;

    for (int i = 0; i < 200; i++) {
        int numero = generarNumeroAleatorio(1, 90);

        int cajaAleatoria = generarNumeroAleatorio(1, 4);
        if (cajaAleatoria == 1) {
            caja1.push(numero);
        } else if (cajaAleatoria == 2) {
            caja2.push(numero);
        } else if (cajaAleatoria == 3) {
            caja3.push(numero);
        } else {
            caja4.push(numero);
        }

        clearScreen();
        std::cout << "Iteracion " << i + 1 << std::endl;
        std::cout << "Numero generado: " << numero << std::endl;
        mostrarCaja(caja1, 1);
        mostrarCaja(caja2, 2);
        mostrarCaja(caja3, 3);
        mostrarCaja(caja4, 4);
        mostrarPersonasAtendidas(personasAtendidas);
        std::cout << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    for (int i = 0; i < 100; i++) {
        if (!caja1.empty()) {
            personasAtendidas.push(caja1.front());
            caja1.pop();
        }
        if (!caja2.empty()) {
            personasAtendidas.push(caja2.front());
            caja2.pop();
        }
        if (!caja3.empty()) {
            personasAtendidas.push(caja3.front());
            caja3.pop();
        }
        if (!caja4.empty()) {
            personasAtendidas.push(caja4.front());
            caja4.pop();
        }

        if (i % 2 == 0 && !personasAtendidas.empty()) {
            clearScreen();
            std::cout << "Iteracion " << i + 1 << std::endl;
            mostrarCaja(caja1, 1);
            mostrarCaja(caja2, 2);
            mostrarCaja(caja3, 3);
            mostrarCaja(caja4, 4);
            std::cout << "Persona atendida: " << personasAtendidas.top() << std::endl;
            personasAtendidas.pop();
            mostrarPersonasAtendidas(personasAtendidas);
            std::cout << std::endl;
        } else {
            clearScreen();
            std::cout << "Iteracion " << i + 1 << std::endl;
            mostrarCaja(caja1, 1);
            mostrarCaja(caja2, 2);
            mostrarCaja(caja3, 3);
            mostrarCaja(caja4, 4);
            mostrarPersonasAtendidas(personasAtendidas);
            std::cout << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    std::cout << "Personas atendidas: ";
    while (!personasAtendidas.empty()) {
        std::cout << personasAtendidas.top() << " ";
        personasAtendidas.pop();
    }
    std::cout << std::endl;
    std::cout << "Cantidad de personas atendidas: " << personasAtendidas.size() << std::endl;

    return 0;
}
