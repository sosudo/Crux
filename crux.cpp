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
	char* delCommand = "del";
	char* sortCommand = "sort";
	char* subsetCommand = "subset";
	char* minCommand = "min";
	char* maxCommand = "max";
	char* containsCommand = "contains";
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
		if(strcmp(in, delCommand) == 0) {
			char* name = readline("Set Name: ");
			sets.erase(name);
			add_history(name);
			free(name);
		}
		if(strcmp(in, sortCommand) == 0) {
			char* a = readline("Set Name: ");
			set c = sets.at(a);
			sort(c.values.begin(), c.values.end());
			for(int i = 0; i < c.values.size(); i++) {
				print(c.values[i]);
				print(" ");
			}
			println("");
			add_history(a);
			free(a);
		}
		if(strcmp(in, subsetCommand) == 0) {
			char* a = readline("Set Name: ");
			char* b = readline("Subset Name: ");
			println(includes(sets.at(a).values.begin(), sets.at(a).values.end(), sets.at(b).values.begin(), sets.at(b).values.end()));
			add_history(a);
			add_history(b);
			free(a);
			free(b);
		}
		if(strcmp(in, minCommand) == 0) {
			char* a = readline("Set Name: ");
			println(*min_element(sets.at(a).values.begin(), sets.at(a).values.end()));
			add_history(a);
			free(a);
		}
		if(strcmp(in, maxCommand) == 0) {
			char* a = readline("Set Name: ");
			println(*max_element(sets.at(a).values.begin(), sets.at(a).values.end()));
			add_history(a);
			free(a);
		}
		free(in);

	}
	return 0;
}