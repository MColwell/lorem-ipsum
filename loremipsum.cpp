#include<string>
#include<vector>
#include<iostream>
#include<cstdlib>

std::string firstword () {
	std::string word;
	char letter = (65+(rand()%26));
	word.push_back(letter);
	int size = (rand()%5 + 4);
	for (int count = 0; count < size; count++) {
	  letter = (97+(rand()%26));
	  word.push_back(letter);
	}
	return word;
}

std::string midword () {
	std::string word;
	char letter;
	int size = (rand()%7 + 2);
	for (int count = 0; count < size; count++) {
	  letter = (97+(rand()%26));
	  word.push_back(letter);
	}
	return word;
}

std::string sentence () {
  char temp = 32;
  std::string output;
  std::string word = firstword();
  output = word;
  int count = 0;
  for(int wordcount = 6 + (rand()%9); count < wordcount; count++) {
	  word = midword();
	  output.push_back(temp);
	  output = output + word;
	}
	temp = 46;
	output.push_back(temp);
	temp = 32;
	output.push_back(temp);
	return output;
}

std::string paragraph (int avg, int dev) {
	std::string output;
	int sentnum = avg;
	if (dev > 0) {
		sentnum = sentnum - dev + (rand() % (2*dev));
	}
	for (int count = 0; count < sentnum; count++) {
		output = output + sentence();
	}
	return output;
}

int main () {
	srand (time(NULL));
	std::cout << "Hey.  This program's intended to generate highly customizable pseudo-random output that can replace Lorem Ipsum."  << std::endl;
	std::cout << "Please enter the number of paragraphs you want and hit enter."  << std::endl;
	int paranum;
	std::cin >> paranum;
	if (paranum <= 0) {
		std::cout << "Paragraph count must exceed 0." << std::endl;
		return 1;
	}
	std::cout << "Thanks.  Please enter the average number of sentences you'd like to aim for in each paragraph and hit enter." << std::endl;
	int sentenceavg;
	std::cin >> sentenceavg;
	if (sentenceavg <= 0) {
		std::cout << "Average sentence count must exceed 0." << std::endl;
		return 1;
	}
	std::cout << "Thanks.  Please enter the allowable deviation for the number of sentences in a paragraph. This must be less than the number of sentences - if you want between 3 and 5 sentences in a paragraph, you should've typed 4 previously and you'd want to type 1 now.  For fixed sentence lengths, you can input 0." << std::endl;
	int sentencedev;
	std::cin >> sentencedev;
	std::cout << "Thanks." << std::endl;
	for (int count = 0; count < paranum; count++) {
		std::cout << paragraph(sentenceavg, sentencedev);
		std::cout << "\n	";
	}
	//std::cout << "Thank you for using Lorem++!" << std::endl;
	return 0;
}
