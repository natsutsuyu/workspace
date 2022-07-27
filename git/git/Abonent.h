#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Abonent {
protected:
	char* name;
	char* owner;
	char* tel_number;
	char* adress;
	char* career;
public:
	Abonent(const char _name[], const char _owner[], const char _tel_number[], const char _adress[], const char _career[]) {
		int n_len = strlen(_name) + 1;
		this->name = new char[n_len];
		for (int i = 0; i < n_len; i++) {
			this->name[i] = _name[i];
		}
		this->name[n_len] = '\0';

		int o_len = strlen(_owner) + 1;
		this->owner = new char[o_len];
		for (int i = 0; i < o_len; i++) {
			this->owner[i] = _owner[i];
		}
		this->owner[o_len] = '\0';

		int t_len = strlen(_tel_number) + 1;
		this->tel_number = new char[t_len];
		for (int i = 0; i < t_len; i++) {
			this->tel_number[i] = _tel_number[i];
		}
		this->tel_number[t_len] = '\0';

		int a_len = strlen(_adress) + 1;
		this->adress = new char[a_len];
		for (int i = 0; i < a_len; i++) {
			this->adress[i] = _adress[i];
		}
		this->adress[a_len] = '\0';

		int c_len = strlen(_career) + 1;
		this->career = new char[c_len];
		for (int i = 0; i < c_len; i++) {
			this->career[i] = _career[i];
		}
		this->career[c_len] = '\0';
	}

	Abonent(const Abonent& other) {
		int n_len = strlen(other.name) + 1;
		this->name = new char[n_len];
		for (int i = 0; i < n_len; i++) {
			this->name[i] = other.name[i];
		}
		this->name[n_len] = '\0';

		int o_len = strlen(other.owner) + 1;
		this->owner = new char[o_len];
		for (int i = 0; i < o_len; i++) {
			this->owner[i] = other.owner[i];
		}
		this->owner[o_len] = '\0';

		int t_len = strlen(other.tel_number) + 1;
		this->tel_number = new char[t_len];
		for (int i = 0; i < t_len; i++) {
			this->tel_number[i] = other.tel_number[i];
		}
		this->tel_number[t_len] = '\0';

		int a_len = strlen(other.adress) + 1;
		this->adress = new char[a_len];
		for (int i = 0; i < a_len; i++) {
			this->adress[i] = other.adress[i];
		}
		this->adress[a_len] = '\0';

		int c_len = strlen(other.career) + 1;
		this->career = new char[c_len];
		for (int i = 0; i < c_len; i++) {
			this->career[i] = other.career[i];
		}
		this->career[c_len] = '\0';
	}

	char* getName() { return this->name; }
	char* getOwner() { return this->owner; }
	char* getTel_number() { return this->tel_number; }
	char* getCareer() { return this->career; }

	void print() {
		cout << "Name of company: " << this->name << endl;
		cout << "Owner of company: " << this->owner << endl;
		cout << "Number of company: " << this->tel_number << endl;
		cout << "Adress of company: " << this->adress << endl;
		cout << "Career of company: " << this->career << endl;
		cout << " " << endl;
	}
};
