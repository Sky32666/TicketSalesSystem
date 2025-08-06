#include <iostream>
using namespace std;

const int ROW = 15;
const int COL = 30;

const string ADMIN= "duck";
const string ADMIN_PASSWORD="quack";

const string MANAGER= "frog";
const string MANAGER_PASSWORD="ribbit";

const string CATEGORY[] = {"STANDARD", "VIP"};
const int PRICES[] = {10, 20};

int seatsAvailable[] = {120, 120};
int seat[ROW][COL] = {{0}};
int row, col;

struct QtySelection
{ 
  int selection;
  int qty;
  double price;
}qSel;

//function 1: display login menu 
int loginMenu()
{
  int optLogin;
  cout<<"-----------------------"<<endl;
  cout<<" WELCOME TO THE SYSTEM"<<endl;
  cout<<"-----------------------"<<endl;
  cout<<"\t"<<endl;
  cout<<"--------------------"<<endl;
  cout<<"\t\tMENU"<<endl;
  cout<<"--------------------"<<endl;
  cout<<"Code"<<"\t"<<"WORK"<<endl;
  cout<<"1"<<"\t\t"<<"ADMIN"<<endl;
  cout<<"2"<<"\t\t"<<"MANAGER"<<endl;
  cout<<"3"<<"\t\t"<<"EXIT"<<endl;

  cout<<"Choose your option:"<<endl;
  cin>>optLogin;

  while(optLogin<1 || optLogin>3)  
    {
      cout<<"Invalid option!"<<endl
          <<"Try again:"<<endl;
      cin>>optLogin;
    }
  
  return optLogin;
}

//function 2: display admin menu 
int adminMenu()
{
  int optAdmin;
  
  cout<<"WELCOME ADMIN. HOW CAN I HELP YOU?"<<endl;
  cout<<"\t\tADMIN MENU"<<endl;
  cout<<"--------------------"<<endl;
  cout<<"CODE"<<"\t"<<"WORK"<<endl;
  cout<<"1"<<"\t\t"<<"DISPLAY SEAT"<<endl;
  cout<<"2"<<"\t\t"<<"BOOK SEATS"<<endl;
  cout<<"3"<<"\t\t"<<"SALES REPORT"<<endl;
  cout<<"4"<<"\t\t"<<"BACK TO LOGIN"<<endl;

  cout<<"Choose your option:"<<endl;
  cin>>optAdmin;

  while(optAdmin<1 || optAdmin>4)
    {
      cout<<"Invalid option!"<<endl
          <<"Try again"<<endl;
      cin>>optAdmin;
    }

  return optAdmin;
}

//function 3: display manager menu
int managerMenu()
{
  int optManager;
  
  cout<<"WELCOME MANAGER.HOW CAN I HELP YOU?"<<endl;
  cout<<"\t\tMANAGER MENU"<<endl;
  cout<<"--------------------"<<endl;
  cout<<"CODE"<<"\t"<<"WORK"<<endl;
  cout<<"1"<<"\t\t"<<"DISPLAY SEAT"<<endl;
  cout<<"2"<<"\t\t"<<"SALES REPORT"<<endl;
  cout<<"3"<<"\t\t"<<"BACK TO LOGIN"<<endl;

  cout<<"Choose your option:"<<endl;
  cin>>optManager;

  while(optManager<1 || optManager>3)
    {
      cout<<"Invalid option!"<<endl
          <<"Try again!"<<endl;
      cin>>optManager;
    }
  
  return optManager;
}

//function 4: checking for Admin
int checkAdmin()
{
  string username, password;
  int counter;
  bool valid_username=true;
  bool valid_password=true;
  
  counter=3;//chances for username
  do
  {
      cout<<"Enter username"<<endl;
      cin>>username;
      if(username==ADMIN)
      {
          counter=3;//chances for password
          do
          {
              cout<<"Enter password"<<endl;
              cin>>password;
              if(password==ADMIN_PASSWORD)
              {
                  cout<<"You have successfully logged in"<<endl;
                  valid_password=false;
                  valid_username=false;
                  return 1;
              }
              else
              {
                  if(counter==1)
                  {
                    cout<<"You have no tries left, invalid password"<<endl;
                    valid_password=false;
                    valid_username=false;
                    return 0;
                  }
                  else
                  {
                  counter=counter - 1; //tries deducted
                  cout<<"\nWrong password"<<endl;
                  cout<<"Try again\n"<<endl;
                  }
              }
          }while(valid_password);
      }
      else
      {
          if(counter==1)
          {
            cout<<"You have no tries left, invalid username"<<endl;
            valid_username=false;
            return 0;
          }
          else
          {
            counter=counter - 1; //tries deducted
            cout<<"\nWrong username"<<endl;
            cout<<"Try again\n"<<endl;
          }
      }
  }while(valid_username);
  return 0;
}


