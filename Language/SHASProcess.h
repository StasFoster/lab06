#pragma once

#include <vector>
#include <string>
#include <tuple>

class SHASProcess {
public:
    static std::string FormatAsMatlabArray(bool manualInput, double num_a, double num_b);
    
    static std::tuple<double, double> meshgrid(double x1, double y1, double x2, double y2);
    static std::tuple<double, double, std::vector<std::vector<double>>> mesh3d(double x1, double y1, double z1, double x2, double y2, double z2);
    static std::tuple<std::vector<double>, std::vector<double>> linspace(double start, double end, int count);
};

