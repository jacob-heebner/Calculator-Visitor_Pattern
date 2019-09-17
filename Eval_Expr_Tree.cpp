#include "Eval_Expr_Tree.h"

#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Number_Expr_Node.h"
#include "Variable_Expr_Node.h"
#include <iostream>


//constructor
Eval_Expr_Tree::Eval_Expr_Tree() {
	
}

//destructor
Eval_Expr_Tree::~Eval_Expr_Tree() {
	
}

//visit add
void Eval_Expr_Tree::Visit_Add_Node(const Add_Expr_Node & node) {
	int left;
	node.getleft()->accept(*this);
	left = result_;
	int right;
	node.getright()->accept(*this);
	right = result_;
	result_ = left + right;
}

//visit subtract
void Eval_Expr_Tree::Visit_Sub_Node(const Subtract_Expr_Node & node) {
	int left;
	node.getleft()->accept(*this);
	left = result_;
	int right;
	node.getright()->accept(*this);
	right = result_;
	result_ = left - right;
}

//visit multiply
void Eval_Expr_Tree::Visit_Multiply_Node(const Multiply_Expr_Node & node) {
	int left;
	node.getleft()->accept(*this);
	left = result_;
	int right;
	node.getright()->accept(*this);
	right = result_;
	result_ = left * right;
}


//visit divide
void Eval_Expr_Tree::Visit_Divide_Node(const Divide_Expr_Node & node) {
	int left;
	node.getleft()->accept(*this);
	left = result_;
	int right;
	node.getright()->accept(*this);
	right = result_;
	if (right == 0) {
		throw 0;
	}
	else {
		result_ = left / right;
	}
}

//visit mod
void Eval_Expr_Tree::Visit_Mod_Node(const Mod_Expr_Node & node) {
	int left;
	node.getleft()->accept(*this);
	left = result_;
	int right;
	node.getright()->accept(*this);
	right = result_;
	if (right == 0) {
		throw 0;
	}
	else {
		result_ = left % right;
	}
}

//visit number
void Eval_Expr_Tree::Visit_Number_Node(const Number_Expr_Node & node) {
	result_ = node.getnumber();
}

//visit variable
void Eval_Expr_Tree::Visit_Variable_Node(const Variable_Expr_Node & node) {
	std::string temp = node.getvariable();
	result_ = var_map.find(temp)->second;
}


//adds variables to map and then asks for values
void Eval_Expr_Tree::Fill_Variables(std::string variables) {
	for (int i = 0; i < variables.size(); i++) {
		std::string temp(1, variables[i]);
		var_map[temp];
	}
	std::map<std::string, int>::iterator it;
	for (it = var_map.begin(); it != var_map.end(); it++) {
		int number;
		std::cout << it->first << " = ";
		std::cin >> number;
		var_map[it->first] = number;
	}
}

//clears the map
void Eval_Expr_Tree::clear_map() {
	var_map.clear();
}

int Eval_Expr_Tree::result() {
	return this->result_;
}