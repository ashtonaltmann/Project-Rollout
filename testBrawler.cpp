#include<iostream>
#include"Brawler.h"

int main(){ //convert into testBrawler or BrawlerDriver
    Brawler Ash(1,2,3,4,5,6,7,8);
    std::cerr << " brawler health " << Ash.health << 
    " brawler MovementSpeed " << Ash.movementSpeed << 
    " brawler Max Damage " << Ash.maxDamage <<
    " brawler Projectiles " << Ash.projectiles <<
    " brawler Range" << Ash.range <<
    " brawler Reloadtime " << Ash.reloadTime <<
    " brawler Super Charge " << Ash.superCharge <<
    " brawler Max Ammo " << Ash.maxAmmo <<std::endl;
}