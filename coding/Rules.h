#pragma once

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Regels {
public:
    virtual bool celMoetLeven(bool leeft, int buren) = 0;
};

class StandaardRegels : public Regels {
public:
    bool celMoetLeven(bool leeft, int buren) override {
        return leeft ? (buren == 2 || buren == 3) : (buren == 3);
    }
};

class HighLifeRegels : public Regels {
public:
    bool celMoetLeven(bool leeft, int buren) override {
        return leeft ? (buren == 2 || buren == 3) : (buren == 3 || buren == 6);
    }
};

class DayNightRegels : public Regels {
public:
    bool celMoetLeven(bool leeft, int buren) override {
        if (leeft) {
            return buren == 3 || buren == 4 || buren == 6 || buren == 7 || buren == 8;
        } else {
            return buren == 3 || buren == 6 || buren == 7 || buren == 8;
        }
    }
};

// Voeg hier alternatieve regels toe...

