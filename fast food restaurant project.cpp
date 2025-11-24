#include <iostream>
#include <string>
#include <sstream>
#define size 5
using namespace std; 
string str;
float total;
bool flag=true;   
struct menu 
{
	string name; 
	float price; 
};
void print_list();
string input_order();
void checkout();
int main() 
{
	int choice,index; 
	string add_to_summary; 
	while(flag) 
	{
		cout<<"Fast food resturant system "<<endl; 
		cout<<"1. Show menu "<<endl; 
		cout<<"2. Order a meal "<<endl; 
		cout<<"3. Exit "<<endl; 
		cout<<"4. Checkout "<<endl;
		cout<<"5. Clear order "<<endl; 
		cout<<"Enter your choice: "; 
		cin>>choice; 
		switch(choice) 
		{
			case 1: 
			print_list();
			break;  
			case 2: 
			add_to_summary = input_order();
			break; 
			case 3: 
			if(str.empty()==0) 
			{
				cout<<"You cannot leave while you have items in your cart "<<endl; 
			}
			else 
			{
				cout<<"Thanks for visiting goodbye "<<endl; 
				flag = false; 
			}
			break;
			case 4:
			checkout(); 
			break;
			case 5: 
			if(str.empty()) 
			{
				cout<<"Your order is empty "<<endl; 
			}
			else 
			{
				total = 0;
				str.clear();
				cout<<"Items cleared from your order "<<endl;  
			}
			break; 
			default: 
			cout<<"Wrong input "<<endl; 	
		}	
	}
	return 0;
}

void print_list() 
{
	menu list[] = {{"Burger",3.5},{"Pizza",4},{"Taco",2.5},{"Drink",1},{"French Fries",3}};
	cout<<"----Restaurant menu----"<<endl; 
	for(int i = 0 ; i<size ; i++)  
	{
		cout<<list[i].name<<" "<<"$"<<list[i].price<<endl; 
	}
}

string input_order()  
{
	string product;
	stringstream s; 
	menu list[] = {{"Burger",3.5},{"Pizza",4},{"Taco",2.5},{"Drink",1},{"French Fries",3}}; 
	cout<<"Write your meal's name: ";
	cin.ignore();
	getline(cin , product);
	for(int j=0 ; j<size ; j++) 
	{
		if(product==list[j].name)
		{
			cout<<"Added "<<list[j].name<<" to your order "<<endl;
			total += list[j].price;
			s<<list[j].price;
			str += list[j].name+" "+"$"+s.str()+"\n";
			return str;
		}
	} 
	cout<<"Wrong input "<<endl;
	return str;
}

void checkout() 
{
	char checkout; 
	if(str.empty()) 
	{
		cout<<"Your order is empty"<<endl; 
	}
	else 
	{
		cout<<"Your order "<<endl; 
		cout<<str; 
		cout<<"Total "<<"$"<<total<<endl; 
		cout<<"To checkout press Y "<<endl; 
		cin>>checkout;
		switch(checkout)  
		{
			default: 
			break; 
			case 'Y': 
			cout<<"Amount paid successfully "<<endl; 
			cout<<"Thank you "; 
			flag = false;
			break;  		
		}
    }
}
