#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other) {
	if (this != &other)
		tree_bag::operator=(other);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag() {}

bool searchable_tree_bag::has(int n) const{
	node *nod = tree;
	while (nod != NULL){
		if (nod->value > n)
			nod = nod->l;
		else if (nod->value < n)
			nod = nod->r;
		else
			return true;
	}
	return false;
}