//function 5: checking for Manager
int checkManager()
{
  string username, password;
  int counter;
  bool valid_username=true;
  bool valid_password=true;

  counter=3;
  do
  {
      cout<<"Enter username"<<endl;
      cin>>username;
      if(username==MANAGER)
      {
          counter=3;
          do
          {
              cout<<"Enter password"<<endl;
              cin>>password;
              if(password==MANAGER_PASSWORD)
              {
                  cout<<"You have successfully logged in"<<endl;
                  valid_password=false;
                  valid_username=false;
                  return 2;
              }
              else
              {
                  if(counter==1)
                  {
                    cout<<"You have no tries left, invalid password"<<endl;
                    valid_password=false;
                    valid_username=false;
                    return 0;
                  }
                  else
                  {
                    counter=counter - 1; //tries deducted
                    cout<<"\nWrong password"<<endl;
                    cout<<"Try again\n"<<endl;
                  }
              }
          }while(valid_password);
      }
      else
      {
          if(counter==1)
          {
            cout<<"You have no tries left, invalid username"<<endl;
            valid_username=false;
            return 0;
          }
          else
          {
            counter=counter - 1; //tries deducted
            cout<<"\nWrong username"<<endl;
            cout<<"Try again\n"<<endl;
          }
      }
  }while(valid_username);
  return 0;
}

//function 6: displaying seats 
void displaySeat(int seat[ROW][COL])
{
  cout<<"\t\t\t\t\t----------------------------------------------------------------------------------\t\t\t\t\t"<<endl;
  cout<<"\t\t\t\t\t|                                      STAGE                                     |\t\t\t\t\t"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------------------------------------------\t\t\t\t\t"<<endl;
  cout<<"VIP"<<endl;
  for (int i = 0; i < 7; i++)
  {
    cout<<"row #"<<i+1<<"\t";
    for (int j = 0; j < COL; j++)
    {
      cout << seat[i][j] << "\t";
    }
    cout << endl;
  }
  cout<<"STANDARD"<<endl;
  for (int i = 7; i < ROW; i++)
  {
    cout<<"row #"<<i+1<<"\t";
    for (int j = 0; j < COL; j++)
    {
      cout << seat[i][j] << "\t";
    }
    cout << endl;
  }
}

//function 7: display standard prices
void displayPriceList()
{
  cout << "Price List:" << endl;
  for (int i = 0; i < 2; i++)
  {
    cout << i + 1 << " " << CATEGORY[i] << " - RM" << PRICES[i] << " (" << seatsAvailable[i] << " seats available)" << endl;
  }
}

//function 8: selecting from VIP and Standard
void selectVIP()
{
  do
  {
    cout << "Choose the row (row 1 - row 7): ";
    cin >> row;
    if (row > 0 && row <= 7)
    {
      cout << "Choose the seat (seat 1 - seat 30): ";
      cin >> col;
      if (col > 0 && col <= COL)
      {
        if (seat[row - 1][col - 1] == 0) // Check whether the seat is available
        {
          seat[row - 1][col - 1] = 1;
          seatsAvailable[1]--; // Update VIP seats available
          break;
        }
        else
        {
          cout << "Seat is already occupied. Please select another seat." << endl;
        }  
     }
     else
     {
        cout << "Invalid seat. Please try again." << endl;
     }
   }
   else
   {
      cout << "Invalid row. Please try again." << endl;
   }
  }while(true);
}

void selectStandard()
{
  do
  {
    cout << "Choose the row (row 8 - row 15): ";
    cin >> row;
    if (row > 7 && row <= ROW)
    {
      cout << "Choose the seat (seat 1 - seat 30): ";
      cin >> col;
      
      if (col > 0 && col <= COL)
      {
        if (seat[row - 1][col - 1] == 0) // Check whether the seat is available
        {
          seat[row - 1][col - 1] = 1;
          seatsAvailable[0]--; // Update STANDARD seats available
          break;
        }
        else
        {
          cout << "Seat is already occupied. Please select another seat." << endl;
        }
      }
      else
      {
        cout << "Invalid seat. Please try again." << endl;
      }
    }
    else
    {
      cout << "Invalid row. Please try again." << endl;
    }
  }while (true);
}


