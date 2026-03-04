#include "ExpenseManager.hpp"
#include <algorithm>

int ExpenseManager::add(const std::string& title, const std::string& category, const std::string& date, double price, int amount)
{
	// format: id|title|category|date|price|amount

	Expense e;

	e.id = nextId_++;
	e.title = title;
	e.category = category;
	e.date = date;
	e.price = price;
	e.amount = amount;

	expenses_.push_back(e);
	return nextId_ - 1;
}

bool ExpenseManager::removeById(int id)
{
	auto oldSize = expenses_.size();
	
	expenses_.erase(std::remove_if(
		expenses_.begin(), 
		expenses_.end(), 
		[id](const Expense& e) { return e.id == id; }), 
		expenses_.end()
	);

	return oldSize != expenses_.size();
}

const std::vector<Expense>& ExpenseManager::list() const
{
	return expenses_;
}

const Expense* ExpenseManager::findById(int id) const
{
	for (const Expense& e : expenses_)
	{
		if (e.id == id) return &e;
	}

	return nullptr;
}

double ExpenseManager::totalByMonth(int year, int month) const
{
	double sum = 0;

	std::string monthStr = (month < 10) ? "0" + std::to_string(month) : std::to_string(month);

	std::string prefix = std::to_string(year) + "-" + monthStr + "-";

	for (const Expense& e : expenses_)
	{
		if (e.date.rfind(prefix, 0) == 0)
		{
			sum += e.price * e.amount;
		}
	}

	return sum;
}

std::vector<Expense> ExpenseManager::filterByCategory(const std::string& category) const
{
	std::vector<Expense> result;
	result.reserve(expenses_.size());

	for (const Expense& e : expenses_) if (e.category == category) result.push_back(e);

	return result;
}

void ExpenseManager::setExpenses(std::vector<Expense> expenses)
{
	expenses_ = std::move(expenses);

	int maxId = 0;
	for (const auto& e : expenses_)
	{
		if (e.id > maxId)
			maxId = e.id;
	}

	nextId_ = maxId + 1;
}