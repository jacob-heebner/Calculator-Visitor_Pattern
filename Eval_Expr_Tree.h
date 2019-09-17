//expr node visitor

#ifndef EVAL_EXPR_TREE_H
#define EVAL_EXPR_TREE_H

#include <map>

#include "Array.h"

class Number_Expr_Node;
class Add_Expr_Node;
class Subtract_Expr_Node;
class Multiply_Expr_Node;
class Divide_Expr_Node;
class Mod_Expr_Node;
class Variable_Expr_Node;

class Eval_Expr_Tree {
public:
	Eval_Expr_Tree(void);
	virtual ~Eval_Expr_Tree(void);

	//methods for visiting concrete nodes
	virtual void Visit_Add_Node(const Add_Expr_Node & node);
	virtual void Visit_Sub_Node(const Subtract_Expr_Node & node);
	virtual void Visit_Multiply_Node(const Multiply_Expr_Node & node);
	virtual void Visit_Divide_Node(const Divide_Expr_Node & node);
	virtual void Visit_Mod_Node(const Mod_Expr_Node & node);
	virtual void Visit_Number_Node(const Number_Expr_Node & node);
	virtual void Visit_Variable_Node(const Variable_Expr_Node & node);
	//fills the map with variables
	void Fill_Variables(std::string variables);
	//clears the map
	void clear_map(void);
	//returns the result of numbernodes
	int result(void);
private:
	int result_;
	std::map<std::string, int> var_map;
};

#endif