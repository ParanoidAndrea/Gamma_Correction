# Gamma_Correction
  Author: Yanyan Zhou
  
  Environment: Visual Studio 2019
  
  Date: 2022/5/17
# Description 
Gamma correction is a method used to adjust the brightness and contrast of an image or video display. It maps the input signal to a non-linear relationship, represented by a gamma value, to compensate for differences in display luminance levels and produce a more accurate representation of the original image. This technique helps to improve the visibility of details and colors, making the display easier for the human eye to perceive.

This code implements a gamma correction algorithm in C++ using the OpenCV library. It performs gamma correction on an image to adjust its brightness and contrast levels.

The code includes the necessary headers to use OpenCV, as well as the standard input/output library and the cmath library for mathematical operations. The "Mat" data type is used to represent images in OpenCV.

The main function of the code is the "gammaTransform" function, which takes an input image and a gamma correction factor as arguments and returns the gamma corrected image. The function first defines an array "LUT" of 256 elements to store the mapping of input image values to the corrected values. It then calculates the gamma correction for each value using the "pow" function from the cmath library and stores the result in the LUT array. The function then creates a clone of the input image and applies the correction to each pixel by looking up the corresponding value in the LUT array. The correction is applied differently for grayscale and color images, depending on the number of channels.

The main function of the code reads an input image "Blue Weekend.jpg" and calls the "gammaTransform" function twice with different gamma correction factors to obtain two different gamma corrected images. The original image and the two corrected images are displayed using the "imshow" function from OpenCV. The result of one of the corrected images is saved to a file "Gamma.jpg".

The code uses the OpenCV library to perform the gamma correction, making it efficient and easy to use.
# Directory Structure

    ├── ReadMe.md               // User Guide
    
    ├── Debug             
    
    │   ├── Gamma校正.exe   // run the program
    
    ├── Gamma校正.sln       // solution file 
    
    ├── Gamma校正.cpp       // source code
        
    ├── Gamma校正.vcxproj   //Visual Studio project files
            
    ├── Gamma校正.vcxproj.filters   
            
    ├── Gamma校正.vcxproj.user 
        
    ├── Blue Weekend.jpg    //sample input picture
        
    ├── Gamma.jpg           //one of the output picture
# Input and Output
Place the image in the root directory, which will display as srcImage:
![image](https://user-images.githubusercontent.com/82789287/218583478-b28b0032-47dc-42e1-956d-b8aa2521f49f.png)
Run the program, two result images will show:
![image](https://user-images.githubusercontent.com/82789287/218583657-dc57cd2e-8b2b-4aec-af72-2c9639a8d6d7.png)

