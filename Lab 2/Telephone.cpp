#include"Telephone.h"



Telephone::Telephone(){}

Telephone::Telephone(std::string mod, std::string num, std::string lcn, double sc) :
	model(mod), number(num), last_called_number(lcn), score(sc) {}

void Telephone::setModel(std::string mod) {
	model = mod;
}
void Telephone::setNumber(std::string num) {
	number = num;
}
void Telephone::setLCN(std::string lcn) {
	last_called_number = lcn;
}
void Telephone::setScore(double sc) {
	score = sc;
}


std::string Telephone::getNumber() {
	return number;
}

void Telephone::call(std::string num, double minutes) {
	last_called_number = num;
	score -= 0.5*minutes;
}

void Telephone::serialize() {
	std::ofstream file;
	file.open(number + ".txt");
	file << model << '\n';
	file << number << '\n';
	file << last_called_number << '\n';
	file << score << '\n';
	file.close();
}

void Telephone::deserialize() {
	std::ifstream file;
	file.open(number + ".txt");
	if (file.is_open()) {
		std::getline(file, model);
		std::getline(file, number);
		std::getline(file, last_called_number);
		file >> score;
	}
}

void Telephone::serialize(const std::string& filename) {
	std::ofstream file;
	file.open(filename);
	file << model << '\n';
	file << number << '\n';
	file << last_called_number << '\n';
	file << score << '\n';
	file.close();
}

void Telephone::deserialize(const std::string& filename) {
	std::ifstream file;
	file.open(filename);
	if (file.is_open()) {
		std::getline(file, model);
		std::getline(file, number);
		std::getline(file, last_called_number);
		file >> score;
	}
}

std::ostream& operator<<(std::ostream &out, const Telephone &tel)
{
	out << tel.model << '\n' 
		<< tel.number << '\n' 
		<< tel.last_called_number << '\n'
		<< tel.score << '\n';

	return out;
}
