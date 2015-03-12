#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <list>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <numeric>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <set>

using namespace cv;
using namespace std;
typedef std::basic_ostringstream<char> ostringstream;
typedef std::basic_istringstream<char> istringstream;

Mat src; Mat src_gray; Mat src_filt; Mat src_gray_dst; Mat src_gray_dst_out; Mat src_gray_dst_out_morph;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);
int contour_thresh = 300;
int MAX_KERNEL_LENGTH = 31;

/** @function thresh_callback */
Mat create_contour(){
  Mat canny_output; Mat fake_src;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  fake_src = src_gray.clone();
  /// Detect edges using canny
  Canny( fake_src, canny_output, thresh, thresh*8);
  
  /// Find contours
  findContours( src_gray, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0) );
  /*
  for( int i = 0; i< contours.size(); i++ )
     {
      std::cout << contours[i].size() << std::endl;
    }*/

  // Draw contours
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  Scalar color = Scalar(255,255,255);
  for( int i = 1; i< contours.size(); i++ ){
    /*
    double temp_sum_slope = 0.0;
    double temp_avg_slope;
    int contour_temp_len = contours[i].size();

    for(int j=contour_temp_len; j>0;j--){
      double diff_y = (double)contours[i][j].y - (double)contours[i][j-1].y;
      double diff_x =  (double)contours[i][j].x - (double)contours[i][j-1].x;
      double temp_slope;
      if(diff_x !=0)
        temp_slope = diff_y/diff_x;
      else
        temp_slope = 0;
      temp_sum_slope += temp_slope;
    }
    if(temp_sum_slope > 0)
      temp_avg_slope = temp_sum_slope/(float)contour_temp_len;
    else
      temp_avg_slope = 0.0;

    std::cout << "temp_avg_slope: " << temp_avg_slope << " contours[i].size(): " <<  contours[i].size() <<  std::endl;
    //Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    //if(contours[i].size() > 1)
      //  drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
    //else
    //  if(abs(temp_avg_slope) > 0)
    */
    drawContours( drawing, contours, i, color, -1, 8, hierarchy, 0, Point() );
   }

  /*
  //kmeans plot
  int clusterCount = 200;
  Mat samples(src_gray.rows * src_gray.cols, 3, CV_32F);

  for( int y = 0; y < src_gray.rows; y++ )
    for( int x = 0; x < src_gray.cols; x++ )
      for( int z = 0; z < 3; z++)
        samples.at<float>(y + x*src_gray.rows, z) = src_gray.at<Vec3b>(y,x)[z];

  Mat labels;
  int attempts = 5;
  Mat centers;
  kmeans(samples, clusterCount, labels, TermCriteria(cv::TermCriteria::MAX_ITER|cv::TermCriteria::EPS,10000, 0.0001), attempts, KMEANS_PP_CENTERS, centers );
  cout << "after kmeans" << endl;


  Mat new_image( src_gray.rows, src_gray.cols, CV_32F);
  cout << "after new image" << endl;
  cout << "labels.size(): " << labels.size() << endl;
  cout << "new_image.size(): " << new_image.size() << endl;
  for( int y = 0; y < src_gray.rows; y++ ){
    //cout << "in new_image_fill y: " << y << endl;
    for( int x = 0; x < src_gray.cols; x++ )
    { 
      try{
        int cluster_idx = labels.at<int>(y + x*src_gray.rows,0);
        new_image.at<Vec3b>(y,x)[0] = centers.at<float>(cluster_idx, 0);
        new_image.at<Vec3b>(y,x)[1] = centers.at<float>(cluster_idx, 1);
        new_image.at<Vec3b>(y,x)[2] = centers.at<float>(cluster_idx, 2);
      }
      catch(...){
        cout << "in new image: " <<  "y: " << y << "x: " << x <<endl;
        exit(1);
      }
      
    }  
  }
  cout << "after new_image_fill" << endl;
  */
  /// Show in a window
  return drawing;
}


