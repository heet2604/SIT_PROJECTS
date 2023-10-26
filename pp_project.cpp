#include <iostream>
#include<windows.h>
#include <string>

using namespace std;

class User {
protected:
string password;//
public:
    string username;
    
    string userID;
    string email;//
    long int phNO;//
    string location;//
    string name;//
    string tenanttype;//
    
    User() {};
    User (string name){
        this->name=name;        //when a user only wants to register and not use the app functionality
    }

    User(string name, string email, long int phNO, string location, string password, string tenanttype, string username )
        : name(name), email(email), phNO(phNO), location(location), password(password), tenanttype(tenanttype) , username(username){
    };

    void getdata() {
        cout << "Enter User ID: ";
        cin >> userID;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter Phone number: ";
        cin >> phNO;
        cin.ignore();
        cout << "Enter your location: ";
        getline(cin, location);
    }

    void displayProfile() {     //displays user profile
        cout << "Name: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Email: " << email << endl;
        cout << "Phone Number: " << phNO << endl;
        cout<<endl<<endl;
    }
};

class Tenant : public User {    //inherits from user class and has extra vriables 
public:
    int budget;
    int no_of_rooms;

    Tenant() {}

    Tenant(string username, string password, string userID, string name, string email, long long phNO, string location, int budget, int no_of_rooms, string tenanttype){
        this->username=username;
        this->password=password;
        this->userID=userID;
        this->name=name;
        this->email=email;
        this->phNO=phNO;
        this->location=location;        //constructor
        this->budget=budget;
        this->no_of_rooms=no_of_rooms;
        this->tenanttype=tenanttype;

    }

    void displayTenantProfile() {       //displays tenant profile while also using display profile from user
        displayProfile();
        cout << "Budget: " << budget << endl;
        cout << "No. of rooms: " << no_of_rooms << endl;

        cout<<"------------------------------------------------------------------------------------------------";

        cout<<endl<<endl;
    }
};

class Owner : public User {         //inherits from user class
public:
    int no_properties;
    string tenant_type;
    string owner_name;
    string owner_id;

    Owner() {}; //default constructor

    Owner(int no_properties, string tenant_type, string owner_name, string owner_id, string email, long long phNO, string location){
        this->no_properties=no_properties;
        this->tenant_type=tenant_type;
        this->owner_name=owner_name;
        this->owner_id=owner_id;        //parametrized constructor
        this->email=email;
        this->phNO=phNO;
        this->location=location;
    };

    void displayOwnerProfile() {        //displays profile while also using display profile
        name=owner_name;
        displayProfile();
        
        cout << "Name: " << owner_name << endl;
        cout << "UserID: " << owner_id << endl;
        cout << "Number of properties: " << no_properties << endl;

        cout<<"----------------------------------------------------------------------------------------------------------";
        cout<<endl<<endl;
    }


    
};

class Property {        //creates a property class 
public:
    int no_rooms;
    int no_bathrooms;
    string facing;
    string location;
    string name;
    string finishing;
    string property_type;
    int price;
    Owner owner_property;

    Property(){};

    Property(int no_rooms, int no_bathrooms, string name, string location, int price, string facing, Owner owner_property, string property_type, string finishing)
        : no_rooms(no_rooms), no_bathrooms(no_bathrooms), name(name), location(location), price(price), facing(facing), owner_property(owner_property), property_type(property_type), finishing(finishing) {
    }

    void displayProperty() {                                    //displays property
        cout << "Name of the property: " << name << endl;
        cout << "No. of rooms: " << no_rooms << endl;
        cout << "Location of the property: " << location << endl;
        cout << "Price of the property: " << price << endl;
        cout << "Facing of the property: " << facing << endl;
        cout << "The property is: " << finishing << endl;

        cout<<"-----------------------------------------------------------------------------------------------------------------";
        cout<<endl<<endl;
    }


