//
//  main.cpp
//  concept2
//
//  Created by Ankush Bharadwaj on 2/9/19.
//  Copyright © 2019 Ankush Bharadwaj. All rights reserved.
//
#include <cassert>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

//character 9 - character 0 => integer value => put it in an integer

bool isValidRowerString(string rowerString);
// purpose: returns true if parameter is well-formed rower string or false otherwise

bool isValidRowerString(string rowerString) {
    //next part deletes any spaces in the beginning and end of rowerString
    size_t intIndex = rowerString.find_first_not_of(' ');
    size_t intIndex2 = rowerString.find_last_not_of(' ');
    size_t diff = intIndex2 - intIndex + 1;
    rowerString = rowerString.substr(intIndex,diff);
    
    //now we start cycling through the rowerString
    bool s_m = false;
    bool ifM = false;
    bool colon = false;
    size_t indexOfColon(0);
    size_t indexOfStrokes(0);
    size_t indexOfDistance(0);
    int notExpectedChar = 0;
    
    if (rowerString.size() == 0) {
        return false;
    }
    if ((rowerString[0] != ':') && (rowerString[1] != ':') && (rowerString[2] != ':')) {
        return false;
    }
    for (size_t i = 0; i < rowerString.size(); i++) {
        if ((!isdigit(rowerString[i])) && (rowerString[i] != ' ')) {
            notExpectedChar++;
        }
        if (isdigit(rowerString[i])) {
        }
        else if ( (rowerString[i] == ':') && (isdigit(rowerString[i+1])) && (rowerString[i+3] == ' ') ) {
            indexOfColon = i;
            colon = true;
        }
        else if (rowerString[i] == ' ') {
        }
        else if ( (rowerString[i] == 's') && (rowerString[i+1] == '/') && (rowerString[i+2] == 'm') && (rowerString[i-1] == ' ') && (rowerString[i+3] == ' ') && (isdigit(rowerString[i-2]))){
            s_m = true;
            indexOfStrokes = i;
        }
        else if ((rowerString[i] == 'm') && (rowerString[i-1] == ' ') && (rowerString[i+1] == ' ') && (isdigit(rowerString[i-2]))) {
            ifM = true;
            indexOfDistance = i;
        }
    }
    
    int minutes(1), seconds(0), strokes(0), distance(0), bpm(0);
    //minutes
    if ((isdigit(rowerString[0])) && ((rowerString[1] == ':') || (rowerString[2] == ':'))) {
        minutes = 0;
        if (rowerString[1] == ':')
            minutes += (rowerString[0]) - '0';
        else if (rowerString[2] == ':') {
            minutes += (rowerString[0] - '0')*10;
            minutes += (rowerString[1] - '0');
        }
    }
    if (isdigit(rowerString[0]) && isdigit(rowerString[1])) {
        if (rowerString[0] == '0')
            return false;
    }
    
    //seconds
    if (!isdigit(rowerString[indexOfColon+1]))
        return false;
    if (rowerString[indexOfColon+3] != ' ' )
        return false;
    else
        seconds = seconds + ((rowerString[indexOfColon+1] - '0') * 10) + ((rowerString[indexOfColon+2] - '0'));
    
    //strokes
    if ( ((rowerString[indexOfStrokes-5]) != ' ') && (isdigit(rowerString[indexOfStrokes-4])) )
        return false;
    if ( (isdigit(rowerString[indexOfStrokes-2])) && (rowerString[indexOfStrokes-3] == '0') && (!isdigit(rowerString[indexOfStrokes-4])))
        return false;
    if ( (isdigit(rowerString[indexOfStrokes-3])) && (rowerString[indexOfStrokes-4] == '0'))
        return false;
    
    //distance
    int i = 2;
    while (isdigit(rowerString[indexOfDistance-i])) {
        if ((rowerString[indexOfDistance-i] == '0') && (rowerString[indexOfDistance-i-1] == ' '))
            return false;
        
        i++;
    }
    
    //bpm
    if (rowerString[rowerString.size()-4] != ' ')
        return false;
    if ((rowerString[rowerString.size()-1 == '0']) && (!isdigit(rowerString[rowerString.size()-2])))
        return false;
    if ((rowerString[rowerString.size()-3] == '0') && (isdigit(rowerString[rowerString.size()-2])))
        return false;
    if ( (rowerString[rowerString.size()-2] == '0') && (!isdigit(rowerString[rowerString.size()-3])) && (isdigit(rowerString[rowerString.size()-1])))
        return false;
    
    
    //run through conditions
    if ((minutes > 59) || (seconds > 59) || (minutes == 0))
        return false;
    if (!(s_m) || !(ifM) || !(colon) || (notExpectedChar != 5)) {
        return false;
    }
    
    //final output value of function
    return true;
}

int totalDistance(string rowerString);
//if parameter is well-formed rower string, should return total meters rowed so far and if parameter is not a valid rower string, return -1

int totalDistance(string rowerString) {
    int distance = 0;
    if (!isValidRowerString(rowerString))
        return -1;
    else {
        //next part deletes any spaces in the beginning and end of rowerString
        size_t intIndex = rowerString.find_first_not_of(' ');
        size_t intIndex2 = rowerString.find_last_not_of(' ');
        size_t diff = intIndex2 - intIndex + 1;
        rowerString = rowerString.substr(intIndex,diff);
        
        //cycle through string
        size_t indexOfDistance;
        for (size_t i = 0; i < rowerString.size(); i++) {
            if ((rowerString[i] == 'm') && (rowerString[i-1] == ' ') && (rowerString[i+1] == ' ') && (isdigit(rowerString[i-2]))) {
                indexOfDistance = i;
            }
        }
        
        int i = 2;
        while (isdigit(rowerString[indexOfDistance-i])) {
            distance += (rowerString[indexOfDistance-i] - '0') * pow(10,(i-2));
            i++;
        }
        
    }
    return distance;
}

