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
        Character(std::string charName, int startingHealth, int startingAttack)
        {
            name = charName;
            health = startingHealth;
            maxHealth = startingHealth;
            attackPower = startingAttack;
        }
        // getter for name
        std:: string getName() const 
        {
            return name;
        }
    };
int main()
{
    Character zoro("Zoro", 100, 20);
    Character mihawk("Mihawk", 150, 30);
    std::cout << zoro.getName() << std:: endl;
    std::cout << mihawk.getName() << std:: endl;
    return 0;
}