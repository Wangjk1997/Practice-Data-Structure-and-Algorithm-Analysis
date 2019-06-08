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
		const_iterator() :current(NULL) {}
		const Object& operator*() const
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
		bool operator== (const const_iterator& rhs)const
		{
			return current==rhs.current
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
	class iterator:public const_iterator
	{
	public:
		iterator()
		{}
		

	private:

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
	const List& operator=(const list& rhs)
	{
		if (this == &rhs)
		{
			return *this
		}
		clear();
		for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
		{
			push_back(*itr);
		}
		return *this;
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

