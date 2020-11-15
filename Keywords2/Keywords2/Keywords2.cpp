/*
	Jonathon Sherwood
	11/14/2020
	Keywords II: iterating through vectors
*/

#include <iostream> //Used to display messages to the console
#include <string> //Allows for unique functions on strings
#include <vector> //Allows for unique functions on vectors
#include <algorithm> //Allows for manipulation in groups of elements
#include <ctime> //Allows the randomiser to use time as the seed
#include <cctype> //Allows for conversion of case in characters

using namespace std; //Uses shortcuts for std names


int main() //Main function for all c++ codes
{
	const int MAX_WRONG = 8; //Sets the max number of wrong guesses
	int correctWords = 0; //Holds the number of correct words per simulation

	vector<string> words; //List of words to be guessed

	// Display Title of the program to the user
	cout << "Welcome to Keywords II\n\n";

	// Ask the recruit to log in using their name
	cout << "Please enter your last name.\n";

	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string playerName;
	cin >> playerName;

	// Display an overview of what Keywords II is to the recruit 
	cout << "\nGood to see you agent " << playerName << ".\n\n";
	cout << "In Keywords II, things are going to be a lot more challenging than your first test.\n";
	cout << "Rather than showing you a scrambled word, we are going to have you guess the word with no hints.\n";
	cout << "Instead, we will simply tell you which letters you get right and if you got it wrong.\n";
	cout << "Ever heard of hangman? Just imagine you're the little guy on the gallows.\n\n";

	// Display directions to the recruit on how to use Keywords
	cout << "All you have to do is type in a letter you think belongs in the word.\n";
	cout << "If you get it right, the letter will be displayed to you.\n";
	cout << "Get it wrong? .. Well.. Just don't get it wrong too many times.\n\n";
	cout << "You will be expected to solve 3 of the words before the simulation is complete.\n";
	cout << "Good luck, Agent " << playerName << ".\n\n\n";

	// Create a collection of 10 words you had written down manually
	words.push_back("BOMB");
	words.push_back("WIRES");
	words.push_back("STEALTH");
	words.push_back("INTEL");
	words.push_back("ATTACK");
	words.push_back("DEFEND");
	words.push_back("BRIEFCASE");
	words.push_back("WEAPONS");
	words.push_back("TARGET");
	words.push_back("CODE");

	// Create an int var to count the number of simulations being run starting at 1
	int simulations = 1;

	bool gameBegin = true; //Allows the code to loop on player response

	do{
	// Display the simulation # is starting to the recruit. 
	cout << "Begin Simulation #" << simulations << ".\n";
	do
	{
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		srand(static_cast<unsigned int>(time(0)));  //Sets the random seed to be based on time
		random_shuffle(words.begin(), words.end()); //Used the algorithm function to randomize the list of words
		string THE_WORD = words[correctWords];      //Assigns the number of attempts word in the scrambled list as our word to guess
		int wrong = 0;                              //Starts the user with 0 incorrect guesses
		string soFar(THE_WORD.size(), '-');         //Holds each correctly gussed letter, replacing the '-'s when gussed
		string used = "";                           //Displays the letters already guessed

		cout << "Loading word #" << correctWords + 1 << "...\n";
		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{
			//     Tell recruit how many incorrect guesses he or she has left
			cout << "You have " << (MAX_WRONG - wrong) << " guesses left.\n";

			//     Show recruit the letters he or she has guessed
			cout << "You've used the following letters: " << used << endl;

			//     Show player how much of the secret word he or she has guessed
			cout << "So far, the word is: " << soFar << endl;

			//     Get recruit's next guess
			char guess;                           //Holds the recruits guess
			cout << "\nPlease enter your guess: ";
			cin >> guess;                         //Takes in the recruits guess
			guess = toupper(guess);               //Converts the guess to capital letters

			//     While recruit has entered a letter that he or she has already guessed
			while (used.find(guess) != string::npos) {
				//          Get recruit ’s guess
				cout << "\nYou've already guessed " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;            //Takes in the player's guess
				guess = toupper(guess);  //Converts the guess to capital letters
			}

			//     Add the new guess to the group of used letters
			used += guess;

			//     If the guess is in the secret word
			if (THE_WORD.find(guess) != string::npos)
			{
				//          Tell the recruit the guess is correct
				cout << "\nGreat work! " << guess << " is one of the letters.\n";

				//          Update the word guessed so far with the new letter
				for (int i = 0; i < THE_WORD.length(); ++i)
				{
					if (THE_WORD[i] == guess) //Uses the current word's guess to fill in sofar's '-'s
					{
						soFar[i] = guess;
					}
				}
			}
			//     Otherwise
			else {
				//          Tell the recruit the guess is incorrect
				cout << "\nIncorrect, " << guess << " is not one of the letters.\n";
				//          Increment the number of incorrect guesses the recruit has made
				wrong++;
			}
		}

		// If the recruit has made too many incorrect guesses
		if (wrong == MAX_WRONG) {
			//     Tell the recruit that he or she has failed the Keywords II course.
			cout << "\nToo many incorrect guesses.";
			cout << "\nSystem Shutdown. You have failed.\n\n\n";
			exit(0); //Exits program
		}
		// Otherwise
		else
		{
			//     Congratulate the recruit on guessing the secret words
			cout << "\nCorrect.";
			correctWords++; //Increases correct guesses by 1
		}
		cout << "\nThe word was " << THE_WORD << "\n\n";
	} while (correctWords < 3);

	// Ask the recruit if they would like to run the simulation again
	cout << "Are you ready for the next simulation? : (Y/N)\n";
	char response;
	cin >> response;
	cout << "\n\n";
	// If the recruit wants to run the simulation again
	if (response == 'Y' || response == 'y')
	{
		//     Increment the number of simulations ran counter
		simulations++;
		//     Move program execution back up to // Display the simulation # is starting to the recruit. 
		correctWords = 0;
		gameBegin = true;
	}
	// Otherwise 
	else if (response == 'n' || response == 'N')
	{
		//     Display End of Simulations to the recruit
		cout << "Very good. Your results will be printed in the other room.\n";
		//     Pause the Simulation with press any key to continue
		system("pause");
		gameBegin = false;
	}
	else //Boots the user on improper response
	{
		cout << "That is not a proper response.\n";
		cout << "Reporting you to your manager and shutting down.\n";
		gameBegin = false;
	}
} while (gameBegin == true); //Loops entire simulation on player request;

	return 0;
}