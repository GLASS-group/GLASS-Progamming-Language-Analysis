#include <chrono>
#include <iostream>
#include <unistd.h>
#include <queue>

using namespace std;

class Node {
public:
    Node(Node* p) {
        parent = p;
        this->data = 0;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    Node* parent;
    Node* leftChild;
    Node* rightChild;
    int data;

    void DFS() {
        data += 1;
        if (leftChild != nullptr) { leftChild->DFS(); }
        if (rightChild != nullptr) {rightChild->DFS(); }
    }
};

class Tree {
public:
    Tree(int nodeNum) {
        rootNode = new Node(nullptr);
        queue<Node*> nodeQueue;
        nodeQueue.push(rootNode);
        for (int i = 0; i < nodeNum; i++) {
            Node* currentNode = nodeQueue.front();
            nodeQueue.pop();
            currentNode->leftChild = new Node(currentNode);
            currentNode->rightChild = new Node(currentNode);
            nodeQueue.push(currentNode->leftChild);
            nodeQueue.push(currentNode->rightChild);

        }
    }

    void DFS() {
        rootNode->DFS();
    }
private:
    Node* rootNode;
};

int main() {
    const int NUM_TRAILS = 50;
    const int ONE_BILLION = 1000000000;
    const int ONE_MILLION = 1000000;
    std::chrono::high_resolution_clock m_clock;
    double cumulative = 0;
    Tree* tree = new Tree(ONE_MILLION);
    for (int t = 0; t < NUM_TRAILS; t++) {
        uint64_t startTime = std::chrono::duration_cast<std::chrono::nanoseconds>(m_clock.now().time_since_epoch()).count();
        tree->DFS();
        uint64_t endTime = std::chrono::duration_cast<std::chrono::nanoseconds>(m_clock.now().time_since_epoch()).count();

        uint64_t difference = endTime - startTime;
        cumulative = cumulative + (double)difference;
        double seconds = difference / (double) ONE_BILLION;

        cout << "Time to process: " << seconds << " seconds" << '\n';
        sleep(0.003);
    }
    double seconds = cumulative / ((double) NUM_TRAILS) / ((double) ONE_BILLION);
    cout << "Total time to process: " << seconds << " seconds" << '\n';
}
