# Grading System

## Overview
This is a **C-based grading system** designed to facilitate student performance tracking. It enables students to **view their grades remotely**, while admins (teachers) can **add, update, and modify grades**. The system uses **CSV files** as a lightweight database to store student and admin information, making it simple yet efficient.

---

## Features
- **Student Access** – Students can log in using their admission number and view their grades.
- **Admin Access** – Admins can log in using their admin number to modify student grades.
- **Secure Authentication** – Only registered users can access the system.
- **CSV Database** – Uses `students.csv` and `admins.csv` for easy record-keeping.
- **Error Handling** – Detects incorrect logins and file errors.
- **User-Friendly Interface** – Simple command-line interface with clear instructions.
- **Data Persistence** – Stores student and admin records for consistent data management.

---

## Setup Instructions

### Prerequisites
- A **C compiler** (e.g., GCC)
- **Git** installed
- **VS Code** or any C IDE

### Installation Steps
1. **Clone the Repository**
```bash
git clone https://github.com/Vic-kins/Grading-project.git
cd Grading-project
```
2. **Compile the Project**
```bash
gcc -o grading_system src/main.c src/student.c src/admin.c
```
3. **Run the System**
```bash
./grading_system
```

---

## Usage Guide

### For Students:
1. Enter your **admission number** to log in.
2. View your **grades** for English, Kiswahili, Science, Maths, and Social Studies.
3. If your login credentials are incorrect, the system will notify you.
4. Logout when done.

### For Admins:
1. Enter your **admin number** to log in.
2. Choose an option to **view all students' grades or modify grades**.
3. Enter the student’s admission number to update grades.
4. Save changes and logout.

---

## Database Structure

### students.csv (Student Records)
| ID | Name | Admission Number | English | Kiswahili | Science | Maths | Social Studies |
|----|------|-----------------|---------|-----------|---------|-------|--------------|
| 1  | John Doe | ADM001 | 85 | 78 | 90 | 88 | 76 |
| 2  | Jane Smith | ADM002 | 92 | 81 | 85 | 89 | 90 |
| ... | ... | ... | ... | ... | ... | ... | ... |

_(...20 students in total...)_

### admins.csv (Admin Records)
| ID | Name | Admin Number |
|----|------------------|-------------|
| 1  | Dr. Robert Evans | ADMIN001 |
| 2  | Prof. Susan Mitchell | ADMIN002 |
| ... | ... | ... |

_(...5 admins in total...)_

---

## Error Handling & Validation
- **Incorrect Logins** – If a student or admin enters invalid credentials, they will be notified.
- **File Handling Errors** – If CSV files are missing or corrupt, the system alerts the user.
- **Data Integrity** – Ensures grades are within the valid range (0-100).

---

## Contributing
Want to improve this project? Follow these steps:
1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature-name`
3. **Commit your changes**: `git commit -m "Added new feature"`
4. **Push to GitHub**: `git push origin feature-name`
5. **Create a Pull Request (PR)`

---

## License
This project is open-source under the **MIT License**. Feel free to modify and improve!

