#ifndef BUREUCRATGRADE_HPP
#define BUREUCRATGRADE_HPP

class BureaucratGrade
{
	public:
		BureaucratGrade();
		BureaucratGrade(BureaucratGrade const &other);
		BureaucratGrade& operator=(BureaucratGrade const &other);
		~BureaucratGrade();
		static void checkBureaucratGradeException(int grade);
};

#endif