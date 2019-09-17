#include "Add_Expr_Node.h"

//constructor
Add_Expr_Node::Add_Expr_Node() {

}

//constructs left and right nodes
Add_Expr_Node::Add_Expr_Node(Expr_Node * n1, Expr_Node * n2) {
	this->left_ = n1;
	this->right_ = n2;
}

//destructor
Add_Expr_Node::~Add_Expr_Node() {

}

//accepts visitor
void Add_Expr_Node::accept(Eval_Expr_Tree & v) {
	v.Visit_Add_Node(*this);
}

//priority level
int Add_Expr_Node::operator_priority() {
	return 0;
}