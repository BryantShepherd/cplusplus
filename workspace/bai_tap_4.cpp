#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int gio, phut, giay;
	char x;
	cin >> gio >> x >> phut >> x >> giay;
	int time_1 = gio*60*60 + phut*60 + giay;
	cin >> gio >> x >> phut >> x >> giay;
	int time_2 = gio*60*60 + phut*60 + giay;
	cout << time_1 << " " << time_2 << " " << endl; 
	int thoi_gian = time_2 - time_1;
	if (thoi_gian <= 0) thoi_gian += 24 * 60 * 60;

	int thoi_gian_gio = thoi_gian / (60*60);
	int thoi_gian_phut = (thoi_gian % (thoi_gian_gio * 60 * 60))/60;
	int thoi_gian_giay = thoi_gian - thoi_gian_gio * 60 * 60 - thoi_gian_phut * 60; 
	cout << thoi_gian_gio << ":" << thoi_gian_phut << ":" << thoi_gian_giay;
}