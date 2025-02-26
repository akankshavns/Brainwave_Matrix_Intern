# Brainwave Matrix Intern  
#### This project is a `console-based` ATM interface developed in C++ as part of my internship at `Brainwave Matrix Solution`. It simulates basic ATM functionalities such as user authentication, balance inquiry, cash withdrawal, deposit, and change PIN.  
This function is used in the code to allow the user to set their ATM card PIN.
``` 
 public: void createPin(){
      cout<<"Please Enter your Card Pin\t";
      cin>>pin;
      if(pin >= 1000 && pin <= 9999){cout<<"\nYour pIN created successfully\n";
      }else{
         cout<<"\nPlease enter four digit PIN\n";
      }
      
   }
   ```  
   This function is used in the code to allow the user to reset or change their ATM card PIN.
``` 
  public: void changePin(){
      int NewPin,OldPin;
      cout<<"Enter your old PIN: ";
      cin>>OldPin;
      if(pin == OldPin){
         cout<<"Enter your PIN to reset: ";
         cin>>NewPin;
         if(NewPin >= 1000 && NewPin <= 9999){
            pin = NewPin;
            cout<<"\nPIN changed successfully!n";
         }else{
            cout<<"\nPlease enter four digit PIN\n";
         }
      }else{
         cout<<"\nIncorrect PIN! Please enter the correct old PIN for Reset the PIN\n";
      }
   }
   ```  
   This function is used in the code to allow the user to withdraw money.
``` 
 public: void withdrawMoney(){
      int Amount;
      cout<<"Enter your 4 digit pin number: ";
      cin>>EnteredPin;
      if(EnteredPin == pin){
         cout << "Enter amount to withdraw: ";
         cin >> Amount;
         if(TotalBalance > 0 && TotalBalance >= Amount ){
            TotalBalance -=Amount;
            cout << "\nWithdrawal successful! Your new balance: " << TotalBalance << endl;
         }else{
            cout<<"You do not have sufficient balance to withdraw the money.";
         }
      }
      else{
         cout<<"\nIncorrect PIN! Access denied, Please Enter the correct PIN\n";
      }
   }

``` 
This function is used in the code to allow the user to deposit money.
 ```
 public: void depositMoney(double depositAmount){
      cout<<"Enter your 4 digit pin number: ";
      cin>>EnteredPin;
      if(EnteredPin == pin){
         TotalBalance += depositAmount;
         cout << "\nBalance credited successful! Your new balance: " << TotalBalance << endl;
      }
      else{
         cout<<"\nIncorrect PIN! Access denied, Please Enter the correct PIN\n";
      }
       
   }
   ```
   This function is used in the code to allow the user fto check their balance.
``` 
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
   ```
   
 

