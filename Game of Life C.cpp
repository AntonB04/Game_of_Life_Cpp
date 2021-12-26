// Game of Life Cpp
#include <iostream>
#include <array>
#include <algorithm>

#define DEF int arr[][9] = { {1, 0, 1, 0, 0, 0, 0, 0, 1},\
                    {1, 0, 1, 0, 0, 1, 0, 0, 1},\
                    {0, 0, 1, 0, 0, 0, 0, 0, 1},\
                    {1, 0, 1, 0, 0, 1, 0, 0, 1},\
                    {0, 0, 1, 0, 0, 1, 0, 0, 1} }

DEF;

using namespace std;

void life(int a[9][9], int n, int m) {

	int temp[9][9];

	for (int row = 0; row < n; ++row)
		for (int col = 0; col < m; ++col)
			temp[row][col] = a[row][col];

	int count;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//int count = 0;
			if (i == 0 && j == 0)
			{
				count = a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j];

			}
			else if (i == 0 && j == m - 1)
			{
				count = a[i][j - 1] + a[i + 1][j - 1] + a[i + 1][j];

			}
			else if (i == n - 1 && j == m - 1)
			{
				count = a[i][j - 1] + a[i - 1][j - 1] + a[i - 1][j];

			}
			else if (i == n - 1 && j == 0)
			{
				count = a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j];

			}
			else if (i == 0 && !(j == 0 || j == m - 1))
			{
				count = a[i][j - 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1] + a[i][j + 1];

			}
			else if (i == n - 1 && !(j == 0 || j == m - 1))
			{
				count = a[i][j - 1] + a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j + 1];

			}
			else if (j == 0 && !(i == 0 || i == n - 1))
			{
				count = a[i - 1][j] + a[i - 1][j + 1] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j];

			}
			else if (j == m - 1 && !(i == 0 || i == n - 1))
			{
				count = a[i - 1][j] + a[i - 1][j - 1] + a[i][j - 1] + a[i + 1][j - 1] + a[i + 1][j];

			}
			else
			{
				count = a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1] + a[i - 1][j + 1] + a[i + 1][j - 1] + a[i - 1][j - 1] + a[i + 1][j + 1];

			}

			//If a cell is alive and has 2-3 living neighbors, then it remains alive, otherwise it dies.
			if (a[i][j] == 1)
			{
				if (count == 2 || count == 3)
				{
					temp[i][j] = 1;
				}
				else
				{
					temp[i][j] = 0;

				}
			}
			//If the cell is dead and has 3 living neighbors, then it becomes alive, otherwise it remains dead.
			else if (a[i][j] == 0)
			{
				if (count == 3)
				{
					temp[i][j] = 1;
				}
				else
				{
					temp[i][j] = 0;

				}
			}

		}
	}

	for (int row = 0; row < n; ++row)
		for (int col = 0; col < m; ++col)
			arr[row][col] = temp[row][col];

	for (int row = 0; row < n; ++row) {
		cout << n - row << " ";
		for (int col = 0; col < m; ++col) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}
	cout << 0 << " " << 1 << " " << 2 << " " << 3 << " " << 4 << " " << 5
		<< " " << 6 << " " << 7 << " " << 8 << " " << 9 << endl;
	cout << "-------------------" << endl;
}

int main()
{

	bool k = true;
	int clonedArray[5][9];
	while (k) {
		for (int row = 0; row < 5; ++row)
			for (int col = 0; col < 9; ++col)
				clonedArray[row][col] = arr[row][col];
		life(arr, 5, 9);
		char ch;
		cin >> ch;
		cout << "\t" << "\n";
		cout << "-------------------" << endl;
		k = false;
		for (int row = 0; row < 5; ++row) {
			for (int col = 0; col < 9; ++col) {
				if (clonedArray[row][col] != arr[row][col])
				{
					k = true;
				}
			}
		}
	}
}
