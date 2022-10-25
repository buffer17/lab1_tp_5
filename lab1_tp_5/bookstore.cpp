#include <iostream>
#include <string>
#include "bookstore.h"

using namespace std;

bookstore::bookstore() : title(""), cost(0), author(""),
						yearRelease(0), pageSize(0), purpose("") {}

bookstore::bookstore(string title_, float cost_, string author_,
	int yearR_, int pageS_, string pur_) : title(title_), cost(cost_), author(author_),
	yearRelease(yearR_), pageSize(pageS_), purpose(pur_) {}

bookstore::bookstore(const bookstore& tmp) {
	this->title = tmp.title;
	this->cost = tmp.cost;
	this->author = tmp.author;
	this->yearRelease = tmp.yearRelease;
	this->pageSize = tmp.pageSize;
	this->purpose = tmp.purpose;
}

bookstore::~bookstore() {
	title = author = purpose = "";
	cost = 0.0; yearRelease = pageSize = 0;
}

void bookstore::set_title(string title) { this->title = title; }
void bookstore::set_cost(float cost) { this->cost = cost; }
void bookstore::set_author(string ath) { this->author = ath; }
void bookstore::set_yearRelease(int year) { this->yearRelease = year; }
void bookstore::set_pageSize(int pg) { this->pageSize = pg; }
void bookstore::set_purpose(string pur) { this->purpose = pur; }

string bookstore::get_title() { return this->title; }
float bookstore::get_cost() { return this->cost; }
string bookstore::get_author() { return this->author; }
int bookstore::get_yearRelease() { return this->yearRelease; }
int bookstore::get_pageSize() { return this->pageSize; }
string bookstore::get_purpose() { return this->purpose; }

void bookstore::change_basic(int ch) {
	switch (ch) {
	case 1:
		cout << "Enter title: "; cin.ignore(); getline(cin, title);
		break;
	case 2:
		cout << "Enter cost: "; cin >> cost;
		break;
	case 3:
		cout << "Enter the author: "; cin.ignore(); getline(cin, author);
		break;
	case 4:
		cout << "Enter the year of release: "; cin >> yearRelease;
		break;
	case 5:
		cout << "Enter the page size: "; cin >> pageSize;
		break;
	case 6:
		cout << "Enter purpose: "; cin.ignore(); getline(cin, purpose);
		break;
	default:
		throw exception("out of choice");
	}
}
