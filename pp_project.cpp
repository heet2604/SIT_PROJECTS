#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<Windows.h>
#include<climits>
#include<string>

using namespace std;

class User {
public:
    string username;
    string password;
    string userID;
    string email;
    string phNO;
    string location;
    string name;

    User() {}
    
    User(string name, string email, string phNO, string location, string password)
        : name(name), email(email), phNO(phNO), location(location), password(password) {
    }
    
    void getdata() {
        cout << "Enter User ID: ";
        cin >> userID;
        cout << "Enter Name: ";
        //cin.ignore();
        getline(cin, name);
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter Phone number: ";
        cin >> phNO;
        cout << "Enter your location: ";
        cin.ignore();
        getline(cin, location);
    }

    void displayProfile() {
        cout << "Name: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Email: " << email << endl;
        cout << "Phone Number: " << phNO << endl;
    }
    

    bool authenticate() {
        string inputUsername, inputPassword;

        cout << "Enter your username: ";
        cin >> inputUsername;
        cout << "Enter your password: ";
        cin >> inputPassword;

        if (inputUsername == username && inputPassword == password) {
            cout << "Authentication successful. Welcome, " << username << "!" << endl;
            return true;
        } else {
            cout << "Authentication failed. Please check your credentials." << endl;
            return false;
        }
    }
};

class Tenant : public User {
public:
    int budget;
    int no_of_rooms;
    string tenanttype;

    Tenant(){};

    Tenant(string username, string password, string userID, string name, string email, string phNO, string location, int budget, int no_of_rooms, string tenanttype)
        : User(name, email, phNO, location, password), budget(budget), no_of_rooms(no_of_rooms), tenanttype(tenanttype) {
        this->username = username;
        this->userID = userID;
    }

    void displayTenantProfile() {
        cout << "Name: " << name << endl;
        cout << "UserID: " << userID << endl;
        cout << "Location: " << location << endl;
        cout << "Budget: " << budget << endl;
        cout << "No. of rooms: " << no_of_rooms << endl;
        cout << "Email: " << email << endl;
        cout << "Phone Number: " << phNO << endl;
    }

    void getdata() {
        User::getdata();
        cout << "Enter Your Budget: ";
        cin >> budget;
        cout << "Enter Your Requirements (1 BHK, 2BHK, 3BHK, etc): ";
        cin >> no_of_rooms;
    }
};

class Owner : public User {
public:
    int no_properties;
    string tenant_type;
    string owner_name;
    string owner_id;

    Owner(int no_properties, string tenant_type, string owner_name, string owner_id, string email, string phNO, string location)
        : no_properties(no_properties), tenant_type(tenant_type), owner_name(owner_name), owner_id(owner_id) {
        this->owner_name=owner_name;
        this->owner_id=owner_id;
        this->tenant_type=tenant_type;
        this->no_properties=no_properties;
        this->email = email;
        this->phNO = phNO;
        this->location = location;
    }

    void displayOwnerProfile() {
        //User::displayProfile();
    
        cout << "Name: " << owner_name << endl;
        cout << "UserID: " << owner_id << endl;
        cout << "Location: " << location << endl;
        cout<<"Number of properties: "<<no_properties<<endl;
        cout << "Email: " << email << endl;
        cout << "Phone Number: " << phNO << endl;}
    

    void getProperties() {
        int no_rooms;
        int no_bathrooms;
        string facing;
        string locality;
        string property_name;
        string finishing;
        string property_type;
        int price;

        cout << "No. of rooms: ";
        cin >> no_rooms;
        cout << "No. of bathrooms: ";
        cin >> no_bathrooms;
        cout << "Facing of the property: ";
        cin >> facing;
        cout << "Location of the property: ";
        cin.ignore();
        getline(cin, locality);
        cout << "Name of the society: ";
        getline(cin, property_name);
        cout << "Furnished or unfurnished? : ";
        cin >> finishing;
        cout << "For sale or for rent? : ";
        cin >> property_type;
        cout << "Price of the property: ";
        cin >> price;
    }
};

class Property {
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

