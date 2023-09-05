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
    sf::RenderWindow window;            // 窗口类

    // 文字显示模块
    sf::Font font1, font2;              // 字体
    sf::Text l_time;                    // 时间文本
    sf::Text l_date;                    // 日期文本
    sf::Text l_step_count;              // 步数文本
    int step_count = 0;                 // 历史步数
    sf::Text l_user_name;               // 用户姓名
    sf::Text l_heart_rate;              // 心率
    sf::Text l_BMI;                     // 体脂率
    time_t now = time(0);               // 时间
    tm* ltm = localtime(&now);          // 当前时间

    // 各菜单 精灵类 + 纹理类
    sf::Sprite main_menu;               // 精灵类-主菜单
    sf::Texture main_menu_img;          // 纹理类-主菜单
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

    sf::Sound heart_rate_effect;        // 测心率音效
    sf::SoundBuffer heart_rate_effect_; // 测心率音效-音频数据

    health user;                        // 健康模块核心类

    int d_main_menu();                  // 默认界面-显示时间
    int d_health_menu();                // 健康界面-个人信息+计步
    int d_address_book_menu();          // 通讯录界面-通讯录+接打电话
    void d_health_choice_menu();        // 健康模块-选择功能界面
    void d_health_heart_rate_menu();    // 健康模块-测心率
    void d_address_book_choice_menu();  // 通讯录模块-显示联系人
public:  
    ui() {
        // 读取使用者信息
        user.set_information("user", 20, 60, 170); 
        // 创建一个400*1000窗口，禁止调整大小，帧率30
        window.create(sf::VideoMode(400, 1000), "SmarBracelet", sf::Style::Close);  
        window.setFramerateLimit(30);
    }
    void ui_main();               // ui选择
    void load_init();             // 加载图像、字体、音频、默认显示位置等资源
};

// 主函数-切换界面
void ui::ui_main() {
    sf::Event event;
    int ui_command, this_ui;
    this_ui = 0;
    int once = 1;
    while (true)
    {
        while (window.waitEvent(event))
        {
            // 翻页功能
            if (once)
            {
                ui_command = d_main_menu();
                this_ui = 0;
                once = 0;
                continue;
            }
            else
                printf("this ui num:%d | ui_command:%d\n", this_ui, ui_command);
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
        if (!window.isOpen())
            return;
    }
}
// 默认界面-显示时间
int ui::d_main_menu() {
    int command;
    sf::Event event;
    while (true)
    {
        window.pollEvent(event);   // 捕获事件
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return -1;
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)  // 检测到鼠标左击事件时
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
        window.draw(main_menu);   // 在窗口绘制背景
        window.draw(l_time);
        window.draw(l_date);
        window.display();
    }
}
// 健康界面-个人信息+计步
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
// 通讯录界面-通讯录+接打电话
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
// 健康模块-选择功能界面
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
                // 保证一直居中显示步数
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
// 健康模块-测心率
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
// 通讯录模块-显示联系人
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
// 加载图像、字体、音频、默认显示位置等资源
void ui::load_init() {
    // 加载音效
    {
        if (!heart_rate_effect_.loadFromFile("resource/buffer/heart_rate_effect.wav"))
        {
            // error...
        }
        heart_rate_effect.setBuffer(heart_rate_effect_);
    }
    // 载入字体
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
    // 初始化文本(字体、大小、格式、位置)
    {
        l_time.setFont(font2); l_time.setCharacterSize(50); l_time.setFillColor(sf::Color::White); l_time.setStyle(sf::Text::Regular); l_time.setPosition(sf::Vector2f(50, 50));
        l_date.setFont(font2); l_date.setCharacterSize(24); l_date.setFillColor(sf::Color::White); l_date.setStyle(sf::Text::Regular); l_date.setPosition(sf::Vector2f(200, 100));
        l_step_count.setFont(font1); l_step_count.setCharacterSize(50); l_step_count.setFillColor(sf::Color::White); l_step_count.setStyle(sf::Text::Regular); sf::FloatRect textRect = l_step_count.getLocalBounds(); l_step_count.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); l_step_count.setPosition(sf::Vector2f(250, 835)); /* <--设置居中显示 */ l_step_count.setString("-");
        l_user_name.setFont(font1); l_user_name.setCharacterSize(50); l_user_name.setFillColor(sf::Color::White); l_user_name.setStyle(sf::Text::Regular); l_user_name.setPosition(sf::Vector2f(160, 70));l_user_name.setString("Hi " + user.m_name);
        l_heart_rate.setFont(font1); l_heart_rate.setCharacterSize(50); l_heart_rate.setFillColor(sf::Color::White); l_heart_rate.setStyle(sf::Text::Regular); l_heart_rate.setPosition(sf::Vector2f(150, 237)); l_heart_rate.setString("---");
        l_BMI.setFont(font1); l_BMI.setCharacterSize(50); l_BMI.setFillColor(sf::Color::White); l_BMI.setStyle(sf::Text::Regular); l_BMI.setPosition(sf::Vector2f(150, 700)); l_BMI.setString(to_string(user.BMI));
    }
    // 加载/设置纹理 设定位置
    {
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

        // 健康界面图标
        if (!health_icon_img.loadFromFile("resource/img/health_icon.png"))
        {
            // error...
        }
        health_icon.setTexture(health_icon_img);
        health_icon.setPosition(sf::Vector2f(72, 372));

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

        // 计步器tom
        if (!user.user_person_img.loadFromFile("resource/img/person_bg.png"))
        {
            // error...
        }
        user.user_person_img.setSmooth(true);
        user.user_person.setTexture(user.user_person_img);
        user.user_person.setPosition(sf::Vector2f(350, 500));

        // 计步器map
        if (!user.map_img.loadFromFile("resource/img/go_map.jpg"))
        {
            // error...
        }
        user.map.setTexture(user.map_img);
        user.map.setPosition(sf::Vector2f(0, 0));

        // 心率图标
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
