#pragma once
#include "bookstore.h"

class textbook : public bookstore {
	int yearStudy;			//год обучения

public:
	const int id_c = 2;

	textbook();
	textbook(std::string, std::string, int, std::string, int, int, float); //называние, автор, год выпуска, назначение, год обучения, объём страниц, стоимость
	textbook(const textbook&);
	~textbook();

	void set_yearStudy(int);	//ввод года обучения
	int get_yearStudy();	//вывод года обучения

	//абс функ
	void out();
	void change_der();
	std::string get_info();
};