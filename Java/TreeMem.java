import java.util.Scanner;
import java.util.ArrayList;

class TreeMem {
    public static void main(String[] args) {
        final int ONE_MILLION = 1000000;
           
        Tree tree = new Tree(100000);

        Scanner scanner = new Scanner(System.in);
        System.out.println("done");
        System.gc();
        scanner.nextLine();
        scanner.close();

    }
}

class Tree {
    class Node {
        Node leftChild;
        Node rightChild;
        Node parent;
        String data;

        Node(Node parent) {
            this.parent = parent;
            data = "a";
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
}