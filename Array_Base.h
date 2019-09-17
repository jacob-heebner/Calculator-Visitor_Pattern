// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _ARRAY_BASE_
#define _ARRAY_BASE_

#include <cstring>

#include "Array_Base.h"
template <typename T>
class Array_Base {
public:
	typedef T type;

	//constructor
	Array_Base(void);
	//size constructor
	Array_Base(size_t length);
	//copy constructor
	Array_Base(const Array_Base & arr);
	//destructor
	~Array_Base(void);
	//equals operator
	const Array_Base & operator = (const Array_Base & rhs);
	//size of array
	size_t size(void) const;
	//memory alocated to array
	size_t max_size(void) const;
	//[] operatro
	T & operator [] (size_t index);
	//const [] operator
	const T & operator [] (size_t index) const;
	//gets size
	T get(size_t index) const;
	//sets size
	void set(size_t index, T value);
	//== operator
	bool operator == (const Array_Base & rhs) const;
	//!= operator
	bool operator != (const Array_Base & rhs) const;
	//fills array
	void fill(T element);
protected:
	void set_size(size_t size);
	void set_max_size(size_t max_size);
private:
	/// Pointer to the actual data.
	T * data_;
	
	/// Current size of the array.
	size_t cur_size_;

	/// Maximum size of the array.
	size_t max_size_;
};



#include "Array_Base.inl"
#include "Array_Base.cpp"

#endif