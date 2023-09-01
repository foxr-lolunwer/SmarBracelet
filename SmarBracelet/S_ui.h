#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string.h>
#include <ctime>
#include "health.h"
#include "operate.h"
#pragma warning( disable : 4996 )
using namespace std;

class ui {
private:
    sf::RenderWindow window;            // 窗口类
    //sf::Event event;                    // 事件类
    sf::Font font1, font2;              // 字体
    sf::Text l_time;                    // 时间文本
    sf::Text l_date;                    // 日期文本
    time_t now = time(0);               // 时间
    tm* ltm = localtime(&now);          // 当前时间
    sf::Sprite main_menu;               // 精灵类-主菜单
    sf::Texture main_menu_img;          // 纹理类-主菜单
    sf::Sprite health_menu;
    sf::Texture health_menu_img;
    sf::Sprite address_book_menu;
    sf::Texture address_book_menu_img;
    sf::Sprite health_choice_menu;
    sf::Texture health_choice_menu_img;
    sf::Sound call_phone;               // 打电话音效
    sf::SoundBuffer call_phone_buffer;  // 打电话音效-音频数据
    int d_main_menu();                  // 主界面-显示时间
    int d_health_menu();                // 健康界面-个人信息+计步
    int d_address_book_menu();          // 通讯录界面-通讯录+接打电话
    int d_health_choice_menu();         // 健康模块选择功能界面
public:
    ui() {
        // 创建一个400*1000窗口，禁止调整大小，帧率30
        window.create(sf::VideoMode(400, 1000), "SmarBracelet", sf::Style::Close);  
        window.setFramerateLimit(30);
    }
    void ui_main();               // ui选择
    void load_init();             // 加载图像、字体、音频、默认显示位置等资源
};

void ui::ui_main() {
    sf::Event event;
    int ui_command, this_ui;
    this_ui = 0;
    int once = 1;
    time_t now = time(0);
    // tm* ltm = localtime(&now);
    /*ltm->tm_year += 1900;
    ltm->tm_mon += 1;*/
    string today_time;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {

            // 翻页功能
            if (once)
            {
                ui_command = d_main_menu();
                this_ui = 0;
                once = 0;
                continue;
            }
            if (this_ui == 0)  // 在第一页（时间界面）
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
            if (this_ui == 1)  // 在第二页（健康界面）
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
            if (this_ui == 2)  // 在第三页（通讯录界面）
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
    }
}

int ui::d_main_menu() {
    int command;
    sf::Event event;
    while (true)
    {
        window.pollEvent(event);   // 捕获事件
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)  // 检测到鼠标左击事件时
        {
            cout << event.mouseButton.x << "   " << event.mouseButton.y << endl;
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
        window.draw(main_menu);   // 在窗口绘制背景
        window.draw(l_time);
        window.draw(l_date);
        window.display();
    }
}

int ui::d_health_menu() {
    int command;
    sf::Event event;
    while (true)
    {
        window.waitEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            cout << event.mouseButton.x << "   " << event.mouseButton.y << endl;
            command = isSlideScreen(event.mouseButton.x);
            if (command == 3)
            {
                event.mouseButton.button == sf::Mouse::Right;
                int command_health = d_health_choice_menu();
                printf("%d\n", command_health);
                if (command_health == 1)
                {
                    // ...
                }
                else if (command_health == 2)
                {
                    // ...
                }
                else
                    continue;
            }
            else if (command)
                return command;
            else
                continue;
            // health func
        }
        window.clear();
        window.draw(health_menu);
        window.display();
    }
}

int ui::d_address_book_menu() {
    int command;
    sf::Event event;
    while (true)
    {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            cout << event.mouseButton.x << "   " << event.mouseButton.y << endl;
            command = isSlideScreen(event.mouseButton.x);
            if (command)
                return command;
            // address_book func
        }
        window.clear();
        window.draw(address_book_menu);
        window.display();
    }
}

int ui::d_health_choice_menu() {
    int command;
    sf::Event event;
    while (true)
    {
        window.clear();
        window.draw(health_choice_menu);
        window.display();
        window.waitEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            cout << event.mouseButton.x << "   " << event.mouseButton.y << endl;
            command = isHealthChoice(event.mouseButton.y);
            if (command)
                return command;
        }
        
    }
}

void ui::load_init() {
    // 加载音效
    if (!call_phone_buffer.loadFromFile("resource/buffer/call_phone.ogg"))
    {
        // error...
    }
    call_phone.setBuffer(call_phone_buffer);

    // 载入字体
    if (!font1.loadFromFile("resource/font/arial.ttf"))
    {
        // error...
    }
    if (!font2.loadFromFile("resource/font/Game Of Squids.ttf"))
    {
        // error...
    }
    // 初始化文本(字体、大小、格式、位置)
    l_time.setFont(font2);
    l_date.setFont(font2);
    l_time.setCharacterSize(50);
    l_date.setCharacterSize(24);
    l_time.setFillColor(sf::Color::White);
    l_date.setFillColor(sf::Color::White);
    l_time.setStyle(sf::Text::Regular);
    l_date.setStyle(sf::Text::Regular);
    l_time.setPosition(sf::Vector2f(50, 50));
    l_date.setPosition(sf::Vector2f(200, 100));

    // 时间界面/默认菜单
    if (!main_menu_img.loadFromFile("resource/img/bg_main.png"))
    {
        // error...
    }
    main_menu.setTexture(main_menu_img);  // 设置纹理
    main_menu.setPosition(sf::Vector2f(0, 0));  // 设置初始位置

    // 健康界面
    if (!health_menu_img.loadFromFile("resource/img/bg_health.png"))
    {
        // error...
    }
    health_menu.setTexture(health_menu_img);
    health_menu.setPosition(sf::Vector2f(0, 0));

    // 通讯录界面
    if (!address_book_menu_img.loadFromFile("resource/img/bg_address_book.png"))
    {
        // error...
    }
    address_book_menu.setTexture(address_book_menu_img);
    address_book_menu.setPosition(sf::Vector2f(0, 0));

    // 健康模块-选择功能界面
    if (!health_choice_menu_img.loadFromFile("resource/img/bg_health_choice.png"))
    {
        // error...
    }
    health_choice_menu.setTexture(health_choice_menu_img);
    health_choice_menu.setPosition(sf::Vector2f(0, 0));
}
