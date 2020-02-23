#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("./img/self.jpg");
	Mat dst1, dst2, dst3;
	dst1 = src.clone();
	src.copyTo(dst2);
	dst3 = src;

	Mat new1 = Mat::zeros(src.size(), src.type());
	Mat new2 = Mat::zeros(Size(512, 512), CV_8UC3);
	Mat new3 = Mat(512, 512, CV_8UC3, Scalar(255, 255, 255));

	// << new3 << endl;

	namedWindow("input6", WINDOW_NORMAL);
	imshow("input6", new3);

	waitKey(0);
	destroyAllWindows();
	return 0;
}


int test002() {
	Mat src = imread("./img/self.jpg");
	if (src.empty()) {
		cout << "load image failed" << endl;
		return 0;
	}

	namedWindow("src", WINDOW_AUTOSIZE);

	imshow("src", src);

	Mat dst;
	cvtColor(src, dst, COLOR_BGR2GRAY);
	namedWindow("dst", WINDOW_NORMAL);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
	return 0;
}


int test001() {
	Mat src = imread("E:\\Desktop\\20200117235347.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cout << "not load image" << endl;
		return 0;
	}

	//namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	waitKey(0);

	destroyAllWindows();
	return 0;
}