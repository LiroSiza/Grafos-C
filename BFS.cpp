#include<iostream>
#include<queue>
#define NODE 5
using namespace std;

int graph[NODE][NODE] = {
   {0, 1, 0, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 0, 1, 1},
   {1, 0, 0, 0, 0},
   {0, 1, 0, 0, 0} };

void traverse(int s, bool visited[]) {
    visited[s] = true; //mark v as visited
    queue<int> que;
    que.push(s);//insert s into queue
    while (!que.empty()) {
        int u = que.front(); //delete from queue and print
        que.pop();
        for (int i = 0; i < NODE; i++) {
            if (graph[i][u]) {
                //when the node is non-visited
                if (!visited[i]) {
                    visited[i] = true;
                    que.push(i);
                }
            }
        }
    }
}

bool isConnected() {
    bool* vis = new bool[NODE];
    //for all vertex u as start point, check whether all nodes are visible or not
    for (int u = 0; u < NODE; u++) {
        for (int i = 0; i < NODE; i++)
            vis[i] = false; //initialize as no node is visited
        traverse(u, vis);
        for (int i = 0; i < NODE; i++) {
            if (!vis[i]) //if there is a node, not visited by traversal, graph is not connected
                return false;
        }
    }
    return true;
}

int main() {
    if (isConnected())
        cout << "The Graph is connected.";
    else
        cout << "The Graph is not connected.";
}