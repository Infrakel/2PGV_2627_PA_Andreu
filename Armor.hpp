class Armor {
    public:
        float getDurability() const;
        float getDamageReduction() const;
        void reduceDurability(float damage);
        float takeDamageReduction(float damage);

        Armor() : 
            durability{0},
            damageReduction{0.1f}
        {
        };

        Armor(int durability, float damageReduction) : 
            durability{durability},
            damageReduction{damageReduction}
        {
        };

    private:
        int durability;
        float damageReduction;
};