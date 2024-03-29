#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

// 是否切换界面/选择功能
int isSlideScreen(int x) {
	// 向右翻页
	if (x >= 300 && x <= 400)
		return 1;
	// 向左翻页
	if (x >= 0 && x <= 100)
		return 2;
	// 选择该功能
	if (x > 100 && x < 300)
		return 3;
	// 没有在屏幕内点击
    return 0;
}

// 健康选择界面判断选择内容
int isHealthChoice(int x , int y) {
	// 姓名
	if (x >= 36 && x <= 146 && y >= 45 && y <= 155)
		return 1;
	// 心率
	if (x >= 259 && x <= 369 && y >= 207 && y <= 317)
		return 2;
	// 计步
	if (x >= 40 && x <= 150 && y >= 780 && y <= 890)
		return 3;
	// 体脂
	if (x >= 255 && x <= 365 && y >= 670 && y <= 880)
		return 4;
	// 返回
	if (x >= 20 && x <= 130 && y >= 527 && y <= 637)
		return 5;
	return 0;
}
