#pragma once
#include <string>

using namespace std;
//описание класса карт и кошельков
class Card
{
private:
	string name;
	int balance;
	bool iscredit;
public:
	Card(string name, int balance, bool isCredit);.//конструктор по умолчанию
	void updateBalance(int balance);//сеттер для изменения балланса
	string getName();//геттер для получения имени
	int getBalance();//геттер для полуание балланса
	bool isCredit();//геттер для получение инфы о карте
	string toString();//функция std::to_string(), которая позволяет преобразовать передаваемое значение в строку. пришлось преобразовать балланс для возвращения в виде строки.
};

