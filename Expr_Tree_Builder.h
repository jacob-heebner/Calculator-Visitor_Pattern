//tree builder

#ifndef EXPR_TREE_BUILDER_H
#define EXPR_TREE_BUILDER_H

#include "Expr_Builder.h"
#include "Stack.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Number_Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Variable_Expr_Node.h"


class Expr_Tree_Builder : public Expr_Builder {
public:
	Expr_Tree_Builder(void);
	virtual ~Expr_Tree_Builder(void);
	//starts new tree
	virtual void start_expression(void);
	//different build operations
	void build_number(int n);
	void build_add_operator(void);
	void build_subtract_operator(void);
	void build_divide_operator(void);
	void build_mod_operator(void);
	void build_multiply_operator(void);
	void build_open_parenthesis(void);
	void build_close_parenthesis(void);
	void build_variable_operator(std::string a);
	//returns head node
	Expr_Node * get_expression(void);

private:
	bool parentheses;
	int nested;
	Expr_Node * tree_;
	Stack<Expr_Node *> num_stack_;
	Stack<Binary_Expr_Node *> op_stack_;
	std::string expression;
};

#endif