#include <bits/stdc++.h>
#include<windows.h>
#include<time.h>
using namespace std;
#define V 20
vector<string> name;
vector <string> address;
vector <int> availaibility;
vector <int> reviews;
vector <int> sector,hotelid;
vector <double> price;
vector <string> room_type;
vector<char>havailaible;
string customer_name;
void hotel_book();
void customer_menu();
map<int,int>d;
void book();
void homePage();
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
void sector_sort(map<int, int>& M)
{
    multimap<int,int> MM;
    for (auto& it : M) {
        MM.insert({ it.second, it.first });
    }
    ifstream addresses,prices,sectors,names,avail,rev,r_type,customers,hid,havail;
    string stAdd,stname,stroom,stCustomer;
    int stsectors,stav,strat,stid;
    double stprice;
    char stavail;
    addresses.open("address.txt");
    names.open("name.txt");
    prices.open("price.txt");
    sectors.open("sectors.txt");
    avail.open("availability.txt");
    rev.open("rating.txt");
    r_type.open("room.txt");
    customers.open("customers.txt");
    hid.open("id.txt");
    havail.open("available.txt");
    while (sectors.eof()==0)
    {
        getline(addresses,stAdd);
        address.push_back(stAdd);
        prices>>stprice;
        price.push_back(stprice);
        getline(names,stname);
        name.push_back(stname);
        sectors>>stsectors;
        sector.push_back(stsectors);
        avail>>stav;
        availaibility.push_back(stav);
        rev>>strat;
        reviews.push_back(strat);
        getline(r_type,stroom);
        room_type.push_back(stroom);
        hid>>stid;
        hotelid.push_back(stid);
        havail>>stavail;
        havailaible.push_back(stavail);

    }
    int k=0,i;
    cout<<"=============================================================================================================================================================================================\n";
    cout<<setw(5)<<"Hid"<<setw(15)<<"Name"<<setw(45)<<"Price"<<setw(30)<<"location"<<setw(30)<<"Room Type"<<setw(30)<<"Available For"<<setw(25)<<"Number of +ve Reviews\n";
   cout<<"=============================================================================================================================================================================================\n";
       for (auto& it : MM) {
            for(i=0;i<sector.size();i++)
            {
                if(k==10)
            break;
                if(sector[i]==it.second+50&&havailaible[i]=='Y')
                {k++;


    cout<<setw(5)<<hotelid[i]<<"\t"<<name[i]<<setw(60-name[i].length())<<price[i]<<setw(30)<<sector[i]<<setw(30)<<room_type[i]<<setw(25)<<availaibility[i]<<setw(20)<<reviews[i]<<endl;
    cout<<"=============================================================================================================================================================================================\n";


                }
            }
    }
    cout<<"\t\t\t\n Press 1 for more hotels and 0 to continue booking: ";
    int option;
    cin>>option;
    switch(option)
    {
        case 0:hotel_book();
        break;
        case 1: k=0;
              cout<<"=============================================================================================================================================================================================\n";
    cout<<setw(5)<<"Hid"<<setw(15)<<"Name"<<setw(45)<<"Price"<<setw(30)<<"location"<<setw(30)<<"Room Type"<<setw(30)<<"Available For"<<setw(25)<<"Number of +ve Reviews\n";
   cout<<"=============================================================================================================================================================================================\n";
       for (auto& it : MM) {
            for(i=0;i<sector.size();i++)
            {
                if(k==15)
            break;

                if(sector[i]==it.second+50&&havailaible[i]=='Y')
                {k++;

if(k>10)
            {
                cout<<setw(5)<<hotelid[i]<<"\t"<<name[i]<<setw(60-name[i].length())<<price[i]<<setw(30)<<sector[i]<<setw(30)<<room_type[i]<<setw(25)<<availaibility[i]<<setw(20)<<reviews[i]<<endl;
    cout<<"=============================================================================================================================================================================================\n";
            }



                }
            }
    }
    hotel_book();
    break;
    default:cout<<"Wrong option selected ";
    homePage();
    break;

    }
}
void printSolution(int dist[])
{
    cout <<"Details of Hotel Availaible:" << endl;
    for (int i = 0; i < V; i++)
    {
        d[i]=dist[i];
    }
    sector_sort(d);
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}
int cust_id;
void adj_matrix(int sec)
{

    int graph[V][V] ;

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            graph[i][j]=abs(i-j);
        }
    }

    dijkstra(graph, sec-50);
}

