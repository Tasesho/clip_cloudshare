#ifndef CLIP_HPP
#define CLIP_HPP

#include <string>
#include <vector>
#include <map>
#include <functional>

using namespace std;

class Clip {
    private:
        vector<string> advices;  //storage strings for GiveAdvice()
        map<string, string> Commands;  //name, description in Help()
        map<string, void(Clip::*)()> actions;  //name , function to run 
public:
    Clip();  //constructor default
    
    //---------
    //we set the methods in empty, like this we can work in clip.cpp
    void Hello();
    void Help();
    void GiveAdvice();
    void ShowHour();
    void Run();
    void ConvertFile();
    //-------------------

    //set the method executecommand to run it internly, avoid hardcoding

    void ExecuteCommand(const string& command); 

};  

#endif // CLIP_HPP
