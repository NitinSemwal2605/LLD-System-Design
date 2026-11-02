# Low-Level Design: Document Editor (Google Docs Case Study)

A practical case study demonstrating object-oriented design evolution from a fragile, procedural implementation to a clean, decoupled architecture adhering to SOLID design principles.

---

## 1. Problem Statement

Design a simplified document editor (similar to Google Docs) capable of:
1. Composing documents with heterogeneous elements (plain text, images, line breaks, indentation/tabs).
2. Rendering the full document to an output string.
3. Persisting the rendered content to target storage mechanisms (local filesystem, database, etc.).

---

## 2. Bad Design Analysis (`BadDesign/DocumentEditor.cpp`)

In the initial implementation, a single `DocumentEditor` class handles data storage, type inspection, document formatting, and file persistence.

```cpp
class DocumentEditor {
private:
    vector<string> documentElements;
    string renderedDocument;

public:
    void addText(string text) { documentElements.push_back(text); }
    void addImage(string imagePath) { documentElements.push_back(imagePath); }

    string renderDocument() {
        if(renderedDocument.empty()) {
            string result;
            for (auto element : documentElements) {
                // Fragile type inference using string extension checking
                if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" ||
                    element.substr(element.size() - 4) == ".png")) {
                    result += "[Image: " + element + "]\n";
                } else {
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }

    void saveToFile() {
        ofstream file("document.txt");
        if (file.is_open()) {
            file << renderDocument();
            file.close();
        }
    }
};
```

### Critical Flaws in the Bad Design

1. **Violation of Single Responsibility Principle (SRP)**:
   - `DocumentEditor` maintains the element collection, handles layout rendering, and performs direct disk I/O.
   - Any change to persistence (e.g., adding database support) or rendering rules forces modifications to `DocumentEditor`.

2. **Violation of Open/Closed Principle (OCP)**:
   - Elements are stored uniformly as raw `std::string`.
   - Distinguishing between text and images relies on manual string parsing (`.substr(...)` checking for `.jpg` or `.png`).
   - Introducing new element types (tables, videos, code blocks, formatting markers) requires altering the `renderDocument()` loop with additional branching logic.

3. **Violation of Dependency Inversion Principle (DIP)**:
   - The editor depends directly on concrete file system operations (`std::ofstream`) rather than an abstraction.
   - Testing `DocumentEditor` in isolation without writing to disk is impossible.

---

## 3. Good Design Architecture (`GoodDesign/DocumentEditor.cpp`)

The refactored design decomposes the system into decoupled abstractions and single-purpose components.

### Class Structure

```
+-------------------+
|  DocumentElement  | <--- (Interface)
+-------------------+
| + render(): string|
+-------------------+
          ^
          |-- TextElement
          |-- ImageElement
          |-- NewLineElement
          |-- TabSpaceElement

+--------------------+
|    Persistence     | <--- (Interface)
+--------------------+
| + save(data): void |
+--------------------+
          ^
          |-- FileStorage
          |-- DBStorage

+--------------------+           +---------------------------------+
|   DocumentEditor   | --------> |            Document             |
+--------------------+           +---------------------------------+
| - doc: Document*   |           | - elements: vector<DocElement*> |
| - store: Persist*  |           | + addElement(DocElement*)       |
| + renderDocument() |           | + render(): string              |
| + saveDocument()   |           +---------------------------------+
+--------------------+
```

### Key Components

1. **Element Hierarchy (`DocumentElement`)**:
   - Pure abstract interface declaring `virtual string render() = 0`.
   - Concrete implementations handle their own rendering semantics:
     - `TextElement`: returns raw string content.
     - `ImageElement`: returns formatted image markup (`[Image: <path>]`).
     - `NewLineElement`: returns newline character (`\n`).
     - `TabSpaceElement`: returns tab character (`\t`).

2. **Document Aggregate (`Document`)**:
   - Manages the lifecycle and order of `DocumentElement*` pointers.
   - Delegates rendering uniformly to each element via polymorphic dispatch (`element->render()`), eliminating all runtime type checks and string inspection heuristics.

3. **Persistence Abstraction (`Persistence`)**:
   - Declares `virtual void save(string data) = 0`.
   - Decoupled implementations:
     - `FileStorage`: writes output to local filesystem via file streams.
     - `DBStorage`: placeholder for relational/NoSQL document database storage.

4. **Controller / Façade (`DocumentEditor`)**:
   - Acts as a high-level coordinator mediating client actions.
   - Receives `Document*` and `Persistence*` via constructor injection (Dependency Injection).
   - Exposes convenient editor operations (`addText`, `addImage`, `addNewLine`, `addTabSpace`, `saveDocument`).

---

## 4. SOLID Mapping

| SOLID Principle | Applied in Good Design |
|---|---|
| **Single Responsibility (SRP)** | `Document` manages element storage; individual `DocumentElement` subclasses handle rendering format; `Persistence` handles storage I/O; `DocumentEditor` manages high-level workflow coordination. |
| **Open/Closed (OCP)** | New document elements (e.g., `TableElement`, `CodeSnippetElement`) can be added by implementing `DocumentElement` without altering existing document or editor logic. New storage mediums implement `Persistence` without touching editor code. |
| **Liskov Substitution (LSP)** | All derived elements (`TextElement`, `ImageElement`, etc.) safely substitute `DocumentElement` through the `render()` contract without exceptional behavior or side effects. |
| **Interface Segregation (ISP)** | `DocumentElement` and `Persistence` maintain lean, focused interfaces without extraneous or unrelated methods. |
| **Dependency Inversion (DIP)** | High-level module `DocumentEditor` depends strictly on abstractions (`DocumentElement`, `Persistence`), injected at runtime rather than instantiated concretely. |

---

## 5. Summary of Files

- `BadDesign/DocumentEditor.cpp`: Monolithic implementation demonstrating coupling, string-parsing type checks, and direct disk dependencies.
- `GoodDesign/DocumentEditor.cpp`: Polymorphic, SOLID-compliant implementation utilizing element abstraction, dependency injection, and decoupled persistence strategies.

