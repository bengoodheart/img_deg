#include <iostream>
#include <fstream>
#include <vips/vips8>

using namespace vips;
using namespace std;

class Degrader{
    private:
        void file_size(string file_name);
    public:
        bool is_square(VImage in);
        void img_specs(VImage in, string file_name);
        VImage cropper(VImage in, double left, double top, double w, double h);
        VImage zoom(VImage in, int x);
        VImage blur(VImage in, double sigma);
        VImage resize(VImage original, VImage degraded);
};