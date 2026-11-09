#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

void dfs(int** matrix, int N, int v, bool* visited)
{
    visited[v] = true;
    std::cout << v + 1 << " ";

    for (int i = 0; i < N; i++)
    {
        if (matrix[v][i] == 1 && !visited[i])
        {
            dfs(matrix, N, i, visited);
        }
    }
}

int main()
{
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cout << "Ошибка: не удалось открыть файл input.txt" << std::endl;
        return 1;
    }

    int N;
    if (!(inputFile >> N))
    {
        std::cout << "Ошибка: не удалось прочитать размерность графа" << std::endl;
        return 1;
    }

    int** matrix = new int*[N];
    for (int i = 0; i < N; i++)
    {
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();

    bool* visited = new bool[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }

    std::cout << "Порядок обхода вершин: ";
    dfs(matrix, N, 0, visited);
    std::cout << std::endl;

    for (int i = 0; i < N; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] visited;

    return 0;
}