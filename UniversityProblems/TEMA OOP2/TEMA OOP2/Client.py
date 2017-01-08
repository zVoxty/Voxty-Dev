import os
from Card import *

class Client:
    username = ""
    password = ""
    sessionOn = True
    UserCards = []

    def RegisterAccount(self):
        os.system('cls')
        print("\n\t\t Register Account ")
        username = input("\nInsert username : ")
        if(username == ""):
            print("Username cannot be empty !")
            return False;
        self.username = username
        self.password = input("Insert password : ")
        return True;

    def RegisterCard(self, bank):
        card = Card()
        if(card.RegisterCard(bank)):
            print("Card registered")
            self.UserCards.append(card)
            return True
        return False
        

    def showCards(self):  
        for i in range (len(self.UserCards)):
            print(self.UserCards[i].card_Name,"-",self.UserCards[i].money)
