//subtract node

#ifndef SUBTRACT_EXPR_NODE_H
#define SUBTRACT_EXPR_NODE_H

#include "Binary_Expr_Node.h"

class Subtract_Expr_Node : public Binary_Expr_Node {
public:
	//constructor
	Subtract_Expr_Node(void);
	Subtract_Expr_Node(Expr_Node * n1, Expr_Node * n2);
	//destructor
	virtual ~Subtract_Expr_Node(void);
	//used to traverse tree
	void accept(Eval_Expr_Tree & v);
	int operator_priority();
};

#endif