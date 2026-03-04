#pragma once
#include "Expense.hpp"
#include "ExpenseManager.hpp"
#include <vector>
#include <string>

class Storage
{
	std::string filename_;

public:
	explicit Storage(const std::string& file_name, ExpenseManager& expenseManager);
	bool save(const std::vector<Expense>& data) const;
	std::vector<Expense> load() const;
};