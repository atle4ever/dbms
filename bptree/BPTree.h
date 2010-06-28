#ifndef __BPTREE_H__
#define __BPTREE_H__

#include <string>
#include <vector>

typedef long Key;
typedef void* Data;
const int NODE_SIZE = 4096;

//---------------------------------------------------------
// B+Tree class template
//---------------------------------------------------------
//
class BPTree
{
public:
    BPTree();

    // Nested classes
    class Node;
    class BranchNode;
    class LeafNode;
    class Iterator;

    // Insert operation
    void insert(Key key, const Data& data);

    // Remove opeartion
    // Returns the number of removed entries
    long remove(Key key);

    // Searches for the iterator to the leftmost entry
    // matches the specified key
    // Returns null iterator if not found
    Iterator search(Key key);

    // Returns the iterator to the leftmost data entry
    Iterator begin();

    // Null iterator for comparison
    Iterator end();

    // Returns a sequence of keys obtained by depth-first search
    std::vector<Key> dfs();

    // Returns information of the tree, for debugging
    std::string inspect();

private:
};


//---------------------------------------------------------
// Base class for B+Tree nodes, Branch node & Leaf node
//---------------------------------------------------------
//
class BPTree::Node
{
public:
    virtual ~Node() {}
    virtual bool isLeaf() = 0;
private:
    friend class BPTree;
};


//---------------------------------------------------------
// Branch node, or intermediate node, or inner node
//---------------------------------------------------------
//
class BPTree::BranchNode : public Node
{
public:
    const static int HEADER_SIZE = 0; // XXX
    const static int MAX_SLOTS   = (NODE_SIZE - HEADER_SIZE - sizeof(Node*))
                                    / (sizeof(Key) + sizeof(Node*));

    bool isLeaf() { return false; }

private:
    Key   keys [MAX_SLOTS];
    Node* child[MAX_SLOTS + 1];

    friend class BPTree;
};


//---------------------------------------------------------
// Leaf node
//---------------------------------------------------------
//
class BPTree::LeafNode : public Node
{
public:
    const static int HEADER_SIZE = sizeof(LeafNode*); // XXX
    const static int MAX_SLOTS   = (NODE_SIZE - HEADER_SIZE)
                                    / (sizeof(Key) + sizeof(Data));

    bool isLeaf() { return true; }

private:
    Key   keys[MAX_SLOTS];
    Data  data[MAX_SLOTS];

    LeafNode* prev;
    LeafNode* next;

    friend class BPTree;
};


//---------------------------------------------------------
// Iterator for scanning index (full scan, range search)
//---------------------------------------------------------
//
class BPTree::Iterator
{
public:
    Iterator() : leaf(0), index(0) {}

    Iterator& operator++();    // Prefix
    Iterator operator++(int) { // Postfix
        Iterator old = *this;
        ++*this;
        return old;
    }
    bool operator==(const Iterator& rhs) {
        return (leaf == rhs.leaf) && (index == rhs.index);
    }
    bool operator!=(const Iterator& rhs) {
        return !(*this == rhs);
    }

    Key   key();
    Data& data();

private:
    BPTree::LeafNode* leaf;
    int index;
};

#endif // __BPTREE_H__
