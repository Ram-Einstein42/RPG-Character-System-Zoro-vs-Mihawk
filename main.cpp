#include <iostream>
#include <string>

// character class
class Character{
    private:
        std::string name{};
        int health{};
        int maxHealth{};
        int attackPower{};

    public:
        Character(std::string charName, int startingHealth, int startingAttack) : name(charName), health(startingHealth), maxHealth(startingHealth), attackPower(startingAttack)
        {
        }

        // getter for name
        std::string getName() const
        {
            return name;
        }

        int getHealth() const
        {
            return health;
        }

        int getMaxHealth() const
        {
            return maxHealth;
        }

        int getAttackPower() const
        {
            return attackPower;
        }

        // damage take
        void takeDamage(int damage)
        {
            if (damage <= 0)
            {
                return;
            }
            else if (damage >= health)
            {
                health = 0;
            }
            else
            {
                health -= damage;
            }
        }

        // healing
        void heal(int amount)
        {
            if (amount <= 0)
            {
                return;
            }

            int missingHealth = getMaxHealth() - getHealth();

            if (amount >= missingHealth)
            {
                health = maxHealth;
            }
            else
            {
                health += amount;
            }
        }
        // attack each other
        void attack(Character& target)
        {
            target.takeDamage(attackPower);
        }

        // is alive or nahh?
        bool isAlive() const
        {
            return health > 0;
        }

};

int main()
{
    // objects
    Character zoro("Zoro", 100, 20);
    Character mihawk("Mihawk", 150, 30);
    zoro.attack(mihawk);
    mihawk.attack(zoro);
    // zoro
    std::cout << zoro.getName() << std::endl;
     
    std::cout << "Health: " << zoro.getHealth() << std::endl;
    std::cout << "Attack Power: " << zoro.getAttackPower() << std::endl;

    // mihawk
    std::cout << mihawk.getName() << std::endl;
  
    std::cout << "Health: " << mihawk.getHealth() << std::endl;
    std::cout << "Attack Power: " << mihawk.getAttackPower() << std::endl;

    return 0;
}