//**************************************************************************************************
// Program Name:	ppm Generator
// Developer:		Adrian Bernat
// Course Number:	CS-162-02
// Date:			1-25-17
// IDE:				Visual Studio 2015
// Purpose:			Generate a PPM image, demonstrating a use of multidimensional arrays and writing
//					to an external file using a function to create the array and another to write it
//					to the external file.
//**************************************************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

//Global Constants
const int HEIGHT = 300;
const int WIDTH = 200;
const int COLOR = 3; //0=red, 1=green, 2=blue

//Prototypes
void createImage(unsigned char image[][WIDTH][COLOR]);
void printImage(const unsigned char image[][WIDTH][COLOR]);

int main() {
	unsigned char image[HEIGHT][WIDTH][COLOR];

	createImage(image);
	printImage(image);
	return 0;
}

/************************************************************************
Function Name:        createImage
Function Description: splits the 300x200 rectangle into multiple colors 
					  based on the pixel's location within it.
Function Arguments:	  Image[][WIDTH][COLOR] (Out) - This is the array
					  that holds the location and color of the pixel.
*************************************************************************/

void createImage(unsigned char image[][WIDTH][COLOR]) {

//Declare the variables holding the center and radius of the circle	
	int cx = 100;
	int cy = 150;
	int radius = 100;
	
//Loop splitting the rectangle into four different colors
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (y < 50) {
				image[y][x][0] = 0;
				image[y][x][1] = 255;
				image[y][x][2] = 0;
			}
			else if (y < (HEIGHT / 2) && y > 50) {
				image[y][x][0] = 255;
				image[y][x][1] = 255;
				image[y][x][2] = 0;
			}
			else if (y < 250 && y >(HEIGHT / 2)) {
				image[y][x][0] = 0;
				image[y][x][1] = 0;
				image[y][x][2] = 128;
			}
			else if (y > 250) {
				image[y][x][0] = 0;
				image[y][x][1] = 255;
				image[y][x][2] = 255;
			}
		}
	}

// This loop creates the red circle
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (sqrt(((x - cx)*(x - cx)) + ((y - cy)*(y - cy))) <= radius) {
				image[y][x][0] = 255;
				image[y][x][1] = 0;
				image[y][x][2] = 0;	
			}
		}
	}

}

/************************************************************************
Function Name:        printImage
Function Description: Outputs the premade array onto an external PPM file
					  to be opened externally and create a picture.
Function Arguments:	  Image[][WIDTH][COLOR] (In) - This is the array
					  that holds the location and color of the pixel.
*************************************************************************/

void printImage(const unsigned char image[][WIDTH][COLOR]) {

//Declare the preliminary ppm-required headers
	ofstream ppmFile;
	ppmFile.open("AdrianBernat.ppm");
	ppmFile << "P3" << endl;
	ppmFile << "200 300" << endl;
	ppmFile << "255" << endl;

//insert the RGB values into the PPM file
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			for (int rgb = 0; rgb < COLOR; rgb++)
				ppmFile << static_cast<int>(image[y][x][rgb]) << " ";
	ppmFile.close();
}
