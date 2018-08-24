class Product{
    int catagory_code;
    int product_code;
    int quantity;
    int price;
    int discount;
public:
    friend fstream& operator << (fstream&,Product&);
    friend ofstream& operator << (ofstream&,Product&);
    friend fstream& operator>>(fstream&,Product&);
    friend ifstream& operator>>(ifstream&,Product&);
    void setCatagoryCode(int code)
    {
        catagory_code = code;
    }
    int getCatagoryCode()
    {
        return catagory_code;
    }
    void setProductCode(int code)
    {
        product_code = code;
    }
    int getProductCode()
    {
        return product_code;
    }
    void setQuantity(int quant)
    {
        quantity = quant;
    }
    int getQuantity()
    {
        return quantity;
    }
    void setDiscount(int dis)
    {
        discount = dis;
    }
    int getDiscount()
    {
        return discount;
    }
    void setPrice(int pri)
    {
        price = pri;
    }
    int getPrice()
    {
        return price;
    }
};
fstream& operator << (fstream& file, Product & product)
{
    file<<setiosflags(ios::left);
    file<<setw(4)<<product.catagory_code<<space<<setw(4)<<product.product_code<<space<<setw(4)<<product.quantity<<space<<setw(4)<<product.price<<space<<setw(4)<<product.discount<<endl;
    return file;
}
ofstream& operator << (ofstream& fout, Product &product)
{
    fout<<setiosflags(ios::left);
    fout<<setw(4)<<product.catagory_code<<space<<setw(4)<<product.product_code<<space<<setw(4)<<product.quantity<<space<<setw(4)<<product.price<<space<<setw(4)<<product.discount<<endl;
    return fout;
}
fstream& operator>>(fstream& file,Product & product)
{
    file>>product.catagory_code>>product.product_code>>product.quantity>>product.price>>product.discount;
    return file;
}
ifstream& operator>>(ifstream& fin ,Product & product)
{
    fin>>product.catagory_code>>product.product_code>>product.quantity>>product.price>>product.discount;
    return fin;
}