/** @function thresh_callback */
void thresh_callback(int, void* )
{
  Mat canny_output; Mat fake_src;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  fake_src = src_gray.clone();
  /// Detect edges using canny
  Canny( fake_src, canny_output, thresh, thresh*8);
  
  /// Find contours
  findContours( src_gray, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0) );
  /*
  for( int i = 0; i< contours.size(); i++ )
     {
      std::cout << contours[i].size() << std::endl;
    }*/

  // Draw contours
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  Scalar color = Scalar(255,255,255);
  for( int i = 1; i< contours.size(); i++ ){
    /*
    double temp_sum_slope = 0.0;
    double temp_avg_slope;
    int contour_temp_len = contours[i].size();

    for(int j=contour_temp_len; j>0;j--){
      double diff_y = (double)contours[i][j].y - (double)contours[i][j-1].y;
      double diff_x =  (double)contours[i][j].x - (double)contours[i][j-1].x;
      double temp_slope;
      if(diff_x !=0)
        temp_slope = diff_y/diff_x;
      else
        temp_slope = 0;
      temp_sum_slope += temp_slope;
    }
    if(temp_sum_slope > 0)
      temp_avg_slope = temp_sum_slope/(float)contour_temp_len;
    else
      temp_avg_slope = 0.0;

    std::cout << "temp_avg_slope: " << temp_avg_slope << " contours[i].size(): " <<  contours[i].size() <<  std::endl;
    //Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    //if(contours[i].size() > 1)
      //  drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
    //else
    //  if(abs(temp_avg_slope) > 0)
    */
    drawContours( drawing, contours, i, color, -1, 8, hierarchy, 0, Point() );
   }

  /*
  //kmeans plot
  int clusterCount = 200;
  Mat samples(src_gray.rows * src_gray.cols, 3, CV_32F);

  for( int y = 0; y < src_gray.rows; y++ )
    for( int x = 0; x < src_gray.cols; x++ )
      for( int z = 0; z < 3; z++)
        samples.at<float>(y + x*src_gray.rows, z) = src_gray.at<Vec3b>(y,x)[z];

  Mat labels;
  int attempts = 5;
  Mat centers;
  kmeans(samples, clusterCount, labels, TermCriteria(cv::TermCriteria::MAX_ITER|cv::TermCriteria::EPS,10000, 0.0001), attempts, KMEANS_PP_CENTERS, centers );
  cout << "after kmeans" << endl;


  Mat new_image( src_gray.rows, src_gray.cols, CV_32F);
  cout << "after new image" << endl;
  cout << "labels.size(): " << labels.size() << endl;
  cout << "new_image.size(): " << new_image.size() << endl;
  for( int y = 0; y < src_gray.rows; y++ ){
    //cout << "in new_image_fill y: " << y << endl;
    for( int x = 0; x < src_gray.cols; x++ )
    { 
      try{
        int cluster_idx = labels.at<int>(y + x*src_gray.rows,0);
        new_image.at<Vec3b>(y,x)[0] = centers.at<float>(cluster_idx, 0);
        new_image.at<Vec3b>(y,x)[1] = centers.at<float>(cluster_idx, 1);
        new_image.at<Vec3b>(y,x)[2] = centers.at<float>(cluster_idx, 2);
      }
      catch(...){
        cout << "in new image: " <<  "y: " << y << "x: " << x <<endl;
        exit(1);
      }
      
    }  
  }
  cout << "after new_image_fill" << endl;
  */
  /// Show in a window
  namedWindow( "Contours", WINDOW_AUTOSIZE );
  imshow( "Contours", drawing );
  //imshow( "clustered image", new_image );
}

void print_list_string(list<string>& v){
  for (list<string>::iterator it=v.begin(); it != v.end(); ++it)
  {
    /* code */
    cout << *it << endl;
  }
}

string NumberToString(int Number){
  ostringstream ss;
  ss << Number;

  std::string out_temp = ss.str();
  //std::cout << out_temp << '\n';
  return out_temp;
}

