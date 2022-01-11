#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include<string>
#include <cstring>
#include<iomanip>
const int rows = 4;
const int columns = 4;
using namespace std;
int copygrid[rows][columns] = { {0},{0},{0},{0} };
void CopyGrid(int grid[][columns], int rows)//grid copying
{
	for (int i = 0; i < rows; i++)//rows
	{
		for (int j = 0; j < columns; j++)//columns
		{
			copygrid[i][j] = grid[i][j];
		}
	}
}
int Checkgrid(int grid[][columns], int rows)//Checking the grid if their was a  move in the grid or not
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (copygrid[i][j] != grid[i][j])
			{
				return 1;
			}
		}
	}
	return 0;
}
void Random(int grid[][columns], int rows)//this is used for genrating random number on random locations in grid
{
	srand(time(0));
	int num3, num4, num;
	while (1)
	{
		num3 = rand() % 4;//row genrator
		num4 = rand() % 4;//column generator
		if (grid[num3][num4] == 0)//this is used to check whether that location is empty or not 
			break;
	}
	while (1)
	{
		num = rand() % 3;
		if (num == 1 || num == 2)
			break;
	}
	grid[num3][num4] = num;

}
void up(int grid[rows][columns])
{
	int result;
	for (int j = 0; j < columns; j++) //column
	{
		int i2 = 0, j2 = j;
		for (int i = 1; i < rows; i++) //rows

		{
			if (grid[i][j] != 0)
			{
				if (grid[i][j] == grid[i - 1][j] || grid[i - 1][j] == 0)
				{
					if (grid[i2][j2] == grid[i][j])
					{
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						i2++;
					}
					else
						if (grid[i2][j2] == 0)
						{
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else
						{
							grid[++i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
				}
				else
					i2++;
			}
		}
	}
	result = Checkgrid(grid, rows);//to check if their was a movement in the grid or not 
	if (result == 1)//if there was a movement that random number will be generated
	{
		Random(grid, rows);
	}
}

void down(int grid[rows][columns])
{
	int result;
	for (int j = 0; j < columns; j++)//columns
	{
		int i2 = rows - 1, j2 = j;
		for (int i = i2 - 1; i >= 0; i--)//rows
		{
			if (grid[i][j] != 0)
			{
				if (grid[i][j] == grid[i + 1][j] || grid[i + 1][j] == 0)
				{
					if (grid[i2][j2] == grid[i][j])
					{
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						i2--;
					}
					else
						if (grid[i2][j2] == 0)
						{
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else
						{
							grid[--i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
				}
				else
					i2--;
			}
		}
	}
	result = Checkgrid(grid, rows);
	if (result == 1)
	{
		Random(grid, rows);
	}
}
void left(int grid[rows][columns])
{
	int result;
	for (int i = 0; i < rows; i++)//row
	{
		int i2 = i, j2 = 0;
		for (int j = 1; j < columns; j++)//column
		{
			if (grid[i][j] != 0)
			{
				if (grid[i][j] == grid[i][j - 1] || grid[i][j - 1] == 0)
				{
					if (grid[i2][j2] == grid[i][j])
					{
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						j2++;
					}
					else
					{
						if (grid[i2][j2] == 0)
						{
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else
						{
							grid[i2][++j2] = grid[i][j];
							grid[i][j] = 0;
						}
					}
				}
				else
					j2++;
			}
		}
	}
	result = Checkgrid(grid, rows);
	if (result == 1)
	{
		Random(grid, rows);
	}
}
void right(int grid[rows][columns])
{
	int result;
	for (int i = 0; i < 4; i++)//rows
	{
		int i2 = i, j2 = columns - 1;
		for (int j = j2 - 1; j >= 0; j--)//columns
		{
			if (grid[i][j] != 0)
			{
				if (grid[i][j] == grid[i][j + 1] || grid[i][j + 1] == 0)
				{
					if (grid[i2][j2] == grid[i][j])
					{
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						j2--;
					}
					else
						if (grid[i2][j2] == 0)
						{
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else
						{
							grid[i2][--j2] = grid[i][j];
							grid[i][j] = 0;
						}
				}
				else
					j2--;
			}
		}
	}
	result = Checkgrid(grid, rows);
	if (result == 1)
	{
		Random(grid, rows);
	}
}
void InterfaceIntialize(int grid[][columns], int rows)//this function is used for intializing two random numbers at random positions in the start of the game 
{
	srand(time(0));
	int num1, num2, num3, num4, num;
	num1 = rand() % 4;
	num2 = rand() % 4;
	while (1)
	{
		num = rand() % 3;
		if (num == 1)
			break;
	}
	grid[num1][num2] = num;
	while (1)
	{
		num3 = rand() % 4;
		num4 = rand() % 4;
		if (num1 != num3 && num4 != num2)
			break;
	}
	while (1)
	{
		num = rand() % 3;
		if (num == 1 || num == 2)
			break;
	}
	grid[num3][num4] = num;
}
void GridDisplay(int grid[][columns], int rows)//this function is used for displaying grid
{
	cout << endl << endl << "\t\t\t\t\t*********************************" << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << "\t\t\t\t\t";
		for (int j = 0; j < columns; j++)
		{
			if (grid[i][j] == 0)
				cout << "|\t";
			else
				cout << "| " << setw(5) << left << grid[i][j] << "\t";
		}
		cout << "|" << endl;
		cout << "\t\t\t\t\t*********************************" << endl;
	}
}
bool WinnerCheck(int grid[][columns], int no_of_row)
{
	for (int i = 0; i < no_of_row; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (grid[i][j] == 1024)
			{
				return true;
			}
		}
	}
	return false;
}
bool LoserCheck(int grid[][columns], int no_of_row)
{
	for (int a = 0; a < no_of_row; a++)
	{
		for (int b = 0; b < columns; b++)
		{
			if (grid[a][b] == 0)
			{
				return false;
			}
		}
	}
	int k = 0;
	for (int c = 0; c < no_of_row; c++)
	{
		k++;
		if (k == 4)
		{
			break;
		}
		for (int d = 0; d < columns; d++)
		{
			if (d == 3)
			{
				break;
			}
			if (grid[c][d] == grid[c][d + 1] || grid[c][d] == grid[k][d])
			{
				return false;
			}
		}
	}
	if (grid[0][3] == grid[1][3] || grid[1][3] == grid[2][3] || grid[2][3] == grid[3][3] || grid[3][0] == grid[3][1] || grid[3][1] == grid[3][2] || grid[3][2] == grid[3][3])
	{
		return false;
	}
	else if (grid[0][3] != grid[1][3] && grid[1][3] != grid[2][3] && grid[2][3] != grid[3][3] && grid[3][0] != grid[3][1] && grid[3][1] != grid[3][2] && grid[3][2] != grid[3][3])
	{
		return true;
	}
	return false;
}
int main()
{
	int grid[rows][columns] = { {0},{0},{0},{0} };
	string key = "w";
	cout << "Welcome to 1024 game!" << endl;
	cout << "\t\t\t\tHere are the instructions for controls: " << endl;
	cout << "Use key W for Up" << endl << "Use key S for Down" << endl << "Use key A for Left" << endl << "Use key D for Right " << endl << "Use Key Q for Quit " << endl;
	InterfaceIntialize(grid, rows);
	GridDisplay(grid, rows);
	cout << endl;
	bool found1 = false, found2 = false;
	while ((key != "Q") || (key != "q"))
	{
		cout << "Input Key: ";
		cin >> key;

		if (key == "Q" || key == "q")
		{
			cout << "You have Quit The Game";
			break;
		}
		else if (key == "W" || key == "w")
		{
			up(grid);
			system("CLS");
			CopyGrid(grid, rows);
			GridDisplay(grid, rows);
		}
		else if (key == "S" || key == "s")
		{
			down(grid);
			system("CLS");
			CopyGrid(grid, rows);
			GridDisplay(grid, rows);
		}
		else if (key == "A" || key == "a")
		{
			left(grid);
			system("CLS");
			CopyGrid(grid, rows);
			GridDisplay(grid, rows);
		}
		else if (key == "D" || key == "d")
		{
			right(grid);
			system("CLS");
			CopyGrid(grid, rows);
			GridDisplay(grid, rows);
		}
		else if (key != "Q" || key != "q" || key != "W" || key != "w" || key != "A" || key != "a" || key != "S" || key != "s" || key != "D" || key != "d")
		{
			cout << "Invalid Key Input.Please Press The Correct Key" << endl;
			continue;
		}
		found1 = WinnerCheck(grid, rows);
		if (found1 == true)
		{
			cout << "You Win.";
			break;
		}
		found2 = LoserCheck(grid, rows);
		if (found2 == true)
		{
			cout << "You Lose.";
			break;
		}
	}
	return 0;
}