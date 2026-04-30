# Data Structures Implementation in C++

A comprehensive implementation of core linear data structures—**Linked Lists**, **Stacks**, and **Queues**—using C++ with proper memory management and modular project structure.

## Project Overview

This project implements fundamental data structures using two different memory allocation approaches:
- **Contiguous Memory (Array-based)**: For StackArray and QueueArray
- **Linked Memory (Pointer-based)**: For LinkedList, StackLinkedList, and QueueLinkedList

The objective is to master memory management, understand LIFO/FIFO principles, and demonstrate professional software development practices through modular design.

## Project Structure

```
data_structures_assignment/
├── Node.h                 # Common node structure for linked structures
├── LinkedList.h           # Singly Linked List interface
├── LinkedList.cpp         # Singly Linked List implementation
├── Stack.h                # Stack interfaces (Array & LinkedList)
├── Stack.cpp              # Stack implementations
├── StackArr.cpp           # Stack Array implementation (legacy)
├── StackLL.cpp            # Stack LinkedList implementation (legacy)
├── Queue.h                # Queue interfaces (Array & LinkedList)
├── Queue.cpp              # Queue implementations
├── main.cpp               # Driver program with test cases
└── README.md              # This file
```

## File Descriptions

### Headers (.h files)

#### **Node.h**
- Defines the `Node` struct for linked list nodes
- Contains `val` (integer value) and `next` (pointer to next node)
- Constructor for easy node creation with initialization

#### **LinkedList.h**
- Interface for singly linked list operations
- Private members: `head`, `tail`, `length`
- Methods: `insertAtHead()`, `insertAtEnd()`, `add()`, `deleteValue()`, `display()`, `get_length()`

#### **Stack.h**
- Two classes: `StackArray` and `StackLinkedList`
- **StackArray**: Dynamic array-based LIFO with capacity management
- **StackLinkedList**: Pointer-based LIFO with O(1) operations
- Methods: `push()`, `pop()`, `peek()`, `isEmpty()`

#### **Queue.h**
- Two classes: `QueueArray` and `QueueLinkedList`
- **QueueArray**: Circular array-based FIFO with modular arithmetic
- **QueueLinkedList**: Pointer-based FIFO with O(1) operations
- Methods: `enqueue()`, `dequeue()`, `peek()`, `isEmpty()`, `isFull()` (for array), `get_length()`

### Implementation Files (.cpp files)

#### **LinkedList.cpp**
- Implements all singly linked list operations
- Proper memory management with dynamic node allocation
- `deleteValue(int val)`: Removes first occurrence of value
- `display()`: Prints list in format: `1 -> 2 -> 3`

#### **Stack.cpp**
- Implements both StackArray and StackLinkedList
- **StackArray**:
  - Handles stack overflow when capacity is reached
  - Uses `head` index to track top of stack
- **StackLinkedList**:
  - Uses `top` pointer for O(1) push/pop
  - Maintains length for quick empty checks

#### **Queue.cpp**
- Implements both QueueArray and QueueLinkedList
- **QueueArray (Circular)**:
  - Uses modular arithmetic: `(index + 1) % capacity`
  - Efficient reuse of array space
  - `front` and `rear` indices for FIFO order
- **QueueLinkedList**:
  - Maintains `front` and `rear` pointers
  - O(1) enqueue and dequeue operations

#### **main.cpp**
- Driver program with comprehensive test cases
- Tests LinkedList: insertAtHead, insertAtEnd, deleteValue, display
- Tests StackArray: push, pop, peek, overflow handling
- Tests StackLinkedList: push, pop, peek
- Tests QueueArray: enqueue, dequeue, peek, circular wrapping
- Tests QueueLinkedList: enqueue, dequeue, peek

## Compilation & Execution

### Compile
```bash
g++ main.cpp LinkedList.cpp Stack.cpp Queue.cpp -o dsa_test
```

### Run
```bash
./dsa_test
```

**Output**: Test results showing all data structure operations with values and state changes.

## Data Structures Overview

### 1. Singly Linked List (FIFO - conceptually, but accessible at any position)

**Operations**:
- `insertAtHead(int val)`: Add element at beginning - O(1)
- `insertAtEnd(int val)`: Add element at end - O(1)
- `add(int val, int index)`: Add at specific position - O(n)
- `deleteValue(int val)`: Remove first occurrence - O(n)
- `display()`: Print all elements - O(n)
- `get_length()`: Return number of elements - O(1)

**Memory**: Dynamic allocation with pointers

### 2. Stack (LIFO - Last In, First Out)

#### Array-Based Stack
- **Push**: Add to top (end of array) - O(1)
- **Pop**: Remove from top - O(1)
- **Peek**: View top element - O(1)
- **Capacity**: Fixed, raises error if overflow
- **Use Case**: Function call stacks, expression evaluation

#### Linked List-Based Stack
- **Push**: Add node at top - O(1)
- **Pop**: Remove node from top - O(1)
- **Peek**: View top node - O(1)
- **Capacity**: Dynamic, grows as needed
- **Use Case**: Memory-efficient when size unknown

### 3. Queue (FIFO - First In, First Out)

#### Circular Array-Based Queue
- **Enqueue**: Add to rear with circular wrapping - O(1)
- **Dequeue**: Remove from front with circular wrapping - O(1)
- **Circular Index**: `(index + 1) % capacity` prevents waste
- **Use Case**: Task scheduling, printer queues, BFS

