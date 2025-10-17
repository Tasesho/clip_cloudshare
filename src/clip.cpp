/*this file only contains methods definitions of Clip class. Use methods inheritance.*/

#include "../include/clip.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

//-----CONSTRUCTOR, it init: advices, commands, actions.------------

Clip::Clip(){  
    //vector of string with advices 
    advices ={
        "The past cannot be changed, it can only be accepted.",
        "For every defeat, I ran around the mountain, until not even shame could keep up",
        "We are privileged to breathe, to taste the air! It is the last gasp of all who have died before us.",
        "Exist to be happy, not to impress.",
    };

    //map (string, string) used for descriptions
    Commands ={
        {"hello", "Clip saludates you :)\n"},
        {"giveadvice", "Clip gives you an advice ;)\n"},
        {"showhour", "Shows system date.\n"},
        {"clear", "Clean the current CMD tab\n"},
        {"exit", "Closes Clip\n"},
        {"run", "Run an adress in your computer: C: direccion_of_file\n"},
        {"convertfile", "Converts a docx file into pdf (COMING SOON)\n"}
    };


    actions ={
        {"hello", &Clip::Hello},
        {"help", &Clip::Help},
        {"giveadvice", &Clip::GiveAdvice},
        {"showhour", &Clip::ShowHour},
        {"run", &Clip::Run},
        {"convertfile", &Clip::ConvertFile}
    };

}

//Functions map that run commands


void Clip::Hello() {
    cout << "Hello! I'm Clip your assistant made in C++.\n";
    cout << "Write 'Help' to deploy a list of commands.\n";
}

void Clip::Help() {
    cout << "\n--- Comandos ---\n";
    for (const auto& cmd : Commands)
        cout << cmd.first << " -> " << cmd.second << "\n";
    cout << "-----------------\n";
}

void Clip::GiveAdvice() {
    srand(time(0));
    int index = rand()  %advices.size();
    cout<<"Consejo: "<<advices[index]<<"\n";
    }

void Clip::ShowHour() {
    time_t ahora = time(nullptr);
    cout << "Hora actual: " << ctime(&ahora);
}

void Clip::Run() {
    string path;
    cout<< "Ingresa direccion que deseas ingresar: ";
    getline(cin, path);

    if(path.empty()){
        cout<<"No se ingreso ninguna direccion.\n";
        return;
    }

    string command= "start \"\" \"" + path+ "\"";
    system(command.c_str());
} 

void Clip::ExecuteCommand(const string& command){
    auto it= actions.find(command);  //search for commands in 'keys'
    if(it != actions.end()){
        (this->*(it->second))();    // runs the method if found
    }
    else if(command =="clear"){
        system(CLEAR_CMD); 
    }
    else if(command=="exit"){
        cout << "See ya  :)... \n" ;      //comando para terminal el programa
            system("pause");            //manda el pause para que no se cierre automaticamente
            exit(0);
    }
    else{
        cout<<"There's no command that matches search.\n";  //if not, send error code.
    }
}

void Clip::ConvertFile() {
    cout<< "PROXIMAMENTE\n";
}
