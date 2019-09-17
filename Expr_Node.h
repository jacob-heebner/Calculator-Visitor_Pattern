//parent node
//other command nodes will inherit from this

#ifndef EXPR_NODE_H
#define EXPR_NODE_H

class Eval_Expr_Tree;

class Expr_Node {
public:
	//constructor
	Expr_Node(void);
	//destructor
	virtual ~Expr_Node(void);

	//used to traverse tree
	virtual void accept(Eval_Expr_Tree & v) = 0;
	virtual int operator_priority();


};

#endif