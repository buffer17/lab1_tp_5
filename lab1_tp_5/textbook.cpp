#include <iostream>
#include <string>
#include "textbook.h"

using namespace std;

textbook::textbook() : yearStudy(0) {}
textbook::textbook(string tit, string aut, 
	int yearR, string pur, int yearS, int pg, float cost) {
	this->title = tit;
	this->author = aut;
	this->yearRelease = yearR;
	this->purpose = pur;
	this->yearStudy = yearS;
	this->pageSize = pg;
	this->cost = cost;
}

textbook::textbook(const textbook& tmp) {
	this->title = tmp.title;
	this->author = tmp.author;
	this->yearRelease = tmp.yearRelease;
	this->purpose = tmp.purpose;
	this->yearStudy = tmp.yearStudy;
	this->pageSize = tmp.pageSize;
	this->cost = tmp.cost;
}

textbook::~textbook() {
	title = author = purpose = "";
	cost = 0.0; yearRelease = yearStudy = pageSize = 0;
}

void textbook::set_yearStudy(int year) { this->yearStudy = year; }
int textbook::get_yearStudy() { return this->yearStudy; }

void textbook::out() {
	cout << "--TEXTBOOK--" << endl;
	cout << "Title: " << title << endl;
	cout << "Cost: " << cost << endl;
	cout << "Author: " << author << endl;
	cout << "Year of release: " << yearRelease << endl;
	cout << "Size of page: " << pageSize << endl;
	cout << "Purpose: " << purpose << endl;
	cout << "Year of Study: " << yearStudy << endl;
}

string textbook::get_info() {
	string info;
	info = to_string(id_c) + "\n" + get_title() + "\n"
		+ get_author() + "\n" + to_string(get_yearRelease()) + "\n"
		+ to_string(get_yearStudy()) + "\n" + to_string(get_pageSize()) + "\n" 
		+ get_purpose() + "\n" + to_string(get_cost()) + "\n";
	return info;
}

void textbook::change_der() {
	int ch;
	out();
	cout << "Change the book: " << '\n' <<
		"1. Title" << '\n' <<
		"2. Cost" << '\n' <<
		"3. Author" << '\n' <<
		"4. Year of release" << '\n' <<
		"5. Size of page" << '\n' <<
		"6. Purpose" << '\n' <<
		"7. Year of study" << '\n';
	//1-6

	cout << "Enter number of the field to be changed: ";
	cin >> ch;
	if (ch >= 1 && ch <= 6)
		change_basic(ch);
	else if (ch == 7) {
		cout << "Enter the year of study: ";
		cin >> this->yearStudy;
	}
	else exception("out of choice");
}