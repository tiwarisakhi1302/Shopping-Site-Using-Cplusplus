#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include <stdlib.h>
using namespace std;

bool Check_Customer(string,string);
void starting_Screen();
void Sign_in();
void Main_Screen();
void Set_info();
void Add_To_cart(int clothing_choice);
bool search_Product_ID(string ID,int clothing_choice);
struct Address
{
    int house_no;
    int postal_code;
};

class Customer
{
public:
    string username;
    string password;
    string email;
    Address Customer_Address;
    long long int phone_no;

    Customer()
    {
        username = "";
        password = "";
        email = "";
        Customer_Address.house_no = 0;
        Customer_Address.postal_code=0;
        phone_no = 0;
    }

    void Sign_up()
    {
        cout<<"\n\n\n---------------Sign UP Window------------\n\n\n";
        cout<<"Enter User Name : ";
        cin>>username;
        cout<<"Enter Email : ";
        cin>>email;
        cout<<"Enter Password : ";
        cin>>password;
        cout<<" \n -- Enter Customer Address -- \n";
        cout<<"Enter House No : ";
        cin>>Customer_Address.house_no;
        cout<<"Enter Postal Code of your area : ";
        cin>>Customer_Address.postal_code;
        cout<<"\n\n\n------------------------------------------\n\n\n";
    }
};


class Clothing
{
public:
    string product_name;
    double price;
    string productID;
    string rating;
};


////////////////////////////////////////////////////////
class Kids:public Clothing
{
public:

};

class Girls:public Kids
{
public:
};

class Boys:public Kids
{

public:
};
//////////////////////////////////////////////////
class Top_Girls:public Girls
{
public:

};

class skirts_Girls:public Girls
{
public:

};

class Jeans_Girls :public Girls
{
public:

};

class Shirt_Girls :public Girls
{
public:


};
class Shoes_Girls :public Girls
{
public:

};

class Jeans_Boys :public Boys
{
public:

};

class Shirt_Boys :public Boys
{
public:


};

class Shoes_Boys :public Boys
{
public:

};

//////////////////////////////////////////////////

class Men:public Clothing
{
public:
};

class Shirt_Men:public Men
{
public:
};

class Trousers_Men:public Men
{
public:
};

//////////////////////////////////////////////////
class Women:public Clothing
{
public:
};

class Top_Women:public Women
{
public:
};

class Jeans_Women:public Women
{
public:
};
////////////////////////////////////////////////
class Cart:private Customer
{
public:
    string name;
    string product_ID;
    double price;
};


 void Add_To_cart(int clothing_choice)
    {
        int Cart_Choice;
        string P_ID;
h:
        cout<<"1> ADD item to cart 2> back \n";
        cin>>Cart_Choice;
        if(Cart_Choice == 1)
        {
            cout<<"\n\t\t--------------Enter Product ID of item you want to buy------------------\t\t\n";
            cin>>P_ID;
            if(search_Product_ID(P_ID,clothing_choice) == 1)
            {
                cout<<"Added Successfully to your Cart\n";
                goto h;
            }
            else
            {
                cout<<"Wrong Product ID\n";
                goto h;
            }
        }
        else if(Cart_Choice == 2)
        {
            system("CLS");
            Main_Screen();

        }
        else
        {
            cout<<"Wrong Choice entered\n";
            goto h;
        }
    }

vector <Cart> user_cart;

vector <Customer> c; //customer object

/////////////////////////////////////////////////////////////////
vector <Shoes_Boys> shoes_object; //shoes boys object

vector <Jeans_Boys> Jeans_Boys_object; //Jeans boys object

vector <Shirt_Boys> Shirt_Boys_object; //Shirt boys object
/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
vector <Shoes_Girls> shoes_object_Girls;//shoes Girls object

vector <Shirt_Girls> shirt_object_Girls;//shirt Girls object

vector <Top_Girls> top_object_Girls;//top Girls object

vector <skirts_Girls> skirts_object_Girls;//skirts Girls object

vector <Jeans_Girls> Jeans_object_Girls;//jeans Girls object
/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
vector <Shirt_Men> shirt_object_Men;//shirt_object_Men

vector <Trousers_Men> Trousers_object_Men;//Trousers_object_Men
/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
vector <Top_Women> Top_object_Women;//Top_object_Women

vector <Jeans_Women> Jeans_object_Women;//Jeans_object_Women
/////////////////////////////////////////////////////////////////



void Saved_Users()
{
    c.push_back(Customer());
    c[c.size()-1].username = "Saksham";
    c[c.size()-1].password = "1234";

    c.push_back(Customer());
    c[c.size()-1].username = "Manan";
    c[c.size()-1].password = "1234";

    c.push_back(Customer());
    c[c.size()-1].username = "Sakshi";
    c[c.size()-1].password = "1234";

}