int search_custId(){
    int cust_id;
    cout<<"\t\tEnter your customer Id : ";
    cin>>cust_id;
    int list;
    ifstream read,cust;
    read.open("cust_id.txt");
    cust.open("customers.txt");
    while(!read.eof()){
            string s;
        read>>list;
        getline(cust,s);
        if(list==cust_id){
            cout<<"\t\tCustomer Login Successful..!!!\n";
            cout<<"\t\tWELCOME "<<s<<"!!!!!!!!!!\n";
            customer_name=s;
            return cust_id;
        }
    }
    return -1;
}

int search_hotels(){
    int hotel_id;
    cout<<"\n\t\tSelect home Id for home you want to book : ";
    cin>>hotel_id;
    int list;
    ifstream read,names;
    read.open("id.txt");
    names.open("name.txt");
    while(!read.eof()){
            string s;
        read>>list;
    getline(names,s);
        if(list==hotel_id){
            cout<<"\n\t\tHome booked successfully...!!\n";
            cout<<"\n\t\tWelcome to "<<s<<"!!!!!!!!!!\n";
            return hotel_id;
        }
    }
    return -1;
}
int search_hotels_d(int id){
    int hotel_id;
    cout<<"\n\t\tEnter home Id for home you want to checkout : ";
    cin>>hotel_id;
    int list;
 ifstream read,names,verify,cust;
    read.open("id.txt");
    names.open("name.txt");
    while(!read.eof()){
            string s;
        read>>list;
    getline(names,s);
    int flag=1;
        if(list==hotel_id){
             verify.open("cust_hotel_id.txt");
             cust.open("cust_id.txt");
             while(!cust.eof())
             {
                 int id1,id2;
                 cust>>id1;
                 verify>>id2;
                 if(id1==id)
                 {
                     if(id2==hotel_id)
                     {
                         cout<<"\n\t\tHome checkout successfully...!!\n";
            return hotel_id;
                     }
                 }
             }
             if(flag)
             {
                 cout<<"\t\tHotel and customer allocation not matched......";
             }


        }
    }
    return -1;
}
void hotel_book()
{
    int hotel_id=search_hotels();
        char avail='N';
        ifstream available,allocate,customer;
        ofstream temp_available,temp_allocate;
        available.open("available.txt");
        allocate.open("cust_hotel_id.txt");
        customer.open("cust_id.txt");
        temp_available.open("temp_avail.txt");
        temp_allocate.open("tempallocate.txt");
        ifstream read;
        int id;
        char hav;
        read.open("id.txt");
        while(!read.eof()){
            read>>id;
            if(hotel_id==id){
                temp_available<<avail<<"\n";
            }
            else
            {
                available>>hav;
                temp_available<<hav<<"\n";

            }
        }
        while(!customer.eof())
        {
            int cid,hid;
            customer>>cid;
            allocate>>hid;
            if(cid==cust_id)
            {
               temp_allocate<<hotel_id<<"\n";
            }
            else
            {
                temp_allocate<<hid<<"\n";
            }
        }
        read.close();
        available.close();
        allocate.close();
        temp_allocate.close();
        temp_available.close();
        customer.close();
        remove("available.txt");
        rename("temp_avail.txt","available.txt");
        remove("cust_hotel_id.txt");
        rename("tempallocate.txt","cust_hotel_id.txt");

    Sleep(2500);
    system("cls");
        homePage();
}

void book()
{
    cout << "\n\n\n            \t";
    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    cout << "\n\t\t||\t\t   SEARCH HOTEL MENU\t\t\t||\n";
    cout << "            \t";

    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    //cout<<"\n\n\n\n\t\t\t\tWELCOME TO HOLIDAY HOME ACCOMODATION SYSTEM\n";
    cout<<"\n\n";
    cust_id=search_custId();
    Sleep(2000);
    system("cls");
    cout<<"\n \n \n             \tUser logged in :"<<customer_name;
    cout << "\n\n\n            \t";
    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    cout << "\n\t\t||\t\t   SEARCH HOTEL MENU\t\t\t||\n";
    cout << "            \t";

    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    //cout<<"\n\n\n\n\t\t\t\tWELCOME TO HOLIDAY HOME ACCOMODATION SYSTEM\n";
    cout<<"\n\n";
    cout<<"\t\tDo you wish to continue booking..(Y/N) : ";
    char choice;
    cin>>choice;
    if(choice=='y' || choice=='Y'){
        int sec;
    cout<<"\n\t\tEnter your location : ";
    cin>>sec;
    adj_matrix(sec);
     }
    else{

        cout<<"\n\n\n\t\tThank You .... Visit Again\n";

    }

}

