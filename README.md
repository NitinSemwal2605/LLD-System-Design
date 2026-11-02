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
│   ├── ISP/                 # Interface Segregation Principle
│   ├── DIP/                 # Dependency Inversion Principle
│   ├── LSP-Rules/           # Deep-dive into LSP rules
│   │   ├── SingatureRules/  # Return type, argument, exception rules
│   │   ├── MethodRules/     # Precondition & postcondition rules
│   │   └── PropertiesRules/ # Class invariants & history constraint
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
| **I** | **Interface Segregation Principle** | [Violated](2_SOLID/ISP/ISP_violated.cpp) \| [Followed](2_SOLID/ISP/ISP_followed.cpp) | Splitting a fat `Shape` interface into `TwoDimensionalShape` and `ThreeDimensionalShape` so 2D shapes aren't forced to implement `volume()`. |
| **D** | **Dependency Inversion Principle** | [Violated](2_SOLID/DIP/DIP_violated.cpp) \| [Followed](2_SOLID/DIP/DIP_followed.cpp) | Introducing an abstract `Database` interface so `UserService` depends on abstractions, not concrete MySQL/MongoDB classes. |

#### LSP Rules — Deep Dive

| Category | Rule | File | Summary |
|---|---|---|---|
| Signature | Return Type Covariance | [ReturnTypeRule.cpp](2_SOLID/LSP-Rules/SingatureRules/ReturnTypeRule.cpp) | Overridden methods must return the same or a narrower type. |
| Signature | Method Argument Rule | [MethodArgumentRule.cpp](2_SOLID/LSP-Rules/SingatureRules/MethodArgumentRule.cpp) | Overridden methods must accept the same or wider argument types. |
| Signature | Exception Rule | [ExceptionRule.cpp](2_SOLID/LSP-Rules/SingatureRules/ExceptionRule.cpp) | Subclass should throw fewer or narrower exceptions. |
| Method | Precondition Weakening | [PreConditions.cpp](2_SOLID/LSP-Rules/MethodRules/PreConditions.cpp) | Subclass may relax but never strengthen preconditions. |
| Method | Postcondition Strengthening | [PostConditions.cpp](2_SOLID/LSP-Rules/MethodRules/PostConditions.cpp) | Subclass may strengthen but never weaken postconditions. |
| Properties | Class Invariant | [ClassInvariants.cpp](2_SOLID/LSP-Rules/PropertiesRules/ClassInvariants.cpp) | Subclass must maintain the parent's invariants. |
| Properties | History Constraint | [HistoryConstraint.cpp](2_SOLID/LSP-Rules/PropertiesRules/HistoryConstraint.cpp) | Subclass must not disallow state transitions the parent allowed. |

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
- [x] **2. SOLID Principles** (SRP, OCP, LSP, ISP, DIP — all covered with Before & After examples + LSP Rules deep-dive)
- [ ] **3. Creational Design Patterns** (Factory, Abstract Factory, Singleton, Builder, Prototype)
- [ ] **4. Structural Design Patterns** (Adapter, Decorator, Facade, Composite, Proxy)
- [ ] **5. Behavioral Design Patterns** (Strategy, Observer, Command, State, Chain of Responsibility)
- [ ] **6. Real-World LLD Case Studies** (Parking Lot, Tic-Tac-Toe, Elevator System, Rate Limiter)

