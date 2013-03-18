all : pokeranch

pokeranch : AreaLuar.o Battle.o BattleScreen.o Home.o Item.o Kota.o main.o Monster.o MonsterBall.o MonsterEgg.o NPC.o Player.o Point.o Potion.o Screen.o SkillMonster.o StatusIncrease.o Store.o
	g++ -o pokeranch AreaLuar.o Battle.o BattleScreen.o Home.o Item.o Kota.o main.o Monster.o MonsterBall.o MonsterEgg.o NPC.o Player.o Point.o Potion.o Screen.o SkillMonster.o StatusIncrease.o Store.o

AreaLuar.o : AreaLuar.cpp
	g++ -c AreaLuar.cpp

Battle.o : Battle.cpp
	g++ -c Battle.cpp
	
BattleScreen.o : BattleScreen.cpp
	g++ -c BattleScreen.cpp
	
Home.o : Home.cpp
	g++ -c Home.cpp
	
Item.o : Item.cpp
	g++ -c Item.cpp
	
Kota.o : Kota.cpp
	g++ -c Kota.cpp
	
main.o : main.cpp
	g++ -c main.cpp
	
Monster.o : Monster.cpp
	g++ -c Monster.cpp
	
MonsterBall.o : MonsterBall.cpp
	g++ -c MonsterBall.cpp
	
MonsterEgg.o : MonsterEgg.cpp
	g++ -c MonsterEgg.cpp
	
NPC.o : NPC.cpp
	g++ -c NPC.cpp
	
Player.o : Player.cpp
	g++ -c Player.cpp
	
Point.o : Point.cpp
	g++ -c Point.cpp
	
Potion.o : Potion.cpp
	g++ -c Potion.cpp
	
Screen.o : Screen.cpp
	g++ -c Screen.cpp
	
SkillMonster.o : SkillMonster.cpp
	g++ -c SkillMonster.cpp
	
StatusIncrease.o : StatusIncrease.cpp
	g++ -c StatusIncrease.cpp
	
Store.o : Store.cpp
	g++ -c Store.cpp
	
run :
	./pokeranch

clean :
	rm -rf pokeranch *.o