void register_acc()
{
    cout << "\n\n\n            \t";
    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    cout << "\n\t\t||\t\t   ADD ACCOMODATION MENU\t      ||\n";
    cout << "            \t";

    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    //cout<<"\n\n\n\n\t\t\t\tWELCOME TO HOLIDAY HOME ACCOMODATION SYSTEM\n";
    cout<<"\n\n";
string Add,name,room;
int sector,av;
double price;
cout<<"\t\t\tEnter Name : ";
cin>>name;
cout<<"\t\t\tEnter Address : ";
cin>>Add;
cout<<"\t\t\tEnter Sector : ";
cin>>sector;
cout<<"\t\t\tEnter room type : ";
cin>>room;
cout<<"\t\t\tEnter price : ";
cin>>price;
cout<<"\t\t\tEnter availaible days : ";
cin>>av;
ofstream addresses,prices,sectors,names,avail,rev,r_type,customers,accomadate;
fstream hid;
addresses.open("address.txt",ios::app);
names.open("name.txt",ios::app);
prices.open("price.txt",ios::app);
sectors.open("sectors.txt",ios::app);
avail.open("availability.txt",ios::app);
rev.open("rating.txt",ios::app);
r_type.open("room.txt",ios::app);
customers.open("customers.txt",ios::app);
hid.open("id.txt");
accomadate.open("available.txt",ios::app);
int tid;
while(!hid.eof())
{
    hid>>tid;
}
names<<name<<"\n";
prices<<price<<"\n";
addresses<<Add<<"\n";
sectors<<sector<<"\n";
avail<<av<<"\n";
rev<<0<<"\n";
r_type<<room<<"\n";
hid.close();
hid.open("id.txt",ios::app);
hid<<tid+1<<"\n";
accomadate<<'Y'<<"\n";
addresses.close();
names.close();
prices.close();
sectors.close();
avail.close();
rev.close();
r_type.close();
customers.close();
hid.close();
accomadate.close();
cout<<"\n\n\t\t\tAccomadation Registration Successfull !!!\n";
cout<<"\t\t\tYour Registered Home id is : "<<tid+1;

Sleep(2500);
system("cls");
homePage();

}
void checkout()
{
    cout << "\n\n\n            \t";
    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    cout << "\n\t\t||\t\t\t CHECKOUT MENU\t\t\t||\n";
    cout << "            \t";

    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    //cout<<"\n\n\n\n\t\t\t\tWELCOME TO HOLIDAY HOME ACCOMODATION SYSTEM\n";
    cout<<"\n\n";
    int id=search_custId();
    if(id!=-1)
    {
        int id1=search_hotels_d(id);
        if(id1==-1)
        {
            Sleep(2000);
            system("cls");
            customer_menu();
        }
        char avail='Y';
        ifstream available,allocate;
        ofstream temp_available,temp_allocate;
        available.open("available.txt");
        temp_available.open("temp_avail.txt");
        allocate.open("cust_hotel_id.txt");
        temp_allocate.open("temp_all.txt");
        ifstream read;
        int id2;
        char hav;
        read.open("id.txt");
        while(!read.eof()){
            read>>id2;
            if(id1==id2){
                temp_available<<avail<<"\n";
            }
            else
            {
                available>>hav;
                temp_available<<hav<<"\n";

            }
        }
        read.close();
        available.close();
        temp_available.close();
        remove("available.txt");
        rename("temp_avail.txt","available.txt");
        int id3,id4;
        read.open("cust_id.txt");
        while(!read.eof()){
            read>>id3;
            allocate>>id4;
            if(id==id3){
                temp_allocate<<0<<"\n";
            }
            else
            {
                temp_allocate<<id4<<"\n";

            }
        }
        read.close();
        allocate.close();
        temp_allocate.close();
        remove("cust_hotel_id.txt");
        rename("temp_all.txt","cust_hotel_id.txt");

        char choice;
      cout<<"\t\tCheckout succesfull..!!\n";
      cout<<"\t\tDo you want to rate your accomadation ,press 'y' for yes : ";
      cin>>choice;
      if(choice=='y'||choice=='Y')
      {
          int fdbk;
          cout<<"\n\t\tFor positive feedback , press 1 ,else 0 : ";
          cin>>fdbk;
          cout<<"\n\t\tThank you for your rating...!!";
          if(fdbk)
          {
        ifstream rev;
        ofstream temp_rating;
        read.open("id.txt");
        rev.open("rating.txt");
        temp_rating.open("temp.txt");
        while(!read.eof())
        {
            int hId;
            read>>hId;
            int acc_rating;
            if(hId==id1){
                rev>>acc_rating;
                temp_rating<<acc_rating+1<<"\n";
            }
            else{
                rev>>acc_rating;
                temp_rating<<acc_rating<<"\n";
            }
        }
        read.close();
        rev.close();
        temp_rating.close();
        remove("rating.txt");
        rename("temp.txt","rating.txt");
          }
      }


    }

    Sleep(2500);
    system("cls");
    homePage();

}

