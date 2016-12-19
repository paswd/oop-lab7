#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include "n-tree.h"

#define NTREE_CONST 2
#define MAX_ELEMENTS_CNT 4

using namespace std;


template <class T> NTree::NTree(void) {
	this->Root = NULL;
	this->NConst = NTREE_CONST;
	//this->ClusterSize = cluster_size;
}

template <class T> NTree::~NTree(void) {
	NodeNTree *tmp = this->Root;

	while (tmp != NULL) {
		NTreeNode *ths_tmp = tmp;
		tmp = tmp->Child;
		delete ths_tmp;
	}
}

template <class T> bool NTree::Push(std::shared_ptr<T> element, size_t param) {
	for ()
}

template <class T> std::shared_ptr<T> NTree::Pop(size_t param) {
	std::shared_ptr<T> res = NULL;
	NTreeNode *node_tmp = this->root;
	NTreeNode *node_prev = NULL;
	bool found = false;
	while (node_tmp != NULL && !found) {
		for (size_t i = 0; i < node_tmp->Clusters.size(); i++) {
			if (found) {
				if (i == 0) {
					size_t size_tmp = node_tmp->Parent->Clusters.size();
					node_tmp->Parent->Clusters[size_tmp - 1] = node_tmp->Clusters[i];
				} else {
					node_tmp->Clusters[i - 1] = node_tmp->Clusters[i];
				}
			} else if (param == node_tmp->Clusters[i].Param) {
				found = true;
				res = node_tmp->Clusters[i].Element;
			}
		}
		node_prev = node_tmp;
		node_tmp = node_tmp->Child;
	}
	node_prev->Clusters.resize(node_prev->Clusters.size() - 1);
}
