#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val){
  //list is empty
  if (empty()){
    Item* newitem = new Item();
    newitem->prev = NULL;
    newitem->next = NULL;
    newitem->first = 0;
    newitem->last = 0;
    newitem->val[newitem->first] = val;
    newitem->last += 1;
    head_ = newitem;
    tail_ = newitem;
  }
  //list is not empty
  else if (tail_->last < ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last += 1;
  }
  //at end of tail_ node
  else{
    Item *ending = new Item();
    ending->prev = tail_;
    ending->next = NULL;
    ending->first = 0;
    ending->last = 0;
    ending->val[ending->first] = val;
    ending->last += 1;
    tail_->next = ending;
    tail_ = ending;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){
  //list is empty
  if (empty()){
    Item* newitem = new Item();
    newitem->prev = NULL;
    newitem->next = NULL;
    newitem->first = 0;
    newitem->last = 0;
    newitem->val[newitem->first] = val;
    newitem->last += 1;
    head_ = newitem;
    tail_ = newitem;
  }
  //list is not empty
  else if (head_->first > 0){
    head_->val[(head_->first) -1] = val;
    head_->first -= 1;
  }
  //head node is filled
  else{
    Item *begining = new Item();
    begining->prev = NULL;
    begining->next = head_;
    begining->first = 0;
    begining->last = 0;
    begining->val[ARRSIZE - 1] = val;
    begining->first = ARRSIZE-1;
    begining->last = ARRSIZE;
    head_->prev = begining;
    head_ = begining;
    
  }
  size_++;
}

void ULListStr::pop_back(){
  //list is empty
  if (empty()){
    return;
  }
  //list has one element
  else if (size_ == 1){
    delete tail_;
    tail_ = NULL;
    head_ = NULL;
    size_ -= 1;
  }
  //list has 1 element in last node
  else if (tail_->last == 1){
    Item *temp = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL;
    delete temp;
    size_ -= 1;
  }
  //list has more then one element in last node
  else{
    tail_->last -= 1;
    size_ -= 1;
  }
  
}

void ULListStr::pop_front(){
  //list is empty
  if (empty()){
    return;
  }
  //list has 1 element
  else if (size_ == 1){
    delete head_;
    tail_ = NULL;
    head_ = NULL;
    size_ -= 1;
  }
  //list has one element in first node
  else if (head_->first == (ARRSIZE - 1)){
    Item *temp = head_;
    head_ = head_->next;
    head_->prev = NULL;
    delete temp;
    size_ -= 1;
  }
  //list has more than one element in last node
  else{
    head_->first += 1;
    size_ -= 1;
  }
}

std::string const & ULListStr::back() const{
  Item *temp = tail_;
  while (temp->last - temp->first == 0){
    temp = temp->prev;
  }
  int point = (temp->last) - 1;
  return temp->val[point];

}

std::string const & ULListStr::front() const{
  Item *temp = head_;
  while (temp->last - temp->first == 0){
    temp =temp->next;
  }
  return temp->val[temp->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  size_t zero = 0;
  //invalid input for loc
  if ((loc > size_) || (loc < zero)){
    return nullptr;
  }
  
  else{
    size_t loc_temp = 0;
    size_t position_temp = head_->first;
    Item *temp = head_;
    while (loc_temp != loc){
      loc_temp++;
      position_temp++;
      if (position_temp == temp->last){
        temp = temp->next;
        position_temp = 0;
      }
    }
    return &temp->val[position_temp];
  }
}