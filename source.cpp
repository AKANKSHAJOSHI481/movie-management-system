// Check the output in text file named P03-OOPC.txt
#include<iostream>
#include<string>
#include<time.h>
#include<iomanip>
#include <fstream>
using namespace std;

fstream new_file;
int n = 50 + rand()%50;

void Title(){
      new_file << "+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
      new_file << "|" << setw(182)<<"|"<<endl;
      new_file << "|" << right << setw(103)<<"CINEMA MANAGEMENT SYSTEM "<<setw(79)<<"|"<<endl;
      new_file << "|" << setw(182)<<"|"<<endl;
      new_file << "+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
      
}

class PhoneNumber{
    public:
    unsigned long int digit1;
    int digit2;
    int digit3;
     unsigned long int digit;
    void setPhoneNumber(int digit1, int digit2, int digit3){
        this->digit1 = digit1;
        this->digit2 = digit2;
        this->digit3 = digit3;
    }
};

class SeatNumber{
    public:
    string Alphabet1[8] ={"A","B","C","D","E","F","G","H"};
    string Alphabet2[8] = {"I","J","K","L","M","N","O","P"};
    string Alphabet3[10]={"Q","R","S","T","U","V","W","X","Y","Z"};
    string Number[26] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26"};
    string alpha1,alpha2,alpha3,num,seat_Number;
    void setSeatNumber(string SeatNumber){
        this->seat_Number = SeatNumber;
    }
    std::string getSeatNumber(){
        return seat_Number;
    }
};

class Date:public SeatNumber{
    public:
    string Datenumber[31] ={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
    string datenumber;
    string Month[31] = {"01","02","03","04","05","06","07","08","09","10","11","12"};
    string month;
    string Year[2] ={"2019","2020"};
    string year;
    string finaldate;
    void setDate(string Datenumber, string month, string year){
        this->datenumber = Datenumber;
        this->month = month;
        this->year = year;
    }
    
};

class Profile: public SeatNumber{
    public:
    string name;
    int age;
    Profile(){
        name = "";
        age = 0;
    }
    void setDetails(string getName, int getAge);
    void setName(string getName);
    void setAge(int getAge);
    std::string getName() { return name; }
    int getAge() { return age; }
    //void printDetails();
};

void Profile::setDetails(string getName, int getAge){
    this->name = getName;
    this->age = getAge;
}

void Profile::setName(string getName){
    this->name = getName;
}

void Profile:: setAge(int getAge){
    this->age = getAge;
}

class DiscountsTaxes{
    protected:
    float tax,discount;
    int price;
    float final_price;

};

class Booking : public Profile,public Date,public PhoneNumber,public DiscountsTaxes{
public:
float rating;
private:
string Name, Age , seatType, screenNumber, MovieName, genreType;
protected:
string showtime;
public:
void setShowType(string Showtime){
    showtime = Showtime;
}

std::string getShowTime(){
    return showtime;
}
void setSeatType(string Seattype);
void setscreenNumber(string Screen);
void setMoviename(string MovieName);
void setGenreType(string Genre);
void setRating(float Rating);
void setDiscount(float Discount);
void setPrice(float price);
void settax(float Tax);
void setFinal_price(float Final);

void printDetails(){
    cout << left <<"| "<< setw(20)<<name<<left << "| "<<setw(5)<<age<<left<<"| "<<setw(12)<<digit<<left<<"| "<<setw(19)<<MovieName<< left <<"| "<< setw(8)<<rating<<left<<"| "<<setw(15)<<showtime<<left<<"| "<<setw(11)<<finaldate<<left<<"| "<<setw(9)<<seatType<<left<<"| "<<setw(7)<<screenNumber<<left<<"| "<<setw(9)<<Profile::seat_Number<<left<<"| "<<setw(9)<<genreType<<left <<"| "<< setw(7)<<price<<left <<"| "<< setw(5)<<tax<<left <<"| "<< setw(2)<<discount<<"%"<< left <<" | "<< setw(12)<<final_price<<"|"<<endl;
}
void printToFile(int p);
std::string getSeatType(){
    return seatType;
}
std::string getScreenType(){
    return screenNumber;
}
std::string getMovieName(){
    return MovieName;
}
std::string getGenreType(){
    return genreType;
}
float getRating(){
    return rating;
}
float getPrice(){
    return price;
}
float getTax(){
    return tax;
}
float getDiscount(){
    return discount;
}
std::string getScreenNumber(){
    return screenNumber;
}
};

void Booking::setSeatType(string Seattype){
     seatType = Seattype;
}
void Booking::setscreenNumber(string Screen){
    screenNumber = Screen;
}
void Booking::setMoviename(string Moviename){
    MovieName = Moviename;
}
void Booking::setGenreType(string Genre){
    genreType = Genre;
}
void Booking::setRating(float Rating){
     rating = Rating;
}
void Booking::setDiscount(float Discount){
    discount = Discount;
}
void Booking::settax(float Tax){
    tax = Tax;
}
void Booking::setPrice(float Price){
    price = Price;
}
void Booking::setFinal_price(float Final){
    final_price = Final;

}


Booking* array1 = new Booking[n];


class SearchBookings : public Booking{
     public:
      void SearchByShowtime(string MovieTime);

 };

class findName : public SearchBookings{
    public:
        void searchByName(string PersonName);
 };

