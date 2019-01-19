#include <iostream>
#include <string>

using namespace std;

class animal
{
  private:
    int numOfLegs;
    int numOfEyes;
    string skinType;

  public:
    animal(int legs, int eyes, string skin)
    {
        this->numOfLegs = legs;
        this->numOfEyes = eyes;
        this->skinType = skin;
    }
    int getNumOfLegs(void) { return numOfLegs; }
    virtual string speak() { return "rarrrrr"; }
};

class dog : public animal
{
  private:
    string name;

  public:
    dog(string inName) : animal(4, 2, "fur")
    {
        this->name = inName;
    }
    string getName(void) { return name; }
    string speak() { return "Woof"; }
};

class cat : public animal
{
  private:
    string name;

  public:
    cat(string inName) : animal(4, 2, "fur")
    {
        this->name = inName;
    }
    string getName(void) { return name; }
    string speak() { return "Meow"; }
};

class spider : public animal
{
  public:
    bool isScary;
    spider(bool scary) : animal(8, 8, "exoskeleton")
    {
        this->isScary = scary;
    }
    string speak() { return "grrrrr"; }
};

class ladybird : public animal
{
  private:
    int numOfSpots;

  public:
    ladybird(int spots) : animal(6, 2, "exoskeleton")
    {
        this->numOfSpots = spots;
    }
};

class fish : public animal
{
  private:
    string name;

  public:
    fish(string inName) : animal(0, 2, "scale")
    {
        this->name = inName;
    }
    string speak() { return "Nothing, it's a fish"; }
};

int main()
{
    cat myCat("fluffy");
    spider mySpider(true);
    ladybird MyLadybird(6);
    animal myAnimal(4, 4, "scales");
    dog mydog("Chester");
    fish myfish("Jeremy");

    cout << "Cats name is " << myCat.getName() << " and says " << myCat.speak() << " and has " << myCat.getNumOfLegs() << " legs" << endl;

    cout << "Spider is " << (mySpider.isScary ? "Scary" : "Not Scary") << " and says " << mySpider.speak() << endl;

    // cout << "ladybird has " << MyLadybird.numOfSpots << " spots and says " << MyLadybird.speak() << endl;

    cout << "ladybird says " << MyLadybird.speak() << endl;

    cout << "animal says " << myAnimal.speak() << " but should an animal class be instantiated ??" << endl;

    cout << "\n"
         << endl;
    return 0;
}

/* Modify nheritance.cpp to include two further kinds of animal, with appropriate characteristics for each. */