//calculator wrapper

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <ctype.h>
#include "Stack.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"

class Calculator {
public:
	//constructor
	Calculator(Expr_Tree_Builder & builder);
	//parses through infix expression
	bool parse_expr(const std::string & infix);
	//evaulates 
	int evaluate(const std::string & infix);
	//for evaluating expressions with subtrees
	Expr_Node * return_subtree(std::string string);
	//checks if valid infix
	bool check_valid_input(std::string infix);
private:
	Expr_Tree_Builder builder_;
	std::string variables;
};

#endif