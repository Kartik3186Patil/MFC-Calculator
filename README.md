# MFC Calculator

This project is a simple calculator application built using the **Microsoft Foundation Classes (MFC)** framework. It demonstrates basic arithmetic operations (Addition, Subtraction, Multiplication, and Division) and uses MFC dialog boxes to create an intuitive user interface.

<!--
Annotation: The title gives a clear overview of the project. This project uses MFC (Microsoft Foundation Classes) for the GUI and implements basic calculator functions.
-->

## Key Features

### Basic Arithmetic Operations:
- **Addition**
- **Subtraction**
- **Multiplication**
- **Division** (with error handling for division by zero)

<!--
Annotation: This section lists the basic arithmetic functions implemented in the project. The operations are self-explanatory, and division has error handling to avoid division by zero errors.
-->

### User Interface:
- **Textboxes** for inputting numbers.
- **ComboBox** for selecting the operation.
- A **ListBox** to display the history of operations.
- **Static Text** for displaying the result of the operation.
- **Buttons** for clearing the history and performing the calculation.

<!--
Annotation: This section explains the components of the GUI built using MFC dialog boxes. It highlights user input elements and the result display components.
-->

### Error Handling:
- Displays an error message for invalid inputs (e.g., empty fields).
- Prevents division by zero, providing a proper error message when this occurs.

<!--
Annotation: The error handling ensures a robust user experience by catching invalid inputs and preventing division by zero errors.
-->

---

## Technologies Used:
- **Microsoft Foundation Classes (MFC)**: Framework for creating the graphical user interface and handling events.
- **C++**: The primary programming language used for implementing the calculator logic.
- **Windows API**: For handling window interactions, such as dialog boxes, buttons, and user inputs.

<!--
Annotation: This section lists the primary technologies and tools used in the project. MFC is used for creating the UI and handling events, while C++ is used for the logic.
-->

---

## Installation

### Prerequisites:
- **Microsoft Visual Studio** (2017 or later) with **MFC** support enabled.

<!--
Annotation: To run the project, you need Visual Studio installed with MFC support. This is necessary for compiling and running MFC-based applications.
-->

### Steps to Run:
1. Clone or download the repository.
2. Open the solution file in **Visual Studio**.
3. Build and run the project.

<!--
Annotation: These are the simple steps to set up the project and run it in Visual Studio.
-->

### Usage:
1. **Enter two numbers** in the input fields.
2. **Select an operation** from the combo box.
3. **Click the "Calculate" button** to perform the calculation.
4. View the result in the **output field**.
5. The **operation history** will be displayed in the ListBox.

<!--
Annotation: This section guides the user on how to use the calculator after it's been set up.
-->
