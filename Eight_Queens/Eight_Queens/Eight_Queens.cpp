#include "stdafx.h"
#include <iostream>
#include <locale>

using namespace std;

bool canPlaceQueen(int chessboard[8][8], int row, int column) {
	setlocale (LC_ALL, "Rus");
    // Проверяем, нет ли других ферзей по вертикали и диагоналям
    for (int i = 0; i < row; i++) {
        if (chessboard[i][column] || 
            (column-row+i >= 0 && chessboard[i][column-row+i]) ||
            (column+row-i < 8 && chessboard[i][column+row-i])) {
            return false;
        }
    }
    return true;
}

void solveEightQueens(int chessboard[8][8], int row, int& count) {
    if (row == 8) {
        count++;
        cout << "Решение #" << count << ":" << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (chessboard[i][j]) {
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

    for (int i = 0; i < 8; i++) {
        if (canPlaceQueen(chessboard, row, i)) {
            chessboard[row][i] = 1;  // размещаем ферзя на доске
            solveEightQueens(chessboard, row + 1, count);  // рекурсивно переходим к следующей строке
            chessboard[row][i] = 0;  // удаляем ферзя, чтобы найти другую возможную позицию
        }
    }
}

int main() {
    int count = 0;
    int chessboard[8][8] = {0};
    
    solveEightQueens(chessboard, 0, count);
    
    cout << "Общее количество решений: " << count << endl;

	system("pause");
    return 0;
}