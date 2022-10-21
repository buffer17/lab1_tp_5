#pragma once
#include <string>

class bookstore {
protected:
	std::string title;		//��������
	float cost;				//���������
	/*---------------------------------*/
	std::string author;		//�����
	int yearRelease;		//��� �������
	int pageSize;			//����� �������
	std::string purpose;	//����������
	
public:
	bookstore();					//������ �����������
	bookstore(std::string, float, std::string, int, int, std::string);	//�����������
	bookstore(const bookstore&);	//����������� �����������
	virtual ~bookstore();

	void set_title(std::string);	//���� ��������
	void set_cost(float);			//���� ���������
	void set_author(std::string);	//���� ������
	void set_yearRelease(int);		//���� ���� �������
	void set_pageSize(int);			//���� ������ �������
	void set_purpose(std::string);	//���� ����������

	std::string get_title();		//����� ��������
	float get_cost();				//����� ���������
	std::string get_author();		//����� ������
	int get_yearRelease();			//����� ���� �������
	int get_pageSize();				//����� ������ �������
	std::string get_purpose();		//����� ����������

	virtual void out() = 0;			//����� ��������
	virtual void change_der() = 0;	//��������� ����� �������� �������
	virtual std::string get_info() = 0; //���������� � ������
	void change_basic(int);			//��������� ����� �������� ������
};
