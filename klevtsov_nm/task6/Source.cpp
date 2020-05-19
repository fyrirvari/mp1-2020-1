#include "Game.h"
#include <time.h>

std::pair<size_t, Mode> startMenu();

int main(void)
{
	srand(time(NULL));
	while (true)
	{
		HideCursor();
		std::pair<size_t, Mode> settings = startMenu();
		Game game(50, 25);
		if (game.start(settings.first, settings.second)) { system("cls"); std::cout << "Applause" << std::endl; }
		else { system("cls"); std::cout << "Game over" << std::endl; }
		system("pause");
		ShowCursor();
	}
	return 0;
}

std::pair<size_t, Mode> startMenu()
{
	system("cls");
	std::pair<size_t, Mode> settings = std::pair<size_t, Mode>(75, Mode::STANDART);
	std::vector<Button> buttons = { Button("Start", true), Button("Settings"), Button("Exit") };
	int modenum;
	while (true)
	{
		int id = ButtonsDrawing::ClickListener(buttons, 25);
		switch (id)
		{
		case 0: return settings; break;
		case 1:
			system("cls");
			std::cout << "Enter snake size: ";
			std::cin >> settings.first;
			std::cout << "Change mode (0:Easy 1:Standart 2:Hard): ";
			std::cin >> modenum;
			settings.second = modenum == 0 ? Mode::EASY : modenum == 1 ? Mode::STANDART : Mode::HARD;
			break;
		default: exit(0); break;
		}
	}
}
