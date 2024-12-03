#include "user.h"

void addWorker(vector<Worker> worker){
   ofstream fr("worker.txt");
   for(int i = 0; i<worker.size(); i++){
   fr << worker.at(i).getWorkerIndex() << " " << worker.at(i).getName() << " " << worker.at(i).getSurname() <<
    " " << worker.at(i).getWorkerPay()  << endl;
   }
   
   fr.close();
}

void getWorker(vector <Worker> &workers){

   ifstream fd("worker.txt");
   
   string name;
   string surname;
   double workerPay;
   int workerIndex;
   Worker worker;
   
   do{
   
      fd >> workerIndex;
      fd >> name;
      fd >> surname;
      fd >> workerPay;

      worker.setName(name);
      worker.setSurname(surname);
      worker.setWorkerIndex(workerIndex);
      worker.setWorkerPay(workerPay);
      
      if(!fd.eof()){
         workers.push_back(worker);
      }
   }while(!fd.eof());
   
   fd.close();
   
}

void addMinus(vector<Minus> minus){
   ofstream fr("minus.txt");
   for(int i=0; i<minus.size(); i++){
   fr << minus.at(i).getMinus() << endl;
   }
   fr.close();
}

void getMinus(vector<Minus> &minuses){
   ifstream fd("minus.txt");
   
   double minusAmount;
   Minus minus;
   
   do{
      fd >> minusAmount;
      minus.setMinus(minusAmount);
      if(!fd.eof()){
         minuses.push_back(minus);
      }
   }while(!fd.eof());
   
   fd.close();
}
void getCurrentResidents(vector <Resident> &residents){

   ifstream fd("human.txt");
   
   string name;
   string surname;
   string dateOfBirth;
   string userId;
   double paymentAmount;
   int index;
   string timeOfPayment;
   Resident resident;
   residents.erase(residents.begin(), residents.end());
   
   do{
      fd >> name;
      fd >> surname;
      fd >> dateOfBirth;
      fd >> userId;
      fd >> index;
      fd >> paymentAmount;
      getline(fd, timeOfPayment, '\n');
      
      resident.setName(name);
      resident.setSurname(surname);
      resident.setDateOfBirth(dateOfBirth);
      resident.setUserId(userId);
      resident.setRoomIndex(index);
      resident.setPaymentAmount(paymentAmount);
      resident.setTimeOfPayment(timeOfPayment);
      if(!fd.eof()){
         residents.push_back(resident);
      }
   }while(!fd.eof());
   
   fd.close();
   
}


void addBookedRooms(vector<Room>  room){
   ofstream fr("rooms.txt");
   for(int i=0; i<room.size(); i++){
      fr << room.at(i).getRoomIndex() << " " << room.at(i).getRoomName() << " " << room.at(i).getDetails() << 
      " " << room.at(i).getPrice() << " " << room.at(i).isRoomBooked() << endl;
   }
   fr.close();
}

void addReview(vector<Review> review){
   ofstream fr("reviews.txt");
   for(int i=0; i<review.size(); i++){
   fr << review.at(i).getReviewText() << endl;
   }
   fr.close();
}

void getReviews(vector<Review> &reviews){
   ifstream fd("reviews.txt");
   
   string reviewText;
   Review review;
   do{
      getline(fd, reviewText, '\n');
      review.setReview(reviewText);
      if(!fd.eof()){
         reviews.push_back(review);
      }
   }while(!fd.eof());
   
   fd.close();
}


void getRooms(vector<Room> &rooms){
   string name;
   string details;
   double price;
   int index;
   Room room;
   bool booked;
   ifstream fd("rooms.txt");
   for(int i = 0; i<22; i++){
      fd >> index;
      fd >> name;
      fd >> details;
      fd >> price;
      fd >> booked;
      room.setRoomIndex(index);
      room.setRoomName(name);
      room.setRoomDetails(details);
      room.setPrice(price);
      room.setBooked(booked);
      rooms.push_back(room);
   }
   
   fd.close();
}

void addResidents(vector<Resident> resident){
   ofstream fr("human.txt");
   for(int i = 0; i<resident.size(); i++){
   fr << resident.at(i).getName() << " " << resident.at(i).getSurname() <<
    " " << resident.at(i).getDateOfBirth() << " " << resident.at(i).getUserId() << " " << resident.at(i).getRoomIndex() << " " << resident.at(i).getPaymentAmount() << " " << resident.at(i).getTimeOfPayment() << endl;
   }
   
   fr.close();
}



