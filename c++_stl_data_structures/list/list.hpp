#include <string>
#include <iostream>
#include <ostream>

template <typename T>

struct node{
    T data_;
    node *next_, *previous_;
    node() : node(0){}
    node(T value) : data_(value), next_(nullptr), previous_(nullptr){}
    friend std::ostream& operator<<(std::ostream& os, const node<T>& input){
        std::cout << input.data_ << " ";
        return os;
    }
};

template <typename T>
class l_{
    public:

    // constructors and destructors

    l_() : size_(0), head_(nullptr), tail_(nullptr) {}

    // getters

    size_t size() const;
    node<T>* head() const;
    node<T>* tail() const;
    bool empty() const;

    // helper functions
    void push_back(T value_);
    void insert_front(T value) { insert_postion(0, value); };
    void insert_postion(size_t position, T value);
    void delete_position(size_t position);

    void pop_back();
    void print();
    void print_recursive(node<T>* H);

    node<T>* find_key(T value);
    node<T>* find_key_recursive(node<T>* H, T value);

    private:

    size_t size_;
    node<T> *head_, *tail_;

};

// destructor


// getters

template <typename T>
size_t l_<T>::size() const{ return size_; }
template <typename T>
node<T>* l_<T>::head() const { return head_; }
template <typename T>
node<T>* l_<T>::tail() const { return tail_; }
template <typename T>
bool l_<T>::empty() const { return (size_ == 0) ? true : false; }

// helper functions

template <typename T>
void l_<T>::pop_back(){
	delete_position(size_);
}

template <typename T>
void l_<T>::delete_position(size_t position){
	node<T>* temp_ = head_;
	if(head_ == nullptr) { return; }
	size_t counter_ = 0;
	while(counter_ < position && temp_->next_ != nullptr){
		temp_ = temp_->next_;
		++counter_;
	}
	node<T>* t = new node<T>;
	t = temp_;
	t->next_ = temp_->previous_;
	t->previous_ = temp_->next_;
	size_--;
}
//
template <typename T>
void l_<T>::push_back(T value_){ insert_postion(size_, value_); }

template <typename T>
void l_<T>::insert_postion(size_t position, T value){
	node<T>* node_insert_ = new node<T>(value);
	node<T>* temp_ = head_;
	if(head_ == nullptr) {
		head_ = tail_ = node_insert_;
		size_++;
		return;
	}
	size_t counter_ = 0;
	while(counter_ != position && temp_->next_ != nullptr){
		temp_ = temp_->next_;
		++counter_;
	}
	node_insert_->next_ = temp_->next_;
	temp_->next_ = node_insert_;
	temp_->next_->previous_ = node_insert_->next_;
	size_++;
}

template <typename T>
void l_<T>::print(){
    if (empty()) { std::cout << "empty" << std::endl; return; }
    node<T>* t = new node<T>;
    t = head_;
    while(t != nullptr){
        std::cout << *t << " ";
        t = t->next_;
    }
    delete t;
    t = nullptr;
    std::cout << std::endl;
}
template <typename T>
void l_<T>::print_recursive(node<T>* H){
    if(H == nullptr) { std::cout << std::endl; return; }
    std::cout << *H << " ";
    return print_recursive(H->next_);
}
template <typename T>
node<T>* l_<T>::find_key(T value){
    node<T>* t = new node<T>;
    t = head_;
    while(t != nullptr){
        if(t->data_ == value) { return t; }
        t = t->next_;
    }
    delete t;
    t = nullptr;
    return t;

}

template <typename T>
node<T>* l_<T>::find_key_recursive(node<T>* H, T value){
    if(H == nullptr) { return nullptr; }
    else if(H->data_ == value) { return head_; }
    return find_key_recursive(H->next_, value);
}

// tests

void test_list(){
    std::cout << "-----------------------" << std::endl;
    std::cout << "| Testing l_ class....| " << std::endl;
    std::cout << "-----------------------" << std::endl;
    l_<int> a;
    if(a.empty()) { std::cout << "List is empty" << std::endl; }
    a.print();
    std::cout <<  "Current size before adding: " << a.size() << std::endl;
    for(int i = 0; i < 11; ++i){
       a.push_back(i);
    }
    std::cout <<  "Current size after adding: " << a.size() << std::endl;
    std::cout << "Printing...." << std::endl;
    a.print();
    std::cout << "Finding node with value of 1" << std::endl;
    node<int> *t = a.find_key(1);
    if(t != nullptr){
        std::cout << "Found node with value 1 at: " << t << std::endl;
    }
    else{
        std::cerr << "Could not find node with value 1" <<  std::endl;
    }
    node<int> *recursive = a.find_key_recursive(a.head(), 10);
    if(recursive != nullptr) {
        std::cout << "Found value of 10 at: "  << recursive << std::endl;
    }
    else{
        std::cerr << "Could not find node with value of 10" << std::endl;
    }
    std::cout << "Testing pop_back...." << std::endl;
    for(size_t i = 0; i < 11; i++){
	    std::cout << "Size: " << a.size() << std::endl;
	    a.print();
	    a.pop_back();
    }
    a.print();
}
