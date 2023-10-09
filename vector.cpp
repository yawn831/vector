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

	vector(vector&& rhs) :
		length{ rhs.length },num{rhs.num}
	//move
	{
		rhs.length = 0;
		rhs.num = nullptr;
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
		int newlength =length+ pow(2, m_index);
		num = (T*)malloc(sizeof(T) * newlength);
		memcpy(num, arr, sizeof(T) * m_size);
		free(arr);
		length = newlength;
		m_index++;
	}

	int GetSize()//获取数组元素个数
	{
		return m_size;
	}

	void pop_back()
	{
		T* arr = num;
		num = (T*)malloc(sizeof(T) * length);
		memcpy(num, arr, sizeof(T) * (m_size - 1));
		free(arr);
		m_size--;
	}

	T find_index(int index)//通过下标寻找
	{
		T findnum = num[index];
		return findnum;
	}

	int find_element(T target)//通过元素找下标
	{
		for (int i = 0; i < m_size; i++)
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
		for (int i = 0; i < m_size; i++)
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
		if (GetSize() == 0)
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
		m_index = 0;
		length = 0;
	}

	void insert(int index,T element)
	{
		m_size++;
		if (m_size == length)
		{
			extendLength();
		}
		for (int i = m_size ; i > index; i--)
		{
			num[i] = num[i-1];
		}
		num[index] = element;
	}

	void erase(int index)
	{
		for (int i = index; i < size(); i++)
		{
			num[i] = num[i + 1];
		}
	}

	void swap(int &a,int &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}


private:
	int m_index=0;
	int length = 0;
	int m_size = 0;
	T* num;
public:
	static int no_pos;
};

int vector<int>::no_pos = -1;

int main()
{
	vector<int> arr;
	arr.push_back(11);
	arr.push_back(12);
	arr.swap(arr[0], arr[1]);
	return 0;
}