int main(){
   
   srand(time(NULL));
   vector<Room> rooms;
   Resident resident;
   getRooms(rooms);
   Review review;
   Minus minus;
   vector <Minus> minuses;
   Worker worker;
   vector <Worker> workers;
   getWorker(workers);
   getMinus(minuses);
   Administrator admin;
   string opinion; 
   vector <Review> reviews;
   vector <Resident> residents;
   bool roleChosen = false;
   string role = "";
   bool systemClosing = false;
   getCurrentResidents(residents);
   getReviews(reviews);
   Client client;
   double workerPay;
   double allPayments;
      
   do{
      cout << "Esate viešbučio sistemoje." << endl;
      cout << "Prašome parašyti, koks jūsų vaidmuo." << endl;
      cout << "1) Jei neturite registracijos į kambarį, rašykite žodį 'klientas'." << endl;
      cout << "2) jei esate prisiregistravę, rašykite žodį 'gyventojas'." << endl;
      cout << "3) jei esate administratorius, rašykite žodį 'administratorius'." << endl;
      getline(cin, role);
      if ((role == "klientas") || (role == "Klientas")){
         roleChosen = true;
         cout << endl;
         bool correctClientChoice = false;
         do{
            cout << "Sveiki atvykę." << endl;
            cout << "--------------------------" << endl;
            cout << "Pasirinkite veiksmą, kurį norite atlikti:" << endl;
            cout << "Rašykite 1, jei norite peržiūrėti laisvus kambarius bei prisiregistruoti į viešbučio sistemą." << endl;
            cout << "Rašykite 2, jei norite peržiūrėti atsiliepimus apie viešbutį." << endl;
            cout << "Rašykite 3, jei norite iš naujo rinktis vaidmenį." << endl;
            cout << "Rašykite 4, jei norite sustabdyti programą." << endl;
            string clientChoose;
            cout << endl;
            cout << "---------------" << endl;
            getline(cin, clientChoose);
            cout << "---------------" << endl;   
            cout << endl;   
            if (clientChoose == "1"){
               cout << "Laisvi kambariai:" << endl;
               cout << "--------------------" << endl;
               for(int i=0; i < rooms.size(); i++){
                  if(!rooms.at(i).isRoomBooked()){
                        cout << i+1 << ". " << rooms[i].getRoomName() << " || ";
                        cout << rooms[i].getDetails() << " ";
                        cout << rooms[i].getPrice() << "€" << endl; 
	          }
               } 
               string name, surname, dateOfBirth;
               Client client;
               cout << endl;
               cout << "----------------------------" << endl;
               cout << "Jei norite atšaukti registravimąsi, rašykite 'ne', jei norite tęsti, rašykite 'taip'." << endl;
               string registration;
               bool registrate = false;
               
               do{
                  bool registrationAcquired = false;
                  cin >> registration;
                  if((registration == "taip") || (registration == "Taip") || (registration == "TAIP")){
                     registrationAcquired = true;
                     cout << "Įveskite savo vardą" << endl;
                     cin >> name;
                     cout << "Įveskite savo pavardę" << endl;
                     cin >> surname;
                     cout << "Įveskite savo gimimo datą (formatas mmmm-mm-dd)" << endl;
                     cin.ignore();
                     cin >> dateOfBirth;
                     cout << "Į kurį kambarį pageidaujate registruotis? Įrašykite jo numerį." << endl;
                     int roomIndex;
                     int days;
                     double paymentAmount;
                     cin.ignore();
                     cin >> roomIndex;
                     string isItPayed;
                     cout << "Įveskite, kiek dienų planuojate apsistoti." << endl;
                     cin >> days;
                     paymentAmount = rooms.at(roomIndex-1).getPrice() * days;
                     cout << "Už viešnagę jums teks sumokėti " << paymentAmount << " €." << endl;
                     cout << "Norėdami įvykdyti mokėjimą, rašykite žodį 'taip'. Jei norite atšaukti registraciją, rašykite 'ne'." << endl;
                     
                     bool paymentOk = false;
                     do{
                     cin >> isItPayed;
                     if((isItPayed == "Taip") || (isItPayed == "taip") || (isItPayed == "TAIP")){
                        paymentOk = true;
                     }
                     else if((isItPayed == "ne") || (isItPayed == "Ne") || (isItPayed == "NE")){
                        return 0;
                     }
                     else cout << "Norėdami prisiregistruoti, turite susimokėti už savo kambarį. Jei nesutinkate, rašykite 'ne'. Jei sutinkate, rašykite 'taip'." << endl;
                     }while(paymentOk == false);
                     string timeOfPayment;
                     time_t ttime = time(0);
    
                     char* payedNow = ctime(&ttime);
                     timeOfPayment = payedNow;
                     
                     cout << "--------------------------------" << endl;
                     cout << "Jūsų mokėjimas įvykdytas." << endl;
                     cout << "Mokėjimo laikas: " << timeOfPayment << endl;
                     if(rooms.at(roomIndex-1).isRoomBooked()){
                        do{
                           for(int i = 0; i < 1; i++){
                              if(rooms.at(i).isRoomBooked()){
                                 cout << endl; 
                                 cout << "Kambarys užimtas." << endl; 
                              }
                           }
                           break;
                        }while(rooms.at(roomIndex-1).isRoomBooked());
                     }           
                     else{	
                        resident=clientToResident(client, rooms[roomIndex-1], name, surname, dateOfBirth, paymentAmount, timeOfPayment); 
                        resident.setRoomIndex(rooms[roomIndex-1].getRoomIndex());   
                        residents.push_back(resident);   
                        addResidents(residents);
                        rooms.at(roomIndex-1).bookingRoom();
                        addBookedRooms(rooms);
                     }
                     registrate = true;
                  }
              else if((registration == "ne") || (registration == "Ne") || (registration == "NE")){
                  cout << endl;
                  cout << "-----------------" << endl;
                  cout << "   Viso gero." << endl;
                  cout << "-----------------" << endl;
                  return 0;
               }
              else{
                 cout << "Bandykite dar kartą." << endl;
                 cout << endl;
              }
               
            }while(registrate == false);  
         correctClientChoice = true;
         }

            if (clientChoose == "2"){
               cout << endl;
               cout << "---------------------------" << endl;
               cout << endl;
               for(int i = 0; i < reviews.size(); i++){
                  cout << reviews.at(i).getReviewText() << endl;
               }
               cout << endl;
               cout << "---------------------------" << endl;
               cout << endl;
               correctClientChoice = true;
            }
            if(clientChoose == "3"){
            correctClientChoice = true;
            }
            if(clientChoose == "4"){
               systemClosing = true;
               correctClientChoice = true;
            }
            }while(correctClientChoice == false);
            }
         if ((role == "gyventojas") || (role == "Gyventojas")){
            roleChosen = true;
            bool loginCorrect = false;
            string loginName;   
            int userIndex;
            bool residentLogin = false;
            do{
               cout << endl;
               cout << "Įveskite vartotojo ID: " << endl; 
               cout << endl;
               cin >> loginName;
               if((loginName == "baigti") || (loginName == "Baigti") || (loginName == "BAIGTI")){
                  roleChosen = true;
                  return 0;
               }
               for(int i = 0; i<residents.size(); i++){
                  if(loginName == residents.at(i).getUserId()){
                     userIndex = i;
                     loginCorrect = true;
                  }
               }   
               if(loginCorrect == false){
                  cout << "Toks ID neegzistuoja, mėginkite dar kartą." << endl;
                  cout << "Jei norite išeiti iš sistemos, rašykite 'baigti'." << endl;
               }
            }while(loginCorrect == false);
         cout << "Sveiki sugrįžę." << endl;
         cout << "--------------------------" << endl;
         cout << "Rašykite 1, jei norite palikti atsiliepimą apie viešbutį." << endl;
         cout << "Rašykite 2, jei norite peržiūrėti atsiliepimus apie viešbutį." << endl;
         cout << "Rašykite 3, jei norite išsiregistruoti iš viešbučio." << endl;
         
         bool residentLoggingOut = false;
         string logOut;
         bool inputCorrect = false;

         do{
            string opinion;
   	    char residentChoose;
            cin >> residentChoose;
   	    if (residentChoose == '1'){
               cout << "Ką manote?" << endl;
               cin.ignore();
	       getline(cin, opinion);
   	       review.setReview(opinion);
	       reviews.push_back(review);
	       addReview(reviews);
            }
	    else if (residentChoose == '2'){
	       for(int i = 0; i < reviews.size(); i++){
                  cout << reviews.at(i).getReviewText() << endl;
               }
	    }
	    else if (residentChoose == '3'){
	       string leaveHotel; 
	       cout << "Jei norite išsiregistruoti iš viešbučio, rašykite 'taip'." << endl;   
	       cin >> leaveHotel;
	       if((leaveHotel == "Taip") || (leaveHotel == "taip")){
	          for(int i=0; i<rooms.size(); i++){
	             if(residents.at(userIndex).getRoomIndex() == rooms.at(i).getRoomIndex()){
	                rooms.at(i).bookingRoom();
	                residents.at(userIndex).setRoomIndex(0);
	                addResidents(residents);   
	                addBookedRooms(rooms);
                     }
	          }
	          cout << "Ačiū ir viso gero." << endl;
	          return 0;
	       }
            }
	    do{
	       cout << "Ar baigėte darbą?" << endl;
	       cin >> logOut;
	       if((logOut == "taip") || (logOut == "Taip")){
                  return 0;
	       }
	       if((logOut == "ne") || (logOut == "Ne")){
                  cout << "Rašykite 1, jei norite palikti atsiliepimą apie kambarį." << endl;
                  cout << "Rašykite 2, jei norite peržiūrėti atsiliepimus apie kambarį." << endl;
                  cout << "Rašykite 3, jei norite susimokėti ir išsiregistruoti iš viešbučio." << endl;
	          inputCorrect = true;
	       }
	       if(inputCorrect == false){
                  cout << "Neteisingai įvesta. Parašykite 'taip' arba 'ne'." << endl;
	       }
	    }while(inputCorrect == false);
         } while(residentLoggingOut == false);
         return 0;
         }
         if ((role == "administratorius") || (role == "Administratorius")){
            roleChosen = true;
            cout << "Įveskite vartotojo ID:" << endl;
            string adminLogIn;
            cin >> adminLogIn;
            if(adminLogIn != admin.getUserId()){
               cout << "Negalima prieiga." << endl;
               return 0;   
            }
            cout << "Sveiki." << endl;
            cout << "--------------------------" << endl;
            cout << "Kokį veiksmą norite atlikti?" << endl;
            cout << "1 - peržiūrėti laisvus kambarius." << endl;
            cout << "2 - peržiūrėti užimtus kambarius." << endl;
            cout << "3 - peržiūrėti gyventojų bei mokėjimų sąrašą.	" << endl;
            cout << "4 - peržiūrėti atsiliepimus apie viešbutį." << endl;
            cout << "5 - įvesti naują išlaidą." << endl;
            cout << "6 - peržiūrėti bendrą pelno bei išlaidų suvestinę." << endl; 
            cout << "---------------" << endl;
            cout << endl;
            string adminChoose;
            bool tryAgain = false;
            bool adminLoggingOut = false;
            double allMinus;
            while(adminLoggingOut == false){
               cin >> adminChoose;
               if(adminChoose == "1"){
                  cout << endl;
                  cout << "-------------" << endl;
                  for(int i = 0; i < rooms.size(); i++){
                     if(!rooms.at(i).isRoomBooked()){
                        cout << i+1 << ". " << rooms[i].getRoomName() << " || ";
                        cout << rooms[i].getDetails() << " ";
                        cout << rooms[i].getPrice() << "€" << endl; 
                        tryAgain = true;  
                     } 
                  }
                  adminLoggingOut = true;
               }
               else if(adminChoose == "2"){
                  for(int i = 0; i < rooms.size(); i++){
                     if(rooms.at(i).isRoomBooked()){
                        cout << i+1 << ". " << rooms[i].getRoomName() << " || ";
                        cout << rooms[i].getDetails() << " ";
                        cout << rooms[i].getPrice() << "€" << endl;   
                     }
                  }
                adminLoggingOut = true;
                tryAgain = true;
               }
               else if(adminChoose == "3"){
                  for(int i = 0; i < residents.size(); i++){
                     cout << residents[i].getUserId() << " " << residents[i].getDateOfBirth() << " ";
                     cout << residents[i].getName() << " " << residents[i].getSurname() << " " << residents[i].getPaymentAmount() << " Eur. Mokėjimo laikas: " << residents[i].getTimeOfPayment() << endl;
                     allPayments = allPayments + residents[i].getPaymentAmount();
                  }
                  adminLoggingOut = true;
                  tryAgain = true;
               }
               else if(adminChoose == "4"){
                  for(int i = 0; i < reviews.size(); i++){
                     cout << reviews.at(i).getReviewText() << endl;
                  }
                  adminLoggingOut = true;
                  tryAgain = true;
               }
               else if(adminChoose == "5"){

                  int whatCost;
                  bool costOK = false;
                  cout << "-------------------------" << endl;
                  cout << "Įveskite išlaidos rūšį:" << endl;
                  cout << "1 - alga darbuotojams." << endl;
                  cout << "2 - mokesčiai." << endl;
                  cout << "3 - gedimo taisymas." << endl;
                  cout << "4 - nenumatytos išlaidos." << endl;
                  cout << "-------------------------" << endl;
                  cin >> whatCost;
                  double payedToWorker;
                  double workerGets;

                  do{
                     if(whatCost == 1){ 
                        int which;

                        int workerIndex;
                        cout << "-------------------------" << endl;
                        for(int i = 0; i < workers.size(); i++){
                           cout << workers[i].getName() << " " << workers[i].getSurname() << endl;
                        }
                        cout << "---------------------------" << endl;
                        cout << "Parašykite, kuriam darbuotojui norite sumokėti (skaičius):" << endl;
                        cin >> workerIndex;
                        cout << endl;
                        cout << "Parašykite, kiek norite sumokėti darbuotojui:" << endl;
                        cin >> payedToWorker;
                        cout << endl;
                        workerGets = workers.at(workerIndex-1).getWorkerPay() + payedToWorker;
                        cout << "Darbuotojui sumokėta " << payedToWorker << " €." << endl;
                        workers.at(workerIndex-1).setWorkerPay(workerGets); 
                        workers.push_back(worker); 
                        addWorker(workers);
                        costOK = true;
                        adminLoggingOut = true;
                        tryAgain = true;
                     }
                     else if((whatCost == 2) || (whatCost == 3) || (whatCost == 4)){
                        double cost;
                        cout << "-------------------------" << endl;
                        cout << "Įveskite sumokėtą sumą:" << endl;
                        cin >> cost;
                        minus.setMinus(cost);
                        minuses.push_back(minus);
	                addMinus(minuses);
                        costOK = true;
                        adminLoggingOut = true;
                        tryAgain = true; 
                        cout << "-------------------------" << endl;
                        cout << "Įvesta sėkmingai. " << endl;

                     }        
                     
                     else{
                     cout << "Įveskite tik skaičių." << endl;
                     }
                     
                  }while(costOK == false);
               }
               else if (adminChoose == "6"){
                  double allPayments;
                  double allBad;
                  double everything;
                  double workersGot;
                  for(int i = 0; i < residents.size(); i++){
                     allPayments = allPayments + residents[i].getPaymentAmount();
                  }
                  for(int i = 0; i < minuses.size(); i++){
                     allBad = allBad + minuses[i].getMinus();
                  }
                  cout << "-------------------------------" << endl;
                  cout << "Bendros pajamos: " << allPayments << "€" << endl;
                  cout << "-------------------------------" << endl;
                  cout << "Viešbučio išlaidos: " << allBad << "€" << endl;
                  cout << "-------------------------------" << endl;
                  cout << "Algos darbuotojams: " << endl;
                  cout << endl;
                  for(int i = 0; i < workers.size(); i++){
                  cout << workers[i].getName() << " " << workers[i].getSurname() << " " << workers[i].getWorkerPay() << "€" << endl;
                  workersGot = workersGot + workers[i].getWorkerPay();
                  }
                  
                  everything = allPayments - allBad - workersGot;
                  cout << endl;
                  cout << "-------------------------------" << endl;
                  cout << "Likutis: " << everything << "€" << endl;
                  adminLoggingOut = true;
                  
               
               } 
               else if(tryAgain == false){
                  cout << "Bandykite dar kartą." << endl;
                  adminLoggingOut = false;
               }
             } 
            systemClosing = true;
            }
            if(roleChosen == false){   
               cout << "Neteisingai įvestas vaidmuo. Bandykite dar kartą." << endl;
            }
      } while(systemClosing == false);
     
   return 0;
}
