// COMP 2450 — Warden of the Foundations (Midterm 1)
// battle/Battle.cpp — YOU build the body.
//
// =====================================================================
// REQUIRED MECHANICS
// =====================================================================
// Re-read the public midterm page if anything below is unclear.
//
// MENU (at minimum, four options):
//   1. Attack          — damage the warden; warden retaliates that turn
//   2. Use item        — pick from inventory; effect; turn ends
//   3. Inspect Warden  — print warden's state; FREE action — turn does
//                        NOT end
//   4. Flee            — leave; gate stays closed
//
// END:
//   Victory  when wardenHP <= 0
//   Defeat   when playerHP <= 0
//   Fled     when the player chose Flee
//
// =====================================================================
// FLOOR-TIED REQUIREMENTS — ALL FOUR MUST APPEAR IN YOUR CODE
// =====================================================================
//
//   F0 (ADT)         — the available actions on a turn must live in a
//                      container of your choice. ABOVE the declaration,
//                      in a comment, name the ADT and defend it in one
//                      sentence (the same kind of defence Trial I Q1
//                      practiced — but this is a different collection
//                      than Q1's items menu; the right ADT may differ).
//
//   F1 (search)      — the Use-item branch MUST call findByName<Item>
//                      against hero.inventory to look up the item the
//                      player typed.
//
//   F2 (sort)        — when the items menu is displayed, sort the
//                      inventory at display time with a comparator
//                      (std::sort or your Floor 2 sortInventory). Pick
//                      a criterion (value — the healing-power stand-in
//                      — weight, or name) and document it in a comment.
//
//   F3 (templates +  — invalid menu input must `throw BattleException`
//      exceptions)     (ready skeleton in Battle.h) — or BagException
//                      where a genuinely bad index is the fault —
//                      caught INSIDE the battle loop so the player gets
//                      another prompt — not a crash, not an exit.
//
// =====================================================================
// WHAT THE GRADER WILL DO
// =====================================================================
//   1. cmake --build the project. If it does not compile, the Warden
//      has won by default.
//   2. Type `battle warden`, play through to BOTH a victory and a
//      defeat (or attempt to — items + RNG permitting).
//   3. Type a deliberately invalid menu choice (e.g., "9" for a
//      4-option menu). The game must NOT crash; it must re-prompt.
//   4. Open this file and find each of the four Floor ties. They must
//      be REAL — i.e., the menu actually runs through your container,
//      Use-item actually goes through findByName, the items menu is
//      actually sorted, the throw actually fires on bad input.

#include "Battle.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "../hero/Bag.h"
#include "../hero/BagException.h"
#include "../hero/Item.h"
#include "../bestiary/Search.h"
#include "../hero/Sort.h"
using namespace std;

namespace dungeon {

namespace {

// =====================================================================
// Tunable battle parameters. Edit to taste; document any tuning in
// encounter-notes.md so the grader knows what to expect.
// =====================================================================
constexpr int kPlayerStartHP   = 30;
constexpr int kWardenStartHP   = 50;
constexpr int kPlayerAttackDmg = 6;   // damage per Attack action
constexpr int kWardenAttackDmg = 4;   // warden's retaliation damage

enum class MenuActions { Attack, UseItem, Inspect, Flee };

struct MenuOptions {
    int number;
    string label;
    MenuActions actions;
};

void printMenu(Bag<MenuOptions> menu, int playerHP, int wardenHP) {
    cout << endl << "======Your Turn======" << endl;
    cout << "Your HP: " << playerHP << endl;
    cout << "Warden HP: " << wardenHP << endl;

    for (size_t i = 0; i < menu.size(); i++) {
        cout << menu.at(i).number << ". " << menu.at(i).label << endl;
    }
    cout << "--> ";
}

void useItem(Hero& hero, int& playerHP) {
    // I couldn't figure out how to get this to work on my own typed over from starter 4 plus I changed a little bit to get it to work with my code


    if (hero.inventory.empty()) {
        std::cout << "  Your satchel is empty.\n";
        return;
    }

    // F2 — sort the menu by value descending so the most valuable item
    // shows first. Sort routine reused from Floor 2; comparator is a
    // lambda.
    sortInventory(hero, "value desc");
    cout << "  Choose an item by name:\n";
    printInventory(hero);
    cout << "  > ";

    std::string name;
    getline(cin >> ws, name);
    if (name.empty()) {
        cout << "  You hesitate." << endl;
        return;
    }

    // F1 — findByName<Item> lookup.
    const Item* it = findByName<Item>(hero.inventory, name);
    if (!it) {
        // F3 — no such item: throw, caught by the battle-loop catch.
        throw BagException(0, hero.inventory.size());
    }

    if (it->name == "Healing potion") {
        playerHP = std::min(playerHP + 12, kPlayerStartHP);
        std::cout << "  You drink " << it->name << ". HP -> " << playerHP << ".\n";
    }
    else {
        std::cout << "  You ready " << it->name << " — but it is not a consumable.\n";
    }
}

}  // anonymous namespace

BattleOutcome runWardenBattle(Hero& hero) {
    // TODO — write the boss battle. Suggested outline (yours to refactor):
    //
    int playerHP = kPlayerStartHP;
    int wardenHP = kWardenStartHP;
    int choice;

    Bag<MenuOptions> menu;
    menu.push_back({ 1, "Attack",   MenuActions::Attack});
    menu.push_back({ 2, "Use Item", MenuActions::UseItem});
    menu.push_back({ 3, "Inspect",  MenuActions::Inspect});
    menu.push_back({ 4, "Flee",     MenuActions::Flee});
    
    while (playerHP > 0 && wardenHP > 0) {
    
        try {
            printMenu(menu, playerHP, wardenHP);
            cin >> choice;
            if (choice < 1 || choice > 4) {
                throw(BattleException("Input must be between 1 and 4."));
            }
            else if (choice == 1) {
                wardenHP -= kPlayerAttackDmg;
                cout << "You did " << kPlayerAttackDmg << "damage to Warden.  Warden HP --> ";
                if (wardenHP <= 0) {
                    cout << "0" << endl;
                }
                else { 
                    cout << wardenHP << endl;
                    playerHP -= kWardenAttackDmg;
                    cout << "Warden attacked back and did " << kWardenAttackDmg << " damage to You.  Your HP --> " << playerHP << endl;
                }
            }
            else if (choice == 2) {
                // this as well from 4 like useItem
                useItem(hero, playerHP);
                // Using an item ends the turn — the warden retaliates.
                if (wardenHP > 0 && playerHP > 0) {
                    playerHP -= kWardenAttackDmg;
                    cout << "The Warden strikes while you fumble.  Your HP -> " << playerHP << endl;
                    cout << "the Warden struck for " << kWardenAttackDmg << endl;
                }
            }
            else if (choice == 3) {
                cout << "Warden HP: " << wardenHP << "/" << kWardenStartHP << endl;
                cout << "No Visible Weaknesses (Free Action)." << endl;
            }
            else if (choice == 4) {
                return BattleOutcome::Fled;
            }
        }
        catch (const exception& e) {
             cout << "  " << e.what() << " Try again." << endl << endl;
             continue;   // re-prompt; turn does NOT advance
        }
    }

    if (wardenHP <= 0) {
        return BattleOutcome::Victory;
    }
    else if (playerHP <= 0) {
        return BattleOutcome::Defeat;
    }
    
}

}  // namespace dungeon
