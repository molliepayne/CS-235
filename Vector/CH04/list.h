#ifndef LIST_H_
#define LIST_H_

#include <stdexcept>
#include <cstddef>

/** Class list implements a subset of the standard
    list class using a double-linked list.
    @author Koffman and Wolfgang
*/
namespace KW {
  
  template<typename Item_Type>
    class list {
    private:
    // Insert definition of nested class DNode here.
#include "DNode.h"
    public:
    // Insert definition of nested class iterator here.
#include "list_iterator.h"
    // Give list access to internal values in iterator.
    friend class iterator;
    // Insert definition of nested class const_iterator here.
#include "list_const_iterator.h"
    // Give list access to internal values in const_iterator.
    friend class const_iterator;
    
    // Data fields
    /** A reference to the head of the list */
    DNode* head;
    /** A reference to the end of the list */
    DNode* tail;
    /** The size of the list */
    int num_items;
    // Functions
    public:
    /** Construct an empty list. */
    list() {
      head = NULL;
      tail = NULL;
      num_items = 0;
    }
    
    /** Construct a copy of a list. */
    list(const list<Item_Type>& other) {
      head = NULL;
      tail = NULL;
      num_items = 0;
      for (const_iterator itr = other.begin(); itr != other.end();
	   ++itr) {
	push_back(*itr);
      }
    }
    
    /** Construct a list from a sequence */
    template <typename iterator>
      list(iterator begin, iterator end) {
      head = NULL;
      tail = NULL;
      while (begin != end) {
	push_back(*begin++);
      }
    }
    
    /** Destroy a list. */
    ~list() {
      while (head != NULL) {
	DNode* current = head;
	head = head->next;
	delete current;
      }
      tail = NULL;
      num_items = 0;
    }
    
    /** Swap this list contents with another one */
    void swap(list<Item_Type>& other) {
      std::swap(head, other.head);
      std::swap(tail, other.tail);
      std::swap(num_items, other.num_items);
    }
    
    /** Assign the contents of one list to another. */
    list<Item_Type>& operator=(const list<Item_Type>& other) {
      // Make a copy of the other list.
      list<Item_Type> temp_copy(other);
      // Swap contents of self with the copy.
      swap(temp_copy);
      // Return -- upon return the copy will be destroyed.
      return *this;
    }
    
    /** Insert an object at the beginning of the list.
        @param item - the item to be added 
    */
    void push_front(const Item_Type& item) {
      head = new DNode(item, NULL, head); // Step 1
      if (head->next != NULL)
	head->next->prev = head;  // Step 2
      if (tail == NULL)    // List was empty.
	tail = head;
      num_items++;
    }
    
    /** Insert an object at the end of the list.
        @param item - the item to be added 
    */
    void push_back(const Item_Type& item) {
      if (tail != NULL) {
	tail->next = new DNode(item, tail, NULL); // Step 1
	tail = tail->next; // Step 2
	num_items++;
      } else {         // List was empty.
	push_front(item);
      }
    }
    
    /** Insert an object at a position in the list
        indicated by an iterator.  The new item is
        inserted before the position indicated by
        the iterator.
        @param pos The iterator that references the 
	           position where the item is to be
	           inserted.
        @param item The item to be inserted
        @return An iterator that references the inserted
	        item.
    */
    iterator insert(iterator pos, const Item_Type& item) {
      // Check for special cases
      if (pos.current == head) {
	push_front(item);
	return begin();
      } else if (pos.current == NULL) {  // Past the last node.
	push_back(item);
	return iterator(this, tail);
      } 
      // Create a new node linked before node referenced by pos.
      DNode* new_node = new DNode(item, 
				  pos.current->prev, 
				  pos.current); // Step 1
      
      // Update links
      pos.current->prev->next = new_node;     // Step 2
      pos.current->prev = new_node;           // Step 3
      num_items++;
      return iterator(this, new_node);
    }
  };
}
    
#endif
