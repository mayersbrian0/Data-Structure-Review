#include <iostream>
#include "mylinkedlist.h"

template<typename T> LinkedList<T>::LinkedList() {
    head = NULL;
    size = 0;
}

template<typename T> LinkedList<T>::~LinkedList() {
    Node<T>* temp = head;
    while (head != NULL) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<typename T> LinkedList<T> LinkedList<T>::operator+(LinkedList<T> const &obj) {
    int size1 = get_size();
    int size2 = obj.get_size();
    LinkedList<T> new_list;
    int i = 0, j = 0;

    while (head && j < size2) {
        new_list.push_back(value_at(i) + obj.value_at(j));
        i++;
        j++;
    }

    return new_list;
}

template<typename T> int LinkedList<T>::get_size() const {
    return size;
}

template<typename T> bool LinkedList<T>::empty() {
    return size == 0;
}

template<typename T>  T LinkedList<T>::value_at(unsigned int index) const {
    if (head == NULL || index >= size) {
        std::cout << "Empty List or Invalid Index\n";
        return -1;
    }

    Node<T>* temp = head;
    while (index > 0) {
        index--;
        temp = temp->next;
    }

    return temp->val;
}

template<typename T> void LinkedList<T>::push_front(T value) {
    Node<T>* new_node = new Node<T>;
    new_node->val = value;
    new_node->next = head;
    head = new_node;
    size++;
}

template<typename T> T LinkedList<T>::pop_front() {
    if (head == NULL) {
        std::cout<< "Empty List\n";
        return -1;
    }

    Node<T>* temp = head;
    int ret = temp->val;
    head = head->next;
    delete temp;
    size--;
    return ret;
}

template<typename T> void LinkedList<T>::push_back(T value) {
    Node<T>* temp = head;
    Node<T>* new_node = new Node<T>;
    new_node->val = value;
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
        size++;
        return;
    }

    while (temp->next != NULL) temp = temp->next;

    temp->next = new_node;
    size++;
}

template<typename T> T LinkedList<T>::pop_back() {
    int ret = 0;

    if (head == NULL) {
        std::cout<< "List is Empty\n";
        return -1;
    }

    else if (head->next == NULL) {
        ret = head->val;
        delete head;
        head = NULL;
        size--;
        return ret;
    }

    else {
        Node<T>* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        ret = temp->next->val;
        delete temp->next;
        temp->next = NULL;
        size--;
        return ret;
    }
}

template<typename T> T LinkedList<T>::front() {
    if (head == NULL) {
        std::cout << "List Empty\n";
        return -1;
    }

    return head->val;
}

template<typename T> T LinkedList<T>::back() {
    if (head == NULL) {
        std::cout << "List Emtpy\n";
        return -1;
    }

    Node<T>* temp = head;
    while (temp->next != NULL) temp = temp->next;
    return temp->val;
}


template<typename T> void LinkedList<T>::insert(unsigned int index, T value) {
    if (head == NULL || index > size) {
        std::cout << "List Empty or Index out of range\n";
        return;
    }

    if (index == 0) {
        push_front(value);
        return;
    }

    int i = 0;
    Node<T>* new_node = new Node<T>;
    new_node->val = value;
    Node<T>* temp = head;

    while (i < index -1) {
        i++;
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    size++;
}


template<typename T> void LinkedList<T>::erase(unsigned int index) {
    if (head == NULL || index >= size) {
        std::cout << "List Empty or Index out of Range\n";
        return;
    }

    if (index == 0) {
        pop_front();
        return;
    }

    int i = 0;
    Node<T>*temp = head;
    Node<T>*remove;

    while (i < index -1) {
        i++;
        temp = temp->next;
    }

    remove = temp->next;
    temp->next = remove->next;
    delete remove;
    size--;    
}

//need to pass a default value because of the function being generic
//note the check before the helper makes sure that a value other than default (unless its the same as head) is returned
template<typename T> T value_from_n_helper(Node<T>* node, unsigned int n, int& i, T value) {
    if (node == NULL) return value;

    T ret = value_from_n_helper(node->next, n, i, value );
    i++;
    if (i == n) return node->val;
    else return ret;
}

template<typename T> T LinkedList<T>::value_n_from_end(unsigned int n) {
    if (head == NULL || n > size) {
        std::cout << "List empty or n greater than size\n";
        return head->val;
    }

    int i = 0;
    return value_from_n_helper(head, n, i, head->val);
}

template<typename T> void LinkedList<T>::reverse() {
    Node<T>* new_list = NULL;

    while (head != NULL) {
        Node<T>* temp = head;
        head = head->next;
        temp->next = new_list;
        new_list = temp;
    }

    head = new_list;
}

template<typename T> void LinkedList<T>::print_list() {
    Node<T> * temp = head;
    while (temp != NULL) {
        std::cout << temp->val << "->";
        temp = temp->next;
    }
    std::cout << "\n";
}