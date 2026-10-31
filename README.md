# Low-Level Design (LLD) & Object-Oriented Programming in C++

A comprehensive repository for mastering **Object-Oriented Programming (OOP)**, **SOLID Principles**, and **Low-Level System Design (LLD)** using modern C++.

---

## 📂 Repository Structure

```plaintext
LLD/
├── 1_OOPS/                  # OOP Fundamentals in C++
└── README.md
```

---

## 1. Object-Oriented Programming (OOP) Foundations (`1_OOPS`)

Hands-on C++ implementations demonstrating foundational and intermediate OOP concepts:

| # | Topic / Concept | File | Description |
|---|---|---|---|
| 01 | **Structure** | [`1_Structure.cpp`](1_OOPS/1_Structure.cpp) | User-defined data types combining heterogeneous types into a single unit. |
| 02 | **Union** | [`2_Union.cpp`](1_OOPS/2_Union.cpp) | Shared memory allocation for multiple members. |
| 03 | **Classes & Objects** | [`3_Classes.cpp`](1_OOPS/3_Classes.cpp) | Encapsulation of data members and member functions. |
| 04 | **Virtual Functions** | [`4_VirtualFunction.cpp`](1_OOPS/4_VirtualFunction.cpp) | Runtime polymorphism and dynamic dispatch via `virtual` / `override`. |
| 05 | **Function Overloading** | [`5_FunctionOverloading.cpp`](1_OOPS/5_FunctionOverloading.cpp) | Compile-time polymorphism with different parameter lists. |
| 06 | **Friend Functions** | [`6_FriendFunctions.cpp`](1_OOPS/6_FriendFunctions.cpp) | Granting non-member functions access to `private` & `protected` members. |
| 07 | **Call by Value vs Reference** | [`7_CallByVal_Ref.cpp`](1_OOPS/7_CallByVal_Ref.cpp) | Memory semantics, passing parameters by value vs pointer/reference. |
| 08 | **Operator Overloading** | [`8_OperatorOverloading.cpp`](1_OOPS/8_OperatorOverloading.cpp) | Extending standard C++ operators (`+`, `-`, etc.) for custom classes. |
| 09 | **Class Design & Getters/Setters** | [`9_Classes.cpp`](1_OOPS/9_Classes.cpp) | Access specifiers (`public`, `private`) and encapsulation. |
| 10 | **Static Keyword** | [`10_StaticKeyword.cpp`](1_OOPS/10_StaticKeyword.cpp) | Class-level static data members and static member functions. |
| 11 | **Constructor & Destructor** | [`11_ConstructorDestructor.cpp`](1_OOPS/11_ConstructorDestructor.cpp) | Object lifecycle, initialization, and cleanup (RAII). |
| 12 | **Default Constructor** | [`12_DefaultConstructor.cpp`](1_OOPS/12_DefaultConstructor.cpp) | Zero-argument object initialization. |
| 13 | **Parameterized Constructor** | [`13_ParameterizedConstructor.cpp`](1_OOPS/13_ParameterizedConstructor.cpp) | Initializing member variables at instantiation time. |
| 14 | **Copy Constructor** | [`14_CopyConstructor.cpp`](1_OOPS/14_CopyConstructor.cpp) | Deep vs shallow copying and object cloning. |

---

## 🛠️ How to Compile and Run

You can compile and run any individual file using `g++`:

```bash
# Example: Compile and run Operator Overloading
g++ -std=c++17 1_OOPS/8_OperatorOverloading.cpp -o output
./output
```

Or run via **VS Code / Antigravity IDE** using the default build task (`Ctrl` + `Shift` + `B`).

---

## 🚀 Roadmap

- [x] **1. OOP Fundamentals**
- [ ] **2. SOLID Principles** (SRP, OCP, LSP, ISP, DIP with Before & After examples)
- [ ] **3. Creational Design Patterns** (Factory, Abstract Factory, Singleton, Builder, Prototype)
- [ ] **4. Structural Design Patterns** (Adapter, Decorator, Facade, Composite, Proxy)
- [ ] **5. Behavioral Design Patterns** (Strategy, Observer, Command, State, Chain of Responsibility)
- [ ] **6. Real-World LLD Case Studies** (Parking Lot, Tic-Tac-Toe, Elevator System, Rate Limiter)
