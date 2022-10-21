#pragma once
#include "bookstore.h"

class textbook : public bookstore {
	int yearStudy;			//��� ��������

public:
	const int id_c = 2;

	textbook();
	textbook(std::string, std::string, int, std::string, int, int, float); //���������, �����, ��� �������, ����������, ��� ��������, ����� �������, ���������
	textbook(const textbook&);
	~textbook();

	void set_yearStudy(int);	//���� ���� ��������
	int get_yearStudy();	//����� ���� ��������

	//��� ����
	void out();
	void change_der();
	std::string get_info();
};