# C++ Modules (CPP00-CPP05) - Learning Journey
![miniRT](https://img.shields.io/badge/42-CPP-blue)
![C++](https://img.shields.io/badge/Language-C++-brightgreen)

This repository contains a comprehensive C++ learning curriculum covering fundamental to advanced object-oriented programming concepts. Each module builds upon the previous one, introducing new concepts and reinforcing programming principles.

## Table of Contents
- [CPP Module 00: Namespaces, Classes, Member Functions, IO Streams](#cpp-module-00)
- [CPP Module 01: Memory Allocation, Pointers, References, Switch Statement](#cpp-module-01)
- [CPP Module 02: Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Class Form](#cpp-module-02)
- [CPP Module 03: Inheritance](#cpp-module-03)
- [CPP Module 04: Subtype Polymorphism, Abstract Classes, Interfaces](#cpp-module-04)
- [CPP Module 05: Repetition and Exceptions](#cpp-module-05)

---

## CPP Module 00: Namespaces, Classes, Member Functions, IO Streams

**Learning Objectives:**
- Introduction to C++ syntax and basic concepts
- Understanding classes and objects
- Working with member functions and access specifiers
- Input/Output streams in C++
- Namespaces and scope

### Exercises:

#### Exercise 00: Megaphone

Creates a program that converts command-line arguments to uppercase, mimicking a megaphone.

#### Exercise 01: My Awesome PhoneBook

Implements a phonebook application that can store contacts and search through them.

#### Exercise 02: The Job Of Your Dreams

Implements a bank account class with deposit/withdrawal functionality and logging.

---

## CPP Module 01: Memory Allocation, Pointers, References, Switch Statement

**Learning Objectives:**
- Dynamic memory allocation (`new`/`delete`)
- Understanding pointers vs references
- Memory management best practices
- Switch statements and control flow
- String manipulation and file I/O

### Exercises:

#### Exercise 00: BraiiiiiiinnnzzzZ

Creates zombie objects both on stack and heap, demonstrating memory management.

#### Exercise 01: Moar brainz!

Creates an array of zombie objects dynamically.

#### Exercise 02: HI THIS IS BRAIN

Demonstrates the differences between pointers and references.

#### Exercise 03: Unnecessary violence

Implements weapon system where humans can have weapons by reference or pointer.

#### Exercise 04: Sed is for losers

Creates a file processor that replaces strings in text files.

#### Exercise 05: Harl 2.0

Implements a logging system with different log levels.

#### Exercise 06: Harl filter

Extends Harl with filtering capabilities using switch statements.

---

## CPP Module 02: Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Class Form

**Learning Objectives:**
- Operator overloading
- Copy constructors and assignment operators
- Orthodox Canonical Class Form (Rule of Three)
- Fixed-point arithmetic
- Const-correctness

### Exercises:

#### Exercise 00: My First Class in Orthodox Canonical Form

Implements a basic fixed-point number class following Orthodox Canonical Form.

#### Exercise 01: Towards a more useful fixed-point number class

Extends the Fixed class with conversion capabilities and output formatting.

#### Exercise 02: Now we're talking

Implements a full-featured fixed-point arithmetic class.

#### Exercise 03: BSP

Determines if a point is inside a triangle using fixed-point arithmetic.

---

## CPP Module 03: Inheritance

**Learning Objectives:**
- Class inheritance
- Protected access specifier
- Virtual functions
- Method overriding
- Diamond problem and virtual inheritance
- Constructor/destructor chaining

### Exercises:

#### Exercise 00: Aaaaand... OPEN!

Implements a ClapTrap robot with attack, repair, and take damage functionality.

#### Exercise 01: Serena, my love!

Creates ScavTrap inheriting from ClapTrap with additional guard gate functionality.

#### Exercise 02: Repetitive work

Adds FragTrap class with high five functionality, alongside ScavTrap.

#### Exercise 03: Now it's weird!

Implements DiamondTrap inheriting from both ScavTrap and FragTrap, solving the diamond problem.

---

## CPP Module 04: Subtype Polymorphism, Abstract Classes, Interfaces

**Learning Objectives:**
- Virtual functions and polymorphism
- Abstract classes
- Pure virtual functions
- Interfaces
- Runtime polymorphism
- Virtual destructors
- Deep vs shallow copying

### Exercises:

#### Exercise 00: Polymorphism

Demonstrates polymorphism with Animal hierarchy and shows wrong implementation.

#### Exercise 01: I don't want to set the world on fire

Adds Brain class to animals, requiring proper deep copying.

#### Exercise 02: Abstract class

Makes Animal abstract by adding pure virtual functions.

#### Exercise 03: Interface & recap

Implements a complex materia system with interfaces for characters and materia sources.

---

## CPP Module 05: Repetition and Exceptions

**Learning Objectives:**
- Exception handling in C++
- Try-catch-throw mechanism
- Custom exception classes
- Exception safety and RAII
- Nested exception handling
- Exception specifications (C++98)

### Exercises:

#### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

Implements a `Bureaucrat` class with:
- Name (constant) and grade (1-150, where 1 is highest)
- Grade increment/decrement with exception handling
- Custom exceptions: `GradeTooHighException` and `GradeTooLowException`
- Proper exception messages and handling

#### Exercise 01: Form up, maggots!

Extends the bureaucrat system with a `Form` class:
- Form with name, sign grade requirement, and execute grade requirement
- Boolean signed status
- `beSigned()` method that checks bureaucrat's grade
- `signForm()` method in Bureaucrat class with error handling
- Demonstrates form signing workflow and permission validation

#### Exercise 02: No, you need form 28B, not 28C...

Creates an abstract `AForm` base class and concrete implementations:
- **ShrubberyCreationForm**: Creates ASCII art trees in files (sign: 145, exec: 137)
- **RobotomyRequestForm**: Performs robotomy with 50% success rate (sign: 72, exec: 45)
- **PresidentialPardonForm**: Grants presidential pardons (sign: 25, exec: 5)
- Abstract `execute()` method with grade and signature validation
- File I/O operations and random number generation

#### Exercise 03: At least this beats coffee-making

Implements an `Intern` class:
- Factory pattern for creating forms by name
- `makeForm()` method that creates forms from string identifiers
- Error handling for unknown form types
- Demonstrates dynamic form creation and polymorphism

---

## Key Programming Concepts Covered

### Memory Management
- Stack vs Heap allocation
- RAII (Resource Acquisition Is Initialization)
- Smart pointer concepts (manual implementation)
- Memory leak prevention
- Deep vs shallow copying

### Object-Oriented Programming
- Encapsulation
- Inheritance
- Polymorphism
- Abstraction
- Composition vs Inheritance

### C++ Specific Features
- Operator overloading
- Function overloading
- Constructor/destructor chaining
- Virtual functions and virtual destructors
- Static members
- Const-correctness
- References vs pointers

### Design Patterns
- Orthodox Canonical Class Form
- Factory pattern basics
- Interface segregation
- Composition patterns

### Best Practices
- SOLID principles introduction
- Rule of Three/Five
- Const-correctness
- Proper error handling
- Code organization and modularity

---

## Compilation and Testing

Each exercise includes a Makefile with:
- Proper compilation flags (`-Wall -Wextra -Werror -std=c++98`)
- Dependency management
- Clean build process

To build any exercise:
```bash
cd CPP0X/exXX
make
```

To test:
```bash
./program_name
```

To clean:
```bash
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild everything
```

---
