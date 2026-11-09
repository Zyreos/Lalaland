#include "./Headers/screen.h"

Screen::Screen()
	:screenX(800),
	screenY(600),
	backgroundSizeX(64),
	backgroundSizeY(64),
	windowName("GAME_START"),
	screenState(GAME_START1)
{ }

Screen::Screen(std::string windowName, ScreenState screenState)
	:screenX(800),
	screenY(600),
	backgroundSizeX(64),
	backgroundSizeY(64),
	windowName(windowName),
	screenState(screenState)
{ }

int Screen::getScreenX()
{
	return screenX;
}
int Screen::getScreenY()
{
	return screenY;
}
