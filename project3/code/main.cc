#include "BPTree.h"

#include <cstdlib>
#include <assert.h>

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

void functional_test()
{
    // Generate a B+Tree
    typedef BPTree MyTree;
    MyTree tree;
    cout << tree.inspect();

    // Insert values (0 ~ 99)
    const int COUNT = 100;
    vector<Key> keys;
    for (int i = 0; i < COUNT; ++i)
        keys.push_back(i);
    random_shuffle(keys.begin(), keys.end());
    for (int i = 0; i < COUNT; ++i)
        tree.insert(keys[i], NULL);

    // Depth-first search
    vector<Key> dfs_seq(tree.dfs());
    copy(dfs_seq.begin(), dfs_seq.end(),
            ostream_iterator<long>(cout, " "));
    cout << endl;

    // Search operation (50 ~ 70)
    MyTree::Iterator it = tree.search(50);
    while (it != tree.end()) {
        if (it.key() >= 70) break;
        cout << it.key() << ": " << it.data() << '\n';
        ++it;
    }
    cout << endl;

    // This should not be found
    assert(tree.search(COUNT+1) == tree.end());

    // Complete scan
    it = tree.begin();
    for (; it != tree.end(); ++it)
        cout << it.key() << ": " << it.data() << '\n';
    cout << endl;

    // Remove operation
    tree.remove(50);

    // TODO: Duplicate handling
}


int main(int argc, char *argv[]) try
{

    functional_test();
}

catch (std::exception& e)
{
    cerr << e.what() << endl;
}

