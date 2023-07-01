#include <iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
#include "B+ Tree.h"





pair<Node*,int> BPTree::search(int key) {
    if (root == NULL) {
    
        return make_pair(root,-1);
    } else {
        Node* cursor = root;
        while (cursor->isLeaf == false) {
            int idx = std::upper_bound(cursor->keys.begin(), cursor->keys.end(), key) - cursor->keys.begin();
            cursor = cursor->ptr2TreeOrData.ptr2Tree[idx];  //upper_bound takes care of all the edge cases
        }

        int idx = std::lower_bound(cursor->keys.begin(), cursor->keys.end(), key) - cursor->keys.begin();  //Binary search

        if (idx == cursor->keys.size() || cursor->keys[idx] != key) {
            return make_pair(root,-1);
        }
		
		return make_pair(cursor,idx);
		
    }
}