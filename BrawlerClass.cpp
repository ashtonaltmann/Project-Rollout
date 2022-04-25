#include <iostream> //for cout
using namespace std;

class brawler {
public:
    int health;
    double movementSpeed;
    int maxDamage;
    int projectiles;
    double range;
    double reloadTime;
    double superCharge;
    int maxAmmo;
    

    brawler(int h, double ms, int md, int p, double r, double rt, double sc, int ma){
        health = h;
        movementSpeed = ms;
        maxDamage = md;
        projectiles = p;
        range = r;
        reloadTime = rt;
        superCharge = sc;
        maxAmmo = ma;
    /*
    TODO: 	🥕 Finish SuperClass
    TODO: 	🥕 Progress: 🛑
    TODO: 	🥕 Comments
    */ 

};

class Lou : public brawler {

public:
    /*
    TODO: 	🥕 Finish SubClass
    TODO: 	🥕 Progress: 🛑
    TODO: 	🥕 Comments
    */ 
};

class Belle : public brawler {

public:
    /*
    TODO: 	🥕 Finish SubClass
    TODO: 	🥕 Progress: 🛑
    TODO: 	🥕 Comments
    */ 
};

class Jacky : public brawler {

     /*
    TODO: 	🥕 Finish SubClass
    TODO: 	🥕 Progress: 🛑
    TODO: 	🥕 Comments
    */ 

};

int main(){
    brawler Ash(1,2,3,4,5,6,7,8);
    std::cerr << " brawler health " << Ash.health << 
    " brawler MovementSpeed " << Ash.movementSpeed << 
    " brawler Max Damage " << Ash.maxDamage <<
    " brawler Projectiles " << Ash.projectiles <<
    " brawler Range" << Ash.range <<
    " brawler Reloadtime " << Ash.reloadTime <<
    " brawler Super Charge " << Ash.superCharge <<
    " brawler Max Ammo " << Ash.maxAmmo <<std::endl;
}