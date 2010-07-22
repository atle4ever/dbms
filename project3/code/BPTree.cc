#include "BPTree.h"
#include <string>
#include <sstream>

//
//---------------------------------------------------------
//
BPTree::BPTree() {}


std::string BPTree::inspect()
{
    std::ostringstream os;
    #define OUTPUT(a) os << # a << ": " << a << '\n'
    OUTPUT(sizeof(BPTree));
    OUTPUT(sizeof(BPTree::BranchNode));
    OUTPUT(sizeof(BPTree::LeafNode));
    OUTPUT(BranchNode::HEADER_SIZE);
    OUTPUT(BranchNode::MAX_SLOTS);
    OUTPUT(  LeafNode::HEADER_SIZE);
    OUTPUT(  LeafNode::MAX_SLOTS);
    #undef OUTPUT
    return os.str();
}


std::vector<Key> BPTree::dfs()
{
    // TODO
    std::vector<Key> vec;
    return vec;
}


BPTree::Iterator BPTree::search(const Key& key)
{
    // TODO
    Iterator it;
    return it;
}


void BPTree::insert(const Key& key, const Data& data)
{
    // TODO
}


long BPTree::remove(const Key& key)
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


BPTree::Iterator BPTree::begin()
{
    // TODO
    Iterator it;
    return it;
}

BPTree::Iterator BPTree::end()
{
    return Iterator();
}


BPTree::Iterator& BPTree::Iterator::operator++()
{
    // TODO
    *this = Iterator();
    return *this;
}


Key BPTree::Iterator::key()
{
    // TODO
    return Key();
}


Data& BPTree::Iterator::data()
{
    // TODO
}
