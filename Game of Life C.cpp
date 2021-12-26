// Game of Life C
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

    int count;
    int temp[9][9];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            count = 0;
            count = a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1] + a[i - 1][j + 1]
                + a[i + 1][j - 1] + a[i - 1][j - 1] + a[i + 1][j + 1];
            //The cell dies
            if (count < 2 || count > 3)
                temp[i][j] = 0;
            //The cell stays the same
            if (count == 2)
                temp[i][j] = a[i][j];
            //The cell either stays alive, or is "born"
            if (count == 3)
                temp[i][j] = 1;
        }
    }

    //Copies the completed temp array back to the main array
    for (int row = 0; row < n; ++row)
        for (int col = 0; col < m; ++col)
            arr[row][col] = temp[row][col];

    for (int row = 0; row < n; ++row) {
        cout << n - row << " ";
        for (int col = 0; col < m; ++col) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    cout << 0 << " " << 1 << " " << 2 << " " << 3 << " " << 4 << " " << 5
        << " " << 6 << " " << 7 << " " << 8 << " " << 9 << endl;
    cout << "-------------------" << endl;
}

int main()
{
    int k = 0;
    while (k < 6) {
        life(arr, 5, 9);
        k++;
        char ch;
        cin >> ch;
        cout << "-------------------" << endl;
    }
}
