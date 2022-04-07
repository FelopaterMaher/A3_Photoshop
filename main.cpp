// Program: Ass3.
// Author:  Felopater maher
// Version: 5
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

void filter7();

void filter8();

void filter9();

void filtera();

void filterb();

void filterc();

void save();

int main() {

for(int M=0;M<20;M++){
    cout << " Ahlan ya user ya habibi \n" << endl;
    load();
    cout << "Please select a filter to apply or 0 to exit:\n"
            "1- Black & White Filter\n"//done
            "2- Invert Filter\n"//done
            "3- Merge Filter \n"//done
            "4- Flip Image\n"//done
            "5- Darken and Lighten Image \n"//done
            "6- Rotate Image\n"//done
            "7- Detect Image Edges \n"
            "8- Enlarge Image\n"//done
            "9- Shrink Image\n"//done
            "a- Mirror 1/2 Image\n"//done
            "b- Shuffle Image\n"
            "c- Blur Image\n"//done
            "s- Save the image to a file\n"//done
            "0- Exit";//done
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
        filter7();
    } else if (iChoice == '8') {
filter8();
    } else if (iChoice == '9') {
        filter9();
    } else if (iChoice == 'a') {
filtera();
    } else if (iChoice == 'b') {

    } else if (iChoice == 'c') {
        filterc();
    } else if (iChoice == 's')
    {
         save();
    }
     else if (iChoice == 0) {
        return 0;
    }

}
    return 0;
}

void load() {
    char imageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    //Add to it .bmb extension and load image.
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void load2() {
    char imageFileName2[100];
    cout << "Enter the source image2 file name: ";
    cin >> imageFileName2;
    //Add to it .bmb extension and load image.
    strcat(imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);//??????
}

void save() {
    char imageFileName[100];
    cout << "Enter the file image file name to save: ";
    cin.ignore();
    cin.clear();
    cin >> imageFileName;
    //Add to it .bmb extension and load image.
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void save2() {
    char imageFileName2[100];
    cout << "Enter the file image file name to save: ";
    cin.ignore();
    cin.clear();
    cin >> imageFileName2;
    //Add to it .bmb extension and load image.
    strcat(imageFileName2, ".bmp");
    writeGSBMP(imageFileName2, image2);
}


void filter1() {//black and white
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    save();
}

void filter2() {//invert
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            image[i][j] = 255 - image[i][j];
}

void filter3() {//merg
    load2();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = (image[i][j] + image2[i][j]) / 2;

        }
    }


    save();
}

void filter4() {//flip
    start:
    cout << "Flip (h)orizontally or (v)ertically ?" << endl;
    char ICHOICE;
    cin >> ICHOICE;
    if (ICHOICE == 'h') {
        for (int i = 0; i < (SIZE / 2); i++) {
            for (int j = 0; j < (SIZE); j++) {
                int temp = image[i][j];
                image[i][j] = image[SIZE - 1 - i][j];
                image[SIZE - 1 - i][j] = temp;
            }
        }
    } else if (ICHOICE == 'v') {
        for (int k = 0; k < (SIZE); k++) {
            for (int l = 0; l < (SIZE / 2); l++) {
                int temp2 = image[k][l];
                image[k][l] = image[k][SIZE - 1 - l];
                image[k][SIZE - 1 - l] = temp2;
            }
        }

    } else {
        cout << "please enter correct value " << endl;
        goto start;
    }
    save();
}

void filter5() {//darken and lighten

    cout << "Do you want to (d)arken or (l)ighten?" << endl;
    char C;
    cin >> C;

    for (int k = 0; k < (SIZE); k++) {
        for (int l = 0; l < (SIZE); l++) {
            if (C == 'd') {
                image[k][l] = (image[k][l]) / 2;
            } else if (C == 'l') {
                if (image[k][l] < 225) {
                    image[k][l] = image[k][l] + 30;
                } else if (image[k][l] < 107) {
                    image[k][l] = image[k][l] + 30;
                } else
                    continue;

            }
        }
    }


    save();
}


void filter6() {//rotate
    cout<<"Rotate 90 , 180 ,270 ?";
    int c;
    cin>>c;
    if(c==90){
 for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image2[i][j] = image[255 - j][i];
        }
    }}
    else if(c==180)
{
     for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image2[i][j] = image[255 - i][255 - j];
        }
    }}
    else if(c==270){
    int k = 255;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image2[i][j] = image[j][k];
        }
        k--;
    }
}
save2();
}


