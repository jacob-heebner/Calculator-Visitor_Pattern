#include "Binary_Expr_Node.h"

//constructor
Binary_Expr_Node::Binary_Expr_Node() {

}

//destructor
Binary_Expr_Node::~Binary_Expr_Node() {
	delete left_;
	delete right_;
}

void Binary_Expr_Node::accept(Eval_Expr_Tree & v) {
	
}

//returns right child
Expr_Node * Binary_Expr_Node::getright() const {
	return this->right_;
}

//returns left child
Expr_Node * Binary_Expr_Node::getleft() const {
	return this->left_;
}

//sets right child
Expr_Node * Binary_Expr_Node::setright(Expr_Node * right) {
	this->right_= right;
}

//sets left child
Expr_Node * Binary_Expr_Node::setleft(Expr_Node * left) {
	this->left_ = left;
}

int Binary_Expr_Node::operator_priority() {
	return 0;
}