#include <iostream>
#include <string>
#include "chancellery.h"

using namespace std;

chancellery::chancellery() : color("") {}
chancellery::chancellery(string tit, string col, 
						string pur, float cost) {
	this->title = tit;
	this->color = col;
	this->purpose = pur;
	this->cost = cost;
}

chancellery::chancellery(const chancellery& tmp) {
	this->title = tmp.title;
	this->color = tmp.color;
	this->purpose = tmp.purpose;
	this->cost = tmp.cost;
}

chancellery::~chancellery() {
	title = color = purpose = "";
	cost = 0.0;
}

void chancellery::set_color(string color_) { this->color = color_; }
string chancellery::get_color() { return this->color; }

void chancellery::out() {
	cout << "--CHANCELLERY--" << endl;
	cout << "Title: " << title << endl;
	cout << "Cost: " << cost << endl;
	cout << "Purpose: " << purpose << endl;
	cout << "Color: " << color << endl;
}

string chancellery::get_info() {
	string info;
	info = to_string(id_c) + "\n" + get_title() + "\n"
		+ get_color() + "\n" + get_purpose() + "\n"
		+ to_string(get_cost()) + "\n";
	return info;
}

void chancellery::change_der() {
	int ch;
	out();
	cout << "Change the book: " << '\n' <<
		"1. Title" << '\n' <<
		"2. Cost" << '\n' <<
		"3. Purpose" << '\n' <<
		"4. Color" << '\n';
	//1-2

	cout << "Enter number of the field to be changed: ";
	cin >> ch;
	if (ch >= 1 && ch <= 2)
		change_basic(ch);
	else if (ch == 3)
		change_basic(6); //purpose
	else if (ch == 4) /*change color*/ {
		cout << "Enter the color: ";
		cin.ignore(); getline(cin, this->color);
	}
	else throw exception("out of choice");

}