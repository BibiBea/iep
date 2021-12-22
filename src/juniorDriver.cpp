#include <iostream>
#include <memory>
#include <thread>
#include "driver.cpp"
#include "lock.cpp"

class JuniorDriver: public Driver{
    private:
    std::string championship;
    
    public:
    JuniorDriver(const int p, const std::string n, const std::string t, const std::string c)
    :Driver(p, n, t),
     championship(c)
    {}

    JuniorDriver()
    :Driver(),
     championship("")
    {}

    JuniorDriver(const JuniorDriver& jd)
    :Driver(jd),
     championship(jd.championship)
    {
        std::cout << "JuniorDriver copy constructor\n";
    }

    JuniorDriver& operator=(const JuniorDriver& jd){
        std::cout << "JuniorDriver copy assignment operator\n";
        Driver::operator=(jd);
        championship = jd.championship;
        return *this;
    }

    std::string getChampionship(){
        return this->championship;
    }

    ~JuniorDriver(){
        std::cout << "Destruct JuniorDriver!\n";
    }
};

Driver* createDriver(int puncte, std::string nume, std::string echipa){
    return (new Driver(puncte, nume, echipa));
}

std::mutex m;

void win(){
    m.lock();
    std::cout << "Race Win!!" << "\n";
    m.unlock();
}

int main(){
    Driver charles(127, "Charles Leclerc", "Ferrari");
    std::cout << charles.getName() << " " << charles.getTeam() << " " << charles.getPoints() << "\n";

    Driver max(charles);
    Driver carlos;

    carlos = max = charles;
    
    JuniorDriver robert(135, "Robert Shwartzman", "Prema", "F2");
    JuniorDriver oscar = robert;
    std::cout << oscar.getChampionship() << "\n";

    std::unique_ptr<Driver> pDriver(createDriver(160, "Lando Norris", "McLaren"));
    std::cout << pDriver->getName() << "\n";
    // std::unique_ptr<Driver> pDriver1(pDriver);
    std::unique_ptr<Driver> pDriver1 = move(pDriver);
    // std::cout << pDriver->getName() << "\n";
    std::cout << pDriver1->getName() << "\n";
    // pDriver = pDriver1;
    pDriver = move(pDriver1);
    std::cout << pDriver->getName() << "\n";
    // std::cout << pDriver1->getName() << "\n";

    std::shared_ptr<Driver> pDriver2(createDriver(110, "Pierre Gasly", "AlphaTauri"));
    std::cout << pDriver2->getName() << "\n";
    std::shared_ptr<Driver> pDriver3(pDriver2);
    std::cout << pDriver2->getName() << "\n";
    std::cout << pDriver3->getName() << "\n";
    pDriver2 = pDriver3;
    std::cout << pDriver2->getName() << "\n";
    std::cout << pDriver3->getName() << "\n";

    Lock *m = new Lock();
    m->someFunction();
    m->~Lock();

    std::thread winner(win);
    std::thread winner1(win);
    winner.join();
    winner1.join();
}