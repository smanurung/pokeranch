/*
	author Sonny Theo Tumbur
*/

#ifndef NPC_H
#define NPC_H

class NPC{
	public :
		//ctor
		NPC();
		NPC(char*, char*);
		
		//cctor
		NPC(const NPC&);
		
		//operator=
		NPC& operator=(const NPC&);
		
		//dtor
		~NPC();
		
		//function member
		void talk();
	
	private :
		char* nama;
		//Monster MonsterNPC[];
		char* warnaNPC;
};

#endif
