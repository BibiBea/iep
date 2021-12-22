#include <iostream>
// #include "uncopyable.cpp"

class Driver/*: private Uncopyable*/{
    private:
    int points;
    std::string name, team;

    public:
    Driver(const int p, const std::string n, const std::string t)
    :points(p),
     name(n),
     team(t)
    {}

    Driver()
    :points(0),
     name(""),
     team("")
    {}

    Driver(const Driver &d)
    :points(d.points),
     name(d.name),
     team(d.team)
    {
        std::cout << "Copy construct\n";
    }

    Driver& operator=(const Driver& d){
        std::cout << "Copy operator\n";
        if (this == &d)
            return *this;
        this->points = d.points;
        this->name = d.name;
        this->team = d.team;
        return *this;
    }

    int getPoints(){
        return this->points;
    }

    std::string getName(){
        return this->name;
    }

    std::string getTeam(){
        return this->team;
    }

    ~Driver(){
        std::cout << "Destruct Driver!\n";
    }
};