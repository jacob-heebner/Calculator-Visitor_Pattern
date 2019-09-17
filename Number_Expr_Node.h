//number node

#ifndef NUMBER_EXPR_NODE_H
#define NUMBER_EXPR_NODE_H

#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"

class Number_Expr_Node : public Expr_Node {
public:
	//constructor
	Number_Expr_Node(int n);
	//destructor
	virtual ~Number_Expr_Node(void);
	//evaluate
	virtual int getnumber(void) const;
	//used to traverse tree
	void accept(Eval_Expr_Tree & v);
protected:
	int n_;
};

#endif