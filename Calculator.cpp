#include "Calculator.h"

Calculator::Calculator(Expr_Tree_Builder & builder)
	:builder_(builder) {

}

//parses through infix notation and gives to builder to convert to a tree
bool Calculator::parse_expr(const std::string & infix) {
	std::istringstream input(infix);
	std::string token;

	builder_.start_expression();
	while (!input.eof()) {
		input >> token;
		if (token == "+") {
			builder_.build_add_operator();
		}
		else if (token == "-") {
			builder_.build_subtract_operator();
		}
		else if (token == "/") {
			builder_.build_divide_operator();
		}
		else if (token == "%") {
			builder_.build_mod_operator();
		}
		else if (token == "*") {
			builder_.build_multiply_operator();
		}
		else if (token == "(") {
			builder_.build_open_parenthesis();
		}
		else if (token == ")") {
			builder_.build_close_parenthesis();
		}
		else if (isdigit(token[0]) || isdigit(token[1])) {
			builder_.build_number(std::stoi(token));
		}
		else {
			if (token != "QUIT") {
				std::string temp = token;
				builder_.build_variable_operator(temp);
				variables += temp;
			}
			else {
				return false;
			}
		}
	}
	return true;

}

//evaluates
int Calculator::evaluate(const std::string & infix) {
	Eval_Expr_Tree eval;
	if (parse_expr(infix)) {
		//when there is a variable the program outputs some junk data number and print statment
		//I am not sure what the cause is or how to fix it
		eval.Fill_Variables(variables);
		Expr_Node * expr = builder_.get_expression();
		expr->accept(eval);
		eval.clear_map();
		return eval.result();
	}
}

//for parentheses, create subtree and add to original tree
Expr_Node * Calculator::return_subtree(std::string string) {
	if (parse_expr(string)) {
		return builder_.get_expression();
	}
}

//checks for valid infix notations
bool Calculator::check_valid_input(std::string infix) {
	std::istringstream input(infix);
	std::string token;
	int operator_count = 0;
	int operand_count = 0;
	int open_parentheses = 0;
	int closed_parentheses = 0;
	while (!input.eof()) {
		input >> token;
		if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
			operator_count++;
		}
		else if (isdigit(token[0]) || isalpha(token[0])) {
			operand_count++;
		}
		else if (token == "(") {
			open_parentheses++;
		}
		else if (token == ")") {
			closed_parentheses++;
		}
		else if (token == "=") {
			return false;
		}
	}
	if (operator_count < operand_count && closed_parentheses == open_parentheses) {
		return true;
	}
	return false;
}