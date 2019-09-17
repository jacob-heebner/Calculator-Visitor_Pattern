#include "Unary_Expr_Node.h"
//constructor
Unary_Expr_Node::Unary_Expr_Node() {

}

//destructor
Unary_Expr_Node::~Unary_Expr_Node() {

}

//evaluate
int Unary_Expr_Node::eval() {
	if (this->child_) {
		return this->child_->eval();
	}
}
void Unary_Expr_Node::accept(Expr_Node_Visitor & v) {
	
}