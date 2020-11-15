#pragma once
#include <iostream>
#include <string>
using namespace std;

class userComment {
public:
	string comment;
	int reads = 0;
	int thumbsUp = 0;
	void incrementReads() {
		reads++;
	}
	void incrementThumbsUp() {
		thumbsUp++;
	}
};