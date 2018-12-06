#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    Mat image;
    image = imread( argv[1], 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    Mat dstImage;
    GaussianBlur(image,dstImage,Size(5,5),0,0);
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    namedWindow("Gaussian filter", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    imshow("Gaussian filte", dstImage);
    waitKey(0);
    return 0;
}