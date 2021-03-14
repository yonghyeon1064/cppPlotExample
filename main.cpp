#include "pbPlots.hpp"
#include "supportLib.hpp"

std::vector<double> createDomain(const double start, const double end, const double step);
std::vector<double> sin_func(const std::vector<double> domain);



int main()
{
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

    //std::vector<double> x = {-2, -1, 0, 1, 2};
    //std::vector<double> y = {1, 2, 3, 4, 5};

    std::vector<double> x = createDomain(-5, 5, 0.1);
    std::vector<double> y = sin_func(x);

    DrawScatterPlot(imageReference, 1000, 1000, &x, &y);

    std::vector<double> *pngData = ConvertToPNG(imageReference->image);
    WriteToFile(pngData, "basic.png");
    DeleteImage(imageReference->image);

    return 0;
}


std::vector<double> createDomain(const double start, const double end, const double step){
    std::vector<double> domain;
    for(double i=start; i<end; i += step){
        domain.push_back(i);
    }
    return domain;
}

std::vector<double> sin_func(const std::vector<double> domain){
    std::vector<double> range;
    for (int i=0; i<domain.size(); ++i){
        range.push_back(sin(domain[i]));
    }
    return range;
}