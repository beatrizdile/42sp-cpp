#include "Zombie.hpp"

Zombie::Zombie(std::string newName){
    this->name = newName;
}

Zombie::~Zombie(){
    std::cout << "Destroying " << this->name << std::endl;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
