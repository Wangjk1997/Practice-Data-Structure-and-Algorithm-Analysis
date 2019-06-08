#pragma once
template<typename object>
class Vector
{
public:
	Vector(int init_size);
	Vector(const Vector& rhs);
	~Vector();
	int size(void) const;
	int capacity(void) const;
	bool empty(void) const;
	const Vector& operator=(const Vector& rhs);
	
	void resize(int new_size)
	{
		if (new_size > the_capacity)
		{
			reserve(2 * new_size + 1);
		}
		the_size = new_size;
	}

	void reserve(int new_capacity)
	{
		if (new_capacity < the_size)
		{
			return;
		}
		object* old_array = the_object;
		the_object = new object[new_capacity];
		for (int k = 0; k < the_size; k++)
		{
			the_object[k] = old_array[k];
		}
		the_capacity = new_capacity;
		delete[] old_array;
	}

	object& operator[](int index)
	{
		return the_object[index];
	}
	const object& operator[](int index) const
	{
		return the_object[index];
	}

	void push_back(const object& x)
	{
		if (the_size == the_capacity)
		{
			reserve(2 * the_capacity + 1);
		}
		the_size++;
		object[the_size] = x;
	}

	void pop_back(void)
	{
		the_size--;
	}

	const object& back(void) const
	{
		return the_object[the_size - 1];
	}

	typedef object* iterator;
	typedef const object* const_iterator;

	iterator begin()
	{
		return &the_object[0];
	}
	const_iterator begin() const// this "const" mains the function will never change the member of this class
	{
		return &the_object[0];
	}
	iterator end()
	{
		return &the_object[size()];
	}
	const_iterator end() const
	{
		return &the_object[size()];
	}
	enum
	{
		spare_capacity = 16
	};
private:
	int the_size;
	int the_capacity;
	object* the_object;
};

template<typename object>
Vector<object>::Vector(int init_size)
{
	the_size = init_size;
	the_capacity = the_size + spare_capacity;
	the_object = new object[the_capacity];
}

template<typename object>
Vector<object>::Vector(const Vector& rhs) :the_object(nullptr)
{
	operator=(rhs);
}
template<typename object>
Vector<object>::~Vector()
{
	delete[] the_object;
}

template<typename object>
int Vector<object>::size(void) const
{
	return the_size;
}
template<typename object>
int Vector<object>::capacity(void) const
{
	return the_capacity;
}
template<typename object>
bool Vector<object>::empty(void) const
{
	return (the_size == 0);
}
template<typename object>
const Vector<object>& Vector<object>::operator=(const Vector & rhs)
{
	if (this != &rhs)
	{
		delete[] the_object;
		the_size = rhs.size();
		the_capacity = rhs.capacity();

		the_object = new object[capacity()];
		for (int k = 0; k < size(); k++)
		{
			the_object[k] = rhs.the_object[k];
		}
	}
	return *this;
}