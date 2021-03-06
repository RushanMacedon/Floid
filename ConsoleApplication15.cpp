#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;


class Algoritm {
private:
	unsigned **A;
	unsigned **Graph;
	unsigned **S;
	int n;
public:
	void Floyd(int n, int **Graph, int **A, int **S)
	{

		for ( int i = 0; i < n; i++)
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

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if ((A[i][k] + A[k][j]) < A[i][j])
					{
						A[i][j] = A[i][k] + A[k][j];
						S[i][j] = k;	
					}
					
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << A[i][j] << "\n";
			}
		}
	}
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
			Graph[d] = new int[n];
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
			S[p] = new int[n];
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < n; i++)
			{
				S[i][j] = j + 1;
			}
		}
		
		Algoritm objFloyd;
		objFloyd.Floyd(n,Graph,A,S);
		system("pause");
		
}

