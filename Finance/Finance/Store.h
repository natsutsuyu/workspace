#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Card.h"
#include "Payment.h"
#include <conio.h>
#include <map>
#include <algorithm>

//описание класса хранилища данных
class Store
{
private:
	vector<Card> cards;
	vector<Payment> payments;
public:
	Store();
	
	void load();//загрузка из байлов
	void save();//сохранение в файлах
	
	vector<Card> getAllCards();//геттер дл€ получени€ информации по картам
	vector<Payment> getAllPayments();//геттер дл€ получени€ информации по затратам
	
	void addCard(Card card);//добавление карты
	void updateBalance(int index, int money);//изменение балланса

	bool makePayment(Payment payment, int index);//добавление затрат
	
	//методы дл€ отчетов по дню, неделе, мес€цу и категори€м
	void getAllPaymentsByDay(int day, int month,int year);
	void getAllPaymentsByWeek(int week, int month, int year);
	void getAllPaymentsByMonth(int month, int year);
	void getAllPaymentsByDayAndCategory(int day, int month, int year, string category);
	void getAllPaymentsByWeekAndCategory(int week, int month, int year, string category);
	void getAllPaymentsByMonthAndCategory(int month, int year, string category);
	//методы дл€ реализации топа 3 затрат и категорий 
	void getTop3PaymentByWeek(int week, int month, int year);
	void getTop3PaymentByMonth(int month, int year);
	void getTop3CategoryByWeek(int week, int month, int year);
	void getTop3CategoryByMonth(int month, int year);

};

