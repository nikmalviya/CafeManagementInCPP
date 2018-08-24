class UserData{
    string first_name;
    string last_name;
    string email;
    string contact_number;
    string date_of_birth;
    string city;
    long int balance;
    string password;
public:
    friend fstream& operator << (fstream&,UserData&);
    friend ofstream& operator << (ofstream&,UserData&);
    friend fstream& operator>>(fstream&,UserData&);
    friend ifstream& operator>>(ifstream&,UserData&);
    void setPassword(string pass)
    {
        password = pass;
    }
    string getPassword()
    {
        return password;
    }
    void setCity(string cty)
    {
        city=cty;
    }
    string getCity()
    {
        return city;
    }
    void setBalance(long int balance)
    {
        this->balance = balance;
    }
    long int getBalance()
    {
        return balance;
    }
    void setFirstName(string fname)
    {
        first_name=fname;
    }
    string getFirstName()
    {
        return first_name;
    }
    void setLastName(string lname)
    {
        last_name=lname;
    }
    string getLastName()
    {
        return last_name;
    }
    void setEmail(string email)
    {
        this->email=email;
    }
    string getEmail()
    {
        return email;
    }
    void setContactNumber(string contact)
    {
        contact_number=contact;
    }
    string getContactNumber()
    {
        return contact_number;
    }
    void setDateOfBirth(string dob)
    {
        date_of_birth=dob;
    }
    string getDateOfBirth()
    {
        return date_of_birth;
    }
};
ostream& space(ostream& out)
{
    out<<" ";
    return out;
}
fstream& operator << (fstream& file, UserData & user)
{
    file<<setiosflags(ios::left);
    file<<setw(10)<<user.first_name<<space<<setw(10)<<user.last_name<<space<<setw(25)<<user.email<<space<<setw(10)<<user.password<<space<<setw(10)<<user.balance<<space<<setw(10)<<user.contact_number<<space<<setw(10)<<user.date_of_birth<<space<<setw(10)<<user.city<<endl;
    return file;
}
ofstream& operator << (ofstream& fout, UserData &user)
{
    fout<<setiosflags(ios::left);
    fout<<setw(10)<<user.first_name<<space<<setw(10)<<user.last_name<<space<<setw(25)<<user.email<<space<<setw(10)<<user.password<<space<<setw(10)<<user.balance<<space<<setw(10)<<user.contact_number<<space<<setw(10)<<user.date_of_birth<<space<<setw(10)<<user.city<<endl;
    return fout;
}
fstream& operator>>(fstream& file,UserData & user)
{
    file>>user.first_name>>user.last_name>>user.email>>user.password>>user.balance>>user.contact_number>>user.date_of_birth>>user.city;
    return file;
}
ifstream& operator>>(ifstream& fin ,UserData & user)
{
    fin>>user.first_name>>user.last_name>>user.email>>user.password>>user.balance>>user.contact_number>>user.date_of_birth>>user.city;
    return fin;
}
