# grasshopper-parser
C++ implementation of a tokenizer and parser for the Grasshopper language.  This project demonstrates linked list data structures, token parsing, and  object-oriented design principles in C++.
---

## Features

- Tokenization of source code input
- Linked list data structure for token management
- Object-oriented design using C++ classes
- Separation of header and implementation files
- Modular parsing architecture

---

## Technologies Used

- C++
- Object-Oriented Programming
- Linked Lists
- Tokenization / Parsing
- Data Structures

---

## Project Structure
grasshopper-parser
│
├── main.cpp # Program entry point
├── LinkedList.cpp # Linked list implementation
├── LinkedList.h # Linked list class definitions
├── node.cpp # Node implementation
├── node.h # Node class definition
├── Tokenizer.cpp # Tokenization logic
├── Tokenizer.h # Tokenizer interface
└── README.md # Project documentation
---

## How to Build and Run

### Compile the project

Using g++:


g++ main.cpp LinkedList.cpp node.cpp Tokenizer.cpp -o grasshopper_parser
### Run the program


./grasshopper_parser


---

## Key Concepts Demonstrated

This project highlights several core computer science principles:

- **Lexical Analysis**  
  Breaking source code into tokens for further processing.

- **Data Structure Design**  
  Implementing linked lists for efficient token storage.

- **Modular Software Design**  
  Separating interface (`.h`) and implementation (`.cpp`) files.

- **Object-Oriented Programming**  
  Using classes to encapsulate tokenization and list behavior.

---
