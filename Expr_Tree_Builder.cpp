#include "Expr_Tree_Builder.h"
#include "Calculator.h"

//constructor
Expr_Tree_Builder::Expr_Tree_Builder() {
	parentheses = false;
	nested = false;
}

Expr_Tree_Builder::~Expr_Tree_Builder() {
	
}

//tree points to the top node
void Expr_Tree_Builder::start_expression() {
	this->tree_ = nullptr;
}

//number
void Expr_Tree_Builder::build_number(int n) {
	if (parentheses) {
		expression += std::to_string(n);
		expression += " ";
	}
	else {
		Expr_Node * num = new Number_Expr_Node(n);
		num_stack_.push(num);
	}
}

//add
void Expr_Tree_Builder::build_add_operator() {
	if (parentheses) {
		expression += "+ ";
	}
	else {
		Binary_Expr_Node * add = new Add_Expr_Node(nullptr, nullptr);
		if (op_stack_.is_empty() != true) {
			if (op_stack_.top()->operator_priority() > 0) {
				op_stack_.top()->setright(num_stack_.top());
				num_stack_.pop();
				op_stack_.top()->setleft(num_stack_.top());
				num_stack_.pop();
				num_stack_.push(op_stack_.top());
				op_stack_.pop();
				op_stack_.push(add);
			}
			else {
				add->setright(num_stack_.top());
				num_stack_.pop();
				add->setleft(num_stack_.top());
				num_stack_.pop();
				num_stack_.push(add);
			}
		}
		else {
			op_stack_.push(add);
		}
	}
}

//subtract
void Expr_Tree_Builder::build_subtract_operator() {
	if (parentheses) {
		expression += "- ";
	}
	else {
		Binary_Expr_Node * subtract = new Subtract_Expr_Node(nullptr, nullptr);
		if (op_stack_.is_empty() != true) {
			if (op_stack_.top()->operator_priority() > 0) {
				op_stack_.top()->setright(num_stack_.top());
				num_stack_.pop();
				op_stack_.top()->setleft(num_stack_.top());
				num_stack_.pop();
				num_stack_.push(op_stack_.top());
				op_stack_.pop();
				op_stack_.push(subtract);
			}
			else {
				subtract->setright(num_stack_.top());
				num_stack_.pop();
				subtract->setleft(num_stack_.top());
				num_stack_.pop();
				num_stack_.push(subtract);
			}
		}
		else {
			op_stack_.push(subtract);
		}
	}
}


//mod
void Expr_Tree_Builder::build_divide_operator() {
	if (parentheses) {
		expression += "/ ";
	}
	else {
		Binary_Expr_Node * divide = new Divide_Expr_Node(nullptr, nullptr);
		if (op_stack_.is_empty() != true) {
			divide->setright(num_stack_.top());
			num_stack_.pop();
			divide->setleft(num_stack_.top());
			num_stack_.pop();
			num_stack_.push(divide);
		}
		else {
			op_stack_.push(divide);
		}
	}
}

//divide
void Expr_Tree_Builder::build_mod_operator() {
	if (parentheses) {
		expression += "% ";
	}
	else {
		Binary_Expr_Node * mod = new Mod_Expr_Node(nullptr, nullptr);
		if (op_stack_.is_empty() != true) {
			mod->setright(num_stack_.top());
			num_stack_.pop();
			mod->setleft(num_stack_.top());
			num_stack_.pop();
			num_stack_.push(mod);
		}
		else {
			op_stack_.push(mod);
		}
	}
}

//multiply
void Expr_Tree_Builder::build_multiply_operator() {
	if (parentheses) {
		expression += "* ";
	}
	else {
		Binary_Expr_Node * multiply = new Multiply_Expr_Node(nullptr, nullptr);
		if (op_stack_.is_empty() != true) {
			multiply->setright(num_stack_.top());
			num_stack_.pop();
			multiply->setleft(num_stack_.top());
			num_stack_.pop();
			num_stack_.push(multiply);
		}
		else {
			op_stack_.push(multiply);
		}
	}
}

//tracks if there are nested parentheses
void Expr_Tree_Builder::build_open_parenthesis() {
	if (parentheses) {
		expression += "( ";
		nested++;
	}
	else {
		parentheses = true;
	}
}

//starts a subtree for parentheses building
void Expr_Tree_Builder::build_close_parenthesis() {
	if (nested > 0) {
		expression += ") ";
		nested--;
	}
	else {
		Expr_Tree_Builder buildersub;
		Calculator * calculator = new Calculator(buildersub);
		expression = expression.substr(0, expression.length() - 1);
		num_stack_.push(calculator->return_subtree(expression));
		parentheses = false;
		expression = "";
	}
}

void Expr_Tree_Builder::build_variable_operator(std::string a) {
	if (parentheses) {
		expression += a;
		expression += " ";
	}
	else {
		Expr_Node * var = new Variable_Expr_Node(a);
		num_stack_.push(var);
	}
}

//returns head node
Expr_Node * Expr_Tree_Builder::get_expression() {
	if (!op_stack_.is_empty()) {
		op_stack_.top()->setright(num_stack_.top());
		num_stack_.pop();
		op_stack_.top()->setleft(num_stack_.top());
		num_stack_.pop();
		num_stack_.push(op_stack_.top());
		op_stack_.pop();
	}
	tree_ = num_stack_.top();

	return tree_;
}