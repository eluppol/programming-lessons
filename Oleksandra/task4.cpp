#include <iostream>

using namespace std;

int main()
{
    string dayOfWeek[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    int numOfDay;
cout<<"Enter your number (0- Monday, 1- Tuesday, 2- Wednesday, 3- Thursday, 4- Friday, 5- Saturday, 6- Sunday): ";
cin>>numOfDay;
cout<<"Your day is "<<dayOfWeek[numOfDay]<<endl;
return 0;
}