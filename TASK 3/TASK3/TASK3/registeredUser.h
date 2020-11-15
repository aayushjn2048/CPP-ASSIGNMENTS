#pragma once
#include <iostream>
#include <string>
#include "movie.h"
#include "userData.h"
using namespace std;

class registeredUser: movie,userData {
public:
	string email;
	string password;
	movie addMovie(string movieName, int movieYear, string movieTitle, string movieGenre) {
		movie newMovie;
		newMovie.title = movieName;
		newMovie.year = movieYear;
		newMovie.desc = movieTitle;
		newMovie.genre = movieGenre;
		return newMovie;
	}
	void addUserData(string username, string useradd, string userCard) {
		name = username;
		address = useradd;
		creditCard = userCard;
	}
};