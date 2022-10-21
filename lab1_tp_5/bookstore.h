#pragma once
#include <string>

class bookstore {
protected:
	std::string title;		//название
	float cost;				//стоимость
	/*---------------------------------*/
	std::string author;		//автор
	int yearRelease;		//год выпуска
	int pageSize;			//объём страниц
	std::string purpose;	//назначение
	
public:
	bookstore();					//пустой конструктор
	bookstore(std::string, float, std::string, int, int, std::string);	//конструктор
	bookstore(const bookstore&);	//конструктор копирования
	virtual ~bookstore();

	void set_title(std::string);	//ввод названия
	void set_cost(float);			//ввод стоимости
	void set_author(std::string);	//ввод автора
	void set_yearRelease(int);		//ввод года выпуска
	void set_pageSize(int);			//ввод объёма страниц
	void set_purpose(std::string);	//ввод назначения

	std::string get_title();		//вывод названия
	float get_cost();				//вывод стоимости
	std::string get_author();		//вывод автора
	int get_yearRelease();			//вывод года выпуска
	int get_pageSize();				//вывод объёма страниц
	std::string get_purpose();		//вывод назначения

	virtual void out() = 0;			//вывод объектов
	virtual void change_der() = 0;	//изменение полей дочерних классов
	virtual std::string get_info() = 0; //информация о классе
	void change_basic(int);			//изменение полей базового класса
};
