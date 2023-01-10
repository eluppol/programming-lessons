#include <iostream>

using namespace std;

int main()
{
    string phrase; 
    string secondWord;
    cout<<"Please enter a string: ";
    getline(cin, phrase);
    int firstPos = phrase.find(' ', 0);
    int secondPos = phrase.find(' ', firstPos+1);
    if(phrase.find(' ', 0)==-1 && phrase.find('.', 0)==-1 && 
       phrase.find(',', 0)==-1 && phrase.find(':', 0)==-1 && 
       phrase.find(';', 0)==-1 && phrase.find('-', 0)==-1 )
    {
    cout<<"Error! your string has only 1 word"<<endl;
    }
    int numberCharSecWord = secondPos- firstPos;
    secondWord = phrase.substr( firstPos+1, numberCharSecWord);
    cout<<secondWord<<endl;
    
return 0;
}