#include "registeredUser.h"
#include "theater.h"
#include "movie.h"
#include "userRating.h"
#include "userComment.h"
#include "userData.h"

int main()
{
	// create a new theatre object
	theater uweTheatre("UWE Frenchay");

	// register a user with the theatre and add some user details
	registeredUser user1 = uweTheatre.registerUser("user1@here.com", "password");
	user1.addUserData("user1", "bristol", "1234");

	// add a favourite movie for the user1
	movie fightClub = user1.addMovie("Fight Club", 1999, "An insomniac office worker crosses paths with a devil-may-care soap maker forming an underground fight club", "Drama");

	// add a comment about and a rating for the Fight Club movie
	userComment comment1 = fightClub.addComment("What a cool film with an suprising twist!");
	fightClub.addMovieRating(5);

	// increment the number of times the comment has been read and give it a thumbs up
	comment1.incrementReads();
	comment1.incrementThumbsUp();

	return 0;
}