//function 9: quantity 
void selectQty()
{
    do 
    {
        int choice;
        cout << "Choose a seat category (1 for Standard seat, 2 for VIP Seat): ";
        cin >> choice;
        qSel.selection = choice -1;
        if (qSel.selection == 0 || qSel.selection == 1)
        {
            cout << "Enter quantity: ";
            cin >> qSel.qty;
            if (qSel.qty > 0)
            {
                cout << "Chosen seat from " << CATEGORY[qSel.selection] << endl;
                cout << "Price per seat: RM " << PRICES[qSel.selection] << endl;
                qSel.price = PRICES[qSel.selection] * qSel.qty;
                break;         
            }
            else
            {
                cout << "Incorrect quantity. Please try again." << endl;   
            }
  }
  else
  {
    cout << "Incorrect selection. Please try again." << endl;
  }
    }while (true);
}


int main() 
{
  int optionLogin;
  bool flag;
  int status;
 
  int optionAdmin, optionManager;
  int totalQuantity =0;
  int soldSeats;

  double totalPrice =0.00;

  do
  {
      optionLogin = loginMenu();
      do
        {
          switch(optionLogin)
          {
            case 1: status=checkAdmin();flag = false;break;
            case 2: status=checkManager();flag = false;break;
            //case 3: cout<<"End of System"<<endl; return 0; break; //do we need to use return 0??????
            default: cout<<"End of System"<<endl;return 0;
            //default: cout<<"Error."<<endl;
          }
        }while(flag);
    
    if(status==1)
    { 
        do
        {
          optionAdmin = adminMenu();
          switch(optionAdmin)
          {
            case 1:
            displayPriceList(); //Display price list 
            cout<<"\nSeat Maps:"<<endl;
            displaySeat(seat); // Display initial seat status
            break;
            
            case 2:
            selectQty(); //select seat and quantity (qSel got values)
            totalQuantity += qSel.qty; // Update total quantity
            totalPrice += qSel.price; // Update total price
      
            // Selecting VIP/Standard
            if (qSel.selection == 0)
             {
               for (int i = 0; i < qSel.qty; i++)
                {
                  selectStandard();
                }
              }
              else
              if (qSel.selection == 1)
              {
                for (int i = 0; i < qSel.qty; i++)
                {
                   selectVIP();
                }
              }
            
            displaySeat(seat); // Display updated seat status after seat selection
              
            break;
            
            case 3:
            // //display sales report - total quantity and price
            soldSeats  = qSel.qty;
            cout<<"\tSales Report"<<endl
                << "Remaining Seats: " << seatsAvailable[0] << " Standard seats & " << seatsAvailable[1] << " VIP seats" << endl
               <<"Total Quantity:"<<totalQuantity<<endl
               <<"Total Earned:RM "<<totalPrice<<endl;break;
      
            default:
            //optionAdmin = 4 (why without this still can exit loop?)
            flag = true; 
          }
        }while(optionAdmin!=4);
    }
    else//408
    {
      if(status==2)
      {
        do 
          {
            optionManager = managerMenu();
            switch(optionManager)
              {
                case 1:
                displayPriceList(); //Display price list 
                cout<<"\nSeat Maps:"<<endl;
                displaySeat(seat); // Display initial seat status
                break;
          
                case 2:
                // //display sales report - total quantity and price
                soldSeats  = qSel.qty;
                cout<<"\tSales Report"<<endl;
                cout<<"Remaining Seats:"<<420 - soldSeats<<"/420"<<endl;
                cout<<"Total Quantity:"<<totalQuantity<<endl;
                cout<<"Total Earned:RM "<<totalPrice<<endl;
                break;
          
                default:
                flag=true;//go back login menu
                //default:cout<<"Error. Try Again"<<endl;
              }
          }while(optionManager != 3); 
      }
      else
      {
        //status =0;
        optionLogin = 3;
      }
    }
  }while(optionLogin!=3 || flag);
}
