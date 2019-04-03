#pragma once
#include "stack.hpp"
#include <assert.h>

template<typename T>
class ArrayStack :public Stack<T>
{
public:
	ArrayStack(int cap = 100);
	~ArrayStack();
	int size() const;
	bool empty() const;
	const T& top();
	void push(const T& value);
	void pop();							 

private:
	T* m_array;
	int m_capacity;
	int m_top;
};

template<typename T>
ArrayStack<T>::ArrayStack(int cap )
:m_array(new T[m_capacity]), m_capacity(cap), m_top(-1){}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
	delete[] m_array;
	m_array = 0;
}
template<typename T>
int ArrayStack<T>::size() const
{
	return (m_top + 1);
}

template<typename T>
bool ArrayStack<T>::empty()	const
{
	return (m_top < 0);
}

template<typename T>
const T& ArrayStack<T>::top()
{
	assert(!empty());
	return m_array[m_top];
}

template<typename T>
void ArrayStack<T>::push(const T& value)
{
	assert(size() < m_capacity);
	m_array[++m_top] = value;
}

template<typename T>
void ArrayStack<T>::pop()
{
	assert(!empty());
	--m_top;
}
