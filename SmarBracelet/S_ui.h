#pragma once
#pragma warning( disable : 4996 )
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include "health.h"
#include "operate.h"
using namespace std;

class ui {
private:
    sf::RenderWindow window;            // ������

    // ������ʾģ��
    sf::Font font1, font2;              // ����
    sf::Text l_time;                    // ʱ���ı�
    sf::Text l_date;                    // �����ı�
    sf::Text l_step_count;              // �����ı�
    int step_count = 0;                 // ��ʷ����
    sf::Text l_user_name;               // �û�����
    sf::Text l_heart_rate;              // ����
    sf::Text l_BMI;                     // ��֬��
    time_t now = time(0);               // ʱ��
    tm* ltm = localtime(&now);          // ��ǰʱ��

    // ���˵� ������ + ������
    sf::Sprite main_menu;               // ������-���˵�
    sf::Texture main_menu_img;          // ������-���˵�
    sf::Sprite health_menu;
    sf::Texture health_menu_img;
    sf::Sprite health_icon;
    sf::Texture health_icon_img;
    sf::Sprite address_book_menu;
    sf::Texture address_book_menu_img;
    sf::Sprite health_choice_menu;
    sf::Texture health_choice_menu_img;
    sf::Sprite heart_rate;
    sf::Texture heart_rate_img;

    sf::Sound heart_rate_effect;        // ��������Ч
    sf::SoundBuffer heart_rate_effect_; // ��������Ч-��Ƶ����

    health user;                        // ����ģ�������

    int d_main_menu();                  // Ĭ�Ͻ���-��ʾʱ��
    int d_health_menu();                // ��������-������Ϣ+�Ʋ�
    int d_address_book_menu();          // ͨѶ¼����-ͨѶ¼+�Ӵ�绰
    void d_health_choice_menu();        // ����ģ��-ѡ���ܽ���
    void d_health_heart_rate_menu();    // ����ģ��-������
    void d_address_book_choice_menu();  // ͨѶ¼ģ��-��ʾ��ϵ��
public:  
    ui() {
        // ��ȡʹ������Ϣ
        user.set_information("user", 20, 60, 170); 
        // ����һ��400*1000���ڣ���ֹ������С��֡��30
        window.create(sf::VideoMode(400, 1000), "SmarBracelet", sf::Style::Close);  
        window.setFramerateLimit(30);
    }
    void ui_main();               // uiѡ��
    void load_init();             // ����ͼ�����塢��Ƶ��Ĭ����ʾλ�õ���Դ
};

