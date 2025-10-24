# ICS_Major_Project
ICS major project for spring session 2025
# Basic Machine Learning Algorithms in C

## Overview

This project demonstrates the implementation of fundamental Machine Learning (ML) algorithms using the C programming language. It was developed as part of the ICS Major Project by a team of five undergraduate students. While most ML libraries are typically built in Python, R, or MATLAB, our goal was to understand the inner workings of ML by building models from scratch in C — a low-level language that offers great control and performance.

## Team Members

- Atharv Sharma  (B24CM1013)
- Jainam Shah  (B24CS1071)  

## Motivation

With the rising popularity of machine learning, we wanted to explore how core ML concepts such as regression, classification, and clustering work under the hood. C provides a solid foundation for understanding memory management, data structures, and algorithmic logic, making it an excellent language to explore the fundamentals of ML.

## Features

We have implemented the following basic ML algorithms:

- **Data Scaling**
- **Linear Regression**  
- **Logistic Regression**
- **K-Nearest Neighbors (KNN)**
- **Softmax Regression**

All algorithms are written from scratch without using external ML libraries.

## Project Structure
## Installation


1.)GNUPLOT INSTALLATION
* For Ubuntu 
```
sudo apt-get update
sudo apt install gnuplot
```


*  For MacOs
```
brew install gnuplot
```


* For Windows
 You can download the installer from the official Gnuplot website: https://sourceforge.net/projects/gnuplot/files/gnuplot/

to use gnuplot in your code replace the location of gnuplot in model_functions.c line 130 with the loaction where gnuplot in installed locally.

         






2.) CODE INSTALLATION                 


1. Clone the repository:

   https://github.com/AtharvSharmaAI/ICS_Major_Project.git



2. Navigate to the project directory:
```
   cd New folder
```


3. Compile the project
```
   gcc -o main main.c -lm
```








## Usage


1. Run the compiled executable:
   ```
   ./main
   ```
2. Select your desired operation along with dataset.

## Contributions

**Atharv Sharma**
Integrated all the function in main file and made the command prompt user friendly along with writing the function of Linear Regression, Logistics Regression,Data Scaling


**Jainam Shah**
Made the function for Softmax Regression and GNUPLOT integration for graphical view


