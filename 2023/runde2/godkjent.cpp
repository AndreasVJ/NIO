#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>


// 80/100


class Node {
public:
    int val;
    int subTreeSize;
    int postorderIndex;
    int subTreePostorderIndex;
    int start;
    int end;

    std::vector<Node*> children;
    Node* parent;
};


void postorderTraverse(Node* root, std::vector<int>& result) {

    std::sort(root->children.begin(), root->children.end(), [](const Node* a, const Node* b) {return a->val < b->val;});
    int subTreeSize = 0;
    for (Node* child : root->children) {
        postorderTraverse(child, result);
        subTreeSize += child->subTreeSize;
    }

    root->subTreeSize = subTreeSize + 1;

    if (root->children.size() == 0) {
        root->subTreePostorderIndex = result.size();
    }
    else {
        root->subTreePostorderIndex = root->children[0]->subTreePostorderIndex;
    }

    root->postorderIndex = result.size();
    result.push_back(root->val);
}


int main() {
    
    int N, M;
    std::cin >> N >> M;

    std::vector<Node> employee(N);
    for (int i = 1; i < N; i++) {
        int L;
        std::cin >> L;
        employee[i].parent = &employee[L];
        employee[L].children.push_back(&employee[i]);
        employee[i].val = i;
    }

    std::vector<int> postorder;
    postorderTraverse(&employee[0], postorder);

    std::vector<std::vector<Node*>> levelOrder;
    std::queue<Node*> q;
    q.push(&employee[0]);

    while (!q.empty()) {

        int s = q.size();
        levelOrder.push_back({});

        for (int i = 0; i < s; i++) {
            levelOrder.back().push_back(q.front());
            for (Node* child : q.front()->children) {
                q.push(child);
            }
            q.pop();
        }
    }

    for (int i = 0; i < M; i++) {
        int W, G;
        std::cin >> W >> G;
        
        if (G == 1) {
            employee[W].start++;
            employee[W].end++;
            continue;
        }

        Node* subLeader;

        if (employee[W].parent->subTreeSize > G) {
            subLeader = &employee[W];
        }
        else {
            int level = levelOrder.size() - 1;
            int pos, tempPos;
            for (int b1 = levelOrder.size()/2; b1 > 0; b1 /= 2) {
                while (level - b1 >= 0) {
                    tempPos = 0;
                    for (int b2 = levelOrder[level - b1].size()/2; b2 > 0; b2 /=2) {
                        while (tempPos < levelOrder[level - b1].size() - b2 && levelOrder[level - b1][tempPos + b2]->subTreePostorderIndex <= employee[W].postorderIndex) {
                            tempPos += b2;
                        }
                    }
                    if (levelOrder[level - b1][tempPos]->subTreeSize < G) {
                        level -= b1;
                        pos = tempPos;
                    }
                    else break;
                }
            }

            if (level == levelOrder.size() - 1) {
                subLeader = &employee[W];
            }
            else {
                subLeader = levelOrder[level][pos];
            }
        }

        Node* leader = subLeader->parent;

        if (leader->subTreePostorderIndex <= subLeader->postorderIndex && subLeader->postorderIndex < leader->subTreePostorderIndex + G) {
            employee[postorder[leader->subTreePostorderIndex]].start++;
            employee[postorder[leader->subTreePostorderIndex + G - 1]].end++;
        }
        else {
            employee[postorder[subLeader->subTreePostorderIndex]].start++;
            employee[postorder[subLeader->postorderIndex]].end++;

            G -= subLeader->postorderIndex - subLeader->subTreePostorderIndex + 1;

            employee[postorder[leader->subTreePostorderIndex]].start++;
            employee[postorder[leader->subTreePostorderIndex + G - 1]].end++;
        }
    }

    std::vector<int> approved(N);

    int num = 0;

    for (int i : postorder) {
        num += employee[i].start;
        approved[i] = num;
        num -= employee[i].end;
    }

    for (int i : approved) {
        std::cout << i << " ";
    }
    
    return 0;
}