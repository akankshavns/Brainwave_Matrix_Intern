#include<iostream>
using namespace std;

class ATM{
   int pin, EnteredPin;
   double TotalBalance = 10000.67;
   public: void setPin(){
      cout<<"Please Enter your Card Pin\t";
      cin>>pin;
      cout<<"\nYour pin created successfully!";
   }
   public: void changePin(){
      int NewPin;
      cout<<"Enter your pin to reset\t";
      cin>>NewPin;
      pin = NewPin;
      cout<<"Pin changed successfully!";
   }
   public: void withdrawMoney(){
      int Amount;
      cout<<"Enter your 4 digit pin numbr";
      cin>>EnteredPin;
      if(EnteredPin == pin){
         cout << "Enter amount to withdraw: ";
         cin >> Amount;
         TotalBalance -=Amount;
         cout << "\nWithdrawal successful! Your new balance: " << TotalBalance << endl;
      }
      else{
         cout<<"Incorrect PIN! Access denied, Please Enter the correct PIN";
      }
   }
   public: void TransferMoney(double depositAmount){
      cout<<"Enter your 4 digit pin number";
      cin>>EnteredPin;
      if(EnteredPin == pin){
         TotalBalance += depositAmount;
         cout << "\nBalancr credited successful! Your new balance: " << TotalBalance << endl;
      }
      else{
         cout<<"Incorrect PIN! Access denied, Please Enter the correct PIN";
      }
       
   }
   public: void BalanceEnquiry(){
      cout<<"Enter your 4 digit pin numbr";
      cin>>EnteredPin;
      if(EnteredPin == pin){
         cout<<"Your Total Balance is : "<<TotalBalance << endl;
      }
      else
      {
         cout<<"Incorrect PIN! Access denied, Please Enter the correct PIN";
      }
      
   }

};



int main(){
   int option;
   ATM obj;
   do{
      cout<<"\nChoose Your Option\n";
      cout<<"1. Set the pin.\n";
      cout<<"2. Change the pin.\n";
      cout<<"3. Withdraw money.\n";
      cout<<"4. Transfer money.\n";
      cout<<"5. Check Balance.\n";
      cout<<"6. Exit.\n";
      cout<<"Enter your option";
      cin>>option;
      
      switch (option)
      {
         case 1:
            obj.setPin();
            break;
         case 2:
            obj.changePin();
            break;
         case 3:
            obj.withdrawMoney();
            break;
         case 4:
            double DepositAmount;
            cout<<"Enter the amount for deposit";
            cin>>DepositAmount;
            obj.TransferMoney(DepositAmount);
            break;
         case 5:
            obj.BalanceEnquiry();
            break;
         case 6:
            cout<<"Thank you for using the ATM. Goodbye!\n";
            break;
         default:
            cout<<"Invalid Option! please choose correct option";
            break;
      }
   }while (option != 6);
   return 0;
}