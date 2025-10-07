#include <iostream>
#include "btree.h"

using namespace std;

int main() {
  TreeNodeInt* n=new TreeNodeInt(5);
  n->insert(10);
  n->insert(1);
  n->insert(2);
  n->insert(4);
  cerr << "ok here" << endl;
  cout << *n << endl;

  cerr << "insertress of obj 4: " << n->find(4) << endl;
}
