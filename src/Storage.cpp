#include "Storage.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Storage::Storage(const std::string& file_name, ExpenseManager& expenseManager)
    : filename_(file_name)
{
    expenseManager.setExpenses(load());
}

std::vector<Expense> Storage::load() const
{
    // format: id|title|category|date|price|amount

	std::ifstream in(filename_);
	std::vector<Expense> expenses;
	if (!in) 
    {
        std::cout << std::endl << "Error! Cannot open file" << std::endl << std::endl;
        return expenses;
    }

	std::string line;

	while (std::getline(in, line))
	{
        if (line.empty()) continue;

        try 
        {
            std::stringstream ss(line);
            Expense e;
            std::string temp;

            std::getline(ss, temp, '|'); e.id = std::stoi(temp);
            std::getline(ss, e.title, '|');
            std::getline(ss, e.category, '|');
            std::getline(ss, e.date, '|');
            std::getline(ss, temp, '|'); e.price = std::stod(temp);
            std::getline(ss, temp, '|'); e.amount = std::stoi(temp);

            expenses.push_back(std::move(e));;
        }
        catch (const std::exception& ex)
        {
            std::cerr << "Bad line skipped: [" << line << "]  reason: " << ex.what() << "\n";
            continue;
        }
	}

	return expenses;
}

bool Storage::save(const std::vector<Expense>& data) const
{
    // format: id|title|category|date|price|amount

    std::ofstream out(filename_);
    if (!out) return false;

    for (auto& e : data)
    {
        out << e.id << "|"
            << e.title << "|"
            << e.category << "|"
            << e.date << "|"
            << e.price << "|"
            << e.amount << "\n";
    }

    return true;
}