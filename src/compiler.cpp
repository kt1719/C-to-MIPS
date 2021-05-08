#include<iostream>
#include <map>
#include "ast.hpp"

extern int yylex(void);
extern int yyparse();
std::map < std::string, std::pair<std::string, std::pair<int, bool>>> mymap;
std::map < std::string, NodePtr> functionmapping;
std::string destReg = "$2";
int localcounter = -1;
int localcounterfloat = -1;
int makeRegUnique = 0;
int memorystorenumber = 0;
bool variableintoreg = false;
std::vector<bool> freeregs;
int makeLabelUnique = -1;
int argumentcount = 0;
int funcnamecount = 0;
int enumeratornumber = 0;
int globalmemorystorenumber = 111100;
const int offset = 111100;
bool globalvariableindicator = true;
std::map < std::string, std::string> sizeofmap;

std::string makeLabel() {
	makeLabelUnique++;
	return "Label" + std::to_string(makeLabelUnique);
}

std::string registerGenerator(std::string variable, std::map<std::string, std::pair<std::string, std::pair<int, bool>>>& functionmap) {
	for (std::map<std::string, std::pair<std::string, std::pair<int, bool>> > ::const_iterator it = functionmap.begin();
		it != functionmap.end(); ++it) {
		if (it->first == variable) {


			bool hasit = false;
			int ff;

			for (int i = 0; i != freeregs.size(); i++) {
				if (freeregs[i] == 0) {
					ff = i + 2;
					ff = memorystorenumber - ff;
					freeregs[i] = 1;
					hasit = true;

				}
			}

			if (!hasit) {
				memorystorenumber++;
				int counter = 0;
				std::cout << "addi $sp,$sp,-" << 4 << std::endl;
				std::cout << "move $fp,$sp" << std::endl;
				std::cout << "sw " << it->second.first << "," << "0($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = it->second.first;
				nnn.second.first = memorystorenumber;
				nnn.second.second = true;
				functionmap.at(it->first) = nnn;
				freeregs.push_back(1);


				std::cout << std::endl;

				return (it->second.first);
			}
			else {

				std::cout << "sw " << it->second.first << "," << 4 * ff << "($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = it->second.first;
				nnn.second.first = memorystorenumber - ff;
				nnn.second.second = true;
				functionmap.at(it->first) = nnn;

				return it->second.first;
			}
		}
	}
	localcounter++;
	if (localcounter < 2) {

		std::pair<std::string, std::pair<int, bool>> x;
		x.first = "$" + std::to_string(2 + localcounter);
		x.second.first = -1;
		x.second.second = true;
		//std::cout << std::endl;
		functionmap.insert(std::pair<std::string, std::pair<std::string, std::pair<int, bool> > >(variable, x));
		return ("$" + std::to_string(2 + localcounter));
	}
	else if ((6 + localcounter) > 25) {
		std::string s = functionmap.find(variable)->second.first;
		int x2 = (6 + localcounter) % 25;
		if (x2 < 3) {}
		else {
			x2 = (10 + localcounter) % 25;
		}

		bool hasit = false;
		int ff;
		for (int i = 0; i != freeregs.size(); i++) {
			if (freeregs[i] == 0) {
				ff = i + 2;
				ff = memorystorenumber - ff;
				freeregs[i] = 1;
				hasit = true;
			}
		}
		if (hasit) {

			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>> > ::const_iterator it = functionmap.begin();
				it != functionmap.end(); ++it) {
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = it->second.first;
				nnn.second.first = memorystorenumber - ff;
				nnn.second.second = false;
				for (std::map<std::string, std::pair<std::string, std::pair<int, bool>> > ::const_iterator it = functionmap.begin();
					it != functionmap.end(); ++it) {
					if (it->second.first == s && it->second.second.second == false) {
						std::cout << "sw " << it->second.first << "," << 4 * ff << "($fp)" << std::endl;
						functionmap.at(it->first) = nnn;
						break;
					}
				}
			}
		}
		else {
			memorystorenumber++;
			std::cout << "addi $sp,$sp,-" << 4 << std::endl;
			std::cout << "move $fp,$sp" << std::endl;
			std::cout << "sw $" << std::to_string(x2 + 1) << "," << "0($fp)" << std::endl;
			freeregs.push_back(1);

			std::cout << std::endl;
			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = functionmap.begin();
				it != functionmap.end(); ++it) {
				if (it->second.first == ("$" + std::to_string(x2 + 1))) {
					std::pair<std::string, std::pair<int, bool>> nnn;
					nnn.first = it->second.first;
					nnn.second.first = memorystorenumber;
					nnn.second.second = false;
					functionmap.at(it->first) = nnn;
					std::pair<std::string, std::pair<int, bool>> x;
					x.first = "$" + std::to_string(x2 + 1);
					x.second.first = -1;
					x.second.second = true;
					functionmap.insert(std::pair<std::string, std::pair<std::string, std::pair<int, bool>> >(variable, x));
					return "$" + std::to_string(x2 + 1);
				}
			}
		}


	}

	else {
		std::pair<std::string, std::pair<int, bool>> x;
		x.first = "$" + std::to_string(6 + localcounter);
		x.second.first = -1;
		x.second.second = true;
		functionmap.insert(std::pair<std::string, std::pair<std::string, std::pair<int, bool> > >(variable, x));
		return ("$" + std::to_string(6 + localcounter));
	}

}

std::string registerGeneratorfloat(std::string variable, std::map<std::string, std::pair<std::string, std::pair<int, bool>>>& functionmap) {
	for (std::map<std::string, std::pair<std::string, std::pair<int, bool>> > ::const_iterator it = functionmap.begin();
		it != functionmap.end(); ++it) {
		if (it->first == variable) {


			bool hasit = false;
			int ff;

			for (int i = 0; i != freeregs.size(); i++) {
				if (freeregs[i] == 0) {
					ff = i + 2;
					ff = memorystorenumber - ff;
					freeregs[i] = 1;
					hasit = true;

				}
			}

			if (!hasit) {
				memorystorenumber++;
				int counter = 0;
				std::cout << "addi $sp,$sp,-" << 4 << std::endl;
				std::cout << "move $fp,$sp" << std::endl;
				std::cout << "s.s " << it->second.first << "," << "0($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = it->second.first;
				nnn.second.first = memorystorenumber;
				nnn.second.second = true;
				functionmap.at(it->first) = nnn;
				freeregs.push_back(1);


				std::cout << std::endl;

				return (it->second.first);
			}
			else {

				std::cout << "s.s " << it->second.first << "," << 4 * ff << "($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = it->second.first;
				nnn.second.first = memorystorenumber - ff;
				nnn.second.second = true;
				functionmap.at(it->first) = nnn;

				return it->second.first;
			}
		}
	}
	localcounterfloat++;
	if (localcounterfloat < 2) {

		std::pair<std::string, std::pair<int, bool>> x;
		x.first = "$f" + std::to_string(localcounterfloat);
		x.second.first = -1;
		x.second.second = true;
		//std::cout << std::endl;
		functionmap.insert(std::pair<std::string, std::pair<std::string, std::pair<int, bool> > >(variable, x));
		return ("$f" + std::to_string(localcounterfloat));
	}
	else if ((3 + localcounterfloat) > 25) {
		std::string s = functionmap.find(variable)->second.first;
		int x2 = (3 + localcounterfloat) % 25;
		if (x2 < 12) {}
		else {
			x2 = (6 + localcounterfloat) % 25;
		}

		bool hasit = false;
		int ff;
		for (int i = 0; i != freeregs.size(); i++) {
			if (freeregs[i] == 0) {
				ff = i + 2;
				ff = memorystorenumber - ff;
				freeregs[i] = 1;
				hasit = true;
			}
		}
		if (hasit) {

			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>> > ::const_iterator it = functionmap.begin();
				it != functionmap.end(); ++it) {
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = it->second.first;
				nnn.second.first = memorystorenumber - ff;
				nnn.second.second = false;
				for (std::map<std::string, std::pair<std::string, std::pair<int, bool>> > ::const_iterator it = functionmap.begin();
					it != functionmap.end(); ++it) {
					if (it->second.first == s && it->second.second.second == false) {
						std::cout << "s.s " << it->second.first << "," << 4 * ff << "($fp)" << std::endl;
						functionmap.at(it->first) = nnn;
						break;
					}
				}
			}
		}
		else {
			memorystorenumber++;
			std::cout << "addi $sp,$sp,-" << 4 << std::endl;
			std::cout << "move $fp,$sp" << std::endl;
			std::cout << "s.s $f" << std::to_string(x2 + 1) << "," << "0($fp)" << std::endl;
			freeregs.push_back(1);

			std::cout << std::endl;
			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = functionmap.begin();
				it != functionmap.end(); ++it) {
				if (it->second.first == ("$f" + std::to_string(x2 + 2))) {
					std::pair<std::string, std::pair<int, bool>> nnn;
					nnn.first = it->second.first;
					nnn.second.first = memorystorenumber;
					nnn.second.second = false;
					functionmap.at(it->first) = nnn;
					std::pair<std::string, std::pair<int, bool>> x;
					x.first = "$f" + std::to_string(x2 + 2);
					x.second.first = -1;
					x.second.second = true;
					functionmap.insert(std::pair<std::string, std::pair<std::string, std::pair<int, bool>> >(variable, x));
					return "$f" + std::to_string(x2 + 2);
				}
			}
		}


	}

	else {
		std::pair<std::string, std::pair<int, bool>> x;
		x.first = "$f" + std::to_string(3 + localcounterfloat);
		x.second.first = -1;
		x.second.second = true;
		functionmap.insert(std::pair<std::string, std::pair<std::string, std::pair<int, bool> > >(variable, x));
		return ("$f" + std::to_string(3 + localcounterfloat));
	}

}

std::string registerGeneratordouble(std::string variable, std::map<std::string, std::pair<std::string, std::pair<int, bool>>>& functionmap) {
	for (std::map<std::string, std::pair<std::string, std::pair<int, bool>> > ::const_iterator it = functionmap.begin();
		it != functionmap.end(); ++it) {
		if (it->first == variable) {


			bool hasit = false;
			int ff;

			for (int i = 0; i != freeregs.size(); i++) {
				if (freeregs[i] == 0) {
					ff = i + 2;
					ff = memorystorenumber - ff;
					freeregs[i] = 1;
					hasit = true;

				}
			}

			if (!hasit) {
				memorystorenumber +=2;
				int counter = 0;
				std::cout << "addi $sp,$sp,-" << 8 << std::endl;
				std::cout << "move $fp,$sp" << std::endl;
				std::cout << "s.d " << it->second.first << "," << "0($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = it->second.first;
				nnn.second.first = memorystorenumber;
				nnn.second.second = true;
				functionmap.at(it->first) = nnn;
				freeregs.push_back(1);



				return (it->second.first);
			}
			else {

				std::cout << "s.d " << it->second.first << "," << 4 * ff << "($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = it->second.first;
				nnn.second.first = memorystorenumber - ff;
				nnn.second.second = true;
				functionmap.at(it->first) = nnn;

				return it->second.first;
			}
		}
	}
	localcounterfloat += 2;
	if (localcounterfloat < 2) {

		std::pair<std::string, std::pair<int, bool>> x;
		x.first = "$f" + std::to_string(localcounterfloat);
		x.second.first = -1;
		x.second.second = true;
		//std::cout << std::endl;
		functionmap.insert(std::pair<std::string, std::pair<std::string, std::pair<int, bool> > >(variable, x));
		return ("$f" + std::to_string(localcounterfloat));
	}
	else if ((3 + localcounterfloat) > 25) {
		std::string s = functionmap.find(variable)->second.first;
		int x2 = (3 + localcounterfloat) % 25;
		if (x2 < 12) {}
		else {
			x2 = (6 + localcounterfloat) % 25;
		}

		bool hasit = false;
		int ff;
		for (int i = 0; i != freeregs.size(); i++) {
			if (freeregs[i] == 0) {
				ff = i + 2;
				ff = memorystorenumber - ff;
				freeregs[i] = 1;
				hasit = true;
			}
		}
		if (hasit) {

			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>> > ::const_iterator it = functionmap.begin();
				it != functionmap.end(); ++it) {
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = it->second.first;
				nnn.second.first = memorystorenumber - ff;
				nnn.second.second = false;
				for (std::map<std::string, std::pair<std::string, std::pair<int, bool>> > ::const_iterator it = functionmap.begin();
					it != functionmap.end(); ++it) {
					if (it->second.first == s && it->second.second.second == false) {
						std::cout << "s.d " << it->second.first << "," << 4 * ff << "($fp)" << std::endl;
						functionmap.at(it->first) = nnn;
						break;
					}
				}
			}
		}
		else {
			memorystorenumber+=2;
			std::cout << "addi $sp,$sp,-" << 4 << std::endl;
			std::cout << "move $fp,$sp" << std::endl;
			std::cout << "s.d $f" << std::to_string(x2 + 1) << "," << "0($fp)" << std::endl;
			freeregs.push_back(1);

			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = functionmap.begin();
				it != functionmap.end(); ++it) {
				if (it->second.first == ("$f" + std::to_string(x2 + 2))) {
					std::pair<std::string, std::pair<int, bool>> nnn;
					nnn.first = it->second.first;
					nnn.second.first = memorystorenumber;
					nnn.second.second = false;
					functionmap.at(it->first) = nnn;
					std::pair<std::string, std::pair<int, bool>> x;
					x.first = "$f" + std::to_string(x2 + 2);
					x.second.first = -1;
					x.second.second = true;
					functionmap.insert(std::pair<std::string, std::pair<std::string, std::pair<int, bool>> >(variable, x));
					return "$f" + std::to_string(x2 + 2);
				}
			}
		}


	}

	else {
		std::pair<std::string, std::pair<int, bool>> x;
		x.first = "$f" + std::to_string(3 + localcounterfloat);
		x.second.first = -1;
		x.second.second = true;
		functionmap.insert(std::pair<std::string, std::pair<std::string, std::pair<int, bool> > >(variable, x));
		return ("$f" + std::to_string(3 + localcounterfloat));
	}

}

