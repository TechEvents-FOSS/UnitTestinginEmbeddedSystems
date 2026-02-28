# Unit Testing in Embedded Systems

| Build | Unit Test | Coverage |
|:--:|:--:|:--:|
| [![Build](https://github.com/TechEvents-FOSS/UnitTestinginEmbeddedSystems/actions/workflows/build.yml/badge.svg)](https://github.com/TechEvents-FOSS/UnitTestinginEmbeddedSystems/actions/workflows/build.yml) | [![Unit Test](https://github.com/TechEvents-FOSS/UnitTestinginEmbeddedSystems/actions/workflows/test.yml/badge.svg)](https://github.com/TechEvents-FOSS/UnitTestinginEmbeddedSystems/actions/workflows/test.yml) | [![Coverage](https://img.shields.io/badge/coverage-0%25-brightgreen)](https://github.com/TechEvents-FOSS/UnitTestinginEmbeddedSystems/actions/workflows/coverage.yml) |

### Running the examples locally
The `Lab1` subproject includes a simple `Makefile` that can be used on Linux/WSL:

```sh
cd Lab1
make all                    # build the test binary
./Lab1                      # run the unit tests
make coverage               # Generate coverage report -> coverage_checksum.txt
cat coverage_checksum.txt   # see percentage for checksum.c
```

## What is Unit testing?
* Isolation of a section of code and validating its correctness
* Testing each modules behavior
* Involves breaking a program into pieces and subjecting each piece to a series of tests

## Why Unit Testing?
* To verify the working of code
* Provides documentation of the code
* Easy debugging
* Bugs are found quicker and fixed at the early stages of SDLC process
* Improves design and quality of code
* Saves time and money
* Helps in refactoring the code for performance and resusability
* Simplifies the integration
* Code covergae can be measured

## When and Who should perform unit testing?
* It is done during the development stage of the project
* Software developers who write the code are resposible for performing Unit testing
* Some safety domain standards like DO178 require independence between those who write  code andthose who write unit tests

## How to do Unit testing?
* By following the **AAA** method:
    * **Arrange**: Initialize the piece of the application to be tested 
    * **Act**: Invoke the units and capture the results
    * **Assert**: Observe and retrospect the behaviour
* Methods of Unit testing:
    * Manual
    * Automation

## Misconceptions and Truths
* It takes more time to write code with Unit test cases, and we don’t have time for that
    * In reality, it would save your development time in the long run
* Unit testing will find all bugs
    * It won’t, as the intent of the Unit test is not to find bugs but develop robust software components that will have fewer defects in later stages of SDLC
* 100% code coverage means 100% test coverage
    * This does not guarantee that code is error-free

## References and additional reading
* [Unit testing and it's importance](https://www.testingxperts.com/blog/unit-testing#What%20are%20some%20important%20Unit%20Test%20frameworks?)
* [Why Unit test my code?](https://www.codemag.com/Article/1901071/10-Reasons-Why-Unit-Testing-Matters)
* [How to write Testabel code](https://www.toptal.com/qa/how-to-write-testable-code-and-why-it-matters)
* [Unity Throw Switch](http://www.throwtheswitch.org/unity) for C Programs