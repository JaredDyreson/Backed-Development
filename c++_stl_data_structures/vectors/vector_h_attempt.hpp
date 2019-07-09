#include <iostream>
#include <algorithm>
#include <ostream>

#define MIN_SIZE 15

template <typename T> class v_;
template <typename T> bool operator==(const v_<T>&a, const v_<T>&b);
template <typename T> bool operator!=(const v_<T>&a, const v_<T>&b);
template <typename T> std::ostream& operator<<(std::ostream& os, const v_<T>& input);
template <typename T> std::ostream& operator<<(std::ostream& os, v_<T>& input);
template <typename T>

class v_{
    public:
        // constructors

        v_<T>() : v_<T>(MIN_SIZE){}
        v_<T>(size_t c) : size_(0), capacity_(c), token_(0), data_(new T[c]){}
        v_<T>& operator=(const v_<T>& copy);
        ~v_();
        // getters
        size_t size() const;
        size_t capacity() const;
        size_t token() const;

        // helper functions

        void resize(size_t newsize);
        void copy(const v_<T>& a);
        void push_back(T value);
        void pop_back();
        friend bool operator== <>(const v_<T>&a, const v_<T>&b);
        friend bool operator!= <>(const v_<T>&a, const v_<T>&b);
        friend std::ostream& operator<< <>(std::ostream& os, const v_<T>& input);
        friend std::ostream& operator<< <>(std::ostream& os, v_<T>& input);
        T operator[](size_t position) const;
        T& operator[](size_t position);

        // empty angle bracket "explanation" --> https://stackoverflow.com/questions/20398587/template-function-call-with-empty-angle-brackets/20398650#20398650


        // attributes

        T* begin() const;
        T* end() const;

        T front() const;
        T& front();

        T back() const;
        T& back();

    private:
        size_t size_, capacity_, token_;
        T* data_;
};

template <typename T>
v_<T>& v_<T>::operator=(const v_<T>& input){
    if(*this != &input) { copy(input); }
    return this;
}

template <typename T>
v_<T>::~v_(){ delete [] data_; data_ = nullptr; }

// getters
template <typename T>
size_t v_<T>::size() const{ return size_; }
template <typename T>
size_t v_<T>::capacity() const{ return capacity_; }
template <typename T>
size_t v_<T>::token() const { return token_; }
template <typename T>
T* v_<T>::begin() const { return data_; }
template <typename T>
T* v_<T>::end() const { return data_+size_; }
template <typename T>
T v_<T>::front() const { return operator[](0); }
template <typename T>
T& v_<T>::front() { return operator[](0); }
template <typename T>
T v_<T>::back() const { return operator[](capacity_-1); }
template <typename T>
T& v_<T>::back() { return operator[](capacity_-1); }
// helper

template <typename T>
void v_<T>::resize(size_t newsize){
    if(capacity_ >= newsize) { throw new std::invalid_argument("size is either too small or same as the original capacity"); }
    T* new_data = new T[newsize];
    std::copy(data_, data_+size_, new_data);
    delete[] data_;
    data_ = new_data;
}
template <typename T>
void v_<T>::copy(const v_<T>& other){
    if(data_ != nullptr) { delete[] data_; }
    size_ = other.size();
    capacity_ = other.capacity();
    data_ = new T[size_];
    std::copy(other.data_, other.data_+other.size_, data_);
}

// operators

template <typename T>
bool operator==(const v_<T>&a, const v_<T>&b){
    if(a.capacity() != b.capacity() || a.size() != b.size()){ return false; }
    for(size_t i = 0; i < a.size(); ++i){
        if(a[i] != b[i]) { return false; }
    }
    return true;
}
template <typename T>
bool operator!=(const v_<T>&a, const v_<T>&b){ return !(a==b); }

template <typename T>
std::ostream& operator<<(std::ostream& os, const v_<T>& input){
    for(auto element : input){ std::cout << element << " "; }
    return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, v_<T>& input){
    for(auto element : input){ std::cout << element << " "; }
    input.token_--;
    return os;
}

template <typename T>
T v_<T>::operator[](size_t position) const{ return data_[position]; }
template <typename T>
T& v_<T>::operator[](size_t position){ return data_[position]; }
// helper functions

template <typename T>
void v_<T>::push_back(T value){ data_[size_++] = value; }

template <typename T>
void v_<T>::pop_back() { 
    //if(capacity_ <= (size_/2)){ resize(size_/2); }
    data_[size_--] = T(); 
}

void test(){
    v_<size_t> a(100);
    v_<size_t> b(a);
    if (a == b) { std::cout << "Both vectors are the same" << std::endl; }
    std::cout << "initial capacity: " <<  a.capacity() << std::endl;
    //for(size_t i = 0; i < 25; ++i){
      //  a.push_back(i);
       // std::cout << a[i] << std::endl;
   // }
}
