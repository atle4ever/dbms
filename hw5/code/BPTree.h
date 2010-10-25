#ifndef __BPTREE_H__
#define __BPTREE_H__

#include <string>
#include <vector>

//---------------------------------------------------------
// B+Tree class template
//---------------------------------------------------------
//
template<typename Key, typename Data, int NODE_SIZE>
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

    // Bulk-loading operator
    void bulk(std::vector< std::pair<Key, Data> >& pairs);

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
    Iterator end() { return Iterator(); }

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
template<typename Key, typename Data, int NODE_SIZE>
class BPTree<Key, Data, NODE_SIZE>::Node
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
template<typename Key, typename Data, int NODE_SIZE>
class BPTree<Key, Data, NODE_SIZE>::BranchNode : public Node
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
template<typename Key, typename Data, int NODE_SIZE>
class BPTree<Key, Data, NODE_SIZE>::LeafNode : public Node
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
template<typename Key, typename Data, int NODE_SIZE>
class BPTree<Key, Data, NODE_SIZE>::Iterator
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
    typename BPTree<Key, Data, NODE_SIZE>::LeafNode* leaf;
    int index;
};

//---------------------------------------------------------
// Template definitions
#include "BPTree.cc"
//---------------------------------------------------------

#endif // __BPTREE_H__
