#include"phone.h"
using namespace std;
phone::phone()
{
	m_number = 0;
}
void::phone::menu()
{
	const int x = 1600, y = 820;
	initgraph(x, y, SHOWCONSOLE);
	IMAGE img, img2, img3;
	loadimage(&img, "resource/img/img1.jpg", x, y);
	loadimage(&img2, "resource/img/img2.jpg", x, y);
	loadimage(&img3, "resource/img/img3.jpg", x, y);
	putimage(0, 0, &img);
	settextstyle(50, 0, "�����ֺ��μ���");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(148, 0, 211));
	outtextxy(700, 100, "�����ϵ��");
	outtextxy(700, 200, "��ʾ��ϵ��");
	outtextxy(700, 300, "�޸���ϵ��");
	outtextxy(700, 400, "������ϵ��");
	outtextxy(700, 500, "ɾ����ϵ��");
	outtextxy(700, 600, "ģ������");
	outtextxy(700, 700, "�˳�ϵͳ");
	MOUSEMSG m;
	int flag = 1;
	while (1)
	{
		ExMessage msg;
		msg = getmessage(EM_MOUSE);

		switch (msg.message)
		{
		case WM_MOUSEMOVE:
			if (flag == 1)
			{
				if (msg.x >= 700 && msg.x <= 950 && msg.y >= 100 && msg.y <= 150)
				{
					settextcolor(RGB(200, 20, 60));
					outtextxy(700, 100, "�����ϵ��");
				}
				else
				{
					settextcolor(RGB(148, 0, 211));
					outtextxy(700, 100, "�����ϵ��");
				}
				if (msg.x >= 700 && msg.x <= 950 && msg.y >= 200 && msg.y <= 250)
				{
					settextcolor(RGB(200, 20, 60));
					outtextxy(700, 200, "��ʾ��ϵ��");
				}
				else
				{
					settextcolor(RGB(148, 0, 211));
					outtextxy(700, 200, "��ʾ��ϵ��");
				}
				if (msg.x >= 700 && msg.x <= 950 && msg.y >= 300 && msg.y <= 350)
				{
					settextcolor(RGB(200, 20, 60));
					outtextxy(700, 300, "�޸���ϵ��");
				}
				else
				{
					settextcolor(RGB(148, 0, 211));
					outtextxy(700, 300, "�޸���ϵ��");
				}
				if (msg.x >= 700 && msg.x <= 950 && msg.y >= 400 && msg.y <= 450)
				{
					settextcolor(RGB(200, 20, 60));
					outtextxy(700, 400, "������ϵ��");
				}
				else
				{
					settextcolor(RGB(148, 0, 211));
					outtextxy(700, 400, "������ϵ��");
				}
				if (msg.x >= 700 && msg.x <= 950 && msg.y >= 500 && msg.y <= 550)
				{
					settextcolor(RGB(200, 20, 60));
					outtextxy(700, 500, "ɾ����ϵ��");
				}
				else
				{
					settextcolor(RGB(148, 0, 211));
					outtextxy(700, 500, "ɾ����ϵ��");
				}
				if (msg.x >= 700 && msg.x <= 950 && msg.y >= 600 && msg.y <= 650)
				{
					settextcolor(RGB(200, 20, 60));
					outtextxy(700, 600, "ģ������");
				}
				else
				{
					settextcolor(RGB(148, 0, 211));
					outtextxy(700, 600, "ģ������");
				}
				if (msg.x >= 700 && msg.x <= 950 && msg.y >= 700 && msg.y <= 750)
				{
					settextcolor(RGB(200, 20, 60));
					outtextxy(700, 700, "�˳�ϵͳ");
				}
				else
				{
					settextcolor(RGB(148, 0, 211));
					outtextxy(700, 700, "�˳�ϵͳ");
				}
			}
			break;
		case WM_LBUTTONDOWN:
			if (msg.x >= 700 && msg.x <= 950 && msg.y >= 100 && msg.y <= 150)
			{
				cleardevice();
				putimage(0, 0, &img2);
				char s1[20];
				char s2[20];
				char s3[20];
				char s4[20];
				char s5[20];
				InputBox(s1, 20, "��������ϵ������", NULL, 0, 50, 50);
				InputBox(s2, 20, "��ѡ���Ա�1�����У�2����Ů", NULL, 0, 50, 50);
				InputBox(s3, 20, "��������ϵ������", NULL, 0, 50, 50);
				InputBox(s4, 20, "��������ϵ�˵绰", NULL, 0, 50, 50);
				InputBox(s5, 20, "��������ϵ��סַ", NULL, 0, 50, 50);
				strcpy(m_Name, s1);
				int n = atoi(s2);
				if (n == 1)
					strcpy(m_Sex, "��");
				if (n == 2)
					strcpy(m_Sex, "Ů");
				m_Age = atoi(s3);
				strcpy(m_Phone, s4);
				strcpy(m_Addr, s5);
				if (m_number == 0)
				{

					ofstream ofs;
					ofs.open("test.txt", ios::binary);
					if (!ofs)
					{
						std::cout << "�޷����ļ����ж�ȡ������" << std::endl;
						return;
					}
					ofs.write(reinterpret_cast<char*>(&*this), sizeof(*this));
					ofs.close();
				}
				else
				{
					ofstream ofs;
					ofs.open("test.txt", ios::app);
					if (!ofs) {
						std::cout << "�޷����ļ����ж�ȡ������" << std::endl;
						return;
					}
					ofs.write(reinterpret_cast<char*>(&*this), sizeof(*this));
					ofs.close();
				}
				m_number++;
				closegraph();
				menu();
			}
			if (msg.x >= 700 && msg.x <= 950 && msg.y >= 200 && msg.y <= 250)
			{
				cleardevice();
				putimage(0, 0, &img3);
				outtextxy(750, 650, "����");
				flag = 2;
				showperson();

			}
			if (msg.x >= 700 && msg.x <= 950 && msg.y >= 300 && msg.y <= 350)
			{
				cleardevice();
				putimage(0, 0, &img3);
				flag = 2;
				modify();
			}
			if (msg.x >= 700 && msg.x <= 950 && msg.y >= 400 && msg.y <= 450)
			{
				cleardevice();
				putimage(0, 0, &img3);
				flag = 2;
				personseek();
			}
			if (msg.x >= 700 && msg.x <= 950 && msg.y >= 500 && msg.y <= 550)
			{
				cleardevice();
				putimage(0, 0, &img3);
				flag = 2;
				deleteperson();
			}
			if (msg.x >= 700 && msg.x <= 950 && msg.y >= 600 && msg.y <= 650)
			{
				flag = 2;
				cleardevice();
				putimage(0, 0, &img3);
				incoming_call();
			}
			if (msg.x >= 700 && msg.x <= 950 && msg.y >= 700 && msg.y <= 750)
			{
				closegraph();
				return;
			}
			if (msg.x >= 700 && msg.x <= 950 && msg.y >= 650 && msg.y <= 700)
			{
				menu();
			}
			break;
		}
	}
}
void::phone::print(int s)
{

	int x = s * 100;
	char num[20];
	sprintf(num, "%d", m_Age);
	settextstyle(35, 0, "�����ֺ��μ���");
	outtextxy(100, x, "������");
	outtextxy(170, x, m_Name);
	outtextxy(270, x, "�Ա�");
	outtextxy(340, x, m_Sex);
	outtextxy(410, x, "���䣺");
	outtextxy(480, x, num);
	outtextxy(550, x, "�绰��");
	outtextxy(620, x, m_Phone);
	outtextxy(800, x, "סַ��");
	outtextxy(870, x, m_Addr);
}
void::phone::showperson()
{
	settextcolor(RGB(0, 0, 0));
	if (m_number == 0)
	{
		settextstyle(200, 50, "�����ֺ��μ���");
		outtextxy(500, 300, "��ϵ��Ϊ��");
	}
	else
	{
		settextcolor(RGB(255, 69, 0));
		ifstream ifs;
		ifs.open("test.txt", ios::binary);
		if (!ifs) {
			std::cout << "�޷����ļ����ж�ȡ������" << std::endl;
		}
		vector<phone>v;
		int s = 0;
		for (int i = 0; i < m_number; i++)
		{
			phone p;
			ifs.read(reinterpret_cast<char*>(&p), sizeof(p));
			v.push_back(p);
			v[i].print(s);
			s++;
		}
		ifs.close();
	}

}
void::phone::print2(int s)
{
	int x = s * 100;
	settextcolor(RGB(255, 255, 0));
	settextstyle(100, 0, "�����ֺ��μ���");
	outtextxy(700, x, m_Name);
}
void::phone::modify2(vector<phone>& v, int c)
{
	char s[20];
	InputBox(s, 20, "��ѡ��Ҫ�޸ĵ����ݣ�1--������2--���䣬3--�Ա�4--�绰��5--סַ", NULL, 0, 50, 50);
	int n = atoi(s);
	if (n == 1)
	{
		InputBox(s, 20, "������������", NULL, 0, 50, 50);
		strcpy(v[c].m_Name, s);
	}
	if (n == 2)
	{
		InputBox(s, 20, "���������䣺", NULL, 0, 50, 50);
		v[c].m_Age = atoi(s);
	}
	if (n == 3)
	{
		InputBox(s, 20, "��ѡ���Ա�1--�У�2--Ů", NULL, 0, 50, 50);
		int a = atoi(s);
		if (a == 1)
			strcpy(v[c].m_Sex, "��");
		if (a == 2)
			strcpy(v[c].m_Sex, "Ů");
	}
	if (n == 4)
	{
		InputBox(s, 20, "������绰��", NULL, 0, 50, 50);
		strcpy(v[c].m_Phone, s);
	}
	if (n == 5)
	{
		InputBox(s, 20, "������סַ��", NULL, 0, 50, 50);
		strcpy(v[c].m_Addr, s);
	}
	for (int i = 0; i <= c; i++)
	{
		if (i == 0)
		{
			ofstream ofs;
			ofs.open("test.txt", ios::binary);
			if (!ofs) {
				std::cout << "�޷����ļ����ж�ȡ������" << std::endl;
				return;
			}
			ofs.write(reinterpret_cast<char*>(&v[i]), sizeof(v[i]));
			ofs.close();
		}
		else
		{
			ofstream ofs;
			ofs.open("test.txt", ios::app);
			if (!ofs) {
				std::cout << "�޷����ļ����ж�ȡ������" << std::endl;
				return;
			}
			ofs.write(reinterpret_cast<char*>(&v[i]), sizeof(v[i]));
			ofs.close();
		}

	}
}
void::phone::modify()
{
	outtextxy(750, 650, "����");
	if (m_number == 0)
	{
		settextcolor(RGB(0, 0, 0));
		settextstyle(200, 50, "�����ֺ��μ���");
		outtextxy(500, 300, "��ϵ��Ϊ��");
	}
	else
	{
		settextcolor(RGB(0, 255, 255));
		settextstyle(50, 0, "�����ֺ��μ���");
		outtextxy(0, 0, "��ѡ��Ҫ�޸ĵ���ϵ�ˣ�");
		ifstream ifs;
		ifs.open("test.txt", ios::binary);
		if (!ifs) {
			std::cout << "�޷����ļ����ж�ȡ������" << std::endl;
		}
		vector<phone>v;
		int s = 0;
		for (int i = 0; i < m_number; i++)
		{
			phone p;
			ifs.read(reinterpret_cast<char*>(&p), sizeof(p));
			v.push_back(p);
			v[i].print2(s);
			s++;
		}
		ifs.close();
		MOUSEMSG m;
		int c = 0;
		while (1)
		{
			ExMessage msg;
			msg = getmessage(EM_MOUSE);
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 700 && msg.x <= 850 && msg.y >= 0 && msg.y <= 100)
				{
					modify2(v, c);
					menu();
				}
				if (msg.x >= 700 && msg.x <= 850 && msg.y >= 100 && msg.y <= 200)
				{
					c++;
					modify2(v, c);
					menu();
				}
				if (msg.x >= 700 && msg.x <= 850 && msg.y >= 200 && msg.y <= 300)
				{
					c += 2;
					modify2(v, c);
					menu();
				}
				if (msg.x >= 700 && msg.x <= 850 && msg.y >= 300 && msg.y <= 400)
				{
					c += 3;
					modify2(v, c);
					menu();
				}
				if (msg.x >= 400 && msg.x <= 650 && msg.y >= 400 && msg.y <= 500)
				{
					c += 4;
					modify2(v, c);
					menu();
				}
				if (msg.x >= 700 && msg.x <= 950 && msg.y >= 650 && msg.y <= 700)
				{
					menu();
				}
				break;
			}
		}
	}
}
void::phone::personseek()
{
	outtextxy(750, 650, "����");
	if (m_number == 0)
	{
		settextcolor(RGB(0, 0, 0));
		settextstyle(200, 50, "�����ֺ��μ���");
		outtextxy(500, 300, "��ϵ��Ϊ��");
	}
	else
	{
		char s[20];
		InputBox(s, 20, "������Ҫ������ϵ��������", NULL, 0, 50, 50);
		ifstream ifs;
		ifs.open("test.txt", ios::binary);
		if (!ifs) {
			std::cout << "�޷����ļ����ж�ȡ������" << std::endl;
		}
		vector<phone>v;
		char str[20];
		for (int i = 0; i < m_number; i++)
		{
			phone p;
			ifs.read(reinterpret_cast<char*>(&p), sizeof(p));
			v.push_back(p);
			strcpy(str, s);
			char* s;
			s = strstr(v[i].m_Name, str);
			if (s)
			{
				int s = 1;
				v[i].print(s);
				ifs.close();
				return;
			}
		}
		settextcolor(RGB(0, 0, 0));
		settextstyle(200, 50, "�����ֺ��μ���");
		outtextxy(500, 200, "δ���ҵ�����ϵ��");
	}
}
void::phone::print3()
{
	cleardevice();
	int x = 1600, y = 820;
	IMAGE img3;
	loadimage(&img3, "ͼƬ5.jpg", x, y);
	putimage(0, 0, &img3);
	settextcolor(RGB(0, 255, 255));
	settextstyle(200, 50, "�����ֺ��μ���");
	outtextxy(300, 200, "�Ƿ�ȷ��ɾ������ϵ��");
	outtextxy(0, 600, "��");
	outtextxy(1450, 600, "��");
}
void::phone::deleteperson()
{
	outtextxy(750, 650, "����");
	if (m_number == 0)
	{
		settextcolor(RGB(0, 0, 0));
		settextstyle(200, 50, "�����ֺ��μ���");
		outtextxy(500, 300, "��ϵ��Ϊ��");
	}
	else
	{
		settextcolor(RGB(0, 255, 255));
		settextstyle(50, 0, "�����ֺ��μ���");
		outtextxy(0, 0, "��ѡ��Ҫɾ������ϵ�ˣ�");
		ifstream ifs;
		ifs.open("test.txt", ios::binary);
		if (!ifs) {
			std::cout << "�޷����ļ����ж�ȡ������" << std::endl;
		}
		vector<phone>v;
		int s1 = 0;
		for (int i = 0; i < m_number; i++)
		{
			phone p;
			ifs.read(reinterpret_cast<char*>(&p), sizeof(p));
			v.push_back(p);
			v[i].print2(s1);
			s1++;
		}
		ifs.close();
		MOUSEMSG m;
		int c = 0;
		while (1)
		{
			ExMessage msg;
			msg = getmessage(EM_MOUSE);
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 700 && msg.x <= 850 && msg.y >= 0 && msg.y <= 100)
				{
					print3();
				}
				if (msg.x >= 700 && msg.x <= 850 && msg.y >= 100 && msg.y <= 200)
				{
					c++;
					print3();
				}
				if (msg.x >= 700 && msg.x <= 850 && msg.y >= 200 && msg.y <= 300)
				{
					c += 2;
					print3();
				}
				if (msg.x >= 700 && msg.x <= 850 && msg.y >= 300 && msg.y <= 400)
				{
					c += 3;
					print3();
				}
				if (msg.x >= 400 && msg.x <= 650 && msg.y >= 400 && msg.y <= 500)
				{
					c += 4;
					print3();
				}
				if (msg.x >= 700 && msg.x <= 950 && msg.y >= 650 && msg.y <= 700)
				{
					menu();
				}
				if (msg.x >= 0 && msg.x <= 100 && msg.y >= 500 && msg.y <= 750)
				{
					v.erase(v.begin() + c);
					c--;
					m_number--;
					for (int i = 0; i <= c; i++)
					{
						if (c == 0)
						{
							break;
						}
						if (i == 0)
						{
							ofstream ofs;
							ofs.open("test.txt", ios::binary);
							if (!ofs) {
								std::cout << "�޷����ļ����ж�ȡ������" << std::endl;
								return;
							}
							ofs.write(reinterpret_cast<char*>(&v[i]), sizeof(v[i]));
							ofs.close();
						}
						else
						{
							ofstream ofs;
							ofs.open("test.txt", ios::app);
							if (!ofs) {
								std::cout << "�޷����ļ����ж�ȡ������" << std::endl;
								return;
							}
							ofs.write(reinterpret_cast<char*>(&v[i]), sizeof(v[i]));
							ofs.close();
						}
					}
					menu();
				}
				if (msg.x >= 1450 && msg.x <= 1550 && msg.y >= 500 && msg.y <= 750)
				{
					menu();
				}
				break;
			}
		}
	}

}
void::phone::incoming_call()
{

	setfillcolor(RGB(60, 179, 113));
	fillcircle(100, 400, 100);
	setfillcolor(RED);
	fillcircle(1400, 400, 100);
	settextcolor(RGB(0, 0, 0));
	settextstyle(60, 0, "�����ֺ��μ���");
	outtextxy(50, 380, "����");
	outtextxy(1350, 380, "�ܾ�");
	if (m_number == 0)
	{
		long long s = 0;
		int a;
		for (int i = 0; i < 11; i++)
		{
			if (i == 10)
			{
				a = 1;
			}
			else
			{
				a = rand() % 10;
			}
			s += a * pow(10, i);
		}
		char num[20];
		sprintf(num, "%lld", s);
		outtextxy(600, 200, num);
		outtextxy(400, 200, "İ������:");
	}
	else
	{
		settextstyle(100, 0, "�����ֺ��μ���");
		outtextxy(600,100,m_Name);
		settextstyle(80, 0, "�����ֺ��μ���");
		outtextxy(500, 200, m_Phone);
	}
	mciSendString("open resource/buffer/SYS.mp3 alias music", 0, 0, 0);
	mciSendString("play music", 0, 0, 0);
	MOUSEMSG m;
	while (1)
	{
		ExMessage msg;
		msg = getmessage(EM_MOUSE);
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			if (msg.x >= 50 && msg.x <= 170 && msg.y >= 280 && msg.y <= 480)
			{
				cleardevice();
				IMAGE img3;
				loadimage(&img3, "resource/img/img4.jpg", 1600, 820);
				putimage(0, 0, &img3);
				mciSendString("stop music", 0, 0, 0);
				mciSendString("open resource/buffer/����.mp3 alias music1", 0, 0, 0);
				mciSendString("play music1", 0, 0, 0);
				outtextxy(750, 650, "����");
			}
			if (msg.x >= 1350 && msg.x <= 1470 && msg.y >= 280 && msg.y <= 480)
			{
				mciSendString("stop music", 0, 0, 0);
				menu();
			}
			if (msg.x >= 700 && msg.x <= 950 && msg.y >= 650 && msg.y <= 700)
			{
				mciSendString("stop music1", 0, 0, 0);
				menu();
			}
		}
	}

}