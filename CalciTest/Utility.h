#pragma once
#include<iostream>
#include<string>
class Utility
{

public:
	enum Operation
	{
		ADDITION, 
		SUBSTRACTION,
		MULTIPLICATION,
		DIVISION
	};

	enum Result {
		Success,
		Failed
	};
	Result performOperation(float num1, float num2, Operation currentOperation, float &result);
	void clearNumbers();
};

