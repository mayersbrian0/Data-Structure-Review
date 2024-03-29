#ifndef MY_LL
#define MY_LL

template<typename T> struct Node {
    T val;
    Node* next;
};

template<typename T> class LinkedList {
    private:
    Node<T> * head;
    int size;

    public:
    LinkedList();
    ~LinkedList();
    //LinkedList(const LinkedList&); //copy constructor

    LinkedList operator +(LinkedList const &obj);
    int get_size() const;
    bool empty();
    T value_at(unsigned int index) const;
    void push_front(T value);
    T pop_front();
    void push_back(T value);
    T pop_back();
    T front();
    T back();
    void insert(unsigned int index, T value);
    void erase(unsigned int index);
    T value_n_from_end(unsigned int n);
    void reverse(); 
    void print_list();
};


#endif