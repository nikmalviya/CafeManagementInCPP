	#include <iostream>
	#include <string>
	#include <cstdio>
	#include <windows.h>
	#include <conio.h>
	#define getch _getch
	#define kbhit _kbhit
namespace Utility {
		inline  void locate(int x, int y);
	}
inline  void gotoxy(int x, int y) {

	Utility::locate(x,y);
}
namespace Utility {
enum {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	GREY,
	DARKGREY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};
enum {
	KEY_ESCAPE  = 0,
	KEY_ENTER   = 1,
	KEY_HOME    = 3,
	KEY_TAB     = 9,
};
inline  void setColor(int c) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hConsole, &csbi);

	SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFFF0) | (WORD)c);
}
inline  void setBackgroundColor(int c) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hConsole, &csbi);

	SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFF0F) | (((WORD)c) << 4));
}
inline  int saveDefaultColor() {
	static char initialized = 0;
	static WORD attributes;
	if (!initialized) {
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		attributes = csbi.wAttributes;
		initialized = 1;
	}
	return (int)attributes;
}
inline  void resetColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)saveDefaultColor());
}
inline  void cls() {
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD coordScreen = {0, 0};
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	const DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}
inline  void locate(int x, int y) {
	COORD coord;
	coord.X = (SHORT)(x - 1);
	coord.Y = (SHORT)(y - 1);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
inline  void setCursorVisibility(char visible) {
	HANDLE hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );
	structCursorInfo.bVisible = (visible ? TRUE : FALSE);
	SetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );
}
inline  void hidecursor() {
	setCursorVisibility(0);
}
inline  void showcursor() {
	setCursorVisibility(1);
}
inline  void setConsoleTitle(char* title) {
	const char * true_title =title;
	SetConsoleTitleA(true_title);
}

inline int getkey() {
	int k = getch();
	switch(k) {
		case 224: {
			int kk;
			switch (kk = getch()) {
				case 71: return KEY_HOME;
				default: return kk-123+18;
			}}
		case 13: return KEY_ENTER;
		case 27: return KEY_ESCAPE;
		default: return k;
	}
}
}
