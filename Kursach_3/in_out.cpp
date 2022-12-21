#include "Header.h"
#include "tabler.h"
#include <string.h>
#include <iomanip>
#include <algorithm>

int N = 0; //���������� ����������� � ������
int M = 0; //���������� ��������� ������� �� �����������
int companies = 0; //���������� ��������, ������ ������� �� ������ ������ ���������
char** companyNames;//������ ��� �������� �������� �����������
char** productNames; //������ ��� ��������� �������� ���������
char* filledCompanies; //������ ��� �������� ������� � ���, ������ ����� �������� ���� ���������


void writeNzap(fstream& p) // �������� ������ � ����
{
	p.clear(); //������� ������
	p.seekg(0, ios::end); //������ � �����
	if (N == 0 && M == 0) { //������ ���������, ���� ��� �� ������ ���������� �������� � �� ���������, �� ��� ��������
		cout << "\nEnter number of companies: "; cin >> N; //������ ���������� ��������
		companyNames = new char* [N];
		for (int i = 0; i < N; i++) companyNames[i] = new char[20]; //�������� ������ ��� ��� ������
		for (int i = 0; i < N; i++) { //� ����� ��������� ������ � ���������� ��������
			cout << "Enter " << i + 1 << " name of company: ";
			cin >> companyNames[i];
		}
		cout << "\nEnter number of products: "; cin >> M; //������ ���������� ���������
		productNames = new char* [M];
		for (int i = 0; i < M; i++) productNames[i] = new char[20]; //�������� ������ ��� ��� ������
		for (int i = 0; i < M; i++) { //� ����� ��������� ������ � ���������� ���������
			cout << "Enter " << i + 1 << " name of product: ";
			cin >> productNames[i];
		}

		filledCompanies = new char[N]; //�������� ������ ��� ��� ������
		for (int i = 0; i < N; i++) filledCompanies[i] = '+'; //��������� ������ ������ "+", ��� ��� ��� �� ���� �������� �� ���������


	}
	if (companies < N) { //���� ���������� ����������� �������� ������ ������ ���������� ��������, �� ����������
		int rec;
		cout << "\n\nEnter number of records: "; //����������� � ������������ ���������� �������
		cin >> rec;
		for (int i = 0; i < rec && companies < N; i++, companies++) {
			INFO zap;
			zap = vvod();
			write(p, zap);
		}
	}
	else cout << "\n\nCompanies run out"; //� ��������� ������ ������� ���������, ��� ������������� �������� ������ ���
}
void write(fstream& p, INFO zap, int num)
{
	p.clear(); //������� ������
	if (num)
		p.seekg((num - 1) * len, ios::beg);
	p.write((char*)&zap, len);
}
INFO vvod()
{
	INFO zap;
	cout << "\nChoose company to fill data:";
	for (int i = 0; i < N; i++) { //������� ������������ ������ ���� ��������, �������� �� ��, ������ ������� ��� ���������, ����� ������������ ������, ����� ����� ���������
		cout << endl << i + 1 << ". " << companyNames[i];
		if (filledCompanies[i] == '-') cout << "  || Fiiled Data!!"; //���� �������� ���������, ����� � �� ��������� ��������� ��������������� �������
	}
	int choosen;
	cout << "\nChoice: "; cin >> choosen;
	while (choosen > N || filledCompanies[choosen-1] == '-') { 		//���� ���� �� ��� ���, ���� ������������ ������� ����� ��������, ������� ������������ � ������ ���� � �� �������� �����������
		cout << "\nIncorrect choice, choose another number!";
		cout << "\nChoice: "; cin >> choosen;
	}
	filledCompanies[choosen-1] = '-'; //���������� � ������, ��� ������ �������� ���������
	strcpy_s(zap.companyName, companyNames[choosen - 1]);
	cout << "\nCompany name: " << zap.companyName;
	for (int i = 0; i < M; i++) { //��������� ��������� ������: ���������� �������� � ��� ����
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
	p.clear(); //������� ������
	if (num) //����������������
		p.seekg((num - 1) * len, ios::beg);
	p.read((char*)&zap, len);
	return p;
}

int countProducts(int array[]) { //������������ ���������� �������������� ������
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
	INFO zap; // ���� ������
	cout << shapka;
	while (read(p, zap))
		print(zap);
	cout << endl << FinishL;
}
void readN(fstream& p, int N)
{
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap; // ���� ������
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

int countCompanies(fstream& p, int& m) { //������������ ���������� ����������� ��� ������� Statistics
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

void fillAnswer(fstream& p, int ans[][20], int n, int m) { //��������� �������, ������ �� ����� ������� �������� ���������� ������ ���������� �� ��������� ������ ��� ������� ������ ������� �����������
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap;
	for (int i = 0; i < n && read(p, zap); i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = zap.unitCost[j] * zap.volume[j];
		}
	}
}

void fillNames(fstream& p, string com[], string prod[], int m) { //��������� ������ ���������� ����������� � ������ ���������� ������� 
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

void Statistics(fstream& p){ //������ ������ �������� ������
	int answer[20][20]; //������ ��� �������� ������������ ���������� �������� �� ��� ��������� ��� ������ �������� ��� ���������� ������� ��������
	int m ,n = countCompanies(p, m); //n �������� �� ���������� �����������, m �� ���������� ������� � ������� �����������
	fillAnswer(p, answer, n, m);
	string companyNamesForStatistics[20]; //������ ����� � ���������� �����������
	string productNamesForStatistics[20]; //������ ����� � ���������� ���������
	fillNames(p, companyNamesForStatistics, productNamesForStatistics, m);
	double sum = 0, max_S = 0; //���������� ��� �������� ����� ����� ������ ���� �������� � ������������ ����� �� ���� �������� �� �������� ������ �����
	int tmp = 0; //�������� �� ������ �������� � ������������ ����� ��������� ���������
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

int DeleteAll(fstream& p) { //������� ���� ��� ��������� ����� ������
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

