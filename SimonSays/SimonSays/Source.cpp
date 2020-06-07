#include<iostream>
#include <string>
#include <random>
#include <windows.h>


using namespace std;

int main()
{
	const int BLUE = 1;
	const int GREEN = 2;
	const int RED = 4;


	std::random_device generator;
	std::uniform_int_distribution<int> distribution(0, 3);

	int result;
	string colors[4] = {"Red", "Blue", "Yello", "Green" };
	string randomColors[4];

	result = MessageBoxA(NULL, "Welcome to Simon Says", "Simon Says", MB_OKCANCEL);
	if (result == IDOK)
	{
		for (int i = 0; i < 4; i++)
		{
			int random = distribution(generator);
			cout << colors[random] << " ";
			randomColors[i] = colors[random];
			changeColor(BLUE);
		}
		cout << "\n";
	}
	else
	{
		cout << "Goodbye\n";
	}

	cin.get();

	return 0;
}

void changeColor(int color)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}