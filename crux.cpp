/*
This sprint sets up a simple Read Eval Print Loop (REPL) for Crux, with a defubed structure for sets and built-in exit, print, and add functions. All other operations depend on these three
operations acting upon a set object, so this acts as a valuable starting point for Crux. 
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <editline/readline.h>
#include <editline/history.h>
#include <editline.h>
#include <vector>
#include <cstring>
#define println(x) cout << x << "\n"
#define print(x) cout << x
#define input(x) cin >> x
using namespace std;
static char input[2048];
struct set {
	int cardinality;
	vector<int> values;
};
int main() {
	println("Crux Shell");
	println("Ctrl-C to exit");
	char* in;
	char* printCommand = "print";
	char* addCommand = "add";
	while(true) {
		print(">>> ");
		in = readline("");
		add_history(in);
		println(in);
		if(strcmp(in, printCommand) == 0) {
			char* a = readline("Print: ");
			add_history(a);
			println(a);
			free(a);
		}
		if(strcmp(in, addCommand) == 0) {
			char* a = readline("Number of Addends: ");
			set Set;
			Set.cardinality = atoi(a);
			for(int i = 1; i < Set.cardinality+1; i++) {
				int z;
				print("Value ");
				print(i);
				print(": ");
				input(z);
				Set.values.push_back(z);
			}
			int out = 0;
			for(int i = 0; i < Set.cardinality; i++) {
				out += Set.values[i];
			}
			println(out);
			add_history(a);
			free(a);
		}
		free(in);
	}
	return 0;
}