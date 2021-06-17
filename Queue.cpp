#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void isBipartite(vector<vector<int>> graph) {
    bool check;
    int n = graph.size();
    for (int i = n; i< n; i++)
        if (i*i == n)
        {
        n=i;
        break;
        }
    int colorArr[n];
    for (int i = 0; i<n ; i++)
        colorArr[i]=-1;
    colorArr[0] = 1;
    queue <int> q;
    q.push(0);
    while (!q.empty())
        {
            int u = q.front();
            q.pop();
     
            if (graph[u][u] == 1)
            check = false;
     
            for (int v = 0; v < 6; ++v)
            {
               
                if (graph[u][v] && colorArr[v] == -1)
                {
                    
                    colorArr[v] = 1 - colorArr[u];
                    q.push(v);
                }
     
                
                else if (graph[u][v] && colorArr[v] == colorArr[u])
                    check = false;
            }
        }
    check = true;
    
    for (int i = 0 ; i < n ; i++ )
    {
        if (colorArr[i] == -1){
            if (check){
                return 1;
                break;
                }
            else {
                return 0;
                break;
                }
            }
    }
    return 1;
    
}

void check(){
    
    
}

int main(){
    int G[6][6] = { {0, 1, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0},
                {0, 0, 1, 0, 1, 0},
                {0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 1, 0} };
    int n = 6;
    vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (G[i][j]) graph[i].push_back(j);
		}
	}

    isBipartite(graph);
}
