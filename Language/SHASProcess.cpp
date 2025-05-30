#include "SHASProcess.h"
#include <sstream>
#include <cmath>

std::string SHASProcess::FormatAsMatlabArray(bool manualInput, double num_a, double num_b) {
    std::ostringstream resultStream;

    if (!manualInput) {
        // вывод матрицы в формате для математического языка
    } else {
        // простой арифметик
        if (num_a > num_b) {
            num_a = num_a + num_b;
        } else {
            num_a = num_a - num_b;
        }

        // возвращаем результат, вторая переменная переменная a
        resultStream << "a = " << num_a << ";\r\n";
    }

    return resultStream.str();
}

std::tuple<double, double> SHASProcess::meshgrid(double x1, double y1, double x2, double y2) {
    double avgX = (x1 + x2) / 2.0;
    double avgY = (y1 + y2) / 2.0;
    
    return std::make_tuple(avgX, avgY);
}

std::tuple<double, double, std::vector<std::vector<double>>> SHASProcess::mesh3d(double x1, double y1, double z1, double x2, double y2, double z2) {
    double avgX = (x1 + x2) / 2.0;
    double avgY = (y1 + y2) / 2.0;
    
    int size = 5;
    std::vector<std::vector<double>> grid(size, std::vector<double>(size, 0.0));
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double x = x1 + (x2 - x1) * i / (size - 1);
            double y = y1 + (y2 - y1) * j / (size - 1);
            grid[i][j] = sin(x) * cos(y);
        }
    }
    
    return std::make_tuple(avgX, avgY, grid);
}

std::tuple<std::vector<double>, std::vector<double>> SHASProcess::linspace(double start, double end, int count) {
    std::vector<double> xVals(count);
    std::vector<double> yVals(count);
    
    for (int i = 0; i < count; i++) {
        double x = start + (end - start) * i / (count - 1);
        xVals[i] = x;
        yVals[i] = sin(x);
    }
    
    return std::make_tuple(xVals, yVals);
}

