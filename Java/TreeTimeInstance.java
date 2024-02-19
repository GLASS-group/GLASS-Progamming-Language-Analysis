import java.util.Scanner;
import java.util.ArrayList;

class TreeTimeInstance {
    public static void main(String[] args) {
        final int ONE_MILLION = 1000000;
        final int ONE_BILLION = 1000000000;
        final int NUM_TRIALS = 50;
        
        long cumulative = 0;
        for (int t = 0; t < NUM_TRIALS; t++) {
           
            long time = System.nanoTime();
            Tree tree = new Tree(100000);
            long finalTime = System.nanoTime();

            long difference = finalTime - time;
            cumulative += difference;
            double seconds = difference / (double) ONE_BILLION;
            System.out.printf("Time to process: %f seconds\n", seconds);
        }

        try {
            Thread.sleep(3);
        } catch (InterruptedException e) { }

        double seconds = (double) cumulative / (double) ONE_BILLION / ((float) NUM_TRIALS);
        System.out.printf("Average time to process: %f seconds\n", seconds);

    }
}

class Tree {
    class Node {
        Node leftChild;
        Node rightChild;
        Node parent;
        int data;

        Node(Node parent) {
            this.parent = parent;
            data = 0;
        }

        private void DFS() {
            data++;
            if (leftChild != null) { leftChild.DFS(); }
            if (rightChild != null) {rightChild.DFS(); }
        }
    }

    Node rootNode;

    Tree(int nodeNum) {
        rootNode = new Node(null);
        ArrayList<Node> nodeQueue = new ArrayList<Node>();
        nodeQueue.add(rootNode);
        for (int i = 0; i < nodeNum; i++) {
            Node currentNode = nodeQueue.remove(0);
            currentNode.leftChild = new Node(currentNode);
            currentNode.rightChild = new Node(currentNode);
            nodeQueue.add(currentNode.leftChild);
            nodeQueue.add(currentNode.rightChild);
        }
    }

    public void DFS() {
        rootNode.DFS();
    }
}