#include <iostream>
#include <vector>
#include <queue>


struct edge {
    int v, cost;
};


struct node {
    int index;
    std::vector<bool> visited;
    std::vector<edge> neighbours;
};


struct pqElement {
    int index, distance, V;
    bool operator()(pqElement& a, pqElement& b) {
        return a.distance > b.distance;
    }
};


int main() {
    int N, M, V;
    std::cin >> N >> M >> V;

    std::vector<node> g(N);

    for (int i = 0; i < N; i++) {
        g[i].index = i;
        g[i].visited.resize(V + 1);
    }
    
    for (int i = 0; i < M; i++) {
        int a, b, k;
        std::cin >> a >> b >> k;
        g[a].neighbours.push_back({b, k});
        g[b].neighbours.push_back({a, k});
    }

    std::priority_queue<pqElement, std::vector<pqElement>, pqElement> pq;

    pq.push({0, 0, V});

    while (pq.top().index != 1) {
        node* n = &g[pq.top().index];
        int currV = pq.top().V;
        int currCost = pq.top().distance;
        n->visited[currV] = true;
        pq.pop();
        
        for (edge e : n->neighbours) {
            if (currV > 0) {
                if (!g[e.v].visited[currV - 1]) {
                    pq.push({e.v, currCost, currV - 1});
                }
            }
            if (!g[e.v].visited[currV]) {
                pq.push({e.v, currCost + e.cost, currV});
            }
        }
    }

    std::cout << pq.top().distance;

    return 0;
}