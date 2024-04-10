#include<iostream>
#include<vector>
#include "MojoJojo.h"
#include "Profesor.h"
#include "Blossom.h"
#include "Bubbles.h"
#include "ButterCup.h"
using namespace std;

void Battle(std::vector<PowerPuffGirl*>& girls, MojoJojo& mojoJojo) {
    int turn = 1;
    while (mojoJojo.GetHealth() > 0 && !girls.empty()) {
        std::cout << "Turn " << turn << std::endl;
        for (auto it = girls.begin(); it != girls.end();) {
            PowerPuffGirl* girl = *it;
            mojoJojo.Attack(girl);
            if (mojoJojo.GetHealth() <= 0) {
                break;
            }
            if (girl->GetHealth() <= 0) {
                delete girl;
                it = girls.erase(it);
            }
            else {
                ++it;
            }
        }
        turn++;
    }

    if (mojoJojo.GetHealth() > 0) {
        PowerPuffGirl* target = mojoJojo.SelectTarget(girls);
        if (target) {
            std::cout << "MojoJojo attacks " << target->GetName() << std::endl;
            target->TakeDamage(mojoJojo.GetDamage());
        }
        else {
            std::cout << "MojoJojo has no target!" << std::endl;
        }
        std::cout << "MojoJojo wins!" << std::endl;
    }
    else {
        std::cout << "PowerPuff Girls win!" << std::endl;
    }

    
}

int main() {

    std::srand(static_cast<unsigned int>(std::time(0)));
	std::vector<std::string> ingredients = { "sugar", "spice", "spice", "everything_nice", "sugar" };
	Profesor profesor(ingredients);
	int numGirlsCreated = profesor.CreatePowerPuffGirls();
   
    for (int i = 0; i < numGirlsCreated; ++i) {
        int girlType = rand() % 3;
        if (girlType == 0) {
            PowerPuffGirl* girl = new Bubbles();
            profesor.AddGirl(girl);
        }
        else if (girlType == 1) {
            PowerPuffGirl* girl = new Blossom();
            profesor.AddGirl(girl);
        }
        else {
            PowerPuffGirl* girl = new ButterCup();
            profesor.AddGirl(girl);
        }
    }

	std::vector<PowerPuffGirl*> girls = profesor.GetGirls();
   
	MojoJojo MJ;

	Battle(girls, MJ);

	return 0;
}