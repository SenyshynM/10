#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

struct route
{
	int nomer;
	char start[30];
	char end[30];
};

void Print(char* filename);
void Create(char* filename);
void Search(char* filename);

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
		cout << "[3] - Пошук по номеру маршруту\n";
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
			cout << "Пошук за номером маршруту:\n";
			cin.get();
			cin.sync();
			cout << "Введіть назву файлу: "; cin.getline(filename, sizeof(filename));
			Search(filename);
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
	FILE* f;
	if ((f = fopen(filename, "w")) == 0)
	{
		cerr << "Error opening file '" << filename << "'" << endl;
		return;
	}

	route r;
	char ch;

	do
	{
		cout << endl;
		cout << "Початок: "; cin >> r.start;
		cout << "Кінець: "; cin >> r.end;
		cout << "Номер: "; cin >> r.nomer;
		cin.sync();

		if (fwrite(&r, sizeof(route), 1, f) != 1)
		{
			cerr << "Error writing file." << endl;
			return;
		}

		cout << "Продовжити? [Y/n]: "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	fclose(f);
}

void Print(char* filename)
{
	FILE* f;
	if ((f = fopen(filename, "r")) == NULL)
	{
		cerr << "Error opening file '" << filename << "'" << endl;
		return;
	}
	route r;

	cout << "=============================="
		<< endl;
	cout << "| Початок | Кінець | Номер " << setw(3) << "|"
		<< endl;
	cout << "------------------------------"
		<< endl;

	while (!feof(f))
	{

		if (fread(&r, sizeof(route), 1, f) != 1)
			if (feof(f))
			{
				cout << "------------------------------" << endl << endl;
				return;
			}
		cout << "| " << setw(7) << left << r.start << " "
			<< "| " << setw(6) << right << r.end << " "
			<< "| " << setw(7) << left << r.nomer << " |" << endl;
	}

	fclose(f);

}

void Search(char* filename)
{
	int found = 0;
	int nomer;
	cout << "Введіть номер маршруту: ";
	cin.sync(); cin >> nomer;

	FILE* f;
	if ((f = fopen(filename, "r")) == NULL)
	{
		cerr << "Error opening file '" << filename << "'" << endl;
		return;
	}
	route r;

	while (!feof(f))
	{
		if (fread(&r, sizeof(route), 1, f) != 1)
			if (feof(f))
			{
				break;
			}

		if (r.nomer == nomer)
		{
			found++;
			cout << endl;
			cout << " Маршрут з номером " << nomer << " знайдено: " << endl;
			cout << " Початок: " << r.start << endl;
			cout << " Кінець: " << r.end << endl;
		}
	}

	if (found == 0)
	{
		cout << "Маршрут не знайдено." << endl;
	}

	fclose(f);
}

