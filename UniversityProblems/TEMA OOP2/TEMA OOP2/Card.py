import os

class Card:
    card_Name = ""
    card_Pin = 0
    card_BankName = ""
    money = 0

    def RegisterCard(self, bank):
        os.system('cls')
        self.card_BankName = bank
        cardName = input("\nInsert card name : ")
        if(cardName == ""):
            return False

        self.card_Name = cardName 
        self.card_Pin = int(input("Insert card PIN :"))
        print("\n\t\t Register Card ")
    
        return True