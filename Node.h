//
// Created by AnnyB on 07.12.2023.
//

#ifndef LAB3_NODE_H
#define LAB3_NODE_H

template <typename T>
struct Node {

    Node<T> *getNext() const {
        return this->NextNode;
    }

    void setNext(Node<T> *next) {
        Node::NextNode = next;
    }

    Node<T> *getPrevious() const {
        return this->PreviousNode;
    }

    void setPrevious(Node<T> *previous) {
        Node::PreviousNode = previous;
    }

    T getData() const {
        return this->NodeData;
    }

    void setData(T data) {
        Node::NodeData = data;
    }

    Node& operator=(const Node<T> & right){
        if(this == &right){
            return *this;
        }
        this->NodeData = right.NodeData;
        this->PreviousNode = right.PreviousNode;
        this->NextNode = right.NextNode;
        return *this;
    }

    Node(T data) : NodeData(data), PreviousNode(nullptr), NextNode(nullptr){}
    Node() : NodeData(nullptr), PreviousNode(nullptr), NextNode(nullptr){}; // default constructor


private:
    Node<T> *PreviousNode;
    Node<T> *NextNode;
    T NodeData;
};


#endif //LAB3_NODE_H
