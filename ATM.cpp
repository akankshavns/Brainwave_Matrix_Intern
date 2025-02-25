#include<iostream>
using namespace std;

class ATM {
   int pin, EnteredPin;
   double TotalBalance = 500.67;

   public: void createPin(){
      cout<<"Please Enter your Card Pin\t";
      cin>>pin;
      if(pin >= 1000 && pin <= 9999){cout<<"\nYour pin created successfully\n";
      }else{
         cout<<"\nPlease enter four digit PIN\n";
      }
      
   }

   public: void changePin(){
      int NewPin,OldPin;
      cout<<"Enter your PIN";
      cin>>OldPin;
      if(pin == OldPin){
         cout<<"Enter your pin to reset\t";
         cin>>NewPin;
         pin = NewPin;
         cout<<"\nPin changed successfully!n";
      }else{
         cout<<"\nIncorrect PIN! Please enter the correct PIN for Reset the PIN\n";
      }
   }

   public: void withdrawMoney(){
      int Amount;
      cout<<"Enter your 4 digit pin number";
      cin>>EnteredPin;
      if(EnteredPin == pin){
         cout << "Enter amount to withdraw: ";
         cin >> Amount;
         if(TotalBalance > 0 && TotalBalance >= Amount ){
            TotalBalance -=Amount;
            cout << "\nWithdrawal successful! Your new balance: " << TotalBalance << endl;
         }
      }
      else{
         cout<<"\nIncorrect PIN! Access denied, Please Enter the correct PIN\n";
      }
   }

   public: void depositMoney(double depositAmount){
      cout<<"Enter your 4 digit pin number";
      cin>>EnteredPin;
      if(EnteredPin == pin){
         TotalBalance += depositAmount;
         cout << "\nBalancr credited successful! Your new balance: " << TotalBalance << endl;
      }
      else{
         cout<<"\nIncorrect PIN! Access denied, Please Enter the correct PIN\n";
      }
       
   }
 
   public: void BalanceEnquiry(){
      cout<<"Enter your 4 digit pin numbr";
      cin>>EnteredPin;
      if(EnteredPin == pin){
         cout<<"\nYour Total Balance is : "<<TotalBalance << endl;
      }
      else
      {
         cout<<"\nIncorrect PIN! Access denied, Please Enter the correct PIN\n";
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
      cout<<"4. Deposit Money.\n";
      cout<<"6. Check Balance.\n";
      cout<<"7. Exit.\n";
      cout<<"Enter your option: ";
      cin>>option;
      
      switch (option)
      {
         case 1:
            obj.createPin();
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
            obj.depositMoney(DepositAmount);
            break;
         case 5:
            obj.BalanceEnquiry();
            break;
         case 6:
            cout<<"\nThank you for using the ATM. Goodbye!\n";
            break;
         default:
            cout<<"\nInvalid Option! please choose correct option\n";
            break;
      }
   }while (option != 6);
   return 0;
}