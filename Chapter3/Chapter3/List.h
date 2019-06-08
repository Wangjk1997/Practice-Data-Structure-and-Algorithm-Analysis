#pragma once
template<typename object>
class List
{
private:
	struct Node
	{
		object data;
		Node* prev;
		Node* next;
		Node(const object& d = object(), Node* p = nullptr, Node* n = nullptr)
			: data(d), prev(p), next(n) {}
	};
public:
	class const_iterator
	{
	public:
		const_iterator()
		{
			current = nullptr;
		}
		const object& operator*() const
		{
			return retrieve();
		}
		const_iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		const_iterator& operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}
		const_iterator& operator--()
		{
			current = current->prev;
			return *this;
		}
		const_iterator& operator--(int)
		{
			const_iterator old = *this;
			--(*this);
			return old;
		}
		bool operator== (const const_iterator& rhs)const
		{
			return current == rhs.current;
		}
		bool operator!= (const const_iterator& rhs)const
		{
			return !(*this == rhs);
		}
	protected://for friend
		Node* current;
		object& retrieve()const
		{
			return current->data;
		}
		const_iterator(Node *p) :current(p)
		{}
		friend class List<object>;
	};
	/*template class:
	the class cannot find the member of the base class;
	the solution is this ptr*/
	class iterator:public const_iterator
	{
	public:
		iterator()
		{}
		object & operator*()
		{
			return const_iterator::retrieve();
		}
		const object& operator*() const
		{
			return const_iterator::operator*();
		}
		iterator& operator++()
		{
			this->current = this->current->next;
			return *this;
		}
		iterator& operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
		iterator& operator--()
		{
			this->current = this->current->prev;
			return *this;
		}
		iterator& operator--(int)
		{
			iterator old = *this;
			--(*this);
			return old;
		}
	protected:
		iterator(Node *p) :const_iterator(p)
		{}
		friend class List<object>;
	};

public:
	List()
	{
		init();
	}
	~List()
	{
		clear();
		delete head;
		delete tail;
	}
	List(const List& rhs)
	{
		init();
		*this = rhs;
	}
	const List& operator=(const List& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		clear();
		for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
		{
			push_back(*itr);
		}
		return *this;
	}


	iterator begin()
	{
		return iterator(head->next);
	}
	const const_iterator begin() const
	{
		return const_iterator(head->next);
	}
	iterator end()
	{
		return iterator(tail);
	}
	const const_iterator end() const
	{
		return const_iterator(tail);
	}

	int size(void) const
	{
		return the_size;
	}
	bool empty(void) const
	{
		return size() == 0;
	}

	void clear()
	{
		while (!empty())
		{
			pop_front();
		} 
	}

	object& front()
	{
		return *begin();
	}
	const object& front() const
	{
		return *begin();
	}
	object& back()
	{
		return *--end();
	}
	const object& back() const
	{
		return *--end();
	}
	void push_front(const object& x)
	{
		insert(begin(),x);
	}
	void push_back(const object& x)
	{
		insert(end(), x);
	}
	void pop_front()
	{
		erase(begin());
	}
	void pop_back()
	{
		erase(--end());
	}

	iterator insert(iterator itr, const object& x)
	{
		Node* p = itr.current;
		the_size++;
		Node* new_Node = new Node(x, p->prev, p);
		p->prev->next = new_Node;
		p->prev = new_Node;
		return iterator(new_Node);
	}
	iterator erase(iterator itr)
	{
		Node* p = itr.current;
		iterator return_value(p->next);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		the_size--;
		return return_value;
	}
	iterator erase(iterator from, iterator to)
	{
		for (iterator itr = from; itr != to;)
		{
			itr = erase(itr);
		}
		return to;
	}
private:
	int the_size;
	Node* head;
	Node* tail;
	void init()
	{
		the_size = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
};

