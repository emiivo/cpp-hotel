#include "room.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>


class User{
   public:
   string  gen_random(int len) {
      string s;
      static const char alphanum[] =
      "0123456789";
      for (int i = 0; i < len; ++i) {
         s += alphanum[rand() % (sizeof(alphanum) - 1)];
      }
   return s;
   }

   string generateUserId(){
      string userID;
      userID = gen_random(4);
      return userID;
   }

   void setUserId(string input){this->userId = input;}

   string userId = "";
   User(){
      setUserId(generateUserId());
   }

   string getUserId(){
      return this->userId;
   }
   ~User(){};

};

struct Age{

   int year;
   int month;
   int day;
   double currentAge;
   void howOld(int year, int month, int day){
      struct tm date = {0};
         date.tm_year = year-1900;
         date.tm_mon = month-1;
         date.tm_mday = day;
         time_t normal = mktime(&date);
         time_t current;
         time(&current);
         long d = (difftime(current, normal) + 86400L/2) / 86400L;
         this->currentAge = d/365.0;
   };

};


class Resident: public User{

   private:
   string dateOfBirth;
   string name;
   string surname;
   double paymentAmount;
   int roomIndex;
   string timeOfPayment;
   vector<Review> listOfReviews;
   public:
   
   Resident(){
      this->dateOfBirth = "";
      this->name = "";
      this->surname = "";
      this->userId = "";
      this->paymentAmount = paymentAmount;
      this->timeOfPayment = "";
      
   }
   
   void addReview(Review review){
      this->listOfReviews.push_back(review);
   }
   
   string getDateOfBirth(){return dateOfBirth;}
   void setDateOfBirth(string dateOfBirth){
      this->dateOfBirth = dateOfBirth;
   };
   
   string getName(){return this->name;}
   void setName(string name){
      this->name=name;
   };
   
   string getSurname(){return this->surname;}
   void setSurname(string surname){
      this->surname=surname;
   };
   
   int getRoomIndex(){return this->roomIndex;}
   void setRoomIndex(int index){
      this->roomIndex = index;
   }
   
   
   double getPaymentAmount(){return this->paymentAmount;}
   void setPaymentAmount(double paymentAmount){
      this->paymentAmount=paymentAmount;
   }
   
   string getTimeOfPayment(){return this->timeOfPayment;}
   void setTimeOfPayment(string timeOfPayment){
      this->timeOfPayment=timeOfPayment;
   }
   
   string reviewRoom(){
      string review;
      cin >> review;
      return review;
   }
   
};

class Client: public User{
   
   private:
      vector<Review> listOfReviews;
      
   public:
   
   void addReview(Review review){
      this->listOfReviews.push_back(review);
   }

   bool isOfAge(string dateOfBirth){
      Age age;
      string year;
      string month;
      string day;
      for(int i = 0; i<4; i++){
         year.push_back(dateOfBirth.at(i));
      }
      for(int i = 5; i<7; i++){
         month.push_back(dateOfBirth.at(i));
      }
      for(int i= 8; i<10; i++){
         day.push_back(dateOfBirth.at(i));
      }	
      age.year = stoi(year);
      age.month = stoi(month);
      age.day = stoi(day);
      age.howOld(age.year, age.month, age.day);
      if(age.currentAge<18){
         return false;
      }
      else{
         return true;
      }
   }
   
   bool bookRoom(Room room, string name, string surname, string dateOfBirth, double paymentAmount, string timeOfPayment){
      if(!isOfAge(dateOfBirth)){
         cout << "Esate per jaunas." << endl;
         return false;
      }

      else {
         cout << "Sveikiname prisiregistravus. Dabar esate viešbučio gyventojas." << endl;
         cout << "Jūsų ID: " << this->getUserId() << ". Su šiuo kodu nuo šiol galite prisijungti prie sistemos kaip gyventojas." << endl;
         return true;
      }
   } 
};


Resident clientToResident(Client client, Room room, string name, string surname, string dateOfBirth, double paymentAmount, string timeOfPayment){
   Resident resident;
   if(client.bookRoom(room, name, surname, dateOfBirth, paymentAmount, timeOfPayment)){ 
      resident.setName(name);
      resident.setSurname(surname);
      resident.setUserId(client.getUserId());
      resident.setDateOfBirth(dateOfBirth);
      resident.setPaymentAmount(paymentAmount);
      resident.setTimeOfPayment(timeOfPayment);
      return resident;
   }
   else{
      cout << "Registracija nepavyko." << endl;
      return resident;
   }
}

   
class Administrator: public User{

   private:
   
   vector<Client> listOfReceipts;
      
   public:
      Administrator(){ userId="ADMIN"; }
      void addTransaction(Client client){
         this->listOfReceipts.push_back(client);
      }
};
