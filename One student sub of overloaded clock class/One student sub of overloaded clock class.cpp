#include "Clock.h"
#include <thread>
#include <chrono>
using std::cout;
using std::cin;

int main()
{
	// define `Clock` objects and display their initial values
	//Clock midnight{ 0, 0, 0 };
	//Clock sunset{ 18, 30, 0 };
	//Clock workdayStart{ 8, 0, 0 };
	//cout << "All `Clock` objects:\n"
	//	<< "`midnight`:\t" << midnight << "\n"
	//	<< "`sunset`:\t" << sunset << "\n"
	//	<< "`workdayStart`:\t" << workdayStart << "\n\n";

	// compare with "less then"
	//cout << "Is `midnight` less then `workdayStart`?";
	//if (midnight < workdayStart)
	//	cout << "\n- Yes!\n\n";
	//else
	//	cout << "\n- No!\n\n";

	//// compare with "equal to"
	//cout << "Does `sunset` and `workdayStart` have the same initial time?";
	//if (sunset == workdayStart)
	//	cout << "\n- Yes!\n\n";
	//else
	//	cout << "\n- No!\n\n";

	//cout << "Wonderful! Let's make your own clock, and watch them run!\nPress ENTER to continue...\n";
	//cin.get();

	// create `userClock` with user submitted numbers
	int user_hours = 0, user_mins = 0, user_secs = 0;
	cout << "Please enter the time (in Army or 24 time), using spaces as delimiters:\n- ";
	cin >> user_hours >> user_mins >> user_secs;
	Clock userClock{ user_hours, user_mins, user_secs };
	cout << "\nProgram will now only close when you click \"X\", so enjoy your clocks!";

	// the clock loop
	// just increments and displays the current value of four clocks
	//for (int )

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::microseconds(1));
		//midnight.increment('h');
		//sunset.increment('m');
		//workdayStart.increment('s');
		//++midnight;
		//++sunset;
		//++workdayStart;
		++userClock;
		//system("CLS");
		//cout << "All `Clock` objects:\n"
		//	<< "`midnight`:\t" << midnight << "\n"
		//	<< "`sunset`:\t" << sunset << "\n"
		//	<< "`workdayStart`:\t" << workdayStart << "\n"
		cout << "`userClock`:\t" << userClock << "\n";
	}

	// user shouldn't reach this point
	cout << "how'd you get here? :o";
	return 0; // finish! [EXIT PRG]
}