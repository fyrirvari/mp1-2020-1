#include "Console.h"

Button::Button(std::string title, bool state) : title(title), state(state) {}
Button::Button(const Button& other) : title(other.title), state(other.state) {}
Button::~Button() {}

void Button::setTitle(const std::string& title) { this->title = title; }
void Button::setState(bool state) { this->state = state; }
std::string Button::getTitle(void) { return title; }
bool Button::getState(void) { return state; }

Button& Button::operator=(const Button& other)
{
	this->title = other.title;
	this->state = other.state;
	return *this;

}

//---------------------------------------------------------------------------------------
void ButtonsDrawing::Render(std::vector<Button> buttons, int titlelength, int marginleft, int margintop)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i].getState()) textattr(RED);
		else textattr(YELLOW);
		for (int k = 0; k < 3; k++)
		{
			gotoxy(marginleft, margintop + k + 4 * i);
			std::stringstream ss;
			if (k == 1) ss << std::setw(titlelength) << " " << buttons[i].getTitle();
			else ss << std::setw(titlelength) << " ";
			puts(ss.str().c_str());
		}
	}
}

int ButtonsDrawing::ClickListener(std::vector<Button> buttons, int titlelength, int marginleft, int margintop)
{
	unsigned char c = 0;
	bool changed = true;
	int id = 0;
	while (true)
	{
		if (_kbhit() != 0)
		{
			c = _getch();
			if (c == 224 || c == 0) c = _getch();
			else if (c == 13) return id;
			else continue;
			buttons[id].setState(false);
			if (c == 72 && id > 0) { id--; changed = true; }
			else if (c == 80 && id < buttons.size() - 1) { id++; changed = true; }
			buttons[id].setState(true);
			if (changed) { Render(buttons, titlelength, marginleft, margintop); changed = false; }
		}
	}
}
//-----------------------------------------------------------------------------
int wherex(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return -1;

  CONSOLE_SCREEN_BUFFER_INFO buf;

  GetConsoleScreenBufferInfo(Console, &buf);
  return buf.dwCursorPosition.X;
}

//-----------------------------------------------------------------------------
int wherey(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return - 1;

  CONSOLE_SCREEN_BUFFER_INFO buf;

  GetConsoleScreenBufferInfo(Console, &buf);
  return buf.dwCursorPosition.Y;
}

//-----------------------------------------------------------------------------
COORD WhereXY(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD pos = {-1, -1};
  if (!Console)
    return pos;

  CONSOLE_SCREEN_BUFFER_INFO buf;

  GetConsoleScreenBufferInfo(Console, &buf);
  return buf.dwCursorPosition;
}

//-----------------------------------------------------------------------------
void clrscr(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_SCREEN_BUFFER_INFO buf;
  GetConsoleScreenBufferInfo(Console, &buf);

  WORD Attr;
  DWORD Count;
  COORD pos = buf.dwCursorPosition;
  ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

  int col = Attr;
  int width = buf.dwSize.X;
  int height = buf.dwSize.Y;

  COORD zpos;
  zpos.X = 0;
  zpos.Y = 0;
  SetConsoleCursorPosition(Console, zpos);

  FillConsoleOutputAttribute(Console, col, width * height, zpos, &Count);
  FillConsoleOutputCharacter(Console, ' ', width * height, zpos, &Count);
}

//-----------------------------------------------------------------------------
void gotoxy(int x, int y)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  COORD pos;
  pos.X = x;
  pos.Y = y;

  SetConsoleCursorPosition(Console, pos);
}

//-----------------------------------------------------------------------------
void textcolor(int color)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_SCREEN_BUFFER_INFO buf;
  GetConsoleScreenBufferInfo(Console, &buf);

  WORD Attr;
  DWORD Count;
  COORD pos = buf.dwCursorPosition;
  ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

  int bk_col = Attr / 16;
  int col = color % 16;
  col = col + bk_col * 16;

  SetConsoleTextAttribute(Console, col);

  char ch;
  pos = WhereXY();
  ReadConsoleOutputCharacter(Console, &ch, 1, pos, &Count);
  printf("%c", ch);
  gotoxy(pos.X, pos.Y);
}

//-----------------------------------------------------------------------------
void textbackground(int color)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_SCREEN_BUFFER_INFO buf;
  GetConsoleScreenBufferInfo(Console, &buf);

  WORD Attr;
  DWORD Count;
  COORD pos = buf.dwCursorPosition;
  ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

  int text_col = Attr % 16;
  int col = color % 16;
  col = color * 16 + text_col;

  SetConsoleTextAttribute(Console, col);

  char ch;
  pos = WhereXY();
  ReadConsoleOutputCharacter(Console, &ch, 1, pos, &Count);
  printf("%c", ch);
  gotoxy(pos.X, pos.Y);
}

//-----------------------------------------------------------------------------
void textattr(int color)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  SetConsoleTextAttribute(Console, color);

  DWORD Count;
  char ch;
  COORD pos = WhereXY();
  ReadConsoleOutputCharacter(Console, &ch, 1, pos, &Count);
  printf("%c", ch);
  gotoxy(pos.X, pos.Y);
}

//-----------------------------------------------------------------------------
void setwindow(int width, int height)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  SMALL_RECT rect;
  rect.Left = 0;
  rect.Right = width - 1;
  rect.Top= 0;
  rect.Bottom = height - 1;
  COORD size;
  size.X = width;
  size.Y = height;
  SetConsoleWindowInfo(Console, true, &rect);
//  printf("%d %d %d %d", rect.Left, rect.Top, rect.Right, rect.Bottom);
  SetConsoleScreenBufferSize(Console, size);
//  printf("%d %d", size.X, size.Y);
}

//-----------------------------------------------------------------------------
void SetWindow(SMALL_RECT rect, COORD size)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  SetConsoleScreenBufferSize(Console, size);
  SetConsoleWindowInfo(Console, true, &rect);
}

//-----------------------------------------------------------------------------
void GetWindow(SMALL_RECT *rect, COORD *size)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_SCREEN_BUFFER_INFO buf;
  GetConsoleScreenBufferInfo(Console, &buf);

  *rect = buf.srWindow;
  size->X = buf.dwSize.X;
  size->Y = buf.dwSize.Y;
}

//-----------------------------------------------------------------------------
void HideCursor(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_CURSOR_INFO buf;
  GetConsoleCursorInfo(Console, &buf);
  buf.bVisible = false;
  SetConsoleCursorInfo(Console, &buf);
}

//-----------------------------------------------------------------------------
void ShowCursor(void)
{
  HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (!Console)
    return;

  CONSOLE_CURSOR_INFO buf;
  GetConsoleCursorInfo(Console, &buf);
  buf.bVisible = true;
  SetConsoleCursorInfo(Console, &buf);
}

//-----------------------------------------------------------------------------
void clrprt(int x, int y, int strings, int columns, TColor color)
{
	textattr(color);
	for (int i = 0; i < strings; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			gotoxy(x + j, y + i);
			printf(" ");
		}
	}
}

//-----------------------------------------------------------------------------