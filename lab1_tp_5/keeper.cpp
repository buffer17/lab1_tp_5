#include <iostream>
#include "keeper.h"

using namespace std;

keeper::keeper() : size_(0), id_(0), data(NULL) {}
keeper::keeper(int sz) : size_(sz), id_(0), data(new bookstore* [size_]) {}
keeper::keeper(const keeper& tmp) {
	this->data = tmp.data;
	this->size_ = tmp.size_;
	this->id_ = tmp.id_;
}
keeper::~keeper() {
	if (size_ == 0)
		return;
	for (int i = 0; i < id_; i++)
		delete(data[i]);
	delete[] data;
	size_ = 0;
	id_ = 0;
}

std::ostream& operator<< (std::ostream& out, const keeper& k) {
	if (k.id_)
		for (int i = 0; i < k.id_; i++) {
			out << i + 1 << ". ";
			k.data[i]->out();
		}
	return out;
}

int keeper::getSIZE() { return this->size_; }
int keeper::getID() { return this->id_; }


void keeper::change_data(int index) {
	if (index < 0 || index > id_) {
		throw exception("out of choice");
		return;
	}
	data[index]->change_der();
}

void keeper::push_back(bookstore& nw_data) {
	if (id_ == size_) {
		size_ += 1;
		bookstore** data_tmp = new bookstore * [size_];
		for (int i = 0; i < id_; i++)
			data_tmp[i] = data[i];
		data_tmp[id_] = &nw_data;
		data = data_tmp;
		id_ += 1;
	}
	else {
		data[id_] = &nw_data;
		id_ += 1;
	}
}

void keeper::pop_back() {
	if (!id_)
		return;
	delete(data[id_ - 1]);
	id_ -= 1;
}

void keeper::pop_by_index(int del_id) {
	del_id--;

	bookstore** data_tmp = new bookstore * [size_];
	for (int i = 0, j = 0; j < id_; i++, j++) {
		if (del_id == i)
			j++;
			
		
		data_tmp[i] = data[j];
	}

	data = data_tmp;
	id_ -= 1;
}

void keeper::save_to_file(string path) {
	ofstream f(path);
	f << id_ << '\n';
	for (int i = 0; i < id_; i++)
		f << data[i]->get_info();
	f.close();
}

void keeper::extract_from_file(string path) {
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

	ifstream f(path);
	if (!f.is_open())
		return;
	int sz;
	int id_c;
	f >> sz;
	
	bookstore* buf = NULL;
	for (int i = 0; i < sz; i++) {
		f >> id_c;
		switch (id_c) {
		case 1:
			f.ignore(); getline(f, title);
			f.ignore(); getline(f, author);
			f >> yearRelease;
			f.ignore(); getline(f, annotation);
			f.ignore(); getline(f, genre);
			f >> pageSize >> cost;
			buf = new book(title, author, yearRelease, annotation, genre, pageSize, cost);
			break;
		case 2:
			f.ignore(); getline(f, title);
			f.ignore(); getline(f, author);
			f >> yearRelease >> yearStudy >> pageSize;
			f.ignore(); getline(f, purpose);
			f >> cost;
			buf = new textbook(title, author, yearRelease, purpose, yearStudy, pageSize, cost);
			break;
		case 3:
			f.ignore(); getline(f, title);
			f.ignore(); getline(f, color);
			f.ignore(); getline(f, purpose);
			f >> cost;
			buf = new chancellery(title, color, purpose, cost);
			break;
		}
		push_back(*buf);
	}

	f.close();
}