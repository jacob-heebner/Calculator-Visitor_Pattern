// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


//
// Stack constructor
//Calls the Array<T> constructor

template <typename T>
Stack <T>::Stack(void)
	:stack_(10)
{
	
}

//
// Stack copy constructor
//
template <typename T>
Stack <T>::Stack(const Stack & stack)
	:stack_(Array<T>(stack.stack_))
{
	
}

//
// ~Stack destructor
//
template <typename T>
Stack <T>::~Stack(void)
{
	//uses arrays deconstructor
}

//
// push, adds element to top of stack
//resizes if elements exceed initial array size
template <typename T>
void Stack <T>::push(T element)
{
	if (stack_.size() >= stack_.max_size()) {
		stack_.resize(stack_.max_size() + 10);
	}
	stack_.set(stack_.size(), element);
}

//
// pop, removes element from stack
//
template <typename T>
void Stack <T>::pop(void)
{
	if (stack_.size() == 0) {
		throw empty_exception();
	}
	stack_.resize(stack_.size() - 1);
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	// COMMENT Check for self assignment.
	//added self assignment check
	for (int i = 0; i < rhs.size(); i++) {
		stack_.set(i, rhs.stack_.get(i));
	} 
	return *this;

}


//
// clears the stack
//pops till stack is to size 0
template <typename T>
void Stack <T>::clear(void)
{
	while (stack_.size() != 0) {

		stack_.pop();
	}
}
