/* 
 * This is the solution of the Question 3 of the Chapter 24.x 
 * (Quiz session of Chapter 24:Inheritance from LearnCpp.com)
 * 
 * We’re going to write a simple game where you fight monsters. 
 * The goal of the game is to collect as much gold as you can 
 * before you die or get to level 20.
 */


#include <iostream>
#include <string>
#include <random>
#include <limits>

// return values of fightMonster function
#define CONTINUE_FIGHT 0
#define MONSTER_DEAD   1
#define PLAYER_DEAD    2
#define ECSAPED        3

// User valid inputs
#define YES   'y'
#define RUN   'r'
#define FIGHT 'f'

// Chance of getting magic potion is this %
#define POTION_CHANCE 30

// Magic Potions
#define HEALTH_SMALL    1
#define HEALTH_MEDIUM   3
#define HEALTH_LARGE    5
#define STRENGTH_SMALL  1
#define STRENGTH_MEDIUM 2
#define STRENGTH_LARGE  3
#define POISON_SMALL    1
#define POISON_MEDIUM   2
#define POISON_LARGE    3

// Scope for all enums and constants used in program
namespace Constants {
enum Potions {
  health_small,
  strength_small,
  poison_small,
  health_medium,
  strength_medium,
  poison_medium,
  health_large,
  strength_large,
  poison_large,
  max_potions
};
}

// Scope for Random number generation
namespace Random {
int get(int min, int max)
{
  std ::random_device rd{};
  std ::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
  std ::mt19937 mt{ss};
  std ::uniform_int_distribution gen{min, max};

  return gen(mt);
}
} // namespace Random


// scope of userinput functions
namespace UserInput {

bool has_unextracted_inputs()
{
  return !std::cin.eof() && std::cin.peek() != '\n';
}

char getCommandFromUser()
{
  char input;

  while (1) {
    std ::cin >> input;

    if (!std::cin) {
      std ::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    if (has_unextracted_inputs()) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Do again : ";
      continue;
    }
    return input;
  }
}
} // namespace UserInput

// Class of Creature
class Creature {
private:
  std::string m_name{};
  char m_symbol{};
  int m_health{};
  int m_damage{};
  int m_gold{};

public:
  Creature(const std ::string &name, char s, int health, int damage, int gold)
    : m_name{name}, m_symbol{s}, m_health{health}, m_damage{damage},
      m_gold{gold}
  {
  }
  // getters
  const std ::string &getName() const
  {
    return m_name;
  }

  const char getSymbol() const
  {
    return m_symbol;
  }

  const int getHealth() const
  {
    return m_health;
  }

  const int getDamage() const
  {
    return m_damage;
  }

  const int getGold() const
  {
    return m_gold;
  }

  bool isDead() const
  {
    return m_health <= 0;
  }
  // setters
  void reduceHealth(int x)
  {
    m_health -= x;
  }

  void addGold(int x)
  {
    m_gold += x;
  }

  void setDamage(int x)
  {
    m_damage += x;
  }

  void setHealth(int x)
  {
    m_health += x;
  }
};

// Class for Player
class Player : public Creature {
  int m_level{1};

public:
  Player(const std ::string &name,
         char s     = '@',
         int health = 10,
         int damage = 1,
         int gold   = 0,
         int level  = 1)
    : m_level{level}, Creature{name, s, health, damage, gold}
  {
  }

  void levelUp()
  {
    m_level++;
    setDamage(1);
  }

  const int getLevel() const
  {
    return m_level;
  }

  // If player reached level 20 , he/she Won
  bool hasWon() const
  {
    return m_level == 20;
  }
};

// Monster class
class Monster : public Creature {
public:
  enum Type { dragon, godzilla, zombie, orc, goblin, slime, max_types };

private:
  static inline Creature monsterData[]{
    {  "dragon", 'd', 20, 4, 100},
    {"godzilla", 'g', 12, 3,  80},
    {  "zombie", 'z',  8, 3,  50},
    {     "orc", 'o',  4, 2,  30},
    {  "goblin", 'G',  2, 2,  20},
    {   "slime", 's',  1, 1,  10}
  };

public:
  Monster(Type type) : Creature{monsterData[type]} {}

  static Type getRandomMonster()
  {
    int rand{};
    rand = Random::get(0, max_types - 1);

    return static_cast<Type>(rand);
  }
};


// Function which attacks the Monster
bool attackMonster(Player &p, Monster &m)
{
  std ::cout << "You hit the " << m.getName() << " for " << p.getDamage()
             << " damage\n";
  m.reduceHealth(p.getDamage());
  if (m.isDead()) {
    std ::cout << "You killed the " << m.getName() << '\n';
    p.levelUp();
    p.addGold(m.getGold());
    std ::cout << "You are now at level " << p.getLevel() << '\n';
    std ::cout << "You found " << p.getGold() << " gold\n";
    return true;
  }
  return false;
}

