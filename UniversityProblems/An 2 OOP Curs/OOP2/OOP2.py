from GeneralBank import *
import os

if __name__ == "__main__":
    generalBank = GeneralBank()

    while(generalBank.aplicationOn):
        os.system("cls")
        generalBank.Refresh()
        print("\n\n\t\t Main")
        print("1) Login")
        print("2) Register")
        print("3) Exit")
        option = input("\n Your option : ")

        if(option == "1"):
            os.system("cls")
            print("\n\n\t\t Login form\n")
            username = input("Insert username : ")
            userIndex = generalBank.VerifyUsername(username)
            if(userIndex != 9999):
                password = input("Insert password : ")
                if(generalBank.VerifyPassword(userIndex,password)):
                    while(generalBank.Accounts[userIndex].clientSession):
                        os.system("cls")
                        print("\n\t\t User interface ")
                        print("1) Register card ")
                        print("2) Check cards ")
                        print("3) Close card ")
                        print("4) Deposit to card")
                        print("5) Withdraw from card")
                        print("6) Transfer between cards")
                        print("7) Exit")
                        option = input("Your option : ")
                        if(option == "1"):
                            bank = generalBank.Accounts[userIndex].RegisterAccountCard()
                            print("Registration card succesfully")
                            os.system("pause")
                        elif(option == "2"):
                            generalBank.Accounts[userIndex].CheckCards()
                        elif(option == "3"):
                            if(generalBank.Accounts[userIndex].CloseCard()):                         
                                generalBank.BCRBank.registeredAccounts.remove(generalBank.Accounts[userIndex])
                                print("Card closed succesfully")
                                os.system("pause")
                            else:
                                print("Card doens't exist !")
                                os.system("pause")
                        elif(option == "4"):
                            if(generalBank.Accounts[userIndex].DepositToCard()):
                                print("Deposit succesfully and refreshed account")
                                os.system("pause")
                            else:
                                print("Problem to deposit !")
                                os.system("pause")
                        elif(option == "5"):
                            if(generalBank.Accounts[userIndex].Withdraw()):
                                print("Withdraw succesfully and refreshed account")
                                os.system("pause")
                            else:
                                print("Problem to withdraw !")
                                os.system("pause")
                        elif(option == "6"):
                            if(generalBank.Accounts[userIndex].Transfer()):                               
                                print("Transfer succesfully and refreshed account")
                                os.system("pause")
                            else:
                                print("Problem to transfer try again later !")
                                os.system("pause")
                        elif(option == "7"):
                            generalBank.Accounts[userIndex].clientSession = False
                        else:
                            print("Wrong choice")
                else:
                    print("Password don't match !")
                    os.system("pause")
            else:
                print("Username don't exist !")
                os.system("pause")
        elif(option == "2"):
            if(generalBank.RegisterAccount()):
                print("Registration succesfull")
                os.system("pause")
            else:
                print("Registration problem")
                os.system("pause")
        elif(option == "3"):
            generalBank.aplicationOn = False
        else:
            print("Wrong option")