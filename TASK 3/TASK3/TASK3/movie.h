#pragma once
#include <iostream>
#include <string>
#include "userRating.h"
#include "userComment.h"
using namespace std;

class movie: userRating,userComment {
public:
	string title;
	int year = 2020;
	string desc;
	string genre;
	void addMovieRating(int num) {
		vote = num;
	}
	userComment addComment(string comments)
	{
		userComment comment1;
		comment1.comment = comments;
		return comment1;
	}
};