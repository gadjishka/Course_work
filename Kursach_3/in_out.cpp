#include "Header.h"
#include "tabler.h"
#include <string.h>
#include <iomanip>
#include <algorithm>

int N = 0; //Количество предприятий в городе
int M = 0; //Количество продуктов каждого из предприятий
int companies = 0; //Количество компаний, данные которых на данный момент заполнены
char** companyNames;//Массив для хранения названий предприятий
char** productNames; //Массив для хранениия названий продуктов
char* filledCompanies; //Массив для хранений записей о том, данные какой компании были заполнены


void writeNzap(fstream& p) // записать данные в файл
{
	p.clear(); //очистка потока
	p.seekg(0, ios::end); //запись в конец
	if (N == 0 && M == 0) { //Начало программы, если еще не заданы количества компаний и их продукции, то они вводятся
		cout << "\nEnter number of companies: "; cin >> N; //Вводим количество компаний
		companyNames = new char* [N];
		for (int i = 0; i < N; i++) companyNames[i] = new char[20]; //Выделяем память под наш массив
		for (int i = 0; i < N; i++) { //В цикле заполняем массив с названиями компаний
			cout << "Enter " << i + 1 << " name of company: ";
			cin >> companyNames[i];
		}
		cout << "\nEnter number of products: "; cin >> M; //Вводим количество продуктов
		productNames = new char* [M];
		for (int i = 0; i < M; i++) productNames[i] = new char[20]; //Выделяем память под наш массив
		for (int i = 0; i < M; i++) { //В цикле заполняем массив с названиями продуктов
			cout << "Enter " << i + 1 << " name of product: ";
			cin >> productNames[i];
		}

		filledCompanies = new char[N]; //Выделяем память под наш массив
		for (int i = 0; i < N; i++) filledCompanies[i] = '+'; //Заполняем массив знаком "+", так как еще ни одна компания не заполнена


	}
	if (companies < N) { //Если количество заполненных компаний меньше общего количества компаний, то записываем
		int rec;
		cout << "\n\nEnter number of records: "; //Запрашиваем у пользователя количество записей
		cin >> rec;
		for (int i = 0; i < rec && companies < N; i++, companies++) {
			INFO zap;
			zap = vvod();
			write(p, zap);
		}
	}
	else cout << "\n\nCompanies run out"; //В противном случае выводим сообщение, что незаполненных компаний больше нет
}
void write(fstream& p, INFO zap, int num)
{
	p.clear(); //очистка потока
	if (num)
		p.seekg((num - 1) * len, ios::beg);
	p.write((char*)&zap, len);
}
INFO vvod()
{
	INFO zap;
	cout << "\nChoose company to fill data:";
	for (int i = 0; i < N; i++) { //Выводим пользователю список всех компаний, указывая на те, данные которых уже заполнены, чтобы пользователь выбрал, какую хочет заполнить
		cout << endl << i + 1 << ". " << companyNames[i];
		if (filledCompanies[i] == '-') cout << "  || Fiiled Data!!"; //Если компания заполнена, рядом с ее названием выводится соответствующая надпись
	}
	int choosen;
	cout << "\nChoice: "; cin >> choosen;
	while (choosen > N || filledCompanies[choosen-1] == '-') { 		//Цикл идет до тех пор, пока пользователь выберет номер компании, которая представлена в списке выше и не является заполненной
		cout << "\nIncorrect choice, choose another number!";
		cout << "\nChoice: "; cin >> choosen;
	}
	filledCompanies[choosen-1] = '-'; //Записываем в массив, что данные компании заполнены
	strcpy_s(zap.companyName, companyNames[choosen - 1]);
	cout << "\nCompany name: " << zap.companyName;
	for (int i = 0; i < M; i++) { //Заполняем остальные данные: количество продукта и его цену
		cout << "\nProduct name:\t" << productNames[i];
		strcpy_s(zap.productName[i], productNames[i]);
		cout << "\nEnter the volume of output:\t";
		cin >> zap.volume[i];
		cout << "Enter unit cost:\t";
		cin >> zap.unitCost[i];
	}
	strcpy_s(zap.metka, "+");
	
	return zap;
}
fstream& read(fstream& p, INFO& zap, int num)
{
	p.clear(); //очистка потока
	if (num) //позиционирование
		p.seekg((num - 1) * len, ios::beg);
	p.read((char*)&zap, len);
	return p;
}

int countProducts(int array[]) { //Подсчитывает количество наимененований товара
	int ans = 0;
	for (int i = 0; i < 20; i++) {
		if (array[i] != 0) ans++;
		else break;
	}
	return ans;
}

