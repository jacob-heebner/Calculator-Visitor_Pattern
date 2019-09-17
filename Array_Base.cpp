// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array_Base.h"
#include <iostream>
#include <stdexcept>         // for std::out_of_bounds exception

//
//Constructor
//
template <typename T>
Array_Base <T>::Array_Base(void)
	:cur_size_(0),
	max_size_(10),
	data_(new T[10])
{

}

//
//Constuctor with length
//
template <typename T>
Array_Base <T>::Array_Base(size_t length)
	:cur_size_(0),
	max_size_(length),
	data_(new T[length])
{
	
}

//
//copy constructor
//
template <typename T>
Array_Base <T>::Array_Base(const Array_Base & arr)
	:cur_size_(arr.cur_size_),
	max_size_(arr.max_size_),
	data_(new T[max_size_])
{
	for (int i = 0; i < cur_size_; i++) {
		data_[i] = arr.data_[i];
	}
}

//
//destructor
//
template <typename T>
Array_Base <T>::~Array_Base(void)
{
	delete[] data_;
}

//
//assignement operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
	if (data_ == rhs.data_) {
		return *this;
	}

	max_size_ = rhs.max_size();
	cur_size_ = rhs.size();
	for (int i = 0; i < cur_size_; i++) {
		data_[i] = rhs.data_[i];
	}

	return *this;
}

//
//assignement operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	if (index >= cur_size_) {
		throw std::out_of_range("Index out of range");
	}
	return data_[index];
}

//
// assignement operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if (index >= cur_size_) {
		throw std::out_of_range("Index out of range");
	}
	return data_[index];
}

//
// get
//
template <typename T>
T Array_Base <T>::get(size_t index) const
{
	if (index >= cur_size_) {
		throw std::out_of_range("Index out of range55");
	}
	return data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set(size_t index, T value)
{
	if (index >= max_size_) {
		throw std::out_of_range("Index out of range");
	}
	data_[index] = value;
	if (index + 1 > cur_size_) {
		cur_size_++;
	}
}

template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	
	if (this == rhs.data_) {
		return true;
	}

	for (int i = 0; i < cur_size_; i++) {
		if (data_[i] != rhs[i]) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	if (data_ == rhs.data_) {
		return false;
	}
	return true;
}

template <typename T>
void Array_Base <T>::fill(T value)
{
	for (int i = 0; i < max_size_; i++) {
		data_[i] = value;
		if (i > cur_size_) {
			cur_size_++;
		}

	}
}

//
//used to manipulate size because size is private
//
template <typename T>
void Array_Base <T>::set_size(size_t size) {
	cur_size_ = size;
}

//
//used to manipulate max size because max size is private
//
template <typename T>
void Array_Base <T>::set_max_size(size_t max_size) {
	max_size_ = max_size;
	
}