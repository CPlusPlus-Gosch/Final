#include<iostream>
#include <string>
#include <random>
#include <windows.h>
#include <chrono>
#include <conio.h>


using namespace std;

//Changes the color of text inside the console
void changeColor(int color)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

int main()
{
	const int BLUE = 1;
	const int GREEN = 2;
	const int RED = 4;
	const int YELLOW = 14;
	const int WHITE = 15;

	//Timer
	std::chrono::time_point<std::chrono::system_clock> start;

	//Random generator with integer bound
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(0, 3);

	int result;
	string guessOne;
	string guessTwo;
	string guessThree;
	string guessFour;
	string colors[4] = {"Red", "Blue", "Yellow", "Green" };
	string randomColors[4];

	result = MessageBoxA(NULL, "Welcome to Simon Says", "Simon Says", MB_OKCANCEL);
	if (result == IDOK)
	{
		for (int i = 0; i < 4; i++)
		{
			int random = distribution(generator);
			randomColors[i] = colors[random];
			if (randomColors[i] == "Blue")
			{
				changeColor(BLUE);
				cout << randomColors[i] << " ";
			}
			else if (randomColors[i] == "Red")
			{
				changeColor(RED);
				cout << randomColors[i] << " ";
			}
			else if (randomColors[i] == "Yellow")
			{
				changeColor(YELLOW);
				cout << randomColors[i] << " ";
			}
			else if (randomColors[i] == "Green")
			{
				changeColor(GREEN);
				cout << randomColors[i] << " ";
			}
		}
		changeColor(WHITE);
		//Start Timer
		start = std::chrono::system_clock::now();

		while (true)
		{
			//Initializes the counter
			__int64 secondsPassed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start).count();

			if (secondsPassed >= 5)
			{
				for (int i = 0; i < 40; i++)
				{
					cout << "\n";
				}
			
				cout << "\nWhat was the first color?" << endl;
				cin >> guessOne;
				cout << "\nThe second?" << endl;
				cin >> guessTwo;
				cout << "\nThird?" << endl;
				cin >> guessThree;
				cout << "\nLastly?" << endl;
				cin >> guessFour;
			
				if (guessOne == randomColors[0] && guessTwo == randomColors[1] && guessThree == randomColors[2] && guessFour == randomColors[3])
				{
					cout << "\nYou were correct!" << endl;
				}
				else
				{
					cout << "Wrong";
				}
				break;
		}
		
		}
		
	}
	else
	{
		cout << "Goodbye\n";
	}

	cin.get();

	return 0;
}