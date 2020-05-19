#pragma once
#include "../library/Console.h"
#include <iostream>

enum class Motion { UP, DOWN, LEFT, RIGHT };
enum class Mode { EASY, STANDART, HARD };

class Object
{
public:
	virtual void drow() = 0;
};

//-------------------------------------------------------------------------------
class Snake : public Object
{
private:
	Motion motion;
	std::vector<COORD> snake;
	COORD last;
public:
	Snake(SHORT centerX, SHORT centerY);
	void drow();
	void setmotion(Motion motion);
	Motion getmotion();
	COORD gethead();
	void render();
	void inc();
	size_t size();
	bool inside(COORD pos);
	bool inside();
};

class Apple : public Object
{
private:
	COORD pos;
	bool visible;
public:
	Apple(SHORT width, SHORT height);
	void drow();
	void randPos(SHORT width, SHORT height);
	COORD getPos();
	bool getVisible();
};
//-------------------------------------------------------------------------------
class Game
{
private:
	Snake snake;
	Apple apple;
	COORD size;
public:
	Game(SHORT width, SHORT height);
	bool start(size_t snakeSize, Mode mode = Mode::STANDART);
};