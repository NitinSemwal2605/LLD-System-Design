# Low-Level Design (LLD) & Object-Oriented Programming in C++

A comprehensive repository for mastering **Object-Oriented Programming (OOP)**, **SOLID Principles**, and **Low-Level System Design (LLD)** using modern C++.

---

## 📂 Repository Structure

```plaintext
LLD/
├── 1_OOPS/                  # OOP Fundamentals in C++
├── 2_SOLID/                 # SOLID Principles
│   ├── SRP/                 # Single Responsibility Principle
│   ├── OCP/                 # Open/Closed Principle
│   ├── LSP/                 # Liskov Substitution Principle
│   └── Solid.md             # Comprehensive SOLID Revision Guide
├── .gitignore
└── README.md
```

---

## 1. Object-Oriented Programming (OOP) Foundations (`1_OOPS`)

Hands-on C++ implementations demonstrating foundational and intermediate OOP concepts:

| # | Topic / Concept | File | Description |
|---|---|---|---|
| 01 | **Structure** | [`01_Structure.cpp`](1_OOPS/01_Structure.cpp) | User-defined data types combining heterogeneous types into a single unit. |
| 02 | **Union** | [`02_Union.cpp`](1_OOPS/02_Union.cpp) | Shared memory allocation for multiple members. |
| 03 | **Classes & Objects** | [`03_Classes.cpp`](1_OOPS/03_Classes.cpp) | Encapsulation of data members and member functions. |
| 04 | **Virtual Functions** | [`04_VirtualFunction.cpp`](1_OOPS/04_VirtualFunction.cpp) | Runtime polymorphism and dynamic dispatch via `virtual` / `override`. |
| 05 | **Function Overloading** | [`05_FunctionOverloading.cpp`](1_OOPS/05_FunctionOverloading.cpp) | Compile-time polymorphism with different parameter lists. |
| 06 | **Friend Functions** | [`06_FriendFunctions.cpp`](1_OOPS/06_FriendFunctions.cpp) | Granting non-member functions access to `private` & `protected` members. |
| 07 | **Call by Value vs Reference** | [`07_CallByVal_Ref.cpp`](1_OOPS/07_CallByVal_Ref.cpp) | Memory semantics, passing parameters by value vs pointer/reference. |
| 08 | **Operator Overloading** | [`08_OperatorOverloading.cpp`](1_OOPS/08_OperatorOverloading.cpp) | Extending standard C++ operators (`+`, `-`, etc.) for custom classes. |
| 09 | **Class Design & Getters/Setters** | [`09_Classes.cpp`](1_OOPS/09_Classes.cpp) | Access specifiers (`public`, `private`) and encapsulation. |
| 10 | **Static Keyword** | [`10_StaticKeyword.cpp`](1_OOPS/10_StaticKeyword.cpp) | Class-level static data members and static member functions. |
| 11 | **Constructor & Destructor** | [`11_ConstructorDestructor.cpp`](1_OOPS/11_ConstructorDestructor.cpp) | Object lifecycle, initialization, and cleanup (RAII). |
| 12 | **Default Constructor** | [`12_DefaultConstructor.cpp`](1_OOPS/12_DefaultConstructor.cpp) | Zero-argument object initialization. |
| 13 | **Parameterized Constructor** | [`13_ParameterizedConstructor.cpp`](1_OOPS/13_ParameterizedConstructor.cpp) | Initializing member variables at instantiation time. |
| 14 | **Copy Constructor** | [`14_CopyConstructor.cpp`](1_OOPS/14_CopyConstructor.cpp) | Deep vs shallow copying and object cloning. |

---

## 2. SOLID Design Principles (`2_SOLID`)

Detailed before-and-after implementations for each principle, accompanied by the in-depth revision guide in [`Solid.md`](2_SOLID/Solid.md):

| Principle | Concept | Code Examples | Description |
|---|---|---|---|
| **S** | **Single Responsibility Principle** | [Violated](2_SOLID/SRP/SRP_violated.cpp) \| [Followed](2_SOLID/SRP/SRP_followed.cpp) | Decomposing a God-class (`ShoppingCart`) into separate domain, printing, and storage classes. |
| **O** | **Open/Closed Principle** | [Violated](2_SOLID/OCP/OCP_violated.cpp) \| [Followed](2_SOLID/OCP/OCP_followed.cpp) | Using a polymorphic `Persistence` interface to add database strategies without modifying existing code. |
| **L** | **Liskov Substitution Principle** | [Violated](2_SOLID/LSP/LSP_violated.cpp) \| [Followed](2_SOLID/LSP/LSP_followed.cpp) | Segregating `DepositOnlyAccount` from `WithdrawableAccount` so child types don't throw unexpected runtime exceptions. |

📖 **For full revision notes, architecture diagrams, and interview prep:** See [`2_SOLID/Solid.md`](2_SOLID/Solid.md).

---

## 🛠️ How to Compile and Run

You can compile and run any individual file using `g++`:

```bash
# Example: Compile and run Operator Overloading
g++ -std=c++17 1_OOPS/08_OperatorOverloading.cpp -o output
./output
```

Or run via **VS Code / Antigravity IDE** using the default build task (`Ctrl` + `Shift` + `B`).

---

## 🚀 Roadmap

- [x] **1. OOP Fundamentals**
- [x] **2. SOLID Principles** (SRP, OCP, LSP covered with Before & After examples)
- [ ] **3. Creational Design Patterns** (Factory, Abstract Factory, Singleton, Builder, Prototype)
- [ ] **4. Structural Design Patterns** (Adapter, Decorator, Facade, Composite, Proxy)
- [ ] **5. Behavioral Design Patterns** (Strategy, Observer, Command, State, Chain of Responsibility)
- [ ] **6. Real-World LLD Case Studies** (Parking Lot, Tic-Tac-Toe, Elevator System, Rate Limiter)

