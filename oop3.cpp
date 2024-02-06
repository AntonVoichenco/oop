#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Character {
protected:
    string name;
    int health;
    int power;

public:
    Character(string _name, int _health, int _power) : name(_name), health(_health), power(_power) {}

    string getName() const {
        return name;
    }
    int getHealth() const {
        return health;
    }
    bool isAlive() const {
        return health > 0;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }

    void attack(Character& target) {
        int damage = rand() % power + 1;
        target.takeDamage(damage);
        cout << name << " àòàêóåò " << target.getName() << " íà " << damage << " óðîíà " << endl;
    }
};

class Hero : public Character {
public:
    Hero(string _name, int _health, int _power) : Character(_name, _health, _power) {}

    void heroAttack(Character& target) {
        attack(target);
        cout << name << " âûêðèêèâàåò ãåðîè÷åñêèé áîåâîé êëè÷!" << endl;
    }
};

class Monster : public Character {
public:
    Monster(string _name, int _health, int _power) : Character(_name, _health, _power) {}

    void monsterAttack(Character& target) {
        attack(target);
        cout << name << " óãðîæàþùå ðû÷èò!" << endl;
    }
};

void printCharacters(const vector<Hero>& heroes, const vector<Monster>& monsters) {
    cout << "Ãåðîè:" << endl;
    for (const auto& hero : heroes) {
        cout << hero.getName() << " (Çäîðîâüå: " << hero.getHealth() << ")" << endl;
    }

    cout << "Ìîíñòðû:" << endl;
    for (const auto& monster : monsters) {
        cout << monster.getName() << " (Çäîðîâüå: " << monster.getHealth() << ")" << endl;
    }
}

void simulateBattle(vector<Hero>& heroes, vector<Monster>& monsters) {
    srand(static_cast<unsigned>(time(nullptr)));

    while (!heroes.empty() && !monsters.empty()) {
        printCharacters(heroes, monsters);

        for (int i = 0; i < heroes.size(); i++) {
            if (!monsters.empty()) {
                int indexMonster;
                cout << "Ãåðîé " << heroes[i].getName() << ", âûáåðèòå íîìåð ìîíñòðà äëÿ àòàêè: ";
                cin >> indexMonster;

                if (indexMonster < 1 || indexMonster > monsters.size()) {
                    cout << "Íåêîððåêòíûé íîìåð ìîíñòðà." << endl;
                    i--;  
                    continue;
                }

                heroes[i].heroAttack(monsters[indexMonster - 1]);

                if (!monsters[indexMonster - 1].isAlive()) {
                    cout << monsters[indexMonster - 1].getName() << " ïîáåæäåí!" << endl;
                    monsters.erase(monsters.begin() + indexMonster - 1);
                }
            }
        }

        for (int i = 0; i < monsters.size(); i++) {
            if (!heroes.empty() && heroes[i].isAlive()) {
                int heroIndex = rand() % heroes.size();
                monsters[i].monsterAttack(heroes[heroIndex]);

                if (!heroes[heroIndex].isAlive()) {
                    cout << heroes[heroIndex].getName() << " ïîáåæäåí!" << endl;
                    heroes.erase(heroes.begin() + heroIndex);
                }
            }
        }
    }

    if (heroes.empty()) {
        cout << "Ìîíñòðû ïîáåæäàþò!" << endl;
    }
    else {
        cout << "Ãåðîè ïîáåæäàþò!" << endl;
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    do {
        cout << "========== Ìåíþ ==========" << endl;
        cout << "1. Èãðàòü" << endl;
        cout << "2.  ûéòè èç ïðîãðàììû" << endl;
        cout << "==========================" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
        {
            vector<Hero> heroes;
            heroes.push_back(Hero("Hero 1", 100, 20));
            heroes.push_back(Hero("Hero 2", 120, 18));
            heroes.push_back(Hero("Hero 3", 80, 25));

            vector<Monster> monsters;
            monsters.push_back(Monster("Monster 1", 80, 15));
            monsters.push_back(Monster("Monster 2", 100, 50));
            monsters.push_back(Monster("Monster 3", 120, 10));

            simulateBattle(heroes, monsters);
        }
        break;
        case 2:
            cout << " ûõîä èç ïðîãðàììû." << endl;
            break;
        default:
            cout << "Íåêîððåêòíûé âûáîð. Ïîïðîáóéòå ñíîâà." << endl;
        }

    } while (choice != 2);

    return 0;
}
