#pragma once

#include<string>

enum ScreenState
{
	GAME_START1,
	FLOOR_11,
	FLOOR_21,
	FLOOR_31,
	BATTLE1,
	VICTORY1,
	DEFEAT1
};

class Screen
{
protected:
	int screenX;
	int screenY;
	int backgroundSizeX;
	int backgroundSizeY;
	std::string windowName;
	ScreenState screenState;

public:

	Screen();
	Screen(std::string windowName, ScreenState screenState);

	int getScreenX();
	int getScreenY();
	int getBackgroundSizeX();
	int getBackgroundSizeY();
	std::string getWindowName();
	int getScreenState();

};

