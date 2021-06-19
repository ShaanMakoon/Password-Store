
#include<iostream>
#include<string>

using namespace std;
//string to store alphabet
const string alpha = "abcdefghijklmnopqrstuvwxyz";

//int to store alphabet length
const int length = 25;

//function to break sentence into individual words
string sentenceBreaker(string words){

    //alphabet
    const string alpha = "abcdefghijklmnopqrstuvwxyz";

    //recieved as input
    
    //used for splitting words
    char space = '-';

    //counter
    int counter = 0;
    
    for(int i = 0;i < words.length();i ++){
        counter = 0;
        for(int j = 0;j < alpha.length();j ++){
        //if the current letter is recognised in alphabet
            if(words[i] == alpha[j]){
                //add to counter
                counter ++;
            //if we are at final point of for loop and counter is less
            //than 1, we are inbetween 2 words, so put a dash    
            }if(j == alpha.length() - 1 && counter < 1){
                //current empty character is now == to dash
                words[i] = space;
            }
        }
    }
   
    //printout new paragraph with dashes between each word
    return words;

}


//encrypts text in caesars cipher
string caesarscipher(string word, int offset){
    
    //offset is the number of which we shift the letter up the alphabet

    //keeps track of current letter of word we are ciphering
    char let;
    char currentLetter;
    char sp = '-';

    string capAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   
    string space = "--";
    string Bword;

    //index counter for let variable
    int counter = 0;
    int num;
    int numb;

    //bword is the sentence broken down into individual words
    Bword = sentenceBreaker(word);
  
   //for loop running for length of word
    for(int i = 0;i < Bword.length();i ++){
        
        //current letter we are changing goes here
        let = Bword[counter];
        
        //if current index is a dash(-)
        if(Bword[counter] == sp){
            counter ++;
        }
  
        //for loop running for length of alphabet
        for(int a = 0;a < length + 1;a ++){
             
            if(let == capAlpha[a]){
                tolower(let);
            }
            
            //if current letter is == to index in alphabet
            if(let == alpha[a]){
                
                //if the offset + current letter of alphabet goes over 26 
                if(a + offset >= 26){
                    //num is the current index of alphabet + the offset
                    num = (a + offset);
                    
                    //numb is (a + offset) - 26, to find the difference
                    numb = num - 26;

                    //reset loop so doesnt go over for loop for alphabet
                    a = 0;
                    //cout << "let" << let << endl;
                    //current letter is = index + numb
                    Bword[counter] = alpha[a + numb];
                    //cout <<"bword" << Bword[counter] << endl;
                    //end for loop
                    a = length;
                
                }else{
                    
                    //cout << "let-" << let << endl;
                    //word index = itself + offset
                    Bword[counter] = alpha[a + offset];
                    //cout <<"bword-" << a + offset << endl;
                }
                
                //counter for letter goes up
                counter ++;
            }
       
        }
    
    }
  
  //return cipherd word
   return Bword;

}


//dencrypts text in caesars cipher
string caesarsDecipher(string word, int offset){
 
    //keeps track of current letter of word we are ciphering
    char let;

    char sp = '-';

    //index counter for let variable
    int counter = 0;

    int num;
    int numb;

    string Bword;
    string capAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    Bword = sentenceBreaker(word);

   //for loop running for length of word
    for(int i = 0;i < word.length();i ++){
        //current letter we are changing goes here
        let = Bword[counter];
        
        //if current index is a dash(-)
        if(Bword[i] == sp){
            counter ++;
        }
       
        //for loop running for length of alphabet
        for(int a = 0;a < length + 1;a ++){
            
            if(let == capAlpha[a]){
                tolower(let);
            }
            //if current letter is == to index in alphabet
            
            if(let == alpha[a]){
                
                if(a - offset < 0){
                    
                    //num is == index of alphabet - offset
                    num = offset - a;
                    //numb is that (a - offset) + 0
                   // numb = num - a;
                    //cout << num << a << endl;
                    
                    //puts for loop at the end
                    a = length + 1;

                    word[counter] = alpha[a - num];

                 
                }else{
                  
                    //word index = itself + offset
                    word[counter] = alpha[a - offset];
                }
               
                //counter for letter goes up
                counter ++;
            }
        
        }
    
    }

    //print out new word
    return word;

}

