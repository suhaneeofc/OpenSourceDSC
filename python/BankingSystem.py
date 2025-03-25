from Bank import Bank, BankAccount, BankingSystem

banking_system = BankingSystem()
banking_system.simulate_transactions()

bank = banking_system.bank

account_id = bank.create_account("User", 5000)
account = bank.get_account(account_id)

account.withdraw(5500)  

for transaction in account.transaction_history:
    print(transaction)
