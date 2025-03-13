#include "pch.h"
#include "Utility.h"

Utility::Result Utility::performOperation(float num1, float num2, Operation currentOperation, float &result) {


	if (currentOperation == Operation::ADDITION) {
		result = num1 + num2;
	}
	else if (currentOperation == Operation::SUBSTRACTION) {
		result = num1 - num2;
	}
	else if (currentOperation == Operation::DIVISION) {
		if (num2 == 0) {
			AfxMessageBox(_T("Error: Division by zero"));
			return Utility::Result::Failed;
		}
		else {
			result = num1 / num2;
		}

	}
	else if (currentOperation == Operation::MULTIPLICATION) {
		result = num1 * num2;
	}
	

	return Utility::Result::Success;
}