    Property(int no_rooms, int no_bathrooms, string name, string location, int price, string facing, Owner owner_property, string property_type, string finishing)
        : no_rooms(no_rooms), no_bathrooms(no_bathrooms), name(name), location(location), price(price), facing(facing), owner_property(owner_property), property_type(property_type), finishing(finishing) {
    }

    void displayProperty() {
        cout << "Name of the property: " << name << endl;
        cout << "No. of rooms: " << no_rooms << endl;
        cout << "Location of the property: " << location << endl;
        cout << "Price of the property: " << price << endl;
        cout << "Facing of the property: " << facing << endl;
        cout << "The property is: " << finishing << endl;
    }
};

void compareInquiry(Tenant t, Property p) {
    if (t.no_of_rooms == p.no_rooms && t.location == p.location && t.budget >= p.price) {
        p.displayProperty();
    }
}

int main() {
        Owner owners[10] = {
        Owner(5, "Family", "Alice", "2001", "alice@email.com", "1234567890", "Location1"),
        Owner(3, "Individual", "Bob", "2002", "bob@email.com", "9876543210", "Location2"),
        Owner(7, "Family", "Charlie", "2003", "charlie@email.com", "5555555555", "Location3"),
        Owner(2, "Individual", "David", "2004", "david@email.com", "1111111111", "Location4"),
        Owner(4, "Family", "Eve", "2005", "eve@email.com", "4444444444", "Location5"),
        Owner(6, "Individual", "Frank", "2006", "frank@email.com", "9999999999", "Location6"),
        Owner(8, "Family", "Grace", "2007", "grace@email.com", "6666666666", "Location7"),
        Owner(1, "Individual", "Henry", "2008", "henry@email.com", "7777777777", "Location8"),
        Owner(5, "Family", "Ivy", "2009", "ivy@email.com", "2222222222", "Location9"),
        Owner(3, "Individual", "Jack", "2010", "jack@email.com", "3333333333", "Location10")
    };

    
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

        Property properties[10]={p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};
    

        Tenant tenant1("user1", "pass1", "ID1", "John Doe", "john@example.com", "1234567890", "Suburbia", 150000, 3, "Family");
        Tenant tenant2("user2", "pass2", "ID2", "Alice Smith", "alice@example.com", "9876543210", "Downtown", 100000, 2, "Individual");
        Tenant tenant3("user3", "pass3", "ID3", "Bob Johnson", "bob@example.com", "5555555555", "Beachfront", 250000, 2, "Family");
        Tenant tenant4("user4", "pass4", "ID4", "Eve Wilson", "eve@example.com", "1111111111", "Lakefront", 220000, 2, "Individual");
        Tenant tenant5("user5", "pass5", "ID5", "Grace Brown", "grace@example.com", "4444444444", "Seaside", 50000, 3, "Family");

        Tenant tenants[5]={tenant1,tenant2,tenant3,tenant4,tenant5};

        Tenant t;
        cout<<"\n\nEnter your id : ";
        cin>>t.userID;
        cout<<"\nEnter Phone number : ";
        cin>>t.phNO;

        int j,i;

        for( i=0;i<5;i++){
            for( j=0;j<5;j++){
                if(tenants[i].phNO==t.phNO){
                compareInquiry(tenants[i],properties[j]);
                }
                
            }
        }

        cout<<endl<<endl;

        properties[j].owner_property.displayOwnerProfile();
        int choice;
        cout<<"Press 1 to view image or Press 2 to exit the program : \n\n";
        cin>>choice;
        if(choice==1){
            if(j==1){
            
                std::system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society1.jpeg");}

            if(j==2){
                std::system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society2.jpeg");

            }
            if(j==3){
                std::system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society3.jpeg");
            }
            if(j==4){
                std::system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society4.jpeg");
            }
            if(j==5){
                std::system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society5.jpeg");
            }
            if(j==6){
                std::system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society6.jpeg");
            }

            if(j==7){
                std::system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society7.jpeg");
            }

            if(j==8){
                std::system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society8.jpeg");
            }

            if(j==9){
                std::system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society9.jpeg");
            }
            if(j==10){
                std::system("start C:\\Users\\HP\\Desktop\\ppprojectpics\\society1.jpeg");
            }

                
            
        }

        else if(choice==2){
            cout<<"exiting...";
            return 0;
        }
        
        return 0;
    }