bool Check_Customer(string username,string password)
{
    for(int i=0; i<c.size(); i++)
    {
        if(c[i].username == username && c[i].password == password)
            return 1;
    }
    return 0;
}

class Display
{
public:
    void Display_Boys()
    {
        cout<<"/////////////////////////////////////////////////////////////<:SHOES:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        cout<<"\n\tProduct name\t\t|\t\tProduct ID\t\t|\t\tRating\t\t|\t\tPrice\t\t\n\n";
        for(int i=0; i<shoes_object.size(); i++)
            cout<<setw(30)<<shoes_object[i].product_name<<"\t\t"<<setw(10)<<shoes_object[i].productID<<"\t\t\t\t"<<setw(10)<<shoes_object[i].rating<<"\t\t\t"<<setw(10)<<shoes_object[i].price<<"\n";

        cout<<"/////////////////////////////////////////////////////////////<:JEANS:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        for(int i=0; i<Jeans_Boys_object.size(); i++)
            cout<<setw(30)<<Jeans_Boys_object[i].product_name<<"\t\t"<<setw(10)<<Jeans_Boys_object[i].productID<<"\t\t\t\t"<<setw(10)<<Jeans_Boys_object[i].rating<<"\t\t\t"<<setw(10)<<Jeans_Boys_object[i].price<<"\n";

        cout<<"/////////////////////////////////////////////////////////////<:SHIRTS:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        for(int i=0; i<Shirt_Boys_object.size(); i++)
            cout<<setw(30)<<Shirt_Boys_object[i].product_name<<"\t\t"<<setw(10)<<Shirt_Boys_object[i].productID<<"\t\t\t\t"<<setw(10)<<Shirt_Boys_object[i].rating<<"\t\t\t"<<setw(10)<<Shirt_Boys_object[i].price<<"\n";
    }
    void Display_Girls()
    {
        cout<<"/////////////////////////////////////////////////////////////<:SHOES:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";

        cout<<"\n\tProduct name\t\t|\t\tProduct ID\t\t|\t\tRating\t\t|\t\tPrice\t\t\n\n";

        for(int i=0; i<shoes_object_Girls.size(); i++)
            cout<<setw(30)<<shoes_object_Girls[i].product_name<<"\t\t"<<setw(10)<<shoes_object_Girls[i].productID<<"\t\t\t\t"<<setw(10)<<shoes_object_Girls[i].rating<<"\t\t\t"<<setw(10)<<shoes_object_Girls[i].price<<"\n";

        cout<<"/////////////////////////////////////////////////////////////<:JEANS:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        for(int i=0; i<Jeans_object_Girls.size(); i++)
            cout<<setw(30)<<Jeans_object_Girls[i].product_name<<"\t\t"<<setw(10)<<Jeans_object_Girls[i].productID<<"\t\t\t\t"<<setw(10)<<Jeans_object_Girls[i].rating<<"\t\t\t"<<setw(10)<<Jeans_object_Girls[i].price<<"\n";

        cout<<"/////////////////////////////////////////////////////////////<:SHIRTS:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        for(int i=0; i<shirt_object_Girls.size(); i++)
            cout<<setw(30)<<shirt_object_Girls[i].product_name<<"\t\t"<<setw(10)<<shirt_object_Girls[i].productID<<"\t\t\t\t"<<setw(10)<<shirt_object_Girls[i].rating<<"\t\t\t"<<setw(10)<<shirt_object_Girls[i].price<<"\n";
        cout<<"/////////////////////////////////////////////////////////////<:SKIRTS:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        for(int i=0; i<skirts_object_Girls.size(); i++)
            cout<<setw(30)<<skirts_object_Girls[i].product_name<<"\t\t"<<setw(10)<<skirts_object_Girls[i].productID<<"\t\t\t\t"<<setw(10)<<skirts_object_Girls[i].rating<<"\t\t\t"<<setw(10)<<skirts_object_Girls[i].price<<"\n";

        cout<<"/////////////////////////////////////////////////////////////<:TOPS:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        for(int i=0; i<top_object_Girls.size(); i++)
            cout<<setw(30)<<top_object_Girls[i].product_name<<"\t\t"<<setw(10)<<top_object_Girls[i].productID<<"\t\t\t\t"<<setw(10)<<top_object_Girls[i].rating<<"\t\t\t"<<setw(10)<<top_object_Girls[i].price<<"\n";

    }
    void Display_Mens()
    {
        cout<<"/////////////////////////////////////////////////////////////<:SHIRTS:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        cout<<"\n\tProduct name\t\t|\t\tProduct ID\t\t|\t\tRating\t\t|\t\tPrice\t\t\n\n";
        for(int i=0; i<shoes_object.size(); i++)
            cout<<setw(30)<<shoes_object[i].product_name<<"\t\t"<<setw(10)<<shoes_object[i].productID<<"\t\t\t\t"<<setw(10)<<shoes_object[i].rating<<"\t\t\t"<<setw(10)<<shoes_object[i].price<<"\n";

        cout<<"/////////////////////////////////////////////////////////////<:TROUSERS:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        for(int i=0; i<Jeans_Boys_object.size(); i++)
            cout<<setw(30)<<Jeans_Boys_object[i].product_name<<"\t\t"<<setw(10)<<Jeans_Boys_object[i].productID<<"\t\t\t\t"<<setw(10)<<Jeans_Boys_object[i].rating<<"\t\t\t"<<setw(10)<<Jeans_Boys_object[i].price<<"\n";
    }
    void Display_Women()
    {
        cout<<"/////////////////////////////////////////////////////////////<:TOP:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        cout<<"\n\tProduct name\t\t|\t\tProduct ID\t\t|\t\tRating\t\t|\t\tPrice\t\t\n\n";
        for(int i=0; i<shoes_object.size(); i++)
            cout<<setw(30)<<shoes_object[i].product_name<<"\t\t"<<setw(10)<<shoes_object[i].productID<<"\t\t\t\t"<<setw(10)<<shoes_object[i].rating<<"\t\t\t"<<setw(10)<<shoes_object[i].price<<"\n";

        cout<<"/////////////////////////////////////////////////////////////<:JEANS:>\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
        for(int i=0; i<Jeans_Boys_object.size(); i++)
            cout<<setw(30)<<Jeans_Boys_object[i].product_name<<"\t\t"<<setw(10)<<Jeans_Boys_object[i].productID<<"\t\t\t\t"<<setw(10)<<Jeans_Boys_object[i].rating<<"\t\t\t"<<setw(10)<<Jeans_Boys_object[i].price<<"\n";
    }

} Display1;



