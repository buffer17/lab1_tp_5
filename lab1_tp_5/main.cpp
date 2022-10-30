#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "bookstore.h"
#include "book.h"
#include "textbook.h"
#include "chancellery.h"
#include "keeper.h"

using namespace std;

void fill_keeper(keeper&, int); //1-book, 2-textbook, 3-chancellery
void menu_output(short); //отрисовка меню
void set_color(WORD color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
enum colors_ {
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED
};

int main() {
	
	keeper k;

	menu_output(1);
	char key_tmp; //временный символ
	char key; //опция
	short func = 1; //запуск функции
	bool ENTER_;
	bool exit = false;

	while (!exit) {
		ENTER_ = false;
		key_tmp = _getch();
		key_tmp == 224 ? key = _getch() : key = key_tmp;

		//управление меню
		switch (key) {
		case 80: //вниз
			func++;
			if (func > 11)
				func = 1;
			break;
		case 72: //вверх
			func--;
			if (func < 1)
				func = 11;
			break;
		case 13: //enter
			ENTER_ = true;
			break;
		}

		//switch var
		int del_id;
		int index;

		if (ENTER_) { //запуск функций
			switch (func) {
			case 1: //add a book
				fill_keeper(k, 1);
				break;
			case 2: //add a textbook
				fill_keeper(k, 2);
				break;
			case 3: //add a chancellery
				fill_keeper(k, 3);
				break;
			case 4: //Delete the last element
				k.pop_back();
				break;
			case 5: //Delete by index
				cout << "Enter index: ";
				cin >> del_id;
				k.pop_by_index(del_id);
				break;
			case 6: //Out keepe
				cout << k;
				system("pause");
				break;
			case 7: //Change
				try {
					cout << "Enter the index of the object to change" << endl;
					cin >> index;
					k.change_data(index - 1);
				}
				catch (const exception exp) { cout << exp.what() << '\n'; system("pause"); }
				break;
			case 8: //Clear
				k.~keeper();
				break;
			case 9: //Save to file
				k.save_to_file("keeper.txt");
				break;
			case 10: //Extract from file
				k.extract_from_file("keeper.txt");
				break;
			case 11: //Exit
				exit = true;
				break;
			}
		}
		menu_output(func);
	}

	return 0;
}

void fill_keeper(keeper& k, int p) {
	//шаблон полей
	string title;
	string author;
	string purpose;
	string color;
	string genre;
	string annotation;
	float cost;
	int yearRelease;
	int yearStudy;
	int pageSize;

	cout << "Enter title: "; cin.ignore(); getline(cin, title);
	cout << "Enter cost: "; cin >> cost;

	bookstore* buf = NULL;
	if (p <= 0 || p >= 4)
		return;
	switch (p) {
	case 1:
		cout << "Enter the author: "; cin.ignore(); getline(cin, author);
		cout << "Enter the year of release: "; cin >> yearRelease;
		cout << "Enter an annotation: "; cin.ignore(); getline(cin, annotation);
		cout << "Enter a genre: "; cin.ignore(); getline(cin, genre);
		cout << "Enter the page size: "; cin >> pageSize;
		buf = new book(title, author, yearRelease, annotation, genre, pageSize, cost);
		break;
	case 2:
		cout << "Enter the author: "; cin.ignore(); getline(cin, author);
		cout << "Enter the year of release: "; cin >> yearRelease;
		cout << "Enter purpose: "; cin.ignore(); getline(cin, purpose);
		cout << "Enter the year of study: "; cin >> yearStudy;
		cout << "Enter the page size: "; cin >> pageSize;
		buf = new textbook(title, author, yearRelease, purpose, yearStudy, pageSize, cost);
		break;
	case 3:
		cout << "Enter the color: "; cin.ignore(); getline(cin, color);
		cout << "Enter purpose: "; cin.ignore(); getline(cin, purpose);
		buf = new chancellery(title, color, purpose, cost);
		break;
	}
	cout << endl;
	k.push_back(*buf);
}

void menu_output(short menu) {
	set_color(WHITE);
	system("cls");

	cout << endl << "====================================\n\n";
	if (menu == 1)
		set_color(RED);
	else set_color(WHITE);
	cout << "Add a book\n";
	if (menu == 2)
		set_color(RED);
	else set_color(WHITE);
	cout << "Add a textbook\n";
	if (menu == 3)
		set_color(RED);
	else set_color(WHITE);
	cout << "Add a chancellery\n";
	if (menu == 4)
		set_color(RED);
	else set_color(WHITE);
	cout << "Delete the last element\n";
	if (menu == 5)
		set_color(RED);
	else set_color(WHITE);
	cout << "Delete by index\n";
	if (menu == 6)
		set_color(RED);
	else set_color(WHITE);
	cout << "Out keeper\n";
	if (menu == 7)
		set_color(RED);
	else set_color(WHITE);
	cout << "Change\n";
	if (menu == 8)
		set_color(RED);
	else set_color(WHITE);
	cout << "Clear\n";
	if (menu == 9)
		set_color(RED);
	else set_color(WHITE);
	cout << "Save to file\n";
	if (menu == 10)
		set_color(RED);
	else set_color(WHITE);
	cout << "Extract from file\n";
	if (menu == 11)
		set_color(RED);
	else set_color(WHITE);
	cout << "Exit\n" << endl;
}