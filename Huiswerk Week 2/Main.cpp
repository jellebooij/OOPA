#include <iostream>
#include "GridPainter.h"
#include "Grid.h"
#include <thread>
#include <windows.h>
#include "BasicRule.h"

void clear_screen(char fill = ' ') {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}

int main() {

	Grid manhatan(25,10);
	GridPainter rembrand;
	BasicRule ahBasic;



	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		clear_screen();
		manhatan.Update(ahBasic);
		rembrand.DrawGrid(manhatan);

		
	}
	
	
	std::cout << manhatan.countNeighbours(0,0);
	std::cin.get();
	return 0;
}



