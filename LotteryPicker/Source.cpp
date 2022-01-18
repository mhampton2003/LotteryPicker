//Maya Hampton
//This is my own work

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//declares functions
vector<int> getNumbers();
void setPowerball(vector<int>&);
void showNumbers(const vector<int>& v);


int main() {
	//sets random seed
	srand(time(NULL));
	vector<int> lotteryPicker;

	int userNum;
	string numCont = "yes";
	//whie the user wants numbers, it will keep asking how many they want to see at a time
	while (numCont == "yes") {
		cout << "How many lottery numbers would you like to see? ";
		cin >> userNum;

		//prints out how many numbers user asked for
		for (int i = 0; i < userNum; i++) {
			lotteryPicker = getNumbers();
			setPowerball(lotteryPicker);
			showNumbers(lotteryPicker);
		}
		cout << "Would you like to see more numbers? Type yes to continue" << endl;
		cin >> numCont;
	}

	return 0;
}

//sets vector to have 5 nonrepeating numbers in ascending order
vector<int> getNumbers()
{
	//sets 5 random numbers between 1 and 69
	vector<int> lotteryNum = {0, 0, 0, 0, 0};
	for (int i = 0; i < 5; ++i) {
		lotteryNum[i] = 1 + rand() % 69;
	}

	//no repeating values while starting index is less than 5
	//if values at the same indicies are equal, it sets it to a new random value
	int startIndex = 0;
	while (startIndex < lotteryNum.size()) {
		for (int i = 0; i < lotteryNum.size(); i++) {
			for (int j = i + 1; j < lotteryNum.size(); j++) {
				if (lotteryNum[i] == lotteryNum[j]) {
					lotteryNum[i] = 1 + rand() % 69;
				}
			}
			startIndex += 1;
		}
	}

	//sorts into ascending order
	//if the value to the left is bigger than the value to the right it switches the values
	for (int i = 0; i < lotteryNum.size(); i++) {
		for (int j = i + 1; j < lotteryNum.size(); j++) {
			if (lotteryNum[i] > lotteryNum[j]) {
				int temp = lotteryNum[i];
				lotteryNum[i] = lotteryNum[j];
				lotteryNum[j] = temp;
			}
		}
	}

	return lotteryNum;
}

//sets the powerball value to a random value between 1 and 26
void setPowerball(vector<int>& ln) {
	ln.push_back(1 + rand() % 26);
}

//prints out the first 5 numbers then prints "PB" and the last powerball number
void showNumbers(const vector<int>& v) {
	for (int i = 0; i < 5; i++) {
		cout << v[i] << " ";
	}
	cout << "PB " << v[5] << endl;
}

