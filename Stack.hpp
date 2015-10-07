#include <iostream>

template <class T>
class Stack
{
	T* data_;
	size_t maxsize_;
	size_t currsize_;
	public:
		Stack() { maxsize_ = currsize_ = 0; }
		Stack(size_t max) : 
			maxsize_(max) {
			data_ = new T[maxsize_];
		}
		void push_back(const T data);
		void pop_back();
		T top();
		void grow();
		void print();
};

template <class T>
void Stack<T>::print()
{
	for(int i = 0; i < currsize_; i++) {
		std::cout << data_[i] << std::endl;
	}
}

template <class T>
void Stack<T>::push_back(const T data)
{
	if(currsize_ >= maxsize_)
		grow();
	data_[++currsize_] = data;
}