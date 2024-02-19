#include <chrono>
#include <iostream>
#include <unistd.h>
#include <queue>

using namespace std;

class Node {
public:
    Node(Node* p) {
        parent = p;
        this->data = "a";
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    Node* parent;
    Node* leftChild;
    Node* rightChild;
    string data;

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
    
    Tree* tree = new Tree(100000);
    cout << "done" << endl;
    string temp;
    cin >> temp;
}