void high_pass_binarize_filter(Mat& src_, Mat& out_, bool is_map, bool is_print){
  int rows = src_.rows;
  int cols = src_.cols;
  int black_int = 0;
  int white_int = 255;

  map<string,int> rgbs_map;

  for(int y=0; y< rows; y++){
    for(int x=0; x < cols; x++){
      if(is_map){
        ostringstream temp_ss;
        string temp_str = "";
        for(int i=2; i>=0;i--){
          temp_str += NumberToString((int)src_.at<cv::Vec3b>(y,x)[i]);//[j];
          if(i != 0)
            temp_str += ",";
        }
        rgbs_map[temp_str]++;
      }
      if(is_map){
        
        if((src_.at<cv::Vec3b>(y,x)[0] < 215) && (src_.at<cv::Vec3b>(y,x)[1] < 215) && (src_.at<cv::Vec3b>(y,x)[2] < 215)  ){
          //cout << "y: " << y << " x: "<<  x << endl;
          out_.at<cv::Vec3b>(y,x)[0] = black_int;
          out_.at<cv::Vec3b>(y,x)[1] = black_int;
          out_.at<cv::Vec3b>(y,x)[2] = black_int;
        }
        /*
        else if ((src_.at<cv::Vec3b>(y,x)[0] == 58) && (src_.at<cv::Vec3b>(y,x)[1] == 58) && (src_.at<cv::Vec3b>(y,x)[2] == 176)){
          out_.at<cv::Vec3b>(y,x)[0] = black_int;
          out_.at<cv::Vec3b>(y,x)[1] = black_int;
          out_.at<cv::Vec3b>(y,x)[2] = black_int;
        }*/
        else{
          out_.at<cv::Vec3b>(y,x)[0] = white_int;
          out_.at<cv::Vec3b>(y,x)[1] = white_int;
          out_.at<cv::Vec3b>(y,x)[2] = white_int;
        }
      }
      else{
        int b_c = (int)src_.at<cv::Vec3b>(y,x)[0];
        int r_c = (int)src_.at<cv::Vec3b>(y,x)[1];
        int g_c = (int)src_.at<cv::Vec3b>(y,x)[2];
        vector<int> vec = {b_c, r_c, g_c};
        vector<int>::iterator result;

        result = std::max_element(vec.begin(), vec.end());
        int max_int = distance(vec.begin(), result);
        if(src_.at<cv::Vec3b>(y,x)[max_int] > 100){
          out_.at<cv::Vec3b>(y,x)[0] = white_int;
          out_.at<cv::Vec3b>(y,x)[1] = white_int;
          out_.at<cv::Vec3b>(y,x)[2] = white_int;
        }else{
          out_.at<cv::Vec3b>(y,x)[0] = black_int;
          out_.at<cv::Vec3b>(y,x)[1] = black_int;
          out_.at<cv::Vec3b>(y,x)[2] = black_int;
        }
      }
    }
  }

  if(is_print){
    for(map<string,int>::const_iterator it = rgbs_map.begin();
      it != rgbs_map.end(); ++it){
      if((it->second) > 1000)
        cout << it->first << " " << it->second << "\n";
    }
  }
}


/** @function main */
int main( int argc, char** argv )
{
  /// Load source image and convert it to gray
  string numb = argv[2];
  src = imread(argv[1], 1 );
  src_gray = src.clone();
  
  high_pass_binarize_filter(src, src_gray, true, false);

  src_gray_dst = src_gray.clone();

  string out_file = "../higgs-hunter/test-imgs-2/" + numb + "-grey.png";
  string out_file_countours = "../higgs-hunter/test-imgs-2/" + numb + "-contours-inverted.png";
  
  for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 ){
    // Applying Bilateral Filter
    bilateralFilter(src_gray, src_gray_dst, i, i*11.5, i*100);
  }
  src_gray_dst_out = src_gray_dst.clone();

  high_pass_binarize_filter(src_gray_dst, src_gray_dst_out, false, false);

  imwrite(out_file, src_gray_dst_out);
  /*
  int morph_elem = 1;
  int morph_size = 0;

  //Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );

  /// Apply the specified morphology operation
  //morphologyEx( src_gray_dst_out, src_gray_dst_out_morph, MORPH_OPEN, element );

  
  // Convert image to gray and blur it
  //negate
  Mat neg_src_gray;

  subtract(Scalar::all(255),src_gray_dst_out,neg_src_gray);
  cvtColor( neg_src_gray, src_gray, COLOR_BGR2GRAY );
  //blur( src_gray, src_gray, Size(2,2) );
  /// Create Window
  
  char* source_window = "Source";
  namedWindow( source_window, WINDOW_AUTOSIZE );
  imshow( source_window, src );

  //createTrackbar( " Canny thresh:", "Source", &thresh, max_thresh, thresh_callback );
  
  
  Mat src_done = create_contour();

  for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 ){
    // Applying Bilateral Filter
    bilateralFilter(src_done, src_gray_dst_out, i, i*15, i*100);
  }
  high_pass_binarize_filter(src_gray_dst_out, src_done, false, false);
  
  imwrite(out_file_countours, src_done);
  
  waitKey(0);*/
  
  return(0);
}

