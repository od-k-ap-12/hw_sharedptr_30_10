#pragma once
template <class T>
class MySharedPtr
{
	T* ptr;
	int count;
public:
	MySharedPtr();
	MySharedPtr(T* _ptr);
	MySharedPtr(MySharedPtr<T>& sp);
	~MySharedPtr();
	int GetCount();
	void operator=(MySharedPtr<T>& sp);
	T* Get();
};

template<class T>
inline MySharedPtr<T>::MySharedPtr()
{
	ptr = nullptr;
	count = 0;
}

template<class T>
inline MySharedPtr<T>::MySharedPtr(T* _ptr)
{
	ptr = _ptr;
	count = 1;
}

template<class T>
inline MySharedPtr<T>::MySharedPtr(MySharedPtr<T>& sp)
{
	ptr = sp.ptr;
	count = sp.count;
	count++;
	sp.count++;
}

template<class T>
inline MySharedPtr<T>::~MySharedPtr()
{
	if (count == 1) {
		delete ptr;
	}
	count--;

}

template<class T>
inline int MySharedPtr<T>::GetCount()
{
	return count;
}

template<class T>
inline void MySharedPtr<T>::operator=(MySharedPtr<T>& sp)
{
	ptr = sp.ptr;
	count = sp.count;
	count++;
	sp.count++;
}

template<class T>
inline T* MySharedPtr<T>::Get()
{
	return ptr;
}
