#include "files.cpp"
#include<iostream>
#include<string>
#include<fstream>

string choice;
int fileChoice;

int main(){

    cout << "//" << endl;
    cin >> choice;

    if(choice == "//"){
        
        cout << "1-writeFile" << endl;
        cout << "2-readFile" << endl;
        
        cin >> fileChoice;
        
        if(fileChoice == 1){
            file();
        
        }else if(fileChoice == 2){
            file_1();
        }
    
    }else{
        system("pause");
    }

       
    return 0;

}