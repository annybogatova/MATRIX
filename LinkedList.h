//
// Created by AnnyB on 25.11.2023.
//

#ifndef LAB3_LINKEDLIST_H
#define LAB3_LINKEDLIST_H

#include "List.h"
#include "Node.h"
#include "Iterator.h"

template <typename T>

class LinkedList: public List<T>{

    Node<T> *front;
    Node<T> *back;
    size_t Size;

public:

    using iterator = Iterator<T>;
    iterator begin(){return Iterator(&front);}
    Iterator<Node<int> *> end(){return Iterator(&back);}

    LinkedList() : front(nullptr), Size(0){};
    ~LinkedList(){
        while (front){
            Node<T> *tmpNode = front;
            front = front->getNext();
            delete tmpNode;
        }
        Size = 0;
    };

    void push_back(const T &data) override{
        try {
            Node<T> *newNode = new Node<T>(data);

            if (Size == 0) {
                front = newNode;
                back = newNode;
            } else {

                back->setNext(newNode);
                newNode->setPrevious(back);
                back = newNode;

//                Node<T> *current = front;
//                while (current->getNext() != nullptr) {
//                    current = current->getNext();
//                }
//                current->setNext(newNode);
//                newNode->setPrevious(current);
            }
            this->Size++;
        }
        catch (std::exception const &err){
            std::cerr << err.what() << std::endl;
        }
    }

    void insert(size_t position, const T &data) override{
        try {
            int counter = 0;
            Node<T> *newNode = new Node<T>(data);
            if(position == 0){
                newNode->setNext(front);
                front->setPrevious(newNode);
                front = newNode;
//            } else if (Size - position == 1) {
//
//                back = newNode;
//
            } else if (Size >= position - 1) {
                Node<T> *current = front;
                while (counter != position) {
                    current = current->getNext();
                    counter++;
                }

                newNode->setNext(current);
                newNode->setPrevious(current->getPrevious());

                (current->getPrevious())->setNext(newNode);

                current->setPrevious(newNode);
            } else {
                throw std::out_of_range("Index out of range");
            }
            Size++;
        }
        catch (const std::out_of_range &err){
            std::cerr << err.what() << std::endl; // add an error location
        }
        catch (const std::exception &err){
            std::cerr << err.what() << std::endl;
        }
    }

    void insert(iterator position, const T &data){

    }

    void erase(std::size_t position) override {
        try {
            if (position == 0) {
                if (front) {
                    Node<T> *toDel = front;
                    front = front->getNext();
                    front->setPrevious(nullptr);
                    delete toDel;
                }
            } else if (position <= Size - 1) {
                Node<T> *current = front;
                int counter = 0;
                while (counter != position) {
                    current = current->getNext();
                    counter++;
                }
                if (current->getNext()) {
                    Node<T> *toDel = current;
                    (current->getPrevious())->setNext(current->getNext());
                    (current->getNext())->setPrevious(current->getPrevious());
                    delete toDel;
                }
            } else {
                throw std::out_of_range("Index out of range");
            }
            Size--;
        } catch (const std::out_of_range &err){
            std::cerr << err.what() << std::endl;
        }
        catch (const std::exception &err){
            std::cerr << err.what() << std::endl;
        }
    }

    std::size_t size() override {
        return Size;
    }


};

#endif //LAB3_LINKEDLIST_H