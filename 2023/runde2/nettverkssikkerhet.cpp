#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>


class Node {
public:
    int val;
    std::unordered_set<int> neighbours;
};


class Graph {
public:
    std::unordered_map<int, Node> nodes;
    std::unordered_set<int> deg0;
    std::unordered_set<int> deg1;
    std::unordered_set<int> deg2;
    std::unordered_set<int> degGE3;

    void addNode(Node& n) {
        nodes[n.val] = n;
        if (n.neighbours.size() == 1) {
            deg1.insert(n.val);
        }
        else if (n.neighbours.size() == 2) {
            deg2.insert(n.val);
        }
        else {
            degGE3.insert(n.val);
        }
        for (int i : n.neighbours) {
            nodes[i].neighbours.insert(n.val);
            if (nodes[i].neighbours.size() == 1) {
                deg0.erase(i);
                deg1.insert(i);
            }
            else if (nodes[i].neighbours.size() == 2) {
                deg1.erase(i);
                deg2.insert(i);
            }
            else if (nodes[i].neighbours.size() == 3) {
                deg2.erase(i);
                degGE3.insert(i);
            }
        }
    }

    void removeNode(Node& n) {
        if (nodes[n.val].neighbours.size() >= 3) {
            degGE3.erase(n.val);
        }
        else if (nodes[n.val].neighbours.size() == 2) {
            deg2.erase(n.val);
        }
        else if (nodes[n.val].neighbours.size() == 1) {
            deg1.erase(n.val);
        }
        for (int i : n.neighbours) {
            nodes[i].neighbours.erase(n.val);
            if (nodes[i].neighbours.size() == 0) {
                deg1.erase(i);
                deg0.insert(i);
            }
            else if (nodes[i].neighbours.size() == 1) {
                deg2.erase(i);
                deg1.insert(i);
            }
            else if (nodes[i].neighbours.size() == 2) {
                degGE3.erase(i);
                deg2.insert(i);
            }
        }
        nodes.erase(n.val);
    }
};


int MIS(Graph& g) {

    if (g.nodes.size() == g.deg0.size()) {
        return g.nodes.size();
    }
    else {
        if (g.deg1.size()) {
            Node n = g.nodes[*g.deg1.begin()];
            Node neighbour = g.nodes[*n.neighbours.begin()];
            g.removeNode(neighbour);
            int nInc = MIS(g);
            g.addNode(neighbour);
            return nInc;
        }
        else if (g.degGE3.size()) {
            Node n = g.nodes[*g.degGE3.begin()];

            g.removeNode(n);
            int nExc = MIS(g);
            g.addNode(n);

            std::stack<Node> s;
            for (int i : n.neighbours) {
                s.push(g.nodes[i]);
                g.removeNode(g.nodes[i]);
            }
            int nInc = MIS(g);
            while (!s.empty()) {
                g.addNode(s.top());
                s.pop();
            }

            return std::max(nInc, nExc);
        }
        else {
            Node n = g.nodes[*g.deg2.begin()];

            std::stack<Node> s;
            for (int i : n.neighbours) {
                s.push(g.nodes[i]);
                g.removeNode(g.nodes[i]);
            }
            int nInc = MIS(g);
            while (!s.empty()) {
                g.addNode(s.top());
                s.pop();
            }

            return nInc;
        }
    }
}


int main() {

    int N, M, K, P;
    std::cin >> N >> M >> K >> P;

    Graph g;
    for (int i = 0; i < N; i++) {
        g.nodes[i] = {i, {}};
    }

    for (int i = 0; i < M + P; i++) {
        int u, v;
        std::cin >> u >> v;
        g.nodes[u].neighbours.insert(v);
        g.nodes[v].neighbours.insert(u);
    }

    for (int i = 0; i < N; i++) {
        if (g.nodes[i].neighbours.size() == 0) {
            g.deg0.insert(i);
        }
        else if (g.nodes[i].neighbours.size() == 1) {
            g.deg1.insert(i);
        }
        else if (g.nodes[i].neighbours.size() == 2) {
            g.deg2.insert(i);
        }
        else {
            g.degGE3.insert(i);
        }
    }

    std::cout << N - MIS(g);

    return 0;
}