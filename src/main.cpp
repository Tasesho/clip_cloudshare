#include "../include/clip.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    Clip assistant;             // Creamos el objeto Clip
    assistant.Hello();          // Saludo inicial

    string comando;

    while(true){
        cout << "Clip> ";
        getline(cin, comando);

        // Convierte el comando ingresado a minúsculas
        transform(comando.begin(), comando.end(), comando.begin(),
                  [](unsigned char c){ return tolower(c); });

        // Ejecuta el comando usando el método central de Clip
        assistant.ExecuteCommand(comando);
    }

    return 0;
}