#include<iostream>
using namespace std;

template<typename T>
class vector
{
public:
	vector()
	{
		num = (T*)malloc(sizeof(T) * length);
	}

	vector(int len)//构造数组
	{
		length = len;
		num = (T*)malloc(sizeof(T) * length);
	}

	vector(const vector& res) :
		length{ res.length }
	//拷贝构造函数，当有两个vector时将一个vector赋值给另一个vector
	{
		num = (T*)malloc(sizeof(T) * length);
		memcpy(num, res.num, sizeof(T) * length);
	}

	vector& operator=(const vector& res)
	{
		if (this != &res)
		{
			if (num != nullptr)
			{
				free(num);
			}
			this->length = res.length;
			this->m_size = res.m_size;
			num = (T*)malloc(sizeof(T) * (this->length));
			memcpy(num, res.num, sizeof(T) * (this->length));
		}
		return *this;
	}

	vector(vector&& rhs) :
		length{ rhs.length },num{rhs.num}
	//move
	{
		rhs.length = 0;
		rhs.num = nullptr;
	}
	
	vector& operator=(vector&& rhs)
	{
		if (this != &rhs)
		{
			if (num != nullptr)
			{
				free(num);
			}
			this->num = rhs.num;
			this->length = rhs.length;
			this->m_size = rhs.m_size;
			rhs.num = nullptr;
			rhs.length = 0;
			rhs.m_size = 0;
		}
		return *this;
	}

	~vector()
	{
		if (num != nullptr)
		{
			delete[]num;
		}
	}

	T& operator[](int index)
	{
		return num[index];
	}

	const T& operator[](int index) const
	{
		return num[index];
	}

	void push_back(T element)
	{
		if (m_size == length)
		{
			extendLength();
		}
		num[m_size] = element;
		m_size++;
	}

	void extendLength()//扩容算法
	{

		T* arr = num;
		length = length * 2;
		num = (T*)malloc(sizeof(T) * length);
		memcpy(num, arr, sizeof(T) * m_size);
		free(arr);
	}

	void pop_back()
	{
		m_size--;
	}

	T find_index(int index)//通过下标寻找
	{
		T findnum = num[index];
		return findnum;
	}

	int find_element(T target)//通过元素找下标
	{
		for (int i = 0; i < size(); ++i)
		{
			if (num[i] == target)
			{
				return i;
			}
		}
		return no_pos;
	}

	bool find(T target)//查找是否有这个元素
	{
		for (int i = 0; i < size(); ++i)
		{
			if (num[i] == target)
			{
				return true;
			}
		}
		return false;
	}

	void change(int index, T changenum)
	{
		 num[index] = changenum;
	}

	bool empty()//检查容器是否为空
	{
		if (size() == 0)
		{
			return true;
		}
		return false;
	}

	int size()//返回容纳的元素数
	{
		return m_size;
	}

	int capacity()//返回当前存储空间能够容纳的元素数
	{
		return length;
	}
	
	void clear()
	{
		num = nullptr;
		m_size = 0;
		length = 0;
	}

	void insert(int index,T element)
	{
		m_size++;
		if (m_size == length)
		{
			extendLength();
		}
		for (int i = size(); i > index; i--)
		{
			num[i] = num[i-1];
		}
		num[index] = element;
	}

	void erase(int index)
	{
		for (int i = index; i < size(); ++i)
		{
			num[i] = num[i + 1];
		}
		m_size--;
	}

	void swap(T &a,T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}


private:
	int length = 1;
	int m_size = 0;
	T* num;
public:
	static int no_pos;
};

int vector<int>::no_pos = -1;

int main()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.pop_back();
	arr.pop_back();
	arr.push_back(1);
	arr.capacity();
	arr.change(1, 22);
	arr.empty();
	arr.erase(1);
	arr.find(22);
	arr.find_element(1);
	arr.find_index(0);
	arr.insert(4, 44);
	arr.size();
	arr.swap(arr[1], arr[0]);
	return 0;
}
