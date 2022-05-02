#include "pbPlots.hpp"
#include "supportLib.hpp"

int main(){
    RGBABitmapImageReference *imageReference1 = CreateRGBABitmapImageReference();
    RGBABitmapImageReference *imageReference2 = CreateRGBABitmapImageReference();
    RGBABitmapImage *combined = CreateImage(2000, 2000, GetWhite());
    RGBABitmapImage *image1, *image2;

    std::vector<double> x = {-2, -1, 0, 1, 2};
    std::vector<double> y1 = {1, 2, 3, 4, 5};
    std::vector<double> y2 = {5, 4, 3, 2, 1};

    DrawScatterPlot(imageReference1, 2000, 2000, &x, &y1);
    DrawScatterPlot(imageReference1, 2000, 2000, &x, &y2);

    image1 = imageReference1->image;
    image2 = imageReference2->image;

    DrawImageOnImage(combined, image1, 0, 0);
    //DrawImageOnImage(combined, image2, 0, 0);

    std::vector<double> *pngData = ConvertToPNG(combined);
    WriteToFile(pngData, "fuzzPlot.png");
    DeleteImage(imageReference1->image);
    DeleteImage(imageReference2->image);
    DeleteImage(combined);


    return 0;
}