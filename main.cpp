// I bet this will be harder than python, bomb defuse time
#include <iostream>
#include <string>
//#include <thread>
//#include <gsl/gsl>
//#include <boost/optional.hpp>
//#include <windows.h>

using std::cout; using std::cin; using std::getline; using std::endl; using std::stoi;

int wirecount(std::string w1, std::string w2, std::string w3, std::string w4, std::string w5, std::string w6, std::string colorcheck) {
	int howmany; howmany = 0;
	if (w1 == colorcheck) {
		howmany++;
	}
	if (w2 == colorcheck) {
		howmany++;
	}
	if (w3 == colorcheck) {
		howmany++;
	}
	if (w4 == colorcheck) {
		howmany++;
	}
	if (w5 == colorcheck) {
		howmany++;
	}
	if (w6 == colorcheck) {
		howmany++;
	}
	return howmany;
}
void wires(int bombodd) {
	std::string w1; std::string w2; std::string w3; std::string w4; std::string w5; std::string w6; std::string colorcheck; std::string Swirenum; int wirenum;
	cout << "How many wires? ";
	getline(cin, Swirenum);
	wirenum = stoi(Swirenum);
	if (wirenum == 3) {
		int bluewires;
		bluewires = wirecount(w1, w2, w3, w4, w5, w6, "blue");
		cout << "Wire 1 color? "; getline(cin, w1); cout << "Wire 2 color? "; getline(cin, w2); cout << "Wire 3 color? "; getline(cin, w3);
		if (w1 != "red" && w2 != "red" && w3 != "red") {
			cout << "Cut the second wire\n";
		}
		else if (w2 == "white") {
			cout << "Cut the last wire\n";
		}
		else if (bluewires>=2)
			cout << "Cut the last blue wire\n";
		else {
			cout << "Cut the last wire\n";
		}
	}
	else if (wirenum == 4) {
		int redwires; int bluewires; int yellowwires;
		cout << "Wire 1 color? "; getline(cin, w1); cout << "Wire 2 color? "; getline(cin, w2); cout << "Wire 3 color? "; getline(cin, w3); cout << "Wire 4 color? "; getline(cin, w4);
		redwires = wirecount(w1, w2, w3, w4, w5, w6, "red"); bluewires = wirecount(w1, w2, w3, w4, w5, w6, "blue"); yellowwires = wirecount(w1, w2, w3, w4, w5, w6, "yellow");
		if (redwires>1) {
			if (bombodd == 2) {
				cout << "Cut the last red wire\n";
				return;
			}
		}
		if (w1 != "red" && w2 != "red" && w3 != "red" && w4 == "yellow") {
			cout << "Cut the first wire\n";
		}
		else if (bluewires==1) {
			cout << "Cut the first wire\n";
		}
		else if (yellowwires>=2) {
			cout << "Cut the last wire\n";
		}
		else {
			cout << "Cut the second wire\n";
		}
	}
	else if (wirenum == 5) {
		int redwires; int yellowwires; int blackwires;
		cout << "Wire 1 color? "; getline(cin, w1); cout << "Wire 2 color? "; getline(cin, w2); cout << "Wire 3 color? "; getline(cin, w3); cout << "Wire 4 color? "; getline(cin, w4); cout << "Wire 5 color? "; getline(cin, w5);
		if (w5 == "black") {
			if (bombodd == 2) {
				cout << "Cut the fourth wire\n";
				return;
			}
		}
		redwires=wirecount(w1, w2, w3, w4, w5, w6, "red"); yellowwires = wirecount(w1, w2, w3, w4, w5, w6, "yellow"); blackwires = wirecount(w1, w2, w3, w4, w5, w6, "black");
		if (redwires == 1 && yellowwires >= 2) {
			cout << "Cut the first wire\n";
		}
		else if (blackwires == 0) {
			cout << "Cut the second wire\n";
		}
		else {
			cout << "Cut the first wire\n";
		}
	}
	else if (wirenum == 6) {
		int yellowwires; int whitewires; int redwires;
		cout << "Wire 1 color? "; getline(cin, w1); cout << "Wire 2 color? "; getline(cin, w2); cout << "Wire 3 color? "; getline(cin, w3); cout << "Wire 4 color? "; getline(cin, w4); cout << "Wire 5 color? "; getline(cin, w5);  cout << "Wire 6 color? "; getline(cin, w6);
		yellowwires = wirecount(w1, w2, w3, w4, w5, w6, "yellow"); whitewires = wirecount(w1, w2, w3, w4, w5, w6, "white"); redwires = wirecount(w1, w2, w3, w4, w5, w6, "red");
		if (yellowwires == 0) {
			if (bombodd == 2) {
				cout << "Cut the third wire\n";
				return;
			}
		}
		if (yellowwires == 1 && whitewires >= 2) {
			cout << "Cut the fourth wire\n";
		}
		else if (redwires == 0) {
			cout << "Cut the last wire\n";
		}
		else {
			cout << "Cut the fourth wire\n";
		}
	}
	else {
		cout << "Impossible\n";
	}
}
void button(int bnum, std::string CAR, std::string FRK) {
	std::string bcolor; std::string btext;
	cout << "What color is the button? ";
	getline(cin, bcolor);
	cout << "What text is on the button? ";
	getline(cin, btext);
	if (bcolor == "blue" && btext == "abort") {
		cout << "Hold the button\n";
		cout << "If blue strip: Release at 4\n";
		cout << "If yellow strip: Release at 5\n";
		cout << "If other strip: Release at 1\n";
	}
	else if (bnum >= 2 && btext == "detonate") {
		cout << "Press and immediately release the button\n";
	}
	else if (bcolor == "white" && CAR == "yes") {
		cout << "Hold the button\n";
		cout << "If blue strip: Release at 4\n";
		cout << "If yellow strip: Release at 5\n";
		cout << "If other strip: Release at 1\n";
	}
	else if (bnum >= 3 && FRK == "yes") {
		cout << "Press and immediately release the button\n";
	}
	else if (bcolor == "yellow") {
		cout << "Hold the button\n";
		cout << "If blue strip: Release at 4\n";
		cout << "If yellow strip: Release at 5\n";
		cout << "If other strip: Release at 1\n";
	}
	else if (bcolor == "red" && btext == "hold") {
		cout << "Press and immediately release the button\n";
	}
	else {
		cout << "Hold the button\n";
		cout << "If blue strip: Release at 4\n";
		cout << "If yellow strip: Release at 5\n";
		cout << "If other strip: Release at 1\n";
	}
}
void keypad() {
	cout << "Please refer to the Bomb Manual.\n";
}
void simon(std::string vowel) {
	std::string Sstrikes; int strikes;
	cout << "How many strikes do you have? ";
	getline(cin, Sstrikes); strikes = stoi(Sstrikes);
	if (vowel == "yes") {
		if (strikes == 0) {
			cout << "Red means Blue, Blue means Red, Green means Yellow, Yellow means Green\n";
		}
		else if (strikes == 1) {
			cout << "Red means Yellow, Blue means Green, Green means Blue, Yellow means Red\n";
		}
		else {
			cout << "Red means Green, Blue means Red, Green means Yellow, Yellow means Blue\n";
		}
	}
	else {
		if (strikes == 0) {
			cout << "Red means Blue, Blue means Yellow, Green means Green, Yellow means Red\n";
		}
		else if (strikes == 1) {
			cout << "Red means Red, Blue means Blue, Green means Yellow, Yellow means Green\n";
		}
		else {
			cout << "Red means Yellow, Blue means Green, Green means Blue, Yellow means Red\n";
		}
	}
}
void whosfirstmanywordscheck(std::string buttonword) {
	if (buttonword == "ready") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("YES, OKAY, WHAT, MIDDLE, LEFT, PRESS, RIGHT, BLANK, READY, NO, FIRST, UHHH, NOTHING, WAIT\n");
	}
	else if (buttonword == "first") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("LEFT, OKAY, YES, MIDDLE, NO, RIGHT, NOTHING, UHHH, WAIT, READY, BLANK, WHAT, PRESS, FIRST\n");
	}
	else if (buttonword == "no") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("BLANK, UHHH, WAIT, FIRST, WHAT, READY, RIGHT, YES, NOTHING, LEFT, PRESS, OKAY, NO, MIDDLE\n");
	}
	else if (buttonword == "blank") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("WAIT, RIGHT, OKAY, MIDDLE, BLANK, PRESS, READY, NOTHING, NO, WHAT, LEFT, UHHH, YES, FIRST\n");
	}
	else if (buttonword == "nothing") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("UHHH, RIGHT, OKAY, MIDDLE, YES, BLANK, NO, PRESS, LEFT, WHAT, WAIT, FIRST, NOTHING, READY\n");
	}
	else if (buttonword == "yes") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("OKAY, RIGHT, UHHH, MIDDLE, FIRST, WHAT, PRESS, READY, NOTHING, YES, LEFT, BLANK, NO, WAIT\n");
	}
	else if (buttonword == "what") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("UHHH, WHAT, LEFT, NOTHING, READY, BLANK, MIDDLE, NO, OKAY, FIRST, WAIT, YES, PRESS, RIGHT\n");
	}
	else if (buttonword == "uhhh") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("READY, NOTHING, LEFT, WHAT, OKAY, YES, RIGHT, NO, PRESS, BLANK, UHHH, MIDDLE, WAIT, FIRST\n");
	}
	else if (buttonword == "left") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("RIGHT, LEFT, FIRST, NO, MIDDLE, YES, BLANK, WHAT, UHHH, WAIT, PRESS, READY, OKAY, NOTHING\n");
	}
	else if (buttonword == "right") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("YES, NOTHING, READY, PRESS, NO, WAIT, WHAT, RIGHT, MIDDLE, LEFT, UHHH, BLANK, OKAY, FIRST\n");
	}
	else if (buttonword == "middle") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("BLANK, READY, OKAY, WHAT, NOTHING, PRESS, NO, WAIT, LEFT, MIDDLE, RIGHT, FIRST, UHHH, YES\n");
	}
	else if (buttonword == "okay") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("MIDDLE, NO, FIRST, YES, UHHH, NOTHING, WAIT, OKAY, LEFT, READY, BLANK, PRESS, WHAT, RIGHT\n");
	}
	else if (buttonword == "wait") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("UHHH, NO, BLANK, OKAY, YES, LEFT, FIRST, PRESS, WHAT, WAIT, NOTHING, READY, RIGHT, MIDDLE\n");
	}
	else if (buttonword == "press") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("RIGHT, MIDDLE, YES, READY, PRESS, OKAY, NOTHING, UHHH, BLANK, LEFT, FIRST, WHAT, NO, WAIT\n");
	}
	else if (buttonword == "you") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("SURE, YOU ARE, YOUR, YOU'RE, NEXT, UH HUH, UR, HOLD, WHAT?, YOU, UH UH, LIKE, DONE, U\n");
	}
	else if (buttonword == "you are") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("YOUR, NEXT, LIKE, UH HUH, WHAT?, DONE, UH UH, HOLD, YOU, U, YOU'RE, SURE, UR, YOU ARE\n");
	}
	else if (buttonword == "your") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("UH UH, YOU ARE, UH HUH, YOUR, NEXT, UR, SURE, U, YOU'RE, YOU, WHAT?, HOLD, LIKE, DONE\n");
	}
	else if (buttonword == "you're") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("YOU, YOU'RE, UR, NEXT, UH UH, YOU ARE, U, YOUR, WHAT?, UH HUH, SURE, DONE, LIKE, HOLD\n");
	}
	else if (buttonword == "ur") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("DONE, U, UR, UH HUH, WHAT?, SURE, YOUR, HOLD, YOU'RE, LIKE, NEXT, UH UH, YOU ARE, YOU\n");
	}
	else if (buttonword == "u") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("UH HUH, SURE, NEXT, WHAT?, YOU'RE, UR, UH UH, DONE, U, YOU, LIKE, HOLD, YOU ARE, YOUR\n");
	}
	else if (buttonword == "uh huh") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("UH HUH, YOUR, YOU ARE, YOU, DONE, HOLD, UH UH, NEXT, SURE, LIKE, YOU'RE, UR, U, WHAT?\n");
	}
	else if (buttonword == "uh uh") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("UR, U, YOU ARE, YOU'RE, NEXT, UH UH, DONE, YOU, UH HUH, LIKE, YOUR, SURE, HOLD, WHAT?\n");
	}
	else if (buttonword == "what?") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("YOU, HOLD, YOU'RE, YOUR, U, DONE, UH UH, LIKE, YOU ARE, UH HUH, UR, NEXT, WHAT?, SURE\n");
	}
	else if (buttonword == "done") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("SURE, UH HUH, NEXT, WHAT?, YOUR, UR, YOU'RE, HOLD, LIKE, YOU, U, YOU ARE, UH UH, DONE\n");
	}
	else if (buttonword == "next") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("WHAT?, UH HUH, UH UH, YOUR, HOLD, SURE, NEXT, LIKE, DONE, YOU ARE, UR, YOU'RE, U, YOU\n");
	}
	else if (buttonword == "hold") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("YOU ARE, U, DONE, UH UH, YOU, UR, SURE, WHAT?, YOU'RE, NEXT, HOLD, UH HUH, YOUR, LIKE\n");
	}
	else if (buttonword == "sure") {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("YOU ARE, DONE, LIKE, YOU'RE, YOU, HOLD, UH HUH, UR, SURE, U, WHAT?, NEXT, YOUR, UH UH\n");
	}
	else {
		cout << ("Push the button with the first word that appears in this list\n");
		cout << ("YOU'RE, NEXT, U, UR, HOLD, DONE, UH UH, WHAT?, UH HUH, YOU, LIKE, SURE, YOU ARE, YOUR\n");
	}
}
void whosfirst() {
	std::string topword; std::string buttonword;
	cout << "What is the display word? ";
	getline(cin, topword);
	if (topword == "yes" || topword == "nothing" || topword == "led" || topword == "they are") {
		cout << "What is the mid left word? ";
		getline(cin, buttonword);
		whosfirstmanywordscheck(buttonword);
	}
	else if (topword == "first" || topword == "okay" || topword == "c") {
		cout << "What is the top right word? ";
		getline(cin, buttonword);
		whosfirstmanywordscheck(buttonword);
	}
	else if (topword == "display" || topword == "says" || topword == "no" || topword == "lead" || topword == "hold on" || topword == "you are" || topword == "there" || topword == "see" || topword == "cee") {
		cout << "What is the bottom right word? ";
		getline(cin, buttonword);
		whosfirstmanywordscheck(buttonword);
	}
	else if (topword == "" || topword == "reed" || topword == "leed" || topword == "they're") {
		cout << "What is the bottom left word? ";
		getline(cin, buttonword);
		whosfirstmanywordscheck(buttonword);
	}
	else if (topword == "blank" || topword == "read" || topword == "red" || topword == "you" || topword == "your" || topword == "you're" || topword == "their") {
		cout << "What is the mid right word? ";
		getline(cin, buttonword);
		whosfirstmanywordscheck(buttonword);
	}
	else {
		cout << "What is the top left word? ";
		getline(cin, buttonword);
		whosfirstmanywordscheck(buttonword);
	}
}
void memory() {
	int step1num; int step2num; int step3num; int step4num; int step1pos; int step2pos; int step3pos; int step4pos; int displaynum;
	std::string Sstep1num; std::string Sstep2num; std::string Sstep3num; std::string Sstep4num; std::string Sstep2pos; std::string Sstep3pos; std::string Sdisplaynum;
	// Stage 1
	cout << "What is the number on the display? ";
	getline(cin, Sdisplaynum);
	displaynum = stoi(Sdisplaynum);
	if (displaynum == 1 || displaynum == 2) {
		cout << "What is the label of the button in the 2 position? ";
		getline(cin, Sstep1num);
		step1num = stoi(Sstep1num);
		step1pos = 2;
		cout << "Press the button in the 2 position\n";
	}
	else if (displaynum == 3) {
		cout << "What is the label of the button in the 3 position? ";
		getline(cin, Sstep1num);
		step1num = stoi(Sstep1num);
		step1pos = 3;
		cout << "Press the button in the 3 position\n";
	}
	else {
		cout << "What is the label of the button in the 4 position? ";
		getline(cin, Sstep1num);
		step1num = stoi(Sstep1num);
		step1pos = 4;
		cout << "Press the button in the 4 position\n";
	}
	//Stage 2
	cout << "What is the number on the display? ";
	getline(cin, Sdisplaynum);
	displaynum = stoi(Sdisplaynum);
	if (displaynum == 1) {
		cout << "What button position is labeled 4? ";
		getline(cin, Sstep2pos);
		step2pos = stoi(Sstep2pos);
		step2num = 4;
		cout << "Press the button labeled 4\n";
	}
	else if (displaynum == 2 || displaynum==4) {
		cout << "What is the label of the button in the "; cout << step1pos; cout << " position? ";
		getline(cin, Sstep2num);
		step2num = stoi(Sstep2num);
		step2pos = step1pos;
		cout << "Press the button in the "; cout << step1pos; cout << " position\n";
	}
	else {
		cout << "What is the label of the button in the 1 position? ";
		getline(cin, Sstep2num);
		step2num = stoi(Sstep2num);
		step2pos = 1;
		cout << "Press the button in the 1 position\n";
	}
	//Stage 3
	cout << "What is the number on the display? ";
	getline(cin, Sdisplaynum);
	displaynum = stoi(Sdisplaynum);
	if (displaynum == 1) {
		cout << "What button position is labeled "; cout << step2num; cout << "? ";
		getline(cin, Sstep3pos);
		step3pos = stoi(Sstep3pos);
		step3num = step2num;
		cout << "Press the button labeled "; cout << step2num; cout << "\n";
	}
	else if (displaynum == 2) {
		cout << "What button position is labeled "; cout << step1num; cout << "? ";
		getline(cin, Sstep3pos);
		step3pos = stoi(Sstep3pos);
		step3num = step1num;
		cout << "Press the button labeled "; cout << step1num; cout << "\n";
	}
	else if (displaynum == 3) {
		cout << "What is the label of the button in the 3 position? ";
		getline(cin, Sstep3num);
		step3num = stoi(Sstep3num);
		step3pos = 3;
		cout << "Press the button in the 3 position\n";
	}
	else {
		cout << "What button position is labeled 4? ";
		getline(cin, Sstep3pos);
		step3pos = stoi(Sstep3pos);
		step3num = 4;
		cout << "Press the button labeled 4\n";
	}
	//Stage 4
	cout << "What is the number on the display? ";
	getline(cin, Sdisplaynum);
	displaynum = stoi(Sdisplaynum);
	if (displaynum == 1) {
		cout << "What is the label of the button in the "; cout << step1pos; cout << " position? ";
		getline(cin, Sstep4num);
		step4num = stoi(Sstep4num);
		step4pos = step1pos;
		cout << "Press the button in the "; cout << step1pos; cout << " position\n";
	}
	else if (displaynum == 2) {
		cout << "What is the label of the button in the 1 position? ";
		getline(cin, Sstep4num);
		step4num = stoi(Sstep4num);
		step4pos = 1;
		cout << "Press the button in the 1 position\n";
	}
	else {
		cout << "What is the label of the button in the "; cout << step2pos; cout << " position? ";
		getline(cin, Sstep4num);
		step4num = stoi(Sstep4num);
		step4pos = step2pos;
		cout << "Press the button in the "; cout << step2pos; cout << " position\n";
	}
	//Stage 5
	cout << "What is the number on the display? ";
	getline(cin, Sdisplaynum);
	displaynum = stoi(Sdisplaynum);
	if (displaynum == 1) {
		cout << "Press the button labeled "; cout << step1num; cout << "\n";
	}
	else if (displaynum == 2) {
		cout << "Press the button labeled "; cout << step2num; cout << "\n";
	}
	else if (displaynum == 3) {
		cout << "Press the button labeled "; cout << step4num; cout << "\n";
	}
	else {
		cout << "Press the button labeled "; cout << step3num; cout << "\n";
	}
}
void morse() {
	std::string morseinput; bool morsedone = false;
	cout << "A short flash represents a ./dot. A long flash represents a -/dash.\n";
	cout << "A long gap will be between letters, and a very long gap will occur before the word repeats.\n";
	while (morsedone == false) {
		cout << "Please input morse: ";
		getline(cin, morseinput);
		if (morseinput == "... .... . .-.. .-..") { //Shell
			cout << "Respond at frequency 3.505MHz\n";
			morsedone = true;
		}
		else if (morseinput == ".... .- .-.. .-.. ...") { //Halls
			cout << "Respond at frequency 3.515MHz\n";
			morsedone = true;
		}
		else if (morseinput == "... .-.. .. -.-. -.-") { //Slick
			cout << "Respond at frequency 3.522MHz\n";
			morsedone = true;
		}
		else if (morseinput == "- .-. .. -.-. -.-") { //Trick
			cout << "Respond at frequency 3.532MHz\n";
			morsedone = true;
		}
		else if (morseinput == "-... --- -..- . ...") { //Boxes
			cout << "Respond at frequency 3.535MHz\n";
			morsedone = true;
		}
		else if (morseinput == ".-.. . .- -.- ...") { //Leaks
			cout << "Respond at frequency 3.542MHz\n";
			morsedone = true;
		}
		else if (morseinput == "... - .-. --- -... .") { //Strobe
			cout << "Respond at frequency 3.545MHz\n";
			morsedone = true;
		}
		else if (morseinput == "-... .. ... - .-. ---") { //Bistro
			cout << "Respond at frequency 3.552MHz\n";
			morsedone = true;
		}
		else if (morseinput == "..-. .-.. .. -.-. -.-") { //Flick
			cout << "Respond at frequency 3.555MHz\n";
			morsedone = true;
		}
		else if (morseinput == "-... --- -- -... ...") { //Bombs
			cout << "Respond at frequency 3.565MHz\n";
			morsedone = true;
		}
		else if (morseinput == "-... .-. . .- -.-") { //Break
			cout << "Respond at frequency 3.572MHz\n";
			morsedone = true;
		}
		else if (morseinput == "-... .-. .. -.-. -.-") { //Brick
			cout << "Respond at frequency 3.575MHz\n";
			morsedone = true;
		}
		else if (morseinput == "... - . .- -.-") { //Steak
			cout << "Respond at frequency 3.582MHz\n";
			morsedone = true;
		}
		else if (morseinput == "... - .. -. --.") { //Sting
			cout << "Respond at frequency 3.592MHz\n";
			morsedone = true;
		}
		else if (morseinput == "...- . -.-. - --- .-.") { //Vector
			cout << "Respond at frequency 3.595MHz\n";
			morsedone = true;
		}
		else if (morseinput == "-... . .- - ...") { //Beats
			cout << "Respond at frequency 3.600MHz\n";
			morsedone = true;
		}
		else { //Error Handler
			cout << "Error in input\n";
		}
	}
}
void bombcheck() {
	//Bomb Check
	int modules; int snum; int bnum; int bombodd;
	std::string Smodules; std::string Ssnum; std::string Sbnum; std::string CAR; std::string FRK; std::string vowel;
	cout << "How many modules? ";
	getline(cin, Smodules);
	modules = stoi(Smodules);
	cout << "How many batteries? ";
	getline(cin, Sbnum);
	bnum = stoi(Sbnum);
	cout << "Last digit of the serial number? ";
	getline(cin, Ssnum);
	snum = stoi(Ssnum);
	if (snum % 2 == 0) { //Check if bomb follows odd S# rules. 0 is unchecked (will implement later). 1 is False. 2 is True.
		bombodd = 1;
	}
	else {
		bombodd = 2;
	}
	cout << "Does the serial number contain a vowel? ";
	getline(cin, vowel);
	cout << "Is there a lit indicator CAR? ";
	getline(cin, CAR);
	cout << "Is there a lit indicator FRK? ";
	getline(cin, FRK);
	int donemod = 0;
	while (modules > donemod) { //Prompt user for module name and loop until all modules defused
		std::string activemod;
		cout << "Module name? ";
		getline(cin, activemod);
		if (activemod == "wires" || activemod == "button" || activemod == "simon" || activemod == "whosfirst" || activemod == "memory" || activemod == "keypad" || activemod == "morse") {
			donemod++;
			if (activemod == "wires") {
				wires(bombodd);
			}
			else if (activemod == "button") {
				button(bnum, CAR, FRK);
			}
			else if (activemod == "simon") {
				simon(vowel);
			}
			else if (activemod == "whosfirst") {
				whosfirst(); //Round 1
				whosfirst(); //Round 2
				whosfirst(); //Round 3
			}
			else if (activemod == "memory") {
				memory();
			}
			else if (activemod == "keypad") {
				keypad();
			}
			else if (activemod == "morse") {
				morse();
			}
		}
		else {
			cout << "Invalid, try again\n";
		}
	}
	cout << "Bomb has been defused\n";
	cout << "Press anything to continue\n";
	getline(cin, Smodules);
	return;
}
//Doesn't Need to be on. Only works with windows.h
/*void counter() {
	int timer;
	timer = 61;
	while (timer != 0) {
		timer--;
		cout << timer; cout << "\n";
		Sleep(5000);
	}
	return;
} */

int main() {
	cout << "Bomb Time!\n";
	//bool played=PlaySound(TEXT("KoC.wav"), NULL, SND_ASYNC);
	bombcheck();
	return 0;
}