#ifndef STACK_HPP
#define STACK_HPP
#pragma once
#include <iterator>
#include <cstddef>

template<typename T>
class Stack{
    private:
        int m_capacity = 0;
        std::size_t m_size = 10; //default as 10
        T *m_array; //m_array
        
        bool is_full(){
            if (m_capacity == m_size)
            {
                return true;
            }

            return false;
        }

        bool is_empty(){
            if (m_capacity == 0)
            {
                return true;
            }
            return false;
        }

    public:
        class Iterator{
            public:
                using iteraotr_category = std::bidirectional_iterator_tag;
                using difference_type = std::ptrdiff_t;
                using value_type = T;
                using pointer = T*;
                using reference = T&;

                //Constructor
                Iterator(pointer ptr) : m_ptr(ptr) {}

                //Operator to return dereferenced pointer of Iterator
                reference operator*()const {return *m_ptr;}
                //Operator to return pointer
                pointer operator->() { return m_ptr; }

                //Prefix increment
                Iterator& operator++() {m_ptr++; return *this;}// To increase a pointer and return it's own object

                //Postfix increment
                //To return increased pointer obeject of Iterator and return object Iterator
                Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

                //friend key word is:
                //this comment is to remind me what "friend" key word is *JUST IGNORE IT*
                /* 
                useful concepts in such situations where you need to give a function or another class 
                access to internal data, while still keeping it hidden from the outside world.
                */


                //To compare two m_ptr of a, b 
                friend bool operator==(const Iterator& a, const Iterator& b){ return a.m_ptr == b.m_ptr;};
                friend bool operator!=(const Iterator& a, const Iterator& b){ return a.m_ptr != b.m_ptr;};
            private:
                pointer m_ptr;
        };

        Stack(){
            m_array = new T [m_size];
        }

        Iterator begin() { return Iterator(&m_array[0]); }
        Iterator end()   { return Iterator(&m_array[m_capacity]); }//end of m_array must be the last elements
        //Returns current ize of stack
        unsigned int get_size(){
            return m_size;
        }

        //resize stack
        void resize(unsigned int newSize){
            T* newArray = new T[newSize];
            for (int i = 0; i < m_capacity; ++i) {
                newArray[i] = m_array[i];
            }
            delete[] m_array;
            m_array = newArray;
            m_size = newSize;
        }
        
        //Push
        void push(const T &item){
            if(is_full() == true){
                resize(m_size * 2);
                push(item);
            }
            m_array[m_capacity] = item;
            m_capacity++;
        }

        unsigned int get_capacity(){
            return m_capacity;
        }

        //Pop
        T pop(){
            if (is_empty() == true)
            {
                return static_cast<T>(0);
            }
            m_capacity--;
            return m_array[m_capacity];
        }

        ~Stack(){
            delete[] m_array;
        }
};

#endif
