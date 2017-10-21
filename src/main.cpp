/*
 * main.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: Karthik Puthraya
 *      E-mail: karthik@puthraya.com
 */
#include "SeamCarver.h"

int main(int argc, char *argv[]) 
{
	if(argc<4)
	{
		std::cerr<<"Usage: ./SeamCarving <IMAGE_FILE_PATH> <CARVED_OUT_IMAGE_PATH> <NEW_INT_WIDTH> <NEW_INT_HEIGHT>"<<std::endl;
		std::cerr<<"Press Esc to exit"<<std::endl;
	}

	//load image and check
	Mat_<Vec3b> image = imread(argv[1],1);
	if (!image.data)
	{
		cout << "Invalid input";
		image.release();
		return -1;
	}
	std::cout<<"image width: "<<image.cols<<std::endl;
	std::cout<<"image height: "<<image.rows<<std::endl;
	imshow("Original Image", image);
	SeamCarver s(image);

	int new_width=0;
	int new_height=0;
	try
	{
		new_width = atoi(argv[3]);
		new_height = atoi(argv[4]);
		std::cout<<"New width: "<<new_width<<std::endl;
		std::cout<<"New height: "<<new_height<<std::endl;
	}
	catch(int)
	{
		std::cerr<<"Error in NEW_INT_WIDTH or NEW_INT_HEIGHT"<<std::endl;
	}
	
	//check valid width and height
	if(new_width<=0 || new_width>image.cols || new_height<=0 || new_height>image.rows)
	{
		std::cerr<<"The new width or height is below zero or bigger than the origin image"<<std::endl;
	}


	int width_offset = 0;
	int height_offset = 0;
	width_offset = image.cols-new_width;
	height_offset = image.rows-new_height;
	std::cout<<"offset width: "<<width_offset<<std::endl;
	std::cout<<"offset height: "<<height_offset<<std::endl;

	for (int i = 0; i < height_offset; ++i) 
	{
		vector<uint> seam = s.findHorizontalSeam();
		s.removeHorizontalSeam(seam);
	}
	for (int i = 0; i < width_offset; ++i)
 	{

		vector<uint> seam = s.findVerticalSeam();
		s.removeVerticalSeam(seam);
	}


	imshow("Carved Image", s.getImage());

	while (waitKey(20) != 27);

	imwrite(argv[2], s.getImage());

	image.release();
	return 0;
}



