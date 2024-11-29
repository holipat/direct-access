Student Registration System - Direct Access
This project uses the Direct Access method to manage student records in the file system. Data is accessed directly based on a fixed structure, allowing for fast read and write operations.

Features:
Direct Access: Student data is accessed directly based on their number. The fseek() function is used to jump to specific locations in the file for operations.
Data Storage: Student information is stored in the file, and direct access is provided for each student record.

Usage:
Create New File: A file to hold 100 student records is created initially.
Add Student: The user adds a new student based on their number. An error message is shown if the student already exists.
Find Student: The user searches for a student by their number, and if found, their information is displayed.

How Direct Access Works:
Each student record is accessed directly in the file. The fseek() function is used to jump to the specific location based on the student number, and the operation is performed. This method improves data access speed.
