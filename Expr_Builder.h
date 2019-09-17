
#ifndef EXPR_BUILDER_H
#define EXPR_BUILDER_H

#include "Expr_Node.h"

class Expr_Builder {
public:
	//starts new tree
	virtual void start_expression(void);
	//different build operations
	virtual void build_number(int n) = 0;
	virtual void build_add_operator(void) = 0;
	virtual void build_subtract_operator(void) = 0;
	virtual void build_divide_operator(void) = 0;
	virtual void build_mod_operator(void) = 0;
	virtual void build_multiply_operator(void) = 0;
	virtual void build_open_parenthesis(void) = 0;
	virtual void build_close_parenthesis(void) = 0;

	//get current expression
	virtual Expr_Node * get_expression(void) = 0;
};

#endif