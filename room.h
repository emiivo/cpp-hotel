#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <random>

using namespace std;
class Room{

   private:
   string roomName;
   string roomDetails;
   double price;
   bool isBooked;
   int roomIndex;
   
   protected:
   
   
   public:
   Room(){
      roomName = "";
      roomDetails = "";
      price = 0;
      roomIndex = 0;
      isBooked = false;
   }
   double getPrice(){return this->price;}
   void setPrice(double price){
   this->price = price;
   }
   
   void setRoomName(string name){this->roomName = name;}
   string getRoomName(){return this->roomName;}
   
   void setRoomDetails(string details){this->roomDetails = details;}
   string getDetails(){return this->roomDetails;}
   
   void setBooked(bool booked){
      this->isBooked = booked;
   }
   
   void bookingRoom(){
      this->isBooked = !this->isBooked;
   }
   
   bool isRoomBooked(){return isBooked;}
   
   void setRoomIndex(int index){
      this->roomIndex = index;
   }
   
   int getRoomIndex(){return this->roomIndex;}
};

class Review{

   private:
   Room room;
   string review;
   
   public:
   Review(){
      this->review = "";
   };
   string getReviewText(){return this->review;}
      void setReview(string review){
      this->review=review;
   }
   void getReview(){
      cout << this->review << endl;
   }
};

class Minus{

   private:
   double minus;
   
   public:
   Minus(){
      this->minus = minus;
   }; 
   
   double getMinus(){return this->minus;}
   void setMinus(double minus){
      this->minus=minus;
   }
};

class Worker{

   private:
   string name;
   string surname;
   double workerPay;
   int workerIndex;
   
   public:
   Worker(){
      this->name = "";
      this->surname = "";
      this->workerPay = 0;
      this->workerIndex = 0;
   };
   
   string getName(){return this->name;}
   void setName(string name){
      this->name=name;
   }
   string getSurname(){return this->surname;}
   void setSurname(string surname){
      this->surname=surname;
   }
   double getWorkerPay(){return this->workerPay;}
   void setWorkerPay(double workerPay){
      this->workerPay=workerPay;
   }
   int getWorkerIndex(){return this->workerIndex;}
   void setWorkerIndex(int index){
      this->workerIndex = index;
   }
   

   

};    
