#include "BPTree.h"
#include "Timer.h"

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
    typedef void* RecordPtr;
    typedef BPTree<long, RecordPtr, 512> MyTree;
    MyTree tree;
    cout << tree.inspect();

    // Insert values (0 ~ 99)
    const int COUNT = 100;
    vector<long> keys;
    for (int i = 0; i < COUNT; ++i)
        keys.push_back(i);
    random_shuffle(keys.begin(), keys.end());
    for (int i = 0; i < COUNT; ++i)
        tree.insert(keys[i], NULL);

    // Depth-first search
    vector<long> dfs_seq(tree.dfs());
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
}

void performance_test(long count)
{
    // Generate a B+Tree
    typedef void* RecordPtr;
    typedef BPTree<long, RecordPtr, 256> MyTree;
    MyTree tree;
    MyTree tree2;

    Timer t;
    long elapsed;

    vector< pair<long, RecordPtr> > data(count);

    // Generatre random data
    srandom(2008);
    for(int i = 0; i < count; ++i) {
        data.push_back(pair<long, RecordPtr>(random() % count, NULL));
    }

    // Insert & bulk
    t.start();
    for (int i = 0; i < count; ++i)
        tree.insert(data[i].first, data[i].second);
    elapsed = t.stop();
    cout << "Insert " << count << " items: " << elapsed << " us\n";

    t.reset();
    t.start();
    tree2.bulk(data);
    elapsed = t.stop();
    cout << "Bulk loading " << count << " items: " << elapsed << " us\n";

    // Search
    t.reset();
    t.start();
    for (int i = 0; i < count; ++i) {
        MyTree::Iterator it = tree.search(random() % count);
    }
    elapsed = t.stop();
    cout << "Search " << count << " items: " << elapsed << " us\n";

    t.reset();
    t.start();
    for (int i = 0; i < count; ++i)
    {
        MyTree::Iterator it = tree2.search(random() % count);
    }
    elapsed = t.stop();
    cout << "Search " << count << " items: " << elapsed << " us\n\n";
}

int main(int argc, char *argv[]) try
{

    functional_test();

    performance_test(10000);
    performance_test(100000);
    performance_test(1000000);
}

catch (std::exception& e)
{
    cerr << e.what() << endl;
}

