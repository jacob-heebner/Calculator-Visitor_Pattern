//unary node

#ifndef UNARY_EXPR_NODE_H
#define UNAR_EXPR_NODE_H

#include "Expr_Node.h"

class Unary_Expr_Node : public Expr_Node {
public:
	//constructor
	Unary_Expr_Node(void);
	//destructor
	virtual ~Unary_Expr_Node(void);
	//evaluate
	virtual int eval(void);
	//used to traverse tree
	void accept(Expr_Node_Visitor & v);
protected:
	Expr_Node * child_;
};

#endif