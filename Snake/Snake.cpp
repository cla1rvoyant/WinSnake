#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;

int main()
{
	srand(time(0));

	int x_field = 50, y_field = 16;
	int x_relative_pos = 30, y_relative_pos = 4;
	x_field += x_relative_pos;
	y_field += y_relative_pos;

	int length = 2;

	vector<int> X_nex(length);
	vector<int> Y_nex(length);

	char apple = 'o';
	char snake_body = '#';
	char snake_heads[4] = {16, 17, 30, 31};
	int head_num = 0;

	COORD c;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), false };
	SetConsoleCursorInfo(h, &cci);

	SetConsoleTextAttribute(h, 15);
	cout << "\n\n\n\n\n\n\n\n";
	cout << "\t                                                                             $$\\                         \n";
	cout << "\t                                                                             $$ |                        \n";
	cout << "\t $$$$$$\\   $$$$$$\\   $$$$$$\\   $$$$$$$\\  $$$$$$$\\        $$$$$$\\  $$$$$$$\\ $$$$$$\\    $$$$$$\\   $$$$$$\\  \n";
	cout << "\t$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  _____|$$  _____|      $$  __$$\\ $$  __$$\\\\_$$  _|  $$  __$$\\ $$  __$$\\ \n";
	SetConsoleTextAttribute(h, 1);
	cout << "\t$$ /  $$ |$$ |  \\__|$$$$$$$$ |\\$$$$$$\\  \\$$$$$$\\        $$$$$$$$ |$$ |  $$ | $$ |    $$$$$$$$ |$$ |  \\__|\n";
	cout << "\t$$ |  $$ |$$ |      $$   ____| \\____$$\\  \\____$$\\       $$   ____|$$ |  $$ | $$ |$$\\ $$   ____|$$ |      \n";
	SetConsoleTextAttribute(h, 4);
	cout << "\t$$$$$$$  |$$ |      \\$$$$$$$\\ $$$$$$$  |$$$$$$$  |      \\$$$$$$$\\ $$ |  $$ | \\$$$$  |\\$$$$$$$\\ $$ |      \n";
	cout << "\t$$  ____/ \\__|       \\_______|\\_______/ \\_______/        \\_______|\\__|  \\__|  \\____/  \\_______|\\__|      \n";
	cout << "\t$$ |                                                                                                     \n";
	cout << "\t$$ |                                                                                                     \n";
	cout << "\t\\__|                                                                                                     ";
	SetConsoleTextAttribute(h, 15);
	_getch();
	system("cls");

	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t $$$$$$\\  \n";
	cout << "\t\t\t\t\t\t\t$$ ___$$\\ \n";
	cout << "\t\t\t\t\t\t\t\\_/   $$ |\n";
	cout << "\t\t\t\t\t\t\t  $$$$$ / \n";
	cout << "\t\t\t\t\t\t\t  \\___$$\\ \n";
	cout << "\t\t\t\t\t\t\t$$\\   $$ |\n";
	cout << "\t\t\t\t\t\t\t\\$$$$$$  |\n";
	cout << "\t\t\t\t\t\t\t \\______/ ";
	Sleep(1000);
	system("cls");

	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t $$$$$$\\  \n";
	cout << "\t\t\t\t\t\t\t$$  __$$\\ \n";
	cout << "\t\t\t\t\t\t\t\\__/  $$ |\n";
	cout << "\t\t\t\t\t\t\t $$$$$$  |\n";
	cout << "\t\t\t\t\t\t\t$$  ____/ \n";
	cout << "\t\t\t\t\t\t\t$$ |      \n";
	cout << "\t\t\t\t\t\t\t$$$$$$$$\\ \n";
	cout << "\t\t\t\t\t\t\t\\________|";
	Sleep(1000);
	system("cls");

	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t  $$\\   \n";
	cout << "\t\t\t\t\t\t\t$$$$ |  \n";
	cout << "\t\t\t\t\t\t\t\\_$$ |  \n";
	cout << "\t\t\t\t\t\t\t  $$ |  \n";
	cout << "\t\t\t\t\t\t\t  $$ |  \n";
	cout << "\t\t\t\t\t\t\t  $$ |  \n";
	cout << "\t\t\t\t\t\t\t$$$$$$\\ \n";
	cout << "\t\t\t\t\t\t\t\\______|";
	Sleep(1000);
	system("cls");

	for (int i = 0; i < y_relative_pos; i++)
		cout << "\n";
	SetConsoleTextAttribute(h, 5);
	for (int y = y_relative_pos; y <= y_field; y++)
	{
		for (int i = 0; i < x_relative_pos; i++)
			cout << " ";
		for (int x = x_relative_pos; x <= x_field; x++)
		{
			if (x == x_relative_pos || x == x_field)
				cout << "|";
			else if (y == y_relative_pos || y == y_field)
				cout << "-";
			else
				cout << " ";
		}
		cout << "\n";
	}
	SetConsoleTextAttribute(h, 15);

	int score = 0;
	for (int i = 0; i < x_relative_pos + (x_field - x_relative_pos - 3) / 2; i++)
		cout << " ";
	cout << "SCORE: " << score;

	int score_x = x_relative_pos + (x_field - x_relative_pos - 3) / 2 + 7;
	int score_y = y_field + 1;

	X_nex[length - 1] = x_relative_pos + (x_field - x_relative_pos) / 2 - 1;
	Y_nex[length - 1] = y_relative_pos + (y_field - y_relative_pos) / 2;
	X_nex[0] = x_relative_pos + (x_field - x_relative_pos) / 2;
	Y_nex[0] = y_relative_pos + (y_field - y_relative_pos) / 2;

	c.X = X_nex[length - 1];
	c.Y = Y_nex[length - 1];
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 2);
	putchar(snake_body);

	c.X = X_nex[0];
	c.Y = Y_nex[0];
	SetConsoleCursorPosition(h, c);
	putchar(snake_heads[head_num]);

	int dx = 1, dy = 0;

	int x_apple, y_apple;
	bool apple_flag;

	do
	{
		apple_flag = 0;

		x_apple = rand() % ((x_field - 1) - (x_relative_pos + 1) + 1) + (x_relative_pos + 1);
		y_apple = rand() % ((y_field - 1) - (y_relative_pos + 1) + 1) + (y_relative_pos + 1);

		for (int i = 0; i < length; i++)
		{
			if (x_apple == X_nex[i] && y_apple == Y_nex[i])
				apple_flag = 1;
		}
	} while (apple_flag == 1);

	c.X = x_apple;
	c.Y = y_apple;
	SetConsoleTextAttribute(h, 4);
	SetConsoleCursorPosition(h, c);
	putchar(apple);
	SetConsoleTextAttribute(h, 15);

	while (1)
	{
		Sleep(100);

		if (_kbhit())
		{
			int key = _getch();

			if (key == 0 || key == 224)
				key = _getch();

			switch (key)
			{
			case 80:
				head_num = 3;
				dy = 1;
				dx = 0;
				break;

			case 72:
				head_num = 2;
				dy = -1;
				dx = 0;
				break;

			case 75:
				head_num = 1;
				dy = 0;
				dx = -1;
				break;

			case 77:
				head_num = 0;
				dy = 0;
				dx = 1;
				break;
			}
		}

		int x = X_nex[length - 1] + dx;
		int y = Y_nex[length - 1] + dy;

		if (x == x_relative_pos)
			x = x_field - 1;
		if (x == x_field)
			x = x_relative_pos + 1;
		if (y == y_relative_pos)
			y = y_field - 1;
		if (y == y_field)
			y = y_relative_pos + 1;

		int break_nexs = 1;
		for (; break_nexs < length; break_nexs++)
		{
			if (x == X_nex[break_nexs] && y == Y_nex[break_nexs])
				break;
		}

		if (break_nexs < length)
			break;

		if (x_apple == x && y_apple == y)
		{
			score++;
			c.X = score_x;
			c.Y = score_y;
			SetConsoleCursorPosition(h, c);
			cout << score;

			c.X = X_nex[length - 1];
			c.Y = Y_nex[length - 1];
			SetConsoleTextAttribute(h, 2);
			SetConsoleCursorPosition(h, c);
			putchar(snake_body);

			length++;
			c.X = X_nex[length - 1] = x;
			c.Y = Y_nex[length - 1] = y;
			SetConsoleCursorPosition(h, c);
			putchar(snake_heads[head_num]);

			do
			{
				apple_flag = 0;

				x_apple = rand() % ((x_field - 1) - (x_relative_pos + 1) + 1) + (x_relative_pos + 1);
				y_apple = rand() % ((y_field - 1) - (y_relative_pos + 1) + 1) + (y_relative_pos + 1);

				for (int i = 0; i < length; i++)
				{
					if (x_apple == X_nex[i] && y_apple == Y_nex[i])
						apple_flag = 1;
				}
			} while (apple_flag == 1);

			c.X = x_apple;
			c.Y = y_apple;
			SetConsoleTextAttribute(h, 4);
			SetConsoleCursorPosition(h, c);
			putchar(apple);
		}
		else
		{
			c.X = X_nex[0];
			c.Y = Y_nex[0];
			SetConsoleCursorPosition(h, c);
			putchar(' ');

			if (length > 1)
			{
				c.X = X_nex[length - 1];
				c.Y = Y_nex[length - 1];
				SetConsoleTextAttribute(h, 2);
				SetConsoleCursorPosition(h, c);
				putchar(snake_body);
			}

			for (int i = 0; i < length - 1; i++)
			{
				X_nex[i] = X_nex[i + 1];
				Y_nex[i] = Y_nex[i + 1];
			}

			c.X = X_nex[length - 1] = x;
			c.Y = Y_nex[length - 1] = y;
			SetConsoleCursorPosition(h, c);
			putchar(snake_heads[head_num]);
			SetConsoleTextAttribute(h, 15);
		}
	}

	system("cls");
	cout << "\n\n\n\n\n\n\n\n";
	SetConsoleTextAttribute(h, 4);
	cout << "\t\t $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\        $$$$$$\\  $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\  \n";
	cout << "\t\t$$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|      $$  __$$\\ $$ |   $$ |$$  _____|$$  __$$\\ \n";
	cout << "\t\t$$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |            $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |\n";
	cout << "\t\t$$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\          $$ |  $$ |\\$$\\  $$  |$$$$$\\    $$$$$$$  |\n";
	cout << "\t\t$$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|         $$ |  $$ | \\$$\\$$  / $$  __|   $$  __$$< \n";
	cout << "\t\t$$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |            $$ |  $$ |  \\$$$  /  $$ |      $$ |  $$ |\n";
	cout << "\t\t\\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\        $$$$$$  |   \\$  /   $$$$$$$$\\ $$ |  $$ |\n";
	cout << "\t\t \\______/ \\__|  \\__|\\__|     \\__|\\________|       \\______/     \\_/    \\________|\\__|  \\__|\n\n\n\n\n";
	SetConsoleTextAttribute(h, 15);
	system("pause");
}
