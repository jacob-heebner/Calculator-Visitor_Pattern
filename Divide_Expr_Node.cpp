#include "Divide_Expr_Node.h"

//constructor
Divide_Expr_Node::Divide_Expr_Node() {

}

Divide_Expr_Node::Divide_Expr_Node(Expr_Node * n1, Expr_Node * n2) {
	this->left_ = n1;
	this->right_ = n2;
}

//destructor
Divide_Expr_Node::~Divide_Expr_Node() {

}

void Divide_Expr_Node::accept(Eval_Expr_Tree & v) {
	v.Visit_Divide_Node(*this);
}

//priority level
int Divide_Expr_Node::operator_priority() {
	return 1;
}