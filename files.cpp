#include "ciphers.cpp"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int fileMax = 0;

bool check = false;

int read(){

    string text;
    ifstream read("count.txt");
    string ans;
    
    int a = -1;
    int counter = 0;
    
    while(getline(read, text)){
        a = std::stoi(text);    
        counter ++;
    }

    if(counter > 0){
        return a;
    
    }else{
        cout<<"h8i";
        check = true;
        return 0;
    }

   
}
void file(){

    int loopMax;
    
    string input;
    ofstream count;
    
    if(check == true){
        count.open("count.txt");
        count << 0 << endl;
        count.close();
    }
    
    loopMax = read();
    cout << "Enter Password to be stored:"<<endl;
    cout << loopMax;

    for(int i = 0;i < loopMax + 2;i ++){
        if(i > loopMax){
            ofstream file;
            file.open (std::to_string(i) + ".txt");
            cin.ingore();
            getline(cin, input);
            input = caesarscipher(input, 7);
            file << input << endl;
            file.close();
            fileMax = loopMax;
            fileMax ++;
            i = fileMax + 2;
        }
    }

    count.open("count.txt");
    count << fileMax;
    count.close();
}

void file_1(){

    string text;
    
    int fileNums;
    fileNums = read();

   for(int i = 0;i <= fileNums;i ++){
        ifstream fileRead(std::to_string(i) + ".txt");
        while(getline(fileRead, text)){
            text = caesarsDecipher(text, 7);
            cout << text << endl;
        }
         
    }
   
}

