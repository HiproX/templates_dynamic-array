#pragma once
#include <stdexcept>

template<typename T>
class Array;

template<typename T>
std::ostream& operator<<(std::ostream&, const Array<T>&);

template<typename T>
class Array final
{
public:
// Typedefs
	typedef T value_type;
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef T& reference;
	typedef const T& const_reference;
	typedef unsigned size_type;
// Constructors & Destructor
	Array(void);
	Array(const size_type&);
	Array(const Array&);
	template<typename T1> Array(const Array<T1>&);
	Array(iterator, iterator);
	~Array(void);
// Iterators
	iterator begin(void);
	iterator end(void);
	const_iterator begin(void) const;
	const_iterator end(void) const;
// Sizes
	size_type size(void) const;
	bool empty(void) const;
	size_type capacity(void) const;
	void resize(size_type);
	void reserve(size_type);
// Access to elements
	reference operator[](size_type);
	const_reference operator[](size_type) const;
	reference front(void);
	reference back(void);
	const_reference front(void) const;
	const_reference back(void) const;
// Methods  of  modification
	void push_back(const value_type&);
	void pop_back(void);
	void clear(void);
	void swap(Array&);
	template<typename T1> void swap(Array<T1>&);
	void assign(const value_type&);
	template<typename T1> void assign(const typename Array<T1>::value_type&);
// Operators
	Array& operator=(const Array&);
	template<typename T1> Array& operator=(const Array<T1>&);
	//friend std::istream& operator>> <>(std::istream&, Array<T>&);
	//friend std::ostream& operator<< <>(std::ostream&, const Array<T>&);
private:
	size_type Size;
	size_type Count;
	value_type *data;
};

#include "array.hpp"