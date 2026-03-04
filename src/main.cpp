#include <limits>
#include "ExpenseManager.hpp"
#include "Storage.hpp"

void printExpenses(const std::vector<Expense>& expenses)
{
	for (const Expense& e : expenses)
	{
		std::cout << "ID = " << e.id << std::endl;
		std::cout << "Title = " << e.title << std::endl;
		std::cout << "Category = " << e.category << std::endl;
		std::cout << "Date = " << e.date << std::endl;
		std::cout << "Price = " << e.price << std::endl;
		std::cout << "Amount = " << e.amount << std::endl << std::endl;
	}
}

int main()
{
	const std::string filename = "data/expenses.txt";

	ExpenseManager expenseManager;
	Storage storage(filename, expenseManager);

	int choice;

	do
	{
		std::cout << "1) Add" << std::endl;
		std::cout << "2) List" << std::endl;
		std::cout << "3) Delete by ID" << std::endl;
		std::cout << "4) Total for Month" << std::endl;
		std::cout << "5) Filter by category" << std::endl;
		std::cout << "0) Exit" << std::endl << std::endl;

		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{

		case 1:
		{
			std::string title;
			std::string category;
			std::string date;
			double price;
			int amount;

			std::cout << "Enter title: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, title);

			std::cout << "Enter Category: ";
			std::cin >> category;

			std::cout << "Enter Date: ";
			std::cin >> date;

			std::cout << "Enter Price: ";
			std::cin >> price;

			std::cout << "Enter Amount: ";
			std::cin >> amount;

			std::cout << std::endl;

			std::cout << "Added new element with id: " << expenseManager.add(title, category, date, price, amount) << std::endl << std::endl;
			break;
		}
		case 2:
		{
			const auto& expenses = expenseManager.list();
			printExpenses(expenses);
			break;
		}
		case 3:
		{
			std::cout << "Enter ID: ";
			int id;
			std::cin >> id;
			if (expenseManager.removeById(id)) std::cout << "Deleted" << std::endl << std::endl;
			else std::cout << "Didn't delete" << std::endl << std::endl;
			break;
		}
		case 4:
		{
			std::cout << "Enter year: ";
			int year;
			std::cin >> year;

			std::cout << "Enter month: ";
			int month;
			std::cin >> month;

			if (month < 1 || month > 12)
			{
				std::cout << "Invalid month!\n\n";
				break;
			}

			double total = expenseManager.totalByMonth(year, month);
			if (total == 0.0) std::cout << "No expenses for this month" << std::endl << std::endl;
			std::cout << "Total = " << total << std::endl << std::endl;

			break;
		}
		case 5:
		{
			std::cout << "Enter category to filter: ";
			std::string category;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, category);

			const auto filtered = expenseManager.filterByCategory(category);
			printExpenses(filtered);
			break;
		}
		case 0: 
		{
			if (storage.save(expenseManager.list())) std::cout << "Data saved!" << std::endl;
			else std::cout << "Error! Data not saved!" << std::endl;
			break;
		}
		default:
		{
			std::cout << "Error! Unknown command!" << std::endl;
			break;
		}
		}

	} while (choice != 0);
}