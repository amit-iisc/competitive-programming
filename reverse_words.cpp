#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){

	int t;
	string str;

	scanf("%d", &t);

	std::getline(cin,str);

	for(int test = 0;test < t; test++){

		std::getline(cin,str);

		stringstream ss(str);
		string words;
		vector <string> result;

		while(ss >> words){

			result.push_back(words);
		}
		reverse(result.begin(),result.end());

		for(int i = 0; i < result.size(); i++){

			if(i){
				printf(" ");
			}
			printf("%s", result[i].c_str());
		}
		printf("\n");
	
	}
}