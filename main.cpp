// Program: Ass3.
// Author:  Felopater maher
// Version: 1.1
//done filter(1,2,4,5).
#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include "bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];

unsigned char image2[SIZE][SIZE];
void load();
void load2();
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
            "1- Black & White Filter\n"//done
            "2- Invert Filter\n"//done
            "3- Merge Filter \n"//done
            "4- Flip Image\n"//done
            "5- Darken and Lighten Image \n"//done
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
        filter3();


    } else if (iChoice == '4') {
        filter4();

    } else if (iChoice == '5') {
        filter5();
    } else if (iChoice == '6') {
        filter6();
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

void load2()
{
    char imageFileName2 [100];
    cout<<"Enter the source image2 file name: ";
    cin>> imageFileName2 ;
    //Add to it .bmb extension and load image.
    strcat(imageFileName2,".bmp");
    readGSBMP(imageFileName2,image2);//??????
}

void save()
{
    char imageFileName [100];
    cout<<"Enter the file image file name to save: ";
    cin.ignore();
    cin.clear();
    cin>> imageFileName ;
    //Add to it .bmb extension and load image.
    strcat (imageFileName,".bmp");
    writeGSBMP(imageFileName,image);
}
void save2()
{
    char imageFileName2 [100];
    cout<<"Enter the file image file name to save: ";
    cin.ignore();
    cin.clear();
    cin>> imageFileName2 ;
    //Add to it .bmb extension and load image.
    strcat (imageFileName2,".bmp");
    writeGSBMP(imageFileName2,image2);
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
    save();
}

void filter2()
{
for (int i = 0; i < SIZE; i++)
    for (int j = 0; j< SIZE; j++)
       image[i][j] = 255 - image[i][j];
}

void filter3 ()
{
load2();
 for (int k = 0; k < (SIZE); k++)
        {
          for (int l = 0; l < (SIZE); l++)
          {

                    if (image2[k][l] <225){
                        image2[k][l]=image2[k][l]+30;
                    }
                    else if(image[k][l] <107){
                       image2[k][l]=image2[k][l]+30;
                    }
                    else
                        continue;

               }
               }

save();
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

    else if(ICHOICE=='v'){
        for (int k = 0; k < (SIZE); k++)
        {
          for (int l = 0; l < (SIZE/ 2); l++)
          {
        int temp2 = image[k][l];
        image[k][l] = image[k][SIZE- 1 - l];
        image[k][SIZE-1-l] = temp2;
          }
        }

    }

    else {
    cout<<"please enter correct value "<<endl;
    goto start;
    }
    save();
}

void filter5(){

    cout << "Do you want to (d)arken or (l)ighten?" << endl;
    char C;
    cin>>C;

     for (int k = 0; k < (SIZE); k++)
        {
          for (int l = 0; l < (SIZE); l++)
          {
             if(C=='d')
               {
                    if (image[k][l] > 117){
                        image[k][l]=image[k][l]-30;
                    }
                    else if(image[k][l] > 30){
                       image[k][l]=image[k][l]-30;
                    }
                    else
                        continue;



               }
            else if(C=='l')
               {
                   if (image[k][l] <225){
                        image[k][l]=image[k][l]+30;
                    }
                    else if(image[k][l] <107){
                       image[k][l]=image[k][l]+30;
                    }
                    else
                        continue;

               }
          }

}
save();
}


void filter6()
{
    cout << "Rotate (90), (180) or (360) degrees?" << endl;
    string I;
    cin>>I;
    if(I=="90")//not correct*************
    {
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image2[j][j-SIZE-1]=image[i][j];
            }
        }

    }
save2();
}
