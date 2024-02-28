#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

#include <vector>
using namespace std;

template<typename T>
struct less{
  bool operator()(const T& a, const T& b) const{
    return a>b;
  }
};

template <typename T, typename PComparator = std::less<T> >
class Heap : public vector<T>
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : m_ary(m), comparator(c){}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap()= default;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);



  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m_ary;
  PComparator comparator;

  void heapifyUp();
  void heapifyDown();

};

// Add implementation of member functions here

template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  vector<T>::push_back(item);
  heapifyUp();
}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  if((vector<T>::size()==0)){
    return true;
  }
  return false;
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("emtpy stack");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vector<T>::front();
  //or 
  //return vector<T>::back(); ??

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("popping from an emtpy stack");
  }

  swap(this->front(), this->back());

  vector<T>::pop_back();
  heapifyDown();

}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return vector<T>::size();
}



template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(){
  int index = vector<T>::size()-1;
  int parent;

  while(index>0){
    parent = (index-1)/m_ary;
    if(comparator(this->at(index), this->at(parent))){
      swap(this->at(index), this->at(parent));
      index = parent;
    }else{
      break;
    }
  }
}


template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(){
  int index = 0;

  int child, minChild;

  while(true){
    child = m_ary *index+1;
    if(child>=this->size()){
      break;
    }

    minChild = child;

    for(int i = 1; i < m_ary && (child + i) < this->size(); ++i) {
          if (comparator(this->at(child + i), this->at(minChild))) {
            minChild = child + i;
          }
    }

    if (comparator(this->at(minChild), this->at(index))) {
      std::swap(this->at(index), this->at(minChild));
        index = minChild;
      } else {
          break;
        }
  }


}


#endif

