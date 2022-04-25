#include"Brawler.h"
#include <iostream> //for cout
using namespace std;

    Brawler::Brawler(int h, double ms, int md, int p, double r, double rt, double sc, int ma) { //creating a brawler object
        health = h;
        movementSpeed = ms;
        maxDamage = md;
        projectiles = p; 
        range = r;
        reloadTime = rt;
        superCharge = sc;
        maxAmmo = ma;
    }
    Brawler::Brawler() { //default constructor just to initialize all values to 0 if needed 
        health = 0;
        movementSpeed = 0;
        maxDamage = 0;
        projectiles = 0;
        range = 0;
        reloadTime = 0;
        superCharge = 0;
        maxAmmo = 0;
    }
    Brawler::Brawler(Brawler &b) { //copy constructor if some brawlers have similar stats
        health = b.health;
        movementSpeed = b.movementSpeed;
        maxDamage = b.maxDamage;
        projectiles = b.projectiles;
        range = b.range;
        reloadTime = b.reloadTime;
        superCharge = b.superCharge;
        maxAmmo = b.maxAmmo;
    }
    /*
    TODO: 	🥕 Finish SuperClass
    TODO: 	🥕 Progress: ⏳
    TODO: 	🥕 Comments
    */ 
