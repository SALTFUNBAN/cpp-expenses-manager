#pragma once
#include "Expense.hpp"
#include <vector>
#include <iostream>

class ExpenseManager
{
public:
	int add(const std::string& title, const std::string& category, const std::string& date, double price, int amount);
	bool removeById(int id);
	const std::vector<Expense>& list() const;
	const Expense* findById(int id) const;
	double totalByMonth(int year, int month) const;
	std::vector<Expense> filterByCategory(const std::string& category) const;
	void setExpenses(std::vector<Expense> expenses);
private:
	std::vector<Expense> expenses_;
	int nextId_ = 1;
};