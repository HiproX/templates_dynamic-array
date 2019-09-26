template<typename T>
Array<T>::Array(void)
	: Size{ 2 }, Count{ 0 }
{
	this->data = new T[this->Size];
}

template<typename T>
Array<T>::Array(const typename Array<T>::size_type &n)
//throw(std::bad_alloc, std::domain_error)
	: Count{ 0 }
{
	if ((n == 0) || (n == 1))
	{
		this->Size = 2;
		this->data = new T[this->Size];
	}
	else if (n > 1)
	{
		this->Size = n;
		this->data = new T[this->Size];
	}
	else
	{
		throw std::domain_error("Size can't be less 0.");
	}
}

template<typename T>
Array<T>::Array(const Array<T> &other)
	: Size{ other.Size }, Count{ other.Count }
//throw(std::bad_alloc)
{
	this->data = new T[other.Size];
	for (unsigned i{}; i < other.Count; i++)
	{
		this->data[i] = other.data[i];
	}
}

template<typename T>
template<typename T1>
Array<T>::Array(const Array<T1> &other)
	: Size{ other.Size }, Count{ other.Count }
//throw(std::bad_alloc)
{
	this->data = new T[other->Size];
	for (unsigned i{}; i < other->Count; i++)
	{
		this->data[i] = other.data[i];
	}
}

template<typename T>
Array<T>::Array(typename Array<T>::iterator first,
	typename Array<T>::iterator last)
//throw(std::bad_alloc, std::invalid_argument)
{
	Array<T> tmp{};
	if (first < last)
	{
		while (first != last)
		{
			tmp.push_back(*first++);
		}
	}
	else
	{
		throw std::invalid_argument("iterator firts > last");
	}
	*this = tmp;
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] this->data;
}

template<typename T>
void Array<T>::swap(Array<T> &other)
{
	std::swap(this->data, other.data);
	std::swap(this->Size, other.Size);
	std::swap(this->Count, other.Count);
}

template<typename T>
template<typename T1>
void Array<T>::swap(Array<T1> &other)
{
	std::swap(this->data, other.data);
	std::swap(this->Size, other.Size);
	std::swap(this->Count, other.Count);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		Array<T> tmp{ other };
		this->swap(tmp);
	}
	return *this;
}

template<typename T>
template<typename T1>
Array<T>& Array<T>::operator=(const Array<T1> &other)
{
	if (this != &other)
	{
		Array<T> tmp{ other };
		this->swap(tmp);
	}
	return *this;
}

template<typename T>
typename Array<T>::iterator Array<T>::begin(void)
{
	return this->data;
}

template<typename T>
typename Array<T>::iterator Array<T>::end(void)
{
	return (this->data + this->Count);
}

template<typename T>
typename Array<T>::const_iterator Array<T>::begin(void) const
{
	return this->data;
}

template<typename T>
typename Array<T>::const_iterator Array<T>::end(void) const
{
	return (this->data + this->Count);
}

template<typename T>
typename Array<T>::size_type Array<T>::size(void) const
{
	return this->Count;
}

template<typename T>
bool Array<T>::empty(void) const
{
	return { this->Count == 0 };
}

template<typename T>
typename Array<T>::size_type Array<T>::capacity(void) const
{
	return this->Size;
}

template<typename T>
void Array<T>::reserve(typename Array<T>::size_type newsize)
{
	if (newsize > capacity())
	{
		Array<T>::value_type *newdata = new Array<T>::value_type[newsize];
		for (Array<T>::size_type i{}; i < this->Count; ++i)
		{
			newdata[i] = this->data[i];
		}
		delete[] this->data;
		this->data = newdata;
		this->Size = newsize;
	}
}

template<typename T>
void Array<T>::push_back(const typename Array<T>::value_type &v)
{
	if (this->Count == this->Size)
	{
		this->reserve(this->Size * 2);
	}
	this->data[this->Count++] = v;
}

template<typename T>
void Array<T>::resize(typename Array<T>::size_type newsize)
//throw(std::bad_alloc)
{
	if ((newsize == 0) || (newsize == 1))
	{
		this->Size = 2;
		delete[] this->data;
		this->data = new Array<T>::value_type[this->Size];
		this->Count = 0;
	}
	else if (newsize > 1)
	{
		Array<T>::value_type *newdata = new Array<T>::value_type[newsize];
		Array<T>::size_type sz = (this->Count < newsize ? this->Count : newsize);
		for (Array<T>::size_type i{}; i < sz; ++i)
		{
			newdata[i] = this->data[i];
		}
		for (Array<T>::size_type i{ sz }; i < newsize; ++i)
		{
			newdata[i] = T{};
		}
		delete[] this->data;
		this->data = newdata;
		this->Size = this->Count = sz;
	}
	else
		throw std::domain_error("Array:: New size can't be less 0!");
}

template<typename T>
void Array<T>::pop_back(void)
{
	if (this->Count)
	{
		--Count;
	}
}

template<typename T>
void Array<T>::clear(void)
{
	this->Count = 0;
}

template<typename T>
typename Array<T>::reference Array<T>::operator[]
	(typename Array<T>::size_type index)
//throw(std::out_of_range)
{
	if (index >= this->Count)
	{
		std::cout << index << std::endl;
		throw std::out_of_range("Not valid index");
	}
	return this->data[index];
}

template<typename T>
typename Array<T>::const_reference Array<T>::operator[]
	(typename Array<T>::size_type index) const
//throw(std::out_of_range)
{
	if (index >= this->Count)
	{
		std::cout << index << std::endl;
		throw std::out_of_range("Not valid index");
	}
	return this->data[index];
}

template<typename T>
typename Array<T>::reference Array<T>::front(void)
{
	return this->data[0];
}

template<typename T>
typename Array<T>::reference Array<T>::back(void)
{
	return this->data[this->size() - 1];
}

template<typename T>
typename Array<T>::const_reference Array<T>::front(void) const
{
	return *(this->data);
}

template<typename T>
typename Array<T>::const_reference Array<T>::back(void) const
{
	return this->data[this->size() - 1];
}

template<typename T>
void Array<T>::assign(const typename Array<T>::value_type &v)
{
	for (typename Array<T>::size_type i{}; i < this->capacity(); ++i)
	{
		this->push_back(v);
	}
}

template<typename T>
template<typename T1>
void Array<T>::assign(const typename Array<T1>::value_type &v)
{
	for (typename Array<T>::size_type i{}; i < this->capacity(); ++i)
	{
		this->push_back(v);
	}
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const Array<T> &rhs)
{
	for (typename Array<T>::size_type i{}; i < rhs.size(); ++i)
	{
		os << rhs[i] << " ";
	}
	return os;
}