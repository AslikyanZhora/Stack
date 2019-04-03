#pragma once

template<typename T>
class Stack
{
public:
	virtual int size() const = 0;
	virtual bool empty() const = 0;
	virtual const T& top() = 0;
	virtual void push(const T& value) = 0;
	virtual void pop() = 0;
	virtual ~Stack(){}
};