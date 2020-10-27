#pragma once
#include<string>
#include<fstream>


class Telephone
{
	std::string model;
	std::string number;
	std::string last_called_number;
	double score;


public:
	Telephone(){}

	Telephone(std::string mod, std::string num, std::string lcn, double sc):
		model(mod), number(num), last_called_number(lcn), score(sc){}

	void setModel(std::string mod) {
		model = mod;
	}
	void setNumber(std::string num) {
		number = num;
	}
	void setLCN(std::string lcn) {
		last_called_number = lcn;
	}
	void setScore(double sc) {
		score = sc;
	}


	std::string getNumber() {
		return number;
	}

	void call(std::string num, double minutes) {
		last_called_number = num;
		score -= 0.5*minutes;
	}

	void serialize() {
		std::ofstream file;
		file.open(number + ".txt");
		file << model << '\n';
		file << number << '\n';
		file << last_called_number << '\n';
		file << score << '\n';
		file.close();
	}
	
	void deserialize() {
		std::ifstream file;
		file.open(number + ".txt");
		if (file.is_open()) {
			std::getline(file, model);
			std::getline(file, number);
			std::getline(file, last_called_number);
			file >> score;
		}
	}

	void serialize(const std::string& filename) {
		std::ofstream file;
		file.open(filename);
		file << model << '\n';
		file << number << '\n';
		file << last_called_number << '\n';
		file << score << '\n';
		file.close();
	}

	void deserialize(const std::string& filename) {
		std::ifstream file;
		file.open(filename);
		if (file.is_open()) {
			std::getline(file, model);
			std::getline(file, number);
			std::getline(file, last_called_number);
			file >> score;
		}
	}
};

