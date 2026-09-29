class Armor {
    public:
        int getDurability() const;
        float getDamageReduction() const;
        float takeDamageReduction(float damage);

        Armor() : 
            durability(0),
            damageReduction(0.0f)
        {
        };

        Armor(int durability, float damageReduction) : 
            durability(durability),
            damageReduction(damageReduction)
        {
        };

    private:
        int durability = 0;
        float damageReduction = 0.1f;
};