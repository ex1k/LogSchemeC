#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	string input;
	int state = 33;
	int y1, y2;
	bool ext = true;;
	cin >> input;
	if (input.size() != 10) {
		cout << "Wrong inputs number" << 1;
		return 1;
	}
	vector<int> input_x;
	input_x.reserve(input.size());
	transform(begin(input), end(input), back_inserter(input_x), [](char c) { return c - '0'; });

	while (ext) {
		switch (state) {
		case 33:
			state = 0;
			(input_x[0] == 0 || input_x[1] == 0) ? input_x[0] = 0 : input_x[0] = 1;
			(input_x[2] == 1 || input_x[3] == 1) ? input_x[1] = 1 : input_x[1] = 0;
			(input_x[4] == 0 || input_x[5] == 0) ? input_x[2] = 0 : input_x[2] = 1;
			(input_x[6] == 1 || input_x[7] == 1) ? input_x[3] = 1 : input_x[3] = 0;
			(input_x[8] == 0 || input_x[9] == 0) ? input_x[4] = 0 : input_x[4] = 1;
			for (int i = 0; i < 5; i++) {
				state += input_x[i] * (1 << (4 - i));
				input_x.pop_back();
			}
			break;
		case 16:
		case 20:
		case 24:
			//000
			y1 = 0;
			y2 = 1;
			ext = false;
			break;
		case 17:
		case 18:
		case 19:
		case 21:
		case 22:
		case 23:
		case 25:
		case 26:
		case 27:
			//001
			y1 = 0;
			y2 = 0;
			ext = false;
			break;
		case 28:
			//010
			y1 = 1;
			y2 = 1;
			ext = false;
			break;
		case 29:
		case 30:
		case 31:
			//011;
			y1 = 1;
			y2 = 0;
			ext = false;
			break;
		case 0:
		case 4:
		case 8:
			//100;
			y1 = 1;
			y2 = 1;
			ext = false;
			break;
		case 1:
		case 2:
		case 3:
		case 5:
		case 6:
		case 7:
		case 9:
		case 10:
		case 11:
			//101;
			y1 = 1;
			y2 = 0;
			ext = false;
			break;
		case 12:
			//110;
			y1 = 1;
			y2 = 1;
			ext = false;
			break;
		case 13:
		case 14:
		case 15:
			//111;
			y1 = 1;
			y2 = 0;
			ext = false;
			break;
		default:
			break;
		}
	}
	
	cout << "y1: " << y1 << endl;
	cout << "y2: " << y2 << endl;
	cin >> input;
	return 0;
}