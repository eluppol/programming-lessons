#include <iostream>

using namespace std;

int main()
{
    string phrase; 
    string secondWord;
    cout<<"Please enter a string: ";
    getline(cin, phrase);
    int firstPos = phrase.find_first_of(" ,.;:-", 0);
    int secondPos = phrase.find_first_not_of(" ,.;:-", firstPos);
    int threePos = phrase.find_first_of(" ,.;:-", secondPos);
    if(phrase.find_first_not_of(" ,.;:-", firstPos)==-1)
    {
    cout<<"Error! your string has only 1 word"<<endl;
    return 0;
    }
    int numberCharSecWord = threePos- secondPos;
    secondWord = phrase.substr( secondPos, numberCharSecWord);
    cout<<secondWord<<endl;
    
return 0;
}

