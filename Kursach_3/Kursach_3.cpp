#include "Header.h"
#include <iostream>
using namespace std;

int len = sizeof(INFO);
char fname[20] = "file1.bin";

char menu() {
	cout << "\n\n\t1-> Add a note"
		<< "\n\t2-> Reading all records"
		<< "\n\t3-> Reading record with N number"
		<< "\n\t4-> Mark for deletion"
		<< "\n\t5-> Unmark for deletion"
		<< "\n\t6-> Delete selected entry"
		<< "\n\t7-> Statistics"
		<< "\n\t8-> Delete all"
		<< "\n\t0-> EXIT\n";
	char s;
	cin >> s;
	return s;
}

int main() {
	fstream p(fname, ios::app);
	if (p) {
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
	}

	do
	{
		char s = menu();
		switch (s)
		{
		case '1':
			writeNzap(p);
			break;
		case '2':
			readAll(p);
			break;
		case '3':
			int nom;
			cout << "\nEnter entry number: ";
			cin >> nom;
			readN(p, nom);
			_getch();
			break;
		case '4':
			int a;
			char name[10];
			cout << "\n\tEnter company name: ";
			cin >> name;
			a = metkaDel(p, name);
			break;
		case '5':
			UNmetkaDel(p);
			system("cls");
			break;
		case '6':
			Delete(p);
			cout << ("\n\tDone!");
			break;
		case '7':
			Statistics(p);
			break;
		case '8':
			DeleteAll(p);
			cout << ("\n\tDone!");
			break;
		case '0':
			p.close();
			exit(0);
		}
	} while (1);
	p.close();
	return 0;
}
