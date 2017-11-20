#include <stdio.h>
#include <stdlib.h>

typedef struct element *list;
struct element {  int value;
                  list next;  };

list cons(int n, list next) {
  list l = malloc(sizeof(*l));
  l->value = n;
  l->next = next;

  return l;
}

void printList(list l) {
  printf("[");
  while(l) {
    printf("%d", l->value);
    if(l->next) printf(", ");
    l = l->next;
  }
  printf("]\n");
}

int sum_it(list l) {
  int sum;
  for(sum=0; l != NULL; l = l->next) {
    sum += l->value;
  }
  return sum;
}

int sum_rec(list l) {
  if(l==NULL) return 0;
  return l->value + sum_rec(l->next);
}

void rmEvens_it(list *l) {
  if(!l) return;
  while(*l != NULL) {
    if((*l)->value %2 == 0) {
      list tmp = *l;
      *l = (*l)->next;
      free(tmp);
    }
    else {
      l = &(*l)->next;
    }
  }
}

void rmEvens_rec(list *l) {
  if(!l || !*l) return;

  rmEvens_rec(&(*l)->next);

  if((*l)->value % 2 == 0) {
    list tmp = *l;
    *l = (*l)->next;
    free(tmp);
  }
}

int main() {
  list l = cons(8, cons(1, cons(2, cons(3, cons(7, cons(2, NULL))))));

  printList(l);

  printf("%d\n", sum_it(l));
  printf("%d\n", sum_rec(l));

  rmEvens_rec(&l);

  printList(l);
  return 0;
}
