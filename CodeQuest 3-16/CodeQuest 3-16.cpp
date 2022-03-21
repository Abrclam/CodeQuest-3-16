#include <iostream>
#include <string>
#include <vector>
#include<bits.h>
using namespace std;

string sandcounter(vector <string> numb); 

int main() {
	cout << "Enter number of cases: " << endl;
	int cases;
	string numpass;
	cin >> cases;
	//cout << sandcounter("23882732998014371873", "12198640218946090114");
	vector <string> numbers;
	while (cases > 0) {
		cout << "Enter number: ";
		cin >> numpass;
		numbers.push_back(numpass);
		cases -= 1;
	}
	cout << "Calculating..." << endl;
	cout << sandcounter(numbers);
	
}

string sandcounter(vector <string> numb) {
	string result = "";
	string resultpass = "0";
	//while (!numb.empty()) {
		if (numb.size() > 1) {
			for (int i = numb.size()-1; i >= 0; i--) {
				if (resultpass.length() > numb[i].length())
					swap(resultpass, numb[i]);



				int longness = resultpass.length();
				int long2 = numb[i].length();

				std::reverse(resultpass.begin(), resultpass.end());
				std::reverse(numb[i].begin(), numb[i].end());

				double pass = 0;

				for (int j = 0; j < longness; j++) {
					int sum = ((resultpass[j] - '0') + (numb[i][j] - '0') + pass);
					result.push_back(sum % 10 + '0');
					pass = sum / 10;
				}
				for (int j = longness; j < long2; j++) {
					int sum = ((numb[i][j] - '0') + pass);
					result.push_back(sum % 10 + '0');
					pass = sum / 10;
				}
				if (pass)
					result.push_back(pass + '0');
				std::reverse(result.begin(), result.end());
				
				numb.pop_back();
			}
		}
	//}
	return result;
}