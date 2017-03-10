// Copyright 2016 Thomas Machado

#ifndef STRUCTURES_LINKED_STACK_H
#define STRUCTURES_LINKED_STACK_H

#include <stdexcept>

namespace structures {

//! Uma classe
    /*!
    Descreve comportamento de uma pilha encadeada
*/
template<typename T>
class LinkedStack {
 public:
    //! Contrutor
    /*!
        Construtor default
    */
    LinkedStack() {
        top_ = nullptr;
        size_ = 0;
    }

    //! Destrutor
    /*!
        Destrutor default
    */
    ~LinkedStack() {
        clear();
    }
    //! Um método
    /*!
        Limpa a pilha deletando todos os nodes
    */
    void clear() {
        Node* current = top_;
        Node* previous;
        top_ = nullptr;
        size_ = 0;
        while (current != nullptr) {
            previous = current;
            current = current->next();
            delete previous;
        }
    }

    //! Um método
    /*!
        \param data
        Adiona elemento data na pilha
    */
    void push(const T& data) {
        Node* newNode;
        newNode = new Node(data, top_);
        if (newNode == nullptr) {
            throw std::out_of_range("Full List");
        } else {
            top_ = newNode;
            size_ = size_ + 1;
        }
    }

    //! Um método
    /*!
        \return T
        Retira elemento data da lista
    */
    T pop() {
        Node* quit;
        T back;
        if (empty()) {
            throw std::out_of_range("Empty List");
        } else {
            quit = top_;
            back = quit->data();
            top_ = quit->next();
            size_ = size_ - 1;
            delete quit;
            return back;
        }
    }
    //! Um método
    /*!
        \return T&
        retorna elemento do topo da lista
    */
    T& top() const {
        if (empty()) {
            throw std::out_of_range("Empty List");
        }
        return top_->data();
    }

    //! Um método constante
    /*!
        \return bool
        Indica se a lista está vazia ou não
    */
    bool empty() const {
        return size_ == 0;
    }

    //! Um método constante
    /*!
        \return size_t
        Indica posição tamanho da lista
    */
    std::size_t size() const {
        return size_;
    }

 private:
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}
        T& data() {
            return data_;
        }
        const T& data() const {
            return data_;
        }

        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }

        void next(Node* next) {
            next_ = next;
        }

     private:
        T data_;
        Node* next_;
    };

    Node* top_;  // nodo-topo
    std::size_t size_;  // tamanho
};

}  // namespace structures

#endif
