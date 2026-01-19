# CPP Module 05 - Complete Guide

## Overview
This module focuses on **exceptions**, **inheritance**, **abstract classes**, and **polymorphism** in C++98. You'll learn how to handle errors properly using exceptions instead of return values.

---

## Table of Contents
1. [Ex00: Bureaucrat](#ex00-bureaucrat)
2. [Ex01: Form](#ex01-form)
3. [Ex02: Concrete Forms](#ex02-concrete-forms)
4. [Ex03: Intern](#ex03-intern)
5. [Key Concepts](#key-concepts)
6. [Common Mistakes](#common-mistakes)

---

## Ex00: Bureaucrat

### What You Need to Know
- **Exceptions**: How to throw and catch exceptions
- **Exception Classes**: Creating custom exception classes that inherit from `std::exception`
- **Const Correctness**: Understanding when to use const
- **Grade System**: Lower number = higher grade (1 is highest, 150 is lowest)

### What Ex00 Does
Creates a `Bureaucrat` class with:
- A **constant name** (can't be changed after creation)
- A **grade** (1-150, where 1 is highest)
- Methods to **increment/decrement** grade
- **Exception handling** for invalid grades

### Implementation Steps

1. **Create Bureaucrat.hpp**:
   ```cpp
   class Bureaucrat {
   private:
       const std::string name;  // MUST be const
       int grade;               // 1 (highest) to 150 (lowest)
   
   public:
       // Orthodox Canonical Form (4 methods required)
       Bureaucrat();
       Bureaucrat(const std::string& name, int grade);
       Bureaucrat(const Bureaucrat &other);
       Bureaucrat& operator=(const Bureaucrat &other);
       ~Bureaucrat();
       
       // Getters
       std::string getName() const;
       int getGrade() const;
       
       // Grade modification
       void incrementGrade();  // Decreases grade number (1 is best)
       void decrementGrade();  // Increases grade number (150 is worst)
       
       // Nested exception classes
       class GradeTooHighException : public std::exception {
           virtual const char* what() const throw();
       };
       class GradeTooLowException : public std::exception {
           virtual const char* what() const throw();
       };
   };
   
   std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
   ```

2. **Grade Validation**:
   - In constructor: Check if grade < 1 → throw `GradeTooHighException`
   - In constructor: Check if grade > 150 → throw `GradeTooLowException`
   - In increment: Check if grade - 1 < 1 → throw exception
   - In decrement: Check if grade + 1 > 150 → throw exception

3. **Exception Implementation**:
   ```cpp
   const char* Bureaucrat::GradeTooHighException::what() const throw() {
       return "Grade is too high!";
   }
   ```

### Key Points
- **Grade logic is backwards**: increment() makes grade better (smaller number)
- **Const members**: Can only be initialized in initialization list
- **Copy constructor**: Can't copy `name` (it's const), must initialize it

### Hardest Parts
1. Understanding that **lower number = higher grade**
2. Nested exception classes syntax
3. `throw()` specification in C++98 (deprecated in C++11+)

---

## Ex01: Form

### What You Need to Know
- Everything from Ex00
- **Forward declarations**: Declaring a class before defining it
- **Circular dependencies**: When two classes need to know about each other
- **Const attributes**: Multiple const members in a class

### What Ex01 Does
Creates a `Form` class that:
- Has a **name** (const)
- Has a **signed status** (bool, starts false)
- Has **two grades**: one to sign, one to execute (both const)
- Can be **signed by a Bureaucrat**
- Validates grades in constructor

### Implementation Steps

1. **Handle Circular Dependency**:
   - `Bureaucrat` needs to know about `Form` (to sign it)
   - `Form` needs to know about `Bureaucrat` (to check grade)
   
   **Solution**:
   ```cpp
   // In Bureaucrat.hpp
   class Form;  // Forward declaration
   
   class Bureaucrat {
       void signForm(Form& form);  // Only declaration, not full definition
   };
   
   // In Form.hpp
   #include "Bureaucrat.hpp"  // Full include needed
   
   class Form {
       void beSigned(const Bureaucrat& bureaucrat);
   };
   ```

2. **Form Class Structure**:
   ```cpp
   class Form {
   private:
       const std::string name;
       bool isSigned;
       const int signGrade;
       const int executeGrade;
   
   public:
       Form(const std::string& name, int signGrade, int executeGrade);
       // ... other canonical form methods
       
       void beSigned(const Bureaucrat& bureaucrat);
       
       // Getters
       std::string getName() const;
       bool getIsSigned() const;
       int getSignGrade() const;
       int getExecuteGrade() const;
   };
   ```

3. **Signing Logic**:
   ```cpp
   void Form::beSigned(const Bureaucrat& bureaucrat) {
       if (bureaucrat.getGrade() > signGrade)  // Higher number = lower grade
           throw Form::GradeTooLowException();
       isSigned = true;
   }
   
   void Bureaucrat::signForm(Form& form) {
       try {
           form.beSigned(*this);
           std::cout << name << " signed " << form.getName() << std::endl;
       } catch (std::exception& e) {
           std::cout << name << " couldn't sign " << form.getName() 
                     << " because " << e.what() << std::endl;
       }
   }
   ```

### Key Points
- **Two-way interaction**: Bureaucrat signs Form, Form checks Bureaucrat's grade
- **Multiple const members**: All initialized in initialization list
- **Copy assignment**: Can't reassign const members, only copy `isSigned`

### Hardest Parts
1. **Circular dependency resolution** with forward declarations
2. Understanding why Form can't be fully included in Bureaucrat.hpp
3. Managing multiple const attributes in copy operations

---

## Ex02: Concrete Forms

### What You Need to Know
- Everything from Ex00 and Ex01
- **Abstract classes**: Classes with pure virtual functions
- **Polymorphism**: Using base class pointers for derived classes
- **Virtual functions**: Methods that can be overridden
- **File I/O**: Writing to files in C++98
- **Random numbers**: Using `rand()` and `srand()`

### What Ex02 Does
- Renames `Form` to `AForm` (Abstract Form)
- Makes AForm **abstract** with pure virtual `execute()` method
- Creates **three concrete form classes**:
  - **ShrubberyCreationForm**: Creates a file with ASCII trees
  - **RobotomyRequestForm**: 50% success rate, makes drilling noises
  - **PresidentialPardonForm**: Prints pardon message
- Adds **execution functionality** with grade checking

### The Three Forms (MEMORIZE THESE GRADES!)

| Form | Sign Grade | Execute Grade | Action |
|------|------------|---------------|--------|
| ShrubberyCreationForm | 145 | 137 | Creates `<target>_shrubbery` file with ASCII trees |
| RobotomyRequestForm | 72 | 45 | Drilling noises + 50% robotomy success |
| PresidentialPardonForm | 25 | 5 | `<target> has been pardoned by Zaphod Beeblebrox.` |

### Implementation Steps

1. **Make AForm Abstract**:
   ```cpp
   class AForm {
       // ... existing members
       
       virtual void execute() const = 0;  // Pure virtual - makes class abstract
       void execute(Bureaucrat const & executor);  // Validation method
   };
   ```

2. **Two Execute Methods Pattern**:
   - `execute(Bureaucrat const & executor)`: Does validation (NOT pure virtual)
   - `execute() const`: Pure virtual, implemented by derived classes
   
   **Why?** Validation happens in parent, action happens in child.
   
   ```cpp
   void AForm::execute(Bureaucrat const & executor) {
       if (!isSigned)
           throw FormNotSignedException();
       if (executor.getGrade() > executeGrade)
           throw GradeTooLowException();
       execute();  // Calls pure virtual (polymorphism!)
   }
   ```

3. **Concrete Form Pattern** (same for all three):
   ```cpp
   class PresidentialPardonForm : public AForm {
   private:
       std::string target;  // Where the action is performed
   
   public:
       // Constructor MUST call parent with fixed grades
       PresidentialPardonForm(const std::string& target)
           : AForm("Presidential Pardon", 25, 5), target(target) {}
       
       // Copy constructor MUST call parent copy constructor
       PresidentialPardonForm(const PresidentialPardonForm &other)
           : AForm(other), target(other.target) {}
       
       // Assignment MUST call parent assignment
       PresidentialPardonForm& operator=(const PresidentialPardonForm &other) {
           if (this != &other) {
               AForm::operator=(other);
               target = other.target;
           }
           return *this;
       }
       
       virtual ~PresidentialPardonForm() {}
       
       virtual void execute() const {
           // Only the action - NO grade checking here!
           std::cout << target << " has been pardoned by Zaphod Beeblebrox." 
                     << std::endl;
       }
   };
   ```

4. **ShrubberyCreationForm Specifics**:
   ```cpp
   void ShrubberyCreationForm::execute() const {
       std::string filename = target + "_shrubbery";
       std::ofstream file(filename.c_str());  // C++98 needs .c_str()
       
       if (!file.is_open()) {
           std::cerr << "Error: Could not create file" << std::endl;
           return;
       }
       
       // Write ASCII trees
       file << "    *    " << std::endl;
       file << "   ***   " << std::endl;
       // ... more tree art
       
       file.close();
   }
   ```

5. **RobotomyRequestForm Specifics**:
   ```cpp
   void RobotomyRequestForm::execute() const {
       std::cout << "* DRILLING NOISES *" << std::endl;
       
       // Seed random ONCE using static
       static bool seeded = false;
       if (!seeded) {
           std::srand(std::time(NULL));
           seeded = true;
       }
       
       // 50% chance
       if (std::rand() % 2 == 0)
           std::cout << target << " has been robotomized successfully!" << std::endl;
       else
           std::cout << "Robotomy failed!" << std::endl;
   }
   ```

6. **Add executeForm to Bureaucrat**:
   ```cpp
   void Bureaucrat::executeForm(AForm& form) {
       try {
           form.execute(*this);  // Calls validation method
           std::cout << name << " executed " << form.getName() << std::endl;
       } catch (std::exception& e) {
           std::cout << name << " couldn't execute because " 
                     << e.what() << std::endl;
       }
   }
   ```

### Key Points
- **NO validation in concrete classes**: Parent handles all checking
- **Grades are hardcoded**: Each form type has fixed grades
- **Initialization list order**: Call parent constructor first
- **Pure virtual makes class abstract**: Can't instantiate AForm directly
- **Polymorphism in action**: `execute()` calls correct derived version

### Hardest Parts
1. **Two execute methods concept**: One for validation, one pure virtual for action
2. **Understanding initialization list**: Must call parent constructor
3. **File I/O in C++98**: Needs `.c_str()` for ofstream
4. **Static for seeding**: Ensuring random is seeded only once
5. **Remembering all the specific grades**: 145/137, 72/45, 25/5

### New Things Learned
- **Abstract classes** with pure virtual functions
- **Polymorphism** through virtual methods
- **Inheritance patterns** for constructors
- **File operations** in C++98
- **Random number generation** in C++

---

## Ex03: Intern

### What You Need to Know
- Everything from Ex00, Ex01, Ex02
- **Function pointers**: Pointers to member functions
- **Dynamic allocation**: Using `new` and `delete`
- **Arrays of function pointers**: Advanced function pointer usage

### What Ex03 Does
Creates an `Intern` class that can **create forms dynamically** based on a string name, using **function pointers** instead of if/else chains.

**Why?** In real programs, you want clean, maintainable code. The correction EXPLICITLY says if/else chains are WRONG.

### The Problem We're Solving

**BAD (Will fail correction):**
```cpp
AForm* makeForm(std::string formName, std::string target) {
    if (formName == "shrubbery creation")
        return new ShrubberyCreationForm(target);
    else if (formName == "robotomy request")
        return new RobotomyRequestForm(target);
    else if (formName == "presidential pardon")
        return new PresidentialPardonForm(target);
    else
        return NULL;
}
```

**GOOD (Required by correction):**
Use **array of function pointers** to dispatch creation.

### Implementation Steps

1. **Intern.hpp**:
   ```cpp
   class Intern {
   private:
       // Helper methods that create specific forms
       AForm* createShrubberyCreation(std::string target);
       AForm* createRobotomyRequest(std::string target);
       AForm* createPresidentialPardon(std::string target);
   
   public:
       Intern();
       Intern(const Intern &other);
       Intern& operator=(const Intern &other);
       ~Intern();
       
       AForm* makeForm(std::string formName, std::string target);
   };
   ```

2. **Helper Methods** (simple):
   ```cpp
   AForm* Intern::createShrubberyCreation(std::string target) {
       return new ShrubberyCreationForm(target);
   }
   
   AForm* Intern::createRobotomyRequest(std::string target) {
       return new RobotomyRequestForm(target);
   }
   
   AForm* Intern::createPresidentialPardon(std::string target) {
       return new PresidentialPardonForm(target);
   }
   ```

3. **makeForm with Function Pointers** (THE TRICKY PART):
   ```cpp
   AForm* Intern::makeForm(std::string formName, std::string target) {
       // 1. Array of form names
       std::string formNames[3] = {
           "shrubbery creation",
           "robotomy request",
           "presidential pardon"
       };
       
       // 2. Array of function pointers to member functions
       AForm* (Intern::*formCreators[3])(std::string) = {
           &Intern::createShrubberyCreation,
           &Intern::createRobotomyRequest,
           &Intern::createPresidentialPardon
       };
       
       // 3. Loop to find matching name
       for (int i = 0; i < 3; i++) {
           if (formName == formNames[i]) {
               std::cout << "Intern creates " << formName << std::endl;
               return (this->*formCreators[i])(target);  // Call through pointer
           }
       }
       
       // 4. Not found
       std::cout << "Intern cannot create " << formName << std::endl;
       return NULL;
   }
   ```

4. **Orthodox Canonical Form** (Intern has no attributes):
   ```cpp
   Intern::Intern() {
       std::cout << "Intern constructor called" << std::endl;
   }
   
   Intern::Intern(const Intern &other) {
       (void)other;  // Suppress unused warning
   }
   
   Intern& Intern::operator=(const Intern &other) {
       (void)other;
       return *this;
   }
   
   Intern::~Intern() {
       std::cout << "Intern destructor called" << std::endl;
   }
   ```

### Function Pointer Syntax Breakdown

**Declaration:**
```cpp
AForm* (Intern::*functionPointer)(std::string);
//     └─────┬─────┘
//           └──> Pointer to member function of Intern class
```

**Array of function pointers:**
```cpp
AForm* (Intern::*array[3])(std::string) = { ... };
//                  └┬┘
//                   └──> Array of 3 pointers
```

**Calling through pointer:**
```cpp
(this->*functionPointer)(argument);
//└──┬──┘
//   └──> Dereference and call on this object
```

### Using in main.cpp

```cpp
Intern intern;
AForm* form;

// Create form
form = intern.makeForm("shrubbery creation", "home");

// Use it
if (form) {
    Bureaucrat boss("Boss", 1);
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;  // MUST delete - created with new!
}

// Invalid form
form = intern.makeForm("invalid", "target");  // Returns NULL
if (!form) {
    std::cout << "Form creation failed" << std::endl;
}
```

### Key Points
- **Function pointers avoid if/else**: Required by correction
- **Returns pointer from new**: Caller must delete
- **Returns NULL on failure**: Always check before using
- **No attributes**: Intern doesn't store anything
- **Case sensitive**: "Presidential Pardon" ≠ "presidential pardon"

### Hardest Parts
1. **Function pointer syntax**: Very confusing at first
2. **Member function pointers**: Different from regular function pointers
3. **Calling through pointer**: `(this->*ptr)(arg)` syntax
4. **Memory management**: Remembering to delete returned forms

### New Things Learned
- **Pointers to member functions**: Advanced C++ feature
- **Arrays of function pointers**: Dispatch pattern
- **Factory pattern**: Creating objects based on runtime input
- **Dynamic dispatching**: Choosing function at runtime

---

## Key Concepts

### 1. Exception Handling
```cpp
try {
    // Code that might throw
    bureaucrat.incrementGrade();
} catch (std::exception& e) {
    // Handle error
    std::cout << e.what() << std::endl;
}
```

**Rules:**
- Catch by reference (`std::exception&`)
- Base class exceptions should inherit from `std::exception`
- Use `what()` method to get error message
- `throw()` specification in C++98 (removed in C++11+)

### 2. Abstract Classes
```cpp
class Abstract {
    virtual void pureVirtual() = 0;  // Pure virtual function
};
```

**Rules:**
- Can't instantiate abstract classes
- Derived classes must implement all pure virtual functions
- Used as interfaces or base classes
- Can have concrete methods too

### 3. Polymorphism
```cpp
AForm* form = new PresidentialPardonForm("target");
form->execute();  // Calls PresidentialPardonForm::execute()
delete form;
```

**Rules:**
- Need virtual destructor in base class
- Base class pointer can point to derived object
- Virtual functions allow dynamic binding
- Enables "one interface, multiple implementations"

### 4. Const Correctness
```cpp
const std::string name;           // Can't change after construction
std::string getName() const;      // Method doesn't modify object
void func(const Bureaucrat& b);   // Can't modify passed object
```

**Rules:**
- Const members initialized in initialization list
- Const methods can be called on const objects
- Use const references to avoid copies
- Can't call non-const methods on const objects

### 5. Orthodox Canonical Form (Coplien's Form)
Every class needs these 4 methods:
1. Default constructor
2. Copy constructor
3. Copy assignment operator
4. Destructor

```cpp
class MyClass {
public:
    MyClass();                              // Default constructor
    MyClass(const MyClass& other);          // Copy constructor
    MyClass& operator=(const MyClass& other); // Assignment operator
    ~MyClass();                             // Destructor
};
```

---

## Common Mistakes

### 1. Grade Logic Backwards
❌ **WRONG:**
```cpp
void incrementGrade() { grade++; }  // Makes grade WORSE!
```
✅ **CORRECT:**
```cpp
void incrementGrade() { grade--; }  // Makes grade BETTER!
```

### 2. Not Calling Parent Constructor
❌ **WRONG:**
```cpp
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : target(target) {}  // Parent not initialized!
```
✅ **CORRECT:**
```cpp
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon", 25, 5), target(target) {}
```

### 3. Using if/else in Intern (ex03)
❌ **WRONG (Will fail correction):**
```cpp
if (name == "form1") return new Form1();
else if (name == "form2") return new Form2();
```
✅ **CORRECT:**
```cpp
// Use array of function pointers (see ex03 section)
```

### 4. Forgetting to Delete Forms
❌ **WRONG:**
```cpp
AForm* form = intern.makeForm("name", "target");
// ... use form ...
// Memory leak! Didn't delete
```
✅ **CORRECT:**
```cpp
AForm* form = intern.makeForm("name", "target");
if (form) {
    // ... use form ...
    delete form;
}
```

### 5. Const Members in Copy Assignment
❌ **WRONG:**
```cpp
Form& operator=(const Form& other) {
    name = other.name;  // Error! name is const
    return *this;
}
```
✅ **CORRECT:**
```cpp
Form& operator=(const Form& other) {
    // Can only copy non-const members
    isSigned = other.isSigned;
    return *this;
}
```

### 6. Execute Validation in Wrong Place
❌ **WRONG:**
```cpp
class PresidentialPardonForm {
    void execute() const {
        if (!isSigned) throw ...;  // Don't validate in derived class!
        // do action
    }
};
```
✅ **CORRECT:**
```cpp
// Validation in parent execute(Bureaucrat const & executor)
// Action only in derived execute()
```

### 7. File I/O Without .c_str()
❌ **WRONG (C++98):**
```cpp
std::ofstream file(filename);  // Won't compile in C++98
```
✅ **CORRECT:**
```cpp
std::ofstream file(filename.c_str());  // C++98 compliant
```

---

## Compilation & Testing

### Compile All Exercises
```bash
cd ex00 && make && ./Bureaucrat
cd ../ex01 && make && ./Bureaucrat
cd ../ex02 && make && ./Tree
cd ../ex03 && make && ./Tree
```

### What to Test

**Ex00:**
- Valid grades (1, 150, 75)
- Invalid grades (0, 151, -5)
- Increment/decrement at boundaries
- Exception catching

**Ex01:**
- Creating forms with valid/invalid grades
- Signing with sufficient grade
- Signing with insufficient grade
- Multiple bureaucrats, multiple forms

**Ex02:**
- Creating each concrete form type
- Signing and executing each form
- Executing unsigned form (should fail)
- Executing with insufficient grade (should fail)
- Check ShrubberyCreationForm creates file
- Check RobotomyRequestForm randomness

**Ex03:**
- Create forms via Intern with all three names
- Test invalid form names
- Test that created forms work correctly
- Test memory management (no leaks)

### Memory Leak Check
```bash
valgrind ./programName
```

---

## Summary

**Ex00:** Basics - exceptions, grade validation  
**Ex01:** Forms - signing, circular dependencies  
**Ex02:** Inheritance - abstract classes, polymorphism, concrete implementations  
**Ex03:** Advanced - function pointers, factory pattern  

**Progression:**
1. Learn exceptions
2. Learn form-bureaucrat interaction
3. Learn abstract classes and inheritance
4. Learn advanced dispatching with function pointers

**Key Takeaway:** Each exercise builds on the previous. Master the basics before moving forward.
