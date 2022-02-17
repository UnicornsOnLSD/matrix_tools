#include <iostream>
#include <vector>

class Matrix
{
public:
    Matrix(std::vector<std::vector<double>>);
    std::vector<std::vector<double>> matrix;
};

Matrix::Matrix(std::vector<std::vector<double>> new_matrix)
{
    matrix = new_matrix;
}

int main(int argc, char const *argv[])
{
    Matrix test = Matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    std::cout << test.matrix[0][0] << std::endl;

    return 0;
}
