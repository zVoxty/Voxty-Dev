from Client import *
import os
class BankBCR():
    y = 3000

    bankBCR_users = []

    def RegisterCard(self, client, bank):
        if(client.RegisterCard(bank)):
            print("Registered succesfully to BCR !")
            self.bankBCR_users.append(client)
            os.system("pause")
        else:
            print("Something happen !")    

    def checkClientCards(self, client):
        print("\n\t\t Show cards for ", client.username)
        client.showCards()
        os.system("pause")
