#include <iostream>
using namespace std;

class Human {
	private:
		string name;
		int strength;
		int mana;

    public:
        Human(string myName, int myStrength=10, int myMana=5) {
            name = myName;
            strength = myStrength;
            mana = myMana;
        }
        virtual ~Human() {
        }
        string getName() {
            return name;
        }
        int getStrength() {
            return strength;
        }
        int getMana() {
            return mana;
        }
};

class Elven {
	private:
		string name;
		int strength;
		int mana;

    public:
        Elven(string myName, int myStrength=5, int myMana=10) {
            name = myName;
            strength = myStrength;
            mana = myMana;
        }
        virtual ~Elven() {
        }
        string getName() {
            return name;
        }
        int getStrength() {
            return strength;
        }
        int getMana() {
            return mana;
        }
};

class Warrior {
	public:
	    Warrior() {
	    }
	    virtual ~Warrior() {
        }
		void meleeAttack(int s) {
			std::cout<<"attacks with melee weapon for " << s << " points" <<endl;
		}
};

class Mage {
	public:
	    Mage() {
	    }
	    virtual ~Mage() {
        }
		void castSpell(int m) {
			std::cout<<"casts spell for " << m << " points"<<endl;
		}
};


class HumanWarrior : public Human, public Warrior {
	public:
	    HumanWarrior(string myName, int myStrength=10, int myMana=5) : Human(myName, myStrength, myMana) {
	    }
	    virtual ~HumanWarrior() {
        }
		void attack() {
			std::cout<< getName() << " the human warrior ";
			meleeAttack(getStrength());
		}
};

class HumanMage : public Human, public Mage {
	public:
	    HumanMage(string myName, int myStrength=10, int myMana=5) : Human(myName, myStrength, myMana) {
	    }
	    virtual ~HumanMage() {
        }
		void attack() {
			std::cout<< getName() << " the human mage ";
			castSpell(getMana());
		}
};

class ElvenWarrior : public Elven, public Warrior {
	public:
	    ElvenWarrior(string myName, int myStrength=5, int myMana=10) : Elven(myName, myStrength, myMana) {
	    }
	    virtual ~ElvenWarrior() {
        }
		void attack(){
			std::cout<< getName() << " the elven warrior ";
			meleeAttack(getStrength());
		}
};

class ElvenMage : public Elven, public Mage {
	public:
	    ElvenMage(string myName, int myStrength=5, int myMana=10) : Elven(myName, myStrength, myMana) {
	    }
	    virtual ~ElvenMage() {
        }
		void attack(){
			std::cout<< getName() << " the elven mage ";
			castSpell(getMana());
		}
};

int main(void){

	std::cout<<endl;

	HumanWarrior* hw = new HumanWarrior("Bob");
	HumanMage* hm = new HumanMage("Tim");
	ElvenWarrior* ew = new ElvenWarrior("Bobby the Elf");
	ElvenMage* em = new ElvenMage("Galadriel");

	hw->attack();
	hm->attack();
	ew->attack();
	em->attack();

	delete hw;
	delete hm;
	delete ew;
	delete em;

	return 0;
}