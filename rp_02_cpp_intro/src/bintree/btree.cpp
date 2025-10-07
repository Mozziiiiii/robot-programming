#include "btree.h"


using namespace std;

TreeNodeInt::TreeNodeInt(int value_,
                         TreeNodeInt* left_,
                         TreeNodeInt* right_):
  value(value_),
  left(left_),
  right(right_){}
  
TreeNodeInt::~TreeNodeInt(){
    if (left)
        delete left;
    if (right)
        delete right;
}

TreeNodeInt* TreeNodeInt::find(int value_){
    if(value==value_)
        return this;
    if(value<value_){
        if(left)
            return left->find(value_);
        else 
            return nullptr;
    }
    if(value>value_){
        if(right)
            return right->find(value_);
        else
            return nullptr;
    }   
    return nullptr;
}

bool TreeNodeInt::insert(int value_){
    if (value==value_)
        return false;
        if(value_<value){
            if(!left){
                left = new TreeNodeInt(value_);
                return true;
            }
            else
                return left->insert(value_);
        }
        if(value_>value){
            if(!right){
             right = new TreeNodeInt(value_);
                return true;
            }
            else
                return right->insert(value_);
        }
    return false;
}

std::ostream& operator <<(std::ostream& os, const TreeNodeInt& node) {
  if (node.left)
    os << *(node.left);
  os << node.value << " ";
  if (node.right)
    os << *(node.right);
  return os;
}

