//#include<iostream>
//#include"person.h"
//#include<math.h>
//#include<cstdlib>
//#include<time.h>
//#include<string>
//#include<graphics.h>
//#include<easyx.h>
//#include<conio.h>
//using namespace std;
//person::person(string name, int age, int weight, int height)
//{
//	m_name = name;
//	m_age = age;
//	m_weight = weight;
//	m_height = height;
//}
//double::person::test_BMI()
//{
//	double BMI = m_weight / pow(m_height, 2);
//	return BMI;
//}
//int::person::test_heart_rate()
//{
//	srand(time(0));
//	int x = (rand() % (100 - 60 + 1)) + 60;
//	return x;
//}
//void::person::print()
//{
//	cout << "姓名：" << m_name << "  " << "年龄：" << m_age << "  " << "身高：" << m_height << "  " << "体重：" << m_height << endl;
//}
//
//void::person::Intelligence_Calculate_Steps()
//{
//	initgraph(800, 600, SHOWCONSOLE);
//	IMAGE img1, img2;
//	loadimage(&img1, "e21c84c214dec8af26251adb7353fe58.jpg", 100, 100);
//	loadimage(&img2, "计数器.jpg", 800, 300);
//	putimage(0, 300, &img2);
//	int x = 0, y = 0;
//	char num[20];
//	int count = 0;
//	settextstyle(200, 0, _T("Consolas"));
//	while (1)
//	{
//		putimage(0, 300, &img2);
//		putimage(x, y, &img1);
//		sprintf(num, "%d", count);
//		outtextxy(350, 330, num);
//		char  key = _getch();
//		switch (key)
//		{
//		case 'W':
//		case 'w':
//			if(y>=10)
//			y -= 10;
//			count++;
//			break;
//		case 'S':
//		case 's':
//			if(y<=190)
//			y += 10;
//			count++;
//			break;
//		case 'A':
//		case 'a':
//			if(x>=10)
//			x -= 10;
//			count++;
//			break;
//		case 'D':
//		case 'd':
//			if(x<=700)
//			x += 10;
//			count++;
//			break;
//		case 13:
//			return;
//		}
//		cleardevice();
//	}
//}