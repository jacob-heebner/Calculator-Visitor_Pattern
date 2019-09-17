//mod node

#ifndef MOD_EXPR_NODE_H
#define MOD_EXPR_NODE_H

#include "Binary_Expr_Node.h"

class Mod_Expr_Node : public Binary_Expr_Node {
public:
	//constructor
	Mod_Expr_Node(void);
	Mod_Expr_Node(Expr_Node * n1, Expr_Node * n2);
	//destructor
	virtual ~Mod_Expr_Node(void);
	//used to traverse tree
	void accept(Eval_Expr_Tree & v);
	//priority level
	int operator_priority();
};

#endif