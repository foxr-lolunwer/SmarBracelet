#pragma once
#pragma warning( disable : 4996 )
#pragma	comment(lib,"winmm.lib")
#include<iostream>
#include <vector>
#include<fstream>
#include<string>
#include<easyx.h>
#include<graphics.h>
#include<Windows.h>
#include<cstring>
#include<algorithm>
#include<mmsystem.h>
using namespace std;
class phone
{
public:
	phone();
	void menu();
	void print(int s);
	void modify();
	void modify2(vector<phone>& v, int c);
	void showperson();
	void print2(int s);
	void personseek();
	void deleteperson();
	void print3();
	void incoming_call();
private:
	int m_number;
	char  m_Name[20];
	char m_Sex[20];
	int m_Age;
	char  m_Phone[20];
	char  m_Addr[20];
};

