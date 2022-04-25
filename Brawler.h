#ifndef _Brawler_H_
#define _Brawler_H_
#include<iostream>
using namespace std;

class Brawler {
public:
    int health;
    double movementSpeed;
    int maxDamage;
    int projectiles;       //Each stat a brawler can have
    double range;
    double reloadTime;
    double superCharge;
    int maxAmmo;

    Brawler(int h, double ms, int md, int p, double r, double rt, double sc, int ma);//creating a brawler object
    Brawler(); //default constructor just to initialize all values to 0 if needed
    Brawler(Brawler &b); //copy constructor if some brawlers have similar stats
    void setHealth(int i){
        health = i;
    }
    void setMovementSpeed(double i){
        movementSpeed = i;
    }
    void setMaxDamage(int i){
        maxDamage = i;
    }
    void setProjectiles(int i){
        projectiles = i;
    }                           //All stat set functions in order to change them depending on starpowers/gadgets
    void setRange(int i){       //Also useful for future-proofing if stats are changed by game developers
        range = i;
    }
    void setReloadTime(double i){
        reloadTime = i;
    }
    void setSuperCharge(double i){
        superCharge = i;
    }
    void setMaxAmmo(int i){
        maxAmmo = i; 
    }
};

class Colt : public Brawler {
    public:
        //Gadget 1
        void speedLoader() { //instantly reloads 2 ammo
            
        }
        //Gadget 2
        void silverBullet() { //next attack is one powerful shot that deals as much damage as 2 of his regular bullets
            setMaxDamage(/*gotta do the math on this*/);
        }
        //Starpower 1
        void slickBoots() {
            setMovementSpeed(813.6);
        }
        //Starpower 2
        void magnumSpecial() { //main attack range and bullet speed are increased by 11%.
            setRange(9.9);
        }
};

class Lou : public Brawler {
public:
    //Gadget 1
    void iceBlock() { //invulnerable for 1s

    }
    //Starpower 1
    void superCool() {//opponents on super area get gradually frozen (like his attack)

    }
    //Starpower 2
    void hypothermia() {//opponents lose up to 50% reload speed based on how frozen they are


    }
};

class Belle : public Brawler {
//G: trap on the ground that will explode when triggered by an opponent. The trap deals 500 damage, and slows down anyone within its blast radius for 3s.
//SP1: gains 25% shield whenever her projectile hits a target
//SP2: being marked by super prevents target from reloading for 3s
public:
    /*
    TODO: 	🥕 Finish SubClass
    TODO: 	🥕 Progress: 🛑
    TODO: 	🥕 Comments
    */ 
};
//G: moves 20% faster for 3s
//SP1: when damaged, converts 30% of that damage into a groundbreaker attack
//SP2: reduces damage taken by 15%
class Jacky : public Brawler {

     /*
    TODO: 	🥕 Finish SubClass
    TODO: 	🥕 Progress: 🛑
    TODO: 	🥕 Comments
    */ 

};

#endif //_Brawler_H_