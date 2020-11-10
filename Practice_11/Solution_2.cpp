#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;

int matrix[5000][5000];
int distances[5000];
bool visited[5000];
stack<int>st;

void DFS(int s, bool visited[5000], stack<int>&st, int vertices)
{
	visited[s] = true;
	for (int i = 1; i <= vertices; i++)
	{
		if (matrix[s][i] != 0 && !visited[i])
		{
			DFS(i, visited, st, vertices);
		}
	}
	st.push(s);
}

void longestPath(int s, int t, int vertices)
{
	for (int i = 1; i <= vertices; i++)
	{
		if (!visited[i])
		{
			DFS(i, visited, st, vertices);
		}
	}

	distances[s] = 0;

	while (!st.empty())
	{
		int nextNode = st.top();
		st.pop();
		if (distances[nextNode] != INT_MIN)
		{
			for (int i = 1; i <= vertices; i++)
			{
				if (matrix[nextNode][i] != 0)
				{
					if (distances[i]<distances[nextNode] + matrix[nextNode][i])
					{
						distances[i] = distances[nextNode] + matrix[nextNode][i];
					}
				}
			}

		}
	}

	for (int i = 1; i <= vertices; i++)
	{
		if (i == t)
		{
			if (distances[i] != INT_MIN) cout << distances[i];
			else cout << -1;
		}
	}

}

int main() {
	int vertices, edges, s, t;
	cin >> vertices >> edges >> s >> t;

	for (int i = 1; i <= vertices; i++)
	{
		visited[i] = false;
		distances[i] = INT_MIN;
	}
	for (int i = 1; i <= vertices; i++)
	{
		for (int j = 1; j <= vertices; j++)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 1; i <= edges; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		matrix[u][v] = w;
	}

	longestPath(s, t, vertices);
	return 0;
}
