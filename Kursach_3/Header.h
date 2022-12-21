#pragma once
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

extern int len;
extern char fname[20]; // переменная под наш файл

struct INFO
{
public:
	char companyName[20];
	char productName[20][20];
	int volume[20];
	int unitCost[20];
	char metka[2];
	INFO() {
		for (int i = 0; i < 20; i++) {
			companyName[i] = 0;
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				productName[i][j] = 0;
			}

		}
		for (int i = 0; i < 20; i++) {
			volume[i] = 0;
		}
		for (int i = 0; i < 20; i++) {
			unitCost[i] = 0;
		}
		for (int i = 0; i < 2; i++) {
			metka[i] = 0;
		}

	}
};


void write(fstream& p, INFO zap, int num = 0);
void print(INFO zap);
INFO vvod();
void writeNzap(fstream& p);
fstream& read(fstream& p, INFO& zap, int num = 0);
void readAll(fstream& p);
void readN(fstream& p, int N);
int metkaDel(fstream& p, char* shifr);
void UNmetkaDel(fstream& p);
void Statistics(fstream& p);
int Delete(fstream& p);
int DeleteAll(fstream& p);
int countProducts(int array[]);
void fillAnswer(fstream& p, int ans[][20], int n, int m);
int countCompanies(fstream& p, int& m);
