#include <iostream>
#include <string>
#include "book.h"

using namespace std;

book::book() : annotation(""), genre("") {}
book::book(string tit, string aut, int year, string ann, string gen, int pg, float cost) {
	this->title = tit;
	this->author = aut;
	this->yearRelease = year;
	this->annotation = ann;
	this->genre = gen;
	this->pageSize = pg;
	this->cost = cost;
}

book::book(const book& tmp) {
	this->title = tmp.title;
	this->author = tmp.author;
	this->yearRelease = tmp.yearRelease;
	this->annotation = tmp.annotation;
	this->genre = tmp.genre;
	this->pageSize = tmp.pageSize;
	this->cost = tmp.cost;
}

book::~book() {
	title = author = annotation = genre = "";
	cost = 0.0; yearRelease = pageSize = 0;
}

void book::set_annotation(string ann) { this->annotation = ann; }
void book::set_genre(string gen) { this->genre = gen; }

string book::get_annotation() { return this->annotation; }
string book::get_genre() { return this->genre; }

void book::out() {
	cout << "--BOOK--" << endl;
	cout << "Title: " << title << endl;
	cout << "Cost: " << cost << endl;
	cout << "Author: " << author << endl;
	cout << "Year of release: " << yearRelease << endl;
	cout << "Size of page: " << pageSize << endl;
	cout << "Annotation: " << annotation << endl;
	cout << "Genre: " << genre << endl;
}

string book::get_info() {
	string info;
	info = to_string(id_c) + "\n" + get_title() + "\n"
		+ get_author() + "\n" + to_string(get_yearRelease()) + "\n"
		+ get_annotation() + "\n" + get_genre() + "\n"
		+ to_string(get_pageSize()) + "\n" + to_string(get_cost()) + "\n";
	return info;
}

void book::change_der() {
	int ch;
	out();
	cout << "Change the book: " << '\n' <<
		"1. Title" << '\n' <<
		"2. Cost" << '\n' <<
		"3. Author" << '\n' <<
		"4. Year of release" << '\n' <<
		"5. Size of page" << '\n' <<
		"6. Annotation" << '\n' <<
		"7. Genre" << '\n';
	//1-5
		
	cout << "Enter number of the field to be changed: ";
	cin >> ch;
	if (ch >= 1 && ch <= 5) {
		change_basic(ch);
		return;
	}
	switch (ch) {
	case 6:
		cout << "Enter an annotation: ";
		cin.ignore(); getline(cin, this->annotation);
		break;
	case 7:
		cout << "Enter a genre: ";
		cin.ignore(); getline(cin, this->genre);
		break;
	default:
		throw exception("out of choice");
	}
}