#include <iostream>

using namespace std;
int ofind (string name, char space, int g)
{
    int size = name.length();
    for (int i=g; i<size; i++)
    {
       if (name[i]== space)
        {
            return i; 
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
    int firstPos = ofind(name,' ', 0);
     int startWord = firstPos+1;
    int secondPos = ofind(name,' ', startWord);
    int numberCharSecWord = secondPos- startWord;
    secondWord = name.substr( startWord, numberCharSecWord);
    cout<<secondWord<<endl;
    
return 0;
}








