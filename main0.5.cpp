#include <iostream>
using namespace std;

const int maxstock = 10;
int menuop = 0,stockmenu = 0,control = 0;

string stock[maxstock];
int amount_stock[maxstock],price_stock[maxstock],sold_stock[maxstock],re_stock[maxstock],income_stock[maxstock];
int income = 0;

void showstock()
{
  cout << "        - stock -        " << endl;
  for(int i = 0; i < maxstock; i++)
    {
      cout << i+1 << "." << stock[i] << "  amount: " << amount_stock[i] << "  price: " << price_stock[i] << endl;
    }
  cout << "--------------------------" << endl;
}

void option_select()
{
  cout << "-------------------------------" << endl;
  cout << "Please select an option : ";
}

void restock()
{
  int nrestock = 0;
  while(control == 12)
    {
      showstock();
      stockmenu = 0;
      cout << "Select Stock to restock (0 to exit) : ";
      cin >> stockmenu;

      if(stockmenu == 0)
      {
        cout << endl;
        stockmenu = 0;
        control = 1;
      }
      else
      {
        stockmenu -= 1;
        if(stockmenu > maxstock)
      {
        cout << "\n*erorr your stock dose not exit please type agian*" << endl;
      }
      else
      {
        if(stockmenu <= maxstock  && stock[stockmenu] == "")
        {
          cout << "\n*Please setup stock first*" << endl;
        }
        else
        {
          cout << "Amount to restock : ";
          cin >> nrestock;

          amount_stock[stockmenu] = amount_stock[stockmenu] + nrestock;
          re_stock[stockmenu] += nrestock;
          
            nrestock = 0;
        }
      }
      }

    }

}

void change_price()
{
  while(control == 12)
  {
    
    cout << "Select Stock to change price (0 to exit) : ";
    cin >> stockmenu;
    if(stockmenu == 0)
    {
      control = 1;
    }
    else
    {
      if(stockmenu > maxstock)
    {
      cout << "\n*erorr your stock dose not exit please type agian*" << endl;
    }
    else
    {
      stockmenu -= 1;
      if(stock[stockmenu] == "")
      {
        cout << "\n*Please setup stock first*" << endl;
      }
      else
      {
        cout << "New Price : ";
        cin >> price_stock[stockmenu];
        cout << endl;
        control = 1;
      }
    }
    }
    
  }
}

void change_name()
{
  while(control == 13)
    {

      cout << "Select Stock to change name (0 to exit) : ";
      cin >> stockmenu;
      if(stockmenu == 0)
      {
        control = 1;
      }
      else
      {
        if(stockmenu > maxstock)
      {
        cout << "\n*erorr your stock dose not exit please type agian*" << endl;
      }
      else
      {
        stockmenu -= 1;
        if(stock[stockmenu] == "")
        {
          cout << "\n*Please setup stock first*" << endl;
        }
        else
        {
          cout << "New Name : ";
          cin >> stock[stockmenu];
          cout << endl;
          control = 1;
        }
      }
      }

    }
}

void SetupStock()
{
  while (control == 1)
    {
      showstock();
      cout << "    #- stock manage -#    " << endl;
      cout << "1.Setup Stock" << endl;
      cout << "2.Restock" << endl;
      cout << "3.Change price" << endl;
      cout << "4.Change name" << endl;
      cout << "*****************" << endl;
      cout << "5.Exit" << endl;
      option_select();

      cin >> menuop;
  
      switch(menuop)
      {
        case 1:
          cout << "----------------------" << endl;
          cout << "Select Stock to set  : ";
          cin >> stockmenu;
          if (stockmenu > maxstock)
          {
            cout << "\n*erorr your stock dose not exit please type agian*" << endl;
          }
          else
          {
            stockmenu = stockmenu-1;

            if(re_stock[stockmenu] == 0)
            {
              cout << "Set a name : ";
              cin >> stock[stockmenu];

              cout << "Set a amount : ";
              cin >> amount_stock[stockmenu];

              re_stock[stockmenu] += amount_stock[stockmenu];

              cout << "Set a price : ";
              cin >> price_stock[stockmenu];

              stockmenu = 0;
              cout << endl;
              break;
            }
            else
            {
              cout << "\nyour stock already set please restock or change price or change name" << endl;
            }
          }
        
        case 2:
          menuop = 0;
          control = 12;
          cout << endl;
          restock();
          break;

        case 3:
          menuop = 0;
          control = 12;
          cout << endl;
          change_price();
          break;

        case 4:
          menuop = 0;
          control = 13;
          cout << endl;
          change_name();
          break;
        
        case 5:
          control = 0;
          cout << endl;
          
          break;
        
        default:
          cout << "erorr" << endl;
          break;
      }
    }
}

