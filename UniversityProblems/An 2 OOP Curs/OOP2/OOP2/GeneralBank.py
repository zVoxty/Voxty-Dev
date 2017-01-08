from Client import *
from BCR_Bank import * 

class GeneralBank:
    Accounts = []

    BCRBank = BCR_Bank()

    aplicationOn = True

    def RegisterAccount(self):
        newClient = Client()
        print("\n\n\t\t Account registration")
        rUsername = input("Insert username : ")

        if(rUsername == ""):
            print("Cannot set empty username")
            return False;

        if(len(self.Accounts) != 0):
            for i in range(len(self.Accounts)):
                if(self.Accounts[i].username == rUsername):
                    print("Username already exist !")
                    return False;

        newClient.RegisterClientAccount(rUsername)
        self.Accounts.append(newClient)
        return True

    def VerifyUsername(self, uname):
        for i in range(len(self.Accounts)):
            if(self.Accounts[i].username == uname):
                return i
        return 9999

    def VerifyPassword(self, index, uPass):
        if(self.Accounts[index].password == uPass):
            return True
        return False

    def Refresh(self):
        for i in range(len(self.Accounts)):
            self.Accounts[i].clientSession = True

    def RevAccounts(self):
        accounts = len(self.Accounts)

        if(accounts == 0):
            print("No accounts registered !")
        else:
            for i in range(accounts):
                print(self.Accounts[i].username, self.Accounts[i].password)
    