// ������-�л�����
void ui::ui_main() {
    sf::Event event;
    int ui_command, this_ui;
    this_ui = 0;
    int once = 1;
    while (true)
    {
        while (window.waitEvent(event))
        {
            // ��ҳ����
            if (once)
            {
                ui_command = d_main_menu();
                this_ui = 0;
                once = 0;
                continue;
            }
            else
                printf("this ui num:%d | ui_command:%d\n", this_ui, ui_command);
            if (this_ui == 0)  // �ڵ�һҳ��ʱ����棩
            {
                if (ui_command == 1)
                {
                    ui_command = d_health_menu();
                    this_ui = 1;
                    continue;
                }
                if (ui_command == 2)
                {
                    ui_command = d_address_book_menu();
                    this_ui = 2;
                    continue;
                }
                if (ui_command == 3)
                    return;
            }
            if (this_ui == 1)  // �ڵڶ�ҳ���������棩
            {
                if (ui_command == 1)
                {
                    ui_command = d_address_book_menu();
                    this_ui = 2;
                    continue;
                }
                if (ui_command == 2)
                {
                    ui_command = d_main_menu();
                    this_ui = 0;
                    continue;
                }
            }
            if (this_ui == 2)  // �ڵ���ҳ��ͨѶ¼���棩
            {
                if (ui_command == 1)
                {
                    ui_command = d_main_menu();
                    this_ui = 0;
                    continue;
                }
                if (ui_command == 2)
                {
                    ui_command = d_health_menu();
                    this_ui = 1;
                    continue;
                }
                if (ui_command == 3)
                    continue;
            }
        }
        if (!window.isOpen())
            return;
    }
}
// Ĭ�Ͻ���-��ʾʱ��
int ui::d_main_menu() {
    int command;
    sf::Event event;
    while (true)
    {
        window.pollEvent(event);   // �����¼�
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return -1;
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)  // ��⵽�������¼�ʱ
        {
            cout << "mouse pos:" << event.mouseButton.x << "   " << event.mouseButton.y << endl;
            command = isSlideScreen(event.mouseButton.x);
            if (command)
                return command;
            // func
        }
        // time func
        window.clear();
        now = time(0);
        ltm = localtime(&now);
        string min = to_string(ltm->tm_min);
        string sec = to_string(ltm->tm_sec);
        if (ltm->tm_min < 10)
            min = "0" + to_string(ltm->tm_min);
        if (ltm->tm_sec < 10)
            sec = "0" + to_string(ltm->tm_sec);
        l_time.setString(to_string(ltm->tm_hour) + ". " + min + ". " + sec);
        l_date.setString(to_string(1900 + ltm->tm_year) + ". " + to_string(1 + ltm->tm_mon) + ". " + to_string(ltm->tm_mday));
        window.draw(main_menu);   // �ڴ��ڻ��Ʊ���
        window.draw(l_time);
        window.draw(l_date);
        window.display();
    }
}
// ��������-������Ϣ+�Ʋ�
int ui::d_health_menu() {
    int command;
    sf::Event event;
    while (true)
    {
        window.waitEvent(event);
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return -1;
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            cout << "mouse pos:" << event.mouseButton.x << "   " << event.mouseButton.y << endl;
            command = isSlideScreen(event.mouseButton.x);
            if (command == 3)
            {
                d_health_choice_menu();
                // func:person information display...
            }
            else if (command)
                return command;
        }
        window.clear();
        window.draw(health_menu);
        window.display();
    }
}
// ͨѶ¼����-ͨѶ¼+�Ӵ�绰
int ui::d_address_book_menu() {
    int command;
    sf::Event event;
    while (true)
    {
        window.waitEvent(event);
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return -1;
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            cout << "mouse pos:" << event.mouseButton.x << "   " << event.mouseButton.y << endl;
            command = isSlideScreen(event.mouseButton.x);
            if (command == 3)
            {
                // int command_health = d_address_book_choice_menu();
                // func:person information display...
            }
            else if (command)
                return command;
            else
                continue;
        }
        window.clear();
        window.draw(address_book_menu);
        window.display();
    }
}
// ����ģ��-ѡ���ܽ���
void ui::d_health_choice_menu() {
    int command;
    sf::Event event;
    while (true)
    {
        window.clear();
        window.draw(health_choice_menu);
        window.draw(l_step_count);
        window.draw(l_user_name);
        window.draw(l_heart_rate);
        window.draw(l_BMI);
        window.display();
        window.waitEvent(event);
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return;
        }
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            cout << "mouse pos:" << event.mouseButton.x << "   " << event.mouseButton.y << endl;
            command = isHealthChoice(event.mouseButton.x, event.mouseButton.y);
            printf("health command:%d\n", command);
            if (command == 2)
            {
                d_health_heart_rate_menu();
            }
            if (command == 3)
            {
                step_count += user.Intelligence_Calculate_Steps();
                // ��֤һֱ������ʾ����
                sf::FloatRect textRect = l_step_count.getLocalBounds();
                l_step_count.setOrigin(textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);
                l_step_count.setPosition(sf::Vector2f(250, 835));
                l_step_count.setString(to_string(step_count));
            }
            else if (command == 5)
            {
                return;
            }
            else
                continue;
        }
        else
            continue;
        // health func
    }
}
// ����ģ��-������
void ui::d_health_heart_rate_menu() {
    sf::Event event;
    while (true)
    {
        window.waitEvent(event);
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return;
        }
        int* record;
        int val = 0;
        record = user.test_heart_rate();
        heart_rate_effect.play();
        for (int i = 0; i < 50; i++) 
        {
            _sleep(100);
            if (i % 5 == 0)
                heart_rate.setScale(*record / 200.0 + 1.0, *record / 200.0 + 1.0);
            val += *record;
            l_heart_rate.setString(to_string(*record));
            window.clear();
            window.draw(heart_rate);
            window.draw(l_heart_rate);
            window.display();
            record++;
        }
        val /= 50;
        l_heart_rate.setString(to_string(val));
        heart_rate.setScale(1.f, 1.f);
        return;
    }
}
// ͨѶ¼ģ��-��ʾ��ϵ��
void ui::d_address_book_choice_menu() {
    return;
    /*int command;
    sf::Event event;
    while (true)
    {
        window.clear();
        window.draw(health_choice_menu);
        window.display();
        window.waitEvent(event);
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return;
        }
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            cout << event.mouseButton.x << "   " << event.mouseButton.y << endl;
            command = isHealthChoice(event.mouseButton.x, event.mouseButton.y);
            if (command)
                return command;
        }
    }*/
}
// ����ͼ�����塢��Ƶ��Ĭ����ʾλ�õ���Դ
void ui::load_init() {
    // ������Ч
    {
        if (!heart_rate_effect_.loadFromFile("resource/buffer/heart_rate_effect.wav"))
        {
            // error...
        }
        heart_rate_effect.setBuffer(heart_rate_effect_);
    }
    // ��������
    {
        if (!font1.loadFromFile("resource/font/YeZiGongChangJingHongXingKai-2.ttf"))
        {
            // error...
        }
        if (!font2.loadFromFile("resource/font/Game Of Squids.ttf"))
        {
            // error...
        }
    }
    // ��ʼ���ı�(���塢��С����ʽ��λ��)
    {
        l_time.setFont(font2); l_time.setCharacterSize(50); l_time.setFillColor(sf::Color::White); l_time.setStyle(sf::Text::Regular); l_time.setPosition(sf::Vector2f(50, 50));
        l_date.setFont(font2); l_date.setCharacterSize(24); l_date.setFillColor(sf::Color::White); l_date.setStyle(sf::Text::Regular); l_date.setPosition(sf::Vector2f(200, 100));
        l_step_count.setFont(font1); l_step_count.setCharacterSize(50); l_step_count.setFillColor(sf::Color::White); l_step_count.setStyle(sf::Text::Regular); sf::FloatRect textRect = l_step_count.getLocalBounds(); l_step_count.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); l_step_count.setPosition(sf::Vector2f(250, 835)); /* <--���þ�����ʾ */ l_step_count.setString("-");
        l_user_name.setFont(font1); l_user_name.setCharacterSize(50); l_user_name.setFillColor(sf::Color::White); l_user_name.setStyle(sf::Text::Regular); l_user_name.setPosition(sf::Vector2f(160, 70));l_user_name.setString("Hi " + user.m_name);
        l_heart_rate.setFont(font1); l_heart_rate.setCharacterSize(50); l_heart_rate.setFillColor(sf::Color::White); l_heart_rate.setStyle(sf::Text::Regular); l_heart_rate.setPosition(sf::Vector2f(150, 237)); l_heart_rate.setString("---");
        l_BMI.setFont(font1); l_BMI.setCharacterSize(50); l_BMI.setFillColor(sf::Color::White); l_BMI.setStyle(sf::Text::Regular); l_BMI.setPosition(sf::Vector2f(150, 700)); l_BMI.setString(to_string(user.BMI));
    }
    // ����/�������� �趨λ��
    {
        // ʱ�����/Ĭ�ϲ˵�
        if (!main_menu_img.loadFromFile("resource/img/bg_main.png"))
        {
            // error...
        }
        main_menu.setTexture(main_menu_img);  // ��������
        main_menu.setPosition(sf::Vector2f(0, 0));  // ���ó�ʼλ��

        // ��������
        if (!health_menu_img.loadFromFile("resource/img/bg_health.png"))
        {
            // error...
        }
        health_menu.setTexture(health_menu_img);
        health_menu.setPosition(sf::Vector2f(0, 0));

        // ��������ͼ��
        if (!health_icon_img.loadFromFile("resource/img/health_icon.png"))
        {
            // error...
        }
        health_icon.setTexture(health_icon_img);
        health_icon.setPosition(sf::Vector2f(72, 372));

        // ͨѶ¼����
        if (!address_book_menu_img.loadFromFile("resource/img/bg_address_book.png"))
        {
            // error...
        }
        address_book_menu.setTexture(address_book_menu_img);
        address_book_menu.setPosition(sf::Vector2f(0, 0));

        // ����ģ��-ѡ���ܽ���
        if (!health_choice_menu_img.loadFromFile("resource/img/bg_health_choice.png"))
        {
            // error...
        }
        health_choice_menu.setTexture(health_choice_menu_img);
        health_choice_menu.setPosition(sf::Vector2f(0, 0));

        // �Ʋ���tom
        if (!user.user_person_img.loadFromFile("resource/img/person_bg.png"))
        {
            // error...
        }
        user.user_person_img.setSmooth(true);
        user.user_person.setTexture(user.user_person_img);
        user.user_person.setPosition(sf::Vector2f(350, 500));

        // �Ʋ���map
        if (!user.map_img.loadFromFile("resource/img/go_map.jpg"))
        {
            // error...
        }
        user.map.setTexture(user.map_img);
        user.map.setPosition(sf::Vector2f(0, 0));

        // ����ͼ��
        if (!heart_rate_img.loadFromFile("resource/img/heart_rate_icon.png"))
        {
            // error...
        }
        heart_rate.setTexture(heart_rate_img);
        sf::FloatRect textRect = heart_rate.getLocalBounds();
        heart_rate.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        heart_rate.setPosition(sf::Vector2f(200, 500));
    }
}
