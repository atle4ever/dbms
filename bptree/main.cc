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
	typedef BPTree<long, RecordPtr, 4096> MyTree;
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
	
	// Remove operation
	// TODO
	tree.remove(50);

	// TODO: Duplicate handling
}

void performance_test(long count)
{
	// Generate a B+Tree
	typedef void* RecordPtr;
	typedef BPTree<long, RecordPtr, 128> MyTree;
	MyTree tree;

	Timer t;
	long elapsed;

	// Insert
	srandom(2008);
	t.start();
	for (int i = 0; i < count; ++i)
		tree.insert(random() % count, NULL);
	elapsed = t.stop();
	cout << "Insert " << count << " items: " << elapsed << " us\n";

	// Search
	t.reset();
	t.start();
	for (int i = 0; i < count; ++i)
	{
		MyTree::Iterator it = tree.search(random() % count);
	}
	elapsed = t.stop();
	cout << "Search " << count << " items: " << elapsed << " us\n";
	
	// Remove
	long removed = 0;
	t.reset();
	t.start();
	for (int i = 0; i < count; ++i)
		removed += tree.remove(random() % count);
	elapsed = t.stop();
	cout << "Remove " << count << " items(count: "
		 << removed << "): "
		 << elapsed << " us\n";
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

