#include <iostream>
using namespace std;

struct Term {
    int row, col, value;
};

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int matrix[50][50];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> matrix[i][j];

    Term sparse[2501];
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                sparse[count++] = {i, j, matrix[i][j]};
            }
        }
    }

    cout << "\nThree-column representation (row, column, value):\n";
    cout << rows << " " << cols << " " << count << '\n';
    for (int i = 0; i < count; ++i)
        cout << sparse[i].row << " " << sparse[i].col << " "
             << sparse[i].value << '\n';

    return 0;
}