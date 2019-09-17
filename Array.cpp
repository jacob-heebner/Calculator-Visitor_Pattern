// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <iostream>
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array(void)
	:Array_Base<T>(10)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
	:Array_Base<T>(length)
{
	
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
	:Array_Base<T>(length)
{
	this->set_size(0);
	this->set_max_size(0);
	for (int i = 0; i < length; i++) {
		this[i] = fill;
		this->set_size(this->size() + 1);
	}

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & arr)
	:Array_Base<T>(arr)
{
	
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	Array_Base<T> temp_(new_size);
	if (new_size > this->max_size()) {
		for (int i = 0; i < this->size(); i++) {
			temp_.set(i, this->get(i));
		}
		this->set_max_size(new_size);
		this->set_size(0);
		for (int i = 0; i < temp_.size(); i++) {
			this->set(i, temp_[i]);
		}
	}
	else {
		this->set_max_size(new_size);
		this->set_size(new_size);
	}
}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
	for (int i = 0; i < this->size(); i++) {
		if (this[i] == value) {
			return i;
		}
	}
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
	if (start >= this->size()) {
		throw std::out_of_range("Index out of range");
	}
	for (int i = start; i < this->size(); i++) {
		if (this[i] == val) {
			return i;
		}
	}
	return -1;
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
	for (int i = 0; i < this->max_size(); i++) {
		this[i] = value;
		if (i > this->size()) {
			this->set_size(this->size() + 1);
		}

	}
}