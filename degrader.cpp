#include <iostream>
#include <fstream>
#include <vips/vips8>
#include "degrader.h"

bool Degrader::is_square(VImage in){
    double w = in.width();
    double h = in.height();
    if (w == h){
        cout << "It's a square";
        return true;
    } else {
        cout << "Not a square...sending to cropper" << "\n";
        return false;
    }
}

void Degrader::file_size(string file_name){
    ifstream in_file(file_name, ios::binary);
    in_file.seekg(0, ios::end);
    int file_size = in_file.tellg();
    double size_in_kb = file_size * .001;
    cout << file_name << " is " << file_size << " bytes large or " << size_in_kb <<" kilobytes" << "\n";
}

void Degrader::img_specs(VImage in, string file_name){
    double w = in.width();
    double h = in.height();
    cout << "The height of the image is: " << h << "\n";
    cout << "The width is: " << w << "\n";
    file_size(file_name);
}

VImage Degrader::cropper(VImage in, double left, double top, double w, double h){
  VImage out = in.crop(left, top, w, h);
  return out;
}

VImage Degrader::zoom(VImage in, int x){
    VImage zoomed = in;
    zoomed = zoomed.zoom(x, x);

    return zoomed;
}

VImage Degrader::blur(VImage in, double sigma){
    VImage blurred = in;
    blurred = blurred.gaussblur(sigma, 0);
    
    return blurred;
}