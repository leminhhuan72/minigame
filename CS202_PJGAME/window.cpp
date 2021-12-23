#include "window.h"
#include <iostream>
#include <Windows.h>

using Console::gotoXY;

Window::Window()
{
	// set cursor off
	CONSOLE_CURSOR_INFO lpCursor;
	GetConsoleCursorInfo(HOUT, &lpCursor);
	lpCursor.bVisible = 0;
	SetConsoleCursorInfo(HOUT, &lpCursor);
}

Window::Window(Point upper, Point lower):upper_left(upper), lower_right(lower)
{
}


Window::~Window()
{
}

void Window::turn_on_reverse_color()
{
	SetConsoleTextAttribute(HOUT, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}


void Window::turn_off_reverse_color()
{
	SetConsoleTextAttribute(HOUT, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

bool Window::contain(Point p)
{
	return upper_left.x < p.x && p.x < lower_right.x && upper_left.y < p.y && p.y < lower_right.y;
}

bool Window::contain(std::shared_ptr<Entity> entity)
{
	//for player
	if (entity->type_name() == "Player") {
		for (auto pixel : entity->pixels) {
			pixel += entity->location;
			if (!contain(pixel)) return false;
		}
		return true;
	}

	for (auto pixel : entity->pixels) {
		pixel += entity->location;
		if (contain(pixel)) return true;
	}
	return false;
}


void Window::draw_full_rect(char c)
{
	for (int x = upper_left.x; x <= lower_right.x; ++x) {
		gotoXY(x, upper_left.y);
		for (int y = upper_left.y; y <= lower_right.y; ++y) std::cout << c;
	}
}

void Window::draw_rect(char c)
{
	for (int x = upper_left.x; x <= lower_right.x; ++x) {
		gotoXY(x, upper_left.y);
		std::cout << c;
		gotoXY(x, lower_right.y);
		std::cout << c;
	}
	for (int y = upper_left.y + 1; y < lower_right.y; ++y) {
		gotoXY(upper_left.x, y);
		std::cout << c;
		gotoXY(lower_right.x, y);
		std::cout << c;
	}
}

void Window::draw_road_marking(bool first, bool last)
{
	for (int y = upper_left.y + 1; y < lower_right.y; ++y) {
		gotoXY(upper_left.x, y);
		if (!first) {
			if ((y - upper_left.y - 1) % 25 == 0 || (y - upper_left.y - 1 + 5) % 25 == 0)
				std::cout << "|";
			else if ((y - upper_left.y - 1 + 5) % 25 <= 5)
				std::cout << " ";
			else
				std::cout << "_";
		}
		else
			std::cout << "#";

		gotoXY(lower_right.x, y);
		if (!last) {
			if ((y - upper_left.y - 1 + 5) % 25 <= 5)
				std::cout << " ";
			else
				std::cout << "_";
		}
		else
			std::cout << "#";
	}
}

void Window::draw_entity(std::shared_ptr<Entity> entity, bool isErase)
{
	for (auto pixel : entity ->pixels) {
		pixel += entity -> location;
		if (!contain(pixel)) continue;
		gotoXY(pixel.x, pixel.y);
		Console::SetColor(pixel.color);
		if (!isErase) putchar(pixel.c);
		else putchar(' ');
		Console::SetColor(COLOR::WHITE);
	}
}





void Window::print_center_align(std::string st, int line)
{
	int y = ((lower_right.y + upper_left.y) - st.size()) / 2;
	gotoXY(line, y);
	std::cout << st.c_str();
}


void Window::set_pos(Point upper, Point lower) {
	upper_left = upper, lower_right = lower;
}

void Window::import_from_file(std::ifstream & fi)
{
	upper_left.import_from_file(fi);
	lower_right.import_from_file(fi);
}

void Window::export_to_file(std::ofstream & fo)
{
	upper_left.export_to_file(fo);
	lower_right.export_to_file(fo);
}