void selling()
{
  while(control == 2)
    {
      showstock();

      int amount_sell = 0;
      cout << "Select Stock to sell (0 to exit) : ";
      cin >> stockmenu;

      switch(stockmenu)
        {
          case 0:
            stockmenu = 0;
            control = 0;
            cout << endl;
            break;

          default:
            if(stockmenu <= maxstock && amount_stock[stockmenu-1] != 0)
            {
              stockmenu = stockmenu - 1;
      
              cout << "Amount to sell : ";
              cin >> amount_sell;

              if(amount_sell > amount_stock[stockmenu])
              {
                cout << "Stock is not enough";
                stockmenu = 0;
              }
              else
              {
                amount_stock[stockmenu] = amount_stock[stockmenu] - amount_sell;
        
                cout << "\nincome from this sell : " << (amount_sell * price_stock[stockmenu]) << endl;
                income = income + (amount_sell * price_stock[stockmenu]);
              
                sold_stock[stockmenu] += amount_sell;
                income_stock[stockmenu] += (amount_sell * price_stock[stockmenu]);
                cout << endl;
              
                stockmenu = 0;
              }
              
              
            }
            else
            {
              if(amount_stock[stockmenu-1] == 0)
              {
                cout << "\n*out of stock*" << endl;
                stockmenu = 0;
              }
              else
              {
                cout << "\n*erorr your stock dose not exit please type agian*" << endl;
                stockmenu = 0;
              }
            }
  }    }  
}

void income_report()
{
  string exit_key;
  for(int i = 0; i < maxstock; i++)
    {
      cout << stock[i] << "  Sold : " << sold_stock[i] << "  restocked : " << re_stock[i] << "  income : " << income_stock[i] << endl;
    }
  cout << "\noverall in come : " << income;
  cout << endl;
  cout << "type anything To exit : ";
  cin >> exit_key;
}

void menu()
{
  while(control == 0)
    {
      //ตัวเลือก
      cout << "--T's Shop Test--" << endl;
      cout << "     -Menu-       " << endl;
      cout << "1.Setup stock" << endl;
      cout << "2.Selling" << endl;
      cout << "3.income report" << endl;;
      cout << "0.Exit" << endl;
      option_select();
      cin >> menuop;
      switch(menuop)
      {
        case 0:
        cout << "Exit..." << endl;
        control = -1;
        break;
        
        case 1:
          menuop = 0;
          control = 1;
          cout << endl;
          SetupStock();
          break;

        case 2:
          menuop = 0;
          control = 2;
          cout << endl;
          selling();
          break;

        case 3:
        menuop = 0;
        cout << endl;
        income_report();
        break;

        default:
          menuop = 0;
          cout << "erorr" << endl;
          break;
      }  
    }
  
}

void lockpick()
{
  string key = "password.json";

  if(key != "seted_key.json")
  {
   control = 0;
   menuop = 99;
   stockmenu = 99;
  }
  else
  {
   control = 1;
   key = "passed";
  }
}

int main() 
{ 
  lockpick()
  menu();
  return 0;
}
  