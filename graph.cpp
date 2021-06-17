#include <iostream>
#include <list>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};

class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        list<int> queue;
        visited[v] = true;
        queue.push_back(v);
        Adjacency *a = new Adjacency(V);
        while (!queue.empty())
        {
            v = queue.front();
            a->push(v);
            queue.pop_front();
            for (int i = 0; i < adj[v].getSize(); i++)
            {
                if (!visited[adj[v].getElement(i)])
                {
                    visited[adj[v].getElement(i)] = 1;
                    queue.push_back(adj[v].getElement(i));
                }
            }
        }
        return a;
	}
    void topo(int i, bool visited[], stack<int>& st) {
		visited[i] = true;
		for (int j = 0; j < adj[i].getSize(); j++) {
			if (!visited[adj[i].getElement(j)]) {
				topo(adj[i].getElement(j), visited, st);
			}
		}
		st.push(i);

	}
	void topologicalSort() {
		//TODO
		stack<int> st;
		bool* visited = new bool[V];
		for (int i = 0; i < V; i++) {
			visited[i] = 0;
		}
		for (int i = 0; i < V; i++) {
			if (visited[i] == 0) {
				topo(i,visited,st);
			}
		}
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
	}
};

class DirectedGraph 
{ 
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool *rs);
public: 
	DirectedGraph(){
        V = 0;
        adj = NULL;
    }
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = new list<int>[V];
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
 	bool iscyc(int v, bool visited[], bool *rs)
    {
        if (visited[v] == false)
        {
            visited[v] = true;
            rs[v] = true;
            auto it = adj[v].begin();
            for (; it != adj[v].end(); it++)
            {
                if (!visited[*it] && iscyc(*it, visited, rs))
                    return true;
                else if (rs[*it])
                    return true;
            }
        }
        rs[v] = false;
        return false;
    }
    bool isCyclic()
    {
        bool *visited = new bool[V];
        bool *rs = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            rs[i] = 0;
        }
        for (int i = 0; i < V; i++)
        {
            if (iscyc(i, visited, rs))
                return true;
        }
        return false;
    }
    
}; 

int minDistance(int dist[], bool sptSet[], int size)
{
    int V = size;
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
int getSize(int **graph)
{
    int count = 0;
    while(graph[count])
    {
        count++;
    }
    return count;
}
int Dijkstra(int** graph, int src, int dst) {
    int V = getSize(graph);
	int dist[V]; 
	bool sptSet[V]; 

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	
	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet, V);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)

		
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	return dist[dst];
}



int main(){
    int n = 6;
int init[6][6] = {
	{0, 10, 20, 0, 0, 0},
	{10, 0, 0, 50, 10, 0},
	{20, 0, 0, 20, 33, 0},
	{0, 50, 20, 0, 20, 2},
	{0, 10, 33, 20, 0, 1},
	{0, 0, 0, 2, 1, 0} };

int** graph = new int*[n];
for (int i = 0; i < n; ++i) {
	graph[i] = init[i];
}

cout << Dijkstra(graph, 0, 1);
}