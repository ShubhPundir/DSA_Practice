package BPlusTree;

import java.util.LinkedList;
import java.util.Queue;

class BPlusTree {
    private int degree;
    private BPlusTreeNode root;

    public BPlusTree(int degree) {
        this.degree = degree;
        this.root = new BPlusTreeNode(degree, true);
    }

    public Long search(int key) {
        BPlusTreeNode node = root;
        while (!node.isLeaf) {
            int i = 0;
            while (i < node.keyCount && key >= node.keys[i]) {
                i++;
            }
            node = node.children[i];
        }
        
        for (int i = 0; i < node.keyCount; i++) {
            if (node.keys[i] == key) return node.offsets[i];
        }
        return null;
    }

    public void insert(int key, long offset) {
        BPlusTreeNode rootNode = root;
        if (rootNode.keyCount == degree - 1) {
            BPlusTreeNode newRoot = new BPlusTreeNode(degree, false);
            newRoot.children[0] = rootNode;
            splitChild(newRoot, 0, rootNode);
            root = newRoot;
        }
        insertNonFull(root, key, offset);
    }

    private void insertNonFull(BPlusTreeNode node, int key, long offset) {
        if (node.isLeaf) {
            int pos = node.keyCount - 1;
            while (pos >= 0 && key < node.keys[pos]) {
                node.keys[pos + 1] = node.keys[pos];
                node.offsets[pos + 1] = node.offsets[pos];
                pos--;
            }
            node.keys[pos + 1] = key;
            node.offsets[pos + 1] = offset;
            node.keyCount++;
        } else {
            int i = node.keyCount - 1;
            while (i >= 0 && key < node.keys[i]) i--;
            i++;
            if (node.children[i].keyCount == degree - 1) {
                splitChild(node, i, node.children[i]);
                if (key > node.keys[i]) i++;
            }
            insertNonFull(node.children[i], key, offset);
        }
    }

    private void splitChild(BPlusTreeNode parent, int i, BPlusTreeNode child) {
        BPlusTreeNode newNode = new BPlusTreeNode(degree, child.isLeaf);
        int mid = (degree - 1) / 2;
        
        for (int j = parent.keyCount; j > i; j--) {
            parent.children[j + 1] = parent.children[j];
        }
        parent.children[i + 1] = newNode;
        
        for (int j = parent.keyCount - 1; j >= i; j--) {
            parent.keys[j + 1] = parent.keys[j];
        }
        parent.keys[i] = child.keys[mid];
        
        newNode.keyCount = child.keyCount - mid - 1;
        child.keyCount = mid;
        
        System.arraycopy(child.keys, mid + 1, newNode.keys, 0, newNode.keyCount);
        
        if (child.isLeaf) {
            System.arraycopy(child.offsets, mid + 1, newNode.offsets, 0, newNode.keyCount);
            newNode.next = child.next;
            child.next = newNode;
        } else {
            System.arraycopy(child.children, mid + 1, newNode.children, 0, newNode.keyCount + 1);
        }
        parent.keyCount++;
    }

    public void printTree() {
        Queue<BPlusTreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            BPlusTreeNode node = queue.poll();
            
            StringBuilder sb = new StringBuilder("[");
            for (int i = 0; i < node.keys.length; i++) {
                if (i < node.keyCount) sb.append(node.keys[i]).append(", ");
                else sb.append("-, "); // Replace empty keys with '-'
            }
            if (sb.length() > 1) sb.setLength(sb.length() - 2);
            sb.append("]");
            
            System.out.println(sb.toString());
            if (!node.isLeaf) {
                for (int i = 0; i <= node.keyCount; i++) {
                    queue.add(node.children[i]);
                }
            }
        }
    }

    public static void main(String[] args) {
        BPlusTree tree = new BPlusTree(4);
        tree.insert(10, 1000L);
        tree.insert(20, 2000L);
        tree.insert(5, 500L);
        tree.insert(6, 600L);
        tree.insert(12, 1200L);
        tree.insert(30, 3000L);
        tree.insert(7, 700L);
        tree.insert(17, 1700L);
        
        tree.printTree();
        System.out.println("Search 6: " + tree.search(6));
    }
}