// Function to attack the player
bool attackPlayer(Player &p, Monster &m)
{
  std ::cout << "The " << m.getName() << " hit you for " << m.getDamage()
             << " damage\n";
  p.reduceHealth(m.getDamage());
  if (p.isDead()) {
    std ::cout << "You died at level " << p.getLevel() << " and with "
               << p.getGold() << " gold\n";
    std ::cout << "Too bad you can't take it with you!\n";
    return true;
  }
  return false;
}

// Function which manages the Fight
int fightMonster(Player &player, Monster &m)
{
  bool mDead{0}, pDead{0};
  std ::cout << "Run (r) or Fight (f): ";
  char c{UserInput::getCommandFromUser()};
  if (c == FIGHT) {
    mDead = attackMonster(player, m);

    if (!mDead) {
      pDead = attackPlayer(player, m);
    }
    if (pDead)
      return PLAYER_DEAD;
    else if (mDead)
      return MONSTER_DEAD;
  } else if (c == RUN) {
    int run = Random::get(0, 1);

    if (run) {
      std ::cout << "You successfully fled.\n";
      return ECSAPED;
    } else {
      std ::cout << "You failed to flee.\n";
      pDead = attackPlayer(player, m);
    }
    if (pDead)
      return PLAYER_DEAD;
  }
  return CONTINUE_FIGHT;
}

// Function which produces a potion
void magicPotion(Player &p)
{
  Constants::Potions potion{static_cast<Constants::Potions>(
    Random::get(0, Constants::max_potions - 1))};
  std ::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
  char y{UserInput::getCommandFromUser()};
  if (y == YES) {
    switch (potion) {
    case Constants::health_small:
      p.setHealth(HEALTH_SMALL);
      std ::cout << "You drank a Small potion of Health\n";
      break;
    case Constants::health_medium:
      p.setHealth(HEALTH_MEDIUM);
      std ::cout << "You drank a Medium potion of Health\n";
      break;
    case Constants::health_large:
      p.setHealth(HEALTH_LARGE);
      std ::cout << "You drank a Large potion of Health\n";
      break;
    case Constants::strength_small:
      p.setDamage(STRENGTH_SMALL);
      std ::cout << "You drank a Small potion of Strength\n";
      break;
    case Constants::strength_medium:
      p.setDamage(STRENGTH_MEDIUM);
      std ::cout << "You drank a Medium potion of Strength\n";
      break;
    case Constants::strength_large:
      p.setDamage(STRENGTH_LARGE);
      std ::cout << "You drank a Large potion of Strength\n";
      break;
    case Constants::poison_small:
      p.reduceHealth(POISON_SMALL);
      std ::cout << "You drank a Small potion of Poison\n";
      break;
    case Constants::poison_medium:
      p.reduceHealth(POISON_MEDIUM);
      std ::cout << "You drank a Medium potion of Poison\n";
      break;
    case Constants::poison_large:
      p.reduceHealth(POISON_LARGE);
      std ::cout << "You drank a Large potion of Poison\n";
      break;
    default:
      break;
    }
  }
}

void printMenu(Player &p, Monster &m)
{
  std ::cout << "\n\nCurrent Stats\n\n";
  std ::cout << "Player : Health = " << p.getHealth() << '\n';
  std ::cout << "Player : Damage = " << p.getDamage() << '\n';
  std ::cout << "Player : Gold = " << p.getGold() << "\n\n";
  std ::cout << "Monster : Health = " << m.getHealth() << '\n';
  std ::cout << "Monster : Damage = " << m.getDamage() << '\n';
  std ::cout << "Monster : Gold = " << m.getGold() << "\n\n";
}

int main()
{
  std ::cout << "Enter your name : ";
  std ::string name{};
  std ::cin >> name;
  std ::cout << "Welcome , " << name << '\n';
  Player player{name};
  std::cout << "You have " << player.getHealth() << " health and is carrying "
            << player.getGold() << " gold.\n";


  Monster m{Monster::getRandomMonster()};
  std ::cout << "You have encountered a " << m.getName() << " ("
             << m.getSymbol() << ")\n";

  while (!player.hasWon()) {
    printMenu(player, m);

    int ret = fightMonster(player, m);

    if (ret == MONSTER_DEAD || ret == ECSAPED) {
      int potion{Random::get(1, 100) <= POTION_CHANCE};
      if (potion && ret == MONSTER_DEAD) {
        magicPotion(player);
        if (player.isDead()) {
          std ::cout << "Player Dead\n";
          return -1;
        }
      }

      m = Monster::getRandomMonster();
      std ::cout << "You have encountered a " << m.getName() << " ("
                 << m.getSymbol() << ")\n";
    }

    if (ret == PLAYER_DEAD) {
      std ::cout << "Player Dead\n";
      return -1;
    }
  }

  std ::cout << "\nYou won the game with " << player.getGold() << " in hand\n";
  return 0;
}