
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
/* ��������:
����� ���������� � ������� ���� ����, �������������� ��������� �������� :
1. ���������� ������� ������ �� ��������� �������� :
hottness = averageTemperature - 25.4,
�� averageTemperature - �� ������� ����������� � ����, ��� ��� ����������
2. ���� � ������� ���� ������������, ������ ������� ������ �� ������� ���������� ����� � ���������������
���������, �� ���� ������� ���������� ����� ���
3. ʳ������ ���������� ����� ��������� �� ���� ������ ����������� �����(2845.92)
4. ���� ������� ����� ����� 2, ��������� ��������� �� 1.1, ���� ������� ����� ����� 5, �� ������ ����� ��������� �� 1.3


Bonus :
	1. ���� ������� ������������ �� avenue ��� road, �� ������� ��������� �� 1.2
	2. ���� ����� ������ ���������� � ������� �����(a, o, e, i, y, u), �� ������ �� ���� ������� 2048


	������� ��������� � ���������� ������ :

Hi, you live on Bougainvilla driveand have a house with 5 bedrooms and 315.42 square meters.
Average temperature in July is 32.
Your home has air conditioning.
The price of your house is : $839245.789
*/
