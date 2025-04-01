package BPlusTree;

class BPlusTreeNode {
    int numKeys;
    int[] keys;
    long[] offset; // Only used in leaf nodes, is null for internal nodes
    // I think this is the part of the implementation where I should have made two distinct child class
    // Two child classes for both Internal Nodes and Leaf Nodes
    BPlusTreeNode[] children;
    boolean isLeaf;
    BPlusTreeNode next;

    BPlusTreeNode(boolean isLeaf, int degree) {
        this.isLeaf = isLeaf;
        this.keys = new int[degree - 1];
        this.offset = isLeaf ? new long[degree - 1] : null;
        this.children = isLeaf ? null : new BPlusTreeNode[degree];
        this.numKeys = 0; // so far zero lol, cos we just starting out homes
        this.next = null;
    }
}