int heartRate(string rowerString);
//if parameter is well-formed rower string, function should return heart rate in beats per minute and if parameter is not valid rower string, return -1

int heartRate(string rowerString) {
    int bpm = 0;
    if (!isValidRowerString(rowerString))
        return -1;
    else {
        //next part deletes any spaces in the beginning and end of rowerString
        size_t intIndex = rowerString.find_first_not_of(' ');
        size_t intIndex2 = rowerString.find_last_not_of(' ');
        size_t diff = intIndex2 - intIndex + 1;
        rowerString = rowerString.substr(intIndex,diff);
        
        if (isdigit(rowerString[rowerString.size()-1]))
            bpm += (rowerString[rowerString.size()-1]) - '0';
        if (isdigit(rowerString[rowerString.size()-2]))
            bpm += ((rowerString[rowerString.size()-2]) - '0')*10;
        if (isdigit(rowerString[rowerString.size()-3]))
            bpm += ((rowerString[rowerString.size()-3]) - '0')*100;
    }
    return bpm;
}

int strokesPerMinute(string rowerString);
//if parameter is well-formed rower string, function should return stroke rate in strokes per minute and if parameter is not valid rower string, return -1

int strokesPerMinute(string rowerString) {
    int strokes = 0;
    if (!isValidRowerString(rowerString))
        return -1;
    else {
        //next part deletes any spaces in the beginning and end of rowerString
        size_t intIndex = rowerString.find_first_not_of(' ');
        size_t intIndex2 = rowerString.find_last_not_of(' ');
        size_t diff = intIndex2 - intIndex + 1;
        rowerString = rowerString.substr(intIndex,diff);
        size_t indexOfStrokes;
        
        //loop loop baby
        for (size_t i = 0; i < rowerString.size(); i++) {
            if ( (rowerString[i] == 's') && (rowerString[i+1] == '/') && (rowerString[i+2] == 'm') && (rowerString[i-1] == ' ') && (rowerString[i+3] == ' ') && (isdigit(rowerString[i-2]))){
                indexOfStrokes = i;
            }
        }
        
        if (isdigit(rowerString[indexOfStrokes-4]) && (isdigit(rowerString[indexOfStrokes-3])) && (isdigit(rowerString[indexOfStrokes-2]))) {
            strokes = strokes + ((rowerString[indexOfStrokes-4] - '0') *100) + ((rowerString[indexOfStrokes-3] - '0') *10) + ((rowerString[indexOfStrokes-2] - '0'));
        }
        else if (isdigit(rowerString[indexOfStrokes-3]) && (isdigit(rowerString[indexOfStrokes-2])))
            strokes = strokes + ((rowerString[indexOfStrokes-3] - '0')*10) + ((rowerString[indexOfStrokes-2] - '0'));
        else if (isdigit(rowerString[indexOfStrokes-2]))
            strokes += (rowerString[indexOfStrokes-4] - '0');
    }
    
    return strokes;
}

int elapsedMinutes(string rowerString);
//if parameter is well-formed rower string, function should return elapsed number of minutes rowing and if parameter is not a valid rower string, return -1

int elapsedMinutes(string rowerString) {
    int minutes = 0;
    
    if (!isValidRowerString(rowerString))
        return -1;
    else {
        //next part deletes any spaces in the beginning and end of rowerString
        size_t intIndex = rowerString.find_first_not_of(' ');
        size_t intIndex2 = rowerString.find_last_not_of(' ');
        size_t diff = intIndex2 - intIndex + 1;
        rowerString = rowerString.substr(intIndex,diff);
        
        
        if ((isdigit(rowerString[0])) && ((rowerString[1] == ':') || (rowerString[2] == ':'))) {
            minutes = 0;
            if (rowerString[1] == ':')
                minutes += (rowerString[0]) - '0';
            else if (rowerString[2] == ':') {
                minutes += (rowerString[0] - '0')*10;
                minutes += (rowerString[1] - '0');
            }
        }
    }
    return minutes;
}

int elapsedSeconds(string rowerString);
//if parameter is well-formed rower string, should return elapsed number of seconds rowing and if parameter is not valid rower string, return -1

int elapsedSeconds(string rowerString) {
    int seconds = 0;
    
    if (!isValidRowerString(rowerString))
        return -1;
    else {
        //next part deletes any spaces in the beginning and end of rowerString
        size_t intIndex = rowerString.find_first_not_of(' ');
        size_t intIndex2 = rowerString.find_last_not_of(' ');
        size_t diff = intIndex2 - intIndex + 1;
        rowerString = rowerString.substr(intIndex,diff);
        size_t indexOfColon;
        
        //cycle through string
        for (size_t i = 0; i < rowerString.size(); i++) {
            if ( (rowerString[i] == ':') && (isdigit(rowerString[i+1])) && (rowerString[i+3] == ' ') ) {
                indexOfColon = i;
            }
        }

        seconds = seconds + ((rowerString[indexOfColon+1] - '0') * 10) + ((rowerString[indexOfColon+2] - '0'));
    }
    return seconds;
}


int main() {
    string rowerString;
    cout << "Enter rower string: ";
    getline(cin, rowerString);
    cout << "elapsed minutes: " << elapsedMinutes(rowerString) << endl;
    cout << "elapsed seconds: " << elapsedSeconds(rowerString) << endl;
    cout << "strokes per minute: " << strokesPerMinute(rowerString) << endl;
    cout << "total distance: " << totalDistance(rowerString) << endl;
    cout << "heart rate: " << heartRate(rowerString) << endl;
    assert(isValidRowerString(rowerString));
    return 0;
}


