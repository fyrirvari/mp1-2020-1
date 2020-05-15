#pragma once
#include <windows.h>
#include <stdio.h>
#include <memory.h>
#include <conio.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

enum TColor {
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
	DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED,
	LIGHTMAGENTA, YELLOW, WHITE
};

class Button
{
private:
	std::string title;
	bool state;
public:
	Button(std::string title, bool state = false);
	Button(const Button&);
	~Button();

	void setTitle(const std::string&);
	void setState(bool);
	std::string getTitle(void);
	bool getState(void);

	Button& operator=(const Button&);
};

class ButtonsDrawing
{
private:
	static void Render(std::vector<Button> buttons, int titlelength, int marginleft, int margintop);
public:
	static int ClickListener(std::vector<Button> buttons, int titlelength = 50, int marginleft = 0, int margintop = 0);
};


int wherex(void);
int wherey(void);
COORD WhereXY(void);
void clrscr(void);
void gotoxy(int x, int y);
void textcolor(int color);
void textbackground(int color);
void textattr(int color);
void setwindow(int width, int height);
void SetWindow(SMALL_RECT rect, COORD size);
void GetWindow(SMALL_RECT *rect, COORD *size);
void HideCursor(void);
void ShowCursor(void);
void clrprt(int x, int y, int strings, int columns, TColor color = LIGHTGRAY);