#ifndef __SINGLETON_H__
#define __SINGLETON_H__

// single ton for free-object (no related with Ref*)
template <class T>
class SingleTon
{
protected:
	static T* _instance;
	SingleTon()
	{
		_instance = (T*) this;
	}
	virtual ~SingleTon()
	{
		_instance = nullptr;
	}
public:
	static T * GetInstance()
	{
		if(_instance)
			return _instance;
		return new T();
	}

	static void CleanInstance()
	{
		if (_instance)
			delete _instance;
	}
};

template <class T>
T* SingleTon<T>::_instance = nullptr;

// single instance for object that belong to cocos2d::PoolManager
template <class T>
class SingleInstance
{
protected:
	static T* _instance;
	SingleInstance()
	{
		_instance = (T*) this;
	}
	virtual ~SingleInstance()
	{
		_instance = nullptr;
	}
public:
	static T * GetInstance()
	{
		return _instance;
	}
};

template <class T>
T* SingleInstance<T>::_instance = nullptr;
#endif//__SINGLETON_H__