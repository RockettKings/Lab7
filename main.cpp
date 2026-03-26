#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 4;

class Matrix {
        int matrix[SIZE][SIZE] = {};
public:
    void readFile(const std::string& fileName){
        std::ifstream file(fileName);

        int rowCount = 0;
        int columnCount = 0;

        if (file.is_open()) {
            int num;
            while (file >> num) {
                if (columnCount >= SIZE){columnCount = 0; rowCount++;}
                matrix[rowCount][columnCount] = num;

                columnCount++;
            }
        }

        file.close();
    }

    void display() {
        for (int i =0; i < SIZE; i++) {
            for (int j =0; j < SIZE; j++) {
                cout << matrix[i][j];
                cout << "   ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) {
        Matrix result;

        for (int i =0; i < SIZE; i++) {
            for (int j =0; j < SIZE; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix &other) {
        Matrix result;

        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        return result;
    }

    int sumOfDiagonals() {
        int result = 0;
        int columnPos = 0;

        for (int i =0; i < SIZE; i++) {
            result += matrix[i][columnPos];

            columnPos++;
        }

        // stops random number grab
        columnPos--;

        for (int i =0; i < SIZE; i++) {
            result += matrix[i][columnPos];

            columnPos --;
        }
        return result;
    }

    Matrix swapRows(int row1, int row2) {
        Matrix result;

        if (row1 < SIZE and row2 < SIZE) {
            for (int i =0; i < SIZE; i++) {
                for (int j =0; j < SIZE; j++) {
                    if (i == row1) {
                        result.matrix[i][j] = matrix[row2][j];
                        continue;
                    }

                    if (i == row2) {
                        result.matrix[i][j] = matrix[row1][j];
                        continue;
                    }

                    result.matrix[i][j] = matrix[i][j];
                }

            }

            return result;
        }

        cout << "\n" << endl;
        cout << "Invalid row" << endl;
        return result;

    }

};


int main() {
    Matrix matrix1;
    Matrix matrix2;

    matrix1.readFile("../matrix-data.txt");
    matrix2.readFile("../matrix-data2.txt");

    cout << "Matrix 1:" << endl;
    matrix1.display();

    cout << "\n" << endl;

    cout << "Matrix 2:" << endl;
    matrix2.display();

    cout << "\n" << endl;

    cout << "Matrix 1 + Matrix 2" << endl;
    (matrix1 + matrix2).display();

    cout << "\n" << endl;

    cout << "Matrix 1 * Matrix 2" << endl;
    (matrix1 * matrix2).display();

    cout << "\n" << endl;

    cout << "Sum of Diagonals: Matrix 1" << endl;
    cout << matrix1.sumOfDiagonals() << endl;

    cout << "\n" << endl;

    cout << "Sum of Diagonals: Matrix 2" << endl;
    cout << matrix2.sumOfDiagonals() << endl;

    cout << "\n" << endl;
    cout << "swapping rows 1 and 2 in matrix 1" << endl;
    (matrix1.swapRows(0, 3)).display();



    return 0;

}