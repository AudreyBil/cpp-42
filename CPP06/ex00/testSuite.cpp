///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   testSuite.cpp                                      :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2025/08/06 17:03:21 by abillote          #+#    #+#             */
///*   Updated: 2025/08/06 17:12:38 by abillote         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */

///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   test_scalar_converter.cpp                          :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: tester <tester@student.42.fr>              +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2025/08/06 17:00:00 by tester            #+#    #+#             */
///*   Updated: 2025/08/06 17:00:00 by tester           ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */

//#include "ScalarConverter.hpp"
//#include <sstream>
//#include <vector>
//#include <string>

//struct TestCase {
//    std::string input;
//    std::string expectedOutput;
//    std::string description;
//};

//class ScalarConverterTester {
//private:
//    std::vector<TestCase> testCases;
//    int totalTests;
//    int passedTests;

//    std::string captureOutput(const std::string& input) {
//        std::streambuf* oldCout = std::cout.rdbuf();
//        std::ostringstream capturedOutput;
//        std::cout.rdbuf(capturedOutput.rdbuf());

//        ScalarConverter::convert(input);

//        std::cout.rdbuf(oldCout);
//        return capturedOutput.str();
//    }

//    std::string trim(const std::string& str) {
//        size_t first = str.find_first_not_of(' ');
//        if (std::string::npos == first) {
//            return str;
//        }
//        size_t last = str.find_last_not_of(' ');
//        return str.substr(first, (last - first + 1));
//    }

//    bool compareOutputs(const std::string& expected, const std::string& actual) {
//        std::istringstream expectedStream(expected);
//        std::istringstream actualStream(actual);
//        std::string expectedLine, actualLine;

//        while (std::getline(expectedStream, expectedLine) && std::getline(actualStream, actualLine)) {
//            if (trim(expectedLine) != trim(actualLine)) {
//                return false;
//            }
//        }

//        // Check if both streams are at the end
//        return !std::getline(expectedStream, expectedLine) && !std::getline(actualStream, actualLine);
//    }

//public:
//    ScalarConverterTester() : totalTests(0), passedTests(0) {
//        setupTestCases();
//    }

//    void setupTestCases() {
//        // Character literal tests
//        testCases.push_back({
//            "A",
//            "char: A\nint: 65\nfloat: 65.0f\ndouble: 65.0\n",
//            "Character 'A' conversion"
//        });

//        testCases.push_back({
//            "z",
//            "char: z\nint: 122\nfloat: 122.0f\ndouble: 122.0\n",
//            "Character 'z' conversion"
//        });

//        // Integer literal tests
//        testCases.push_back({
//            "42",
//            "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n",
//            "Integer 42 conversion"
//        });

//        testCases.push_back({
//            "0",
//            "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n",
//            "Integer 0 conversion"
//        });

//        testCases.push_back({
//            "-42",
//            "char: Non displayable\nint: -42\nfloat: -42.0f\ndouble: -42.0\n",
//            "Negative integer -42 conversion"
//        });

//        testCases.push_back({
//            "127",
//            "char: Non displayable\nint: 127\nfloat: 127.0f\ndouble: 127.0\n",
//            "Integer 127 (DEL character) conversion"
//        });

//        // Float literal tests
//        testCases.push_back({
//            "42.0f",
//            "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n",
//            "Float 42.0f conversion"
//        });

//        testCases.push_back({
//            "42.42f",
//            "char: '*'\nint: 42\nfloat: 42.42f\ndouble: 42.42\n",
//            "Float 42.42f conversion"
//        });

//        testCases.push_back({
//            "-4.2f",
//            "char: Non displayable\nint: -4\nfloat: -4.2f\ndouble: -4.2\n",
//            "Negative float -4.2f conversion"
//        });

//        // Double literal tests
//        testCases.push_back({
//            "42.0",
//            "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n",
//            "Double 42.0 conversion"
//        });

//        testCases.push_back({
//            "42.42",
//            "char: '*'\nint: 42\nfloat: 42.42f\ndouble: 42.42\n",
//            "Double 42.42 conversion"
//        });

//        testCases.push_back({
//            "-4.2",
//            "char: Non displayable\nint: -4\nfloat: -4.2f\ndouble: -4.2\n",
//            "Negative double -4.2 conversion"
//        });

//        // Special float cases
//        testCases.push_back({
//            "nanf",
//            "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n",
//            "Float NaN conversion"
//        });

//        testCases.push_back({
//            "+inff",
//            "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n",
//            "Float positive infinity conversion"
//        });

//        testCases.push_back({
//            "-inff",
//            "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n",
//            "Float negative infinity conversion"
//        });

//        // Special double cases
//        testCases.push_back({
//            "nan",
//            "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n",
//            "Double NaN conversion"
//        });

//        testCases.push_back({
//            "+inf",
//            "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n",
//            "Double positive infinity conversion"
//        });

//        testCases.push_back({
//            "-inf",
//            "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n",
//            "Double negative infinity conversion"
//        });

//        // Edge cases
//        testCases.push_back({
//            "2147483647",
//            "char: Non displayable\nint: 2147483647\nfloat: 2.14748e+09f\ndouble: 2.14748e+09\n",
//            "INT_MAX conversion"
//        });

