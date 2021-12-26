#include "Zombie.hpp"

int main(void)
{
	// Stack allocation
	Zombie zombie_stack1(std::string("stack1"));
	Zombie zombie_stack2(std::string("stack2"));

	zombie_stack1.announce();
	zombie_stack2.announce();

	// Heap allocation
	Zombie *zombie_heap1 = newZombie("Heap1");
	Zombie *zombie_heap2 = newZombie("Heap2");

	zombie_heap1->announce();
	zombie_heap2->announce();

	randomChump(std::string("Heap3"));

	delete zombie_heap1;
	delete zombie_heap2;
}
