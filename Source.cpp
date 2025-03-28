#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class car {
public:
	int size;
	string name;
	string model;
	car(int s, string n, string m) :size(s), name(n), model(m)
	{
		fstream file;
		file.open("cars.collection", ios::out | ios::app);

		file << size << "*" << name << "*" << model << "*" << endl;

		file.close();

	}
	void book();
	void add(vector<car>& cars);
	void rem(vector<car>& cars);

};
void car::book() {
	fstream file;
	int a;
	string nam;
	string mod;
	file.open("cars.collection", ios::in);
	cout << "Available cars in showroom:" << endl;

	while (file >> a)
	{
		file.ignore();
		getline(file, nam, '*');
		getline(file, mod, '*');
		cout << "Car Name: " << nam << " | Size: " << a << " | Model: " << mod << endl;
	}

	file.close();
}
void car::add(vector<car>& cars)
{
	string na;
	string mode;
	int si;
	cout << "enter the name of the car you want to add:" << endl;
	getline(cin, na);
	cout << "enter the model of this car:" << endl;
	getline(cin, mode);
	cout << "enter the size of the car" << endl;
	cin >> si;
	cars.push_back(car(si, na, mode));
}
void car::rem(vector<car>& cars)
{
	string nam;
	cout << "enter the car you want to remove:" << endl;
	cin.ignore();
	getline(cin, nam);
	for (auto i = cars.begin();i != cars.end();++i)
	{
		if (i->name == nam)
		{
			cars.erase(i);
			cout << "removed successfully:" << nam << endl;
		}
		else {  
			cout << "car not found:" << endl;
		}
	}
}
int main()
{
	cout << "we can add the cars first and then you can select your car:" << endl;
	cout << "press enter to add the cars in the showroom" << endl;
	cin.ignore();
	vector<car>cars;
	cars.push_back(car(4, "ferrari", "2014"));
	cars.push_back(car(5, "mehran", "2023"));
	cars.push_back(car(9, "alto", "2013"));
	int c;
	string ch = "yes";
	cout << "now your choice to book your car from the showroom of cars:" << endl;
	cout << "1) book order:" << endl;
	cout << "2) add the car: " << endl;
	cout << "3) remove the car:" << endl;
	cout << "4) exit showroom:" << endl;
	while (ch == "yes" || ch == "Yes" || ch == "YES") {
		cin >> c;
		switch (c)
		{
		case 1:
			cars[0].book();
			break;
		case 2:
			cars[0].add(cars);
			break;
		case 3:
			cars[0].rem(cars);
			break;
			case 4:
			cout<<"exiting showroom!"<<endl;
			default:
			cout<<"invalid correction:::"<<endl;

		}
		cout << "do you want to do more : yes :: no" << endl;
		cin >> ch;
	}


}