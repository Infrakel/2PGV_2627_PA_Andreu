#include "Armor.hpp"

class Player {
    public:
        std::string name = "Aria";
        void increaseLife(int change);
        bool spendMoney(int change);
        void printPlayer();
        void printArmorStats();

        //speed ente minSpeed y maxSpeed
        void increaseSpeed(int change);
        void decreaseSpeed(int change);

        // armor settings
        void equipArmor(Armor armor_to_set);
        void unequipArmor(int slot_number);

        Armor* getArmor(int slot);

        Player(): 
            x(0.0f),
            y(0.0f),
            speed(5.0f),
            hp(100),
            maxHp(100),
            minSpeed(1),
            maxSpeed(100),
            gold(50)
        {
            // logic to put nullptr to every armor

            for (int i = 0; i < 10; i++) {
                armors[i] = nullptr;
            }
        }
    
    private:
        Armor* armors[10];
        float x = 0.0f;
        float y = 0.0f;
        float speed = 5.0f;
        int hp = 100;
        int maxHp = 100;
        float minSpeed = 1;
        float maxSpeed = 100;
        int gold = 50;

};