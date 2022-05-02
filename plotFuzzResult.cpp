#include "pbPlots.hpp"
#include "supportLib.hpp"

int main(){
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

    std::vector<double> x = {-2, -1, 0, 1, 2};
    std::vector<double> y = {1, 2, 3, 4, 5};

    DrawScatterPlot(imageReference, 1000, 1000, &x, &y);

    std::vector<double> *pngData = ConvertToPNG(imageReference->image);
    WriteToFile(pngData, "fuzzPlot.png");
    DeleteImage(imageReference->image);


    return 0;
}