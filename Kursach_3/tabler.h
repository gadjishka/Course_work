#include <iostream>
#include <iomanip>

using namespace std;

ostream& FinishL(ostream& stream)
{
	stream << setfill('-') << setw(75) << '|' << setfill(' ');
	return stream;
}

ostream& shapka(ostream& stream)
{
	stream << endl << FinishL << endl;
	stream << setw(15) << "Company name"
		<< setw(15) << "Product name"
		<< setw(9) << "volume"
		<< setw(12) << "unit_cost"
		<< setw(8) << "metka" << endl;
	cout << FinishL;
	return stream;
}

ostream& FinishL2(ostream& stream)
{
	stream << setfill('-') << setw(20) << '|' << setfill(' ');
	return stream;
}

ostream& shapka2(ostream& stream)
{
	stream << endl << FinishL2 << endl;
	stream << setw(10) << "Company name" << setw(7) << "Metka" << endl;
	stream << FinishL2;
	return stream;
}