void filter7() {


    for (int i = 0; i < SIZE; i ++) {
            for (int j = 0; j < SIZE; j ++) {
                    if (image[i][j]>image[i+1][j+1]||image[i][j]>image[i+1][j-1]||image[i][j]>image[i-1][j-1]||image[i][j]>image[i-1][j]||image[i][j]>image[i][j+1]){
                        image[i][j]=0;
                    }
                    else {
                        image[i][j]=255;
                    }
}
    }
    save();
}


void filter8()//enlarge
{
    cout<<" 1,2,3,4 ";
    int i;
    cin>>i;
        if (i == 1) {
                for(int k=0;k<SIZE;k+=2)
                {
                    for(int l=0;l<SIZE;l+=2)
                    {
                       image2[k][l]=image[k/2][l/2];
                       image2[k+1][l+1]=image[(k/2)+1][(l/2)+1];

        }
        }
        }
        else if(i==2){
                  for(int k=0;k<SIZE;k+=2)
                {
                    for(int l=0;l<SIZE;l+=2)
                    {
                       image2[k][l]=image[(k/2)][(l/2)+128];
                         image2[k+1][l+1]=image[(k/2)+1][(l/2)+1];

        }
        }

        }
        else if(i==3){
               for(int k=0;k<SIZE;k+=2)
                {
                    for(int l=0;l<SIZE;l+=2)
                    {
                       image2[k][l]=image[(k/2)+128][(l/2)];
                         image2[k+1][l+1]=image[(k/2)+1][(l/2)+1];

        }
        }
        }
        else if(i==4){
               for(int k=0;k<SIZE;k+=2)
                {
                    for(int l=0;l<SIZE;l+=2)
                    {
                       image2[k][l]=image[(k/2)+128][(l/2)+128];
                         image2[k+1][l+1]=image[(k/2)+1][(l/2)+1];

        }
        }
        }

        for(int m=0;m<SIZE;m++)
                {
                    for(int h=0;h<SIZE;h++)
                    {
        if (image2[m][h] < 225) {
                    image2[m][h] = image2[m][h] + 30;
                } else if (image2[m][h] < 107) {
                    image2[m][h] = image2[m][h] + 30;
                } else{ continue;

                    }
                    }}
    save2();
}


void filter9()//shrink
{

    cout << "Shrink to (1/2), (1/3) or (1/4)? ";
    double c;

    string w;
    cin >> w;
    if (w == "1/2") {
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2) {


                image2[i / 2][j / 2] = image[i][j];
            }

        }


    } else if (w == "1/3") {

        for (int i = 0; i < SIZE; i += 3) {
            for (int j = 0; j < SIZE; j += 3) {


                image2[i / 3][j / 3] = image[i][j];
            }

        }

    } else if (w == "1/4") {

        for (int i = 0; i < SIZE; i += 4) {
            for (int j = 0; j < SIZE; j += 4) {


                image2[i / 4][j / 4] = image[i][j];
            }

        }

    }


    save2();
}


void filtera() {//mirror
     int n;
    cout << "\n1.Left 1/2"
            "\n2.Right 1/2"
            "\n3.Up 1/2"
            "\n4.Down 1/2"
            "\nOperation No.";
    cin >> n;
    if (n == 1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                image2[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                image2[i][j] = image[i][255 - j];
            }
        }
        save2();
    }
    if (n == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                image2[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                image2[i][j] = image[i][255 - j];
            }
        }
        save2();
    }
    if (n == 3) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[i][j];
            }
        }
        for (int i = SIZE / 2; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[255 - i][j];
            }
        }
        save2();
    }
    if (n == 4) {
        for (int i = SIZE / 2; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
               image2[i][j] = image[255 - i][j];
            }
        }
        save2();
    }
}


void filterb() {

}


void filterc() {//blur

    for (int k = 0; k < (SIZE); k++) {
        for (int l = 0; l < (SIZE); l++) {
            image[k][l] = (image[k - 1][l - 1] + image[k - 1][l] + image[k - 1][l + 1] + image[k][l - 1] + image[k][l] +
                           image[k][l + 1] + image[k + 1][l - 1] + image[k + 1][l] + image[k + 1][l + 1]) / 9;
        }
    }
    save();
}

