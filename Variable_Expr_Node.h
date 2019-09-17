//variable node

#ifndef VARIABLE_EXPR_NODE_H
#define VARIABLE_EXPR_NODE_H

#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"

class Variable_Expr_Node : public Expr_Node {
public:
	//constructor
	Variable_Expr_Node(std::string a);
	std::string getvariable(void) const;
	//used to traverse tree
	void accept(Eval_Expr_Tree & v);
protected:
	std::string a_;
};

#endif