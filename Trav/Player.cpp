//TODO: Pull the cin stuff into the do while loops 
#include <windows.h>
#include <iostream>
#include <algorithm>
#include "Player.h"
#include <string>



Player::Player(){
    uniEvent = "";
    psiTrainingEnabled = false;
    eligibleForGraduation = false;
    isPrisoner = false;
    allies = 0;
    enemies = 0;
    rivals = 0;
    friends = 0;
    Str = 0;
    Dex = 0;
    End = 0;
    Edu = 0;
    Soc = 0;
    Intt= 0;
    strDiceMod = 0;
    dexDiceMod = 0;
    endDiceMod = 0;
    socDiceMod = 0;
    inttDiceMod= 0;
    eduDiceMod = 0;
    skills = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
              -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
              -1,-1,-1};  
};

void Player::DisplaySkills(){
	std::cout << "    ++++++++++++++++++++++++++++++++Skills+++++++++++++++++++++++++++++++++++++    " << std::endl;
  std::cout <<"Admin:        "<< skills.admin       <<" Advocate:    "<<skills.advocate    <<" Animals:        "<< skills.animals<< std::endl;
  std::cout <<"Art:          "<< skills.art         <<" Astrogation: "<<skills.astrogation <<" Athletics:      "<< skills.athletics<< std::endl;
  std::cout <<"Broker:       "<< skills.broker      <<" Carouse:     "<<skills.carouse     <<" Deception:      "<< skills.deception<< std::endl;
  std::cout <<"Diplomat:     "<< skills.diplomat    <<" Drive:       "<<skills.drive       <<" Electronics:    "<< skills.electronics<< std::endl;
  std::cout <<"Engineer:     "<< skills.engineer    <<" Explosives:  "<<skills.explosives  <<" Flyer:          "<< skills.flyer<< std::endl;
  std::cout <<"Gambler:      "<< skills.gambler     <<" Gunner:      "<<skills.gunner      <<" Guncombat:      "<< skills.gunCombat<< std::endl;
  std::cout <<"HeavyWeapons: "<< skills.heavyWeapons<<" Investigate: "<<skills.investigate <<" Jackofalltrades:"<< skills.jackOfAllTrades<< std::endl;
  std::cout <<"Language:     "<< skills.language    <<" Leadership:  "<<skills.leadership  <<" Mechanic:       "<< skills.mechanic<< std::endl;
  std::cout <<"Medic:        "<< skills.medic       <<" Melee:       "<<skills.melee       <<" Navigation:     "<< skills.navigation<< std::endl;
  std::cout <<"Persuade:     "<< skills.persuade    <<" Pilot:       "<<skills.pilot       <<" Profession:     "<< skills.profession<< std::endl;
  std::cout <<"Recon:        "<< skills.recon       <<" Science:     "<<skills.science     <<" Seafarer:       "<< skills.seafarer<< std::endl;
  std::cout <<"Stealth:      "<< skills.stealth     <<" Steward:     "<<skills.steward     <<" Streetwise:     "<< skills.streetwise<< std::endl;
  std::cout <<"Surival:      "<< skills.survival    <<" Tactics:     "<<skills.tactics     <<" Vaccsuit:       "<< skills.vaccSuit<< std::endl;


}
void Player::UpdateDiceMod(){
     //TODO: Finish this function
     if(Str == 0){
       strDiceMod = -3;
     }else if(Str > 0 && Str < 3){

     }else if(Str > 2 && Str < 6){

     }else if(Str > 5 && Str < 9){

     }else if(Str > 8 && Str < 12){

     }else if(Str > 11 && Str < 15){

     }else if(Str >= 15){

     }

}
void Player::DisplayStats(){  
  std::cout<<"Str = "<<Str<<"Int = "<<Intt<<"End = "<<End <<std::endl;
  std::cout<<"Dex = "<<Dex<<"Edu = "<<Edu <<"Soc = "<<Soc <<std::endl;
  }
