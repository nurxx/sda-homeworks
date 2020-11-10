#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int vertices, edges;
int matrix[5000][5000];
bool visited[5000];
long long int distances[5000];


void shortestPath(int start)
{
	for (int i = 1; i <= vertices; i++)
	{
		visited[i] = false;
		distances[i] = -1;
	}

	distances[start] = 0;
	int min;
	int nextNode = start;
	for (int i = 0; i<vertices; i++)
	{

		long long min = LLONG_MAX;

		for (int j = 1; j <= vertices; j++)
		{
			if (min > distances[j] && distances[j] != -1 && !visited[j])
			{
				min = distances[j];
				nextNode = j;
			}
		}
		visited[nextNode] = true;

		for (int k = 1; k <= vertices; k++)
		{
			if (matrix[nextNode][k] != 0 && !visited[k])
			{
				if (distances[k] == -1 || distances[k] > distances[nextNode] + matrix[nextNode][k])
				{
					distances[k] = distances[nextNode] + matrix[nextNode][k];
				}
			}
		}
	}
	for (int i = 1; i <= vertices; i++)
	{
		if (i != start)
		{
			printf("%lld ", distances[i]);
		}
	}
	printf("\n");
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	short t;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> vertices >> edges;

		for (int rows = 1; rows <= vertices; rows++)
		{
			for (int cols = 1; cols <= vertices; cols++)
			{
				matrix[rows][cols] = 0;
			}
		}

		for (int j = 0; j<edges; j++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			if (matrix[u][v]>0 && w < matrix[u][v])
			{
				matrix[u][v] = w;
				matrix[v][u] = w;
			}
			else if (matrix[u][v] == 0)
			{
				matrix[u][v] = w;
				matrix[v][u] = w;
			}

		}
		int s;
		cin >> s;
		shortestPath(s);
	}

}
