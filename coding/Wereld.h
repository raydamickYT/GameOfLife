#pragma once

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Rules.h"

class Wereld
{
private:
    std::vector<std::vector<bool>> matrix;
    Regels *regels;

public:
    Wereld(int grootte, Regels *regels) : regels(regels)
    {
        matrix.resize(grootte, std::vector<bool>(grootte, false));
        // Vul de matrix willekeurig
        srand(time(nullptr));
        for (int i = 0; i < grootte; ++i)
        {
            for (int j = 0; j < grootte; ++j)
            {
                matrix[i][j] = rand() % 2;
            }
        }
    }

    void updateWereld()
    {
        auto tempMatrix = matrix;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                int buren = telBuren(i, j);
                tempMatrix[i][j] = regels->celMoetLeven(matrix[i][j], buren);
            }
        }
        matrix = tempMatrix;
    }

    int telBuren(int x, int y)
    {
        int count = 0;
        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                int nx = x + i, ny = y + j;
                if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix.size())
                {
                    count += matrix[nx][ny];
                }
            }
        }
        return count;
    }

    void printWereld()
    {
        for (const auto &rij : matrix)
        {
            for (bool cel : rij)
            {
                std::cout << (cel ? '*' : ' ');
            }
            std::cout << std::endl;
        }
    }
};