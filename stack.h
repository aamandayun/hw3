#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;
// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public vector<T>
{
public:
    Stack()= default;
    ~Stack()=default;
    bool empty() const{
        if(vector<T>::size()==0){
            return true;
        }
        return false;
    }
    size_t size() const{
        return vector<T>::size();
    }
    void push(const T& item){
        vector<T>::push_back(item);
    }
    void pop(){
        if(vector<T>::empty()){
            throw std::underflow_error("popping from an emtpy stack");
        }else{
            vector<T>::pop_back();
        }
    }

    const T& top() const{
        if(vector<T>::empty()){
            throw std::underflow_error("stack is empty");
        }else{
            return vector<T>::back();
        }
    } 
};

#endif