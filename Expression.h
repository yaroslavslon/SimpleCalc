﻿#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <memory>
#include <iomanip>
#include "Token.h"
#include "Operand.h"
#include "Operation.h"
#include "AST.h"
class Expression
{
private:
	std::string inputExpression;
	std::vector<std::shared_ptr<Token>> processedInputExpression;
	std::vector<std::shared_ptr<Token>> rpnProcessedInputExpression;
	AST ast;
	long double ans;
public:
	struct LogicError :
		public std::logic_error
	{
		explicit LogicError() :logic_error{ "Unknown error.\n" } {}
		explicit LogicError(const std::string &error) :logic_error{ error } {}
	};
	struct Exit :
		public std::exception
	{
		explicit Exit() :std::exception{ "Quiting...\n" }{};
	};
	explicit Expression() = default;
	void parse();
	bool isOperation(const char &symbol);
	long double stringToDouble(const std::string &string);
	void getRpnData();
	void getAst();
	void getAns();
	void clear();
	friend std::istream& operator>>(std::istream &input, Expression &expressionObject);
	friend std::ostream& operator<<(std::ostream &output, Expression &expressionObject);
	~Expression() = default;
};
