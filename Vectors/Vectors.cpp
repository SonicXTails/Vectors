#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void fillRandomNumbers(std::vector<std::vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = getRandomNumber(1, 100); // Можно изменить диапазон случайных чисел здесь
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << std::setw(3) << value << " ";
        }
        std::cout << std::endl;
    }
}

int findMinValue(const std::vector<std::vector<int>>& matrix) {
    int min = matrix[0][0];
    for (const auto& row : matrix) {
        for (int value : row) {
            if (value < min) {
                min = value;
            }
        }
    }
    return min;
}

int findMaxValue(const std::vector<std::vector<int>>& matrix) {
    int max = matrix[0][0];
    for (const auto& row : matrix) {
        for (int value : row) {
            if (value > max) {
                max = value;
            }
        }
    }
    return max;
}

double findAverageValue(const std::vector<std::vector<int>>& matrix) {
    double sum = 0;
    int totalElements = 0;
    for (const auto& row : matrix) {
        for (int value : row) {
            sum += value;
            totalElements++;
        }
    }
    return totalElements != 0 ? sum / totalElements : 0;
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(static_cast<unsigned int>(time(0)));

    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    fillRandomNumbers(matrix);

    std::cout << "Матрица:" << std::endl;
    printMatrix(matrix);

    int minValue = findMinValue(matrix);
    std::cout << "Минимальное значение: " << minValue << std::endl;

    int maxValue = findMaxValue(matrix);
    std::cout << "Максимальное значение: " << maxValue << std::endl;

    double averageValue = findAverageValue(matrix);
    std::cout << "Среднее значение: " << averageValue << std::endl;

    return 0;
}