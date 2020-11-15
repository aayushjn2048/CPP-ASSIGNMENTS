#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class DungeonCrawl {
	public:
		vector <vector<char>> grid;
		int playerX, playerY;
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
		int isCollide(int x,int y)
		{
			if (grid[x][y] == '.')
				return 0;
			else if (grid[x][y] == 'T')
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
			case 'a':	val = isCollide(playerX, (playerY-1+20)%20);
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