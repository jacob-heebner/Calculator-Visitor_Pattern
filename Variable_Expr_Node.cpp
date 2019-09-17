#include "Variable_Expr_Node.h"

Variable_Expr_Node::Variable_Expr_Node(std::string a)
	:a_(a)
{

}

std::string Variable_Expr_Node::getvariable() const{
	return a_;
}

//traverses tree
void Variable_Expr_Node::accept(Eval_Expr_Tree & v) {
	v.Visit_Variable_Node(*this);
}