//        testCases.push_back({
//            "-2147483648",
//            "char: Non displayable\nint: -2147483648\nfloat: -2.14748e+09f\ndouble: -2.14748e+09\n",
//            "INT_MIN conversion"
//        });

//        // Invalid/impossible conversions
//        testCases.push_back({
//            "invalid",
//            "This conversion is not possible as this type is unknown.\n",
//            "Invalid string conversion"
//        });

//        totalTests = testCases.size();
//    }

//    void runSingleTest(const TestCase& testCase, int testNumber) {
//        std::cout << "\n--- Test " << testNumber << ": " << testCase.description << " ---" << std::endl;
//        std::cout << "Input: \"" << testCase.input << "\"" << std::endl;

//        std::string actualOutput = captureOutput(testCase.input);

//        std::cout << "\nExpected Output:" << std::endl;
//        std::cout << testCase.expectedOutput;

//        std::cout << "\nActual Output:" << std::endl;
//        std::cout << actualOutput;

//        bool passed = compareOutputs(testCase.expectedOutput, actualOutput);

//        if (passed) {
//            std::cout << "✅ PASSED" << std::endl;
//            passedTests++;
//        } else {
//            std::cout << "❌ FAILED" << std::endl;
//            std::cout << "\n🔍 Detailed Comparison:" << std::endl;

//            std::istringstream expectedStream(testCase.expectedOutput);
//            std::istringstream actualStream(actualOutput);
//            std::string expectedLine, actualLine;
//            int lineNumber = 1;

//            while (std::getline(expectedStream, expectedLine) || std::getline(actualStream, actualLine)) {
//                std::cout << "Line " << lineNumber << ":" << std::endl;
//                std::cout << "  Expected: \"" << expectedLine << "\"" << std::endl;
//                std::cout << "  Actual  : \"" << actualLine << "\"" << std::endl;

//                if (trim(expectedLine) != trim(actualLine)) {
//                    std::cout << "  ❌ MISMATCH" << std::endl;
//                } else {
//                    std::cout << "  ✅ MATCH" << std::endl;
//                }
//                lineNumber++;
//            }
//        }
//    }

//    void runAllTests() {
//        std::cout << "🧪 Running ScalarConverter Test Suite" << std::endl;
//        std::cout << "=====================================" << std::endl;

//        for (size_t i = 0; i < testCases.size(); ++i) {
//            runSingleTest(testCases[i], i + 1);
//        }

//        std::cout << "\n📊 TEST SUMMARY" << std::endl;
//        std::cout << "===============" << std::endl;
//        std::cout << "Total Tests: " << totalTests << std::endl;
//        std::cout << "Passed: " << passedTests << std::endl;
//        std::cout << "Failed: " << (totalTests - passedTests) << std::endl;
//        std::cout << "Success Rate: " << std::fixed << std::setprecision(1)
//                  << (static_cast<double>(passedTests) / totalTests * 100.0) << "%" << std::endl;

//        if (passedTests == totalTests) {
//            std::cout << "\n🎉 ALL TESTS PASSED! 🎉" << std::endl;
//        } else {
//            std::cout << "\n⚠️  " << (totalTests - passedTests) << " test(s) failed. Please review above." << std::endl;
//        }
//    }

//    void runSpecificTest(int testNumber) {
//        if (testNumber < 1 || testNumber > static_cast<int>(testCases.size())) {
//            std::cout << "Invalid test number. Valid range: 1-" << testCases.size() << std::endl;
//            return;
//        }

//        passedTests = 0; // Reset for single test
//        runSingleTest(testCases[testNumber - 1], testNumber);

//        std::cout << "\nResult: " << (passedTests == 1 ? "PASSED" : "FAILED") << std::endl;
//    }

//    void listTests() {
//        std::cout << "\n📋 Available Tests:" << std::endl;
//        std::cout << "==================" << std::endl;

//        for (size_t i = 0; i < testCases.size(); ++i) {
//            std::cout << i + 1 << ". " << testCases[i].description
//                      << " (Input: \"" << testCases[i].input << "\")" << std::endl;
//        }
//    }
//};

//int main(int argc, char* argv[]) {
//    ScalarConverterTester tester;

//    if (argc == 1) {
//        // Run all tests
//        tester.runAllTests();
//    } else if (argc == 2) {
//        std::string arg = argv[1];

//        if (arg == "list" || arg == "-l") {
//            tester.listTests();
//        } else {
//            // Try to run specific test number
//            int testNumber = std::atoi(argv[1]);
//            if (testNumber > 0) {
//                tester.runSpecificTest(testNumber);
//            } else {
//                std::cout << "Usage: " << argv[0] << " [test_number|list|-l]" << std::endl;
//                std::cout << "  Run without arguments to execute all tests" << std::endl;
//                std::cout << "  Use 'list' or '-l' to see available tests" << std::endl;
//                std::cout << "  Use test number (1-N) to run specific test" << std::endl;
//            }
//        }
//    } else {
//        std::cout << "Usage: " << argv[0] << " [test_number|list|-l]" << std::endl;
//    }

//    return 0;
//}
