/*
  File: Gamma Correction.cpp
  Author: Yanyan Zhou
  Desctiption: This code implements a gamma correction algorithm in C++ using the OpenCV library.
  It performs gamma correction on an image to adjust its brightness and contrast levels.
  Date: December 2021
*/

#include <iostream>  
#include <opencv2\core\core.hpp>  
#include <opencv2\highgui\highgui.hpp>  
#include <opencv2\imgproc\imgproc.hpp>  
#include<cmath>
using namespace cv;

// Function to perform gamma correction on an image
Mat GammaTransform(Mat& srcImage, float kFactor)
{
	// Look-up table (LUT) with 256 elements of type unsigned char
	unsigned char LUT[256];

	// Loop through the LUT and calculate the gamma correction value for each LUT element
	for (int i = 0; i < 256; i++)
	{
		float f = (i + 0.5f) / 255;
		f = (float)(pow(f, kFactor));
		LUT[i] = saturate_cast<uchar>(f * 255.0f - 0.5f);
	}

	// Create a clone of the source image as the result image
	Mat resultImage = srcImage.clone();

	// Check if the source image is grayscale or color
	if (srcImage.channels() == 1)
	{
		// If grayscale, loop through the result image and apply gamma correction to each element
		MatIterator_<uchar> iterator = resultImage.begin<uchar>();
		MatIterator_<uchar> iteratorEnd = resultImage.end<uchar>();
		for (; iterator != iteratorEnd; iterator++)
		{
			*iterator = LUT[(*iterator)];
		}
	}
	else
	{
		// If color, loop through the result image and apply gamma correction to each color channel
		MatIterator_<Vec3b> iterator = resultImage.begin<Vec3b>();
		MatIterator_<Vec3b> iteratorEnd = resultImage.end<Vec3b>();
		for (; iterator != iteratorEnd; iterator++)
		{
			(*iterator)[0] = LUT[((*iterator)[0])]; // Blue channel
			(*iterator)[1] = LUT[((*iterator)[1])]; // Green channel
			(*iterator)[2] = LUT[((*iterator)[2])]; // Red channel
		}
	}

	// Return the result image
	return resultImage;
}

int main()
{
	// Load the source image
	Mat srcImage = imread("Blue Weekend.jpg");

	// Check if the image was successfully loaded
	if (!srcImage.data)
	{
		printf("could not load image...\n");
		return -1;
	}

	// Retrieve two different gamma values
	float gamma1 = 2.2f;
	// float gamma1 = 0.33f;
	float kFactor1 = gamma1;
	float kFactor2 = 1 / gamma1;

	// Apply gamma correction to the source image with kFactor1 and kFactor2
	Mat result1 = GammaTransform(srcImage, kFactor1);
	Mat result2 = GammaTransform(srcImage, kFactor2);

	// Display the source image and the two results
	imshow("srcImage", srcImage);
	imshow("res1", result1);
	imshow("res2", result2);

	// Save the first result
	bool saveFlag = cv::imwrite("Gamma.jpg", result1);
	printf("saveFlag=%d\n", saveFlag);
	waitKey(0);
	return 0;
}
