from Client import *
from BankBCR import *
import os

class GeneralBank:
    Plafon = 3000
    Accounts = []
    bankBCR = BankBCR()

    def RegisterClient(self):
        client = Client()
        if(client.Register()):
            self.GeneralBankUsers.append(client)
            print("\nSuccesfully registered to bank ", client.card_BankName, " !")
            os.system("pause")
        else:
            print("\nUnsuccesfull registered!")
            os.system("pause")

    def RegisterAccount(self):
        client = Client()
        if(client.RegisterAccount()):
            self.Accounts.append(client)
            print("\nSuccesfully registered account !")
            os.system("pause")
        else:
            print("\nUnsuccesfull registered!")
            os.system("pause")

    def RevizieAccounts(self):
        if(len(self.GeneralBankUsers) != 0):
            for i in range(len(self.GeneralBankUsers)):
                print(self.GeneralBankUsers[i].card_Name, "-",self.GeneralBankUsers[i].money, "$")
        else:
            print("No users !");
        os.system("pause")

    def VerifyUsername(self, username):
         for i in range(len(self.Accounts)):
             if(username == self.Accounts[i].username):
                 return i    
         return 9999

    def VerifyUser(self, cardName):
         for i in range(len(self.GeneralBankUsers)):
             if(cardName == self.GeneralBankUsers[i].card_Name):
                 return i    
         return 9999

    def VerifyPassword(self, index, password):
        if(self.Accounts[index].password == password):
            return True
        return False
    
    def VerifyBank(self, index, bank):
        if(self.GeneralBankUsers[index].card_BankName == bank):
            return True
        return False