int searchId(){
    int id;
    cout<<"\n\t\tEnter your seller Id : ";
    cin>>id;
    int list;
    ifstream read,names;
    read.open("id.txt");
    names.open("name.txt");
    while(!read.eof()){
            string s;
        read>>list;
        getline(names,s);
        if(list==id){
            cout<<"\n\t\tID Matched....Login In Successful..!!\n";
            cout<<"\n\t\tWELCOME "<<s<<"!!!!!!!!!!!!!!\n\n";
            return id;
        }
    }
    return -1;
}

void modify_details(){
    cout << "\n\n\n            \t";
    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    cout << "\n\t\t||\t\t   MODIFY DETAILS MENU\t\t\t||\n";
    cout << "            \t";

    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    //cout<<"\n\n\n\n\t\t\t\tWELCOME TO HOLIDAY HOME ACCOMODATION SYSTEM\n";
    cout<<"\n\n";
    int id=searchId();
    cout<<"\n\t\tDo You Want to Modify Details (Y/N) : ";
    char choice;
    cin>>choice;
    if(choice=='y' || choice=='Y'){

        cout<<"\n\n\t\tEnter your new details\n\n";
        string Add,name,room;
int sector,av;
double price;
cout<<"\t\tEnter Name : ";
cin>>name;
cout<<"\n\t\tEnter Address : ";
cin>>Add;
cout<<"\n\t\tEnter Sector : ";
cin>>sector;
cout<<"\n\t\tEnter room type : ";
cin>>room;
cout<<"\n\t\tEnter price : ";
cin>>price;
cout<<"\n\t\tEnter availaible days : ";
cin>>av;
ifstream addresses,prices,sectors,names,avail,r_type;

    ofstream temp_name,temp_address,temp_price,temp_sector,temp_avail,temp_rtype;
    addresses.open("address.txt");
    names.open("name.txt");
    prices.open("price.txt");
    sectors.open("sectors.txt");
    avail.open("availability.txt");
    r_type.open("room.txt");
        temp_name.open("tempname.txt");
        temp_address.open("tempaddress.txt");
        temp_price.open("tempprice.txt");
        temp_sector.open("tempSectors.txt");
        temp_avail.open("tempavail.txt");
        temp_rtype.open("tempr_type.txt");
        ifstream read;
        read.open("id.txt");
        while(!read.eof()){
            int customerId;
            read>>customerId;
            string acc_name,acc_add,acc_room;
            double acc_price;
            int acc_sector,acc_av;
            avail>>acc_av;
             prices>>acc_price;
             sectors>>acc_sector;
            getline(names,acc_name);
            getline(addresses,acc_add);
            getline(r_type,acc_room);
            if(customerId==id){
                temp_price<<price<<"\n";
                temp_sector<<sector<<"\n";
                temp_avail<<av<<"\n";
                temp_name<<name<<"\n";
                temp_address<<Add<<"\n";
                temp_rtype<<room<<"\n";
            }
            else{
                temp_price<<acc_price<<"\n";
                temp_sector<<acc_sector<<"\n";
                temp_avail<<acc_av<<"\n";
                temp_name<<acc_name<<"\n";
                temp_address<<acc_add<<"\n";
                temp_rtype<<acc_room<<"\n";
            }
        }

        read.close();
        names.close();
        addresses.close();
        prices.close();
        sectors.close();
        avail.close();
        r_type.close();
        temp_name.close();
        temp_address.close();
        temp_price.close();
        temp_sector.close();
        temp_avail.close();
        temp_rtype.close();
        remove("name.txt");
        remove("address.txt");
        remove("availability.txt");
        remove("price.txt");
        remove("room.txt");
        remove("sectors.txt");
        rename("tempname.txt","name.txt");
        rename("tempaddress.txt","address.txt");
        rename("tempprice.txt","price.txt");
        rename("tempSectors.txt","sectors.txt");
        rename("tempavail.txt","availability.txt");
        rename("tempr_type.txt","room.txt");
        cout<<"\n\t\tData modified successfully..!!\n";
    }
    else{
        cout<<"\n\t\tData not modified\n";
    }

    Sleep(2500);
    system("cls");
    homePage();

}
void seller_menu(){
    cout << "\n\n\n            \t";
    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    cout << "\n\t\t||\t      \t     SELLER MENU\t\t\t||\n";
    cout << "            \t";

    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    //cout<<"\n\n\n\n\t\t\t\t\t\t\tSELLER MENU\n";
    cout<<"\n\n";
    cout<<"\t\t\t\t-> 1) ADD ACCOMODATION \n \t\t\t\t-> 2) MODIFY DETAILS\n\n";
    int choice;
    cout<<"\t\tSelect the task you wish to continue..\n";
    cout<<"\t\t-> ";
    cin>>choice;
    system("cls");
    switch(choice)
    {
        case 1:register_acc();
        break;
        case 2:modify_details();
        break;
        default: cout<<"\n\t\tInvalid Option....Please select valid option..!!\n";
        Sleep(2500);
        seller_menu();
        break;
    }
}

