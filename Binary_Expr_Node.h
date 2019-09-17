//binary node

#ifndef BINARY_EXPR_NODE_H
#define BINARY_EXPR_NODE_H

#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"

class Binary_Expr_Node : public Expr_Node {
public:
	//constructor
	Binary_Expr_Node(void);
	//destructor
	virtual ~Binary_Expr_Node();
	//used to traverse tree
	void accept(Eval_Expr_Tree & v);
	//gets right child
	Expr_Node * getright(void) const;
	//gets left child
	Expr_Node * getleft(void) const;
	//sets right child
	Expr_Node * setright(Expr_Node * right);
	//sets left child
	Expr_Node * setleft(Expr_Node * left);
	virtual int operator_priority();
protected:
	Expr_Node * right_;
	Expr_Node * left_;
};

#endif