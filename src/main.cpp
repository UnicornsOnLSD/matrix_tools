#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

class Matrix
{
public:
    Matrix(std::vector<std::vector<double>>);
    Matrix(int, int);
    std::vector<std::vector<double>> matrix;

    int getM()
    {
        return matrix.size();
    }

    int getN()
    {
        if (getM() == 0)
            return 0;
        else
            return matrix[0].size();
    }

    Matrix *getTranspose()
    {
        Matrix *transpose = new Matrix(getN(), getM());

        for (int i = 0; i < transpose->getM(); i++)
            for (int j = 0; j < transpose->getN(); j++)
                transpose->matrix[i][j] = matrix[j][i];

        return transpose;
    }
};

Matrix::Matrix(std::vector<std::vector<double>> new_matrix)
{
    int column_size = -1;

    for (auto column : new_matrix)
    {
        if (column_size == -1)
            column_size = column.size();
        else if (column_size != column.size())
            throw std::invalid_argument("Columns must have same length");
    }

    matrix = new_matrix;
}

Matrix::Matrix(int m, int n)
{
    matrix = std::vector<std::vector<double>>(m);

    for (int i = 0; i < m; i++)
    {
        matrix[i] = std::vector<double>(n);
    }
}

int main(int argc, char const *argv[])
{
    Matrix *test = new Matrix({{2, 7, 3.4, sqrt(2)}, {5, 0, 4, 1}});

    std::cout << test->matrix[0][1] << std::endl;

    Matrix *transpose = test->getTranspose();

    std::cout << transpose->matrix[3][1] << std::endl;

    return 0;
}