void customer_menu();

void cust_register()
{
    cout << "\n\n\n            \t";
    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    cout << "\n\t\t||\t\t CUSTOMER REGISTRATION MENU\t\t||\n";
    cout << "            \t";

    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    //cout<<"\n\n\n\n\t\t\t\tWELCOME TO HOLIDAY HOME ACCOMODATION SYSTEM\n";
    cout<<"\n\n";
    cout<<"\t\tEnter your name : ";
    string name;
    cin>>name;
    fstream custname,custid,custhid;
    custname.open("customers.txt",ios::app);
    custid.open("cust_id.txt");
    custhid.open("cust_hotel_id.txt",ios::app);
    int tid;
while(!custid.eof())
{
    custid>>tid;
}
custname<<name<<"\n";
custhid<<0<<"\n";
custhid.close();
custid.close();
custid.open("cust_id.txt",ios::app);
custid<<tid+1<<"\n";
cout<<"\n\t\tCustomer Registration Successfull!!!!\n";
cout<<"\n\t\tYour registered customer id is : "<<tid+1;

custname.close();
custid.close();
Sleep(2500);
system("cls");
customer_menu();
}

void customer_menu(){
    cout << "\n\n\n            \t";
    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    cout << "\n\t\t||\t\t\tCUSTOMER MENU\t\t\t||\n";
    cout << "            \t";

    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    //cout<<"\n\n\n\n\t\t\t\tWELCOME TO HOLIDAY HOME ACCOMODATION SYSTEM\n";
    cout<<"\n\n";
    cout<<"\t\t\t\t-> 1)SEARCH HOTEL \n \t\t\t\t-> 2)CHECKOUT \n \t\t\t\t-> 3)REGISTER\n\n";
    int choice;
    cout<<"\t\tSelect the task you wish to continue..\n";
    cout<<"\t\t-> ";
    cin>>choice;
    system("cls");
    switch(choice)
    {
        case 1:book();
        break;
        case 2:checkout();
        break;
        case 3:cust_register();
        break;
        default: cout<<"\n\n\t\tInvalid Option....Please select valid option..!!!\n";
        Sleep(2500);
        customer_menu();
        break;
    }
}

/*HOMEPAGE COMPLETED*/

void homePage(){
    cout << "\n\n\n            \t";
    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    cout << "\n\t\t||\t WELCOME TO HOLIDAY HOME ACCOMODATION SYSTEM\t||\n";
    cout << "            \t";

    for(int i=1;i<59;i++)
	{
		cout<<"=";
	}
    //cout<<"\n\n\n\n\t\t\t\tWELCOME TO HOLIDAY HOME ACCOMODATION SYSTEM\n";
    cout<<"\n\n";
    cout<<"\t\t\t\t -> 1) SELLER MENU \n \t\t\t\t -> 2) CUSTOMER MENU \n \t\t\t\t -> 3) Exit\n\n";
    cout<<"\t\tSelect the menu you wish to continue with......\n\n";
    int choice;
    cout<<"\t\t-> ";
    cin>>choice;
    system("cls");
    switch(choice)
    {
        case 1:seller_menu();
        break;
        case 2:customer_menu();
        break;
        case 3:exit(0);
        break;
        default: cout<<"\n\n\t\tInvalid Option....Please select valid option...!!!!\n";
        Sleep(2500);
        homePage();
        break;
    }
}

int main()
{
    system("cls");
    homePage();
    return 0;
}

