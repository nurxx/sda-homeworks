#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Graph {
	int v;
	list<int>*adj;
public:
	Graph(int v) {
		this->v = v;
		adj = new list<int>[v];
		vector<int>distances(v);
	}

	void addEdge(int v, int w) {
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	vector<int> BFS(int v) {

		bool *visited = new bool[this->v];
		vector<int> distances(this->v, -1);
		for (int i = 0; i<this->v; i++)visited[i] = false;

		list<int>q;
		visited[v] = true;
		distances[v] = 0;
		q.push_back(v);

		list<int>::iterator it;

		while (!q.empty())
		{
			int s = q.front();
			q.pop_front();
			for (it = adj[s].begin(); it != adj[s].end(); ++it)
			{
				if (!visited[*it] && distances[*it] == -1)
				{
					visited[*it] = true;
					distances[*it] = distances[s] + 6;
					q.push_back(*it);
				}
			}
		}
		return distances;
	}

};

int main() {
	int queries;
	cin >> queries;

	for (int t = 0; t < queries; t++) {

		int n, m;
		cin >> n;

		Graph graph(n);
		cin >> m;

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			graph.addEdge(u, v);
		}
		int startId;
		cin >> startId;
		startId--;

		vector<int> distances = graph.BFS(startId);

		for (int i = 0; i < distances.size(); i++) {
			if (i != startId) {
				cout << distances[i] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}