#include "../include/clip.hpp"
#include "../include/todo.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    Clip assistant;            // Creamos el objeto Clip
    ToDoManager Manager; 
    assistant.Hello();          // Saludo inicial

    string comando;

    while(true){
        cout << "Clip> ";
        getline(cin, comando);

        // Convierte el comando ingresado a minúsculas
        transform(comando.begin(), comando.end(), comando.begin(),
                  [](unsigned char c){ return tolower(c); });

        if(comando=="todo" || comando== "task" || comando=="to-do") {
            Manager.manageMenu();
        }
        else{
            // Ejecuta el comando usando el método central de Clip
        assistant.ExecuteCommand(comando);
        }         
        
    }

    return 0;
}