#### Linked List-Based Queue
- **Enqueue**: Add node at rear - O(1)
- **Dequeue**: Remove node from front - O(1)
- **Flexible Size**: Dynamic allocation
- **Use Case**: Process queues, message passing

## Memory Management

### Key Principles
1. **Every `new` has a `delete`**: Destructors clean up all allocations
2. **Array cleanup**: `delete[]` for dynamically allocated arrays
3. **Node cleanup**: `delete` for individual nodes
4. **Circular references**: None (singly linked)

### Destructors
- **LinkedList**: Frees all nodes via `remove_first()` loop
- **StackArray**: Frees dynamic array
- **StackLinkedList**: Frees all nodes via `pop()` loop
- **QueueArray**: Frees dynamic array
- **QueueLinkedList**: Frees all nodes via `dequeue()` loop

## Encapsulation

All data members are **private**:
- Direct access prevented (prevents corruption)
- Access only through public methods
- Methods validate operations before modification

## Time Complexity

| Operation | LinkedList | StackArray | StackLL | QueueArray | QueueLL |
|-----------|-----------|-----------|---------|-----------|---------|
| Insert    | O(n)      | O(1)      | O(1)    | O(1)      | O(1)    |
| Remove    | O(n)      | O(1)      | O(1)    | O(1)      | O(1)    |
| Search    | O(n)      | O(n)      | O(n)    | O(n)      | O(n)    |
| Access    | O(n)      | O(1)      | O(1)    | O(1)      | O(1)*   |

*Front element only for Queue

## Example Usage

### Linked List
```cpp
LinkedList list;
list.insertAtEnd(10);
list.insertAtHead(5);
list.display();              // Output: 5 -> 10
list.deleteValue(5);
list.display();              // Output: 10
```

### Stack Array
```cpp
StackArray stack(3);
stack.push(1);
stack.push(2);
cout << stack.peek();        // Output: 2
cout << stack.pop();         // Output: 2
```

### Queue LinkedList
```cpp
QueueLinkedList queue;
queue.enqueue(100);
queue.enqueue(200);
cout << queue.dequeue();     // Output: 100
cout << queue.peek();        // Output: 200
```

## Circular Queue Index Wrapping

**Example with capacity = 3**:
```
Initial:    front=0, rear=-1
Enqueue 1:  rear=(−1+1)%3=0   → arr[0]=1
Enqueue 2:  rear=(0+1)%3=1    → arr[1]=2
Enqueue 3:  rear=(1+1)%3=2    → arr[2]=3
Dequeue:    front=(0+1)%3=1   → return arr[0]=1
Enqueue 4:  rear=(2+1)%3=0    → arr[0]=4 (reuse space)
```

Prevents array overflow by reusing dequeued space!

## Key Features

✅ **Modular Design**: Separate headers and implementations  
✅ **Include Guards**: Prevents multiple inclusion errors  
✅ **Proper Encapsulation**: Private members, public interfaces  
✅ **Complete Memory Management**: All allocations freed  
✅ **Error Handling**: Checks for underflow/overflow conditions  
✅ **Circular Queue**: Efficient space utilization  
✅ **Comments**: Clear explanation of algorithms  
✅ **Professional Code**: Follows C++ best practices  

## Assignment Requirements Met

- ✅ Linked Lists: `insertAtHead()`, `insertAtEnd()`, `deleteValue()`, `display()`
- ✅ Stacks: Array-based and linked list-based with O(1) operations
- ✅ Queues: Circular array and linked list implementations
- ✅ Compiles with: `g++ main.cpp LinkedList.cpp Stack.cpp Queue.cpp -o dsa_test`
- ✅ Proper memory management and destructors
- ✅ Private data members with public methods
- ✅ Comments explaining logic (especially circular array wrapping)

## Testing

Run `./dsa_test.exe` to execute comprehensive tests:
- LinkedList insertion, deletion, display
- StackArray push/pop with overflow
- StackLinkedList push/pop
- QueueArray enqueue/dequeue with circular wrapping
- QueueLinkedList enqueue/dequeue

All operations display results for verification.

## Notes

This implementation emphasizes:
1. **Understanding**: Clear code that teaches how each structure works
2. **Practice**: Hands-on memory management with pointers
3. **Professionalism**: Industry-standard code organization
4. **Efficiency**: Optimal time complexity for all operations


## Contributors

<div align="center">

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/fady-nasser">
        <img src="https://avatars.githubusercontent.com/u/183446123?v=4" width="90px;" style="border-radius:50%"/><br/>
        <sub><b>Fady Nasser</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/Seif-ElDin10">
        <img src="https://avatars.githubusercontent.com/u/180775212?v=4" width="90px;" style="border-radius:50%"/><br/>
        <sub><b>Seif ElDin</b></sub>
      </a>
     <!-- 
    </td>
    <td align="center">
      <a href="https://github.com/..">
        <img src="https://avatars.githubusercontent.com/u/143766084?v=4" width="90px;" style="border-radius:50%"/><br/>
        <sub><b>Hassan Badawy</b></sub>
      </a>
      -->
    </td>
    <td align="center">
      <a href="https://github.com/YomnaSabry172">
        <img src="https://avatars.githubusercontent.com/u/80396445?v=4" width="90px;" style="border-radius:50%"/><br/>
        <sub><b>Youmna Sabry</b></sub>
      </a>
    </td>
  </tr>
</table>

</div>


