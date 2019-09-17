//multiply node

#ifndef Multiply_EXPR_NODE_H
#define Multiply_EXPR_NODE_H

#include "Binary_Expr_Node.h"

class Multiply_Expr_Node : public Binary_Expr_Node {
public:
	//constructor
	Multiply_Expr_Node(void);
	Multiply_Expr_Node(Expr_Node * n1, Expr_Node * n2);
	//destructor
	virtual ~Multiply_Expr_Node(void);
	//used to traverse tree
	void accept(Eval_Expr_Tree & v);
	//priority level
	int operator_priority();
};

#endif