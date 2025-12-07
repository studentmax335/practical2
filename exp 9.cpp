
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ------------ DFS USING ADJACENCY MATRIX --------------
void DFS_matrix(int start, vector<vector<int>>& adjMat, vector<bool>& visited)
{
    cout << start << " ";
    visited[start] = true;

    for (int i = 0; i < adjMat.size(); i++)
    {
        if (adjMat[start][i] == 1 && visited[i]==0)
        {
            DFS_matrix(i, adjMat, visited);
        }
    }
}

// ------------ BFS USING ADJACENCY LIST -----------------
void BFS_list(int start, vector<vector<int>>& adjList)
{
    vector<bool> visited(adjList.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (q.empty()==false)
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neigh : adjList[node])
        {
            if (visited[neigh]==false)
            {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
}

int main()
{
    // ----- Landmark index reference -----
    // 0 = Park
    // 1 = Hospital
    // 2 = School
    // 3 = Mall
    // 4 = Station

    int n = 5;

    // ------------------ Adjacency Matrix ---------------------
    vector<vector<int>> adjMat = {
        //P  H  S  M  ST
        {0, 1, 1, 0, 0}, // Park
        {1, 0, 0, 1, 0}, // Hospital
        {1, 0, 0, 1, 1}, // School
        {0, 1, 1, 0, 1}, // Mall
        {0, 0, 1, 1, 0}  // Station
    };

    vector<bool> visited(n, false);

    cout << "DFS Traversal (Adjacency Matrix) starting from Park (0): ";
    DFS_matrix(0, adjMat, visited);
    cout << endl;

    // ------------------ Adjacency List -----------------------
    vector<vector<int>> adjList = {
        {1, 2},       // Park
        {0, 3},       // Hospital
        {0, 3, 4},    // School
        {1, 2, 4},    // Mall
        {2, 3}        // Station
    };

    cout << "BFS Traversal (Adjacency List) starting from Park (0): ";
    BFS_list(0, adjList);
    cout << endl;

    return 0;
}


