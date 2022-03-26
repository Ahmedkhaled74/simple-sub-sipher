#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    string alphabet="abcdefghijklmnopqrstuvwxyz";

    reverse(alphabet.begin(), alphabet.end());       // reverse the alphabet to be from z to a.
    string text ;
    string key ;
    int ctr;
    int press ;
    cout<<"Please enter a text you want: " ;
    getline(cin,text) ;

    transform(text.begin(), text.end(), text.begin(), ::tolower);    // the text is always in lower case when the user input it.

    cout<<"Please enter a key of 5 unique letters: ";

    cin>>key ;
    transform(key.begin(), key.end(), key.begin(), ::tolower);  // the key always turns  to lower case when the user input it.


    while((key.length()>5)||(key.length()<5)){                     // check while the key contains less than five letters or more five letters.
                                                                    // print wrong key if it is true and break the loop if it is false.
          cout<<"Wrong key, Please enter a key of 5 letters: ";
          cin>>key ;

          if(key.length()==5){
             break;
         }
    }
    for(int i=0;i<key.length()-1;i++){                              // check if the key has repeated characte
        for(int j=i+1;j<key.length();j++){                          // print wrong key if it is true and break the loop if it is false.
            while (key[i] == key[j]){
                cout<<"Wrong key, Please enter a key of 5 unique letters: ";
                 cin>>key ;
                 ctr=0;
                 if(ctr!=0){
                    break ;
                 }
            }
        }
    }

     cout<<"press 1 to cipher"<<"\n"<<"press 2 to decipher "<<"\n"<<"press 3 to exit"<<"\n";
     cin>>press ;

if(press==1){                                      // if the user has entered "1"

     for (int i=0 ; i<alphabet.length();i++){
        for(int j=0; j<key.length();j++){
            if(key[j]==alphabet[i]){                 // check if each character in the key is equal to another in the alphabet
                 alphabet.erase(remove(alphabet.begin(), alphabet.end(), key[j]), alphabet.end()); // remove the characters of the key from the alphabet.
            }
        }
    }
    for (int i=key.length() ; i<=key.length();i-- ){
        alphabet.push_back(key[i]) ;                      // add each character of the key from the end to the alphabet

    }
     reverse(alphabet.begin(), alphabet.end());

     for(int j=key.length()+1; j>key.length();j++){
        alphabet.erase(remove(alphabet.begin(), alphabet.end(), key[j]), alphabet.end());   // remove a space in the alphabet.
        break ;
     }



        for(int m=0; m<text.length();m++){
                text[m]=alphabet[int(text[m]-97)] ;       //each character with its index of text now will equal to each one in alphabet
                                                            // with its index too.

        }

        cout<<text<<"\n" ;


}
else if (press==2){              // if user entered '2'
           for (int i=0 ; i<alphabet.length();i++){
        for(int j=0; j<key.length();j++){
            if(key[j]==alphabet[i]){
                 alphabet.erase(remove(alphabet.begin(), alphabet.end(), key[j]), alphabet.end());
            }
        }
    }
    for (int i=key.length() ; i<=key.length();i-- ){
        alphabet.push_back(key[i]) ;

    }
     reverse(alphabet.begin(), alphabet.end());
     for(int j=key.length()+1; j>key.length();j++){
        alphabet.erase(remove(alphabet.begin(), alphabet.end(), key[j]), alphabet.end());
        break ;
     }




         for (int m=0 ; m<text.length();m++){

            text[m]=char(alphabet.find(text[m])+97) ;


         }


         cout<<text<<"\n" ;
}




else{
    cout<<"you have ended the program." ;
}







    return 0;
}
