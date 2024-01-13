#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

double calculateWeightedScore(const std::vector<std::string>& data) {
    if (data.size() < 8) {
        throw std::invalid_argument("Data vector does not contain enough elements.");
    }

    try {
        double m = std::stod(data[1]) * 0.40;    //midterms  %40
        double hwt = std::stod(data[2]) * 0.10;  //homeworks averages  %10
        double qt = std::stod(data[3]) * 0.10;   //quiz averages  %10
        double f = std::stod(data[4]) * 0.40;    //finals  %40

        return m + hwt + qt + f;  
    }
    catch (const std::invalid_argument& e) {
        // Conversion error
        throw std::invalid_argument("Invalid data format: " + std::string(e.what()));
    }
    catch (const std::out_of_range& e) {
        // Number is out of the range error
        throw std::out_of_range("Out of range error: " + std::string(e.what()));
    }
}

int main() {
    // Specify the file name
    const std::string fileName = "data.csv";

    // Open the file
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return 1;
    }

    // Variables holding the number of passing and failing students
    int passedCount = 0;
    int failedCount = 0;

    // Read lines from the file and determine the status of each student
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> studentData;
        std::istringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ';')) {
            studentData.push_back(cell);
        }

        try {
            double weightedScore = calculateWeightedScore(studentData);

            // Update the number of students accordingly
            if (weightedScore < 50.0) {
                std::cout << "Student ID: " << studentData[0] << ", Weighted Score: " << weightedScore << ", Status: Failed" << std::endl;
                failedCount++;
            }
            else {
                std::cout << "Student ID: " << studentData[0] << ", Weighted Score: " << weightedScore << ", Status: Passed" << std::endl;
                passedCount++;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error for student " << studentData[0] << ": " << e.what() << std::endl;
        }
    }

    // Close the file
    file.close();

    // Print the results
    std::cout << std::endl;

    std::cout << "Failed: " << failedCount << " Student\n";

    std::cout << "Passed: " << passedCount << " Student\n";

    return 0;
}
