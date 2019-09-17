#include <iostream>
#include "Add_Expr_Node.h"
#include "Number_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Eval_Expr_Tree.h"
#include "Calculator.h"

// COMMENT Good job!
//thank you

int main()
{
	std::string expression;
	//loop till QUIT is typed
	while (expression != "QUIT") {
		try {
			Expr_Tree_Builder builder;
			Calculator * calculator = new Calculator(builder);
			std::cout << "enter an expression: ";
			std::getline(std::cin, expression);
			if (expression == "QUIT") {
				std::cout << "Calculator exiting..." << std::endl;
			}
			else if (!calculator->check_valid_input(expression)) {
				std::cout << "Please enter a valid infix expression" << std::endl;
			}
			else {
				std::cout << calculator->evaluate(expression) << std::endl;
			}
		}
		//catch divide by 0 errors
		catch (int x) {
			std::cout << "Divide by 0 error." << std::endl;
		}
		//catch unexpected errors
		catch (...) {
			std::cout << "An error has occured." << std::endl;
		}
	}
	return 0;
} 
