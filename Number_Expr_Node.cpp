#include "Number_Expr_Node.h"

Number_Expr_Node::Number_Expr_Node(int n) 
	:n_(n)
{

}

Number_Expr_Node::~Number_Expr_Node() {
	
}

//returns number
int Number_Expr_Node::getnumber() const{
	return n_;
}

//traverses tree
void Number_Expr_Node::accept(Eval_Expr_Tree & v) {
	v.Visit_Number_Node(*this);
}