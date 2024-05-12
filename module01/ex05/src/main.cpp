#include "Harl.hpp"

int main()
{
	Harl robot;
	robot.complain("DEBUG");
	robot.complain("INFO");
	robot.complain("WARNING");
	robot.complain("ERROR");

	robot.complain("batata");
}
