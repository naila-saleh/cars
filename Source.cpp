#include<iostream>
#include <vector>
#include<math.h>
#include<algorithm>
#include<fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
int MAXSIZE = 1000;
struct Car {
	int id;
	char make[20];
	char model[20];
	int year;
	char color[20];
	int engine;
	int price;
};
void menu() {
	cout << "1) Add a car record\n";
	cout << "2) Delete a car record\n";
	cout << "3) Update a car record\n";
	cout << "4) view all car records\n";
	cout << "5) view cars with price less than value\n";
	cout << "6) view cars by  car make\n";
	cout << "7) view all cars sorted by price\n";
	cout << "8) view all cars sorted by year\n";
	cout << "9) save\n";
	cout << "10) quit\n";
}
void updateRec(Car* arr, int n) {
	cout << "enter a car ID to update : ";
	int ID;
	cin >> ID;
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (arr[i].id == ID) {
			f = false;
			Car a;
			cout << "enter a new value for each field :\n";
			cout << "\nmake : "; cin >> a.make;
			cout << "\nmodel : "; cin >> a.model;
			cout << "\nyear : "; cin >> a.year;
			cout << "\ncolor : "; cin >> a.color;
			cout << "\nengine : "; cin >> a.engine;
			cout << "\nprice : "; cin >> a.price;
			cout << "\nThe new values for this ID are :\nmake : " << a.make << "\nmodel : "
				<< a.model << "\nyear : " << a.year << "\ncolor : " << a.color << "\nengine : "
				<< a.engine << "\nprice : " << a.price << endl;
			cout << "1- confirm\n2- cancel\n";
			int m; cin >> m;
			if (m == 1) {
				memcpy(arr[i].make, a.make, 20 * sizeof(char));
				memcpy(arr[i].model, a.model, 20 * sizeof(char));
				arr[i].year = a.year;
				memcpy(arr[i].color, a.color, 20 * sizeof(char));
				arr[i].engine = a.engine;
				arr[i].price = a.price;
			}
			break;
		}
	}
	if (f)cout << "unvailable ID";
}
void addRecord(Car* arr, int& n) {
	if (n < MAXSIZE) {
		Car a;
		cout << "enter the values of the new Car :\n";
		cout << "ID : "; cin >> a.id;
		cout << "\nmake : "; cin >> a.make;
		cout << "\nmodel : "; cin >> a.model;
		cout << "\nyear : "; cin >> a.year;
		cout << "\ncolor : "; cin >> a.color;
		cout << "\nengine : "; cin >> a.engine;
		cout << "\nprice : "; cin >> a.price;
		cout << "\nThe new values for this ID are :\nmake : " << a.make << "\nmodel : "
			<< a.model << "\nyear : " << a.year << "\ncolor : " << a.color << "\nengine : "
			<< a.engine << "\nprice : " << a.price << endl;
		cout << "1- confirm\n2- cancel\n";
		int m; cin >> m;
		if (m == 1) {
			arr[n].id = a.id;
			memcpy(arr[n].make, a.make, 20 * sizeof(char));
			memcpy(arr[n].model, a.model, 20 * sizeof(char));
			arr[n].year = a.year;
			memcpy(arr[n].color, a.color, 20 * sizeof(char));
			arr[n].engine = a.engine;
			arr[n].price = a.price;
			n++;
		}
	}
	else cout << "no more space for new Cars";
}
void deleteRecord(Car* arr, int& n) {
	cout << "enter a car ID to delete : ";
	int ID; cin >> ID;
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (arr[i].id == ID) {
			f = false;
			cout << "Do you want to delete this info about this ID ?\n ID : " << arr[i].id << "\nmake : "
				<< arr[i].make << "\nmodel : " << arr[i].model << "\nyear : " << arr[i].year << "\ncolor : "
				<< arr[i].color << "\nengine : " << arr[i].engine << "\nprice : " << arr[i].price;
			cout << "\n1- confirm\n2- cancel\n";
			int m; cin >> m;
			if (m == 1) {
				arr[i].id = arr[n - 1].id;
				memcpy(arr[i].make, arr[n - 1].make, 20 * sizeof(char));
				memcpy(arr[i].model, arr[n - 1].model, 20 * sizeof(char));
				arr[i].year = arr[n - 1].year;
				memcpy(arr[i].color, arr[n - 1].color, 20 * sizeof(char));
				arr[i].engine = arr[n - 1].engine;
				arr[i].price = arr[n - 1].price;
				n--;
			}
		}
	}
	if (f)cout << "unvailable ID";
}
void display(Car* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "ID : " << arr[i].id << "\nmake : " << arr[i].make << "\nmodel : " << arr[i].model
			<< "\nyear : " << arr[i].year << "\ncolor : " << arr[i].color << "\nengine : " << arr[i].engine
			<< "\nprice : " << arr[i].price;
		cout << "\n__________________________________________\n";
	}
}
void displayByPrice(Car* arr, int n) {
	cout << "enter a price : ";
	int price; cin >> price;
	for (int i = 0; i < n; i++) {
		if (arr[i].price <= price) {
			cout << "ID : " << arr[i].id << "\nmake : " << arr[i].make << "\nmodel : " << arr[i].model
				<< "\nyear : " << arr[i].year << "\ncolor : " << arr[i].color << "\nengine : " << arr[i].engine
				<< "\nprice : " << arr[i].price;
			cout << "\n__________________________________________\n";
		}
	}
}
void displayByModel(Car* arr, int n) {
	cout << "enter a make : ";
	char s[20]; cin >> s;
	for (int i = 0; i < n; i++) {
		if (arr[i].make == s) {
			cout << "ID : " << arr[i].id << "\nmake : " << arr[i].make << "\nmodel : " << arr[i].model
				<< "\nyear : " << arr[i].year << "\ncolor : " << arr[i].color << "\nengine : " << arr[i].engine
				<< "\nprice : " << arr[i].price;
			cout << "\n__________________________________________\n";
		}
	}
}
void displayByYear(Car* arr, int n) {
	cout << "enter a yaer : ";
	int year; cin >> year;
	for (int i = 0; i < n; i++) {
		if (arr[i].year == year) {
			cout << "ID : " << arr[i].id << "\nmake : " << arr[i].make << "\nmodel : " << arr[i].model
				<< "\nyear : " << arr[i].year << "\ncolor : " << arr[i].color << "\nengine : " << arr[i].engine
				<< "\nprice : " << arr[i].price;
			cout << "\n__________________________________________\n";
		}
	}
}
bool sortByPrice(Car& a, Car& b) {
	return a.price < b.price;
}
void displaySortedPrice(Car* arr, int n) {
	sort(&arr[0], &arr[n], sortByPrice);
	for (int i = 0; i < n; i++) {
		cout << "ID : " << arr[i].id << "\nmake : " << arr[i].make << "\nmodel : " << arr[i].model
			<< "\nyear : " << arr[i].year << "\ncolor : " << arr[i].color << "\nengine : " << arr[i].engine
			<< "\nprice : " << arr[i].price;
		cout << "\n__________________________________________\n";
	}
}
void save(Car* arr, int n) {
	ofstream myfile;
	myfile.open("cars.txt", ios::out);
	if (myfile.is_open()) {
		myfile << n << endl;
		for (int i = 0; i < n; i++) {
			myfile << arr[i].id << ' ';
			myfile << arr[i].make << ' ';
			myfile << arr[i].model << ' ';
			myfile << arr[i].year << ' ';
			myfile << arr[i].color << ' ';
			myfile << arr[i].engine << ' ';
			myfile << arr[i].price << endl;
		}
		myfile.close();
	}
	else {
		cout << "can't save this file!";
	}
}
void run() {
	int n;
	Car* arr = new Car[MAXSIZE];
	ifstream filein;
	filein.open("cars.txt");
	if (filein.is_open()) {
		filein >> n;
		for (int i = 0; i < n; i++) {
			filein >> arr[i].id;
			filein >> arr[i].make;
			filein >> arr[i].model;
			filein >> arr[i].year;
			filein >> arr[i].color;
			filein >> arr[i].engine;
			filein >> arr[i].price;
		}
		filein.close();
	}
	else {
		cout << "could not open file!\nDo you want to creat one?\t(Y/N)\n";
		char ans;
		cin >> ans;
		if (ans == 'Y') {
			cout << "enter a number of Cars you want to creat : ";
			cin >> n;
			cout << "enter info of Cars : ";
			for (int i = 0; i < n; i++) {
				cout << "ID : "; cin >> arr[i].id;
				cout << "make : "; cin >> arr[i].make;
				cout << "model : "; cin >> arr[i].model;
				cout << "year : "; cin >> arr[i].year;
				cout << "color : "; cin >> arr[i].color;
				cout << "engine : "; cin >> arr[i].engine;
				cout << "price : "; cin >> arr[i].price;
				cout << "\n_____________________________________________\n";
			}
		}
		else if (ans == 'N') {
			cout << "Thanks for using our app!";
			return;
		}
	}
	menu();
	cout << "select an operation : ";
	int r; cin >> r;
	while (r != 10) {
		if (r == 1)addRecord(arr, n);
		else if (r == 2)deleteRecord(arr, n);
		else if (r == 3)updateRec(arr, n);
		else if (r == 4)display(arr, n);
		else if (r == 5)displayByPrice(arr, n);
		else if (r == 6)displayByModel(arr, n);
		else if (r == 7)displaySortedPrice(arr, n);
		else if (r == 8)displayByYear(arr, n);
		else if (r == 9)save(arr, n);
		else cout << "not available choice!!";
		cout << "\n*********************************************\n";
		menu();
		cout << "select an operation : ";
		cin >> r;
	}
	cout << "Thanks for using our app!";
}
int main() {
	run();
	return 0;
}
