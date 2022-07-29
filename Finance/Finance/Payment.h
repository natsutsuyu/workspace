#pragma once
#include <string>

using namespace std;

//описание класса затрат
class Payment
{
private:
	string name;
	int day;
	int month;
	int year;
	string category;
	int cost;
public:
	Payment();
	Payment(string name, int day, int month, int year, string category, int cost);
	string getName();//геттер дл€ получени€ названи€
	int getDay();//геттер дл€ дн€
	int getMonth();//мес€ца
	int getYear();//года
	string getCategory();//категории
	int getCost();//суммы
	string toString();//идентична функции в заголовочном файле card.h. использована функци€ to_string дл€ преобразовани€ интовых данных
};

