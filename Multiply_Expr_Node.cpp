#include "Multiply_Expr_Node.h"

//constructor
Multiply_Expr_Node::Multiply_Expr_Node() {

}

Multiply_Expr_Node::Multiply_Expr_Node(Expr_Node * n1, Expr_Node * n2) {
	this->left_ = n1;
	this->right_ = n2;
}

//destructor
Multiply_Expr_Node::~Multiply_Expr_Node() {

}

void Multiply_Expr_Node::accept(Eval_Expr_Tree & v) {
	v.Visit_Multiply_Node(*this);
}

int Multiply_Expr_Node::operator_priority() {
	return 1;
}