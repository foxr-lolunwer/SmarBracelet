#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

int isSlideScreen(int x) {
	if (x >= 300 && x <= 400)
		return 1;
	else if (x >= 0 && x <= 100)
		return 2;
	else if (x > 100 && x < 300)
		return 3;
	else
		return 0;
}

int isHealthChoice(int y) {
	if (y < 300 && y >= 0)
		return 1;
	else if (y >= 300 && y < 600)
		return 2;
	else if (y >= 600 && y < 1000)
		return 3;
	else
		return 0;
}
