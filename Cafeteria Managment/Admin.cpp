inline void borderedScreen1()
{
        Shape box;
        box.drawBorderedBox(3,1,119,28,Utility::WHITE,Utility::CYAN);
}
class Admin{
public:
    void admin_menu();
    void admin_menu_program();
    void product_program();
    void user_program();
    void set_products(string,int);
    void catagory_select(int);
    void product_select(int,int);
    void get_product_data(int,int,int);
    void get_product(int);
    void clear_products();
    void reset_products();
    void show_quantity(int catagory_code);
    void show_price(int catagory_code);
    void show_discount(int catagory_code);
    void display_all();
    void catagory_select();
    void get_products(int);
    void view_all_users();
    void delete_user();
    void view_transactions();
    void view_orders();
    void delete_database();
    void admin_login();
};
void Admin::delete_database()
{
        borderedScreen1();
        Widget wdg;
        TextEffects text;
        Utility::hidecursor();
        wdg.dialogBox(" -: DELETE DATABASE :- ",35,8,80,19,Utility::BLACK,Utility::GREY);
        Utility::setColor(15);
        text.typingText(string(" -: DELETE DATABASE :- "),47,12,20);
        Utility::setColor(0);
        Utility::setBackgroundColor(Utility::GREY);
        gotoxy(43,14);
        cout<<" DO YOU REALLY WANT TO DELETE ";
        gotoxy(48,16);
        wdg.label(" CANCEL ",Utility::WHITE,Utility::CYAN);
        gotoxy(59,16);
        wdg.label(" CONFIRM ",Utility::WHITE,Utility::CYAN);
        int key_counter=0,input_validate=0;
        while(true)
        {
            switch(key_counter)
            {
                case 0:
                    gotoxy(59,16);
                    wdg.label(" CONFIRM ",Utility::WHITE,Utility::CYAN);
                    gotoxy(48,16);
                    wdg.label(" CANCEL ",Utility::RED,Utility::WHITE);
                    if(input_validate==1)
                    {
                        input_validate=0;
                        admin_menu();
                        admin_menu_program();
                    }
                    break;
                case 1:
                    gotoxy(48,16);
                    wdg.label(" CANCEL ",Utility::WHITE,Utility::CYAN);
                    gotoxy(59,16);
                    wdg.label(" CONFIRM ",Utility::RED,Utility::WHITE);
                    if(input_validate==2)
                    {
                        input_validate=0;
                        wdg.drawSolidBox(35,8,77,19,Utility::GREY);
                        wdg.drawBorderedBox(37,9,78,18,0,Utility::GREY);
                        Utility::setColor(0);
                        Utility::setBackgroundColor(Utility::GREY);
                        gotoxy(48,15);
                        cout<<" DELETE DATABASE ";
                        gotoxy(52,13);
                        Utility::hidecursor();
                        cout<<"DELETING";
                        char dots[]="...";
                        for(char a:dots)
                        {
                            Sleep(1000);
                            cout<<a;
                        }
                        remove("UserData.txt");
                        remove("Transactions.txt");
                        remove("Orders.txt");
                        wdg.drawBorderedBox(37,9,78,18,0,Utility::GREY);
                        Utility::setColor(0);
                        Utility::setBackgroundColor(Utility::GREY);
                        gotoxy(44,14);
                        cout<<" DATA DELETED SUCCESSFULLY ";
                        Utility::hidecursor();
                        Sleep(1000);
                        admin_menu();
                        admin_menu_program();
                    }
                    break;
                default:
                    break;
                }
                if(kbhit())
                {
                    int key = Utility::getkey();
                    if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                    {
                        if(key==Utility::KEY_TAB)
                            key_counter++;
                        else
                        {
                            if(key==Utility::KEY_ENTER&&key_counter==0)
                                input_validate++;
                            else if(key==Utility::KEY_ENTER&&key_counter==1)
                                input_validate+=2;
                        }
                    }
                    if(key_counter>1)
                        key_counter=0;
                }
            }
}
void Admin::view_orders()
{
    Widget wdg;
    Utility::hidecursor();
    borderedScreen1();
    wdg.dialogBox(" -: VIEW ALL ORDERS :- ",15,3,105,26,0,7);
    TextEffects txefft;
    txefft.typingText(string(" -: ALL ORDERS :- "),50,7,20);
    Utility::setBackgroundColor(7);
    Utility::setColor(4);
    gotoxy(25,9);
    cout<<" DATE ";
    gotoxy(37,9);
    cout<<" TIME ";
    gotoxy(48,9);
    cout<<" USERNAME ";
    gotoxy(60,9);
    cout<<" PRODUCT NAME ";
    gotoxy(74,9);
    cout<<" QUANTITY ";
    gotoxy(85,9);
    cout<<" AMOUNT ";
    Order order;
    ifstream fin("Orders.txt");
    int y=11;
    Utility::setColor(0);
    while(fin>>order)
    {
            gotoxy(24,y);
            cout<<setfill('0');
            cout<<setw(2)<<order.day<<'/'<<setw(2)<<order.month<<'/'<<order.year;
            gotoxy(37,y);
            cout<<setw(2)<<order.hour<<':'<<setw(2)<<order.minute<<ends<<order.suffix;
            gotoxy(49,y);
            cout<<order.email;
            gotoxy(62,y);
            cout<<order.product;
            gotoxy(78,y);
            cout<<order.quantity;
            gotoxy(86,y);
            cout<<"RS "<<order.price;
            y++;
            if(y>22)
            {
                gotoxy(55,24);
                wdg.label(" NEXT PAGE ",4,15);
                getch();
                wdg.dialogBox(" -: VIEW ALL ORDERS :- ",15,3,105,26,0,7);
                txefft.typingText(string(" -: ALL ORDERS :- "),50,7,20);
                Utility::setBackgroundColor(7);
                Utility::setColor(4);
                gotoxy(25,9);
                cout<<" DATE ";
                gotoxy(37,9);
                cout<<" TIME ";
                gotoxy(48,9);
                cout<<" USERNAME ";
                gotoxy(60,9);
                cout<<" PRODUCT NAME ";
                gotoxy(74,9);
                cout<<" QUANTITY ";
                gotoxy(85,9);
                cout<<" AMOUNT ";
                Utility::setColor(0);
                y=11;
            }
    }
    gotoxy(55,y+1);
    wdg.label(" MAIN MENU ",4,15);
    getch();
    fin.close();
    admin_menu();
    admin_menu_program();
}
void Admin::view_transactions()
{
    Widget wdg;
    Utility::hidecursor();
    borderedScreen1();
    wdg.dialogBox(" -: VIEW TRANSACTIONS :- ",15,3,105,26,0,7);
    TextEffects txefft;
    txefft.typingText(string(" -: TRANSACTIONS :- "),50,7,20);
    Utility::setBackgroundColor(7);
    Utility::setColor(4);
    gotoxy(22,9);
    cout<<" DATE ";
    gotoxy(32,9);
    cout<<" TIME ";
    gotoxy(41,9);
    cout<<" USERNAME ";
    gotoxy(52,9);
    cout<<" PREV. AMOUNT ";
    gotoxy(66,9);
    cout<<" TYPE ";
    gotoxy(72,9);
    cout<<" TRANS. AMOUNT ";
    gotoxy(87,9);
    cout<<" FINAL AMOUNT ";
    Transaction order;
    ifstream fin("Transactions.txt");
    int y=11;
    string type;
    Utility::setColor(0);
    while(fin>>order)
    {
            if(order.final_amt>order.previous_balance)
                type="Cr";
            else if(order.final_amt<order.previous_balance)
                    type="Dr";
            gotoxy(21,y);
            cout<<order.day<<'/'<<order.month<<'/'<<order.year;
            gotoxy(32,y);
            cout<<order.hour<<':'<<order.minute<<ends<<order.suffix;
            gotoxy(42,y);
            cout<<order.email;
            gotoxy(55,y);
            cout<<"RS "<<order.previous_balance;
            gotoxy(66,y);
            cout<<type;
            gotoxy(72,y);
            cout<<"RS "<<order.amount;
            gotoxy(87,y);
            cout<<"RS "<<order.final_amt;
            y++;
            if(y>22)
            {
                gotoxy(55,24);
                wdg.label(" NEXT PAGE ",4,15);
                getch();
                wdg.dialogBox(" -: VIEW TRANSACTIONS :- ",15,3,105,26,0,7);
                txefft.typingText(string(" -: TRANSACTIONS :- "),50,7,20);
                Utility::setBackgroundColor(7);
                Utility::setColor(4);
                gotoxy(22,9);
                cout<<" DATE ";
                gotoxy(32,9);
                cout<<" TIME ";
                gotoxy(41,9);
                cout<<" USERNAME ";
                gotoxy(52,9);
                cout<<" PREV. AMOUNT ";
                gotoxy(61,9);
                cout<<" TYPE ";
                gotoxy(70,9);
                cout<<" TRANS. AMOUNT ";
                gotoxy(85,9);
                cout<<" FINAL AMOUNT ";
                Utility::setColor(0);
                y=11;
            }

    }
    gotoxy(55,y+1);
    wdg.label(" MAIN MENU ",4,15);
    getch();
    fin.close();
    admin_menu();
    admin_menu_program();
}
void Admin::delete_user()
{
    Utility::hidecursor();
    borderedScreen1();
        Widget wdg;
        wdg.dialogBox(" -: DELETE USER :- ",35,10,80,21,Utility::BLACK,Utility::GREY);
        TextEffects text;
        text.typingText(" -: DELETE USER :- ",47,14,20);
        gotoxy(39,16);
        wdg.label(" ENTER USERNAME :::",Utility::BLACK,Utility::GREY);
        gotoxy(59,16);
        wdg.textBox(16);
        gotoxy(47,18);
        wdg.label(" DELETE ",Utility::WHITE,Utility::CYAN);
        gotoxy(58,18);
        wdg.label(" CANCEL ",Utility::WHITE,Utility::CYAN);
        int key_counter=0,input_validate=0;
        gotoxy(60,16);
        Utility::showcursor();
        Utility::setBackgroundColor(15);
        Utility::setColor(0);
        string email;
        cin>>email;
        Utility::hidecursor();
        while(true)
        {
            switch(key_counter)
            {
            case 0:
                gotoxy(58,18);
                wdg.label(" CANCEL ",Utility::WHITE,Utility::CYAN);
                gotoxy(47,18);
                wdg.label(" DELETE ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    UserData user;
                    input_validate=0;
                    int count=0;
                    ifstream fin("UserData.txt");
                    ofstream fout("temp.txt");
                    while(fin>>user)
                    {
                        if(email==user.getEmail())
                        {
                            count++;
                            continue;
                        }
                        fout<<user;
                    }
                    fin.close();
                    fout.close();
                    if(count==0)
                    {
                        wdg.alertBox(" USER DOES NOT EXIST ",40,10,75,19,0,15);
                        remove("temp.txt");
                        delete_user();
                    }
                    fin.open("temp.txt");
                    fout.open("UserData.txt");
                    while(fin>>user)
                        fout<<user;
                    fout.close();
                    fin.close();
                    wdg.alertBox(" USER DELETED SUCCESSFULLY ",40,10,75,19,0,15);
                    admin_menu();
                    admin_menu_program();
                }
                break;
            case 1:
                gotoxy(47,18);
                wdg.label(" DELETE ",Utility::WHITE,Utility::CYAN);
                gotoxy(58,18);
                wdg.label(" CANCEL ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    admin_menu();
                    admin_menu_program();
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                {
                    if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                    }
                }
                if(key_counter>1)
                    key_counter=0;
            }
        }
}
void Admin::view_all_users()
{
    Widget wdg;
    Utility::hidecursor();
    borderedScreen1();
    wdg.dialogBox(" -: VIEW ALL USERS :- ",15,3,105,26,0,7);
    TextEffects txefft;
    txefft.typingText(string(" -: ALL USERS :- "),50,7,20);
    Utility::setBackgroundColor(7);
    Utility::setColor(4);
    gotoxy(22,9);
    cout<<" FIRST NAME  ";
    gotoxy(38,9);
    cout<<" LAST NAME ";
    gotoxy(53,9);
    cout<<" USERNAME ";
    gotoxy(68,9);
    cout<<" BALANCE ";
    gotoxy(81,9);
    cout<<" CONTACT NO. ";
    UserData data;
    ifstream fin("UserData.txt");
    int y=11;
    Utility::setColor(0);
    while(fin>>data)
    {
            gotoxy(24,y);
            cout<<data.getFirstName();
            gotoxy(40,y);
            cout<<data.getLastName();
            gotoxy(53,y);
            cout<<data.getEmail();
            gotoxy(68,y);
            cout<<"RS "<<data.getBalance();
            gotoxy(82,y);
            cout<<data.getContactNumber();
            y+=2;
            if(y>22)
            {
                gotoxy(55,24);
                wdg.label(" NEXT PAGE ",4,15);
                getch();
                wdg.dialogBox(" -: VIEW ALL USERS :- ",15,3,105,26,0,7);
                txefft.typingText(string(" -: ALL USERS :- "),50,7,20);
                Utility::setBackgroundColor(7);
                Utility::setColor(4);
                gotoxy(22,9);
                cout<<" FIRST NAME  ";
                gotoxy(38,9);
                cout<<" LAST NAME ";
                gotoxy(53,9);
                cout<<" USERNAME ";
                gotoxy(68,9);
                cout<<" BALANCE ";
                gotoxy(81,9);
                cout<<" CONTACT NO. ";
                Utility::setColor(0);
                y=11;
            }

    }
    gotoxy(53,y+1);
    wdg.label(" ADMIN MENU ",4,15);
    getch();
    fin.close();
    admin_menu();
}
void Admin::get_products(int catagory_code)
{
    string products[4][5];
    products[0][0]="PIZZA       ";
    products[0][1]="BURGER      ";
    products[0][2]="SANDWITCH   ";
    products[0][3]="VADAPAV     ";
    products[0][4]="DABELI      ";
    products[2][4]="CHOCOCHIPS  ";
    products[2][0]="VANILLA     ";
    products[2][1]="CHOCOLATE   ";
    products[2][2]="STRAWBERRY  ";
    products[2][3]="RAJBHOG     ";
    products[1][0]="PEPSI       ";
    products[1][1]="MOUNT.DEW   ";
    products[1][2]="THUMBS_UP   ";
    products[1][3]="SLICE       ";
    products[1][4]="SPRITE      ";
    products[3][0]="LAYS        ";
    products[3][1]="KUKURE      ";
    products[3][2]="SOLID_MASTI ";
    products[3][3]="OREO        ";
    products[3][4]="CHEETOS     ";
    Utility::setBackgroundColor(7);
    Utility::setColor(0);
    int yco=13;
    for(int i=0;i<5;i++)
    {
        gotoxy(27,yco);
        cout<<products[catagory_code-1][i];
        yco+=2;
    }
    yco=13;
    Product p;
    ifstream fin("Products.txt");
    while(fin>>p)
    {
        if(catagory_code==p.getCatagoryCode())
        {
            gotoxy(51,yco);
            cout<<"   ";
            gotoxy(51,yco);
            cout<<p.getQuantity();
            gotoxy(66,yco);
            cout<<"   ";
            gotoxy(66,yco);
            cout<<p.getDiscount()<<"%";
            gotoxy(81,yco);
            cout<<"    ";
            gotoxy(78,yco);
            cout<<"RS "<<p.getPrice();
            yco+=2;
        }
    }
    fin.close();
}
void Admin::catagory_select()
{
    Widget w;
    int key_counter=0,input_validate=0;
    while(true)
    {
        Utility::hidecursor();
        switch(key_counter)
        {
            case 0:
                gotoxy(71,9);
                w.label(" SNACKS ",Utility::WHITE,Utility::CYAN);
                gotoxy(36,9);
                w.label(" FAST-FOOD ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    get_products(1);

                }
                break;
            case 1:
                gotoxy(36,9);
                w.label(" FAST-FOOD ",Utility::WHITE,Utility::CYAN);
                gotoxy(47,9);
                w.label(" ICE-CREAM ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    get_products(3);

                }
                break;
            case 2:
                gotoxy(47,9);
                w.label(" ICE-CREAM ",Utility::WHITE,Utility::CYAN);
                gotoxy(58,9);
                w.label(" COLD-DRINKS ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    get_products(2);

                }
                break;
            case 3:
                gotoxy(58,9);
                w.label(" COLD-DRINKS ",Utility::WHITE,Utility::CYAN);
                gotoxy(71,9);
                w.label(" SNACKS ",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    get_products(4);

                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_HOME)
                {
                    if(key==Utility::KEY_HOME)
                    {
                        admin_menu();
                        admin_menu_program();
                    }
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;

                    }
                }
                if(key_counter>3)
                    key_counter=0;
            }
        }
}
void Admin::display_all()
{
    borderedScreen1();
    Utility::hidecursor();
    Widget w;
    TextEffects text;
    w.dialogBox(" -: ALL ITEMS :- ",18,5,97,26,0,7);
    gotoxy(33,9);
    w.label(" -: FAST-FOOD ",15,Utility::CYAN);
    gotoxy(47,9);
    w.label(" ICE-CREAM ",15,Utility::CYAN);
    gotoxy(58,9);
    w.label(" COLD-DRINKS ",15,Utility::CYAN);
    gotoxy(71,9);
    w.label(" SNACKS :- ",15,Utility::CYAN);
    gotoxy(27,11);
    Utility::setColor(4);
    Utility::setBackgroundColor(7);
    cout<<"PRODUCT NAME";
    gotoxy(47,11);
    cout<<" QUANTITY ";
    gotoxy(62,11);
    cout<<" DISCOUNT ";
    gotoxy(77,11);
    cout<<" PRICE ";
    catagory_select();

}
void Admin::reset_products()
{
        borderedScreen1();
        Widget wdg;
        TextEffects text;
        Utility::hidecursor();
        wdg.dialogBox(" -: RESET :- ",35,8,80,19,Utility::BLACK,Utility::GREY);
        Utility::setColor(15);
        text.typingText(string(" -: RESET PRODUCTS :- "),47,12,20);
        Utility::setColor(0);
        Utility::setBackgroundColor(Utility::GREY);
        gotoxy(43,14);
        cout<<" DO YOU REALLY WANT TO RESET ";
        gotoxy(48,16);
        wdg.label(" CANCEL ",Utility::WHITE,Utility::CYAN);
        gotoxy(59,16);
        wdg.label(" CONFIRM ",Utility::WHITE,Utility::CYAN);
        int key_counter=0,input_validate=0;
        while(true)
        {
            switch(key_counter)
            {
                case 0:
                    gotoxy(59,16);
                    wdg.label(" CONFIRM ",Utility::WHITE,Utility::CYAN);
                    gotoxy(48,16);
                    wdg.label(" CANCEL ",Utility::RED,Utility::WHITE);
                    if(input_validate==1)
                    {
                        input_validate=0;
                        admin_menu();
                        admin_menu_program();
                    }
                    break;
                case 1:
                    gotoxy(48,16);
                    wdg.label(" CANCEL ",Utility::WHITE,Utility::CYAN);
                    gotoxy(59,16);
                    wdg.label(" CONFIRM ",Utility::RED,Utility::WHITE);
                    if(input_validate==2)
                    {
                        input_validate=0;
                        wdg.drawSolidBox(35,8,77,19,Utility::GREY);
                        wdg.drawBorderedBox(37,9,78,18,0,Utility::GREY);
                        Utility::setColor(0);
                        Utility::setBackgroundColor(Utility::GREY);
                        gotoxy(48,15);
                        cout<<"RESET YOUR PRODUCTS";
                        gotoxy(53,13);
                        Utility::hidecursor();
                        cout<<"RESETTING";
                        char dots[]="...";
                        for(char a:dots)
                        {
                            Sleep(1000);
                            cout<<a;
                        }
                        Product p;
                        ofstream fout;
                        ifstream fin;
                        fin.open("Products.txt");
                        fout.open("temp.txt");
                        while(fin>>p)
                        {
                            p.setDiscount(0);
                            p.setPrice(0);
                            p.setQuantity(0);
                            fout<<p;
                        }
                        fin.close();
                        fout.close();
                        fin.open("temp.txt");
                        fout.open("Products.txt");
                        while(fin>>p)
                            fout<<p;
                        fin.close();
                        fout.close();
                        remove("temp.txt");
                        wdg.drawBorderedBox(37,9,78,18,0,Utility::GREY);
                        Utility::setColor(0);
                        Utility::setBackgroundColor(Utility::GREY);
                        gotoxy(44,14);
                        cout<<" PRODUCT RESET SUCCESSFULL ";
                        Utility::hidecursor();
                        Sleep(1000);
                        admin_menu();
                        admin_menu_program();
                    }
                    break;
                default:
                    break;
                }
                if(kbhit())
                {
                    int key = Utility::getkey();
                    if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                    {
                        if(key==Utility::KEY_TAB)
                            key_counter++;
                        else
                        {
                            if(key==Utility::KEY_ENTER&&key_counter==0)
                                input_validate++;
                            else if(key==Utility::KEY_ENTER&&key_counter==1)
                                input_validate+=2;
                        }
                    }
                    if(key_counter>1)
                        key_counter=0;
                }
            }

}
void Admin::show_quantity(int catagory_code)
{
    int y=13;
    Product product;
    Utility::setColor(0);
    Utility::setBackgroundColor(15);
    ifstream fin("Products.txt");
    while(fin>>product)
    {
        if(catagory_code==product.getCatagoryCode())
        {
            gotoxy(56,y);
            cout<<"   ";
            gotoxy(56,y);
            cout<<product.getQuantity();
            y+=2;
        }
    }
    fin.close();
}
void Admin::show_discount(int catagory_code)
{
    int y=13;
    Product product;
    Utility::setColor(0);
    Utility::setBackgroundColor(15);
    ifstream fin("Products.txt");
    while(fin>>product)
    {
        if(catagory_code==product.getCatagoryCode())
        {
            gotoxy(55,y);
            cout<<"    ";
            gotoxy(55,y);
            cout<<product.getDiscount()<<"%";
            y+=2;
        }
    }
    fin.close();
}
void Admin::show_price(int catagory_code)
{
    int y=13;
    Product product;
    Utility::setColor(0);
    Utility::setBackgroundColor(15);
    ifstream fin("Products.txt");
    while(fin>>product)
    {
        if(catagory_code==product.getCatagoryCode())
        {
            gotoxy(56,y);
            cout<<"    ";
            gotoxy(53,y);
            cout<<"RS "<<product.getPrice();
            y+=2;
        }
    }
    fin.close();
}
void Admin::get_product(int catagory_code)
{
    string products[4][5];
    products[0][0]="PIZZA       ";
    products[0][1]="BURGER      ";
    products[0][2]="SANDWITCH   ";
    products[0][3]="VADAPAV     ";
    products[0][4]="DABELI      ";
    products[2][4]="CHOCOCHIPS  ";
    products[2][0]="VANILLA     ";
    products[2][1]="CHOCOLATE   ";
    products[2][2]="STRAWBERRY  ";
    products[2][3]="RAJBHOG     ";
    products[1][0]="PEPSI       ";
    products[1][1]="MOUNT.DEW   ";
    products[1][2]="THUMBS_UP   ";
    products[1][3]="SLICE       ";
    products[1][4]="SPRITE      ";
    products[3][0]="LAYS        ";
    products[3][1]="KUKURE      ";
    products[3][2]="SOLID_MASTI ";
    products[3][3]="OREO        ";
    products[3][4]="CHEETOS     ";
    Utility::setBackgroundColor(7);
    Utility::setColor(0);
    int yco=13;
    for(int i=0;i<5;i++)
    {
        gotoxy(37,yco);
        cout<<products[catagory_code-1][i];
        yco+=2;
    }
}
void Admin::get_product_data(int product_code,int catagory_code,int type)
{

    int data;
    Widget wdg;
    int y = product_code*2;
    y+=11;
    error:
    Utility::setColor(0);
    Utility::setBackgroundColor(15);
    tag:
    gotoxy(68,y);
    cout<<"   ";
    gotoxy(68,y);
    Utility::showcursor();
    cin>>data;
//    if(!cin.good())
//    {
//        gotoxy(63,12);
//        wdg.label(" Enter Only Numbers ",15,4);
//        cin.clear();
//        goto tag;
//
//    }
    Utility::hidecursor();
    ifstream fin("Products.txt");
    Product p;
    while(fin>>p)
    {
        if(p.getCatagoryCode()==catagory_code&&p.getProductCode()==product_code)
            break;
    }
    fin.close();
    gotoxy(80,y);
    wdg.label(" + ",Utility::RED,Utility::WHITE);
    getch();
    ofstream fout;
    fin.open("Products.txt");
    fout.open("temp.txt");
    switch(type)
    {
    case 1:
        while(fin>>p)
        {
            if(p.getCatagoryCode()==catagory_code&&p.getProductCode()==product_code)
                p.setQuantity(p.getQuantity()+data);
            fout<<p;
        }
        break;
    case 2:
        while(fin>>p)
        {
            if(p.getCatagoryCode()==catagory_code&&p.getProductCode()==product_code)
                p.setPrice(p.getPrice()+data);
            fout<<p;
        }
        break;
    case 3:
        while(fin>>p)
        {
            if(p.getCatagoryCode()==catagory_code&&p.getProductCode()==product_code)
                p.setDiscount(p.getDiscount()+data);
            fout<<p;
        }
        break;
    default:
        break;
    }
    fin.close();
    fout.close();
    fin.open("temp.txt");
    fout.open("Products.txt");
    while(fin>>p)
        fout<<p;
    fin.close();
    fout.close();
    remove("temp.txt");
    switch(type)
    {
    case 1:
        show_quantity(catagory_code);
        break;
    case 2:
        show_price(catagory_code);
        break;
    case 3:
        show_discount(catagory_code);
        break;
    }
    gotoxy(80,y);
    wdg.label(" + ",Utility::WHITE,Utility::CYAN);
}
void Admin::product_select(int catagory_code,int type)
{
    Widget wdg;
   int key_counter=0,input_validate=0;
    while(true)
    {
        Utility::hidecursor();
        switch(key_counter)
        {
            case 0:
                gotoxy(31,21);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(31,13);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    get_product_data(1,catagory_code,type);
                }
                break;
            case 1:
                gotoxy(31,13);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(31,15);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    get_product_data(2,catagory_code,type);
                }
                break;
            case 2:
                gotoxy(31,15);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(31,17);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    get_product_data(3,catagory_code,type);
                }
                break;
            case 3:
                gotoxy(31,17);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(31,19);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    get_product_data(4,catagory_code,type);
                }
                break;
            case 4:
                gotoxy(31,19);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(31,21);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==5)
                {
                    input_validate=0;
                    get_product_data(5,catagory_code,type);
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_ESCAPE)
                {
                    if(key==Utility::KEY_ESCAPE)
                    {
                        catagory_select(type);
                    }
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;
                        else if(key==Utility::KEY_ENTER&&key_counter==4)
                            input_validate+=5;
                    }
                }
                if(key_counter>4)
                    key_counter=0;
            }
        }
}
void Admin::catagory_select(int type)
{
    Widget w;
    int key_counter=0,input_validate=0;
    while(true)
    {
        Utility::hidecursor();
        switch(key_counter)
        {
            case 0:
                gotoxy(71,9);
                w.label(" SNACKS ",Utility::WHITE,Utility::CYAN);
                gotoxy(36,9);
                w.label(" FAST-FOOD ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    get_product(1);
                    switch(type)
                    {
                    case 1:
                        show_quantity(1);
                        product_select(1,1);
                        break;
                    case 2:
                        show_price(1);
                        product_select(1,2);
                        break;
                    case 3:
                        show_discount(1);
                        product_select(1,3);
                        break;
                    default:
                        break;
                    }

                }
                break;
            case 1:
                gotoxy(36,9);
                w.label(" FAST-FOOD ",Utility::WHITE,Utility::CYAN);
                gotoxy(47,9);
                w.label(" ICE-CREAM ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    get_product(3);
                    switch(type)
                    {
                    case 1:
                        show_quantity(2);
                        product_select(2,1);
                        break;
                    case 2:
                        show_price(2);
                        product_select(2,2);
                        break;
                    case 3:
                        show_discount(2);
                        product_select(2,3);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 2:
                gotoxy(47,9);
                w.label(" ICE-CREAM ",Utility::WHITE,Utility::CYAN);
                gotoxy(58,9);
                w.label(" COLD-DRINKS ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    get_product(2);
                    switch(type)
                    {
                    case 1:
                        show_quantity(3);
                        product_select(3,1);
                        break;
                    case 2:
                        show_price(3);
                        product_select(3,2);
                        break;
                    case 3:
                        show_discount(3);
                        product_select(3,3);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 3:
                gotoxy(58,9);
                w.label(" COLD-DRINKS ",Utility::WHITE,Utility::CYAN);
                gotoxy(71,9);
                w.label(" SNACKS ",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    get_product(4);
                    switch(type)
                    {
                    case 1:
                        show_quantity(4);
                        product_select(4,1);
                        break;
                    case 2:
                        show_price(4);
                        product_select(4,2);
                        break;
                    case 3:
                        show_discount(4);
                        product_select(4,3);
                        break;
                    default:
                        break;
                    }
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_HOME)
                {
                    if(key==Utility::KEY_HOME)
                    {
                        admin_menu();
                        admin_menu_program();
                    }
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;

                    }
                }
                if(key_counter>3)
                    key_counter=0;
            }
        }
}
void Admin::set_products(string title,int code)
{
    borderedScreen1();
    Utility::hidecursor();
    Widget w;
    TextEffects text;
    w.dialogBox(title.c_str(),25,5,90,26,0,7);
    gotoxy(33,9);
    w.label(" -: FAST-FOOD ",15,Utility::CYAN);
    gotoxy(47,9);
    w.label(" ICE-CREAM ",15,Utility::CYAN);
    gotoxy(58,9);
    w.label(" COLD-DRINKS ",15,Utility::CYAN);
    gotoxy(71,9);
    w.label(" SNACKS :- ",15,Utility::CYAN);
    gotoxy(37,11);
    Utility::setColor(4);
    Utility::setBackgroundColor(7);
    cout<<"PRODUCT NAME";
    gotoxy(52,11);
    cout<<" CURRENT ";
    gotoxy(67,11);
    cout<<" NEW ";
    gotoxy(31,13);
    w.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(31,15);
    w.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(31,17);
    w.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(31,19);
    w.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(31,21);
    w.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(55,13);
    w.textBox(4);
    gotoxy(55,15);
    w.textBox(4);
    gotoxy(55,17);
    w.textBox(4);
    gotoxy(55,19);
    w.textBox(4);
    gotoxy(55,21);
    w.textBox(4);
    gotoxy(68,13);
    w.textBox(4);
    gotoxy(68,15);
    w.textBox(4);
    gotoxy(68,17);
    w.textBox(4);
    gotoxy(68,19);
    w.textBox(4);
    gotoxy(68,21);
    w.textBox(4);
    gotoxy(80,13);
    w.label(" + ",Utility::WHITE,Utility::CYAN);
    gotoxy(80,15);
    w.label(" + ",Utility::WHITE,Utility::CYAN);
     gotoxy(80,17);
    w.label(" + ",Utility::WHITE,Utility::CYAN);
    gotoxy(80,19);
    w.label(" + ",Utility::WHITE,Utility::CYAN);
    gotoxy(80,21);
    w.label(" + ",Utility::WHITE,Utility::CYAN);
    catagory_select(code);
}
void Admin::product_program()
{
    Widget wdg;
    int key_counter=0,input_validate=0;
    while(true)
    {
        Utility::hidecursor();
        switch(key_counter)
        {
            case 0:
                gotoxy(22,21);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(22,13);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    display_all();
                }
                break;
            case 1:
                gotoxy(22,13);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(22,15);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    set_products(" -: SET QUANTITY :- ",1);
                }
                break;
            case 2:
                gotoxy(22,15);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(22,17);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    set_products(" -: SET PRICE :- ",2);
                }
                break;
            case 3:
                gotoxy(22,17);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(22,19);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    set_products(" -: SET DISCOUNT :- ",3);
                }
                break;
            case 4:
                gotoxy(22,19);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(22,21);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==5)
                {
                    input_validate=0;
                    reset_products();
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_ESCAPE)
                {
                    if(key==Utility::KEY_ESCAPE)
                        admin_menu_program();
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;
                        else if(key==Utility::KEY_ENTER&&key_counter==4)
                            input_validate+=5;
                    }
                }
                if(key_counter>4)
                    key_counter=0;
            }
        }
}
//void Admin::admin_menu_program()
//{
//    Widget wdg;
//    int key_counter=0,input_validate=0;
//    while(true)
//    {
//        Utility::hidecursor();
//        switch(key_counter)
//        {
//            case 0:
//                gotoxy(69,8);
//                wdg.label("-: USER DETAILS :-",Utility::WHITE,Utility::CYAN);
//                gotoxy(14,8);
//                wdg.label("-: PRODUCTS DETAILS :-",Utility::RED,Utility::WHITE);
//                if(input_validate==1)
//                {
//                    input_validate=0;
//                    product_program();
//                }
//                break;
//            case 1:
//                gotoxy(14,8);
//                wdg.label("-: PRODUCTS DETAILS :-",Utility::WHITE,Utility::CYAN);
//                gotoxy(69,8);
//                wdg.label("-: USER DETAILS :-",Utility::RED,Utility::WHITE);
//                if(input_validate==2)
//                {
//                    input_validate=0;
//                    user_program();
//                }
//                break;
//            default:
//                break;
//            }
//            if(kbhit())
//            {
//                int key = Utility::getkey();
//                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==KEY_HOME)
//                {
//                    if(key==Utility::KEY_HOME)
//                    {
//                        MainMenu menu;
//                        menu.main_menu_layout();
//                        menu.main_menu_program();
//                    }
//                   else if(key==Utility::KEY_TAB)
//                        key_counter++;
//                    else
//                    {
//                        if(key==Utility::KEY_ENTER&&key_counter==0)
//                            input_validate++;
//                        else if(key==Utility::KEY_ENTER&&key_counter==1)
//                            input_validate+=2;
//                    }
//                }
//                if(key_counter>1)
//                    key_counter=0;
//            }
//        }
//}
void Admin::user_program()
{
    Widget wdg;
    int key_counter=0,input_validate=0;
    while(true)
    {
        Utility::hidecursor();
        switch(key_counter)
        {
            case 0:
                gotoxy(75,21);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(75,13);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    view_all_users();
                }
                break;
            case 1:
                gotoxy(75,13);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(75,15);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    delete_user();
                }
                break;
            case 2:
                gotoxy(75,15);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(75,17);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    view_transactions();
                }
                break;
            case 3:
                gotoxy(75,17);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(75,19);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    view_orders();
                }
                break;
            case 4:
                gotoxy(75,19);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(75,21);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==5)
                {
                    input_validate=0;
                    delete_database();
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_ESCAPE)
                {
                    if(key==Utility::KEY_ESCAPE)
                    {
                        admin_menu_program();
                    }
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;
                        else if(key==Utility::KEY_ENTER&&key_counter==4)
                            input_validate+=5;
                    }
                }
                if(key_counter>4)
                    key_counter=0;
            }
        }
}
void Admin::admin_menu()
{
    //system("COLOR 3f");
    borderedScreen1();
    Widget wdg;
    Shape shape;
    Utility::hidecursor();
    shape.drawSolidBox(7,2,115,5,7);
    shape.drawBorderedBox(9,2,113,5,0,7);
    wdg.dialogBox(" -: PRODUCTS DETAILS :- ",7,6,60,27,0,7);
    wdg.dialogBox(" -: USER DETAILS :- ",62,6,115,27,0,7);
    gotoxy(22,13);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(30,13);
    wdg.label(" ALL ITEMS ",Utility::BLACK,Utility::GREY);
    gotoxy(22,15);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(30,15);
    wdg.label(" SET QUANTITY ",Utility::BLACK,Utility::GREY);
    gotoxy(22,17);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(30,17);
    wdg.label(" SET PRICE ",Utility::BLACK,Utility::GREY);
    gotoxy(22,19);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(30,19);
    wdg.label(" SET DISCOUNT ",Utility::BLACK,Utility::GREY);
    gotoxy(22,21);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(30,21);
    wdg.label(" RESET PRODUCTS ",Utility::BLACK,Utility::GREY);
    gotoxy(75,13);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(82,13);
    wdg.label(" VIEW ALL USERS ",Utility::BLACK,Utility::GREY);
    gotoxy(75,15);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(82,15);
    wdg.label(" DELETE USERS ",Utility::BLACK,Utility::GREY);
    gotoxy(75,17);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(82,17);
    wdg.label(" VIEW TRANSACTIONS ",Utility::BLACK,Utility::GREY);
    gotoxy(75,19);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(82,19);
    wdg.label(" VIEW ALL ORDERS ",Utility::BLACK,Utility::GREY);
    gotoxy(75,21);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(82,21);
    wdg.label(" DELETE DATABASE ",Utility::BLACK,Utility::GREY);
    gotoxy(12,4);
    Utility::setColor(1);
    Utility::setBackgroundColor(7);
    cout<<" WELCOME ";
    cout<<"ADMIN";
    Time time;
    gotoxy(85,4);
    Utility::setColor(1);
    time.displayTime();
    Utility::setColor(4);
    TextEffects text;
    text.typingText(string(" -: WELCOME ADMINISTRATOR :- "),45,4,10);
}
//int main()
//{
//    system("color 3f");
//    Admin adm;
////    adm.delete_database();
////    adm.view_orders();
////    adm.view_transactions();
////    adm.delete_user();
////    adm.view_all_users();
////    adm.display_all();
//    adm.admin_menu();
//    adm.admin_menu_program();
////    system("color 3f");
////    adm.reset_products();
//}
