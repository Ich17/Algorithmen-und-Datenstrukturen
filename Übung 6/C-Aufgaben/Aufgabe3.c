#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree;
typedef struct node { int key;
                      tree left;
                      tree right;} node;

tree cons(int n, tree l, tree r) {
    tree t = malloc(sizeof(*t));
    t->key = n;
    t->left = l;
    t->right = r;

    return t;
}

int count(tree t, int k) {
  int c = 0;

  if(t==NULL) return 0;
  if(t->key == k) c = 1;

  return c + count(t->left, k) + count(t->right, k);
}

tree baz(tree s, tree t) {
  tree ret;

  if(s==NULL) return NULL;

  ret = (tree) malloc(sizeof(node));
  ret->key = count(t, s->key);
  ret->left = baz(s->left, t);
  ret->right = baz(s->right, t);

  return ret;
}

int leafprod(tree t) {
  if(t==NULL) return 1;

  if(t->left == NULL && t->right == NULL)
    return t->key;

  return t->key * leafprod(t->left) * leafprod(t->right);
}

int main() {
  tree s = cons(2, cons(3, cons(2, NULL, NULL), cons(4, NULL, NULL)), cons(1, NULL, NULL));
  tree t = cons(2, cons(2, NULL, NULL), cons(3, NULL, NULL));

  printf("%d\n", leafprod(s));

  printf("%d\n", leafprod(t));
  return 0;
}
