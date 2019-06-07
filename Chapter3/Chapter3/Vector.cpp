template<typename object>
#define share_capacity 100
class Vector
{
public:
	Vector(int init_size = 0) :
		the_size(init_size), thecapacity(the_size + share_capacity)
	{
		the_object = new object[the_capacity];
	}
	~Vector();

	int size(void) const
	{
		return the_size;
	}
	int capacity(void) const
	{
		return the_capacity;
	}
	bool empty(void) const
	{
		return (the_size == 0);
	}
private:
	int the_size;
	int the_capacity;
	object the_object;
};

