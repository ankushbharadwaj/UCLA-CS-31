//
//  main.cpp
//  array
//
//  Created by Ankush Bharadwaj on 2/17/19.
//  Copyright © 2019 Ankush Bharadwaj. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool hasDuplicates(const string array[], int size);
//return true if the given size of the array has any strings that are duplicated in the array. returns false if the size is less than or equal to 0

bool hasDuplicates(const string array[], int size) {
    bool result = false;
    if (size <= 0) {
        return result;
    }
    else {
        for (int i = 0; i < size; i++){
            for (int j = i+1; j < size; j++){
                if (array[i] == array[j]) {
                    result = true;
                    break;
                }
            }
        }
    }
    return result;
}

int countAllDigits(const string array[], int size);
//returns the total number of digit characters ('0' to '9') in the array. return -1 if there are no elements because size is less than or equal to zero

int countAllDigits(const string array[], int size) {
    int result = 0;
    if (size <= 0) {
        result = -1;
        return result;
    }
    else {
        for (int i = 0; i < size; i++) {
            for (size_t j = 0; j < array[i].size(); j++){
                if ( isdigit(array[i].at(j)) )
                    result++;
            }
        }
    }
    return result;
}

bool isInDecreasingOrder(const string array[], int size);
//if every value in the array is smaller than the one that precedes it, return true => false otherwise. also, if the size is 0 or 1, then it automatically returns true and if the size is less than zero it will return false

bool isInDecreasingOrder(const string array[], int size) {
    bool result = true;
    if ( (size == 0) || (size == 1) )
        return result;
    if (size < 0) {
        result = false;
        return result;
    }
    else {
        for (int i = 0; i < size-1; i++) {
            if (array[i] <= array[i+1]) {
                result = false;
                return result;
            }
        }
    }
    return result;
}

int shiftRight(string array[], int size, int amount, string placeholder);
//adjust values in array by shifting each value to the right by amount parameter. after doing this, the first amount number of parameters should be empty and the placeholder string should be placed into these parameters. return -1 if size or amount is less than 0

int shiftRight(string array[], int size, int amount, string placeholder) {
    int result = 0;
    string temp;
    if ( (size < 0) || (amount < 0)) {
        result = -1;
        return result;
    }
    else {
        for (int i = 0; i < size - 1; ++i) { //cycle through array FROM THE BACK
            array[size-1-i] = array[size-1-amount-i];
            if (size-1-amount-i== 0) //make sure i dont walk off the array lol
                break;
        }
        for (int i = 0; i < amount; ++i) {
            if (i < size)
                array[i] = placeholder;
        }
    }
    if (amount <= size)
        result = amount;
    if (amount > size)
        result = size;
        
    return result;
}

int find(const string array[], int size, string match);
// return smallest index of the element whose value equals the match string in the array. return -1 if item not found or if size less than 0

int find(const string array[], int size, string match) {
    int result = -1;
    if (size < 0)
        return result;
    else {
        for (int i = 0; i < size; i++) {
            if (array[i] == match) {
                result = i;
                return result;
            }
        }
    }
    return result;
}

int replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter);
//replace every occurrence of the find letter value with the replace letter value. return number of letters replaced or -1 if size less than or equal to zero

int replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter) {
    int result = 0;
    if (size <= 0) {
        result = -1;
        return result;
    }
    else {
        for (int i = 0; i < size; i++) {
            for (size_t j = 0; j < array[i].size(); j++) {
                if (array[i].at(j) == findLetter) {
                    array[i].at(j) = replaceLetter;
                    result++;
                }
            }
        }
    }
    return result;
}



int main()
{
    string folks[8] = {"samwell", "jon", "margaery", "daenerys","tyrion", "sansa", "howard123", "jon"};
    string tester1[8] = {"d", "c", "b", "a", "hel", "hello", "halloween", "thisStringIsGibberish"};
    string tester2[8] = {"thisStringIsGibberish", "hello", "hell", "halloween", "d", "c", "b", "a"};
    string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    string people2[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    string people3[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    string array[5] = {"1","2","3","4","5"};
    
    //asserts for hasDuplicates
    assert(hasDuplicates(folks,5) == false);
    assert(hasDuplicates(folks,8) == true);
    assert(hasDuplicates(folks,0) == false);
    assert(hasDuplicates(folks,-1) == false);
    
    //asserts for countAllDigits
    assert(countAllDigits(folks,8) == 3);
    assert(countAllDigits(folks,-108) == -1);
    assert(countAllDigits(folks,0) == -1);
    
    //asserts for isInDecreasingOrder
    assert(isInDecreasingOrder(tester1,8) == false);
    assert(isInDecreasingOrder(tester2,8) == true);
    assert(isInDecreasingOrder(tester1,4) == true);
    assert(isInDecreasingOrder(tester1,0) == true);
    assert(isInDecreasingOrder(tester2,1) == true);
    assert(isInDecreasingOrder(tester2,-2) == false);
    
    //asserts and checks for shiftRight
    assert(shiftRight(people,5,3,"foo") == 3);
    for (int i = 0; i < 5; i++)
        cout << people[i] << " ";
    cout << endl;
    shiftRight(array, 3, 1, "placeholder");
    for (int i = 0; i < 5; i++)
        cout << array[i] << " ";
    cout << endl;
    assert(shiftRight(people,-5,3,"foo") == -1);
    assert(shiftRight(people,5,-3,"foo") == -1);
    assert(shiftRight(people3,5,25,"foo") == 5);
    for (int i = 0; i < 5; i++)
        cout << people3[i] << " ";
    cout << endl;
    
    //asserts for find
    assert(find(folks, 5, "foo") == -1);
    assert(find(folks, -100, "foo") == -1);
    assert(find(folks, 8, "jon") == 1);
    
    //asserts and checks for replaceAllCharacters
    assert(replaceAllCharacters(people2, 5, 'z', 'a') == 0);
    assert(replaceAllCharacters(people2, -5, 'z', 'a') == -1);
    assert(replaceAllCharacters(people2, 5, 'a', '_') == 4);
    for (int i = 0; i < 5; i++)
        cout << people2[i] << " ";
    cout << endl;
    
    
    cout << "All tests succeeded" << endl;
    return(0);
}