    void getproperty(){
        Property(p);
        cout<<"Enter number of rooms";
        cin>>p.no_rooms;
        cout<<"Enter number of bathrooms\n";
        cin>>p.no_rooms;
        cout<<"Enter name of property\n";
        getline(cin,p.name);
        cout<<"Enter location of property\n";
        getline(cin,p.location);
        cout<<"Enter price of property\n";
        cin>>p.price;
        cout<<"Enter facing of property\n";
        getline(cin,p.facing);
        cout<<"Enter Property Type";
        getline(cin, p.property_type);
        cout<<"Enter Finishing";
        getline(cin, p.finishing);

    }



    
};

bool compareInquiry(const Tenant& t, const Property& p) {
    return (t.no_of_rooms == p.no_rooms && t.location == p.location && t.budget <= p.price);
}






int main() {
    cout << " ====================================== WELCOME TO TENANT/ OWNER FINDER ========================================\n\n";

    
        Owner o1= Owner(5, "Family", "Alice", "2001", "alice@email.com", 1234567890, "Location1");
        Owner o2= Owner(3, "Individual", "Bob", "2002", "bob@email.com", 9876543210, "Location2");
        Owner o3= Owner(7, "Family", "Charlie", "2003", "charlie@email.com", 5555555555, "Location3");
        Owner o4= Owner(2, "Individual", "David", "2004", "david@email.com", 1111111111, "Location4");
        Owner o5= Owner(4, "Family", "Eve", "2005", "eve@email.com", 4444444444, "Location5");
        Owner o6= Owner(6, "Individual", "Frank", "2006", "frank@email.com", 9999999999, "Location6");
        Owner o7= Owner(8, "Family", "Grace", "2007", "grace@email.com", 6666666666, "Location7");
        Owner o8= Owner(1, "Individual", "Henry", "2008", "henry@email.com", 7777777777, "Location8");
        Owner o9= Owner(5, "Family", "Ivy", "2009", "ivy@email.com", 2222222222, "Location9");
        Owner o10= Owner(3, "Individual", "Jack", "2010", "jack@email.com", 3333333333, "Location10");

        
        Owner owners[30] = {o1,o2,o3,o4,o5,o6,o7,o8,o9,o10};

    

        
        Property p1=Property(3, 2, "Cozy Cottage", "Suburbia", 150000, "North", owners[0], "House", "Modern");
        Property p2=Property(4, 3, "Luxury Villa", "Seaside", 500000, "East", owners[1], "House", "Luxury");
        Property p3=Property(2, 1, "City Apartment", "Downtown", 100000, "South", owners[2], "Apartment", "Basic");
        Property p4=Property(5, 4, "Spacious Mansion", "Countryside", 800000, "West", owners[3], "House", "Classic");
        Property p5=Property(2, 2, "Beach Condo", "Beachfront", 250000, "East", owners[4], "Condo", "Modern");
        Property p6=Property(3, 2, "Rural Farmhouse", "Rural Area", 200000, "North", owners[5], "House", "Rustic");
        Property p7=Property(2, 1, "High-rise Condo", "City Center", 300000, "South", owners[6], "Condo", "Luxury");
        Property p8=Property(4, 2, "Suburban Duplex", "Suburbia", 180000, "East", owners[7], "House", "Basic");
        Property p9=Property(1, 1, "Studio Apartment", "Downtown", 75000, "West", owners[8], "Apartment", "Modern");
        Property p10=Property(3, 2, "Lakeside Cottage", "Lakefront", 220000, "North", owners[9], "House", "Rustic");

        Property properties[20]={p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};
    


   
        Tenant t1= Tenant("user1", "pass1", "ID1", "John Doe", "john@example.com", 1234567890, "Suburbia", 150000, 3, "Family");
        Tenant t2= Tenant("user2", "pass2", "ID2", "Alice Smith", "alice@example.com", 9876543210, "Downtown", 100000, 2, "Individual");
        Tenant t3= Tenant("user3", "pass3", "ID3", "Bob Johnson", "bob@example.com", 5555555555, "Beachfront", 250000, 2, "Family");
        Tenant t4= Tenant("user4", "pass4", "ID4", "Eve Wilson", "eve@example.com", 1111111111, "Lakefront", 220000, 2, "Individual");
        Tenant t5= Tenant("user5", "pass5", "ID5", "Grace Brown", "grace@example.com", 4444444444, "Seaside", 50000, 3, "Family");

        Tenant tenants[10]={t1,t2,t3,t4,t5};
        


    int choice = 0;

    while (choice != 10) {
        std::cout << "\n\nPress 1 to Enter as a tenant" << std::endl;
        std::cout << "Press 2 to view all properties" << std::endl;
        std::cout << "Press 3 to display all owner profiles" << std::endl;
        std::cout << "Press 4 to display all tenant profiles" << std::endl;
        std::cout <<"Press 5 to display property image using property ID number"<<endl;
        std::cout<< "Press 6 to add a new property"<<endl;
        std::cout << "Press 10 to exit the program" << std::endl;
        
        cin>>choice;
        //Property properties[10]; // Initialize your properties array
        int propertyCount = 0; 


    if (choice == 1) {
    // Tenant profile

    Tenant t;

    cout << "Enter user ID: ";
    cin.ignore();
    getline(cin, t.userID);

    int flag = 0;
    int i;

    for (i = 0; i < 5; i++) {
        if (t.userID == tenants[i].userID) {
            tenants[i].displayTenantProfile();
            flag = 1;
            break; // Exit the loop when the tenant is found
        }
    }

    if (flag == 0) {
        cout << "Tenant not found in existing database\n\n";
    } 
    
    else {
        cout << "Properties most suitable for you:\n\n";

        for (int w = 0; w < 10; w++) {
            if (compareInquiry(tenants[i], properties[w])) {
                properties[w].displayProperty();
                cout<<"Property ID ="<<w<<endl;}


    }
    }
    }

     else if (choice==2){        //displays properties
            for(int j=0;j<10;j++){
                properties[j].displayProperty();
            }

            cout<<endl<<endl;
        }

        else if(choice==3){         //displays owner profile
             for(int k=0;k<10;k++){
                owners[k].displayOwnerProfile();                
             }
             cout<<endl<<endl;
        }

        else if(choice==4){
             //displays tenant profiles 

             for(int w=0;w<5;w++){
                tenants[w].displayTenantProfile();
             }
        }

    else if (choice == 5) {
    cout << "Enter property number : " << endl;
    int prop_num, w;
    cin >> prop_num;
    w = prop_num;

    // Property number
    if (w == 1) {
        system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society1.jpeg");       //since images are displayed directly through system
    } else if (w == 2) {
        system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society2.jpeg");       //this functionality will not work 
    } else if (w == 3) {
        system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society3.jpeg");
    } else if (w == 4) {
        system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society4.jpeg");
    } else if (w == 5) {
        system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society5.jpeg");
    } else if (w == 6) {
        system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society6.jpeg");
    } else if (w == 7) {
        system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society7.jpeg");
    } else if (w == 8) {
        system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society8.jpeg");
    } else if (w == 9) {
        system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society9.jpeg");
    } else if (w == 10) {
        system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society10.jpeg");
    }
}

else if (choice == 6) {
    if (propertyCount < 20) {  // Check if the propertyCount is less than array size 
        Property newProperty;

        cout << "Enter number of rooms: ";
        cin >> newProperty.no_rooms;
        cout << "Enter number of bathrooms: ";
        cin >> newProperty.no_bathrooms;
        cout << "Enter name of property: ";
        cin.ignore();
        getline(cin, newProperty.name);
        cout << "Enter location of property: ";
        getline(cin, newProperty.location);
        cout << "Enter price of property: ";
        cin >> newProperty.price;
        cout << "Enter facing of property: ";
        cin.ignore();
        getline(cin, newProperty.facing);
        cout << "Enter Property Type: ";
        getline(cin, newProperty.property_type);
        cout << "Enter Finishing: ";
        getline(cin, newProperty.finishing);

        properties[propertyCount] = newProperty;
        propertyCount++;

        cout << "New property has been added." << endl;
    } else {
        cout << "Property list is full. Cannot add more properties." << endl;
    }
}


    }






    return 0;
}
