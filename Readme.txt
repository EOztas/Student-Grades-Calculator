
This C++ program reads student performance data from a CSV file named "data.csv," calculates weighted scores based on specified criteria, and determines whether each student has passed or failed. The user should provide input data in the CSV file format, with semicolons separating the columns. The columns should represent the following information:

Student ID
Midterm exam scores
Homework averages
Quiz averages
Final exam scores
The program uses a weighted scoring system, where midterms contribute 40%, homework averages contribute 10%, quiz averages contribute 10%, and finals contribute 40% to the overall score.

Here's a step-by-step explanation of how the code works:

calculateWeightedScore Function:

This function takes a vector of strings (data) as input, representing a single student's data.
It extracts numeric values from the relevant positions in the vector and calculates the weighted score based on the specified percentages for midterms, homework averages, quizzes, and finals.
If the data vector doesn't contain enough elements, an exception is thrown.
If a conversion error or out-of-range error occurs during the extraction of numeric values, appropriate exceptions are thrown.
main Function:

Specifies the input file name as "data.csv."
Opens the file and checks for any errors in the file opening process.
Initializes variables to keep track of the number of passing and failing students.
Reads lines from the file and parses each line into a vector of strings (studentData) using semicolons as delimiters.
Calls the calculateWeightedScore function for each student's data to calculate the weighted score.
Determines whether the student has passed or failed based on the calculated score.
Updates counters for passing and failing students accordingly.
Catches and handles exceptions that might occur during the processing of each student's data.
Prints the results, including student ID, weighted score, and pass/fail status, to the console.
Results:

After processing all students, the program prints the total number of students who passed and failed.
Error Handling:

The program includes error handling for cases where the data vector doesn't contain enough elements or when conversion errors or out-of-range errors occur during the extraction of numeric values.
User Interaction:

The user interacts with the program by providing input data in the "data.csv" file.
The program processes the data, calculates the weighted scores, and informs the user about the pass/fail status of each student.
Note to the User:

Ensure that the input data in "data.csv" adheres to the specified format for the program to work correctly.
If any errors occur during the processing of a student's data, the program will display an error message for that specific student.