#include "stdafx.h"
#include <iostream>
#include <vector>
#include <locale>

using namespace std;

bool canPlaceQueen(vector<int>& chessboard, int row, int column) {
	setlocale (LC_ALL, "Rus");
    for (int i = 0; i < row; i++) {
        if (chessboard[i] == column || chessboard[i] - column == i - row || chessboard[i] - column == row - i) {
            return false;
        }
    }
    return true;
}

void solveEightQueens(vector<int>& chessboard, int row, int n, int& count) {
    if (row == n) {
        count++;
        cout << "Решение #" << count << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (chessboard[i] == j) {
                    cout << "Ф ";
                } else {
                    cout << "- ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (canPlaceQueen(chessboard, row, i)) {
            chessboard[row] = i;
            solveEightQueens(chessboard, row + 1, n, count);
        }
    }
}

int main() {
    int n = 8;
    int count = 0;
    vector<int> chessboard(n);
    
    solveEightQueens(chessboard, 0, n, count);
    
    cout << "Общее количество решений: " << count << endl;

	system ("pause");
    return 0;
}