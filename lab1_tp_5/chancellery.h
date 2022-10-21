#pragma once
#include "bookstore.h"

class chancellery : public bookstore {
	std::string color;		//цвет

public:
	const int id_c = 3;
	
	chancellery();
	chancellery(std::string, std::string, std::string, float); //тип, цвет, назначение, стоимость
	chancellery(const chancellery&);
	~chancellery();

	void set_color(std::string);
	std::string get_color();

	//абс функ
	void out();
	void change_der();
	std::string get_info();
};
