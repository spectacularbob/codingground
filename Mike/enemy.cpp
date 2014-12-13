#include "enemy.h"
#include "weapon.h"

const int PAWN_HEALTH = 10;
const int ELITE_HEALTH = 35;
const int BOSS_HEALTH = 80;
const int HEALTH_REWARD_DIVISOR = 5;
const int FIRE_DELAY = 10;

Enemy::Enemy(World* worldRef, Hero* dude, Weapon* mainWeapon, EnemyLevel lev) {
    facing = LEFT;
    heroPtr = dude;
    worldPtr = worldRef;
    weapons.push_back(mainWeapon);
    currentWeapon = 0;
    level = lev;
    count = 0;
    switch (level) {
        case PAWN:
            head = "-";
            body = "}";
            health = calculateHealth;
            healthReward = health / HEALTH_REWARD_DIVISOR;
            wait = FIRE_DELAY;
            break;
            
        case ELITE:
            head = "+";
            body = "&";
            health = calculateHealth;
            healthReward = health / HEALTH_REWARD_DIVISOR;
            wait = FIRE_DELAY;
            break;
            
        case BOSS:
            head = "@";
            body = "H";
            health = calculateHealth;
            healthReward = health / HEALTH_REWARD_DIVISOR;
            wait = FIRE_DELAY;
            break;
            
        default:
            break;
    }
}
void Enemy::update() {
    if (worldPtr->mode == SIDEVIEW) {
        if (count < wait) {
            count++;
        } else {
            count = 0;
            switch (weapons[currentWeapon]->getWeapon()) {
                case FIST:
                    Drawable* fire = new Fist(calcDir());
                    break;
                    
                case PISTOL:
                    Drawable* fire = new Pistol(calcDir());
                    break;
                    
                case FIRE_BALL:
                    Drawable* fire = new FireBall(calcDir());
                    break;
                    
                case ELEC_BALL:
                    Drawable* fire = new ElecBall(calcDir());
                    break;
                    
                default:
                    break;
            }
        }
        if (health <= 0 || heroPtr->health <= 0) {
            worldRef->endFight();
        }
    }
}

int Enemy::calculateHealth() {
    switch (level) {
        case PAWN:
            if (heroPtr->getHealth() <= PAWN_HEALTH) {
                return PAWN_HEALTH;
            }
            return PAWN_HEALTH + heroPtr->getHealth() / HEALTH_REWARD_DIVISOR;
            break;
            
        case ELITE:
            if (heroPtr->getHealth() <= ELITE_HEALTH) {
                return ELITE_HEALTH;
            }
            return ELITE_HEALTH + heroPtr->getHealth() / HEALTH_REWARD_DIVISOR;
            break;
            
        case BOSS:
            if (heroPtr->getHealth() <= BOSS_HEALTH) {
                return BOSS_HEALTH;
            }
            return BOSS_HEALTH + heroPtr->getHealth() / HEALTH_REWARD_DIVISOR;
            break;
            
        default:
            return PAWN_HEALTH;
            break;
    }
}





