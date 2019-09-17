#include "Mod_Expr_Node.h"

//constructor
Mod_Expr_Node::Mod_Expr_Node() {

}

Mod_Expr_Node::Mod_Expr_Node(Expr_Node * n1, Expr_Node * n2) {
	this->left_ = n1;
	this->right_ = n2;
}

//destructor
Mod_Expr_Node::~Mod_Expr_Node() {

}

void Mod_Expr_Node::accept(Eval_Expr_Tree & v) {
	v.Visit_Mod_Node(*this);
}
int Mod_Expr_Node::operator_priority() {
	return 1;
}