 class Search_By_Age :virtual public findName{
 public:
     void SearchByAge(int PersonAge);
     void SearchByAge(int minAge , int maxAge);
 };

class Search_BY_Movie:virtual public findName{
 public:
    void SearchByMovie(string SpecificMovie); 
};

class Search_By_Rating:public Search_BY_Movie{
    public:
    void SearchByRating(float rate);
};

class Search_By_Genre:public Search_By_Age,public Search_By_Rating{
public:
    void SearchByGenre(string GenreTyp);
};

void Header(){
    new_file << "+---------------------+------+-------------+--------------------+---------+----------------+------------+----------+--------+----------+----------+--------+------+-----+-------------+"<<endl;
    new_file << left << setw(22)<<"| Name"<<left << setw(7)<<"| Age"<<left<<setw(14)<<"| PhoneNumber"<<left<<setw(21)<<"| Movie Name"<<left << setw(10)<<"| Rating"<<left <<setw(17)<<"| Show time"<<left << setw(13)<<"| Date"<<left<<setw(11)<<"| SeatType"<<left<<setw(9)<<"| Screen"<<left<<setw(11)<<"| SeatNo"<<left<<setw(11)<<"| Genre"<<left << setw(9)<<"| TktPr"<<left << setw(7)<<"| Tax"<<left << setw(5)<<"| Dis"<<left << setw(15)<<" | finalPrice"<<"|"<<endl;
    new_file << "+---------------------+------+-------------+--------------------+---------+----------------+------------+----------+--------+----------+----------+--------+------+-----+-------------+"<<endl;
}

void Footer(){
      new_file << "+---------------------+------+-------------+--------------------+---------+----------------+------------+----------+--------+----------+----------+--------+------+-----+-------------+"<<endl;

}

void Booking::printToFile(int p){
    Header();
     for(int i=0;i<p;i++){
        new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
    }
    Footer();
}

void findName::searchByName(string PersonName){
    new_file << "\n---Search By Name----->" <<PersonName <<endl<<endl;
    Header();
    for(int i=0;i<n;i++){
        if(array1[i].getName() == PersonName){
             //array1[i].printDetails();
          new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
        }
    }  
Footer();
}

void Search_By_Age::SearchByAge(int PersonAge){
    new_file<<"\n\n----Search By Age ------> "<<PersonAge<< endl<<endl;
    Header();
    for(int i=0;i<n;i++){
        if(array1[i].getAge() == PersonAge){
            //array1[i].printDetails();
          new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
  
        }
    }
Footer();
}

void Search_By_Age::SearchByAge(int minAge,int maxAge){
    new_file<<"\n\n----Search Booking by a range of Age ------> "<<minAge<<","<<maxAge<< endl<<endl;
    Header();
    for(int i=0;i<n;i++){
        if(array1[i].getAge()<=maxAge && array1[i].getAge()>=minAge){
            //array1[i].printDetails();
          new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
  
        }
    }
Footer();
}

void Search_BY_Movie::SearchByMovie(string SpecificMovie){
    new_file<<"\n\n----Search By Movie ------> "<<SpecificMovie<< endl<<endl;
    Header();
    for(int i=0;i<n;i++){
        if(array1[i].getMovieName() == SpecificMovie){
             //array1[i].printDetails();
           new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
 
        }
    }
Footer();
}

void Search_By_Rating::SearchByRating(float rate){
    new_file<<"\n\n----Search By Rating ------> "<<rate<< endl<<endl;
    Header();
    for(int i=0;i<n;i++){
        if(array1[i].getRating() == rate){
             //array1[i].printDetails();
           new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
        }
    }
    Footer();
}

void SearchBookings::SearchByShowtime(string MovieTime){
    new_file<<"\n\n----Search By Show Time ------> "<<MovieTime<< endl<<endl;
    Header();
    for(int i=0;i<n;i++){
        if(array1[i].getShowTime() == MovieTime){
             //array1[i].printDetails();
           new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
        }
    }
    Footer();
}

void Search_By_Genre::SearchByGenre(string GenreTyp){
    new_file<<"\n\n----Search By Genre ------> "<<GenreTyp<< endl<<endl;
    Header();
    for(int i=0;i<n;i++){
        if(array1[i].getGenreType() == GenreTyp){
             //array1[i].printDetails();
         new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
   
        }
    }
    Footer();
}


class Modifications : public Booking{
    public:
    void ModifyByName(string oldname, string newName);
    void UpdateBookings(int p);
};

class Modify_By_Discount:public Modifications{
    public:
    void ModifyByDiscount(int oldDis, int NewDis);
};

class Modify_By_SeatNum:public Modify_By_Discount{
    public:
    void ModifyBySeatNum(string oldSeatNum, string newSeatAlpha,string newSeatNum); 
};

void Modifications::ModifyByName(string oldName,string newName){
    new_file << "\n Modifying By name :"<<oldName << " changed to "<<newName<<endl;
    Header();
    for(int i=0;i<n;i++){
        if(array1[i].getName() == oldName){
            array1[i].setName(newName);
            //array1[i].printDetails();
        new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
    
        }
    }
    Footer();
}

void Modify_By_Discount::ModifyByDiscount(int oldDis, int NewDis){
    new_file << "\n Modifying By Discount :"<<oldDis << " changed to "<<NewDis<<endl;
    Header();
    for(int i=0;i<n;i++){
        if(array1[i].getDiscount() == oldDis){
            array1[i].setDiscount(NewDis);
            array1[i].setFinal_price( array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice());
            //array1[i].printDetails();
        new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;   
        }
    }
    Footer();
}

void Modify_By_SeatNum::ModifyBySeatNum(string oldSeatNum, string newSeatAlpha, string newSeatNum){
    new_file << "\n Modifying By Seat Number :"<<oldSeatNum << " changed to "<<"-"+ newSeatAlpha + newSeatNum<<endl;
    Header();
    for(int i=0;i<n;i++){
        if(array1[i].Profile::getSeatNumber() == oldSeatNum){
            
            //array1[i].Profile::setSeatNumber(array1[i].getScreenType(),array1[i].getSeatType(),newSeatAlpha,newSeatNum);
            array1[i].Profile::setSeatNumber(array1[i].getScreenType() + "-" + array1[i].getSeatType() + "-" + newSeatAlpha + newSeatNum);
            new_file << left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::seat_Number<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
    
        }
    }
    Footer();   
}

void Modifications::UpdateBookings(int p){
    Header();
    for(int i=0;i<p;i++){
        new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
    }
    Footer();
}


class Delete_By_Name :public Booking{
     public:
     void DeleteByName(string Naum);
     void UpdateBookings(int p);
};

class Delete_By_SeatNumber: public Delete_By_Name{
   public:
   void DeleteBySeatNum(string SeatNumber);
};

void Delete_By_Name::DeleteByName(string Naum){
         new_file << "\n"<<Naum << " has been deleted"<<endl;
         int count = 0;
         for(int i=0;i<n;i++){
             if(array1[i].getName() == Naum){
                 for(int j=i; j<(n-1); j++)
                        {
                                array1[j]=array1[j+1];
                        }
                        count++;
                        break;
             }
         }
     }

void Delete_By_SeatNumber::DeleteBySeatNum(string SeatNumber){
    new_file<<"\n" << SeatNumber << " Has been deleted"<<endl;
    int count = 0;
         for(int i=0;i<n;i++){
             if(array1[i].Profile::getSeatNumber() == SeatNumber){
                 for(int j=i; j<(n-1); j++)
                        {
                                array1[j]=array1[j+1];
                        }
                        count++;
                        break;
             }
         }
}

void Delete_By_Name::UpdateBookings(int p){
     Header();
     for(int i=0;i<p;i++){
        new_file<<left <<"| "<< setw(20)<<array1[i].name<<left << "| "<<setw(5)<<array1[i].age<<left<<"| "<<setw(12)<<array1[i].digit<<left<<"| "<<setw(19)<<array1[i].getMovieName()<< left <<"| "<< setw(8)<<array1[i].rating<<left<<"| "<<setw(15)<<array1[i].getShowTime()<<left<<"| "<<setw(11)<<array1[i].finaldate<<left<<"| "<<setw(9)<<array1[i].getSeatType()<<left<<"| "<<setw(7)<<array1[i].getScreenNumber()<<left<<"| "<<setw(9)<<array1[i].Profile::getSeatNumber()<<left<<"| "<<setw(9)<<array1[i].getGenreType()<<left <<"| "<< setw(7)<<array1[i].getPrice()<<left <<"| "<< setw(5)<<array1[i].getTax()<<left <<"| "<< setw(2)<<array1[i].getDiscount()<<"%"<< left <<" | "<< setw(12)<<array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice()<<"|"<<endl;
    }
   Footer();
}



int main(){
    new_file.open("P03-OOPC.txt",ios::out);
    if(!new_file)
    {
    cout<<"File creation failed";
    }
    else
    {
    cout<<"New file created ,output will be printed in that .txt file."<<endl;
    Title();
    srand((unsigned) time(NULL));
    int minAge,maxAge;
    string firstnames[205] = {"Abigail","Alexandra","Alison","Amanda","Amelia","Amy","Andrea","Angela","Anna","Anne","Audrey","Akshu","Ava","Bella","Bernadette","Bobby","Carol","Caroline","Carolyn","Chloe","Claire","Deirdre","Diana","Diane","Donna","Dorothy","Elizabeth","Ella","Emily","Emma","Faith","Felicity","Fiona","Gabrielle","Grace","Hannah","Heather","Irene","Jan","Jane","Jasmine","Jennifer","Jessica","Joan","Joanne","Julia","Karen","Katherine","Kimberly","Kylie","Lauren","Leah","Lillian","Lily","Lisa","Madeleine","Maria","Mary","Megan","Melanie","Michelle","Molly","Natalie","Nicola","Olivia","Penelope","Pippa","Rachel","Rebecca","Rose","Ruth","Sally","Samantha","Sarah","Sonia","Sophie","Stephanie","Sue","Theresa","Tracey","Una","Vanessa","Victoria","Virginia","Wanda","Wendy","Yvonne","Zoe","Adam","Adrian","Alan","Alexander","Andrew","Anthony","Austin","Benjamin","Blake","Boris","Brandon","Brian","Cameron","Carl","Charles","Christian","Christopher","Colin","Connor","Dan","David","Nimmi","Ayush","Dominic","Dylan","Sri","Edward","Mounika","Eric","Evan","Frank","Gavin","Gordon","Harry","Ian","Isaac","Jack","Jacob","Jake","James","Jason","Joe","John","Jonathan","Joseph","Joshua","Julian","Justin","Keith","Kevin","Leonard","Liam","Lucas","Luke","Matt","Max","Michael","Nathan","Neil","Nicholas","Oliver","Owen","Paul","Peter","Phil","Piers","Richard","Robert","Ryan","Sam","Sean","Sebastian","Simon","Stephen","Steven","Stewart","Thomas","Tim","Trevor","Victor","Warren","William"};
    string lastnames[200]={"Abraham","Allan","Alsop","Anderson","Arnold","Avery","Bailey","Baker","Ball","Bell","Berry","Black","Blake","Bond","Bower","Brown","Buckland","Burgess","Butler","Cameron","Campbell","Carr","Chapman","Churchill","Clark","Clarkson","Coleman","Cornish","Davidson","Davies","Dickens","Dowd","Duncan","Dyer","Edmunds","Ellison","Ferguson","Fisher","Forsyth","Fraser","Gibson","Gill","Glover","Graham","Grant","Gray","Greene","Hamilton","Hardacre","Harris","Hart","Hemmings","Henderson","Hill","Hodges","Howard","Hudson","Hughes","Hunter","Ince","Jackson","James","Johnston","Jones","Kelly","Kerr","King","Knox","Lambert","Langdon","Lawrence","Lee","Lewis","Lyman","MacDonald","Mackay","Mackenzie","MacLeod","Manning","Marshall","Martin","Mathis","May","McDonald","McLean","McGrath","Metcalfe","Miller","Mills","Mitchell","Morgan","Morrison","Murray","Nash","Newman","Nolan","North","Ogden","Oliver","Paige","Parr","Parsons","Paterson","Payne","Peake","Peters","Piper","Poole","Powell","Pullman","Quinn","Rampling","Randall","Rees","Reid","Roberts","Robertson","Ross","Russell","Rutherford","Sanderson","Scott","Sharp","Short","Simpson","Skinner","Slater","Smith","Springer","Stewart","Sutherland","Taylor","Terry","Thomson","Tucker","Turner","Underwood","Vance","Vaughan","Walker","Wallace","Walsh","Watson","Welch","White","Wilkins","Wilson","Wright","Young"};
    string showTime[5] = {"Premiere Show" , "Morning Show" , "Matinee Show" , "First Show" ,"Second Show"};
    string SeaTType[3] = {"P","G","E"};//P = Platinum,G=Gold,E=Elite
    string Screen_Number[4]={"S1","S2","S3","S4"};
    string Movienames[4] = {"12-'O' CLOCK","JAATI RATNALU","RADHESHYAM","FANTASTIC BEASTS"};
    string Genretypes[4]= {"Horror","Comedy","Rom-com","Fantasy"};
    float rating_array[4];
    for(int i=0;i<4;i++){
        rating_array[i] = 2+ rand()%(7) + (0.1)*(rand()%9);
    }
    int price_array[3] = {350,250,150};

    for(int i=0;i<n;i++){
        array1[i].name = firstnames[rand() %100] + " " + lastnames[rand() %100];
        array1[i].age = 10 + rand()%70;
        array1[i].datenumber = array1[i].Datenumber[rand()%31];
        array1[i].month = array1[i].Month[rand()%12];
        array1[i].year = array1[i].Year[rand()%2];
        array1[i].finaldate = array1[i].datenumber + "/" + array1[i].month + "/" + array1[i].year;
        array1[i].Profile::alpha1 = array1[i].Profile::Alphabet1[rand() %8];
        array1[i].Profile::alpha2 = array1[i].Profile::Alphabet2[rand() %8];
        array1[i].Profile::alpha3 = array1[i].Profile::Alphabet3[rand() %10];
        array1[i].Profile::num = array1[i].Profile::Number[rand()%26];
        array1[i].digit1 = 6000 + rand() %3999;
        array1[i].digit2 = rand()%999;
        array1[i].digit3 = rand()%999;
        array1[i].digit = (array1[i].digit1)*100000 + (array1[i].digit2)*1000 + (array1[i].digit3);
        array1[i].setDetails(array1[i].name, array1[i].age);
        array1[i].setShowType(showTime[rand()%5]);
        array1[i].setDate(array1[i].datenumber,array1[i].month,array1[i].year);
        array1[i].setSeatType(SeaTType[rand()%3]);
        array1[i].setscreenNumber(Screen_Number[rand()%4]);
        array1[i].setDiscount(0 + rand()%20);
        
        if(array1[i].getSeatType() == "P"){
        array1[i].Profile::seat_Number = array1[i].getScreenType()+"-"+array1[i].getSeatType()+"-"+array1[i].Profile::alpha1 + array1[i].Profile::num;
        array1[i].setPrice(price_array[0]);
        array1[i].settax((0.18)*price_array[0]);
        }
        else if(array1[i].getSeatType() == "G"){
            array1[i].Profile::seat_Number = array1[i].getScreenType()+"-"+array1[i].getSeatType()+"-"+array1[i].Profile::alpha2 + array1[i].Profile::num;
            array1[i].setPrice(price_array[1]);
            array1[i].settax((0.18)*price_array[1]);}
            else if(array1[i].getSeatType() == "E"){
                array1[i].Profile::seat_Number = array1[i].getScreenType()+"-"+array1[i].getSeatType()+"-"+array1[i].Profile::alpha3 + array1[i].Profile::num;
                array1[i].setPrice(price_array[2]);
                array1[i].settax((0.18)*price_array[2]);}
        if(array1[i].getScreenType() == "S1"){
             array1[i].setMoviename(Movienames[0]);
             array1[i].setGenreType(Genretypes[0]);
             array1[i].setRating(rating_array[0]);

        }
        else if(array1[i].getScreenType() == "S2"){
            array1[i].setMoviename(Movienames[1]);
            array1[i].setGenreType(Genretypes[1]);
            array1[i].setRating(rating_array[1]);
        }
        else if(array1[i].getScreenType() == "S3"){
            array1[i].setMoviename(Movienames[2]);
            array1[i].setGenreType(Genretypes[2]);
            array1[i].setRating(rating_array[2]);
        }
        else{
            array1[i].setMoviename(Movienames[3]);
            array1[i].setGenreType(Genretypes[3]);
            array1[i].setRating(rating_array[3]);
        }
        array1[i].setFinal_price( array1[i].getPrice() + array1[i].getTax() - (0.01)*array1[i].getDiscount()*array1[i].getPrice());
        //array1[i].printDetails();
    }
   array1[0].printToFile(n);


    new_file << "\n\n second Part\n\n";
    new_file<<"\nSearch Bookings\n"<<endl;

    minAge=10+rand()%35;
    maxAge=46+rand()%34;

    Search_By_Genre G;
    G.findName::searchByName(array1[rand()%n].name);
    G.Search_By_Age::SearchByAge(array1[rand()%n].age);
    G.Search_By_Age::SearchByAge(minAge,maxAge);
    G.Search_BY_Movie::SearchByMovie(array1[rand()%n].getMovieName());
    G.SearchByRating(array1[rand()%n].getRating());
    G.SearchByGenre(array1[rand()%n].getGenreType());
    G.SearchBookings::SearchByShowtime(array1[rand()%n].getShowTime());


    new_file << "\n\n Third Part \n\n";
    Modify_By_SeatNum M;
    string NewName = firstnames[rand() %100] + " " + lastnames[rand() %100];
    M.ModifyByName(array1[rand()%n].name,NewName);
    M.ModifyByDiscount(array1[rand()%n].getDiscount(), array1[rand()%n].getDiscount()+1+rand()%9);
    string Alphabets[26] = {"A", "B", "C", "D", "E", "F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string Numberss[26] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26"};
    
    int t =rand()%n;
    if(array1[t].getSeatType() == "P"){
         M.ModifyBySeatNum(array1[rand()%n].Profile::seat_Number,array1[t].Profile::Alphabet1[rand()%8],array1[t].Profile::Number[rand()%26]);
    }
    else if(array1[t].getSeatType() == "G"){
         M.ModifyBySeatNum(array1[rand()%n].Profile::seat_Number,array1[t].Profile::Alphabet2[rand()%8],array1[t].Profile::Number[rand()%26]);
    }
    else if(array1[t].getSeatType() == "E"){
         M.ModifyBySeatNum(array1[rand()%n].Profile::seat_Number,array1[t].Profile::Alphabet3[rand()%10],array1[t].Profile::Number[rand()%26]);
    }
    new_file  << "\n\nUpdated List After Modifications\n"<<endl;
        //array1[i].printDetails();
        M.UpdateBookings(n);


    new_file << "\n\n Fourth part \n\n";
    new_file << "Delete Bookings\n"<<endl;
    Delete_By_SeatNumber D;
    D.DeleteByName(array1[rand()%n].name);
    D.DeleteBySeatNum(array1[rand()%n].Profile::seat_Number);
    
    new_file << "\n\nUpdated List After Deletion\n"<<endl;
        //array1[i].printDetails();
        D.UpdateBookings(n-2);
    new_file.close();
    }

    return 0;
}