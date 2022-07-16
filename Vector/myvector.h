#ifndef MY_VEC
#define MY_VEC


template <typename T> class vector {
    private:
    
    T* arr;
    int curr_size;
    unsigned int cap;
    void resize();

    public:

    vector();
    ~vector();
    int size();
    unsigned int capacity();
    bool is_empty();
    int at(unsigned int index);
    void push(T item);
    void insert(T item, unsigned int index);
    void prepend(T item);
    void push();
    int pop();
    void del(unsigned int index);
    void remove(T item);
    int find(T item);
    void print();
};


#endif