#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;
void Create(char* filename);
void Print(char* filename);
void count(char* filename, char* ofilename);
bool Same(string r);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	char filename[101];

	do {
		cout << "--------------------------\n";
		cout << "Меню\n";
		cout << "[1] - Ввести і зберегти інформацію\n";
		cout << "[2] - Загрузити і вивести інформацію\n";
		cout << "[3] - Отримати кількість рядків\n";
		cout << "[0] - завершити роботу\n";
		cout << "--------------------------\n";
		cout << "Виберіть: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Введення і збереження:\n";
			cin.get();
			cin.sync();
			cout << "Введіть назву файлу: "; cin.getline(filename, sizeof(filename));
			Create(filename);
			break;

		case 2:
			cout << "Виведення інформації:\n";
			cin.get();
			cin.sync();
			cout << "Введіть назву файлу: "; cin.getline(filename, sizeof(filename));
			Print(filename);
			break;

		case 3:
			cin.get();
			cin.sync();
			char ofilename[101];
			cout << "Введіть назву файлу: "; cin.getline(filename, sizeof(filename));
			cout << "Введіть назву файлу для виведення інформації: "; cin.getline(ofilename, sizeof(ofilename));
			count(filename, ofilename);
			break;

		case 0:
			break;

		default:
			cout << "--------------------------\n";
			cout << "Меню\n";
			cout << "[1] - Ввести і зберегти інформацію\n";
			cout << "[2] - Загрузити і вивести інформацію\n";
			cout << "[3] - Пошук по номеру маршруту\n";
			cout << "[0] - Завершити роботу\n";
			cout << "--------------------------\n";
			cout << "Виберіть:";
			cin >> choice;
		}
	} while (choice != 0);
}

void Create(char* filename)
{
	ofstream f(filename);
	if (!f)
	{
		cerr << "Помилка відкриття файлу '" << filename << "'" << endl;
		return;
	}

	char ch;
	char r[101];
	do
	{
		cout << endl;
		cout << "Введіть рядок: "; cin.sync();
		cin >> r; cout << endl;

		if (!f.write((char*)&r, sizeof(r)))
		{
			cerr << "Помилка запису у файл." << endl;
		}

		cout << "Продовжити? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	f.close();
}

void Print(char* filename)
{

	ifstream f(filename);
	char r[101];
	if (!f)
	{
		cerr << "Помилка відкриття файлу '" << filename << "'" << endl;
		return;
	}

	while (f.read((char*)&r, sizeof(r)))
	{
		cout << endl;
		cout << r;
	}
	cout << endl;

	f.close();
}

bool Same(string s) {
	int s1 = 0; int s2 = 1;
	for(int i = 0; i < s.length() - 1; i++){
		if (s[s1] != s[s2])
			return false;
		s1++; s2++;
	}

	return true;
}


void count(char* filename, char* ofilename)
{
	fstream f(filename, ios::in | ios::binary);
	if (!f)
	{
		cerr << "Помилка відкриття файлу '" << filename << "'" << endl;
		return;
	}

	int first = 0; int first_and_last = 0; int same = 0; int empty = 0;

	string symbol;
	char s[101];

	cout << "Введіть перший символ: "; cin.sync(); cin >> symbol; cout << endl;
	cin.sync();

	while (f.read((char*)&s, sizeof(s)))
	{
		if (s[0] == symbol[0])
			first++;
		else if (Same(s) == true)
			same++;
		else if (s[0] == s[strlen(s) - 1])
			first_and_last++;
		else if (s[0] == '\0')
			empty++;
	}

	f.close();
	ofstream out(ofilename);

	out << "-----------------------------------\n";
	out << first << " - Перший символ \n";
	out << first_and_last << " - Перший і останній \n";
	out << same << " - Строка з однакових символів \n";
	out << empty << " - Пуста строка \n";

	out.close();
	string outp;
	ifstream out_print(ofilename);

	while (getline(out_print, outp)) {
		cout << outp << '\n';
	}
}
