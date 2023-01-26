// questions to ask:
// cin vs getline() "Yes and No" and checking in conditional
// conditional && and || for number ranges
// variable initialization in if statement (scope?)

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "What movie is to be rated? ";
    string movie_name; // The Matrix
    getline(cin, movie_name);

    cout << "On a scale of 1-10, how much do you like movies with a similar theme? ";
    int theme;
    cin >> theme;  // 1-10
    cin.ignore(10000, '\n');

    cout << "Do you like movies starring the actor or actress that stars in this movie? ";
    string actor;
    getline(cin, actor);  // Yes or No

    cout << "On a scale of 1-10, how much do users with tastes similar to yours like this movie? ";
    int taste;  // 1-10
    cin >> taste;
    cin.ignore(10000, '\n');

    cout << "Have you thumbed up this movie already? ";
    string thumbed_up;
    getline(cin, thumbed_up);  // Yes or No

    cout << "Have you thumbed down this movie already? ";
    string thumbed_down;
    getline(cin, thumbed_down);  // Yes or No



    if (theme < 1 || theme > 10) {
        cout << "Invalid theme value!" << endl;
    }

    else if (actor != "Yes" && actor != "No") {
        cout << "Invalid actor value!" << endl;
    }

    else if (taste < 1 || taste > 10) {
        cout << "Invalid taste value!" << endl;
    }

    else if (thumbed_up != "Yes" && thumbed_up != "No") {
        cout << "Invalid thumbed up value!" << endl;
    }

    else if (thumbed_down != "Yes" && thumbed_down != "No") {
        cout << "Invalid thumbed down value!" << endl;
    }

    else {
        // theme, taste:        score = 0.3 for each point
        // actor, thumbed_up:   score = 0.2 for Yes, 0 for No
        // thumbed_down:        score = -0.2 for Yes, 0 for No

        double theme_score = theme * 0.3;
        
        double taste_score = taste * 0.3;

        double actor_score;

        double thumbed_up_score;

        double thumbed_down_score;

        if (actor == "Yes") {
            actor_score = 2.0;
        }
        if (actor == "No") {
            actor_score = 0.0;
        }

        if (thumbed_up == "Yes") {
            thumbed_up_score = 2.0;
        }
        if (thumbed_up == "No") {
            thumbed_up_score = 0.0;
        }

        if (thumbed_down == "Yes") {
            thumbed_down_score = -2.0;
        }
        if (thumbed_down == "No") {
            thumbed_down_score = 0.0;
        }

        double score = theme_score + taste_score + actor_score + thumbed_up_score + thumbed_down_score;

        cout.setf(ios::showpoint);  // show decimal
        cout.setf(ios::fixed);      // fixed notation (not scientific notation)
        cout.precision(1);          // decimal places
        cout << "Our recommendation for you for the movie: " << movie_name << " is " << score << endl;
    }

    return 0;
}