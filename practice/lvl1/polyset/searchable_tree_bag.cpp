#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int n) const {
  node *nod = tree;
  while (nod != NULL){
    if (nod->value > n)
      nod = nod->r;
    else if (nod->value < n)
      nod = nod->l;
    else
      return true;
  }
  return false;
}
