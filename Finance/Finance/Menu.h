#pragma once

#include <iostream>
#include"Store.h"
using namespace std;

//отписание класса меню
class Menu
{
private:
	Store store;
	void main();
	void cards();
	void payments();
public:
	Menu();
};

