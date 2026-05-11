# Modern C++ Student Roster Management System

## 📌 Project Overview
This repository contains a high-performance console application for managing student records. Originally developed as a standard university assignment, this project has been fully refactored to comply with **Modern C++20 standards**, emphasizing memory safety, efficient data structures, and object-oriented encapsulation.

## 🚀 Engineering Refactor Highlights
I transitioned this codebase from legacy "C-style" patterns to professional-grade C++ to demonstrate technical proficiency in resource management.

### 1. Memory Safety via RAII
* **Smart Pointers:** Replaced manual `new` and `delete` cycles with `std::unique_ptr`.
* **Zero Leaks:** Leveraged **Resource Acquisition Is Initialization (RAII)** to ensure automatic memory deallocation, eliminating the risk of memory leaks common in legacy C++ projects.

### 2. Modern Data Structures
* **Dynamic Scaling:** Migrated from fixed-size raw arrays to `std::vector`, allowing the roster to scale dynamically while maintaining $O(1)$ access time for individual elements.
* **Type Safety:** Implemented `std::array` for internal student data to prevent pointer decay and out-of-bounds errors.

### 3. Professional Output Formatting
* **<iomanip> Integration:** Used `std::setw` and `std::left` to produce a perfectly aligned, table-consistent console UI regardless of data string length.
* **Fixed-Point Precision:** Ensured average days in course are calculated and displayed with floating-point precision for academic accuracy.

### 4. Robust Data Parsing
* **Stringstreams:** Implemented a robust CSV parsing engine using `std::stringstream`, replacing fragile substring manipulation with a safer, token-based approach.

---

## 📊 Final Output Preview
<img width="1862" height="938" alt="590168018-dd091274-f296-46c1-89f5-00320d3924cb" src="https://github.com/user-attachments/assets/24ec0d53-ac42-4781-925b-82c4d8897715" />



---

## 🛠 Technical Stack
* **Language:** C++20
* **IDE:** Visual Studio 2022
* **Library:** Standard Template Library (STL)
* **Design Pattern:** Object-Oriented Programming (OOP)

## 📖 Key Takeaways
This project served as a deep dive into **Variable Scope**, **Member Initializer Lists**, and the **One Definition Rule (ODR)**. By modernizing the architecture, I improved the maintainability and reliability of the system while adhering to modern industry best practices.
