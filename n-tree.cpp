#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include "n-tree.h"

#define NTREE_CONST 2
#define MAX_LEVEL_CNT 4

using namespace std;

template <class T> Cluster::Cluster(void) {
	//this->IsEmpty = false;
	this->IsOverload = false;
}
template <class T> Cluster::~Cluster(void) {
	
}


template <class T> NTree::NTree(void) {
	this->Root = NULL;
	this->NConst = NTREE_CONST;
	this->MaxLevelCnt = MAX_LEVEL_CNT;
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

template <class T> Cluster NTree::Push(std::shared_ptr<T> element, size_t param) {
	Cluster extra;
	extra.Element = NULL;

	if (this->Root == NULL) {
		this->Root = new NTreeNode;
		this->Root->Child = NULL;
		this->Root->Parent = NULL;
		this->Root->Level = 0;
		this->Root->ClustersCnt = 0;
		this->Root->Clusters.resize(1);
	}

	NTreeNode *last = this->Root;
	NTreeNode *current = NULL;
	size_t current_pos = 0;
	bool full = false;
	bool found = false;

	Cluster insert;
	insert.Element = element;
	insert.Param = param;

	size_t cnt = 0;
	while (true) {
		for (size_t i = 0; i < last->ClustersCnt; i++) {
			if (last->Clusters[i].Param > param && !found) {
				found = true;
				current = last;
				current_pos = i;
			}
		}
		if (last->Clild == NULL) {
			break;
		}
		cnt++;
		last = last->Child;
	}
	if (!found) {
		extra.IsOverload = true;
		return extra;
	}
	if (last->ClustersCnt >= last->Clusters.size()) {
		if (last->ClustersCnt < this->MaxLevelCnt) {
			last->Child = new NTreeNode;
			last->Child->Child = NULL;
			last->Child->Parent = last;
			last->Child->Level = last->Level + 1;
			last->Child->ClustersCnt = 0;
			last->Clild->Clusters.resize(last->Clusters.size() * this->NConst)
			last = last->Child;
		} else {
			extra = last->Clusters[last->ClustersCnt - 1];
			extra.IsOverload = true;
		}
	}
	//if (last->ClustersCnt < last->Clusters.size()) {
	last->ClustersCnt++;
	NTreeNode *tmp_node = last;
	while (tmp_node != NULL && tmp_node != current) {
		if (tmp_node != last) {
			tmp_node->Child->Clusters[0] = tmp_node->Clusters[tmp_node->ClustersCnt - 1];
		}
		for (size_t i = tmp_node->ClustersCnt - 1; i > 0; i--) {
			tmp_node->Clusters[i] = tmp_node->Clusters[i - 1];
		}
	}
	if (current != last) {
		current->Child->Clusters[0] = current->Clusters[tmp_node->ClustersCnt - 1];
	}
	for (size_t i = current->ClustersCnt - 1; i > current_pos; i--) {
		current->Clusters[i] = current->Clusters[i - 1];
	}
	current->Clusters[current_pos] = element;
	//}
	return extra;
}

template <class T> std::shared_ptr<T> NTree::Pop(size_t param) {
	std::shared_ptr<T> res = NULL;
	NTreeNode *node_tmp = this->root;
	NTreeNode *node_prev = NULL;
	bool found = false;
	while (node_tmp != NULL && !found) {
		for (size_t i = 0; i < node_tmp->ClustersCnt; i++) {
			if (found) {
				if (i == 0) {
					size_t size_tmp = node_tmp->Parent->ClustersCnt;
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
	//node_prev->Clusters.resize(node_prev->Clusters.size() - 1);
	node_prev->ClustersCnt--;
}
template <class T> bool NTree::IsEmpty(size_t param) {
	return this->Root->ClustersCnt > 0;
}

template <class T> std::ostream& operator<<(std::ostream& os, const NTree<T>& ntree) {
	/*std::shared_ptr<TStackItem<T>> item = stack.head;

	while(item != NULL) {
		os << *item;
		item = item->GetNext();
	}*/
	NTreeNode *ths = this->Root;
	while (ths != NULL) {
		for (size_t i = 0; i < ths->ClustersCnt; i++) {
			cout << *(ths->Clusters[i].Element);
		}
		ths = ths->Child;
	}

	return os;
}

template class NTree<Figure>;
template class NTreeNode<Figure>;
template class Cluster<Figure>;
template std::ostream& operator<<(std::ostream& os, const NTree<Figure>&
ntree);
