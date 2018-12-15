#include <iostream>
struct BankAccount
{
	__int64 accountNumber;
	__int64 balance;
};

int main()
{
	BankAccount myAccount = { 123456789, 50 }; // $50
	BankAccount *pAccount = &myAccount; 

	std::cout << "My bank account number: " << myAccount.accountNumber << std::endl;
	std::cout << "My bank account number: " << pAccount->accountNumber << std::endl;

	std::cout << "My balance: " << myAccount.balance << std::endl;
	std::cout << "My balance: " << pAccount->balance << std::endl;

	return 0;
}