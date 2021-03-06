#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;


class Algoritm {
public:
	void Floyd(int n, int **Graph, int **A, int **S)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				S[i][j] = j + 1;
			}
		}

		setlocale(LC_ALL, "Russian");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((i != j) && (Graph[i][j] != 0))
				{
					A[i][j] = Graph[i][j];
				}
				else
				{
					A[i][j] = 655534;
				}
			}
		}
		
		cout << "Матрица смежности графа" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {				
				cout << Graph[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if ((A[i][k] + A[k][j]) < A[i][j])
					{
						A[i][j] = A[i][k] + A[k][j];
						S[i][j] = k+1;
					}
		cout << "Матрица кратчайших путей графа" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "Матрица промежуточных вершин" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << S[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	ifstream fout;
	fout.open("input.txt");
	int n, t;//n - количество вершин, t - количество рёбер
	fout >> n;
	fout >> t;
	int i, j, k;//i - из какой вершины, j - в какую, k - шаг алгоритма
	fout >> i >> j >> k;
	int **A = new int*[n];
	int **Graph = new int*[n] {0};
	int **S = new int*[n] {0};
	for (int i = 0; i < n; i++) {
		A[i] = new int[n] {0};
		Graph[i] = new int[n] {0};
		S[i] = new int[n] {0};
	}
	int v1, v2, w;
	// n*n is amount of edges
	for (int i = 0; i < n*n; i++) {
		 fout >> v1 >> v2 >> w;
		if (v1 != v2)
			Graph[v1][v2] = w;
	}
	Algoritm objFloyd;
	objFloyd.Floyd(n, Graph, A, S);
	system("pause");
}

