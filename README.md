
---

# 📂 C++ Module 05 – Repetition and Exceptions

This project is part of the **42 C++ Modules** series, focusing on **exceptions, inheritance, and object-oriented design patterns** in C++.

You will build a small **bureaucratic system** with multiple classes, handling grade-based permissions, exception handling, and dynamic form creation.

---

## 📌 Table of Contents

* [Introduction](#-introduction)
* [General Rules](#-general-rules)
* [Project Structure](#-project-structure)
* [Exercises Overview](#-exercises-overview)

  * [ex00 – Bureaucrat](#ex00--bureaucrat)
  * [ex01 – Form](#ex01--form)
  * [ex02 – Specialized Forms](#ex02--specialized-forms)
  * [ex03 – Intern](#ex03--intern)
* [Build & Run](#-build--run)
* [Key Concepts Learned](#-key-concepts-learned)

---

## 📖 Introduction

C++ Module 05 introduces **repetition and exceptions** in an OOP context.

You’ll implement a **bureaucratic nightmare simulator** with:
✅ Multiple interacting classes
✅ Proper exception handling (`try/catch`)
✅ Grade-based validation for actions
✅ Abstract base classes and inheritance
✅ Dynamic form creation via the `Intern` class

This module follows **C++17 standard** and **Orthodox Canonical Form**.

---

## ⚙️ General Rules

* Compile with:

  ```bash
  c++ -Wall -Wextra -Werror -std=c++98
  ```

* **Forbidden:**

  * `printf`, `malloc`, `free`, `C++11`, `Boost`, STL containers/algorithms (until Module 08)
  * `using namespace <ns>` and `friend`

* **Allowed:**

  * Most of the standard C++17 library (`<iostream>`, `<string>`, `<fstream>`, `<exception>`, etc.)

* **Memory management**: Avoid leaks when using `new`.

* **Class design**: Orthodox Canonical Form required (constructor, copy constructor, destructor, operator=).

---

## 📂 Project Structure

```
📦 cpp_module_05/
 ├── ex00/
 │   ├── Bureaucrat.hpp
 │   ├── Bureaucrat.cpp
 │   ├── main.cpp
 │   └── Makefile
 ├── ex01/
 │   ├── Form.hpp / Form.cpp
 │   ├── Bureaucrat.[hpp/cpp]
 │   ├── main.cpp
 │   └── Makefile
 ├── ex02/
 │   ├── AForm.hpp / AForm.cpp
 │   ├── ShrubberyCreationForm.hpp / .cpp
 │   ├── RobotomyRequestForm.hpp / .cpp
 │   ├── PresidentialPardonForm.hpp / .cpp
 │   ├── Bureaucrat.[hpp/cpp]
 │   ├── main.cpp
 │   └── Makefile
 ├── ex03/
 │   ├── Intern.hpp / Intern.cpp
 │   ├── all previous forms
 │   ├── Bureaucrat.[hpp/cpp]
 │   ├── main.cpp
 │   └── Makefile
 └── README.md
```

---

## 📝 Exercises Overview

### **ex00 – Bureaucrat**

* Implements a `Bureaucrat` class with:

  * `name` (constant)
  * `grade` (1 = highest, 150 = lowest)
* Supports:

  * `incrementGrade()` / `decrementGrade()`
  * Throws `GradeTooHighException` or `GradeTooLowException`
  * `operator<<` overload for printing

---

### **ex01 – Form**

* Adds a `Form` class:

  * `name` (constant)
  * `isSigned` (boolean)
  * `gradeToSign` & `gradeToExecute`
* `Form::beSigned(Bureaucrat)` allows signing if grade is high enough.
* `Bureaucrat::signForm()` tries to sign and prints success/failure.

---

### **ex02 – Specialized Forms**

* `AForm` becomes an **abstract class**.
* Adds **3 concrete forms**:

  * **ShrubberyCreationForm** → creates a file with ASCII trees 🌳
  * **RobotomyRequestForm** → 50% chance of success 🤖
  * **PresidentialPardonForm** → pardons a target 🏛️
* `execute()` checks if form is signed & grade is sufficient.
* `Bureaucrat::executeForm()` runs the form action.

---

### **ex03 – Intern**

* Adds an `Intern` class with:

  * `makeForm(formName, target)` → dynamically creates correct form type.
  * Prints `"Intern creates <form>"` or an error if unknown.

Example:

```cpp
Intern someRandomIntern;
AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
```

---

## 🚀 Build & Run

### Build

Inside any exercise folder:

```bash
make
```

### Run

```bash
./bureaucrat
```

---

## 🧠 Key Concepts Learned

* ✅ **Exception handling** (`try/catch`, custom exceptions)
* ✅ **Abstract classes & inheritance**
* ✅ **Polymorphism & virtual functions**
* ✅ **Canonical Form in class design**
* ✅ **Dynamic memory & avoiding leaks**
* ✅ **Operator overloading**

---
