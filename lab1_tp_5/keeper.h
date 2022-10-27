#pragma once
#include <fstream>
#include "bookstore.h"
#include "textbook.h"
#include "book.h"
#include "chancellery.h"

class keeper {
	bookstore** data;
	int size_;
	int id_;

public:
	keeper();
	keeper(int);
	keeper(const keeper&);
	~keeper();

	friend std::ostream& operator<< (std::ostream& out, const keeper& k);

	void push_back(bookstore&);
	void pop_back();
	void pop_by_index(int);
	void change_data(int);

	void save_to_file(std::string);
	void extract_from_file(std::string);

	int getSIZE();
	int getID();
};