void print(INFO zap)
{
	bool f;
	if (zap.companyName[0] != 0) {
		f = true;
		cout << endl << setw(10) << zap.companyName << setw(2) << ' ';
		for (int i = 0; i < countProducts(zap.volume); i++)
		{
			cout << setw(15) << right << zap.productName[i] << setw(2) << ' ';
			cout << setw(9) << right << zap.volume[i] << setw(2) << ' '
				<< setw(10) << right << zap.unitCost[i] << setw(2) << ' ';
			cout << setw(7) << right << zap.metka;
			cout << "\n" << setw(12) << " ";
		}
	}
}
void readAll(fstream& p)
{
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap; // куда читать
	cout << shapka;
	while (read(p, zap))
		print(zap);
	cout << endl << FinishL;
}
void readN(fstream& p, int N)
{
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap; // куда читать
	if (read(p, zap, N))
	{
		cout << shapka;
		print(zap);
		cout << endl << FinishL;
	}
	else
		cout << endl << "There is no such record";
	_getch();
}
void UNmetkaDel(fstream& p/*, char* metka*/)
{
	p.clear();
	INFO zap;
	p.seekp(0, ios::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "-") == 0)
		{
			strcpy_s(zap.metka, "+");
			write(p, zap, i);
		}
	}
	_getch();
}
int metkaDel(fstream& p, char* name/*, char* metka*/)
{
	p.clear();
	INFO zap;
	p.seekp(0, ios::beg);
	int kol = 0;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.companyName, name) == 0)
		{
			strcpy_s(zap.metka, "-");
			write(p, zap, i);
			kol++;
		}
	}
	return kol;
}
int Delete(fstream& p)
{
	fstream p1("temp.txt", ios::app);
	p.clear();
	INFO zap;
	p.seekp(0, ios::beg);
	int kol = 0;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "+") == 0)
		{
			write(p1, zap);
			kol++;
		}
	}
	p.close();
	p1.close();
	remove(fname);
	rename("temp.txt", fname);
	p.open(fname, ios::in | ios::out | ios::ate);
	return kol;
}

int countCompanies(fstream& p, int& m) { //Подсчитывает количество предприятий для функции Statistics
	INFO zap;
	int count = 0;
	p.clear();
	p.seekg(0, ios::beg);
	while (read(p, zap)) {
		m = countProducts(zap.volume);
		count++;
	}
	return count;
}

void fillAnswer(fstream& p, int ans[][20], int n, int m) { //Заполняет матрицу, каждая из ячеек которой содержит количество товара умноженное на стоимость товара для каждого товара каждого предприятия
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap;
	for (int i = 0; i < n && read(p, zap); i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = zap.unitCost[j] * zap.volume[j];
		}
	}
}

void fillNames(fstream& p, string com[], string prod[], int m) { //Заполняет массив названиями предприятий и массив названиями товаров 
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap;
	for (int i = 0; read(p, zap); i++) {
		com[i] = string(zap.companyName);
		for (int j = 0; j < m; j++) {
			prod[j] = string(zap.productName[j]);
		}
	}
}

void Statistics(fstream& p){ //Решает задачу курсовой работы
	int answer[20][20]; //Массив под хранения произведения количества продукта на его стоимость для каждой компании для выполнения задания курсовой
	int m ,n = countCompanies(p, m); //n отвечает за количество предприятий, m за количество товаров у каждого предприятия
	fillAnswer(p, answer, n, m);
	string companyNamesForStatistics[20]; //Массив строк с названиями предприятий
	string productNamesForStatistics[20]; //Массив строк с названиями продуктов
	fillNames(p, companyNamesForStatistics, productNamesForStatistics, m);
	double sum = 0, max_S = 0; //Переменные для подсчета общей суммы товара всех компаний и максимальной суммы из всех компаний за отдельно взятый товар
	int tmp = 0; //Отвечает за индекс компании с максимальной долей отдельной продукции
	for (int i = 0; i < m; i++) {
		max_S = 0;
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += answer[j][i];
			if (answer[j][i] > max_S) {
				max_S = answer[j][i];
				tmp = j;
			}
		}
		cout << "\n\nThe largest share of the product:\t" << productNamesForStatistics[i];
		cout << "\nCompany:\t" << companyNamesForStatistics[tmp];
		cout << "\nPercentage share:\t" << max_S / sum * 100 << "%";
	}

}

int DeleteAll(fstream& p) { //Очищает файл для занесения новых данных
	fstream p1("temp.txt", ios::app);
	p.clear();
	p.seekp(0, ios::beg);
	p.close();
	p1.close();
	remove(fname);
	rename("temp.txt", fname);
	p.open(fname, ios::in | ios::out | ios::ate);
	companies = 0;
	return 0;
}