std::string loadfromram(std::string variable, std::map<std::string, std::pair<std::string, std::pair<int, bool> >>& functionmap) {

	int x2 = functionmap.find(variable)->second.second.second;
	int x22 = functionmap.find(variable)->second.second.first;
	std::string s = functionmap.find(variable)->second.first;
	std::string name = functionmap.find(variable)->first;

	if (x2 == true) {
		return s;
	}
	else if (s[1] == 'f') {
		localcounterfloat++;
		memorystorenumber++;
		int z = memorystorenumber - x22;
		int ff;
		bool hasit = false;
		for (int i = 0; i != freeregs.size(); i++) {
			if (freeregs[i] == 0) {
				ff = i + 1;
				ff = memorystorenumber - ff;
				freeregs[i] = 1;
				memorystorenumber--;
				hasit = true;
			}
		}
		int counter = 0;
		for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
			it != functionmap.end(); ++it) {
			if (it->first != variable && it->second.first == s) {
				counter++;
			}
		}
		if (!hasit) {

			if (counter != 0) {
				freeregs.push_back(1);
				std::cout << "addi $sp,$sp,-" << 4 << std::endl;
				std::cout << "move $fp,$sp" << std::endl;
				std::cout << "s.s " << s << "," << "0($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = s;
				nnn.second.first = memorystorenumber;
				nnn.second.second = false;
				for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
					it != functionmap.end(); ++it) {

					if (it->second.first == s && it->second.second.second == true) {
						std::pair<std::string, std::pair<int, bool>> nnn;
						nnn.first = s;
						nnn.second.first = memorystorenumber;
						nnn.second.second = false;
						functionmap.at(it->first) = nnn;
					}
				}

			}
			else {

				memorystorenumber--;
				z--;
			}
		}
		else {
			if (counter != 0) {
				std::cout << "s.s " << s << "," << 4 * ff << "($fp)" << std::endl;
				for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
					it != functionmap.end(); ++it) {

					if (it->second.first == s && it->second.second.second == true) {
						std::pair<std::string, std::pair<int, bool> > nnn;
						nnn.first = s;
						nnn.second.first = (memorystorenumber + 1) - ff;
						nnn.second.second = false;
						functionmap.at(it->first) = nnn;
					}
				}
			}
			else {
				z--;
			}

		}
		if (x22 < offset) {
			freeregs[x22 - 1] = 0;

			std::cout << std::endl;
			std::pair<std::string, std::pair<int, bool> > nnn;
			nnn.first = s;
			nnn.second.first = -1;
			nnn.second.second = true;
			functionmap.at(variable) = nnn;
			std::cout << "l.s " << s << "," << 4 * z << "($fp)" << std::endl;
		}
		else {
			std::cout << std::endl;
			std::pair<std::string, std::pair<int, bool> > nnn;
			nnn.first = s;
			nnn.second.first = -1;
			nnn.second.second = true;
			functionmap.at(variable) = nnn;
			std::cout << "l.s " << s << "," << name << std::endl;
		}
	}
	else if (s[1] == 'd') {
		s = s.erase(1, 2);
		s =  "$f" + s.substr(0,1);
		localcounterfloat++;
		memorystorenumber++;
		int z = memorystorenumber - x22;
		int ff;
		bool hasit = false;
		for (int i = 0; i != freeregs.size(); i++) {
			if (freeregs[i] == 0) {
				ff = i + 1;
				ff = memorystorenumber - ff;
				freeregs[i] = 1;
				memorystorenumber--;
				hasit = true;
			}
		}
		int counter = 0;
		for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
			it != functionmap.end(); ++it) {
			if (it->first != variable && it->second.first == s) {
				counter++;
			}
		}
		if (!hasit) {

			if (counter != 0) {
				freeregs.push_back(1);
				std::cout << "addi $sp,$sp,-" << 4 << std::endl;
				std::cout << "move $fp,$sp" << std::endl;
				std::cout << "s.d " << s << "," << "0($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = s;
				nnn.second.first = memorystorenumber;
				nnn.second.second = false;
				for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
					it != functionmap.end(); ++it) {

					if (it->second.first == s && it->second.second.second == true) {
						std::pair<std::string, std::pair<int, bool>> nnn;
						nnn.first = s;
						nnn.second.first = memorystorenumber;
						nnn.second.second = false;
						functionmap.at(it->first) = nnn;
					}
				}

			}
			else {

				memorystorenumber--;
				z--;
			}
		}
		else {
			if (counter != 0) {
				std::cout << "s.d " << s << "," << 4 * ff << "($fp)" << std::endl;
				for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
					it != functionmap.end(); ++it) {

					if (it->second.first == s && it->second.second.second == true) {
						std::pair<std::string, std::pair<int, bool> > nnn;
						nnn.first = s;
						nnn.second.first = (memorystorenumber + 1) - ff;
						nnn.second.second = false;
						functionmap.at(it->first) = nnn;
					}
				}
			}
			else {
				z--;
			}

		}
		if (x22 < offset) {
			freeregs[x22 - 1] = 0;

			std::cout << std::endl;
			std::pair<std::string, std::pair<int, bool> > nnn;
			nnn.first = s;
			nnn.second.first = -1;
			nnn.second.second = true;
			functionmap.at(variable) = nnn;
			std::cout << "L.d " << s << "," << 4 * z << "($fp)" << std::endl;
		}
		else {
			std::cout << std::endl;
			std::pair<std::string, std::pair<int, bool> > nnn;
			nnn.first = s;
			nnn.second.first = -1;
			nnn.second.second = true;
			functionmap.at(variable) = nnn;
			std::cout << "L.d " << s << "," << name << std::endl;
		}
	}
	else {
		localcounter++;
		memorystorenumber++;
		int z = memorystorenumber - x22;
		int ff;
		bool hasit = false;
		for (int i = 0; i != freeregs.size(); i++) {
			if (freeregs[i] == 0) {
				ff = i + 1;
				ff = memorystorenumber - ff;
				freeregs[i] = 1;
				memorystorenumber--;
				hasit = true;
			}
		}
		int counter = 0;
		for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
			it != functionmap.end(); ++it) {
			if (it->first != variable && it->second.first == s) {
				counter++;
			}
		}
		if (!hasit) {

			if (counter != 0) {
				freeregs.push_back(1);
				std::cout << "addi $sp,$sp,-" << 4 << std::endl;
				std::cout << "move $fp,$sp" << std::endl;
				std::cout << "sw " << s << "," << "0($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool>> nnn;
				nnn.first = s;
				nnn.second.first = memorystorenumber;
				nnn.second.second = false;
				for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
					it != functionmap.end(); ++it) {

					if (it->second.first == s && it->second.second.second == true) {
						std::pair<std::string, std::pair<int, bool>> nnn;
						nnn.first = s;
						nnn.second.first = memorystorenumber;
						nnn.second.second = false;
						functionmap.at(it->first) = nnn;
					}
				}

			}
			else {

				memorystorenumber--;
				z--;
			}
		}
		else {
			if (counter != 0) {
				std::cout << "sw " << s << "," << 4 * ff << "($fp)" << std::endl;
				for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
					it != functionmap.end(); ++it) {

					if (it->second.first == s && it->second.second.second == true) {
						std::pair<std::string, std::pair<int, bool> > nnn;
						nnn.first = s;
						nnn.second.first = (memorystorenumber + 1) - ff;
						nnn.second.second = false;
						functionmap.at(it->first) = nnn;
					}
				}
			}
			else {
				z--;
			}

		}
		if (x22 < offset) {
			freeregs[x22 - 1] = 0;

			std::cout << std::endl;
			std::pair<std::string, std::pair<int, bool> > nnn;
			nnn.first = s;
			nnn.second.first = -1;
			nnn.second.second = true;
			functionmap.at(variable) = nnn;
			std::cout << "lw " << s << "," << 4 * z << "($fp)" << std::endl;
		}
		else {
			std::cout << std::endl;
			std::pair<std::string, std::pair<int, bool> > nnn;
			nnn.first = s;
			nnn.second.first = -1;
			nnn.second.second = true;
			functionmap.at(variable) = nnn;
			std::cout << "lw " << s << "," << name << std::endl;
		}
	}
}

std::string randomVarGenerator(std::map<std::string, std::pair<std::string, std::pair<int, bool> >>& functionmap) {
	std::string tempVar = ("%" + std::to_string(makeRegUnique));
	std::string temporaryReg = registerGenerator(tempVar, functionmap);
	makeRegUnique++;
	return temporaryReg;
}

std::string randomFloatVarGenerator(std::map<std::string, std::pair<std::string, std::pair<int, bool> >>& functionmap) {
	std::string tempVar = ("%" + std::to_string(makeRegUnique));
	std::string temporaryReg = registerGeneratorfloat(tempVar, functionmap);
	makeRegUnique++;
	return temporaryReg;
}

std::string randomDoubleVarGenerator(std::map<std::string, std::pair<std::string, std::pair<int, bool> >>& functionmap) {
	std::string tempVar = ("%" + std::to_string(makeRegUnique));
	std::string temporaryReg = registerGeneratordouble(tempVar, functionmap);
	makeRegUnique++;
	return temporaryReg;
}

void storeinram(std::string variable, std::map<std::string, std::pair<std::string, std::pair<int, bool> >>& functionmap) {
	memorystorenumber++;
	freeregs.push_back(1);
	std::cout << "addi $sp,$sp,-" << 4 << std::endl;
	std::cout << "move $fp,$sp" << std::endl;
	std::cout << "sw " << variable << ",0($fp)" << std::endl;

	std::pair<std::string, std::pair<int, bool>> nnn;
	nnn.first = variable;
	nnn.second.first = memorystorenumber;
	nnn.second.second = false;
	for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
		it != functionmap.end(); ++it) {
		if (it->second.first == variable) {
			functionmap.at(it->first) = nnn;
			break;
		}
	}
}

void storeinglobalram(std::string variable, std::map<std::string, std::pair<std::string, std::pair<int, bool> >>& functionmap) {
	globalmemorystorenumber++;

	std::pair<std::string, std::pair<int, bool>> nnn;
	nnn.first = variable;
	nnn.second.first = globalmemorystorenumber;
	nnn.second.second = false;
	for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
		it != functionmap.end(); ++it) {
		if (it->second.first == variable) {
			functionmap.at(it->first) = nnn;
			break;
		}
	}
}

std::string makeFuncNameUnique(std::string x) {
	std::string n;
	if (funcnamecount == 0) {
		n = x;
	}
	else {
		n = x;
	}
	funcnamecount++;
	return n;
}

