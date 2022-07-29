#include "Store.h"

//����������� ������ ���������
Store::Store() {
	load();
}

//�������� �� ������
void Store::load() {
    ifstream myfile("Cards.txt");
    if (myfile.is_open())
    {
        string name;
        while (getline(myfile, name))
        {
            string balance;
            string credit;

            getline(myfile, balance);
            getline(myfile, credit);
            Card card(name, stoi(balance), stoi(credit) == 1 ? true : false);
            cards.push_back(card);
        }
        myfile.close();
    }
    else cout << "Unable to open file Shops";
    ifstream myfile2("Payments.txt");
    if (myfile2.is_open())
    {
        string name;
        while (getline(myfile2, name))
        {

            string day;
            string month;
            string year;
            string category;
            string cost;

            getline(myfile2, day);
            getline(myfile2, month);
            getline(myfile2, year);
            getline(myfile2, category);
            getline(myfile2, cost);

            Payment payment(name,stoi(day),stoi(month),stoi(year),category,stoi(cost));
            payments.push_back(payment);

        }
        myfile2.close();
    }
    else cout << "Unable to open file Payments";
}
//������ � �����
void Store::save() {
    ofstream myfile("Cards.txt");
    for (int i = 0; i < cards.size(); i++) {
        if (myfile.is_open())
        {
            myfile << cards.at(i).getName();
            myfile << "\n";
            myfile << cards.at(i).getBalance();
            myfile << "\n";
            myfile << cards.at(i).isCredit() ? 1 : 0;
            myfile << "\n";            
        }
    }
    myfile.close();
    ofstream myfile2("Payments.txt");
    for (int i = 0; i < payments.size(); i++) {
        if (myfile2.is_open())
        {
            myfile2 << payments.at(i).getName();
            myfile2 << "\n";
            myfile2 << payments.at(i).getDay();
            myfile2 << "\n";
            myfile2 << payments.at(i).getMonth();
            myfile2 << "\n";
            myfile2 << payments.at(i).getYear();
            myfile2 << "\n";
            myfile2 << payments.at(i).getCategory();
            myfile2 << "\n";
            myfile2 << payments.at(i).getCost();
            myfile2 << "\n";
        }
    }
    myfile2.close();
}
//���������� ������� �����
void Store::updateBalance(int index, int money) {
    cards.at(index - 1).updateBalance(money);
    save();
}
//��������� ������ ���� ����
vector<Card> Store::getAllCards() {
    system("cls");
    for (int i = 0; i < cards.size(); i++) {
        cout <<"Card number: " << i + 1 << endl;
        cout << cards.at(i).toString() << endl;
        cout << "------------------------" << endl;
    }
	return this->cards;
}
//��������� ������ ���� ��������
vector<Payment> Store::getAllPayments() {
    system("cls");
    for (int i = 0; i < payments.size(); i++) {
        cout << payments.at(i).toString() << endl;
        cout << "------------------------" << endl;
    }
    return this->payments;
}
//���������� ������ �������
bool Store::makePayment(Payment payment, int index) {
    if (payment.getCost() < cards.at(index-1).getBalance()) {
        payments.push_back(payment);
        cards.at(index - 1).updateBalance(-1 * payment.getCost());
        save();
        return true;
    }
    else
    {
        cout << "Card doesnt have money for this pay..." << endl;
        _getch();
        return false;
    }
}
//���������� �����
void Store::addCard(Card card) {
    cards.push_back(card);
    save();
}
//��������� ���� ������� �� ������������ ����
void Store::getAllPaymentsByDay(int day, int month, int year) {
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) {
        if (payments.at(i).getDay() == day && payments.at(i).getMonth() == month && payments.at(i).getYear() == year) {
            cout << payments.at(i).toString() << endl;
            cout << "------------------------" << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "No such payments..." << endl;
    }
}
//��������� ���� ������� �� ������
void Store::getAllPaymentsByWeek(int week, int month, int year) {
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year ) {
            if (week == 1 && payments.at(i).getDay() >= 1 && payments.at(i).getDay() <= 7) {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "------------------------" << endl;
            }
            else if (week == 2 && payments.at(i).getDay() > 7 && payments.at(i).getDay() <= 14) {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "------------------------" << endl;
            }
            else if (week == 3 && payments.at(i).getDay() > 14 && payments.at(i).getDay() <= 21) {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "------------------------" << endl;
            }
            else if (week == 4 && payments.at(i).getDay() > 21 && payments.at(i).getDay() < 31) {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "------------------------" << endl;
            }
        }
    }
    if (!flag) {
        cout << "No such payments..." << endl;
    }
}
//��������� ���� ������� �� ������������ �����
void Store::getAllPaymentsByMonth(int month, int year) {
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year) {
            cout << payments.at(i).toString() << endl;
            cout << "------------------------" << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "No such payments..." << endl;
    }
}
//��������� ���� ������� �� ������������ ���� + ���������
void Store::getAllPaymentsByDayAndCategory(int day, int month, int year, string category) {
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) {
        if (payments.at(i).getDay() == day && payments.at(i).getMonth() == month && payments.at(i).getYear() == year && category.compare(payments.at(i).getCategory())==0) {
            cout << payments.at(i).toString() << endl;
            cout << "------------------------" << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "No such payments..." << endl;
    }
}
//��������� ���� ������� �� ������ + ���������
void Store::getAllPaymentsByWeekAndCategory(int week, int month, int year, string category) {
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year && category.compare(payments.at(i).getCategory()) == 0) {
            if (week == 1 && payments.at(i).getDay() >= 1 && payments.at(i).getDay() <= 7) {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "------------------------" << endl;
            }
            else if (week == 2 && payments.at(i).getDay() > 7 && payments.at(i).getDay() <= 14) {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "------------------------" << endl;
            }
            else if (week == 3 && payments.at(i).getDay() > 14 && payments.at(i).getDay() <= 21) {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "------------------------" << endl;
            }
            else if (week == 4 && payments.at(i).getDay() > 21 && payments.at(i).getDay() < 31) {
                flag = true;
                cout << payments.at(i).toString() << endl;
                cout << "------------------------" << endl;
            }
        }
    }
    if (!flag) {
        cout << "No such payments..." << endl;
    }
}
//��������� ���� ������� �� ����� + ��������
void Store::getAllPaymentsByMonthAndCategory(int month, int year, string category) {
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year && category.compare(payments.at(i).getCategory()) == 0) {
            cout << payments.at(i).toString() << endl;
            cout << "------------------------" << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "No such payments..." << endl;
    }
}
//��� 3 ������� �� ������
void Store::getTop3PaymentByWeek(int week, int month, int year) {
    vector<Payment> sorted;
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year) {
            if (week == 1 && payments.at(i).getDay() >= 1 && payments.at(i).getDay() <= 7) {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 2 && payments.at(i).getDay() > 7 && payments.at(i).getDay() <= 14) {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 3 && payments.at(i).getDay() > 14 && payments.at(i).getDay() <= 21) {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 4 && payments.at(i).getDay() > 21 && payments.at(i).getDay() < 31) {
                flag = true;
                sorted.push_back(payments.at(i));
            }
        }
    }
    if (!flag) {
        cout << "No such payments..." << endl;
    }
    else {
        Payment temp;
        for (int i = 0; i < sorted.size() - 1; i++) {
            for (int j = 0; j < sorted.size() - i - 1; j++) {
                if (sorted.at(j).getCost() < sorted.at(j + 1).getCost()) {
                    temp = sorted.at(j);
                    sorted.at(j) = sorted.at(j + 1);
                    sorted.at(j + 1) = temp;
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) {
            if (i < 3) {
                cout << sorted.at(i).toString() << endl;
                cout << "------------------------" << endl;
            }
        }
    }
}
//��� 3 ������� �� �����
void Store::getTop3PaymentByMonth(int month, int year) {
    vector<Payment> sorted;
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year) {
            flag = true;
            sorted.push_back(payments.at(i));
        }
    }
    if (!flag) {
        cout << "No such payments..." << endl;
    }
    else {
        Payment temp;
        for (int i = 0; i < sorted.size() - 1; i++) {
            for (int j = 0; j < sorted.size() - i - 1; j++) {
                if (sorted.at(j).getCost() < sorted.at(j + 1).getCost()) {
                    temp = sorted.at(j);
                    sorted.at(j) = sorted.at(j + 1);
                    sorted.at(j + 1) = temp;
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) {
            if (i < 3) {
                cout << sorted.at(i).toString() << endl;
                cout << "------------------------" << endl;
            }
        }
    }
}
//��� 3 ��������� �� ������
void Store::getTop3CategoryByWeek(int week, int month, int year) {
    map<string, int> result;
    vector<Payment> sorted;
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year) {
            if (week == 1 && payments.at(i).getDay() >= 1 && payments.at(i).getDay() <= 7) {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 2 && payments.at(i).getDay() > 7 && payments.at(i).getDay() <= 14) {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 3 && payments.at(i).getDay() > 14 && payments.at(i).getDay() <= 21) {
                flag = true;
                sorted.push_back(payments.at(i));
            }
            else if (week == 4 && payments.at(i).getDay() > 21 && payments.at(i).getDay() < 31) {
                flag = true;
                sorted.push_back(payments.at(i));
            }
        }
    }
    if (!flag) {
        cout << "No such payments..." << endl;
    }
    else {
        for (int i = 0; i < sorted.size(); i++) {
            if (result.count(sorted.at(i).getCategory())) {
                int value = result.find(sorted.at(i).getCategory())->second;
                result.find(sorted.at(i).getCategory())->second += sorted.at(i).getCost();
            }
            else {
                result.insert({ sorted.at(i).getCategory(),sorted.at(i).getCost() });
            }
        }
        // create an empty vector of pairs
        vector<pair<string, int>> vec;


        std::copy(result.begin(),
            result.end(),
            back_inserter<std::vector<pair<string, int>>>(vec));


        std::sort(vec.begin(), vec.end(),
            [](const pair<string, int>& l, const pair<string, int>& r)
            {
                if (l.second != r.second) {
                    return l.second > r.second;
                }

                return l.first > r.first;
            });

        int count = 0;
        for (auto const& pair : vec) {
            if (count < 3) {
                cout << '{' << pair.first << "," << pair.second << '}' << endl;
                count++;
            }
        }

    }
}
//��� 3 ��������� �� �����
void Store::getTop3CategoryByMonth(int month, int year) {
    map<string, int> result;
    
    vector<Payment> sorted;
    system("cls");
    bool flag = false;
    for (int i = 0; i < payments.size(); i++) {
        if (payments.at(i).getMonth() == month && payments.at(i).getYear() == year) {
            flag = true;
            sorted.push_back(payments.at(i));
        }
    }
    if (!flag) {
        cout << "No such payments..." << endl;
    }
    else {
        for (int i = 0; i < sorted.size(); i++) {
            if (result.count(sorted.at(i).getCategory())) {
                int value = result.find(sorted.at(i).getCategory())->second;
                result.find(sorted.at(i).getCategory())->second += sorted.at(i).getCost();
            }
            else {
                result.insert({ sorted.at(i).getCategory(),sorted.at(i).getCost() });
            }
        }
        // create an empty vector of pairs
        vector<pair<string,int>> vec;

        
        std::copy(result.begin(),
            result.end(),
            back_inserter<std::vector<pair<string, int>>>(vec));

        
        std::sort(vec.begin(), vec.end(),
            [](const pair<string, int>& l, const pair<string, int>& r)
            {
                if (l.second != r.second) {
                    return l.second > r.second;
                }

                return l.first > r.first;
            });

        
        int count = 0;
        for (auto const& pair : vec) {
            if (count < 3) {
                cout << '{' << pair.first << "," << pair.second << '}' << endl;
                count++;
            }
        }  
    }
}