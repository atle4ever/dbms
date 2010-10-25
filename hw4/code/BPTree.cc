#include <string>
#include <sstream>

//
//---------------------------------------------------------
//

template<typename Key, typename Data, int NODE_SIZE>
BPTree<Key, Data, NODE_SIZE>::BPTree() {}

template<typename Key, typename Data, int NODE_SIZE>
std::string
BPTree<Key, Data, NODE_SIZE>::inspect()
{
    std::ostringstream os;
    #define OUTPUT(a) os << # a << ": " << a << '\n'
    OUTPUT(sizeof(BPTree));
    OUTPUT(sizeof(typename BPTree::BranchNode));
    OUTPUT(sizeof(typename BPTree::LeafNode));
    OUTPUT(BranchNode::HEADER_SIZE);
    OUTPUT(BranchNode::MAX_SLOTS);
    OUTPUT(  LeafNode::HEADER_SIZE);
    OUTPUT(  LeafNode::MAX_SLOTS);
    #undef OUTPUT
    return os.str();
}

template<typename Key, typename Data, int NODE_SIZE>
std::vector<Key>
BPTree<Key, Data, NODE_SIZE>::dfs()
{
    // TODO
    std::vector<Key> vec;
    return vec;
}

template<typename Key, typename Data, int NODE_SIZE>
typename BPTree<Key, Data, NODE_SIZE>::Iterator
BPTree<Key, Data, NODE_SIZE>::search(Key key)
{
    // TODO
    Iterator it;
    return it;
}

template<typename Key, typename Data, int NODE_SIZE>
void
BPTree<Key, Data, NODE_SIZE>::insert(Key key, const Data& data)
{
    // TODO
}

template<typename Key, typename Data, int NODE_SIZE>
void
BPTree<Key, Data, NODE_SIZE>::bulk(std::vector< std::pair<Key, Data> >& pairs)
{
    // TODO
}

template<typename Key, typename Data, int NODE_SIZE>
long
BPTree<Key, Data, NODE_SIZE>::remove(Key key)
{
    // TODO
    return 0;
}

//
//---------------------------------------------------------
//

//
//---------------------------------------------------------
//

template<typename Key, typename Data, int NODE_SIZE>
typename BPTree<Key, Data, NODE_SIZE>::Iterator
BPTree<Key, Data, NODE_SIZE>::begin()
{
    // TODO
    Iterator it;
    return it;
}

template<typename Key, typename Data, int NODE_SIZE>
typename BPTree<Key, Data, NODE_SIZE>::Iterator&
BPTree<Key, Data, NODE_SIZE>::Iterator::operator++()
{
    // TODO
    *this = Iterator();
    return *this;
}

template<typename Key, typename Data, int NODE_SIZE>
Key
BPTree<Key, Data, NODE_SIZE>::Iterator::key()
{
    // TODO
    return Key();
}

template<typename Key, typename Data, int NODE_SIZE>
Data&
BPTree<Key, Data, NODE_SIZE>::Iterator::data()
{
    // TODO
}

