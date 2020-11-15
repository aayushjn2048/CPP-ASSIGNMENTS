#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <utility>
using namespace std;

class DungeonCrawl {
public:
	vector <vector<char>> grid;
	int playerX, playerY;
	vector <pair<int, int>> enemies;
	void init()
	{
		srand(time(0));
		for (int i = 0; i < 6; i++)
		{
			vector <char> v;
			for (int j = 0; j < 20; j++)
			{
				int num = rand() % 4;
				if (num == 0)
					v.push_back('T');
				else
					v.push_back('.');
			}
			grid.push_back(v);
		}
		bool isTreasure, isPlayer;
		isTreasure = isPlayer = false;
		while (!isTreasure)
		{
			int x = rand() % 6;
			int y = rand() % 20;
			if (grid[x][y] != 'T')
			{
				grid[x][y] = 'X';
				isTreasure = true;
			}
		}
		while (!isPlayer)
		{
			int x = rand() % 6;
			int y = rand() % 20;
			if (grid[x][y] != 'T' && grid[x][y] != 'X')
			{
				grid[x][y] = '@';
				playerX = x;
				playerY = y;
				isPlayer = true;
			}
		}
		int count = 0;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				int num = rand() % 12;
				if (num == 0 && grid[i][j] != 'T' && grid[i][j] != 'X' && grid[i][j] != '@')
				{
					grid[i][j] = 'E';
					enemies.push_back({ i,j });
				}
			}
		}
	}
	void showGrid()
	{
		for (auto i : grid)
		{
			for (auto j : i)
				cout << j;
			cout << endl;
		}
	}
	int isCollide(int x, int y)
	{
		if (grid[x][y] == '.')
			return 0;
		else if (grid[x][y] == 'T' || grid[x][y] == 'E')
		{
			cout << "Oh O..fallen into the trap!!!" << endl;
			exit(0);
		}
		else if (grid[x][y] == 'X')
		{
			cout << "Hurray..found the treasure!!!" << endl;
			exit(1);
		}
	}
	void playerMovement()
	{
		srand(time(0));
		char key;
		cin >> key;
		int val;
		for (auto enemy : enemies)
		{
			int x = enemy.first;
			int y = enemy.second;
			int movement = rand() % 4;
			switch (movement)
			{
			case 0: x = (x - 1 + 6) % 6;
				if (grid[x][y] == '.')
				{
					grid[enemy.first][enemy.second] = '.';
					enemy.first = x;
					grid[enemy.first][enemy.second] = 'E';
				}
				break;
			case 1: x = (x + 1 + 6) % 6;
				if (grid[x][y] == '.')
				{
					grid[enemy.first][enemy.second] = '.';
					enemy.first = x;
					grid[enemy.first][enemy.second] = 'E';
				}
				break;
			case 2: y = (y - 1 + 20) % 20;
				if (grid[x][y] == '.')
				{
					grid[enemy.first][enemy.second] = '.';
					enemy.second = y;
					grid[enemy.first][enemy.second] = 'E';
				}
				break;
			case 3: y = (y + 1 + 20) % 20;
				if (grid[x][y] == '.')
				{
					grid[enemy.first][enemy.second] = '.';
					enemy.second = y;
					grid[enemy.first][enemy.second] = 'E';
				}
				break;
			}
		}
		switch (key)
		{
		case 'w':	val = isCollide((playerX - 1 + 6) % 6, playerY);
			if (val == 0)
			{
				grid[playerX][playerY] = '.';
				playerX = (playerX - 1 + 6) % 6;
				grid[playerX][playerY] = '@';
			}
			break;
		case 's':	val = isCollide((playerX + 1 + 6) % 6, playerY);
			if (val == 0)
			{
				grid[playerX][playerY] = '.';
				playerX = (playerX + 1 + 6) % 6;
				grid[playerX][playerY] = '@';
			}
			break;
		case 'a':	val = isCollide(playerX, (playerY - 1 + 20) % 20);
			if (val == 0)
			{
				grid[playerX][playerY] = '.';
				playerY = (playerY - 1 + 20) % 20;
				grid[playerX][playerY] = '@';
			}
			break;
		case 'd':	val = isCollide(playerX, (playerY + 1 + 20) % 20);
			if (val == 0)
			{
				grid[playerX][playerY] = '.';
				playerY = (playerY + 1 + 20) % 20;
				grid[playerX][playerY] = '@';
			}
			break;
		}
	}
};

int main()
{
	DungeonCrawl newGame;
	newGame.init();
	cout << "Query:\n1) Print()\n2) PlayerMovement()\n3) Quit" << endl;
	do
	{
		int queryNo;
		cin >> queryNo;
		switch (queryNo)
		{
		case 1:	newGame.showGrid();
			break;
		case 2: newGame.playerMovement();
			break;
		case 3: return 0;
		}
	} while (1);
}