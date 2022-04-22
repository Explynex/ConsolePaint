#include "DevAttribute\devattribute.h"

int main() {
	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
	HWND wh = getConsoleHwnd();
	setConsoleFullscreen();
	utf.setUtfLocale();
	RECT r;
	POINT p;
	int posX, posY, inputColor = 15;
	bool buttoninput1 = 0,buttoninput2=0,buttoninput3=0,buttoninput4=0,erase=0;
	GotoXY(50, 1, "CONSOLE PAINT",YELLOW,BLACK);
	GotoXY(50, 2, "Explyne ©", YELLOW, BLACK);
	std::string brush[10] = { "█","•","☼","#","¶","■","♥","♦","Ø","@"};
	int pointer = 0;
	while (true) {
		showConsoleCursor(false);
		sheetGenerator(0, 0, 5, 1, 8, 2);
		GotoXY(3, 1, "EXIT",BROWN,BLACK);
		GotoXY(4, 2, "←-",BROWN,BLACK);
		GotoXY(20, 1, "ERASER", BROWN, BLACK);
		GotoXY(22, 2, "¤¤", BROWN, BLACK);
		GotoXY(11, 1, "CLEAR", BROWN, BLACK);
		GotoXY(14, 2, "ALL", BROWN, BLACK);
		GotoXY(39, 1, "BRUSH", BROWN, BLACK);
		GotoXY(39, 2, "[   ]", WHITE, BLACK);
		consoleColor color = static_cast<consoleColor>(inputColor);
		GotoXY(41, 2, brush[pointer],color,BLACK);
		int maxXPos = getConsoleSize("width");
		cleaning(29, 1, 2, 6, LIGHTGRAY, color);
		while (true) {
			GetWindowRect(wh, &r);
			GetCursorPos(&p);
			posX = ((p.x - r.left) / 8);
			posY = ((p.y - r.top) / 16);
			if (posX >= 0 && posX < maxXPos - 1 && posY >= 4 && GetKeyState(VK_LBUTTON) < 0) {
				if(erase == 0)
				GotoXY(posX, posY,brush[pointer], color, BLACK);
				else GotoXY(posX, posY,brush[pointer], BLACK, BLACK);
			}
			if (posX >= 29 && posX <= 35 && posY >= 1 && posY <= 2) {
				if (GetKeyState(VK_LBUTTON) < 0) {
					inputColor--;
					if (inputColor == -1) inputColor = 15;
				}
				if (GetKeyState(VK_RBUTTON) < 0) {
					inputColor++;
					if (inputColor == 16) inputColor = 0;
				}
				Sleep(80);
				break;
			}
			if (posX >= 2 && posX <= 9 && posY >= 1 && posY <= 2) {
				if (GetKeyState(VK_LBUTTON) < 0) return 0;
				Sleep(70);
				GotoXY(3, 1, "EXIT",LIGHTRED,BLACK);
				GotoXY(4, 2, "←-",LIGHTRED,BLACK);
				buttoninput1 = 1;
			}
			else if (buttoninput1 == 1) {
				GotoXY(3, 1, "EXIT", BROWN, BLACK);
				GotoXY(4, 2, "←-", BROWN, BLACK);
				buttoninput1 = 0;
			}
			if (posX >= 20 && posX <= 26 && posY >= 1 && posY <= 2) {
				if (GetKeyState(VK_LBUTTON) < 0) {
					Sleep(30);
					if (erase == 0) erase = 1;
					else if (erase == 1) erase = 0;
				}
				Sleep(70);
				GotoXY(20, 1, "ERASER", LIGHTRED, BLACK);
				GotoXY(22, 2, "¤¤", LIGHTRED, BLACK);
				buttoninput3 = 1;
			}
			else if (buttoninput3 == 1 && erase == 0) {
				GotoXY(20, 1, "ERASER", BROWN, BLACK);
				GotoXY(22, 2, "¤¤", BROWN, BLACK);
				buttoninput3 = 0;
			}
			if (posX >= 10 && posX <= 16 && posY >= 1 && posY <= 2) {
				if (GetKeyState(VK_LBUTTON) < 0) {
					system("cls");
					break;
				}
				Sleep(70);
				GotoXY(11, 1, "CLEAR", LIGHTRED, BLACK);
				GotoXY(14, 2, "ALL", LIGHTRED, BLACK);
				buttoninput2 = 1;
			}
			else if (buttoninput2 == 1) {
				GotoXY(11, 1, "CLEAR", BROWN, BLACK);
				GotoXY(14, 2, "ALL", BROWN, BLACK);
				buttoninput2 = 0;
			}
			if (posX >= 38 && posX <= 44 && posY >= 1 && posY <= 2) {
				if (GetKeyState(VK_LBUTTON) < 0) {
					Sleep(70);
					pointer++;
					if (pointer == 10) pointer = 0;
					break;
				}
				if (GetKeyState(VK_RBUTTON) < 0) {
					Sleep(70);
					pointer--;
					if (pointer == -1) pointer = 9;
					break;
				}
				Sleep(70);
				GotoXY(39, 1, "BRUSH", LIGHTRED, BLACK);
				GotoXY(39, 2, "[   ]", LIGHTRED, BLACK);
				GotoXY(41, 2, brush[pointer], color, BLACK);
				buttoninput4 = 1;
			}
			else if (buttoninput4 == 1) {
				GotoXY(39, 1, "BRUSH", BROWN, BLACK);
				GotoXY(39, 2, "[   ]", WHITE, BLACK);
				GotoXY(41, 2, brush[pointer], color, BLACK);
				buttoninput4 = 0;
			}
		}
	}
}