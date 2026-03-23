# Star Generator

A C-based command-line utility that generates a procedural ASCII star shape. The program calculates the necessary dimensions and coordinates based on a provided "size" integer and renders the result to the terminal.

## Table of Contents

- [Star Generator](#star-generator)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
  - [Installation \& Compilation](#installation--compilation)

---

## Features

- **Dynamic Scaling:** Generates stars of varying sizes based on user input.
- **Memory Efficient:** Uses a stack-allocated 2D array (canvas) for coordinate mapping.
- **Clean Output:** Automatically trims trailing whitespace for a polished terminal look.
- **Input Validation:** Basic checks to ensure only numeric arguments are processed.

## Installation & Compilation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/rahawii/star-generator.git
   cd star-generator
   make
   ./star <size_number>
   ```
