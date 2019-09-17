//Divide node

#ifndef DIVIDE_EXPR_NODE_H
#define DIVIDE_EXPR_NODE_H

#include "Binary_Expr_Node.h"

class Divide_Expr_Node : public Binary_Expr_Node {
public:
	//constructor
	Divide_Expr_Node(void);
	Divide_Expr_Node(Expr_Node * n1, Expr_Node * n2);
	//destructor
	virtual ~Divide_Expr_Node(void);
	//used to traverse tree
	void accept(Eval_Expr_Tree & v);
	//priority level
	int operator_priority();
};

#endif