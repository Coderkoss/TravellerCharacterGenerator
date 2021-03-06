#include "SkillSet.h"

class Player{
	
  
public:
  
  SkillSet skills;
  std::string uniEvent;  
  bool psiTrainingEnabled;
  bool eligibleForGraduation;
  bool isPrisoner;  
  int allies,enemies,rivals,friends;
  int Str,Dex,End,Edu,Soc,Intt;
  int strDiceMod,dexDiceMod,endDiceMod,eduDiceMod,socDiceMod,inttDiceMod;
  Player();  
  void DisplaySkills();
  void UpdateDiceMod();
  bool RollOnSkill(std::string skill,int value);
  bool isSkillUnder(std::string skill, int number);
  bool SetSkill(std::string skill,int valuechange ); 
  void DisplayStats();
  int RollDice(int x);
  void RollCharacteristics();
}; 