#pragma once
#include "bookstore.h"

class book : public bookstore {
	std::string annotation; //���������
	std::string genre;		//����
public:
	const int id_c = 1;

	book();
	book(std::string, std::string, int, std::string, std::string, int, float); //��������, �����, ��� �������, ���������, ����, ����� �������, ���������
	book(const book&);
	~book();


	void set_annotation(std::string);//���� ���������
	void set_genre(std::string);	 //���� �����

	std::string get_annotation();	//����� ���������
	std::string get_genre();		//����� �����

	//��� ����
	void out();
	void change_der();
	std::string get_info();
};