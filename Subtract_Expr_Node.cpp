#include "Subtract_Expr_Node.h"

//constructor
Subtract_Expr_Node::Subtract_Expr_Node() {

}

Subtract_Expr_Node::Subtract_Expr_Node(Expr_Node * n1, Expr_Node * n2) {
	this->left_ = n1;
	this->right_ = n2;
}

//destructor
Subtract_Expr_Node::~Subtract_Expr_Node() {

}


void Subtract_Expr_Node::accept(Eval_Expr_Tree & v) {
	v.Visit_Sub_Node(*this);
}

//priority level
int Subtract_Expr_Node::operator_priority() {
	return 0;
}