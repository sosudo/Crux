#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <editline/readline.h>
#include <editline/history.h>
#include <editline.h>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <iterator>
#define println(x) cout << x << "\n"
#define print(x) cout << x
#define input(x) cin >> x
using namespace std;
struct set {
	int cardinality;
	vector<int> values;
};
map<string, set> sets;
int main() {
	println("Crux Shell");
	println("Ctrl-C to exit");
	char* in;
	char* printCommand = "print";
	char* sumCommand = "sum";
	char* subCommand = "sub";
	char* multCommand = "mult";
	char* setCommand = "set";
	char* unionCommand = "union";
	char* intersectionCommand = "intersection";
	char* disjointCommand = "disjoint";
	while(true) {
		in = readline(">>> ");
		add_history(in);
		println(in);
		if(strcmp(in, setCommand) == 0) {
			char* name = readline("Set Name: ");
			add_history(name);
			char* cardinality = readline("Cardinality: ");
			add_history(cardinality);
			set tmp;
			tmp.cardinality = atoi(cardinality);
			char* adder;
			for(int i = 1; i < tmp.cardinality+1; i++) {
				adder = readline("Value to Append: ");
				add_history(adder);
				tmp.values.push_back(atoi(adder));
			}
			sets.insert(make_pair(name, tmp));
			free(name);
			free(cardinality);
			if(atoi(cardinality) > 0) {
				free(adder);
			}
		}
		if(strcmp(in, printCommand) == 0) {
			char* a = readline("Set Name: ");
			add_history(a);
			for(int i = 0; i < sets.at(a).cardinality; i++) {
				print(sets.at(a).values[i]);
				print(" ");
			}
			println("");
			free(a);
		}
		if(strcmp(in, sumCommand) == 0) {
			char* a = readline("Set Name: ");
			int out = 0;
			for(int i = 0; i < sets.at(a).cardinality; i++) {
				out += sets.at(a).values[i];
			}
			println(out);
			add_history(a);
			free(a);
		}
		if(strcmp(in, subCommand) == 0) {
			char* a = readline("Set 1 Name: ");
			char* b = readline("Set 2 Name: ");
			set c;
			set_difference(sets.at(a).values.begin(), sets.at(a).values.end(), sets.at(b).values.begin(), sets.at(b).values.end(), inserter(c.values, c.values.begin()));
			for(int i = 0; i < c.values.size(); i++) {
				print(c.values[i]);
				print(" ");
			}
			println("");
			add_history(a);
			add_history(b);
			free(a);
			free(b);
		}
		/*if(strcmp(in, multCommand) == 0) {
			char* a = readline("Set 1 Name: ");
			char* b = readline("Set 2 Name: ");
			
		}*/
		/*
		if(strcmp(in, disjointCommand) == 0) {
			char* a = readline("Set 1 Name: ");
			char* b = readline("Set 2 Name: ");
			bool out = true;
			for(int i = 0; i < sets.at(a).cardinality; i++) {
				for(int j = 0; j < sets.at(b).cardinality; j++) {
					if(sets.at(a).values[i] == sets.at(b).values[j]) {
						out = false;
					}
				}
			}
			println(out);
			add_history(a);
			add_history(b);
			free(a);
			free(b);
		}*/
		if(strcmp(in, disjointCommand) == 0) {
    			char* a = readline("Set 1 Name: ");
    			char* b = readline("Set 2 Name: ");
    			set intersection;
    			set_intersection(sets.at(a).values.begin(), sets.at(a).values.end(), sets.at(b).values.begin(), sets.at(b).values.end(), back_inserter(intersection.values));
    			bool out = intersection.values.empty();
    			println(out);
    			add_history(a);
    			add_history(b);
    			free(a);
    			free(b);
		}
		if(strcmp(in, unionCommand) == 0) {
			char* a = readline("Set 1 Name: ");
			char* b = readline("Set 2 Name: ");
			for(int i = 0; i < sets.at(a).cardinality; i++) {
				print(sets.at(a).values[i]);
				print(" ");
			}
			for(int i = 0; i < sets.at(b).cardinality; i++) {
				print(sets.at(b).values[i]);
				print(" ");
			}
			println("");
			add_history(a);
			add_history(b);
			free(a);
			free(b);
		}
		if(strcmp(in, intersectionCommand) == 0) {
			char* a = readline("Set 1 Name: ");
			char* b = readline("Set 2 Name: ");
			set c;
			set_intersection(sets.at(a).values.begin(), sets.at(a).values.end(), sets.at(b).values.begin(), sets.at(b).values.end(), back_inserter(c.values));
			for(int i = 0; i < c.values.size(); i++) {
				print(c.values[i]);
				print(" ");
			}
			println("");
			add_history(a);
			add_history(b);
			free(a);
			free(b);
		}
		free(in);

	}
	return 0;
}