void Player::RollCharacteristics(){
  //Roll 2D for every characteristic. Calculate dice modifier(DM)
  std::cout <<"Rolling for characteristic...."<<std::endl;

  int stats [6];
  // assigning 26d dicerolls to the stats array
  for (int i = 0; i < sizeof(stats)/sizeof(stats[0]);++i)
  {
    stats[i]  = RollDice(2);
    std::cout<<stats[i]<<std::endl;
  }
  //Sort the stats random array
  std::sort(std::begin(stats),std::end(stats));
  //Sets the variables for text up
  int input;
  std::string strtex =  "Press 1 = Str";
  std::string dextex =  "Press 2 = Dex";
  std::string endtex =  "Press 3 = End";
  std::string inttex =  "Press 4 = Int";
  std::string edutex =  "Press 5 = Edu";
  std::string soctex =  "Press 6 = Soc";

  for (int i = 6; i > 0; --i)
  {
       // this makes the x iterate through the loop
       int x = i - 1;  
       std::string padding = "\t\t";

       std::cout << "Where do you want the "<<stats[x]<< " to go?" <<std::endl;
       std::cout<< strtex <<padding<<inttex<<padding<<soctex<<std::endl;
       std::cout<< dextex <<padding<<edutex<<padding<<endtex<<std::endl; 

       
       // the input is the choice of were you want your current attribute
       // to go.
       std::cin >> input;
       switch (input){
        case 1:
          if(Str != 0){
              std::cout << " You need to enter another number."<<std::endl;
              i++;
          }
          else 
          {
            Str = stats[x];
            switch(stats[x]){
              case 1:
              case 2:
              strDiceMod = -2;
              break;
              case 3:
              case 4:
              case 5:
              strDiceMod = -1;
              case 9:
              case 10:
              case 11: 
              strDiceMod = 1;
              break;
              case 12:
              case 13:
              strDiceMod = 2;
              break;

            } 
            strtex = "";          
          }
          break;
        case 2:
          if(Dex != 0){
              std::cout << " You need to enter another number."<<std::endl;
              i++;
          }
          else 
          {
            Dex = stats[x];
            switch(stats[x]){
              case 1:
              case 2:
              strDiceMod = -2;
              break;
              case 3:
              case 4:
              case 5:
              strDiceMod = -1;
              case 9:
              case 10:
              case 11: 
              strDiceMod = 1;
              break;
              case 12:
              case 13:
              strDiceMod = 2;
              break;

            } 
            
            dextex = "";
          }
         
          break;
        case 3:
          if(End != 0){
              std::cout << " You need to enter another number."<<std::endl;
              i++;
          }
          else 
          {
           End = stats[x];
           switch(stats[x]){
              case 1:
              case 2:
              strDiceMod = -2;
              break;
              case 3:
              case 4:
              case 5:
              strDiceMod = -1;
              case 9:
              case 10:
              case 11: 
              strDiceMod = 1;
              break;
              case 12:
              case 13:
              strDiceMod = 2;
              break;

            } 
            
           endtex = "";
          }
          break;
        case 4:
          if(Intt != 0){
              std::cout << " You need to enter another number."<<std::endl;
              i++;
          }
          else 
          {
           Intt = stats[x];
           switch(stats[x]){
              case 1:
              case 2:
              strDiceMod = -2;
              break;
              case 3:
              case 4:
              case 5:
              strDiceMod = -1;
              case 9:
              case 10:
              case 11: 
              strDiceMod = 1;
              break;
              case 12:
              case 13:
              strDiceMod = 2;
              break;

            } 
            
           inttex = "";
          }
          break;
        case 5:
          if(Edu != 0){
              std::cout << " You need to enter another number."<<std::endl;
              i++;
          }
          else 
          {
           Edu = stats[x];
           switch(stats[x]){
              case 1:
              case 2:
              strDiceMod = -2;
              break;
              case 3:
              case 4:
              case 5:
              strDiceMod = -1;
              case 9:
              case 10:
              case 11: 
              strDiceMod = 1;
              break;
              case 12:
              case 13:
              strDiceMod = 2;
              break;

            } 
            
           edutex= "";
          }
          break;
        case 6:
          if(Soc != 0){
              std::cout << " You need to enter another number."<<std::endl;
              i++;
          }
          else 
          {
           Soc = stats[x];
           switch(stats[x]){
              case 1:
              case 2:
              strDiceMod = -2;
              break;
              case 3:
              case 4:
              case 5:
              strDiceMod = -1;
              case 9:
              case 10:
              case 11: 
              strDiceMod = 1;
              break;
              case 12:
              case 13:
              strDiceMod = 2;
              break;

            } 
            
           soctex = "";
          }
          break;
        default:
            //pos bug
            std::cout << " you just entered an invilid number"<<std::endl;
            i++;
          break;
       }     


  }
  
}
int Player::RollDice(int x){
  int randomRoll;

  switch (x){
    case 1:
    randomRoll = rand() % 6 + 1;
    break;    
    case 2:
    randomRoll = rand() % 12 + 1;    
    break;
    case 3:
    randomRoll = rand() % 18 + 1;    
    break;
    default:
    std::cout << "enter a value between 1-3"<<std::endl;
    break;
  }
  return randomRoll;
}
bool Player::RollOnSkill(std::string skill, int value){
  do{
   if(skill == "admin"){
       if(this->skills.admin + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "advocate"){    
       if(this->skills.advocate + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "animals"){    
       if(this->skills.animals + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "art"){    
       if(this->skills.art + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "astrogation"){    
       if(this->skills.astrogation + this->RollDice(2) >= value){return true}return false; 
    }else if(skill == "broker"){    
       if(this->skills.broker + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "carouse"){    
       if(this->skills.carouse + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "deception"){    
       if(this->skills.deception + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "diplomat"){    
       if(this->skills.diplomat + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "drive"){    
       if(this->skills.driv + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "electronics"){    
       if(this->skills.electronics + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "engineer"){    
       if(this->skills.enginee + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "explosives"){    
       if(this->skills.explosives + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "flyer"){    
       if(this->skills.flye + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "gambler"){    
       if(this->skills.gamble + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "gunner"){    
       if(this->skills.gunne + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "guncombat"){    
       if(this->skills.gunCombat + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "heavyweapons"){    
       if(this->skills.heavyWeapons + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "investigate"){    
       if(this->skills.investigate + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "jackofalltrades"){    
       if(this->skills.jackOfAllTrades + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "language"){    
       if(this->skills.languag + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "leadership"){    
       if(this->skills.leadership + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "mechanic"){    
       if(this->skills.mechanic + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "medic"){    
       if(this->skills.medic + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "melee"){    
       if(this->skills.melee + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "navigation"){    
       if(this->skills.navigatio + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "persuade"){    
       if(this->skills.persuade + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "pilot"){    
       if(this->skills.pilot + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "profession"){    
       if(this->skills.profession + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "recon"){    
       if(this->skills.recon + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "science"){    
       if(this->skills.science + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "seafarer"){    
       if(this->skills.seafarer + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "stealth"){    
       if(this->skills.stealth + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "steward"){    
       if(this->skills.steward + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "streetwise"){    
       if(this->skills.streetwise + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "survival"){    
       if(this->skills.survival + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "tactics"){    
       if(this->skills.tactics + this->RollDice(2) >= value){return true}return false;
    }else if(skill == "vaccsuit"){    
       if(this->skills.vaccSuit + this->RollDice(2) >= value){return true}return false;
    }else {
      std::cout << "No valid skills was set..."<<std::endl;
      std::cout <<"Enter a valid skill."<<std::endl;
      skill = "";
      return false;
    }
  }while(skill == "")
}
bool Player::isSkillUnder(std::string skill, int number){

   do{
    if(skill == "admin"){
       if(skills.admin >= number){return true;}    
       return false;          
    }else if(skill == "advocate"){    
       if(skills.advocate >= number){return true;}
       return false;
    }else if(skill == "animals"){    
       if(skills.animals >= number){return true;}
       return false;
    }else if(skill == "art"){    
       if(skills.art >= number){return true;}
       return false;
    }else if(skill == "astrogation"){    
       if(skills.astrogation >= number){return true;}
       return false;
    }else if(skill == "broker"){    
       if(skills.broker >= number){return true;}
       return false;
    }else if(skill == "carouse"){    
       if(skills.carouse >= number){return true;}
       return false;
    }else if(skill == "deception"){    
       if(skills.deception >= number){return true;}
       return false;
    }else if(skill == "diplomat"){    
       if(skills.diplomat >= number){return true;}
       return false;
    }else if(skill == "drive"){    
       if(skills.drive >= number){return true;}
       return false;
    }else if(skill == "electronics"){    
       if(skills.electronics >= number){return true;}
       return false;
    }else if(skill == "engineer"){    
       if(skills.engineer >= number){return true;}
       return false;
    }else if(skill == "explosives"){    
       if(skills.explosives >= number){return true;}
       return false;
    }else if(skill == "flyer"){    
       if(skills.flyer >= number){return true;}
       return false;
    }else if(skill == "gambler"){    
       if(skills.gambler >= number){return true;}
       return false;
    }else if(skill == "gunner"){    
       if(skills.gunner >= number){return true;}
       return false;
    }else if(skill == "guncombat"){    
       if(skills.gunCombat >= number){return true;}
       return false;
    }else if(skill == "heavyweapons"){    
       if(skills.heavyWeapons >= number){return true;}
       return false;
    }else if(skill == "investigate"){    
       if(skills.investigate >= number){return true;}
       return false;
    }else if(skill == "jackofalltrades"){    
       if(skills.jackOfAllTrades >= number){return true;}
       return false;
    }else if(skill == "language"){    
       if(skills.language >= number){return true;}
       return false;
    }else if(skill == "leadership"){    
       if(skills.leadership >= number){return true;}
       return false;
    }else if(skill == "mechanic"){    
       if(skills.mechanic >= number){return true;}
       return false;
    }else if(skill == "medic"){    
       if(skills.medic >= number){return true;}
       return false;
    }else if(skill == "melee"){    
       if(skills.melee >= number){return true;}
       return false;
    }else if(skill == "navigation"){    
       if(skills.navigation >= number){return true;}
       return false;
    }else if(skill == "persuade"){    
       if(skills.persuade >= number){return true;}
       return false;
    }else if(skill == "pilot"){    
       if(skills.pilot >= number){return true;}
       return false;
    }else if(skill == "profession"){    
       if(skills.profession >= number){return true;}
       return false;
    }else if(skill == "recon"){    
       if(skills.recon >= number){return true;}
       return false;
    }else if(skill == "science"){    
       if(skills.science >= number){return true;}
       return false;
    }else if(skill == "seafarer"){    
       if(skills.seafarer >= number){return true;}
       return false;
    }else if(skill == "stealth"){    
       if(skills.stealth >= number){return true;}
       return false;
    }else if(skill == "steward"){    
       if(skills.steward >= number){return true;}
       return false;
    }else if(skill == "streetwise"){    
       if(skills.streetwise >= number){return true;}
       return false;
    }else if(skill == "survival"){    
       if(skills.survival >= number){return true;}
       return false;
    }else if(skill == "tactics"){    
       if(skills.tactics >= number){return true;}
       return false;
    }else if(skill == "vaccsuit"){    
       if(skills.vaccSuit >= number){return true;}
       return false;
    }else {
      std::cout << "No valid skills was set..."<<std::endl;
      std::cout <<"Enter a valid skill."<<std::endl;
      skill = "";
      return false;
    }
  }while(skill == "")
} 


bool Player::SetSkill(std::string skill, int valuechange){
  do{
    if(skill == "admin"){
       this->skills.admin += valuechange;
       return true;       
    }else if(skill == "advocate"){    
       this->skills.advocate += valuechange;
       return true;
    }else if(skill == "animals"){    
       this->skills.animals += valuechange;
       return true;
    }else if(skill == "art"){    
       this->skills.art += valuechange;
       return true;
    }else if(skill == "astrogation"){    
       this->skills.astrogation += valuechange; 
       return true;   
    }else if(skill == "broker"){    
       this->skills.broker += valuechange;
       return true;
    }else if(skill == "carouse"){    
       this->skills.carouse += valuechange;
       return true;
    }else if(skill == "deception"){    
       this->skills.deception += valuechange;
       return true;
    }else if(skill == "diplomat"){    
       this->skills.diplomat += valuechange;
       return true;
    }else if(skill == "drive"){    
       this->skills.drive+= valuechange;
       return true;
    }else if(skill == "electronics"){    
       this->skills.electronics += valuechange;
       return true;
    }else if(skill == "engineer"){    
       this->skills.engineer+= valuechange;
       return true;
    }else if(skill == "explosives"){    
       this->skills.explosives += valuechange;
       return true;
    }else if(skill == "flyer"){    
       this->skills.flyer+= valuechange;
       return true;
    }else if(skill == "gambler"){    
       this->skills.gambler+= valuechange;
       return true;
    }else if(skill == "gunner"){    
       this->skills.gunner+= valuechange;
       return true;
    }else if(skill == "guncombat"){    
       this->skills.gunCombat += valuechange;
       return true;
    }else if(skill == "heavyweapons"){    
       this->skills.heavyWeapons += valuechange;
       return true;
    }else if(skill == "investigate"){    
       this->skills.investigate += valuechange;
       return true;
    }else if(skill == "jackofalltrades"){    
       this->skills.jackOfAllTrades += valuechange;
       return true;
    }else if(skill == "language"){    
       this->skills.language+= valuechange;
       return true;
    }else if(skill == "leadership"){    
       this->skills.leadership += valuechange;
       return true;
    }else if(skill == "mechanic"){    
       this->skills.mechanic += valuechange;
       return true;
    }else if(skill == "medic"){    
       this->skills.medic += valuechange;
       return true;
    }else if(skill == "melee"){    
       this->skills.melee += valuechange;
       return true;
    }else if(skill == "navigation"){    
       this->skills.navigation+= valuechange;
       return true;
    }else if(skill == "persuade"){    
       this->skills.persuade += valuechange;
       return true;
    }else if(skill == "pilot"){    
       this->skills.pilot += valuechange;
       return true;
    }else if(skill == "profession"){    
       this->skills.profession += valuechange;
       return true;
    }else if(skill == "recon"){    
       this->skills.recon += valuechange;
       return true;
    }else if(skill == "science"){    
       this->skills.science += valuechange;
       return true;
    }else if(skill == "seafarer"){    
       this->skills.seafarer += valuechange;
       return true;
    }else if(skill == "stealth"){    
       this->skills.stealth += valuechange;
       return true;
    }else if(skill == "steward"){    
       this->skills.steward += valuechange;
       return true;
    }else if(skill == "streetwise"){    
       this->skills.streetwise += valuechange;
       return true;
    }else if(skill == "survival"){    
       this->skills.survival += valuechange;
       return true;
    }else if(skill == "tactics"){    
       this->skills.tactics += valuechange;
       return true;
    }else if(skill == "vaccsuit"){    
       this->skills.vaccSuit += valuechange;
       return true;
    }else {
      std::cout << "No valid skills was set..."<<std::endl;
      std::cout <<"Enter a valid skill."<<std::endl;
      skill = "";
      return false;
    }while(skill == "");
  }
} 
 

