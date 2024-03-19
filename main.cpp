#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype> // for isdigit
using namespace std;

//prototypes
int num_quiz_taken();
int quiz_scores();
double total_avg(string next);

int main() {
    srand(time(0));
    ifstream in_stream; // read info in file
    ofstream out_stream; // put info in file
    out_stream.open("read.txt");
    //check file stream error
    if (out_stream.fail()) {
        cerr << "Error: Failed to open file." << endl;
        return 1; // Return 1 if failure
    }
    string first_Name;//comment from beginning
    string last_Name;
    for (int i = 0; i < 10; i++) {//searching from 0-10
        cout << "First Name: " << endl;
        cin >> first_Name;
        cout << "Last Name: " << endl;
        cin >> last_Name;
        out_stream << first_Name << ", " << last_Name << " ";
        int num_quizzes = num_quiz_taken();
        for (int j = 0; j < num_quizzes; j++) {
            int next_quiz = quiz_scores();
            out_stream << next_quiz << " ";
        }
        out_stream << endl;
    }
    out_stream.close(); //comment

    in_stream.open("read.txt");
    //check in_stream error
    if(in_stream.fail()){
        cerr << "Error: failed to open" << endl;
        return 1;
    }

    out_stream.open("getout.txt");
    if(out_stream.fail()){
        cerr << "Error: failed to open" << endl;
        return 1;
    }
    out_stream << "******* This file displays the student grades along with the average score for each student *******" << endl;
    string next;
    while (getline(in_stream, next)) {
        double average = total_avg(next);
        out_stream << next << ": " << average << endl;
    }

    return 0;
}
//definitions

int num_quiz_taken(){
    //N: number of quizzes students takes. max 10 quizzes
    int N = (rand() % 11); //0-10
    return N;
};
int quiz_scores(){
    //n: quiz scores from 1-20
    int n = (rand() % 20)+ 1; //1-20
    return n;
};
double total_avg(string next){
    int sum = 0;
    int count = 0;

    stringstream ss(next); // Create a stringstream from the string
    int number;
    while (ss >> number) { // Read integers from stringstream
        sum += number;
        count++;
    }

    double average = 0.0;
    if (count > 0) {
        average = static_cast<double>(sum) / count;
    }

    return average;
}