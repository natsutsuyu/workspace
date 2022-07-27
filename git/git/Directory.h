#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "Abonent.h"

using namespace std;

class Directory {
private:
	vector<Abonent> home_numb;
	vector<Abonent> mobile_numb;
	vector<Abonent> state_numb;
public:
	Directory(Abonent& _abonents, int numb) {
		if (numb == 1) {
			home_numb.push_back(_abonents);
			writeToFile(_abonents);
		}
		else if (numb == 2) {
			mobile_numb.push_back(_abonents);
			writeToFile(_abonents);
		}
		else if (numb == 3) {
			state_numb.push_back(_abonents);
			writeToFile(_abonents);
		}
	}



	void setAbonent(Abonent& _abonents, int numb) {
		if (numb == 1) {
			home_numb.push_back(_abonents);
			writeToFile(_abonents);
		}
		else if (numb == 2) {
			mobile_numb.push_back(_abonents);
			writeToFile(_abonents);
		}
		else if (numb == 3) {
			state_numb.push_back(_abonents);
			writeToFile(_abonents);
		}
	}

	Abonent findByName(const char find[], int numb) {
		if (numb == 1) {
			for (vector<Abonent>::iterator index = home_numb.begin(); index != home_numb.end(); index++) {
				if (strcmp(index->getName(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
		else if (numb == 2) {
			for (vector<Abonent>::iterator index = mobile_numb.begin(); index != mobile_numb.end(); index++) {
				if (strcmp(index->getName(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
		else if (numb == 3) {
			for (vector<Abonent>::iterator index = state_numb.begin(); index != state_numb.end(); index++) {
				if (strcmp(index->getName(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
	}

	Abonent findByOwner(const char find[], int numb) {
		if (numb == 1) {
			for (vector<Abonent>::iterator index = home_numb.begin(); index != home_numb.end(); index++) {
				if (strcmp(index->getOwner(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
		else if (numb == 2) {
			for (vector<Abonent>::iterator index = mobile_numb.begin(); index != mobile_numb.end(); index++) {
				if (strcmp(index->getOwner(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
		else if (numb == 3) {
			for (vector<Abonent>::iterator index = state_numb.begin(); index != state_numb.end(); index++) {
				if (strcmp(index->getOwner(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
	}

	Abonent findByTel_Number(const char find[], int numb) {
		if (numb == 1) {
			for (vector<Abonent>::iterator index = home_numb.begin(); index != home_numb.end(); index++) {
				if (strcmp(index->getTel_number(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
		else if (numb == 2) {
			for (vector<Abonent>::iterator index = mobile_numb.begin(); index != mobile_numb.end(); index++) {
				if (strcmp(index->getTel_number(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
		else if (numb == 3) {
			for (vector<Abonent>::iterator index = state_numb.begin(); index != state_numb.end(); index++) {
				if (strcmp(index->getTel_number(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
	}

	Abonent findByCareer(const char find[], int numb) {
		if (numb == 1) {
			for (vector<Abonent>::iterator index = home_numb.begin(); index != home_numb.end(); index++) {
				if (strcmp(index->getCareer(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
		else if (numb == 2) {
			for (vector<Abonent>::iterator index = mobile_numb.begin(); index != mobile_numb.end(); index++) {
				if (strcmp(index->getCareer(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
		else if (numb == 3) {
			for (vector<Abonent>::iterator index = state_numb.begin(); index != state_numb.end(); index++) {
				if (strcmp(index->getCareer(), find) == 0) {
					Abonent tmp(*index);
					return tmp;
				}
			}
		}
	}

	void writeToFile(Abonent& _abonents) {
		ofstream dir_file;
		dir_file.open("dir_file.txt", ofstream::app);

		if (!dir_file.is_open()) {
			cout << "Îøèáêà çàïèñè äàííûõ â ôàéë." << endl;
		}
		else {
			dir_file.write((char*)&_abonents, sizeof(Abonent));
		}
		dir_file.close();
	}

	void printAll() {
		for (vector<Abonent>::iterator index = home_numb.begin(); index != home_numb.end(); index++) {
			Abonent tmp(*index);
			tmp.print();
		}
		for (vector<Abonent>::iterator index = mobile_numb.begin(); index != home_numb.end(); index++) {
			Abonent tmp(*index);
			tmp.print();
		}
		for (vector<Abonent>::iterator index = state_numb.begin(); index != home_numb.end(); index++) {
			Abonent tmp(*index);
			tmp.print();
		}
	}
};