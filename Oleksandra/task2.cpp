#include <iostream>

using namespace std;

int main()
{
    string nameStreet; 
    char typeStreet;
    int numberRooms;
    double numberSquareMeters;
    bool airConditining;
    int averageTemperature;
    double hottness;
    double priceHouse;
    cout<<"Enter street name ";
    cin>>nameStreet;
    cout<<"Enter the letter that corresponds to the type of street ";
    cin>>typeStreet;
    cout<<"Enter number of rooms ";
    cin>>numberRooms;
    cout<<"Enter number of square meters ";
    cin>>numberSquareMeters;
    cout<<"The house has an air conditioner ";
    cin>>airConditining;
    cout<<"Enter average temperature in July ";
    cin>>averageTemperature;
    hottness = averageTemperature - 25.4 ;
    
    if (!airConditining)
    {
       numberSquareMeters = numberSquareMeters - hottness;
    }
    priceHouse = numberSquareMeters * 2845.92 ;
    if (numberRooms>2 && numberRooms<5)
    {
        priceHouse = priceHouse * 1.1;
    }
     if (numberRooms>=5)
    {
        priceHouse = priceHouse * 1.3;
    }
    if (typeStreet == 'a' || typeStreet == 'r')
    {
        priceHouse = priceHouse / 1.2;
    }
if (nameStreet[0]=='a'||nameStreet[0]=='o'||nameStreet[0]=='e'||nameStreet[0]=='i'||nameStreet[0]=='y'||nameStreet[0]=='u')
{
    priceHouse = priceHouse + 2048;
}
string fullTypeStreet;
    if (typeStreet == 'a')
    {
        fullTypeStreet = "avenue";
    }
      if (typeStreet == 'b')
    {
        fullTypeStreet = "boulevard";
    }
      if (typeStreet == 'c')
    {
        fullTypeStreet = "court";
    }
      if (typeStreet == 'd')
    {
       fullTypeStreet = " drive";
    }
      if (typeStreet == 'r')
    {
        fullTypeStreet = " road";
    }
      if (typeStreet == 's')
    {
       fullTypeStreet=" street";
    }
      if (typeStreet == 'w')
    {
       fullTypeStreet =" way";
    }
    cout<<"Hi, you live in "<< nameStreet<<fullTypeStreet<<endl;
    cout<<"and have a house with "<< numberRooms <<" bedrooms and "<<numberSquareMeters<< " square meters."<<endl;
    cout<<"Average temperature in July is "<< averageTemperature<<endl;
    if (!airConditining)
    {
        cout<<"Your home has not air conditioning. "<<endl;
    }
    else
    {
        cout<<"Your home has air conditioning. "<<endl;
    }
    cout<<"The price of your house is $" << priceHouse<<endl;
return 0;
}

