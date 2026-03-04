#pragma once
#include <string>

struct Expense
{
	int id;
	std::string title;
	std::string category;
	std::string date;
	double price;
	int amount;
};