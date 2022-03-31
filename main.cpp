// Program: Ass3.
// Author:  Felopater maher
// Version: 1.1

#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include "bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];

void load();
void filter1();
void filter2();
void filter3();
void filter4();
void filter5();
void filter6();
void save();

int main() {


    cout << " Ahlan ya user ya habibi \n"<<endl;
    load();
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
            "0- Exit" ;
    char iChoice;
    cin.ignore();
    cin >> iChoice;
    if (iChoice == '1') {
            filter1();
    } else if (iChoice == '2') {
        filter2();
    } else if (iChoice == '3') {
    } else if (iChoice == '4') {
        filter4();

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
    }

    save();
    return 0;
}

void load()
{
    char imageFileName [100];
    cout<<"Enter the source image file name: ";
    cin>> imageFileName ;
    //Add to it .bmb extension and load image.
    strcat(imageFileName,".bmp");
    readGSBMP(imageFileName,image);
}

void save(){
    char imageFileName [100];
    cout<<"Enter the file image file name to save: ";
    cin>> imageFileName ;
    //Add to it .bmb extension and load image.
    strcat (imageFileName,".bmp");
    writeGSBMP(imageFileName,image);

}

void filter1()
{
    for (int i = 0; i < SIZE; i++)
    {
    for (int j = 0; j< SIZE; j++)
    {

        if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;
    }
    }
}
void filter4()
{
    start:
    cout << "Flip (h)orizontally or (v)ertically ?" << endl;
    char ICHOICE;
    cin>> ICHOICE;
    if(ICHOICE=='h')
    {
    for (int i = 0; i < (SIZE/ 2); i++)
        {
          for (int j = 0; j < (SIZE); j++)
          {
        int temp = image[i][j];
        image[i][j] = image[SIZE- 1 - i][j];
        image[SIZE - 1 -i][j] = temp;
          }
        }
    }
    else if(ICHOICE=='v')//erorrrrrrrrrrrrrrrrrrrrrrrrrrrrr
    {
       for(int i = 0;i<SIZE;i++)
       {
          for(int j=0;j<SIZE;j++)
          {
            image[i][j] = image[j][i];
          }
       }
    }

    else {
    cout<<"please enter correct value "<<endl;
    goto start;
    }


}
void filter2()
{
for (int i = 0; i < SIZE; i++)
    for (int j = 0; j< SIZE; j++)
       image[i][j] = 255 - image[i][j];}
