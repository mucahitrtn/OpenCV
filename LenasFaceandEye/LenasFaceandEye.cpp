#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
  double scale = 1;
  Mat img = imread("lena2.jpg");
  if (img.empty())
  {
    cout << "Image not found!";
    return -1;
  }
  else
    cout << "LENA\n";
  
  vector <Rect> recteye;
  vector <Rect> rectface;
  CascadeClassifier eye;
  CascadeClassifier face;
  
    eye.load("C:\\Users\\canis\\Downloads\\opencv\\build\\etc\\haarcascades\\haarcascade_eye.xml");
    eye.detectMultiScale(img, recteye, 1.2, 3, 0, Size(30, 30));
    face.load("C:\\Users\\canis\\Downloads\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt2.xml");
    face.detectMultiScale(img, rectface, 1.1, 3, 0, Size(30, 30));
    
  cout << " eyes: " << recteye.size() << endl;
  cout << " faces: " << rectface.size() << endl;
  
  for (Rect area : recteye) {
      Scalar drawColor = Scalar(255,0,0);
      rectangle(img, Point(cvRound(area.x * scale), cvRound(area.y * scale)),
      Point(cvRound(area.x + area.width - 1), cvRound(area.y + area.height - 1)), drawColor);
  }
  for (Rect area : rectface) {
      Scalar drawColor1 = Scalar(0, 0, 0,150);
      rectangle(img, Point(cvRound(area.x * scale), cvRound(area.y * scale)),
      Point(cvRound(area.x + area.width - 1), cvRound(area.y + area.height - 1)), drawColor1);
  }
  imshow("color", img);
  cv::waitKey();
  
  return 0;
}
