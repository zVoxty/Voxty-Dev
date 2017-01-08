from Card import *
import os

class Client:
    username = ""
    password = ""
    clientSession = True

    CardsOnAccount = []

    def RegisterClientAccount(self, username):
        self.username = username
        self.password = input("Insert password : ")

    def RegisterAccountCard(self):
        newCard = Card()
        print("\n\n\t\t Card registration")

        bank = input("Insert bank name (BCR, BRD)")

        if(bank == "BCR"):
            CardName = input("Insert card name : ")

            if(CardName == ""):
                print("Cannot set empty card name !")
                return ""

            if(len(self.CardsOnAccount) != 0):
                for i in range(len(self.CardsOnAccount)):
                    if(self.CardsOnAccount[i].cardName == CardName):
                        print("Card already exist !")
                        return ""

            newCard.RegisterCard(CardName, bank, self.username)
            self.CardsOnAccount.append(newCard)
            return bank

        elif(bank == "BRD"):
            CardName = input("Insert card name : ")

            if(CardName == ""):
                print("Cannot set empty card name")
                return ""

            if(len(self.CardsOnAccount) != 0):
                for i in range(len(self.CardsOnAccount)):
                    if(self.CardsOnAccount[i].cardName == CardName):
                        print("Card already exist !")
                        return ""

            newCard.RegisterCard(CardName, bank, self.username)
            self.CardsOnAccount.append(newCard)
            return bank

        else:
            print("This bank doesn't exist !")
        return True

    def CheckCards(self):
        #   Solutia aceasta de checkcards folosind o variabila owner in clasa card am folosit-o deoarece
        #de fiecare daca cand se creaza un card se creaza pentru toate obiectele de tipul Client adica lista CardsOnAccount este pentru toti clientii
        #nu am stiut cum sa rezolv aceasta problema.

        os.system("cls")
        print("\n\n\t\t Cards on account", self.username)
        cardsAcc = 0
        for i in range(len(self.CardsOnAccount)):
                if(self.CardsOnAccount[i].owner == self.username):
                    cardsAcc += 1
        if(len(self.CardsOnAccount) == 0 or cardsAcc == 0):
            print("No cards")
            os.system("pause")
        else:
            for i in range(len(self.CardsOnAccount)):
                if(self.CardsOnAccount[i].owner == self.username):
                    print(self.CardsOnAccount[i].cardName, "-","Bank :",self.CardsOnAccount[i].Bank, self.CardsOnAccount[i].moneyOnCard,"$")
            os.system("pause")

        return cardsAcc;

    def CloseCard(self):
        print("\n\n\t\t Close card on account", self.username)
 
        cardName = input("Insert card name : ")
        for i in range(len(self.CardsOnAccount)):
            if(self.CardsOnAccount[i].owner == self.username):                
                if(self.CardsOnAccount[i].cardName == cardName):
                    pin = input("Insert pin : ")
                    if(pin != self.CardsOnAccount[i].cardPin):
                        print("Pin don't match")
                        os.system("pause")
                        return False
                    print("Card",self.CardsOnAccount[i].cardName, "removed")
                    self.CardsOnAccount.remove(self.CardsOnAccount[i])
                    return True
        return False      
        
    def DepositToCard(self):
        print("\n\n\t\t Deposit to card account", self.username)
 
        cardName = input("Insert card name : ")
        for i in range(len(self.CardsOnAccount)):
            if(self.CardsOnAccount[i].owner == self.username):
                if(self.CardsOnAccount[i].cardName == cardName):
                    pin = input("Insert pin : ")
                    if(pin != self.CardsOnAccount[i].cardPin):
                        print("Pin don't match")
                        os.system("pause")
                        return False
                    moneyToDeposit = int(input("Insert sum of money to deposit : "))
                    if(moneyToDeposit < 0):
                        print("Can't deposit negative numbers")
                        return False

                    self.CardsOnAccount[i].moneyOnCard += moneyToDeposit
                    print("Money on card",self.CardsOnAccount[i].cardName,"-",self.CardsOnAccount[i].moneyOnCard)
                    os.system("pause")
                    return True
        return False  

    def Withdraw(self):
        print("\n\n\t\t Withdraw from card account", self.username)
 
        cardName = input("Insert card name : ")
        for i in range(len(self.CardsOnAccount)):
            if(self.CardsOnAccount[i].owner == self.username):
                if(self.CardsOnAccount[i].cardName == cardName):
                    pin = input("Insert pin : ")
                    if(pin != self.CardsOnAccount[i].cardPin):
                        print("Pin don't match")
                        os.system("pause")
                        return False
                    moneyToWithdraw = int(input("Insert sum of money to withdraw : "))
                    if(moneyToWithdraw < 0):
                        print("Can't withdraw negative numbers")
                        return False
                    if(moneyToWithdraw > self.CardsOnAccount[i].moneyOnCard):
                        print("Can't withdraw more than you have")
                        return False

                    self.CardsOnAccount[i].moneyOnCard -= moneyToWithdraw
                    print("Money on card",self.CardsOnAccount[i].cardName,"-",self.CardsOnAccount[i].moneyOnCard)
                    os.system("pause")
                    return True
        return False  

    def Transfer(self):
        print("\n\n\t\t Transfer between cards")
        baseCard = input("Insert base card name : ")
        indexBaseCard = 9999
        for i in range(len(self.CardsOnAccount)):
            if(self.CardsOnAccount[i].owner == self.username):
                if(self.CardsOnAccount[i].cardName == baseCard):
                    pin = input("Insert pin : ")
                    if(pin != self.CardsOnAccount[i].cardPin):
                        print("Pin don't match")
                        os.system("pause")
                        return False
                    indexBaseCard = i

        transferCard = input("Insert insert where to transfer name : ")
        indexTransferCard = 9999
        for i in range(len(self.CardsOnAccount)):
            if(self.CardsOnAccount[i].owner == self.username):
                if(self.CardsOnAccount[i].cardName == transferCard):
                    pin = input("Insert pin : ")
                    if(pin != self.CardsOnAccount[i].cardPin):
                        print("Pin don't match")
                        os.system("pause")
                        return False
                    indexTransferCard = i
        
        if(indexBaseCard == 9999 or indexTransferCard == 9999):
            print("Problem with cards : Existence")
            os.system("pause")
            return False

        transferSum = int(input("How much to transfer : "))

        if(transferSum > self.CardsOnAccount[indexBaseCard].moneyOnCard):
            print("No enought money to transfer !")
            os.system("pause")
            return False
        if(transferSum < 0):
            print("Cannot transfer negative numbers !")
            os.system("pause")
            return False

        self.CardsOnAccount[indexBaseCard].moneyOnCard -= transferSum
        self.CardsOnAccount[indexTransferCard].moneyOnCard += transferSum
        print("Transfer succesfully")       
        os.system("pause")
        return True