bool search_Product_ID(string ID,int clothing_choice)
{

    if(clothing_choice == 1)
    {
        //boys

        //boys shoes
        for(int i=0; i<shoes_object.size(); i++)
        {
            if(ID == shoes_object[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = shoes_object[i].product_name;
                user_cart[user_cart.size()-1].product_ID = shoes_object[i].productID;
                user_cart[user_cart.size()-1].price = shoes_object[i].price;
                return 1;
            }
        }
        //boys shirts

        for(int i=0; i<Shirt_Boys_object.size(); i++)
        {
            if(ID == Shirt_Boys_object[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = Shirt_Boys_object[i].product_name;
                user_cart[user_cart.size()-1].product_ID = Shirt_Boys_object[i].productID;
                user_cart[user_cart.size()-1].price = Shirt_Boys_object[i].price;
                return 1;
            }
        }

        //boys Jeans

        for(int i=0; i<Jeans_Boys_object.size(); i++)
        {
            if(ID == Jeans_Boys_object[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = Jeans_Boys_object[i].product_name;
                user_cart[user_cart.size()-1].product_ID = Jeans_Boys_object[i].productID;
                user_cart[user_cart.size()-1].price = Jeans_Boys_object[i].price;
                return 1;
            }
        }

        //girls

        //girls shoes
        for(int i=0; i<shoes_object_Girls.size(); i++)
        {
            if(ID == shoes_object_Girls[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = shoes_object_Girls[i].product_name;
                user_cart[user_cart.size()-1].product_ID = shoes_object_Girls[i].productID;
                user_cart[user_cart.size()-1].price = shoes_object_Girls[i].price;
                return 1;
            }
        }

        //girls shirt

        for(int i=0; i<shirt_object_Girls.size(); i++)
        {
            if(ID == shirt_object_Girls[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = shirt_object_Girls[i].product_name;
                user_cart[user_cart.size()-1].product_ID = shirt_object_Girls[i].productID;
                user_cart[user_cart.size()-1].price = shirt_object_Girls[i].price;
                return 1;
            }
        }


        //girls Jeans

        for(int i=0; i<Jeans_object_Girls.size(); i++)
        {
            if(ID == Jeans_object_Girls[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = Jeans_object_Girls[i].product_name;
                user_cart[user_cart.size()-1].product_ID = Jeans_object_Girls[i].productID;
                user_cart[user_cart.size()-1].price = Jeans_object_Girls[i].price;
                return 1;
            }
        }

        //girls Top

        for(int i=0;i<top_object_Girls.size(); i++)
        {
            if(ID == top_object_Girls[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = top_object_Girls[i].product_name;
                user_cart[user_cart.size()-1].product_ID = top_object_Girls[i].productID;
                user_cart[user_cart.size()-1].price = top_object_Girls[i].price;
                return 1;
            }
        }
        //girls Skirts

        for(int i=0;i<skirts_object_Girls.size(); i++)
        {
            if(ID == skirts_object_Girls[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = skirts_object_Girls[i].product_name;
                user_cart[user_cart.size()-1].product_ID = skirts_object_Girls[i].productID;
                user_cart[user_cart.size()-1].price = skirts_object_Girls[i].price;
                return 1;
            }
        }

        return 0;
    }

    else if(clothing_choice == 2)
    {
        //shirts men

        for(int i=0; i<shirt_object_Men.size(); i++)
        {
            if(ID == shirt_object_Men[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = shirt_object_Men[i].product_name;
                user_cart[user_cart.size()-1].product_ID = shirt_object_Men[i].productID;
                user_cart[user_cart.size()-1].price = shirt_object_Men[i].price;
                return 1;
            }
        }

        //trousers men

        for(int i=0; i<Trousers_object_Men.size(); i++)
        {
            if(ID == Trousers_object_Men[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = Trousers_object_Men[i].product_name;
                user_cart[user_cart.size()-1].product_ID = Trousers_object_Men[i].productID;
                user_cart[user_cart.size()-1].price = Trousers_object_Men[i].price;
                return 1;
            }
        }

        return 0;

    }

    else if(clothing_choice == 3)
    {
        //tops women

        for(int i=0; i< Top_object_Women.size(); i++)
        {
            if(ID == Top_object_Women[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = Top_object_Women[i].product_name;
                user_cart[user_cart.size()-1].product_ID = Top_object_Women[i].productID;
                user_cart[user_cart.size()-1].price = Top_object_Women[i].price;
                return 1;
            }
        }

        //jeans women

        for(int i=0; i<Jeans_object_Women.size(); i++)
        {
            if(ID == Jeans_object_Women[i].productID)
            {
                user_cart.push_back(Cart());
                user_cart[user_cart.size()-1].name = Jeans_object_Women[i].product_name;
                user_cart[user_cart.size()-1].product_ID = Jeans_object_Women[i].productID;
                user_cart[user_cart.size()-1].price = Jeans_object_Women[i].price;
                return 1;
            }
        }
        return 0;
    }
    else
        return 0;
}


void Set_info()
{
//boys shoes
    {
        /////////////////////////////////////////////////////

        shoes_object.push_back(Shoes_Boys());
        shoes_object[shoes_object.size()-1].product_name = "BeFit Boys Running Shoe";
        shoes_object[shoes_object.size()-1].productID = "CKBS001";
        shoes_object[shoes_object.size()-1].price = 599;
        shoes_object[shoes_object.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shoes_object.push_back(Shoes_Boys());
        shoes_object[shoes_object.size()-1].product_name = "BeFit Boys Sports Shoe";
        shoes_object[shoes_object.size()-1].productID = "CKBS002";
        shoes_object[shoes_object.size()-1].price = 699;
        shoes_object[shoes_object.size()-1].rating = "* * *";

//////////////////////////////////////////////////////


/////////////////////////////////////////////////////

        shoes_object.push_back(Shoes_Boys());
        shoes_object[shoes_object.size()-1].product_name = "Liberty Luke Boy's";
        shoes_object[shoes_object.size()-1].productID = "CKBS003";
        shoes_object[shoes_object.size()-1].price = 799;
        shoes_object[shoes_object.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shoes_object.push_back(Shoes_Boys());
        shoes_object[shoes_object.size()-1].product_name = "Sparx Boy's Sx0414b";
        shoes_object[shoes_object.size()-1].productID = "CKBS004";
        shoes_object[shoes_object.size()-1].price = 490;
        shoes_object[shoes_object.size()-1].rating = "* * * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shoes_object.push_back(Shoes_Boys());
        shoes_object[shoes_object.size()-1].product_name = "Nike Walking Shoes For Boys";
        shoes_object[shoes_object.size()-1].productID = "CKBS005";
        shoes_object[shoes_object.size()-1].price = 2000;
        shoes_object[shoes_object.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////
    }

//Jeans Boys
    {

        /////////////////////////////////////////////////////

        Jeans_Boys_object.push_back(Jeans_Boys());
        Jeans_Boys_object[Jeans_Boys_object.size()-1].product_name = "Slim Fit Stretchable Jeans";
        Jeans_Boys_object[Jeans_Boys_object.size()-1].productID = "CKBJ001";
        Jeans_Boys_object[Jeans_Boys_object.size()-1].price = 490;
        Jeans_Boys_object[Jeans_Boys_object.size()-1].rating = "* *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Jeans_Boys_object.push_back(Jeans_Boys());
        Jeans_Boys_object[Jeans_Boys_object.size()-1].product_name = "Max Boy's Carrot Slim Jeans";
        Jeans_Boys_object[Jeans_Boys_object.size()-1].productID = "CKBJ002";
        Jeans_Boys_object[Jeans_Boys_object.size()-1].price = 690;
        Jeans_Boys_object[Jeans_Boys_object.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Jeans_Boys_object.push_back(Jeans_Boys());
        Jeans_Boys_object[Jeans_Boys_object.size()-1].product_name = "Boys' Regular Fit Jeans";
        Jeans_Boys_object[Jeans_Boys_object.size()-1].productID = "CKBJ003";
        Jeans_Boys_object[Jeans_Boys_object.size()-1].price = 890;
        Jeans_Boys_object[Jeans_Boys_object.size()-1].rating = "* * *";

//////////////////////////////////////////////////////


/////////////////////////////////////////////////////

        Jeans_Boys_object.push_back(Jeans_Boys());
        Jeans_Boys_object[Jeans_Boys_object.size()-1].product_name = "Slim Fit Jogger Jeans Stretch";
        Jeans_Boys_object[Jeans_Boys_object.size()-1].productID = "CKBJ004";
        Jeans_Boys_object[Jeans_Boys_object.size()-1].price = 745;
        Jeans_Boys_object[Jeans_Boys_object.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Jeans_Boys_object.push_back(Jeans_Boys());
        Jeans_Boys_object[Jeans_Boys_object.size()-1].product_name = "AD & AV boy's  Cargo Pants";
        Jeans_Boys_object[Jeans_Boys_object.size()-1].productID = "CKBJ005";
        Jeans_Boys_object[Jeans_Boys_object.size()-1].price = 1099;
        Jeans_Boys_object[Jeans_Boys_object.size()-1].rating = "* * * * *";

//////////////////////////////////////////////////////
    }
//Shirts Boys
    {

        /////////////////////////////////////////////////////

        Shirt_Boys_object.push_back(Shirt_Boys());
        Shirt_Boys_object[Shirt_Boys_object.size()-1].product_name = "Kids Printed Cotton Blend Shirt";
        Shirt_Boys_object[Shirt_Boys_object.size()-1].productID = "CKBSH001";
        Shirt_Boys_object[Shirt_Boys_object.size()-1].price = 750;
        Shirt_Boys_object[Shirt_Boys_object.size()-1].rating = "* * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Shirt_Boys_object.push_back(Shirt_Boys());
        Shirt_Boys_object[Shirt_Boys_object.size()-1].product_name = "Max Boy's Regular Shirt";
        Shirt_Boys_object[Shirt_Boys_object.size()-1].productID = "CKBSH002";
        Shirt_Boys_object[Shirt_Boys_object.size()-1].price = 1570;
        Shirt_Boys_object[Shirt_Boys_object.size()-1].rating = "* * * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Shirt_Boys_object.push_back(Shirt_Boys());
        Shirt_Boys_object[Shirt_Boys_object.size()-1].product_name = "Boys' Regular Button Down Shirt";
        Shirt_Boys_object[Shirt_Boys_object.size()-1].productID = "CKBSH003";
        Shirt_Boys_object[Shirt_Boys_object.size()-1].price = 490;
        Shirt_Boys_object[Shirt_Boys_object.size()-1].rating = "* *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Shirt_Boys_object.push_back(Shirt_Boys());
        Shirt_Boys_object[Shirt_Boys_object.size()-1].product_name = "Boy's Regular fit Shirt";
        Shirt_Boys_object[Shirt_Boys_object.size()-1].productID = "CKBSH004";
        Shirt_Boys_object[Shirt_Boys_object.size()-1].price = 1250;
        Shirt_Boys_object[Shirt_Boys_object.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Shirt_Boys_object.push_back(Shirt_Boys());
        Shirt_Boys_object[Shirt_Boys_object.size()-1].product_name = "Half Sleeve Kids Tshirt";
        Shirt_Boys_object[Shirt_Boys_object.size()-1].productID = "CKBSH005";
        Shirt_Boys_object[Shirt_Boys_object.size()-1].price = 850;
        Shirt_Boys_object[Shirt_Boys_object.size()-1].rating = "* * *";

//////////////////////////////////////////////////////
    }
//girls shoes
    {
        /////////////////////////////////////////////////////

        shoes_object_Girls.push_back(Shoes_Girls());
        shoes_object_Girls[shoes_object_Girls.size()-1].product_name = "ADIDAS Lace Shoes(Beige)";
        shoes_object_Girls[shoes_object_Girls.size()-1].productID = "CKGS001";
        shoes_object_Girls[shoes_object_Girls.size()-1].price = 1500;
        shoes_object_Girls[shoes_object_Girls.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shoes_object_Girls.push_back(Shoes_Girls());
        shoes_object_Girls[shoes_object_Girls.size()-1].product_name = "Puma Velcro Running Shoes(Pink)";
        shoes_object_Girls[shoes_object_Girls.size()-1].productID = "CKGS002";
        shoes_object_Girls[shoes_object_Girls.size()-1].price = 1200;
        shoes_object_Girls[shoes_object_Girls.size()-1].rating = "* * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shoes_object_Girls.push_back(Shoes_Girls());
        shoes_object_Girls[shoes_object_Girls.size()-1].product_name = "BUNNIES Walking Shoes(Pink)";
        shoes_object_Girls[shoes_object_Girls.size()-1].productID = "CKGS003";
        shoes_object_Girls[shoes_object_Girls.size()-1].price = 800;
        shoes_object_Girls[shoes_object_Girls.size()-1].rating = "* * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shoes_object_Girls.push_back(Shoes_Girls());
        shoes_object_Girls[shoes_object_Girls.size()-1].product_name = "KazarMax Girl's Ballet Flats";
        shoes_object_Girls[shoes_object_Girls.size()-1].productID = "CKGS004";
        shoes_object_Girls[shoes_object_Girls.size()-1].price = 870;
        shoes_object_Girls[shoes_object_Girls.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shoes_object_Girls.push_back(Shoes_Girls());
        shoes_object_Girls[shoes_object_Girls.size()-1].product_name = "Miss&Slip Running Shoes Girls ";
        shoes_object_Girls[shoes_object_Girls.size()-1].productID = "CKGS005";
        shoes_object_Girls[shoes_object_Girls.size()-1].price = 935;
        shoes_object_Girls[shoes_object_Girls.size()-1].rating = "* * *";

//////////////////////////////////////////////////////
    }
//girls shirts
    {
        /////////////////////////////////////////////////////

        shirt_object_Girls.push_back(Shirt_Girls());
        shirt_object_Girls[shirt_object_Girls.size()-1].product_name = "Kidsvil Regular fit T-Shirt";
        shirt_object_Girls[shirt_object_Girls.size()-1].productID = "CKGSH001";
        shirt_object_Girls[shirt_object_Girls.size()-1].price = 750;
        shirt_object_Girls[shirt_object_Girls.size()-1].rating = "* * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shirt_object_Girls.push_back(Shirt_Girls());
        shirt_object_Girls[shirt_object_Girls.size()-1].product_name = "Relaxed Fit T-Shirt";
        shirt_object_Girls[shirt_object_Girls.size()-1].productID = "CKGSH002";
        shirt_object_Girls[shirt_object_Girls.size()-1].price = 1550;
        shirt_object_Girls[shirt_object_Girls.size()-1].rating = "* * * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shirt_object_Girls.push_back(Shirt_Girls());
        shirt_object_Girls[shirt_object_Girls.size()-1].product_name = "Kuchipoo T-Shirt";
        shirt_object_Girls[shirt_object_Girls.size()-1].productID = "CKGSH003";
        shirt_object_Girls[shirt_object_Girls.size()-1].price = 450;
        shirt_object_Girls[shirt_object_Girls.size()-1].rating = "* *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shirt_object_Girls.push_back(Shirt_Girls());
        shirt_object_Girls[shirt_object_Girls.size()-1].product_name = "Girls Cotton Multicolor T-Shirt";
        shirt_object_Girls[shirt_object_Girls.size()-1].productID = "CKGSH004";
        shirt_object_Girls[shirt_object_Girls.size()-1].price = 1200;
        shirt_object_Girls[shirt_object_Girls.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        shirt_object_Girls.push_back(Shirt_Girls());
        shirt_object_Girls[shirt_object_Girls.size()-1].product_name = "Totz T-Shirt Sleeveless";
        shirt_object_Girls[shirt_object_Girls.size()-1].productID = "CKGSH005";
        shirt_object_Girls[shirt_object_Girls.size()-1].price = 500;
        shirt_object_Girls[shirt_object_Girls.size()-1].rating = "* * *";

//////////////////////////////////////////////////////
    }
//girls Tops
    {
        /////////////////////////////////////////////////////

        top_object_Girls.push_back(Top_Girls());
        top_object_Girls[top_object_Girls.size()-1].product_name = "Hopscotch Santa Printed Top";
        top_object_Girls[top_object_Girls.size()-1].productID = "CKGT001";
        top_object_Girls[top_object_Girls.size()-1].price = 1090;
        top_object_Girls[top_object_Girls.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        top_object_Girls.push_back(Top_Girls());
        top_object_Girls[top_object_Girls.size()-1].product_name = "TEJASVI Girls Flower Print Top";
        top_object_Girls[top_object_Girls.size()-1].productID = "CKGT002";
        top_object_Girls[top_object_Girls.size()-1].price = 899;
        top_object_Girls[top_object_Girls.size()-1].rating = "* * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        top_object_Girls.push_back(Top_Girls());
        top_object_Girls[top_object_Girls.size()-1].product_name = "Western Style Striped Print TOP";
        top_object_Girls[top_object_Girls.size()-1].productID = "CKGT003";
        top_object_Girls[top_object_Girls.size()-1].price = 450;
        top_object_Girls[top_object_Girls.size()-1].rating = "* *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        top_object_Girls.push_back(Top_Girls());
        top_object_Girls[top_object_Girls.size()-1].product_name = "Girls Multicolor TOP";
        top_object_Girls[top_object_Girls.size()-1].productID = "CKGT004";
        top_object_Girls[top_object_Girls.size()-1].price = 1750;
        top_object_Girls[top_object_Girls.size()-1].rating = "* * * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        top_object_Girls.push_back(Top_Girls());
        top_object_Girls[top_object_Girls.size()-1].product_name = "Ventra Unicorn Sequin Top";
        top_object_Girls[top_object_Girls.size()-1].productID = "CKGT005";
        top_object_Girls[top_object_Girls.size()-1].price = 760;
        top_object_Girls[top_object_Girls.size()-1].rating = "* * *";

//////////////////////////////////////////////////////
    }
//girls skirts
    {
        /////////////////////////////////////////////////////

        skirts_object_Girls.push_back(skirts_Girls());
        skirts_object_Girls[skirts_object_Girls.size()-1].product_name = "Modish Vogue Floral Print Skirt";
        skirts_object_Girls[skirts_object_Girls.size()-1].productID = "CKGK001";
        skirts_object_Girls[skirts_object_Girls.size()-1].price = 799;
        skirts_object_Girls[skirts_object_Girls.size()-1].rating = "* * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        skirts_object_Girls.push_back(skirts_Girls());
        skirts_object_Girls[skirts_object_Girls.size()-1].product_name = "Girl's Maxi Skirt";
        skirts_object_Girls[skirts_object_Girls.size()-1].productID = "CKGK002";
        skirts_object_Girls[skirts_object_Girls.size()-1].price = 999;
        skirts_object_Girls[skirts_object_Girls.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        skirts_object_Girls.push_back(skirts_Girls());
        skirts_object_Girls[skirts_object_Girls.size()-1].product_name = "Aarika Cotton Blend Skirt";
        skirts_object_Girls[skirts_object_Girls.size()-1].productID = "CKGK003";
        skirts_object_Girls[skirts_object_Girls.size()-1].price = 499;
        skirts_object_Girls[skirts_object_Girls.size()-1].rating = "* *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        skirts_object_Girls.push_back(skirts_Girls());
        skirts_object_Girls[skirts_object_Girls.size()-1].product_name = "Girls Stripe Print Skirt";
        skirts_object_Girls[skirts_object_Girls.size()-1].productID = "CKGK004";
        skirts_object_Girls[skirts_object_Girls.size()-1].price = 1399;
        skirts_object_Girls[skirts_object_Girls.size()-1].rating = "* * * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        skirts_object_Girls.push_back(skirts_Girls());
        skirts_object_Girls[skirts_object_Girls.size()-1].product_name = "kidstudio Skirt Mini Kilt ";
        skirts_object_Girls[skirts_object_Girls.size()-1].productID = "CKGK005";
        skirts_object_Girls[skirts_object_Girls.size()-1].price = 730;
        skirts_object_Girls[skirts_object_Girls.size()-1].rating = "* * *";

//////////////////////////////////////////////////////


    }
//girls jeans
    {
        /////////////////////////////////////////////////////

        Jeans_object_Girls.push_back(Jeans_Girls());
        Jeans_object_Girls[Jeans_object_Girls.size()-1].product_name = " Girls' Slim Fit Jeans";
        Jeans_object_Girls[Jeans_object_Girls.size()-1].productID = "CKGK001";
        Jeans_object_Girls[Jeans_object_Girls.size()-1].price = 799;
        Jeans_object_Girls[Jeans_object_Girls.size()-1].rating = "* * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Jeans_object_Girls.push_back(Jeans_Girls());
        Jeans_object_Girls[Jeans_object_Girls.size()-1].product_name = "Max Girls Jeans Regular";
        Jeans_object_Girls[Jeans_object_Girls.size()-1].productID = "CKGK002";
        Jeans_object_Girls[Jeans_object_Girls.size()-1].price = 999;
        Jeans_object_Girls[Jeans_object_Girls.size()-1].rating = "* * * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Jeans_object_Girls.push_back(Jeans_Girls());
        Jeans_object_Girls[Jeans_object_Girls.size()-1].product_name = "Girl's Jeggings Slim Jeans";
        Jeans_object_Girls[Jeans_object_Girls.size()-1].productID = "CKGK003";
        Jeans_object_Girls[Jeans_object_Girls.size()-1].price = 699;
        Jeans_object_Girls[Jeans_object_Girls.size()-1].rating = "* *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Jeans_object_Girls.push_back(Jeans_Girls());
        Jeans_object_Girls[Jeans_object_Girls.size()-1].product_name = "Girl's Skinny Fit Jeans";
        Jeans_object_Girls[Jeans_object_Girls.size()-1].productID = "CKGK004";
        Jeans_object_Girls[Jeans_object_Girls.size()-1].price = 1350;
        Jeans_object_Girls[Jeans_object_Girls.size()-1].rating = "* *  * *";

//////////////////////////////////////////////////////

/////////////////////////////////////////////////////

        Jeans_object_Girls.push_back(Jeans_Girls());
        Jeans_object_Girls[Jeans_object_Girls.size()-1].product_name = "Max Carrot Slim Jeans";
        Jeans_object_Girls[Jeans_object_Girls.size()-1].productID = "CKGK005";
        Jeans_object_Girls[Jeans_object_Girls.size()-1].price = 790;
        Jeans_object_Girls[Jeans_object_Girls.size()-1].rating = "* * * * *";

//////////////////////////////////////////////////////

    }


}


void Main_Screen()
{

    int n;
    system("CLS");
    cout<<"\n\n\n--------------------------S-MART---------------------------------\n\n\n";
    cout<<"\n\n\t\t\t1 : Continue Shopping  \n\n\n\t\t\t2 : Goto Cart\n";
    cout<<"\n\n\n-----------------------------------------------------------------\n\n\n";
    cout<<"Enter Choice : ";
    cin>>n;

    if(n == 1)
    {
        int clothing_choice;
        system("CLS");
        cout<<"\n\n\n--------------------------S-MART---------------------------------\n\n\n";
        cout<<"\n\n\n--------------------------<:Clothings:>---------------------------------\n\n\n";
        cout<<"\n\n\t\t\t1 : KIDS \n\n\n\t\t\t2 : MEN \n\n\n\t\t\t3 : WOMEN\n";
        cout<<"\n\n\n-----------------------------------------------------------------\n\n\n";
        cout<<"Enter Choice : ";
        cin>>clothing_choice;
        if(clothing_choice == 1)
        {

            int gender_choice;


            system("CLS");
            cout<<"\n\n\n--------------------------S-MART---------------------------------\n\n\n";
            cout<<"\n\n\n--------------------------<:KIDS:>---------------------------------\n\n\n";
            cout<<"\n\n\t\t\t1 :Boys \n\n\n\t\t\t2 : Girls\n";
            cout<<"\n\n\n-----------------------------------------------------------------\n\n\n";
            cout<<"Enter Choice : ";
            cin>>gender_choice;

            if(gender_choice==1)
            {

                system("CLS");
                cout<<"\n\n\n--------------------------S-MART---------------------------------\n\n\n";
                cout<<"\n\n\n--------------------------<:BOYS:>---------------------------------\n\n\n";

                Display1.Display_Boys();
                Add_To_cart(clothing_choice);

            }
            else if(gender_choice == 2)
            {
                system("CLS");
                cout<<"\n\n\n--------------------------S-MART---------------------------------\n\n\n";
                cout<<"\n\n\n--------------------------<:GIRLS:>---------------------------------\n\n\n";
                Display1.Display_Girls();
                Add_To_cart(clothing_choice);
            }
            else
            {
                system("CLS");
                Main_Screen();
            }
        }
        else if(clothing_choice == 2)
        {
            system("CLS");
            cout<<"\n\n\n--------------------------S-MART---------------------------------\n\n\n";
            cout<<"\n\n\n--------------------------<:MEN:>---------------------------------\n\n\n";
            Display1.Display_Mens();
             Add_To_cart(clothing_choice);
        }
        else if(clothing_choice == 3)
        {
            system("CLS");
            cout<<"\n\n\n--------------------------S-MART---------------------------------\n\n\n";
            cout<<"\n\n\n--------------------------<:WOMEN:>---------------------------------\n\n\n";
            Display1.Display_Women();
             Add_To_cart(clothing_choice);
        }
        else
        {
            system("CLS");
            Main_Screen();
        }

    }
    else if(n == 2)
    {
        system("CLS");
        cout<<"\n\n\n--------------------------S-MART---------------------------------\n\n\n";
        cout<<"\n\n\n--------------------------<:CART:>---------------------------------\n\n\n";

    }
    else
    {
        system("CLS");
        Main_Screen();
    }
}

void Sign_in()
{
    cout<<"\n\n\n---------------Sign in Window------------\n\n\n";
    string username_Input;
    string password_Input;
    cout<<"\n Enter Username : ";
    cin>>username_Input;
    cout<<"\n Enter Password : ";
    cin>>password_Input;
    if (Check_Customer(username_Input,password_Input) == 1)
    {
        //cout<<"Customer found :) \n";
        system("CLS");
        Main_Screen();
    }

    else
    {
        cout<<"not found :{ \n";
        system("CLS");
        starting_Screen();
    }
}









void starting_Screen()
{
    int n;
    cout<<"\n\n\n--------------------------S-MART---------------------------------\n\n\n";
    cout<<"\n\n\t\t\t1 : Sign up \n\n\n\t\t\t2 : Sign in\n";
    cout<<"\n\n\n-----------------------------------------------------------------\n\n\n";
    cin>>n;
    if(n == 1)
    {
        c.push_back(Customer());
        c[c.size()-1].Sign_up();
        cout<<"Sign Up Successful \n";
        system("CLS");
        Sign_in();
    }
    else if(n == 2)
    {
        Sign_in();
    }
}

int main()
{
    Set_info();
    system("color 70");
    Saved_Users();
    starting_Screen();

    return 0;
}