void Compile(
	std::string destReg,
	std::map<std::string, std::pair<std::string, std::pair<int, bool> > >& functionmap,
	Node* ast
) {
	if (ast->returntype() == "Program") {
		std::map<std::string, std::pair<std::string, std::pair<int, bool> > > programmappings;
		Compile(destReg, programmappings, ast->getbranch(0));
	}

	else if (ast->returntype() == "LIST") {
		for (int i = 0; i < ast->evaluate(); i++) {
			//std::cout << " flag " << ast->evaluate() << " " << ast->getbranch(0)->returntype() << std::endl;
			Compile(destReg, functionmap, ast->getbranch(i));
		}

	}

	//Function
	else if (ast->returntype() == "Function Declaration") {
		std::vector<std::string> arguments;
		if (ast->getbranch(1) != NULL) {
			if (ast->getbranch(1)->returntype() != "Variable") {
				arguments = ast->getbranch(1)->returnname();
			}
			else {
				if (ast->getbranch(1)->getbranch(1)->returntype() != "Number" && ast->getbranch(1)->getbranch(1)->returntype() != "VariableName") {
					arguments.push_back("%expression");
				}
				else {
					arguments.push_back(ast->getbranch(1)->name());
				}
			}
		}
		//std::map<std::string, std::pair<std::string, std::pair<int, bool > > mappings;
		int x = ast->evaluate();
		std::cout << "sw " << "$31" << "," << (memorystorenumber - 1) * 4 << "($fp)" << std::endl;
		if (x > 0) {
			/**
			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = functionmap.begin();
				it != functionmap.end(); ++it) {
				std::cout << it->first << " " << it->second.first << " " << it->second.second.first << " " << it->second.second.second << std::endl;
			}*/

			for (int i = 0; i < x; i++) {
				std::string temp = arguments[i];

				if (i < 4) {
					//storeinram("$"+std::to_string(i+4), functionmap);

					if (isdigit(temp[0])) {
						std::cout << "li $" << i + 4 << "," << arguments[i] << std::endl; //here
					}
					else {
						bool hasspace = false;
						for (int i = 0; i < temp.size(); i++) {
							if (isspace(temp[i])); {
								hasspace = true;
							}
						}
						if (arguments[i] != "%expression") {
							std::string variableone = loadfromram(temp, functionmap);
							storeinram(variableone, functionmap);
							std::cout << "add $" << i + 4 << "," << variableone << ",$0" << std::endl;
						}
						else {
							//var with arguments ( n - 1 )
							std::string temp = randomVarGenerator(functionmap);
							if (ast->getbranch(1)->returntype() == "Variable") { //1 argument 
								Compile(temp, functionmap, ast->getbranch(1)->getbranch(1));
								std::cout << "add $" << i + 4 << "," << temp << ",$0" << std::endl;
							}
							else { //more than 1 argument
								Compile(temp, functionmap, ast->getbranch(1)->getbranch(1));
								std::cout << "add $" << i + 4 << "," << temp << ",$0" << std::endl;
							}

						}


					}
					if ((x < 4) && (i == x - 1)) {
						for (std::map<std::string, std::pair<std::string, std::pair<int, bool> > > ::const_iterator it = functionmap.begin();
							it != functionmap.end(); ++it) {
							if (it->first[0] != '%') {
								storeinram(it->second.first, functionmap);
							}
						}
						std::cout << "addi " << "$sp," << "$sp" << ",-16" << std::endl;
					}
				}
				else {
					int n = i % 4;
					if (i == 4) {
						std::cout << "addi " << "$sp," << "$sp" << "," << -4 * (4 + x - 4) << std::endl;
					}
					if (isdigit(temp[0])) {
						std::string temporaryreg = randomVarGenerator(functionmap);
						std::cout << "li " << temporaryreg << "," << arguments[i] << std::endl; //here
						std::cout << "sw " << temporaryreg << "," << 4 * (4 + n) << "($sp)" << std::endl;
					}
					else {
						std::string variableone = loadfromram(temp, functionmap);
						std::cout << "sw " << variableone << "," << 4 * (4 + n) << "($sp)" << std::endl;
					}
				}
			}



		}
		std::string functioname = makeFuncNameUnique(ast->getbranch(0)->name());

		std::cout << "jal " << functioname << std::endl;
		std::cout << "nop" << std::endl;
		std::cout << "add " << destReg << "," << "$2" << "," << "$0" << std::endl;

		std::cout << "lw " << "$31" << "," << (memorystorenumber - 1) * 4 << "($fp)" << std::endl;

	}

	else if (ast->returntype() == "Function") {
		globalvariableindicator = false;
		variableintoreg = true;
		//std::cout << arguementcount << std::endl;
		std::vector<std::string> returningvec = ast->returnname();
		std::vector<std::string> arguments;
		std::vector<std::string> argumentsfloat;
		std::vector<std::string> argumentsdouble;
		if (ast->getbranch(1)->getbranch(1) != NULL) {
			arguments = ast->getbranch(1)->getbranch(1)->returnname();
		}
		
		for (int i = 0; i < arguments.size(); i++) {
			if (arguments[i].back() == '%' || arguments[i].back() == '|') {
				arguments.erase(arguments.begin() + i);
				i--;
			}
		}

		if (ast->getbranch(1)->getbranch(1) != NULL) {
			argumentsfloat = ast->getbranch(1)->getbranch(1)->returnname();
		}

		for (int i = 0; i < argumentsfloat.size(); i++) {

			if (argumentsfloat[i].back() != '%') {

				argumentsfloat.erase(argumentsfloat.begin() + i);
				i--;
			}
			else {
				argumentsfloat[i] = argumentsfloat[i].substr(0, argumentsfloat[i].length() - 1);
			}
		}

		if (ast->getbranch(1)->getbranch(1) != NULL) {
			argumentsdouble = ast->getbranch(1)->getbranch(1)->returnname();
		}

		for (int i = 0; i < argumentsdouble.size(); i++) {

			if (argumentsdouble[i].back() != '|') {

				argumentsdouble.erase(argumentsdouble.begin() + i);
				i--;
			}
			else {
				argumentsdouble[i] = argumentsdouble[i].substr(0, argumentsdouble[i].length() - 1);
			}
		}

		//std::map<std::string, std::pair<std::string, std::pair<int, bool > > mappings;

		argumentcount = (argumentsdouble.size() * 2) + argumentsfloat.size() + arguments.size();
		memorystorenumber += argumentcount + 1;
		std::string functioname = makeFuncNameUnique(ast->getbranch(1)->name());
		NodePtr node = ast;
		functionmapping.insert(std::pair<std::string, NodePtr>(functioname, node));
		std::cout << ".globl " << functioname << std::endl;
		std::cout << functioname << ":" << std::endl;
		std::cout << "addi $sp,$sp,-" << (2 + argumentcount) * 4 << std::endl;
		std::cout << "sw $fp," << (argumentcount + 1) * 4 << "($sp)" << std::endl;
		std::cout << "move $fp,$sp" << std::endl;

		for (int i = 0; i < arguments.size(); i++) {
			if (i < 4) {
				std::string temp = registerGenerator(arguments[i], functionmap);
				freeregs.push_back(1);
				std::cout << "sw $" << i + 4 << "," << i * 4 << "($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool> > pair;
				pair.first = temp;
				pair.second.first = memorystorenumber - i;
				pair.second.second = 0;
				functionmap.at(arguments[i]) = pair;
			}
			else {
				int n = i % 4;
				std::string temp = registerGenerator(arguments[i], functionmap);
				freeregs.push_back(1);
				std::cout << "lw $" << n + 4 << "," << (4 + 2 + arguments.size() + n) * 4 << "($fp)" << std::endl;
				std::cout << "sw $" << n + 4 << "," << i * 4 << "($fp)" << std::endl;
				std::pair<std::string, std::pair<int, bool> > pair;
				pair.first = temp;
				pair.second.first = memorystorenumber - i;
				pair.second.second = 0;
				functionmap.at(arguments[i]) = pair;
			}
		}
		if (argumentsfloat.size() > 0) {
			for (int i = 0; i < (argumentsfloat.size() - arguments.size()); i++) {
				if (i < 2) {
					std::string temp = registerGeneratorfloat(argumentsfloat[i], functionmap);
					freeregs.push_back(1);
					std::cout << "s.s $f" << (i * 2) + 12 << "," << i * 4 << "($fp)" << std::endl;
					std::pair<std::string, std::pair<int, bool> > pair;
					pair.first = temp;
					pair.second.first = memorystorenumber - i;
					pair.second.second = 0;
					functionmap.at(argumentsfloat[i]) = pair;
				}
				else if (i < 4) {
					std::string temp = registerGeneratorfloat(argumentsfloat[i], functionmap);
					freeregs.push_back(1);
					std::cout << "mtc1 $" << i + 4 << "," << temp << std::endl;
					std::cout << "s.s " << temp << "," << i * 4 << "($fp)" << std::endl;
					std::pair<std::string, std::pair<int, bool> > pair;
					pair.first = temp;
					pair.second.first = memorystorenumber - i;
					pair.second.second = 0;
					functionmap.at(argumentsfloat[i]) = pair;
				}
				else {
					int n = i % 4;
					std::string temp = registerGeneratorfloat(argumentsfloat[i], functionmap);
					freeregs.push_back(1);
					std::cout << "L.s $f" << (n * 2) + 12 << "," << (4 + 2 + argumentsfloat.size() + n) * 4 << "($fp)" << std::endl;
					std::cout << "s.s $f" << (n * 2) + 12 << "," << i * 4 << "($fp)" << std::endl;
					std::pair<std::string, std::pair<int, bool> > pair;
					pair.first = temp;
					pair.second.first = memorystorenumber - i;
					pair.second.second = 0;
					functionmap.at(argumentsfloat[i]) = pair;
				}
			}
		}

		if (argumentsdouble.size() > 0) {
			for (int i = 0; i < (argumentsdouble.size() - argumentsfloat.size()); i++) {
				if (i < 2) {
					std::string temp = registerGeneratorfloat(argumentsdouble[i], functionmap);
					freeregs.push_back(1);
					std::cout << "s.d $f" << (i * 2) + 12 << "," << i * 8 << "($fp)" << std::endl;
					std::pair<std::string, std::pair<int, bool> > pair;
					temp = temp.erase(0, 2);
					std::string doublespec = temp.substr(0, 1) + "d" + temp.substr(1);
					pair.first = doublespec;
					pair.second.first = memorystorenumber - i;
					pair.second.second = 0;
					functionmap.at(argumentsdouble[i]) = pair;
				}
				else if (i < 4) {
					std::string temp = registerGeneratorfloat(argumentsdouble[i], functionmap);
					freeregs.push_back(1);
					std::cout << "mtc1 $" << i + 4 << "," << temp << std::endl;
					std::cout << "s.d " << temp << "," << i * 8 << "($fp)" << std::endl;
					std::pair<std::string, std::pair<int, bool> > pair;
					temp = temp.erase(0, 2);
					std::string doublespec = temp.substr(0,1) + "d" + temp.substr(1);
					pair.first = doublespec;
					pair.second.first = memorystorenumber - i;
					pair.second.second = 0;
					functionmap.at(argumentsdouble[i]) = pair;
				}
				else {
					int n = i % 4;
					std::string temp = registerGeneratorfloat(argumentsdouble[i], functionmap);
					freeregs.push_back(1);
					std::cout << "L.d $f" << (n * 2) + 12 << "," << (4 + 2 + argumentsdouble.size() + n) * 8 << "($fp)" << std::endl;
					std::cout << "s.d $f" << (n * 2) + 12 << "," << i * 8 << "($fp)" << std::endl;
					std::pair<std::string, std::pair<int, bool> > pair;
					temp = temp.erase(0, 2);
					std::string doublespec = temp.substr(0, 1) + "d" + temp.substr(1);
					pair.first = doublespec;
					pair.second.first = memorystorenumber - i;
					pair.second.second = 0;
					functionmap.at(argumentsdouble[i]) = pair;
				}
			}
		}
		std::map<std::string, std::pair<std::string, std::pair<int, bool>>> mappings;
		for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = functionmap.begin();
			it != functionmap.end(); ++it) {
			mappings.insert(std::pair < std::string, std::pair<std::string, std::pair<int, bool>> >(it->first, it->second));
		}
		Compile(ast->getbranch(0)->returntype(), mappings, ast->getbranch(3));

		std::cout << "addi $sp,$sp," << (2 + argumentcount) * 4 << std::endl; //can be replaced with argument size
		std::cout << "move $fp,$sp" << std::endl;
		localcounter = -1;
		memorystorenumber = 0;
		freeregs.clear();
		//

		//Compile(mymap,ast->getbranch(3));
	}
	//Variable
	else if (ast->returntype() == "Variable") {
		if (ast->getbranch(1) != NULL) {
			if (ast->getbranch(1)->returntype() == "Enum Specifier") {
				Compile(ast->name(), functionmap, ast->getbranch(1));
			}
			else if (ast->getbranch(1)->returntype() != "Function Declaration") {
				if (!globalvariableindicator) {
					if (ast->getbranch(1)->returntype() == "Array Declaration") {
						Compile(destReg, functionmap, ast->getbranch(1));
					}
					else {
						std::string x = registerGenerator(ast->name(), functionmap);
						std::cout << "li " << x << ",0" << std::endl;
						if (ast->getbranch(0)->returntype() == "CharType") {
							sizeofmap.insert(std::pair<std::string, std::string>(ast->name(), "char"));
						}
						else if (ast->getbranch(0)->returntype() == "inttype") {
							sizeofmap.insert(std::pair<std::string, std::string>(ast->name(), "int"));
						}
						else if (ast->getbranch(0)->returntype() == "floattype") {
							sizeofmap.insert(std::pair<std::string, std::string>(ast->name(), "float"));
						}
						else if (ast->getbranch(0)->returntype() == "doubletype") {
							sizeofmap.insert(std::pair<std::string, std::string>(ast->name(), "double"));
						}
						if (ast->getbranch(1)->returntype() == "VariableName") {}
						else {
							Compile(ast->name(), functionmap, ast->getbranch(1));
						}
					}
				}
				else if (ast->getbranch(1)->returntype() == "Array Declaration") {
					std::string variablename = ast->getbranch(1)->getbranch(0)->name();
					std::cout << ".globl " << variablename << std::endl;
					std::cout << ".data " << std::endl;
					std::cout << variablename << ":" << std::endl;
					storeinglobalram(variablename, functionmap);
				}
				else {
					std::string x = registerGenerator(ast->name(), functionmap);
					std::cout << ".globl " << ast->name() << std::endl;
					std::cout << ".data " << std::endl;
					std::cout << ast->name() << ":" << std::endl;
					std::cout << ".word " << ast->evaluate() << std::endl;
					storeinglobalram(x, functionmap);
				}
			}

		}
		else {}
	}

	//Arrays
	else if (ast->returntype() == "Array Declaration") {
		for (int i = 0; i < ast->getbranch(1)->evaluate(); i++) {
			std::string name = ast->getbranch(0)->name();
			name = name + "[" + std::to_string(i) + "]";
			std::string temp = registerGenerator(name, functionmap);
			storeinram(temp, functionmap);
		}
	}
	else if (ast->returntype() == "Array Identifier") {
		if (ast->getbranch(1)->returntype() == "Number") {

			std::string variablename = ast->getbranch(0)->name() + "[" + std::to_string((int)ast->getbranch(1)->evaluate()) + "]";
			std::cout << "lw " << destReg << "," << (memorystorenumber - (functionmap.at(variablename).second.first)) * 4 << "($fp)" << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string variablename = ast->getbranch(0)->name() + "[0]";
			int x = functionmap.at(variablename).second.first;
			std::string variable = ast->getbranch(1)->name();
			variable = loadfromram(variable, functionmap);
			std::string temporarystore = randomVarGenerator(functionmap);
			std::cout << "sub " << temporarystore << "," << "$fp" << "," << variable << std::endl;
			std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
			std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
			std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
			std::cout << "lw " << destReg << "," << (memorystorenumber - (x)) * 4 << "(" << temporarystore << ")" << std::endl;
		}
		else {

			std::string variablename = ast->getbranch(0)->name() + "[0]";
			int x = functionmap.at(variablename).second.first;
			std::string variable = randomVarGenerator(functionmap);
			Compile(variable, functionmap, ast->getbranch(1));
			std::string temporarystore = randomVarGenerator(functionmap);
			std::cout << "sub " << temporarystore << "," << "$fp" << "," << variable << std::endl;
			std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
			std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
			std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
			std::cout << "lw " << destReg << "," << (memorystorenumber - (x)) * 4 << "(" << temporarystore << ")" << std::endl;
		}
	}
	else if (ast->returntype() == "VARIABLE STORE LIST") {
		std::cout << ast->getbranch(0)->returntype() << std::endl;
		Compile(destReg, functionmap, ast->getbranch(0));
	}


	//Return
	else if (ast->returntype() == "Return") {
		if (ast->getbranch(0)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
			if (x[1] != 'f') {
				std::cout << "add $2," << x << ",$0" << std::endl;
				std::cout << "move $sp,$fp" << std::endl;
				std::cout << "lw $fp," << memorystorenumber * 4 << "($sp)" << std::endl;
				std::cout << "addiu $sp,$sp," << (memorystorenumber + 1) * 4 << std::endl;
				std::cout << "jr $31" << std::endl;
				std::cout << "nop" << std::endl;
			}
			else {
				std::cout << "add $f0," << x << ",$0" << std::endl;
				std::cout << "move $sp,$fp" << std::endl;
				std::cout << "lw $fp," << memorystorenumber * 4 << "($sp)" << std::endl;
				std::cout << "addiu $sp,$sp," << (memorystorenumber + 1) * 4 << std::endl;
				std::cout << "jr $31" << std::endl;
				std::cout << "nop" << std::endl;
			}
		}
		else if (ast->getbranch(0)->returntype() == "Number") {
			std::cout << "li $2," << ast->getbranch(0)->evaluate() << std::endl;
			std::cout << "move $sp,$fp" << std::endl;
			std::cout << "lw $fp," << (memorystorenumber) * 4 << "($sp)" << std::endl;
			std::cout << "addiu $sp,$sp," << (memorystorenumber + 1) * 4 << std::endl;
			std::cout << "jr $31" << std::endl;
			std::cout << "nop" << std::endl;
		}
		else if (ast->getbranch(0)->returntype() == "Array Identifier") {
			if (ast->getbranch(0)->getbranch(1)->returntype() == "Number") {
				std::string x = ast->getbranch(0)->getbranch(0)->name();
				x = x + "[" + std::to_string((int)ast->getbranch(0)->getbranch(1)->evaluate()) + "]";
				x = loadfromram(x, functionmap);
				std::cout << "add $2," << x << ",$0" << std::endl;
				std::cout << "move $sp,$fp" << std::endl;
				std::cout << "lw $fp," << memorystorenumber * 4 << "($sp)" << std::endl;
				std::cout << "addiu $sp,$sp," << (memorystorenumber + 1) * 4 << std::endl;
				std::cout << "jr $31" << std::endl;
				std::cout << "nop" << std::endl;
			}
			else {
				std::string x = randomVarGenerator(functionmap);
				Compile(x, functionmap, ast->getbranch(0));
				std::cout << "add $2," << x << ",$0" << std::endl;
				std::cout << "move $sp,$fp" << std::endl;
				std::cout << "lw $fp," << memorystorenumber * 4 << "($sp)" << std::endl;
				std::cout << "addiu $sp,$sp," << (memorystorenumber + 1) * 4 << std::endl;
				std::cout << "jr $31" << std::endl;
				std::cout << "nop" << std::endl;
			}
		}
		else {
			if (destReg != "FloatType" && destReg != "DoubleType") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::cout << "add $2," << temporaryReg << ",$0" << std::endl;
				std::cout << "move $sp,$fp" << std::endl;
				std::cout << "lw $fp," << (memorystorenumber) * 4 << "($sp)" << std::endl;
				std::cout << "addiu $sp,$sp," << (memorystorenumber + 1) * 4 << std::endl;
				std::cout << "jr $31" << std::endl;
				std::cout << "nop" << std::endl;
			}
			else if (destReg == "DoubleType") {
				std::string temporaryReg = randomFloatVarGenerator(functionmap);
				temporaryReg.erase(1, 1);
				temporaryReg = temporaryReg.substr(0, 1) + "d" + temporaryReg.substr(1);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				temporaryReg.erase(1, 1);
				temporaryReg = temporaryReg.substr(0, 1) + "f" + temporaryReg.substr(1);
				std::cout << "mov.d $f0," << temporaryReg << std::endl;
				std::cout << "move $sp,$fp" << std::endl;
				std::cout << "lw $fp," << (memorystorenumber) * 4 << "($sp)" << std::endl;
				std::cout << "addiu $sp,$sp," << (memorystorenumber + 1) * 4 << std::endl;
				std::cout << "jr $31" << std::endl;
				std::cout << "nop" << std::endl;
			}
			else {
				std::string temporaryReg = randomFloatVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::cout << "mov.s $f0," << temporaryReg << std::endl;
				std::cout << "move $sp,$fp" << std::endl;
				std::cout << "lw $fp," << (memorystorenumber) * 4 << "($sp)" << std::endl;
				std::cout << "addiu $sp,$sp," << (memorystorenumber + 1) * 4 << std::endl;
				std::cout << "jr $31" << std::endl;
				std::cout << "nop" << std::endl;
			}
		}
	}

	//Enum
	else if (ast->returntype() == "Enum Specifier") {
		Compile(destReg, functionmap, ast->getbranch(0));
	}
	else if (ast->returntype() == "Enum List") {
		for (int i = 0; i < ast->evaluate(); i++) {
			Compile(destReg, functionmap, ast->getbranch(i));
		}
	}
	else if (ast->returntype() == "Enumerator") {
		std::string x = registerGenerator(ast->name(), functionmap);
		if (ast->getbranch(0) == NULL) {
			std::cout << ".globl " << ast->name() << std::endl;
			std::cout << ".data " << std::endl;
			std::cout << ast->name() << ":" << std::endl;
			std::cout << ".word " << enumeratornumber << std::endl;
			storeinglobalram(x, functionmap);
			enumeratornumber++;
		}//
		else {
			std::cout << ".globl " << ast->name() << std::endl;
			std::cout << ".data " << std::endl;
			std::cout << ast->name() << ":" << std::endl;
			std::cout << ".word " << ast->getbranch(0)->evaluate() << std::endl;
			storeinglobalram(x, functionmap);
			enumeratornumber++;
			enumeratornumber = ast->getbranch(0)->evaluate() + 1;

			storeinglobalram(x, functionmap);
		}


	}

	//useless
	else if (ast->returntype() == "VariableName") {
	}
	else if (ast->returntype() == "CharType") {

}

	//Grouping Classes
	else if (ast->returntype() == "Compound Statement") {
		if (ast->getbranch(0) != NULL) {

			int counter = 0;
			std::map<std::string, std::pair<std::string, std::pair<int, bool>>> mappings;
			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = functionmap.begin();
				it != functionmap.end(); ++it) {
				mappings.insert(std::pair < std::string, std::pair<std::string, std::pair<int, bool>> >(it->first, it->second));
			}
			//std::cout << ast->getbranch(0)->returntype() << std::endl;
			Compile(destReg, mappings, ast->getbranch(0));
			if (ast->getbranch(1) != NULL) {
				Compile(destReg, mappings, ast->getbranch(1));
			}
			std::map<std::string, std::pair<std::string, std::pair<int, bool>> >::iterator ti;
			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = functionmap.begin();
				it != functionmap.end(); ++it) {
				int x1 = it->second.second.first;
				int x2 = mappings.at(it->first).second.first;
				if ((x2) < offset) {
					if ((x2 != -1) && (x1 == -1)) {
						int x = mappings.at(it->first).second.first;
						std::pair <std::string, std::pair<int, bool>> newpos;
						//freeregs[x-1] = 0;
						newpos.first = mappings.at(it->first).first;
						newpos.second.first = -1;
						newpos.second.second = true;
						functionmap.at(it->first) = newpos;
						if (it->second.first[1] != 'f') {
							std::cout << "lw " << it->second.first << "," << std::to_string((memorystorenumber - x) * 4) << "($fp)" << std::endl;
							counter++;
						}
					}
					else if ((x2 == -1) && (x1 != -1)) {
						int x = it->second.second.first;
						std::pair <std::string, std::pair<int, bool>> newpos;
						if (freeregs.size() < 0) {
							freeregs[x - 1] = 0;
						}
						newpos.first = mappings.at(it->first).first;
						newpos.second.first = -1;
						newpos.second.second = true;
						functionmap.at(it->first) = newpos;
						if (it->second.first[1] != 'f') {
							std::cout << "lw " << it->second.first << "," << std::to_string((memorystorenumber - x) * 4) << "($fp)" << std::endl;
							counter++;
						}
					}
					else if ((x2 != -1) && (x1 != -1) && (x2 != x1)) {
						int x = mappings.at(it->first).second.first;
						std::pair <std::string, std::pair<int, bool>> newpos;
						//freeregs[x - 1] = 0;
						if (it->second.first[1] != 'f') {
							std::cout << "lw " << it->second.first << "," << std::to_string((memorystorenumber - x) * 4) << "($fp)" << std::endl;
							counter++;
						}
					}
				}
			}
			int difference = mappings.size() - (functionmap.size());
			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = mappings.begin();
				it != mappings.end(); ++it) {
				std::map<std::string, std::pair<std::string, std::pair<int, bool>>>::iterator ti;
				ti = functionmap.find(it->first);
				if (ti == functionmap.end()) {
					if (it->second.second.first == -1) {
						difference--;
					}
				}
			}

			for (int i = 0; i < (counter); i++) {
				freeregs.pop_back();
			}



			memorystorenumber -= (difference + counter);
			std::cout << std::endl;
			std::cout << "addi $sp,$sp," << (difference + counter) * 4 << std::endl;
			std::cout << "move $fp,$sp" << std::endl;

		}
	}


	//Grouping Lists
	else if (ast->returntype() == "StatementList") {
		if (ast->getbranch(0) != NULL) {
			Compile(destReg, functionmap, ast->getbranch(0));
			if (ast->getbranch(1) != NULL) {
				Compile(destReg, functionmap, ast->getbranch(1));
			}
		}
	}
	else if (ast->returntype() == "COMPOUND LIST") {
		if (ast->getbranch(0) != NULL) {
			Compile(destReg, functionmap, ast->getbranch(0));
			if (ast->getbranch(1) != NULL) {
				Compile(destReg, functionmap, ast->getbranch(1));
			}

		}
	}
	else if (ast->returntype() == "DeclarationList") {
		if (ast->getbranch(0) != NULL) {
			Compile(destReg, functionmap, ast->getbranch(0));
			if (ast->getbranch(1) != NULL) {
				Compile(destReg, functionmap, ast->getbranch(1));
			}

		}
	}

	//Sizeof
	else if (ast->returntype() == "Sizeof") {

		if (ast->getbranch(0)->returntype() == "inttype") {
			std::cout << "li " << destReg << "," << "4" << std::endl;
		}
		else if (ast->getbranch(0)->returntype() == "CharType") {
			std::cout << "li " << destReg << "," << "1" << std::endl;
		}
		else if (ast->getbranch(0)->returntype() == "floattype") {
			std::cout << "li " << destReg << "," <<"4" << std::endl;
		}
		else if (ast->getbranch(0)->returntype() == "doubletype") {
			std::cout << "li " << destReg << "," <<"8" << std::endl;
		}
		else {
			for (std::map<std::string, std::string> ::const_iterator it = sizeofmap.begin();
				it != sizeofmap.end(); ++it) {
				if (it->first == ast->getbranch(0)->name()) {
					if (it->second == "int") {
						std::cout << "li " << destReg << ","<<"4" << std::endl;
					}
					else if (it->second == "char") {
						std::cout << "li " << destReg << "," <<"1" << std::endl;
					}
					else if (it->second == "float") {
						std::cout << "li " << destReg << "," << "4" << std::endl;
					}
					else if (it->second == "double") {
						std::cout << "li " << destReg << ","<<"8" << std::endl;
					}
				}
			}
		}
	}

	//Switch Statement
	else if (ast->returntype() == "Switch") {
	std::string x = loadfromram("x", functionmap);
	std::cout << "addi " << "$2" << "," << x << "," << "9" << std::endl;
	std::cout << "move $sp,$fp" << std::endl;
	std::cout << "lw $fp," << 8 << "($sp)" << std::endl;
	std::cout << "addiu $sp,$sp," << 12 << std::endl;
	std::cout << "jr $31" << std::endl;
	std::cout << "nop" << std::endl;
}

	//Assign Ops
	else if (ast->returntype() == "AssignOp") {
		if (ast->getbranch(0)->returntype() != ("Array Declaration") && ast->getbranch(0)->returntype() != "Array Identifier") {
			if (ast->getbranch(1)->returntype() == "Number") {
				std::string x2 = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "li " << x2 << "," << ast->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(1)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "add " << x << "," << x2 << ",$0" << std::endl;
				//std::cout << "sw " << x << " " << (stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
			}
			else if (ast->getbranch(1)->returntype() == "CharName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "li " << x << "," << ast->getbranch(1)->evaluate() << std::endl;
			}
			else {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				Compile(x, functionmap, ast->getbranch(1));
			}
		}
		else {
			if (ast->getbranch(0)->returntype() == "Array Identifier") {
				if (ast->getbranch(0)->getbranch(1)->returntype() == "Number") {
					std::string variablename = ast->getbranch(0)->getbranch(0)->name() + "[" + std::to_string((int)ast->getbranch(0)->getbranch(1)->evaluate()) + "]";
					std::string reg = registerGenerator(variablename, functionmap);
					if (ast->getbranch(1)->returntype() == "Number") {
						std::cout << "li " << reg << "," << ast->getbranch(1)->evaluate() << std::endl;
						std::cout << "sw " << reg << "," << (memorystorenumber - (functionmap.at(variablename).second.first)) * 4 << "($fp)" << std::endl;
					}
					else if (ast->getbranch(1)->returntype() == "VariableName") {

						std::string tem = loadfromram(ast->getbranch(1)->name(), functionmap);
						std::cout << "add " << reg << "," << tem << "," << "$0" << std::endl;
						std::cout << "sw " << reg << "," << (memorystorenumber - (functionmap.at(variablename).second.first)) * 4 << "($fp)" << std::endl;
					}
					else {
						std::string tem = randomVarGenerator(functionmap);
						Compile(tem, functionmap, ast->getbranch(1));
						std::cout << "add " << reg << "," << tem << "," << "$0" << std::endl;
						std::cout << "sw " << reg << "," << (memorystorenumber - (functionmap.at(variablename).second.first)) * 4 << "($fp)" << std::endl;
					}
				}
				else if (ast->getbranch(0)->getbranch(1)->returntype() == "VariableName") {
					std::string variablename = ast->getbranch(0)->getbranch(0)->name() + "[0]";
					int x = functionmap.at(variablename).second.first;
					std::string variable = ast->getbranch(0)->getbranch(1)->name();
					variable = loadfromram(variable, functionmap);
					std::string temporarystore = randomVarGenerator(functionmap);
					std::cout << "sub " << temporarystore << "," << "$fp" << "," << variable << std::endl;
					std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
					std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
					std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
					std::string reg = randomVarGenerator(functionmap);
					if (ast->getbranch(1)->returntype() == "Number") {
						std::cout << "li " << reg << "," << ast->getbranch(1)->evaluate() << std::endl;
						std::cout << "sw " << reg << "," << (memorystorenumber - (x)) * 4 << "(" << temporarystore << ")" << std::endl;
					}
					else if (ast->getbranch(1)->returntype() == "VariableName") {

						std::string tem = loadfromram(ast->getbranch(1)->name(), functionmap);
						std::cout << "add " << reg << "," << tem << "," << "$0" << std::endl;
						std::cout << "sw " << reg << "," << (memorystorenumber - (x)) * 4 << "(" << temporarystore << ")" << std::endl;
					}
					else {
						std::string tem = randomVarGenerator(functionmap);
						Compile(tem, functionmap, ast->getbranch(1));
						std::cout << "add " << reg << "," << tem << "," << "$0" << std::endl;
						std::cout << "sw " << reg << "," << (memorystorenumber - (x)) * 4 << "(" << temporarystore << ")" << std::endl;
					}
				}
				else {
					std::string variablename = ast->getbranch(0)->getbranch(0)->name() + "[0]";
					int x = functionmap.at(variablename).second.first;
					std::string variable = randomVarGenerator(functionmap);
					Compile(variable, functionmap, ast->getbranch(0)->getbranch(1));
					std::string temporarystore = randomVarGenerator(functionmap);
					std::cout << "sub " << temporarystore << "," << "$fp" << "," << variable << std::endl;
					std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
					std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
					std::cout << "sub " << temporarystore << "," << temporarystore << "," << variable << std::endl;
					std::string reg = randomVarGenerator(functionmap);
					if (ast->getbranch(1)->returntype() == "Number") {
						std::cout << "li " << reg << "," << ast->getbranch(1)->evaluate() << std::endl;
						std::cout << "sw " << reg << "," << (memorystorenumber - (x)) * 4 << "(" << temporarystore << ")" << std::endl;
					}
					else if (ast->getbranch(1)->returntype() == "VariableName") {

						std::string tem = loadfromram(ast->getbranch(1)->name(), functionmap);
						std::cout << "add " << reg << "," << tem << "," << "$0" << std::endl;
						std::cout << "sw " << reg << "," << (memorystorenumber - (x)) * 4 << "(" << temporarystore << ")" << std::endl;
					}
					else {
						std::string tem = randomVarGenerator(functionmap);
						Compile(tem, functionmap, ast->getbranch(1));
						std::cout << "add " << reg << "," << tem << "," << "$0" << std::endl;
						std::cout << "sw " << reg << "," << (memorystorenumber - (x)) * 4 << "(" << temporarystore << ")" << std::endl;
					}
				}
			}
		}
		//Compile(mymap,ast->getbranch(0));


	}
	else if (ast->returntype() == "AddAssignOp") {
		if (ast->getbranch(1)->returntype() == "Number") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::cout << "addi " << x << "," << x << "," << ast->getbranch(1)->evaluate() << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
			std::cout << "add " << x << "," << x << "," << x2 << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::string x = loadfromram(ast->name(), functionmap);
			Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "add " << x << "," << x << "," << temporaryReg << std::endl;
		}
	}
	else if (ast->returntype() == "subAssignOp") {
		if (ast->getbranch(1)->returntype() == "Number") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::cout << "addi " << x << "," << x << ",-" << ast->getbranch(1)->evaluate() << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
			std::cout << "sub " << x << "," << x << "," << x2 << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::string x = loadfromram(ast->name(), functionmap);
			Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "sub " << x << "," << x << "," << temporaryReg << std::endl;
		}
	}
	else if (ast->returntype() == "multAssignOp") {
		if (ast->getbranch(1)->returntype() == "Number") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::cout << "li " << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
			//Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "mult " << x << "," << temporaryReg << std::endl;
			std::cout << "mflo " << x << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
			std::cout << "mult " << x << "," << x2 << std::endl;
			std::cout << "mflo " << x << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::string x = loadfromram(ast->name(), functionmap);;
			Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "mult " << x << "," << temporaryReg << std::endl;
			std::cout << "mflo " << x << std::endl;
		}
	}
	else if (ast->returntype() == "divAssignOp") {
		if (ast->getbranch(1)->returntype() == "Number") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::cout << "li " << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
			//Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "div " << x << "," << temporaryReg << std::endl;
			std::cout << "mflo " << x << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);;
			std::cout << "div " << x << "," << x2 << std::endl;
			std::cout << "mflo " << x << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::string x = loadfromram(ast->name(), functionmap);
			Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "div " << x << "," << temporaryReg << std::endl;
			std::cout << "mflo " << x << std::endl;
		}
	}
	else if (ast->returntype() == "ModAssignOp") {
		if (ast->getbranch(1)->returntype() == "Number") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::cout << "li " << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
			//Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "div " << x << ",-" << temporaryReg << std::endl;
			std::cout << "mfhi " << x << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->name(), functionmap);;
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);;
			std::cout << "div " << x << "," << x2 << std::endl;
			std::cout << "mfhi " << x << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::string x = loadfromram(ast->name(), functionmap);
			Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "div " << x << "," << temporaryReg << std::endl;
			std::cout << "mfhi " << x << std::endl;
		}
	}
	else if (ast->returntype() == "LeftShiftAssignOp") {
		if (ast->getbranch(1)->returntype() == "Number") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::cout << "sll " << x << "," << x << "," << ast->getbranch(1)->evaluate() << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
			std::cout << "sllv " << x << "," << x << "," << x2 << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::string x = loadfromram(ast->name(), functionmap);
			Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "sllv " << x << "," << x << "," << temporaryReg << std::endl;
		}
	}
	else if (ast->returntype() == "RightShiftAssignOp") {
		if (ast->getbranch(1)->returntype() == "Number") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::cout << "sra " << x << "," << x << "," << ast->getbranch(1)->evaluate() << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
			std::cout << "srav " << x << "," << x << "," << x2 << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::string x = loadfromram(ast->name(), functionmap);
			Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "srav " << x << "," << x << "," << temporaryReg << std::endl;
		}
	}
	else if (ast->returntype() == "AndAssignOp") {
		if (ast->getbranch(1)->returntype() == "Number") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::cout << "andi " << x << "," << x << "," << ast->getbranch(1)->evaluate() << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
			std::cout << "and " << x << "," << x << "," << x2 << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::string x = loadfromram(ast->name(), functionmap);
			Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "and " << x << "," << x << "," << temporaryReg << std::endl;
		}
	}
	else if (ast->returntype() == "ExclOrAssignOp") {
		if (ast->getbranch(1)->returntype() == "Number") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::cout << "xori " << x << "," << x << "," << ast->getbranch(1)->evaluate() << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
			std::cout << "xor " << x << "," << x << "," << x2 << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::string x = loadfromram(ast->name(), functionmap);
			Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "xor " << x << "," << x << "," << temporaryReg << std::endl;
		}
	}
	else if (ast->returntype() == "InclOrAssignOp") {
		if (ast->getbranch(1)->returntype() == "Number") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::cout << "ori " << x << "," << x << "," << ast->getbranch(1)->evaluate() << std::endl;
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->name(), functionmap);
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
			std::cout << "or " << x << "," << x << "," << x2 << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::string x = loadfromram(ast->name(), functionmap);
			Compile(temporaryReg, functionmap, ast->getbranch(1));
			std::cout << "or " << x << "," << x << "," << temporaryReg << std::endl;
		}
	}

	//Unary Ops
	else if (ast->returntype() == "UnaryOp") {
		if (ast->getbranch(0)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
			if (ast->name() == "+") {
				std::cout << "add " << destReg << ",$0," << x << std::endl;
			}
			else if (ast->name() == "-") {
				std::cout << "sub " << destReg << ",$0," << x << std::endl;
			}
			else if (ast->name() == "*") {
				//still yet to be implemented
			}
			else if (ast->name() == "~") {
				std::cout << "nor " << destReg << "," << x << ",$0" << std::endl;
			}
			else if (ast->name() == "!") {
				if (ast->evaluate() == 0) {
					std::cout << "li " << x << "0" << std::endl;
				}
				else {
					std::cout << "li " << x << "1" << std::endl;
				}
			}
		}
		else {
			if (ast->name() == "+") {
				std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
			}
			else if (ast->name() == "-") {
				std::cout << "li " << destReg << "," << -(ast->evaluate()) << std::endl;
			}
			else if (ast->name() == "*") {
				//still yet to be implemented
			}
			else if (ast->name() == "~") {
				std::cout << "li " << destReg << "," << ~((unsigned int)ast->evaluate()) << std::endl;
			}
			else if (ast->name() == "!") {
				if (ast->evaluate() == 0) {
					std::cout << "li " << destReg << "0" << std::endl;
				}
				else {
					std::cout << "li " << destReg << "1" << std::endl;
				}
			}
		}
	}

	//Unary Expr
	else if (ast->returntype() == "UnaryExpr") {
		std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);;
		if (ast->name() == "++") {
			std::cout << "addi " << x << "," << x << "," << "1" << std::endl;
		}
		else if (ast->name() == "--") {
			std::cout << "addi " << x << "," << x << "," << "-1" << std::endl;
		}
	}

	//Loop statements
	else if (ast->returntype() == "IFElseStatement") {
		std::string label1 = makeLabel();
		std::string label2 = makeLabel();
		if (ast->getbranch(0)->returntype() == "Number") {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
			std::cout << "beq " << temporaryReg << ",$0," << label1 << std::endl;
			std::cout << "nop" << std::endl;
		}
		else if (ast->getbranch(0)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
			std::cout << "beq " << x << ",$0," << label1 << std::endl;
			std::cout << "nop" << std::endl;
		}
		else {
			std::string tempreg = randomVarGenerator(functionmap);
			Compile(tempreg, functionmap, ast->getbranch(0)); //could just change the destreg parameter in here
			std::cout << "beq " << tempreg << ",$0" << "," << label1 << std::endl;
			std::cout << "nop" << std::endl;
		}
		Compile(label1, functionmap, ast->getbranch(1));
		std::cout << "j " << label2 << std::endl;

		std::cout << label1 << ":" << std::endl;
		Compile(destReg, functionmap, ast->getbranch(2));
		std::cout << label2 << ":" << std::endl;
	}
	else if (ast->returntype() == "IFStatement") {
		std::string label1 = makeLabel();
		if (ast->getbranch(0)->returntype() == "Number") {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
			std::cout << "beq " << temporaryReg << ",$0," << label1 << std::endl;
			std::cout << "nop" << std::endl;
		}
		else if (ast->getbranch(0)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
			std::cout << "beq " << x << ",$0," << label1 << std::endl;
			std::cout << "nop" << std::endl;
		}
		else {
			std::string tempreg = randomVarGenerator(functionmap);
			Compile(tempreg, functionmap, ast->getbranch(0)); //could just change the destreg parameter in here
			std::cout << "beq " << tempreg << ",$0" << "," << label1 << std::endl;
			std::cout << "nop" << std::endl;
		}
		Compile(destReg, functionmap, ast->getbranch(1));
		std::cout << label1 << ":" << std::endl;
	}
	else if (ast->returntype() == "While") {
		std::string label1 = makeLabel();
		std::string label2 = makeLabel();
		std::cout << label2 << ":" << std::endl;
		if (ast->getbranch(0)->returntype() == "Number") {
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
			std::cout << "beq " << temporaryReg << ",$0," << label1 << std::endl;
			std::cout << "nop" << std::endl;
		}
		else if (ast->getbranch(0)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
			std::cout << "beq " << x << ",$0," << label1 << std::endl;
			std::cout << "nop" << std::endl;
		}
		else {
			std::string tempreg = randomVarGenerator(functionmap);
			Compile(tempreg, functionmap, ast->getbranch(0)); //could just change the destreg parameter in here
			std::cout << "beq " << tempreg << ",$0" << "," << label1 << std::endl;
			std::cout << "nop" << std::endl;
		}
		if (ast->getbranch(1)->getbranch(0) != NULL) {
			Compile(destReg, functionmap, ast->getbranch(1));
		}
		std::cout << "j " << label2 << std::endl;
		std::cout << "nop" << std::endl;
		std::cout << label1 << ":" << std::endl;
	}

	//For Loop
	else if (ast->returntype() == "For Loop") {
		std::string label1 = makeLabel();
		std::string label2 = makeLabel();
		std::string label3 = makeLabel();

		std::map<std::string, std::pair<std::string, std::pair<int, bool>>> mappings;
		for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = functionmap.begin();
			it != functionmap.end(); ++it) {
			mappings.insert(std::pair < std::string, std::pair<std::string, std::pair<int, bool>> >(it->first, it->second));
		}
		if (ast->getbranch(0)->returntype() == "Variable") {
			//std::cout << localcounter << " " << memorystorenumber << std::endl;
			Compile(destReg, mappings, ast->getbranch(0));

			//std::cout << localcounter << " " << memorystorenumber << std::endl;
			//for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = functionmap.begin();
			//	it != functionmap.end(); ++it) {
			//	std::cout << "list is : " << it->first << " " << it->second.first << " " << it->second.second.first << " " << it->second.second.second << std::endl;
			//}
			//could store previous one in memory
			//std::cout << std::endl;
			//functionmap.insert(std::pair<std::string, std::pair<std::string, std::pair<int, bool> > >(variable, x));
		}
		else {
			Compile(destReg, functionmap, ast->getbranch(0));
		}
		std::cout << label2 << ":" << std::endl;
		std::string tempreg = randomVarGenerator(functionmap);

		Compile(tempreg, mappings, ast->getbranch(1)); //could just change the destreg parameter in here
		std::cout << "beq " << tempreg << ",$0" << "," << label1 << std::endl;
		std::cout << "nop" << std::endl;
		Compile(label1, mappings, ast->getbranch(3));
		std::cout << label3 << ":" << std::endl;
		Compile(destReg, mappings, ast->getbranch(2));
		std::cout << "j " << label2 << std::endl;
		std::cout << "nop" << std::endl;
		std::cout << label1 << ":" << std::endl;
		int counter = 0;

		if (ast->getbranch(0)->returntype() == "Variable") {

			//functionmap[ast->getbranch(0)->name()].second.second = false;
			for (std::map<std::string, std::pair<std::string, std::pair<int, bool>>> ::const_iterator it = mappings.begin();
				it != mappings.end(); ++it) {
				if (ast->getbranch(0)->name() == it->first) {
					int x = it->second.second.first;
					int z = memorystorenumber - x;
					std::cout << "lw " << it->second.first << "," << z << "($fp)" << std::endl;
					if (freeregs.size() > 0) {
						freeregs[x - 1] = 0;
					}
				}
			}
		}
	}
	else if (ast->returntype() == "Break") {
		std::cout << "j " << destReg << std::endl;
		std::cout << "nop" << std::endl;
	}
	else if (ast->returntype() == "Continue") {
		std::string x = destReg;
		char n = x[x.length()];
		int integer = (int)n;
		integer += 2;
		x.pop_back();
		x = x + std::to_string(integer);
		std::cout << "j " << x << std::endl;
		std::cout << "nop" << std::endl;
	}

	//Comparison operations
	else if (ast->returntype() == "Equal") {
		std::string label = makeLabel();
		std::string label2 = makeLabel();
		if (ast->getbranch(1)->returntype() == "Number") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "bne " << temporaryReg << "," << temporaryReg2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "bne " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "bne " << temporaryReg << "," << temporaryReg2 << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "bne " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "bne " << x << "," << x2 << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "bne " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "bne " << temporaryReg2 << "," << temporaryReg << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(1));
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "bne " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "bne " << temporaryReg << "," << temporaryReg2 << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
	}
	else if (ast->returntype() == "NotEqual") {
		{
			std::string label = makeLabel();
			std::string label2 = makeLabel();
			if (ast->getbranch(1)->returntype() == "Number") {
				if (ast->getbranch(0)->returntype() == "Number") {
					std::string temporaryReg = randomVarGenerator(functionmap);
					std::string temporaryReg2 = randomVarGenerator(functionmap);
					std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
					std::cout << "li " << temporaryReg2 << "," << ast->getbranch(1)->evaluate() << std::endl;
					std::cout << "beq " << temporaryReg << "," << temporaryReg2 << "," << label << std::endl;
					std::cout << "nop" << std::endl;
					std::cout << "li " << destReg << ",1" << std::endl;
					std::cout << "j " << label2 << std::endl;
					std::cout << "nop" << std::endl;
					std::cout << label << ":" << std::endl;
					std::cout << "li " << destReg << ",0" << std::endl;
					std::cout << label2 << ":" << std::endl;
				}
				else if (ast->getbranch(0)->returntype() == "VariableName") {
					std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
					std::string temporaryReg = randomVarGenerator(functionmap);
					std::cout << "li " << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
					std::cout << "beq " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
					std::cout << "nop" << std::endl;
					std::cout << "li " << destReg << ",1" << std::endl;
					std::cout << "j " << label2 << std::endl;
					std::cout << "nop" << std::endl;
					std::cout << label << ":" << std::endl;
					std::cout << "li " << destReg << ",0" << std::endl;
					std::cout << label2 << ":" << std::endl;
				}
				else {
					std::string temporaryReg = randomVarGenerator(functionmap);
					Compile(temporaryReg, functionmap, ast->getbranch(0));
					std::string temporaryReg2 = randomVarGenerator(functionmap);
					std::cout << "li " << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
					std::cout << "beq " << temporaryReg << "," << temporaryReg2 << "," << label << std::endl; //fix this later on
					std::cout << "nop" << std::endl;
					std::cout << "li " << destReg << ",1" << std::endl;
					std::cout << "j " << label2 << std::endl;
					std::cout << "nop" << std::endl;
					std::cout << label << ":" << std::endl;
					std::cout << "li " << destReg << ",0" << std::endl;
					std::cout << label2 << ":" << std::endl;
				}
			}
			else if (ast->getbranch(1)->returntype() == "VariableName") {
				if (ast->getbranch(0)->returntype() == "Number") {
					std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
					std::string temporaryReg = randomVarGenerator(functionmap);
					std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
					std::cout << "beq " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
					std::cout << "nop" << std::endl;
					std::cout << "li " << destReg << ",1" << std::endl;
					std::cout << "j " << label2 << std::endl;
					std::cout << "nop" << std::endl;
					std::cout << label << ":" << std::endl;
					std::cout << "li " << destReg << ",0" << std::endl;
					std::cout << label2 << ":" << std::endl;
				}
				else if (ast->getbranch(0)->returntype() == "VariableName") {
					std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
					std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
					std::cout << "beq " << x << "," << x2 << "," << label << std::endl; //fix this later on
					std::cout << "nop" << std::endl;
					std::cout << "li " << destReg << ",1" << std::endl;
					std::cout << "j " << label2 << std::endl;
					std::cout << "nop" << std::endl;
					std::cout << label << ":" << std::endl;
					std::cout << "li " << destReg << ",0" << std::endl;
					std::cout << label2 << ":" << std::endl;
				}
				else {
					std::string temporaryReg = randomVarGenerator(functionmap);
					Compile(temporaryReg, functionmap, ast->getbranch(0));
					std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
					std::cout << "beq " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
					std::cout << "nop" << std::endl;
					std::cout << "li " << destReg << ",1" << std::endl;
					std::cout << "j " << label2 << std::endl;
					std::cout << "nop" << std::endl;
					std::cout << label << ":" << std::endl;
					std::cout << "li " << destReg << ",0" << std::endl;
					std::cout << label2 << ":" << std::endl;;
				}
			}
			else {
				if (ast->getbranch(0)->returntype() == "Number") {
					std::string temporaryReg = randomVarGenerator(functionmap);
					std::string temporaryReg2 = randomVarGenerator(functionmap);
					std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
					Compile(temporaryReg2, functionmap, ast->getbranch(1));
					std::cout << "beq " << temporaryReg2 << "," << temporaryReg << "," << label << std::endl; //fix this later on
					std::cout << "nop" << std::endl;
					std::cout << "li " << destReg << ",1" << std::endl;
					std::cout << "j " << label2 << std::endl;
					std::cout << "nop" << std::endl;
					std::cout << label << ":" << std::endl;
					std::cout << "li " << destReg << ",0" << std::endl;
					std::cout << label2 << ":" << std::endl;
				}
				else if (ast->getbranch(0)->returntype() == "VariableName") {
					std::string temporaryReg = randomVarGenerator(functionmap);
					Compile(temporaryReg, functionmap, ast->getbranch(1));
					std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
					std::cout << "beq " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
					std::cout << "nop" << std::endl;
					std::cout << "li " << destReg << ",1" << std::endl;
					std::cout << "j " << label2 << std::endl;
					std::cout << "nop" << std::endl;
					std::cout << label << ":" << std::endl;
					std::cout << "li " << destReg << ",0" << std::endl;
					std::cout << label2 << ":" << std::endl;
				}
				else {
					std::string temporaryReg = randomVarGenerator(functionmap);
					Compile(temporaryReg, functionmap, ast->getbranch(0));
					std::string temporaryReg2 = randomVarGenerator(functionmap);
					Compile(temporaryReg2, functionmap, ast->getbranch(1));
					std::cout << "beq " << temporaryReg << "," << temporaryReg2 << "," << label << std::endl; //fix this later on
					std::cout << "nop" << std::endl;
					std::cout << "li " << destReg << ",1" << std::endl;
					std::cout << "j " << label2 << std::endl;
					std::cout << "nop" << std::endl;
					std::cout << label << ":" << std::endl;
					std::cout << "li " << destReg << ",0" << std::endl;
					std::cout << label2 << ":" << std::endl;
				}
			}
		}
	}
	else if (ast->returntype() == "GreaterThan") {
		std::string label = makeLabel();
		std::string label2 = makeLabel();
		if (ast->getbranch(1)->returntype() == "Number") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "slti " << temporaryReg2 << "," << temporaryReg << "," << ast->getbranch(1)->evaluate() + 1 << std::endl;
				std::cout << "bne " << temporaryReg2 << ",$0" << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg << "," << x << "," << ast->getbranch(1)->evaluate() + 1 << std::endl;
				std::cout << "bne " << temporaryReg << ",$0 " << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg2 << "," << temporaryReg << "," << ast->getbranch(1)->evaluate() + 1 << std::endl;
				std::cout << "bne " << temporaryReg2 << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg << "," << x << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "beq " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slt " << temporaryReg << "," << x2 << "," << x << std::endl;
				std::cout << "beq " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "slt " << temporaryReg << "," << temporaryReg << "," << x << std::endl;
				std::cout << "beq " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "slti " << temporaryReg << "," << temporaryReg2 << "," << ast->getbranch(0)->evaluate() << std::endl;

				std::cout << "beq " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(1));
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "slt " << temporaryReg << "," << x << "," << temporaryReg << std::endl;
				std::cout << "beq " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "slt " << temporaryReg << "," << temporaryReg << "," << temporaryReg2 << std::endl;
				std::cout << "beq " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
	}
	else if (ast->returntype() == "LessThan") {
		std::string label = makeLabel();
		std::string label2 = makeLabel();
		if (ast->getbranch(1)->returntype() == "Number") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);

				std::string temporaryReg2 = randomVarGenerator(functionmap);

				std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "slti " << temporaryReg2 << "," << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "beq " << temporaryReg2 << ",$0 " << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {

				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg << "," << x << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "beq " << temporaryReg << ",$0 " << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg2 << "," << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "beq " << temporaryReg2 << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg << "," << x << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "bne " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slt " << temporaryReg << "," << x << "," << x2 << std::endl;
				std::cout << "beq " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "slt " << temporaryReg << "," << temporaryReg << "," << x << std::endl;
				std::cout << "bne " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "slti " << temporaryReg << "," << temporaryReg2 << "," << ast->getbranch(0)->evaluate() << std::endl;

				std::cout << "bne " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(1));
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "slt " << temporaryReg << "," << x << "," << temporaryReg << std::endl;
				std::cout << "bne " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "slt " << temporaryReg << "," << temporaryReg << "," << temporaryReg2 << std::endl;
				std::cout << "bne " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
	}
	else if (ast->returntype() == "GreaterEqualThan") {
		std::string label = makeLabel();
		std::string label2 = makeLabel();
		if (ast->getbranch(1)->returntype() == "Number") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "slti " << temporaryReg2 << "," << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "bne " << temporaryReg2 << ",$0 " << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << "1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << "0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg << "," << x << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "bne " << temporaryReg << ",$0 " << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << "1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << "0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg2 << "," << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "bne " << temporaryReg2 << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << "1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << "0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg << "," << x << "," << ast->getbranch(0)->evaluate() + 1 << std::endl;
				std::cout << "beq " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << "1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << "0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slt " << temporaryReg << "," << x << "," << x2 << std::endl;
				std::cout << "bne " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << "1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << "0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "slt " << temporaryReg << "," << x << "," << temporaryReg << std::endl;
				std::cout << "bne " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << "1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << "0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "slti " << temporaryReg << "," << temporaryReg2 << "," << ast->getbranch(0)->evaluate() + 1 << std::endl;

				std::cout << "beq " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << "1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << "0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(1));
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "slt " << temporaryReg << "," << temporaryReg << "," << x << std::endl;
				std::cout << "bne " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << "1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << "0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "slt " << temporaryReg << "," << temporaryReg2 << "," << temporaryReg << std::endl;
				std::cout << "bne " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << "1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << "0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
	}
	else if (ast->returntype() == "LessEqualThan") {
		std::string label = makeLabel();
		std::string label2 = makeLabel();
		if (ast->getbranch(1)->returntype() == "Number") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "slti " << temporaryReg2 << "," << temporaryReg << "," << ast->getbranch(1)->evaluate() + 1 << std::endl;
				std::cout << "beq " << temporaryReg2 << ",$0 " << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg << "," << x << "," << ast->getbranch(1)->evaluate() + 1 << std::endl;
				std::cout << "beq " << temporaryReg << ",$0 " << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg2 << "," << temporaryReg << "," << ast->getbranch(1)->evaluate() + 1 << std::endl;
				std::cout << "beq " << temporaryReg2 << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slti " << temporaryReg << "," << x << "," << ast->getbranch(0)->evaluate() + 1 << std::endl;
				std::cout << "bne " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "slt " << temporaryReg << "," << x2 << "," << x << std::endl;
				std::cout << "bne " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "slt " << temporaryReg << "," << x << "," << temporaryReg << std::endl;
				std::cout << "beq " << x << "," << temporaryReg << "," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "slti " << temporaryReg << "," << temporaryReg2 << "," << ast->getbranch(0)->evaluate() + 1 << std::endl;

				std::cout << "bne " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(1));
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "slt " << temporaryReg << "," << temporaryReg << "," << x << std::endl;
				std::cout << "beq " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "slt " << temporaryReg << "," << temporaryReg2 << "," << temporaryReg << std::endl;
				std::cout << "beq " << temporaryReg << ",$0," << label << std::endl; //fix this later on
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
	}

	//types 
	else if (ast->returntype() == "inttype") {
	}
	else if (ast->returntype() == "CharName") {
	std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
}


	//Arithmetic Operators

	else if (ast->returntype() == "AddOp") {
		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				//std::string x = functionmap.find(ast->getbranch(0)->name())->second.first;
				std::cout << "addi " << destReg << "," << x << "," << ast->evaluate() << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::cout << "addi " << destReg << "," << tempvar << "," << ast->getbranch(1)->evaluate() << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "addi " << destReg << "," << x << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				if (destReg[1] == 'f') {
					std::cout << "add.s " << destReg << "," << x << "," << x2 << std::endl;
				}
				else if (destReg[1] == 'd') {
					std::string dest = destReg;
					dest.erase(1, 1);
					dest = dest.substr(0, 1) + "f" + dest.substr(1);
					std::cout << "add.d " << dest << "," << x << "," << x2 << std::endl;
				}
				else {
					std::cout << "add " << destReg << "," << x << "," << x2 << std::endl;
				}
			}
			else {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string tempvar;
				if (destReg[1] != 'f' && destReg[1] != 'd') {
					tempvar = randomVarGenerator(functionmap);
				}
				else if (destReg[1] == 'f'){
					tempvar = randomFloatVarGenerator(functionmap);
				}
				else {
					tempvar = randomDoubleVarGenerator(functionmap);
				}
				Compile(tempvar, functionmap, ast->getbranch(0));
				if (destReg[1] != 'f' && destReg[1] != 'd') {
					std::cout << "add " << destReg << "," << tempvar << "," << x << std::endl;
				}
				else if (destReg[1] == 'f') {
					std::cout << "add.s " << destReg << "," << tempvar << "," << x << std::endl;
				}
				else if (destReg[1] == 'd') {
					std::string dest = destReg;
					dest.erase(1, 1);
					dest = dest.substr(0, 1) + "f" + dest.substr(1);
					std::cout << "add.d " << dest << "," << tempvar << "," << x << std::endl;
				}
			}

		}
		else {
			//Compile(destReg,functionmap, ast->getbranch(0));
			std::string tempvar;
			if (destReg[1] != 'f') {
				tempvar = randomVarGenerator(functionmap);
			}
			else {
				tempvar = randomFloatVarGenerator(functionmap);
			}
			Compile(tempvar, functionmap, ast->getbranch(1));
			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "addi " << destReg << "," << tempvar << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				if (destReg[1] == 'f') {
					std::cout << "add.s " << destReg << "," << x << "," << tempvar << std::endl;
				}
				else if (destReg[1] == 'd') {
					std::string dest = destReg;
					dest.erase(1, 1);
					dest = dest.substr(0, 1) + "f" + dest.substr(1);
					std::cout << "add.d " << dest << "," << x << "," << tempvar << std::endl;
				}
				else {
					std::cout << "add " << destReg << "," << x << "," << tempvar << std::endl;
				}
			}
			else {
				std::string tempvar2;
				if (tempvar[1] != 'f' && destReg[1] != 'd') {
					 tempvar2 = randomVarGenerator(functionmap);
				}
				else if (destReg[1] == 'f') {
					tempvar2 = randomFloatVarGenerator(functionmap);
				}
				else {
					//for doubles
				}
				Compile(tempvar2, functionmap, ast->getbranch(0));
				if (destReg[1] != 'f' && destReg[1] != 'd') {
					std::cout << "add " << destReg << "," << tempvar << "," << tempvar2 << std::endl;
				}
				else if (destReg[1] == 'f'){
					std::cout << "add.s " << destReg << "," << tempvar << "," << tempvar2 << std::endl;
				}
				else {
					std::string dest = destReg;
					dest.erase(1, 1);
					dest = dest.substr(0, 1) + "f" + dest.substr(1);
					std::cout << "add.d " << dest << "," << tempvar << "," << tempvar2 << std::endl;
				}
			}
		}
	}
	else if (ast->returntype() == "SubOp") {
	if (ast->getbranch(1)->returntype() == "Number") {

		if (ast->getbranch(0)->returntype() == "Number") {
			std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
			//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
			//stackcounter++;
			//std::cout << "sw " 
		}
		else if (ast->getbranch(0)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
			std::cout << "addi " << destReg << "," << x << ",-" << ast->getbranch(1)->evaluate() << std::endl;
		}
		else {
			std::string temporaryReg = randomVarGenerator(functionmap);
			Compile(temporaryReg, functionmap, ast->getbranch(0));
			std::cout << "addi " << destReg << "," << temporaryReg << ",-" << ast->getbranch(1)->evaluate() << std::endl;
		}
	}
	else if (ast->getbranch(1)->returntype() == "VariableName") {

		if (ast->getbranch(0)->returntype() == "Number") {
			std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
			std::string temporaryReg = randomVarGenerator(functionmap);
			std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
			std::cout << "sub " << destReg << "," << temporaryReg << "," << x << std::endl;
			//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
			//stackcounter++;
			//std::cout << "sw " 
		}
		else if (ast->getbranch(0)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
			std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
			if (x[1] == 'f' || x2[1] == 'f') {
				std::cout << "sub.s " << destReg << "," << x << "," << x2 << std::endl;
			}
			else if (x[1] == 'd' && x2[1] == 'd') {
				std::cout << "sub.d " << destReg << "," << x << "," << x2 << std::endl;
			}
			else {
				std::cout << "sub " << destReg << "," << x << "," << x2 << std::endl;
			}
		}
		else {
			std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
			std::string tempvar;
			if (x[1] != 'f' && x[1] != 'd') {
				tempvar = randomVarGenerator(functionmap);
			}
			else if (x[1] == 'f') {
				tempvar = randomFloatVarGenerator(functionmap);
			}
			else {
				tempvar = randomDoubleVarGenerator(functionmap);
			}
			Compile(tempvar, functionmap, ast->getbranch(0));
			if (destReg[1] != 'f' && destReg[1] != 'd') {
				std::cout << "sub" << destReg << "," << tempvar << "," << x << std::endl;
			}
			else if (destReg[1] == 'f') {
				std::cout << "sub.s " << destReg << "," << tempvar << "," << x << std::endl;
			}
			else if (destReg[1] == 'd') {
				std::cout << "sub.d " << destReg << "," << tempvar << "," << x << std::endl;
			}
		}
	}
	else {
		//Compile(destReg,functionmap, ast->getbranch(0));
		std::string tempvar;
		if (destReg[1] != 'f') {
			tempvar = randomVarGenerator(functionmap);
		}
		else {
			tempvar = randomFloatVarGenerator(functionmap);
		}
		Compile(tempvar, functionmap, ast->getbranch(1));
		if (ast->getbranch(0)->returntype() == "Number") {
			std::cout << "addi " << destReg << "," << tempvar << ",-" << ast->getbranch(0)->evaluate() << std::endl;
			//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
			//stackcounter++;
			//std::cout << "sw " 
		}
		else if (ast->getbranch(0)->returntype() == "VariableName") {
			std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
			if (destReg[1] == 'f') {
				std::cout << "sub.s " << destReg << "," << x << "," << tempvar << std::endl;
			}
			else if (destReg[1] == 'd') {
				std::cout << "sub.d " << destReg << "," << x << "," << tempvar << std::endl;
			}
			else {
				std::cout << "sub " << destReg << "," << x << "," << tempvar << std::endl;
			}
		}
		else {
			std::string tempvar2;
			if (tempvar[1] != 'f' && destReg[1] != 'd') {
				tempvar2 = randomVarGenerator(functionmap);
			}
			else if (destReg[1] == 'f') {
				tempvar2 = randomFloatVarGenerator(functionmap);
			}
			else {
				//for doubles
			}
			Compile(tempvar2, functionmap, ast->getbranch(0));
			if (destReg[1] != 'f' || destReg[1] != 'd') {
				std::cout << "sub " << destReg << "," << tempvar << "," << tempvar2 << std::endl;
			}
			else if (destReg[1] == 'f') {
				std::cout << "sub.s " << destReg << "," << tempvar << "," << tempvar2 << std::endl;
			}
			else {
				std::cout << "sub.d " << destReg << "," << tempvar << "," << tempvar2 << std::endl;
			}
		}
	}
	}
	else if (ast->returntype() == "MultOp") {
		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				if (ast->getbranch(1)->evaluate() == 1) {}
				else {
					//std::string x = functionmap.find(ast->getbranch(0)->name())->second;
					std::string temporaryReg = randomVarGenerator(functionmap);
					std::cout << "li " << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
					std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
					std::cout << "mult " << x << "," << temporaryReg << std::endl;
					std::cout << "mflo " << destReg << std::endl;
				}
			}
			else {
				if (ast->getbranch(1)->evaluate() == 1) {
					Compile(destReg, functionmap, ast->getbranch(0));
				}
				else {
					std::string temporaryReg = randomVarGenerator(functionmap);
					Compile(temporaryReg, functionmap, ast->getbranch(0));
					std::cout << "li " << destReg << "," << ast->getbranch(1)->evaluate() << std::endl;
					std::cout << "mult " << destReg << "," << temporaryReg << std::endl;
					std::cout << "mflo " << destReg << std::endl;
				}
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {

			if (ast->getbranch(0)->returntype() == "Number") {
				if (ast->getbranch(0)->evaluate() == 1) {}
				else {
					std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
					std::cout << "li " << destReg << "," << ast->getbranch(0)->evaluate() << std::endl;
					std::cout << "mult " << x << "," << destReg << std::endl;
					std::cout << "mflo " << destReg << std::endl;
				}
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				if (x[1] == 'f' || x2[1] == 'f') {
					std::cout << "mul.s " << destReg << "," << x << "," << x2 << std::endl;
				}
				else if (x[1] == 'd' || x2[1] == 'd') {
					std::cout << "mul.d " << destReg << "," << x << "," << x2 << std::endl;
				}
				else {
					std::cout << "mult " << x << "," << x2 << std::endl;
					std::cout << "mflo " << destReg << std::endl;
				}
			}
			else {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string tempvar;
				if (x[1] != 'f' || x[1] != 'd') {
					tempvar = randomVarGenerator(functionmap);
				}
				else if (x[1] == 'f') {
					tempvar = randomFloatVarGenerator(functionmap);
				}
				else {
					tempvar = randomDoubleVarGenerator(functionmap);
				}
				Compile(destReg, functionmap, ast->getbranch(0));
				if (destReg[1] != 'f' && destReg[1] != 'd')
				{
					std::cout << "mult " << destReg << "," << x << std::endl;
					std::cout << "mflo " << destReg << std::endl;
				}
				else if (destReg[1] == 'f') {
					std::cout << "mult.s " << destReg << "," << destReg << x << std::endl;
				}
				else {
					std::cout << "mult.d " << destReg << "," << destReg << x << std::endl;
				}
			}

		}
		else {
			if (ast->getbranch(0)->returntype() == "Number") {
				if (ast->getbranch(0)->evaluate() == 1) {
					Compile(destReg, functionmap, ast->getbranch(1));
				}
				else {
					std::string temporaryReg;
					if (destReg[1] != 'f' && destReg[1] != 'd') {
						temporaryReg = randomVarGenerator(functionmap);
					}
					else if (destReg[1] == 'f') {
						temporaryReg = randomFloatVarGenerator(functionmap);
					}
					else {

					}
					Compile(temporaryReg, functionmap, ast->getbranch(1));
					if (destReg[1] != 'f' && destReg[1] != 'd') {
						std::cout << "li " << destReg << "," << ast->getbranch(0)->evaluate() << std::endl;
						std::cout << "mult " << destReg << "," << temporaryReg << std::endl;
						std::cout << "mflo " << destReg << std::endl;
					}
					else if (destReg[1] == 'f') {
					}
					else {
					}
				}
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string temporaryReg;
				if (destReg[1] != 'f' || destReg[1] != 'd') {
					temporaryReg = randomVarGenerator(functionmap);
				}
				else if (destReg[1] == 'f') {
					temporaryReg = randomFloatVarGenerator(functionmap);
				}
				else {

				}
				if (destReg[1] != 'f' && destReg[1] != 'd') {
					Compile(temporaryReg, functionmap, ast->getbranch(1));
					std::cout << "mult " << x << "," << temporaryReg << std::endl;
					std::cout << "mflo " << destReg << std::endl;
				}
				else if (destReg[1] == 'f') {
					std::cout << "mult.s " << destReg << "," << x << temporaryReg << std::endl;
				}
				else {
					std::cout << "mult.d " << destReg << "," << x << temporaryReg << std::endl;
				}
			}
			else {
				std::string temporaryReg;
				std::string temporaryReg2;
				if (destReg[1] != 'f' && destReg[1] != 'd') {
					temporaryReg = randomVarGenerator(functionmap);
					temporaryReg2 = randomVarGenerator(functionmap);
				}
				else if (destReg[1] == 'f') {
					temporaryReg = randomFloatVarGenerator(functionmap);
					temporaryReg2 = randomFloatVarGenerator(functionmap);
				}
				else {

				}
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				if (destReg[1] != 'f' && destReg[1] != 'd') {
					std::cout << "mult " << temporaryReg << "," << temporaryReg2 << std::endl;
					std::cout << "mflo " << destReg << std::endl;
				}
				else if (destReg[1] == 'f') {
					std::cout << "mult.s " << destReg << "," << temporaryReg << temporaryReg2 << std::endl;
				}
				else {
					std::cout << "mult.d " << destReg << "," << temporaryReg << temporaryReg2 << std::endl;
				}
			}
		}
	}
	else if (ast->returntype() == "DivOp") {
		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				if (ast->getbranch(1)->evaluate() == 1) {
					std::cout << "li " << destReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				}
				else {
					std::string temporaryReg = randomVarGenerator(functionmap);
					std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
					std::string temporaryReg2 = randomVarGenerator(functionmap);
					std::cout << "li " << temporaryReg2 << "," << ast->getbranch(1)->evaluate() << std::endl;
					std::cout << "div " << temporaryReg << "," << temporaryReg2 << std::endl;
					std::cout << "mflo " << destReg << std::endl;
				}
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				//std::string x = functionmap.find(ast->getbranch(0)->name())->second;
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "div " << x << "," << temporaryReg << std::endl;
				std::cout << "mflo " << destReg << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::cout << "li " << destReg << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "div " << destReg << "," << temporaryReg << std::endl;
				std::cout << "mflo " << destReg << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "li " << destReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "div " << destReg << "," << x << std::endl;
				std::cout << "mflo " << destReg << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				if (x[1] == 'f' || x2[1] == 'f') {
					std::cout << "div.s " << destReg << "," << x << "," << x2 << std::endl;
				}
				else if (x[1] == 'd' || x2[1] == 'd') {
					std::cout << "div.d " << destReg << "," << x << "," << x2 << std::endl;
				}
				else {
					std::cout << "div " << x << "," << x2 << std::endl;
					std::cout << "mflo " << destReg << std::endl;
				}
			}
			else {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				Compile(destReg, functionmap, ast->getbranch(0));
				std::cout << "div " << destReg << "," << x << std::endl;
				std::cout << "mflo " << destReg << std::endl;
			}

		}
		else {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(1));
				std::cout << "li " << destReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "div " << destReg << "," << temporaryReg << std::endl;
				std::cout << "mflo " << destReg << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(1));
				std::cout << "div " << x << "," << temporaryReg << std::endl;
				std::cout << "mflo " << destReg << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "div " << temporaryReg << "," << temporaryReg2 << std::endl;
				std::cout << "mflo " << destReg << std::endl;
			}
		}
	}
	else if (ast->returntype() == "ModOp") {
		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "div " << temporaryReg << "," << temporaryReg2 << std::endl;
				std::cout << "mfhi " << destReg << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				//std::string x = functionmap.find(ast->getbranch(0)->name())->second;
				std::cout << "li " << destReg << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "div " << x << "," << destReg << std::endl;
				std::cout << "mfhi " << destReg << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				std::cout << "li " << destReg << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "div " << destReg << "," << temporaryReg << std::endl;
				std::cout << "mfhi " << destReg << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "li " << destReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "div " << destReg << "," << x << std::endl;
				std::cout << "mfhi " << destReg << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "div " << x << "," << x2 << std::endl;
				std::cout << "mfhi " << destReg << std::endl;
			}
			else {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				Compile(destReg, functionmap, ast->getbranch(0));
				std::cout << "div " << destReg << "," << x << std::endl;
				std::cout << "mfhi " << destReg << std::endl;
			}

		}
		else {
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(1));
				std::cout << "li " << destReg << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "div " << destReg << "," << temporaryReg << std::endl;
				std::cout << "mfhi " << destReg << std::endl;
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string temporaryReg = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(1));
				std::cout << "div " << x << "," << temporaryReg << std::endl;
				std::cout << "mfhi " << destReg << std::endl;
			}
			else {
				std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				Compile(temporaryReg, functionmap, ast->getbranch(0));
				Compile(temporaryReg2, functionmap, ast->getbranch(1));
				std::cout << "div " << temporaryReg << "," << temporaryReg2 << std::endl;
				std::cout << "mfhi " << destReg << std::endl;
			}
		}
	}
	else if (ast->returntype() == "AndOp") {
		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				//std::string x = functionmap.find(ast->getbranch(0)->name())->second.first;
				std::cout << "andi " << destReg << "," << x << "," << ast->evaluate() << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::cout << "andi " << destReg << "," << tempvar << "," << ast->getbranch(1)->evaluate() << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "andi " << destReg << "," << x << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "and " << destReg << "," << x << "," << x2 << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "and " << destReg << " " << tempvar << "," << x << std::endl;
			}

		}
		else {
			//Compile(destReg,functionmap, ast->getbranch(0));
			std::string tempvar = randomVarGenerator(functionmap);
			Compile(tempvar, functionmap, ast->getbranch(1));
			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "andi " << destReg << "," << tempvar << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "and " << destReg << "," << x << "," << tempvar << std::endl;
			}
			else {
				std::string tempvar2 = randomVarGenerator(functionmap);
				Compile(tempvar2, functionmap, ast->getbranch(0));
				std::cout << "and " << destReg << " " << tempvar << " " << tempvar2 << std::endl;
			}
		}
	}
	else if (ast->returntype() == "OrOp") {

		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				//std::string x = functionmap.find(ast->getbranch(0)->name())->second.first;
				std::cout << "ori " << destReg << "," << x << "," << ast->evaluate() << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::cout << "ori " << destReg << "," << tempvar << "," << ast->getbranch(1)->evaluate() << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "ori " << destReg << "," << x << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "or " << destReg << "," << x << "," << x2 << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "or " << destReg << " " << tempvar << "," << x << std::endl;
			}

		}
		else {
			//Compile(destReg,functionmap, ast->getbranch(0));
			std::string tempvar = randomVarGenerator(functionmap);
			Compile(tempvar, functionmap, ast->getbranch(1));
			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "ori " << destReg << "," << tempvar << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "or " << destReg << "," << x << "," << tempvar << std::endl;
			}
			else {
				std::string tempvar2 = randomVarGenerator(functionmap);
				Compile(tempvar2, functionmap, ast->getbranch(0));
				std::cout << "or " << destReg << " " << tempvar << " " << tempvar2 << std::endl;
			}
		}
	}
	else if (ast->returntype() == "LogicalAnd") {
		std::string label = makeLabel();
		std::string label2 = makeLabel();
		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				//std::string x = functionmap.find(ast->getbranch(0)->name())->second.first;
				//std::string temporaryReg = randomVarGenerator(functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "beq " << "$0" << "," << temporaryReg2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "beq " << "$0" << "," << x << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "beq " << "$0" << "," << temporaryReg2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "beq " << "$0" << "," << tempvar << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "beq " << "$0" << "," << temporaryReg2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "beq " << "$0" << "," << x << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "beq " << "$0" << "," << x << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "beq " << "$0" << "," << x2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "beq " << "$0" << "," << tempvar << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "beq " << "$0" << "," << x << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}

		}
		else {
			//Compile(destReg,functionmap, ast->getbranch(0));
			std::string tempvar = randomVarGenerator(functionmap);
			Compile(tempvar, functionmap, ast->getbranch(1));
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "beq " << "$0" << "," << temporaryReg2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "beq " << "$0" << "," << tempvar << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "and " << destReg << "," << x << "," << tempvar << std::endl;
			}
			else {
				std::string tempvar2 = randomVarGenerator(functionmap);
				Compile(tempvar2, functionmap, ast->getbranch(0));
				std::cout << "beq " << "$0" << "," << tempvar2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "beq " << "$0" << "," << tempvar << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
	}
	else if (ast->returntype() == "LogicalOr") {
		std::string label = makeLabel();
		std::string label2 = makeLabel();
		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				//std::string x = functionmap.find(ast->getbranch(0)->name())->second.first;
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "bne " << "$0" << "," << temporaryReg2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "bne " << "$0" << "," << x << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(1)->evaluate() << std::endl;
				std::cout << "bne " << "$0" << "," << temporaryReg2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "bne " << "$0" << "," << tempvar << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "bne " << "$0" << "," << temporaryReg2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "bne " << "$0" << "," << x << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << label2 << ":" << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "bne " << "$0" << "," << x2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "bne " << "$0" << "," << x << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "bne " << "$0" << "," << tempvar << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "bne " << "$0" << "," << x << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}

		}
		else {
			//Compile(destReg,functionmap, ast->getbranch(0));
			std::string tempvar = randomVarGenerator(functionmap);
			Compile(tempvar, functionmap, ast->getbranch(1));
			if (ast->getbranch(0)->returntype() == "Number") {
				std::string temporaryReg2 = randomVarGenerator(functionmap);
				std::cout << "li " << temporaryReg2 << "," << ast->getbranch(0)->evaluate() << std::endl;
				std::cout << "bne " << "$0" << "," << temporaryReg2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "bne " << "$0" << "," << tempvar << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << label2 << ":" << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "bne " << "$0" << "," << x << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "bne " << "$0" << "," << tempvar << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
			else {
				std::string tempvar2 = randomVarGenerator(functionmap);
				Compile(tempvar2, functionmap, ast->getbranch(0));
				std::cout << "bne " << "$0" << "," << tempvar2 << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "bne " << "$0" << "," << tempvar << "," << label << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << "li " << destReg << ",0" << std::endl;
				std::cout << "j " << label2 << std::endl;
				std::cout << "nop" << std::endl;
				std::cout << label << ":" << std::endl;
				std::cout << "li " << destReg << ",1" << std::endl;
				std::cout << label2 << ":" << std::endl;
			}
		}
	}
	else if (ast->returntype() == "XorOp") {
		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				//std::string x = functionmap.find(ast->getbranch(0)->name())->second.first;
				std::cout << "xori " << destReg << "," << x << "," << ast->evaluate() << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::cout << "xori " << destReg << "," << tempvar << "," << ast->getbranch(1)->evaluate() << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "xori " << destReg << "," << x << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "xor " << destReg << "," << x << "," << x2 << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "xor " << destReg << " " << tempvar << "," << x << std::endl;
			}

		}
		else {
			//Compile(destReg,functionmap, ast->getbranch(0));
			std::string tempvar = randomVarGenerator(functionmap);
			Compile(tempvar, functionmap, ast->getbranch(1));
			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "xori " << destReg << "," << tempvar << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "xor " << destReg << "," << x << "," << tempvar << std::endl;
			}
			else {
				std::string tempvar2 = randomVarGenerator(functionmap);
				Compile(tempvar2, functionmap, ast->getbranch(0));
				std::cout << "xor " << destReg << " " << tempvar << " " << tempvar2 << std::endl;
			}
		}
	}
	else if (ast->returntype() == "LeftShiftOp") {
		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				//std::string x = functionmap.find(ast->getbranch(0)->name())->second.first;
				std::cout << "sll " << destReg << "," << x << "," << ast->getbranch(1)->evaluate() << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::cout << "sll " << destReg << "," << tempvar << "," << ast->getbranch(1)->evaluate() << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "sll " << destReg << "," << x << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "sllv " << destReg << "," << x << "," << x2 << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "sllv " << destReg << " " << tempvar << "," << x << std::endl;
			}

		}
		else {
			//Compile(destReg,functionmap, ast->getbranch(0));
			std::string tempvar = randomVarGenerator(functionmap);
			Compile(tempvar, functionmap, ast->getbranch(1));
			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "sll " << destReg << "," << tempvar << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "sllv " << destReg << "," << x << "," << tempvar << std::endl;
			}
			else {
				std::string tempvar2 = randomVarGenerator(functionmap);
				Compile(tempvar2, functionmap, ast->getbranch(0));
				std::cout << "sllv " << destReg << " " << tempvar << " " << tempvar2 << std::endl;
			}
		}
	}
	else if (ast->returntype() == "RightShiftOp") {
		if (ast->getbranch(1)->returntype() == "Number") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "li " << destReg << "," << ast->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				//std::string x = functionmap.find(ast->getbranch(0)->name())->second.first;
				std::cout << "sra " << destReg << "," << x << "," << ast->getbranch(1)->evaluate() << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::cout << "sra " << destReg << "," << tempvar << "," << ast->getbranch(1)->evaluate() << std::endl;
			}
		}
		else if (ast->getbranch(1)->returntype() == "VariableName") {

			if (ast->getbranch(0)->returntype() == "Number") {
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "sra " << destReg << "," << x << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::string x2 = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "srav " << destReg << "," << x << "," << x2 << std::endl;
			}
			else {
				std::string tempvar = randomVarGenerator(functionmap);
				Compile(tempvar, functionmap, ast->getbranch(0));
				std::string x = loadfromram(ast->getbranch(1)->name(), functionmap);
				std::cout << "srav " << destReg << " " << tempvar << "," << x << std::endl;
			}

		}
		else {
			//Compile(destReg,functionmap, ast->getbranch(0));
			std::string tempvar = randomVarGenerator(functionmap);
			Compile(tempvar, functionmap, ast->getbranch(1));
			if (ast->getbranch(0)->returntype() == "Number") {
				std::cout << "sra " << destReg << "," << tempvar << "," << ast->getbranch(0)->evaluate() << std::endl;
				//std::cout << "sw " << x << " " << ( stackcounter ) * 4 << "($fp)" << std::endl;
				//stackcounter++;
				//std::cout << "sw " 
			}
			else if (ast->getbranch(0)->returntype() == "VariableName") {
				std::string x = loadfromram(ast->getbranch(0)->name(), functionmap);
				std::cout << "srav " << destReg << "," << x << "," << tempvar << std::endl;
			}
			else {
				std::string tempvar2 = randomVarGenerator(functionmap);
				Compile(tempvar2, functionmap, ast->getbranch(0));
				std::cout << "srav " << destReg << " " << tempvar << " " << tempvar2 << std::endl;
			}
		}
	}

	//else 


	else {
		std::cout << "it doesnt work but atleast it goes here!" << std::endl;
		std::cout << ast->evaluate() << " this is the error " << ast->returntype() << std::endl;

	}



}



void Compiler(NodePtr ast) {
	Compile(destReg, mymap, ast);
}
//comment  
int main()
{
	Node* ast = parseAST();
	Compiler(ast);

}
