#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
int select, number;
double suma = 0;

struct menuList {
	string name;
	double cost;
};
menuList menu[9];

void getData();
void showMenu();
void saskaita();

int main() {
	cout << "Sveiki atvyke i restorana Dziugelis" << endl << endl;
	getData();
	showMenu();
	return 0;
}
void getData() {
	menu[1].name = "Kiausiniene"; menu[1].cost = 1.45;
	menu[2].name = "Kiaulienos sonine su keptu kiausiniu"; menu[2].cost = 2.45;
	menu[3].name = "Keksiukas su vysnia"; menu[3].cost = 0.99;
	menu[4].name = "Prancuziskas skrebutis"; menu[4].cost = 1.99;
	menu[5].name = "Vaisiu salotos"; menu[5].cost = 2.49;
	menu[6].name = "Pusryciu dribsniai"; menu[6].cost = 0.69;
	menu[7].name = "Kava"; menu[7].cost = 0.50;
	menu[8].name = "Arbata"; menu[8].cost = 0.75;
}

void showMenu() {
	cout << "0 - Paskaiciuoti ir atspausdinti saskaita." << endl;
	for (int i = 1; i <= 8; i++) {
		cout << i << ". " << menu[i].name << " " << menu[i].cost << "eur" << endl;
	}
	cout << "Iveskite numeri, kad uzsisakyti jam atitinkanti patiekala: " << endl;
	cin >> select;
	ofstream fr("rez.txt");
	while (select != 0) {
		if (select == 0) continue;
		else {
			cout << "Iveskite kieki: " << endl;
			cin >> number;
			fr << menu[select].name << " po " << menu[select].cost<<"eur" << " x" << number <<endl<< menu[select].cost * number << "eur" << endl<<endl;
			suma +=(menu[select].cost * number);
			cout << "Iveskite numeri, kad uzsisakyti jam atitinkanti patiekala: " << endl<< "0 - Paskaiciuoti ir atspausdinti saskaita." << endl;
			cin >> select;
		}
	}
	fr << " Mokesciai - " << suma / 100 * 9 << endl;
	fr << "Jusu galutine suma - " << fixed << setprecision(2) << suma + (suma / 100 * 9) <<"eur"<< endl;
	fr.close();
}