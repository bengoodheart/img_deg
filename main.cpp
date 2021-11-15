#include <iostream>
#include <fstream>
#include <string>
#include <vips/vips8>
#include "degrader.h"

using namespace vips;
using namespace std;

int main(int argc, char **argv){ 
  if (VIPS_INIT (argv[0])) 
    vips_error_exit (NULL);

  if (argc < 6 )
    vips_error_exit ("usage: %s input-file output-file quality blur_amount zoom", argv[0]);

  
  int qual_num = stoi(argv[3]);
  if (qual_num <=0 || qual_num >75){
    vips_error_exit("Error! You put in an integer either zero or below or above 75");
  }

  int blur_amount = stoi(argv[4]);
  if(blur_amount < 0 || blur_amount > 100){
    vips_error_exit("Error! You put in an integer either below zero or above 100");
  }

  int zoom_amount = stoi(argv[5]);
  if(zoom_amount < 0 || zoom_amount > 5){
    vips_error_exit("Error! You put in an integer either below zero or above 5");
  }


  VImage in = VImage::new_from_file (argv[1],
    VImage::option ()->set ("access", VIPS_ACCESS_SEQUENTIAL));

  Degrader deg;

  double avg = in.avg();
  

  printf ("avg = %g\n", avg);
  printf ("width = %d\n", in.width ());


  /** Turn into a square
  if (deg.is_square(in) != true){
    double w = in.width();
    double h = in.height();
    double top = h/(w/h);
    double left = w/(w/h);
    cout << left << "\n";
    in = deg.cropper(in, left, top, 10, 500);
  } 
  **/


  deg.img_specs(in, argv[1]);
  VImage blurred = deg.blur(in, blur_amount);
  VImage out = deg.zoom(blurred, zoom_amount);
  
  //img specs again, write a block tosee if the shit is too big, if it is they gotta resize or crop auttomatically
  // out = deg.cropper()

  out.jpegsave(argv[2], VImage::option ()-> set ("Q", qual_num));    //The Q option refers to the quality, default is 75


  deg.img_specs(out, argv[2]);
  vips_shutdown ();
  
  

  return 0;
}