#include "Game.h"

Snake::Snake(SHORT centerX, SHORT centerY) : motion(Motion::LEFT), snake(5), last()
{
	for (size_t i = 0; i < 5; ++i)
	{
		snake[i].X = centerX + (SHORT)i;
		snake[i].Y = centerY;
	}
}

void Snake::drow()
{
	textbackground(DARKGRAY);
	if (last.X != 0 && last.Y != 0)
	{
		gotoxy(last.X, last.Y);
		printf(" ");
	}
	textbackground(BLACK);
	gotoxy(snake[0].X, snake[0].Y);
	printf(" ");
	textbackground(LIGHTGREEN);
	for (size_t i = 1;i < snake.size(); ++i)
	{
		gotoxy(snake[i].X, snake[i].Y);
		printf(" ");
	}
	textbackground(BLACK);
}

void Snake::setmotion(Motion motion) { this->motion = motion; }
Motion Snake::getmotion() { return motion; }
COORD Snake::gethead() { return snake[0]; }
void Snake::render()
{
	if (snake[snake.size() - 1].X != 0 && snake[snake.size() - 1].Y != 0)
	{
		last.X = snake[snake.size() - 1].X;
		last.Y = snake[snake.size() - 1].Y;
	}
	for (size_t i = snake.size() - 1; i > 0; --i)
		snake[i] = snake[i - 1];
	switch (motion)
	{
	case Motion::UP: snake[0].Y--; break;
	case Motion::DOWN: snake[0].Y++; break;
	case Motion::LEFT: snake[0].X--; break;
	case Motion::RIGHT: snake[0].X++; break;
	}
}
void Snake::inc() { snake.push_back(COORD()); }
size_t Snake::size() { return snake.size(); }
bool Snake::inside(COORD pos)
{
	for (auto tail : snake)
		if (pos.X == tail.X && pos.Y == tail.Y) return true;
	return false;
}
bool Snake::inside()
{
	for (size_t i = 1; i < snake.size(); ++i)
		if (snake[0].X == snake[i].X && snake[0].Y == snake[i].Y) return true;
	return false;
}

//-------------------------------------------------------------------------------
Apple::Apple(SHORT width, SHORT height) : visible(false)
{
	pos.X = (SHORT)(rand() % width + 2);
	pos.Y = (SHORT)(rand() % height + 1);
}

void Apple::drow()
{
	textbackground(RED);
	gotoxy(pos.X, pos.Y);
	printf(" ");
	visible = true;
	textbackground(BLACK);
}

void Apple::randPos(SHORT width, SHORT height)
{
	gotoxy(pos.X, pos.Y);
	printf(" ");
	visible = false;
	pos.X = (SHORT)(rand() % width + 2);
	pos.Y = (SHORT)(rand() % height + 1);
}
COORD Apple::getPos() { return pos; }
bool Apple::getVisible() { return visible; }
//-------------------------------------------------------------------------------
Game::Game(SHORT width, SHORT height) : snake(width / 2 + 2, height / 2 + 1), apple(width, height), size()
{
	setwindow(width + 4, height + 2);
	size.X = width;
	size.Y = height;
}

bool Game::start(size_t snakeSize, Mode mode)
{
	system("cls");
	unsigned char c = 0;
	clrprt(2, 1, size.Y, size.X, DARKGRAY);
	clock_t sleeptime;
	switch (mode)
	{
	case Mode::EASY: sleeptime = 150; break;
	case Mode::STANDART: sleeptime = 100; break;
	case Mode::HARD: sleeptime = 50; break;
	}
	while (snake.size() < snakeSize)
	{
		clock_t begin = clock();
		if (_kbhit() != 0)
		{
			c = _getch();
			if (c == 224)
			{
				c = _getch();
				switch (c)
				{
				case 72: if (snake.getmotion() != Motion::DOWN) snake.setmotion(Motion::UP); break;
				case 80: if (snake.getmotion() != Motion::UP) snake.setmotion(Motion::DOWN); break;
				case 75: if (snake.getmotion() != Motion::RIGHT) snake.setmotion(Motion::LEFT); break;
				case 77: if (snake.getmotion() != Motion::LEFT) snake.setmotion(Motion::RIGHT); break;
				}
			}
			else if (c == 27) { ShowCursor(); return false; }
		}
		{
			COORD head = snake.gethead();
			if (head.X == 1 || head.X == size.X + 2 || head.Y == 0 || head.Y == size.Y + 1) { ShowCursor(); return false; }
		}
		if (snake.inside()) { ShowCursor(); return false; }
			if (snake.gethead().X == apple.getPos().X && snake.gethead().Y == apple.getPos().Y)
			{
				snake.inc();
				while (true)
				{
					apple.randPos(size.X, size.Y);
					if (!snake.inside(apple.getPos())) break;
				}
			}
		snake.render();
		if (!apple.getVisible()) apple.drow();
		snake.drow();
		clock_t end = clock();
		Sleep(sleeptime - (end - begin));
	}
	return true;
}