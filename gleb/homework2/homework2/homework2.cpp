
#include <iostream>
using namespace std;
int main()
{
	string strname;
	cout << "Write name of street";
	cin >> strname;
	char typestr;
	cout << "Write type of street,if (a - avenue, b - boulevard, c - court, d - drive, r - road, s - street, w - way) ";
	cin >> typestr;
	int rooms;
	cout << "Write how many rooms in build";
	cin >> rooms;
	double sqrtm;
	cout << "Write how many sqrt metrs";
	cin >> sqrtm;
	bool conditioner;
	cout << "Have in building conditioner(0-no,1-yes)";
	cin >> conditioner;
	double temperature;
	cout << "Write average temperature of air in July";
	cin >> temperature;
	double hottness;
	hottness = temperature - 25.4;
	if (conditioner == 0)
	{
		sqrtm = sqrtm - hottness;
	}
	double price;
	price = sqrtm * 2845.92;
	if (rooms > 2 and rooms < 6)
	{
		price = price * 1.1;
	}
	string cond;
	string typestreet;
	if (typestr == 'w')
	{

		typestreet = "way";
	}
	if (typestr == 's')
	{

		typestreet = "street";
	}
	if (typestr == 'd')
	{

		typestreet = "drive";
	}
	if (typestr == 'c')
	{
		typestreet = "court";
	}
	if (typestr == 'b')
	{

		typestreet = "boulevard";
	}
	if (conditioner)

	{

		cond = "has";
	}
	else
	{
		cond = "hasn't";
	}
	if (rooms > 5)
	{
		price = price * 1.3;
	}
	if (typestr == 'a')
	{
		price = price / 1.2;
		typestreet = "avenue";
	}
	else {
		if (typestr == 'r')
		{
			price = price / 1.2;
			typestreet = "road";
		}
	}
	cout << "Hi, you live on  " << strname << typestreet << " and have a house with " << rooms << " bedrooms and  " << sqrtm << " square meters. " << endl;
	cout << " Average temperature in July is " << temperature << "." << endl;
	cout << "Your home " << cond << " air conditioning. " << endl;
	cout << " The price of your house is : $" << price << endl;
	return 0;

}
/* «авданн€:
“реба порахувати ≥ вивести ц≥ну дома, використовуючи наступний алгоритм :
1. ѕорахувати жарк≥сть рег≥ону за наступною формулою :
hottness = averageTemperature - 25.4,
де averageTemperature - це середн€ температура в липн≥, €ку вв≥в користувач
2. якщо в будинку нема кондиц≥онера, в≥дн€ти жарк≥сть рег≥ону в≥д к≥лькост≥ квадратних метр≥в ≥ використовувати
результат, €к нову к≥льк≥сть квадратних метр≥в дал≥
3.  ≥льк≥сть квадратних метр≥в помножити на ц≥ну одного квадратного метра(2845.92)
4. якщо к≥льк≥сть к≥мнат б≥льше 2, помножити результат на 1.1, якщо к≥льк≥сть к≥мнат б≥льше 5, то зам≥сть цього помножити на 1.3


Bonus :
	1. якщо будинок розташований на avenue або road, то под≥лити результат на 1.2
	2. якщо назва вулиц≥ починаЇтьс€ з голосноњ л≥тери(a, o, e, i, y, u), то додати до ц≥ни будинку 2048


	¬ивести результат в наступному формат≥ :

Hi, you live on Bougainvilla driveand have a house with 5 bedrooms and 315.42 square meters.
Average temperature in July is 32.
Your home has air conditioning.
The price of your house is : $839245.789
*/
