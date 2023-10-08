#include<iostream>
using namespace std;

template<class T>
class vector
{
private:
	int length;
	int size=0;
	T* num;
public:
	vector(int len)//构造数组
	{
		length = len;
		num = new T[length];
	}
	~vector()
	{
		delete[]num;
	}
	void push_back(T element)
	{
		if (size == length)
		{
			T* arr = num;
			int newlength = length +1;
			num = new T[newlength];
			for (int i = 0; i <size; i++)
			{
				num[i] = arr[i];
			}
			delete[]arr;
			length = newlength;
		}
		num[size] = element;
		size++;
	}

	void pop_back()
	{
		T* arr = num;
		num = new T[length];
		for (int i = 0; i < size-1; i++)
		{
			num[i] = arr[i];
		}
		delete[]arr;
		size--;
	}

	T find_index(int index)//通过下标寻找
	{
		T findnum = num[index];
		return findnum;
	}

	int find_element(T target)//通过元素找下标
	{
		for (int i = 0; i < size; i++)
		{
			if (num[i] == target)
			{
				return i;
			}
		}
		return -1;
	}

	bool find(T target)//查找是否有这个元素
	{
		for (int i = 0; i < size; i++)
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
};

int main()
{
	vector<int>* arr = new vector<int>(3);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->push_back(1);
	arr->pop_back();
	arr->pop_back();
	arr->pop_back();
	arr->pop_back();
	arr->pop_back();
	arr->pop_back();
	arr->pop_back();
	arr->pop_back();
	arr->pop_back();
	arr->change(1, 22);
	arr->find_index(0);
	arr->find_element(1);
	arr->find(22);
	delete arr;
	return 0;
}
