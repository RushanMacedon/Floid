#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;
void Floyd(int n, int **Graph, int **A, int **S)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if ((i != j) && (Graph[i][j] != 0))
			{
				A[i][j] = Graph[i][j];
			}
			else
			{
				A[i][j] = 654534;
			}
		}
	}

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((A[i][k] + A[k][j]) < A[i][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					S[i][j] = k;
				}
				cout << A[i][j];
				cout << S[i][j];
			}
		}
	}
}

class Algoritm {
private:
	unsigned **A;
	unsigned **Graph;
	unsigned **S;
public:
	void Floyd();
};
int main()
{
	ifstream fout;
	fout.open("input.txt");
	int n, t;//n - количество вершин, t - количество рёбер
	fout >> n;
	fout >> t;
	int i, j, k;//i - из какой вершины, j - в какую, k - шаг алгоритма
	fout >> i >> j >> k;
	int **A = new int*[n];
	for (int s = 0; s < n; s++)
		A[s] = new int[n];
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n; ++i) {
			A[i][j] = 0;
		}
	}
		int **Graph = new int*[n];
		for (int d = 0; d < n; d++)
			A[d] = new int[n];
		for (int l = 0; l < n; ++l) {
			for (int i = 0; i < n; ++i) {
				Graph[l][i] = 0;
			}
		}
		int v1, v2, w;
		for (int i = 0; i < t; i++) {
			fout >> v1 >> v2 >> w;
			if (v1 != v2)
				Graph[v1][v2] = w;
		}
		int **S = new int*[n];
		for (int p = 0; p < n; p++)
			A[p] = new int[n];
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < n; i++)
			{
				S[i][j] = j + 1;
			}
		}
		for (int s = 0; s < n; s++)
			delete[]A[n];
		for (int d = 0; d < n; d++)
			delete[]Graph[n];
		for (int p = 0; p < n; p++)
			delete[]S[n];
		Algoritm objFloyd;
		objFloyd.Floyd();
		system("pause");
		return 0;
}

