#pragma once
#include "bookstore.h"

class book : public bookstore {
	std::string annotation; //аннотация
	std::string genre;		//жанр
public:
	const int id_c = 1;

	book();
	book(std::string, std::string, int, std::string, std::string, int, float); //название, автор, год выпуска, аннотация, жанр, объём страниц, стоимость
	book(const book&);
	~book();


	void set_annotation(std::string);//ввод аннотации
	void set_genre(std::string);	 //ввод жарра

	std::string get_annotation();	//вывод аннотации
	std::string get_genre();		//вывод жанра

	//абс функ
	void out();
	void change_der();
	std::string get_info();
};