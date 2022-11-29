#pragma once


template <class T>
struct Node {
    Node(T* value) : value(value), next(nullptr) {}
    Node(T* value, Node<T>* next) : value(value), next(next) {}
    T* value;
    Node<T>* next;
};

template <class T>
class List {
private:
    Node<T>* head = nullptr;

    size_t tracked_length = 0;
public:
    List();

    ~List();

    T& operator[](size_t) const;

    void prepend(T*);

    void append(T*);

    size_t length() const;
};
