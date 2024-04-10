#pragma once
#include <string>

class PowerPuffGirl {
public:
    virtual void Attack() = 0;
    virtual void TakeDamage(int damage) = 0;
    virtual int GetHealth() = 0;
    virtual std::string GetName() = 0;
    virtual int GetDamage() = 0;
};
