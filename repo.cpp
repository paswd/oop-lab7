#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include "repo.h"

using namespace std;

Repo::Repo(void) {

}
Repo::~Repo(void) {

}

void Repo::Push(std::shared_ptr<Figure> &&item) {
	/*if (this->stack.empty()) {
		std::shared_ptr<NTree <Figure>> tree_tmp(new NTree<Figure>);
		tree_tmp->Push(item);
		this->stack.push(*tree_tmp);
		return;
	}*/

	TStack <NTree <Figure>> stack_tmp;
	Cluster res_tmp;
	res_tmp.IsOverload = true;
	Cluster insert;
	insert.Element = item;
	insert.Param = item->Square();
	while (!this->stack.empty()) {
		res_tmp = this->stack.top()->Push(insert.Element, insert.Param);
		if (res_tmp.Element != NULL) {
			insert = res_tmp;
		}
		if (res_tmp.IsOverload) {
			stack_tmp.push(this->stack.pop());
		} else {
			break;
		}
	}
	if (this->stack.empty()) {
		std::shared_ptr<NTree <Figure>> tree_tmp(new NTree<Figure>);
		tree_tmp->Push(item);
		this->stack.push(*tree_tmp);
		return;
	}
	while (!stack_tmp.empty()) {
		this->stack.push(stack_tmp.pop());
	}
}

std::shared_ptr<Figure> Repo::Pop(size_t param) {
	TStack <NTree <Figure>> stack_tmp;
	std::shared_ptr<Figure> result;
	while (!this->stack.empty()) {
		std::shared_ptr<NTree <Figure>> tree_tmp = this->stack.pop();
		result = tree_tmp.Pop(param);
		if (!tree_tmp.IsEmpty()) {
			stack_tmp.push(tree_tmp);
		}
		if (result != NULL) {
			break;
		}
	}
	while (!stack_tmp.empty()) {
		this->stack.push(stack_tmp.pop());
	}
}

/*template class TStack<NTree <Figure>>;
template std::ostream& operator<<(std::ostream& os, const TStack<NTree <Figure>>&
stack);*/

