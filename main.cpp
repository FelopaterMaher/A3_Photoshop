//Assignment 3 v1.1 by Felopater maher
#include<bits/stdc++.h>

using namespace std;

int main() {
    cout << " Ahlan ya user ya habibi \n"
            "Please enter file name of the image to process:\n";
    //cin>>photo;
    Start:
    cout << "Please select a filter to apply or 0 to exit:\n"
            "1- Black & White Filter\n"
            "2- Invert Filter\n"
            "3- Merge Filter \n"
            "4- Flip Image\n"
            "5- Darken and Lighten Image \n"
            "6- Rotate Image\n"
            "7- Detect Image Edges \n"
            "8- Enlarge Image\n"
            "9- Shrink Image\n"
            "a- Mirror 1/2 Image\n"
            "b- Shuffle Image\n"
            "c- Blur Image\n"
            "s- Save the image to a file\n"
            "0- Exit" << endl;
    char iChoice;
    cin >> iChoice;
    if (iChoice == '1') {
    } else if (iChoice == '2') {
    } else if (iChoice == '3') {
    } else if (iChoice == '4') {
        cout << "Flip (h)orizontally or (v)ertically ?" << endl;
    } else if (iChoice == '5') {
        cout << "Do you want to (d)arken or (l)ighten?" << endl;
    } else if (iChoice == '6') {
        cout << "Rotate (90), (180) or (360) degrees?" << endl;
    } else if (iChoice == '7') {
    } else if (iChoice == '8') {
        cout << "Which quarter to enlarge 1, 2, 3 or 4?" << endl;
    } else if (iChoice == '9') {
        cout << "Shrink to (1/2), (1/3) or (1/4)?" << endl;
    } else if (iChoice == 'a') {
        cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?" << endl;
    } else if (iChoice == 'b') {
    } else if (iChoice == 'c') {
    } else if (iChoice == 's') {
        cout << "Please enter target file name:" << endl;
    } else if (iChoice == 0) {
        return 0;
    } else {
        cout << "Please enter a correct choice" << endl;
        goto Start;
    }
    return 0;
}
