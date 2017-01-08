from GeneralBank import *
import os

if __name__ == "__main__":
   
    appActive = True
    generalBank = GeneralBank()

    while(appActive):
        os.system('cls')
        print("\n\t\t Lobby ")
        print("1) Login")
        print("2) Register")
        print("3) Exit")
        option = input("Insert your option : ")

        if(option == "1"):
            os.system('cls')
            print("\n\t\t Session ")

            username = input("Insert username : ")
            index = generalBank.VerifyUsername(username)

            if(index != 9999):             
                password = input("Insert your password : ")

                if(generalBank.VerifyPassword(index, password)):
                    while(generalBank.Accounts[index].sessionOn):
                        os.system("cls")
                        print("\n\t\t User interface ")
                        print("1) Register card ")
                        print("2) Check cards ")
                        print("3) Close card ")
                        print("4) Deposit to card")
                        print("5) Withdraw from card")
                        print("6) Transfer between cards")
                        print("7) Exit")

                        option = input("\nInsert option : ")
                        if(option == "1"):
                            bank = input("Choose bank (BCR, BRD) : ")
                            if(bank == "BCR"):
                                generalBank.bankBCR.RegisterCard(generalBank.Accounts[index], bank)
                            elif(bank == "BRD"):
                                os.system("pause")
                            else:
                                print("This bank don't exist")

                        elif(option == "2"):
                            generalBank.bankBCR.checkClientCards(generalBank.Accounts[index])
                        elif(option == "3"):
                            os.system("pause")
                        elif(option == "4"):
                            os.system("pause")
                        elif(option == "5"):
                            os.system("pause")
                        elif(option == "6"):
                            os.system("pause")
                        elif(option == "7"):
                            generalBank.Accounts[index].sessionOn = False
                        else:
                            print("Wrong choice")
                else:
                    print("Wrong password for username", username)
                    os.system("pause")

            else:
                print("This user does not exist !")
                os.system("pause")

        elif(option == "2"):
            generalBank.RegisterAccount();

        elif(option == "3"):
            appActive = False

        else:
            print("Option does not exist !")