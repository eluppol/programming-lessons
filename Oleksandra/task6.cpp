#include <iostream>

using namespace std;
int ofind_first_of (string name, string chars, int g)
{
    int sizeN = name.length();
    int sizeC = chars.length();
    int i;
    int j;
    for (i = g; i<sizeN; i++)
    {
        for ( j=0; j<sizeC; j++)
        {
            if(name[i]==chars[j])
            { 
            return i;
            }
        
            
        }
        
    }
    return -1;
}
int main()
{
    string name; 
    string secondWord;
    cout<<"Please enter a string: ";
    getline(cin, name);
    int firstPos = name.find_first_not_of(" ,.;:-", 0);
    int secondPos = ofind_first_of(name, " ,.;:-", firstPos);
    int startWord = name.find_first_not_of(" ,.;:-", secondPos); 
    int endWord = ofind_first_of(name, " ,.;:-", startWord); 
    if(name.find_first_not_of(" ,.;:-", secondPos) ==-1) 
    {
    cout<<"Error! your string has only 1 word"<<endl;
    return 0;
    }
    int numberCharSecWord = endWord- startWord; 
    secondWord = name.substr( startWord, numberCharSecWord);
    cout<<secondWord<<endl;
    
return 0;
}

