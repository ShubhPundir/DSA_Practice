package BPlusTree;

import java.util.Arrays;

class BPlusTreeNode {
    boolean isLeaf;
    int[] keys;
    long[] offsets;
    BPlusTreeNode[] children;
    BPlusTreeNode next;
    int keyCount;

    public BPlusTreeNode(int degree, boolean isLeaf) {
        this.isLeaf = isLeaf;
        this.keys = new int[degree - 1];
        Arrays.fill(this.keys, -1); // Fill keys with placeholder '-1'
        this.offsets = isLeaf ? new long[degree - 1] : null;
        if (this.offsets != null) Arrays.fill(this.offsets, -1L); // Fill offsets with placeholder '-1'
        this.children = isLeaf ? null : new BPlusTreeNode[degree];
        this.next = null;
        this.keyCount = 0;
    }
}
