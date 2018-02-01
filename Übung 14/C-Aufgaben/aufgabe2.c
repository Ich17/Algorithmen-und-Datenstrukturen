#include <stdio.h>

int ident(tree t1, tree t2) {
  if (t1 == NULL && t2 == NULL) {
    return 1;
  }
  if (t1 == NULL || t2 == NULL) {
    return 0;
  }
  return t1->key == t2->key && ident(t1->left, t2->left)
    && ident(t1->right, t2->right);
}


int internal(tree t) {
  if(t == NULL) {
    return 0;
  }
  if (t->left == NULL && t->right == NULL) {
    return 0;
  }
  return 1 + internal(t->left) + internal(t->right);
}


void lRot(tree* tp) {
  tree rightChild;

  if(tp == NULL || *tp == NULL) {
    return;
  }

  rightChild = (*tp)->right;
  (*tp)->right = rightChild->left;
  rightChild->left = *tp;
  *tp = rightChild;
}
