#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;





//像素加减乘除
int test005() {
	Mat src1 = imread("./img/self.jpg");
	Mat src2 = src1.clone();
	
	Mat dst = Mat::zeros(src1.size(), src1.type());

	add(src1, src2, dst);
	imshow("add", dst);

	subtract(src1, src2, dst);
	imshow("subtract", dst);

	multiply(src1, src2, dst);
	imshow("mulitply", dst);

	divide(src1, src2, dst);
	imshow("divide", dst);

	waitKey(0);
	destroyAllWindows();

	return 0;
}

//图像像素的读写操作
int test004() {
	Mat src = imread("./img/self.jpg");
	Mat dst = Mat::zeros(src.cols, src.rows, src.type());

	//cout << dst.rows << ' ' << dst.cols << ' ' << src.rows << ' ' << src.cols << endl;
	int rows = src.rows, cols = src.cols;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			dst.at<Vec3b>(cols - 1 - j, i) = src.at<Vec3b>(i, j);
		}
	}
		
	
	/*for(int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j) {
			Vec3b vec = src.at<Vec3b>(i, j);
			dst.at<Vec3b>(rows - 1 - i, cols - j - 1) = vec;
		}*/

	/*for (int i = 0; i < rows; ++i) {
		uchar* cur_row = src.ptr<uchar>(i);
		uchar* dst_row = dst.ptr<uchar>(rows - 1 - i);
		for (int j = 0; j < cols; ++j)
			for (int k = 0; k < 3; ++k)
				* dst_row++ = *cur_row++;
	}*/


	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

//图像对象的创建与赋值
int test003() {
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


//图像色彩空间转换
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

//图像读取与显示
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