//TODO: Setting a default screen size
#define _WIN32_WINNT 0x0501
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "Player.h"
#include "time.h"
#include <string>


enum Color {RED=12,BLUE=9,GREEN=10,RESET=15};//blue is 9
enum FontWeight{NORMAL = 400, BOLD=600, HEADER=1000};
  
const int DEFAULT_FONT_SIZE_X = 10;
const int DEFAULT_FONT_SIZE_Y = 16;

void PCE_levelZeroSkill();
void PCE_levelOneSkill();
bool Choice();
void zeroskillCheck(int& skill,int& i);
void SetConsoleSize();
void SetColor(int num);
void FontSize(int x,int y,int fontWeight);
void ResetTextAttr();
void cls();
void SetBackgroundSkills();
void PCE_Skills_Display();
void PCE_Event();
Player player;

int main(){
  srand (time(NULL));  
  //player.DisplayStats();
  //std::cout<< "=================================="<<std::endl;  
  //player.RollCharacteristics();
  //std::cout << "Rolling for Characteristics"<<std::endl;
  //std::cout << "+++++++++++++++++++++++++++++++++++++++"<<std::endl;
  //cls();
  // =====================================
  //SetBackgroundSkills();
  
  //NOTE:This is the Pre-career Section of code 
  {//Pre-Career Education
   std::cout << "Do you want to go to School?"<<std::endl;
   if(Choice()){
       int eduPick = 0;
       std::cout << "Go to University enter: 1 "<<std::endl;
       std::cout << "Go to Military Academy enter: 2"<<std::endl;
       while(eduPick != 1 && eduPick != 2){
          std::cin >> eduPick;
          if(eduPick != 1 && eduPick != 2){
            std::cout << "Enter 1 for University"<<std::endl;
            std::cout << "Enter 2 for Military Academy"<<std::endl;
          }        
       }
       
       //University section
       if(eduPick == 1){
         std::cout << "You have choosen to go to University."<<std::endl;
         bool entry = player.RollDice(2) + player.eduDiceMod >= 7;
  
       if(true){
            player.eligibleForGraduation = true;
            std::cout << "Congrats you pass entry into University!!!"<<std::endl;
            // PCE_Skills_Display();
            // PCE_levelZeroSkill();
            // PCE_Skills_Display();
            // PCE_levelOneSkill();
            // //Increase EDU by +1           
            player.Edu += 1;
            bool check;
            check = player.CheckSkillLevel("admin",-2);
            std::cout << check<<std::endl;

            //PCE_Event();
            //roll for graduation 7 or higher if you roll 11 you get honours
           
            //Apply graduation benefits
         }
         else
         {
           std::cout << "Sorry you did not make it into school"<<std::endl;
         }

       }
       else if(eduPick == 2){
        //TODO: Finish making the going to Miltary Academy
         std::cout << "You have choosen to go to Military Academy."<<std::endl;
         if(player.RollDice(2) + player.eduDiceMod >= 7){
            std::cout << "You did not make it into school you will have to find a real job"<<std::endl;
            //code for you making it into school
            //Choose a level 0 and level 1 skill 
            //increase edu + 1
            //roll for graduation 7 or higher if you roll 11 you get honours
            //Apply graduation benefits
         }else{
           std::cout << "You did not make it into school"<<std::endl;
           // 
         }
       }       
    }//No uni for you!!!! 

	}
  std::cin.get();  
  return 0;
}
//Gameplay Methods
  void PCE_levelOneSkill(){
    //This function assigns a level one skill to a list of open skills
    //It does not care about what level the skill is
    //It will make it level 1 no matter what
    int oneskill;
    int countdown = 0;
    while(countdown == 0)
    {            
    std::cout<< "What level 1 skill do you want?"<<std::endl;
    std::cin >> oneskill;
    switch(oneskill){
      case 0:
      player.skills.admin = 1;              
      break;
      case 1:
      player.skills.advocate = 1;
      break;
      case 2:
      player.skills.animals = 1;
      break;
      case 3:
      player.skills.art = 1;
      break;
      case 4:
      player.skills.astrogation = 1;
      break;
      case 5:
      player.skills.electronics = 1;
      break;
      case 6:
      player.skills.engineer = 1;
      break;
      case 7:
      player.skills.language = 1;
      break;
      case 8:
      player.skills.medic = 1;
      break;
      case 9:
      player.skills.navigation = 1;
      break;
      case 10:
      player.skills.profession = 1;
      break;
      case 11:
      player.skills.science = 1;
      break;
    }
    countdown--;    
    }
  }
  void PCE_levelZeroSkill(){
          //TODO:This method needs comments
          int zeroskill;
            int i = 0;
            while(i == 0)
            {            
            std::cout<< "What 0 skill do you want?"<<std::endl;
            std::cin >> zeroskill;
            switch(zeroskill){
              case 0:
              zeroskillCheck(player.skills.admin,i);
              break;
              case 1:
              zeroskillCheck(player.skills.advocate,i);
              break;
              case 2:
              zeroskillCheck(player.skills.animals,i);
              break;
              case 3:
              zeroskillCheck(player.skills.art,i);
              break;
              case 4:
              zeroskillCheck(player.skills.astrogation,i);
              break;
              case 5:
              zeroskillCheck(player.skills.electronics,i);
              break;
              case 6:
              zeroskillCheck(player.skills.engineer,i);
              break;
              case 7:
              zeroskillCheck(player.skills.language,i);
              break;
              case 8:
              zeroskillCheck(player.skills.medic,i);
              break;
              case 9:
              zeroskillCheck(player.skills.navigation,i);
              break;
              case 10:
              zeroskillCheck(player.skills.profession,i);
              break;
              case 11:
              zeroskillCheck(player.skills.science,i);
              break;
            }
            i--;
            int oneskill;

          }
      
  }
  void PCE_Skills_Display(){

   std::string uni_skills[] = {"Admin","Advocate","Animals(training or veterinary)","Art",
                                  "Astrogation","Electronics(any)","Engineer(any)","Language(any)",
                                  "Medic","Navigation","Profession(any)","Science(any)"};
            //Prints the uni array with format
            for (int i = 0; i < sizeof(uni_skills)/sizeof(uni_skills[0]); ++i)
            {
              std::cout << uni_skills[i]<< " : " << i << std::endl;              
            } 
            
  }
  void PCE_Event(){
  //TODO: Work on commented out seciton!!

  std::string events [] = 
  {
    "You are approached by an underground (and highly illegal) psionic group who sense potential in you. You may test your PSI and attempt to enter the Psion career in any subsequent term.",//{0}
    "Your time in education is not a happy one and you suffer a deep tragedy;perhaps you become hopelessly addicted to drink or drugs, a failed romance leaves you in tatters, or a fatal accident involving a close friend shakes your confidence. You crash and fail to graduate.",//{1}
    "A supposedly harmless prank goes wrong and someone gets hurt, physically or emotionally. Roll SOC 8+. If you succeed, gain a Rival. If you fail, gain an Enemy. If you roll 2, you must take the Prisoner career in your next term.",//{2}
    "Taking advantage of youth, you party as much as you study. Gain Carouse 1.",//{3}
    "You become involved in a tightly knit clique or group and make a pact to remain friends forever, wherever in the galaxy you may end. Gain D3 Allies.",//{4}
    "Life Event. Roll on the Life Events table",//{5}
    "You join a political movement. Roll SOC 8+. If successful, you become a leading figure. Gain one Ally within the movement but gain one Enemy in wider society.",//{6}
    "You develop a healthy interest in a hobby or other area of study. Gain any skill of your choice, with the exception of Jack-of-all-Trades, at level 0.",//{7}
    "A newly arrived tutor rubs you up the wrong way and you work hard to overturn their conclusions. Roll 9+ on any skill you have learned during this term. If successful, you provide a truly elegant proof that soon becomes accepted as the standard approach. Gain a level in the skill you rolled on and the tutor as a Rival.",//{8}
    "War comes and a wide-ranging draft is instigated. You can either flee and join the Drifter career next term or be drafted (roll 1D: 1-3 Army, 4-5 Marine, 6 Navy). Either way, you do not graduate this term. However, if you roll SOC 9+, you can get enough strings pulled to avoid the draft and complete your education – you may attempt graduation normally and are not drafted.",//{9}
    "You gain wide-ranging recognition of your initiative and innovative approach to study. Increase your SOC by +1."//{10}
  };
  std::cout << "Rolling for Event"<<std::endl;
  int twoDSix = player.RollDice(2);
  switch(9){
    case 2:
    player.uniEvent = events[0];
    player.psiTrainingEnabled = true;
    std::cout << player.uniEvent<<std::endl;  
    break;
    case 3:
    player.uniEvent = events[1];
    std::cout << player.uniEvent << std::endl;
    player.eligibleForGraduation = false; 
    break;
    case 4:    
    player.uniEvent  = events[2];
    std::cout << player.uniEvent << std::endl;
    if(player.RollDice(2) + player.socDiceMod > 8){
      player.rivals += 1;
    }else if (player.RollDice(2) + player.socDiceMod == 2){
      player.eligibleForGraduation =false;
      player.isPrisoner = true;
    }else{
        player.enemies += 1;
    }
    break;
    case 5:
    player.uniEvent  = events[3];
    std::cout << player.uniEvent << std::endl;
    player.skills.carouse = 1;
    break;
    case 6:
    player.uniEvent  = events[4];
    std::cout << player.uniEvent << std::endl;
    player.allies = player.RollDice(3);
    break;
    case 7:
    player.uniEvent  = events[5];
    std::cout << player.uniEvent << std::endl;
    //TODO:Roll on the life event table page 44
    break;
    case 8:
    player.uniEvent  = events[6];
    std::cout << player.uniEvent << std::endl;
    if(player.RollDice(2) + player.socDiceMod >8){
      player.allies += 1;
      player.enemies += 1;
    }
    break;
    case 9:
    player.uniEvent  = events[7];
    {
      std::string tempSkill =" ";
      std::cout << player.uniEvent << std::endl;
      std::cout<<"Choose any skill for level one besides jackofalltrades"<<std::endl;
      do{
        getline(std::cin,tempSkill);
        if(tempSkill == "jackofalltrades"){tempSkill = "";}

      }while(!player.SetSkill(tempSkill,0)); 
    }
    
    break;
    case 10:
    player.uniEvent  = events[8];
    std::cout << player.uniEvent << std::endl;
    /*
    roll 9+ on any skill
      if true gain a level in that skill
      also gain a rival  
    */
   
    break;
    case 11:
    player.uniEvent  = events[9];
    std::cout << player.uniEvent << std::endl;
    /*
    flee
      Drifter career next term
      don't graduate
    join
      drafted roll 1d 1-3=army 4-5 marine 6 navy
      don't graduate
    socCheck roll a 9+ avoid draft

    */

    break;
    case 12:
    player.uniEvent  = events[10];
    std::cout << player.uniEvent << std::endl;
    player.Soc+=1;
    break;    
    }
  }
  void zeroskillCheck(int& skill,int& i){
    if(skill >= 0){
        std::cout << "This skill is already zero. Choose another skill."<<std::endl; 
        i++;   
    }else {
        skill = 0;
    }
  }
