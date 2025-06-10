package BPlusTree;

import java.util.LinkedList;
import java.util.Queue;

class BPlusTree {
    private int degree = 4;
    private BPlusTreeNode root;

    public BPlusTree() {
        this.root = new BPlusTreeNode(true, degree);
    }

    public BPlusTree(int degree) {
        // System.out.println("Param-Ctor called with a degree: " + degree);
        this.degree = degree;
        this.root = new BPlusTreeNode(true, degree);
    }

    public long search(int key){
        BPlusTreeNode node = root; // head node;

        // get to the correct leaf children node
        while(!node.isLeaf){
            int i = 0;
            while(i < node.numKeys && key >= node.keys[i]){
                i++;
            }
            node = node.children[i];
        }

        // search inside the leaf children node's keys
        for(int i = 0; i < node.numKeys; i++){
            if(node.keys[i] == key){
                return node.offset[i];
            }            
        }

        return -1; // not found
    }
    
    public void insert(int key, long offset){
        BPlusTreeNode rootNode = root;
        if(rootNode.numKeys == degree - 1){
            // any node has the maximum limit of keys == degree - 1
            // therefor if the rootNode is maxed out with full capacity, 
            // it either splits or pushes the data onto it's children, if appropriate

            BPlusTreeNode newRoot = new BPlusTreeNode(false, degree);
            newRoot.children[0] = rootNode;
            splitChild(newRoot, 0, rootNode);
            root = newRoot;
        }
        insertNonFull(root, key, offset);
    }

    private void insertNonFull(BPlusTreeNode node, int key, long value) {
        int i = node.numKeys - 1;
        if (node.isLeaf) {
            while (i >= 0 && key < node.keys[i]) {
                node.keys[i + 1] = node.keys[i];
                node.offset[i + 1] = node.offset[i];
                i--;
            }
            node.keys[i + 1] = key;
            node.offset[i + 1] = value;
            node.numKeys++;
        } else {
            while (i >= 0 && key < node.keys[i]) { // loop starts from the right
                i--;
            }
            i++;
            if (node.children[i].numKeys == degree - 1) {
                splitChild(node, i, node.children[i]);
                if (key > node.keys[i]) {
                    i++;
                }
            }
            insertNonFull(node.children[i], key, value);
        }
    }

    private void splitChild(BPlusTreeNode parent, int index, BPlusTreeNode child) {
        BPlusTreeNode newNode = new BPlusTreeNode(child.isLeaf, degree);
        int mid = (degree - 1) / 2;
        newNode.numKeys = degree - 1 - mid - 1;
        child.numKeys = mid;

        for (int j = 0; j < newNode.numKeys; j++) {
            newNode.keys[j] = child.keys[mid + 1 + j];
            if (child.isLeaf) {
                newNode.offset[j] = child.offset[mid + 1 + j];
            } else {
                newNode.children[j] = child.children[mid + 1 + j];
            }
        }
        if (!child.isLeaf) {
            newNode.children[newNode.numKeys] = child.children[degree - 1];
        }
        for (int j = parent.numKeys; j > index; j--) {
            parent.children[j + 1] = parent.children[j];
            parent.keys[j] = parent.keys[j - 1];
        }
        parent.children[index + 1] = newNode;
        parent.keys[index] = child.keys[mid];
        parent.numKeys++;
        if (child.isLeaf) {
            newNode.next = child.next;
            child.next = newNode;
        }
    }

    public void printTree() {
        printTree(root, "");
    }

    private void printTree(BPlusTreeNode node, String indent) {
        System.out.print(indent + "[");
        for (int i = 0; i < node.numKeys; i++) {
            System.out.print(node.keys[i] + (i < node.numKeys - 1 ? ", " : ""));
        }
        System.out.println("]");
        if (!node.isLeaf) {
            for (int i = 0; i <= node.numKeys; i++) {
                printTree(node.children[i], indent + "    ");
            }
        }
    }


    public static void main(String[] args) {
        BPlusTree tree = new BPlusTree();
        tree.insert(10, 1000L);
        tree.insert(20, 2000L);
        tree.insert(5, 500L);
        tree.insert(6, 600L);
        tree.insert(12, 1200L);
        tree.insert(30, 3000L);
        tree.insert(7, 700L);
        tree.insert(17, 1700L);
        
        tree.printTree();
        int k = 114;
        System.out.println("Search " + k + " : " + tree.search(k));
    }
}

