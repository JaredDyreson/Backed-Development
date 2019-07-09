#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <cassert>

#define MIN_VECTOR_SIZE 15

namespace learning{

	// forward declaration

	template <typename T> class vector;
	template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& iv);
	template <typename T> bool operator==(const vector<T>& a, const vector<T>& b);
	template <typename T> bool operator!=(const vector<T>& a, const vector<T>& b);
	template <typename T>

	class vector{
		private:
			std::string name;
			size_t size_, capacity_;
			T* data_;
		public:
			// constructors and destructors
			vector() : vector(MIN_VECTOR_SIZE){}
			vector(size_t c): size_(0), capacity_(c), data_(new T[c]){}
			vector& operator=(const vector<T> &v);
			~vector();

			// helper functions

			void copy(const vector<T>& other);
			void resize(size_t newsize);
			void print();
			void push_back(T val);
			void pop_back();
			void vector_test();

			// attributes

			size_t size() const;
			size_t capacity() const;

			T* begin() const;
			T* end() const;

			T front() const;
			T& front();
			T back() const;
			T& back();

			// overloaded operators
			T  operator[](size_t i) const;
			T& operator[](size_t i);
			friend bool operator== <>(const vector<T>& a, const vector<T>& b);
			friend bool operator!= <>(const vector<T>& a, const vector<T>& b);
			friend std::ostream& operator << <>(std::ostream& os, const vector<T>& iv);
	};

	// getter functions

	template <typename T>
	size_t vector<T>::size() const{ return size_; }

	template <typename T>
	size_t vector<T>::capacity() const { return capacity_; }

	template <typename T>
	T* vector<T>::begin() const {return data_; }

	template <typename T>
	T* vector<T>::end() const { return data_+capacity_; }

	template <typename T> 
	T vector<T>::front() const { return operator[](0); }
	template <typename T> 
	T& vector<T>::front(){ return operator[](0); }

	template <typename T> 
	T vector<T>::back() const  { return operator[](capacity_ - 1); }
	template <typename T> 
	T& vector<T>::back(){ return operator[](capacity_ - 1); }

	// constructors and destructors

	template <typename T>
	vector<T>& vector<T>::operator=(const vector<T> &v){
	  if(this != &v){ copy(v); }
	  return *this;
        }

	template <typename T>
	vector<T>::~vector(){
		delete[] data_;
		data_ = nullptr;
	}

	// helper functions

	template <typename T>
	void vector<T>::copy(const vector<T>& other){
		if(data_ != nullptr) { delete[] data_; }
		size_ = other.size_;
		capacity_ = other.capacity_;
		data_ = new T[size_];
		std::copy(other.data_, other.data_+other.size_, data_);
	}
	template <typename T>
		void learning::vector<T>::resize(size_t newsize){
		if (capacity_ > newsize) { throw new std::invalid_argument("new buffer size too small for data"); }
  
		T* newdata = new T[newsize];
		std::copy(data_, data_ + size_, newdata);
		capacity_ = newsize;
		delete [] data_;
		data_ = newdata;
	}
	template <typename T>
	void vector<T>::print(){
		for(size_t i = 0; i < size_; ++i) { std::cout << data_[i] << std::endl; }
	}
	template <typename T>
	void vector<T>::push_back(T val){
		if(size_ >= capacity_) { throw new std::invalid_argument("Buffer overflow"); }
		data_[size_++] = val;
	}
	template <typename T>
	void vector<T>::pop_back(){
		if(capacity_ == 0) { throw new std::invalid_argument("buffer underflow"); }
		else if(capacity_ <= (size_/2)){ resize(size_/2); } // reduce size
		data_[size_--] = T();
		
	}
	template <typename T>
	void vector<T>::vector_test(){
		learning::vector<float> iv;

		for (size_t i = 0; i < iv.size(); ++i) { iv.push_back(0.5 + 2 * i); }
		std::cout << "iv is: " << &iv << "   " << iv << "\n";
		assert(iv[0] == 0.5);
		assert(iv[iv.capacity() - 1] == 2 * (iv.size() - 1) + 0.5);

		learning::vector<float> iu(iv);
		std::cout << "after copy c'tor...\niu is: " << &iu << "   " << iu << "\n";
		assert(iv == iu);

		learning::vector<float> it;
		it = iu;
		std::cout << "after operator=...\nit is: " << &iu << "   " << iu << "\n";
		assert(it == iu);

		iv.push_back(90.9);
		iv.push_back(900.9);
		iv.push_back(90000.9);
		std::cout << "after adding more data, iv is now..." << iv << "\n";

		while (iv.size() > 5) {
		iv.pop_back();
		std::cout << "iv is now..." << iv << "\n";
		}

	}
	// operators

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const vector<T>& iv) {
		for (auto val : iv) { os << val << " "; }
		return os;
	}

	template <typename T>
	T vector<T>::operator[](size_t i) const { return data_[i]; }

	template <typename T>
	T& vector<T>::operator[](size_t i) { return data_[i]; }
	template <typename T>
	bool operator==(const vector<T>& a, const vector<T>& b){
		if(a.size() != b.size() || a.capacity() != b.capacity()) { return false; }
		for(size_t i = 0; i < a.capacity(); ++i){
			if(a[i] != b[i]) { return false; }
		}
	return true;
	}
	template <typename T>
	bool operator!=(const vector<T>& a, const vector<T>& b) { return !(a==b); }
}