//Gameplay Methods

//Console helper methods
  void SetBackgroundSkills(){
  //TODO: see if I can get this to work with the zeroskillCheck with this method
  player.DisplaySkills();
  player.eduDiceMod = 0;
  int numberOfSkills;
  switch (player.eduDiceMod){
   case -3:
   numberOfSkills = 0;
   break;
   case -2:
   numberOfSkills = 1;
   break;
   case -1:
   numberOfSkills = 2;
   break;
   case 0:
   numberOfSkills = 3;
   break;
   case 1:
   numberOfSkills = 4;
   break;
   case 2:
    numberOfSkills = 5;     
   break;
   case 3:
   numberOfSkills = 6;     
   break;
   default :
   break;     
   }
   std::string bgskills[] = {"Admin = 1      ","Animals = 2    ", "Art = 3        ",
                        "Athletics = 4  ","Carouse = 5    ", "Drive = 6      ",
                        "Electronics = 7","Flyer = 8      ", "Language = 9   ",
                        "Mechanic = 10  ","Medic = 11     ", "Profession = 12",
                        "Science = 13   ","Seafarer = 14  ", "Streetwise = 15",
                        "Survival = 16  ","Vacc Suit = 17 "};
   std::cout << bgskills[0]  <<"\t\t"<<bgskills[1] <<"\t\t"<<bgskills[2]  <<"\t\t"<<bgskills[3] << std::endl;
   std::cout << bgskills[4]  <<"\t\t"<<bgskills[5] <<"\t\t"<<bgskills[6]  <<"\t\t"<<bgskills[7] << std::endl;
   std::cout << bgskills[8]  <<"\t\t"<<bgskills[9] <<"\t\t"<<bgskills[10] <<"\t\t"<<bgskills[11]<< std::endl;
   std::cout << bgskills[12] <<"\t\t"<<bgskills[13]<<"\t\t"<<bgskills[14] <<"\t\t"<<bgskills[15]<< std::endl;
   std::cout << bgskills[16] <<std::endl;
      
   int skillchoice;
   while(numberOfSkills > 0){
        std::cin >> skillchoice;
        switch(skillchoice - 1){
          case 0:
          zeroskillCheck(player.skills.admin,numberOfSkills);
            break;
          case 1:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 2:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 3:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 4:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 5:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 6:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 7:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 8:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 9:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 10:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 11:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 12:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 13:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 14:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 15:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;
          case 16:
          zeroskillCheck(player.skills.animals,numberOfSkills);
          break;                    
        }
        numberOfSkills--;
        std::cout <<numberOfSkills<<std::endl;
   }
  
  }
  void SetColor(int num){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,num);
  }
  void FontSize(int x, int y,int fontWeight){
  CONSOLE_FONT_INFOEX cfi;
  cfi.cbSize = sizeof(cfi);
  cfi.nFont = 0;
  cfi.dwFontSize.X = x;
  cfi.dwFontSize.Y = y;
  cfi.FontFamily = FF_DONTCARE;
  cfi.FontWeight =fontWeight;
  //wcscpy(cfi.FaceName, L"Consolas");//Chose your font
  SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),FALSE,&cfi);
  }
  void ResetTextAttr(){
  SetColor(15);
  FontSize(DEFAULT_FONT_SIZE_X,DEFAULT_FONT_SIZE_Y,NORMAL);
  }
  void ResetConsole(){
    ResetTextAttr();
  }
  void SetConsoleSize(){
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD size;
  size.X = 100;
  size.Y = 40;
  SMALL_RECT rect;
  rect.Top = 0;
  rect.Left = 0;
  rect.Bottom = size.Y;
  rect.Right = size.X;

  SetConsoleScreenBufferSize(console,size);
  SetConsoleWindowInfo(console,1,&rect);
  //getch();
  }
  
  void cls( )
  {
   HANDLE hConsole;
   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD coordScreen = { 0, 0 };    // home for the cursor 
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi; 
   DWORD dwConSize;
   //the number of character cells in the current buffer. 
  
   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
   // Fill the entire screen with blanks.
   if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer 
                                    (TCHAR) ' ',     // Character to write to the buffer
                                    dwConSize,       // Number of cells to write 
                                    coordScreen,     // Coordinates of first cell 
                                    &cCharsWritten ))// Receive number of characters written
   {
      return;
   }
   // Get the current text attribute.
   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }
   // Set the buffer's attributes accordingly.
   if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer 
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize,        // Number of cells to set attribute 
                                    coordScreen,      // Coordinates of first cell 
                                    &cCharsWritten )) // Receive number of characters written
   {
      return;
   }
   // Put the cursor at its home coordinates.
   SetConsoleCursorPosition( hConsole, coordScreen );
  }
  bool Choice(){

  std::cout<< "Enter y = Yes or n = No"<<std::endl;
  char pick = ' ';
  while(pick != 'n'&& pick != 'y' && 
        pick != 'Y'&& pick != 'N') {
    std::cin >> pick;
    if(pick != 'n' && pick != 'y' && 
        pick != 'Y'&& pick != 'N')
    {
      std::cout << "You need to Enter a valid pick; n or y"<<std::endl;      
    }
  }
  if(pick != 'n' && pick != 'N'){
   return true;
  }else{
   return false;    
  }
  }
