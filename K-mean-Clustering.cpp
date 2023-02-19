#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

float dicecoffiecient(float **arr,int rows,int cols) {
	Mat image_tru = imread("IMD004_lesion.bmp");
	/*imshow("Display Window", image);
	waitKey(0);*/
	float DC =0.000000000000000000000000000;
	float n = 0;
	float tp = 0, fp = 0, fn = 0;
	float** matrix_tru = new float* [image_tru.rows];
	image_tru.convertTo(image_tru, CV_32F);
	for (int k = 0; k < image_tru.rows; k++) {
		matrix_tru[k] = new float[image_tru.cols];
	}
	for (int i = 0; i < image_tru.rows; i++)
	{

		for (int j = 0; j < image_tru.cols; j++)
		{
			matrix_tru[i][j] = image_tru.at<float>(i, j);
		}
	}

	for (int i = 0; i < image_tru.rows; i++) {
		for (int j = 0; j < image_tru.cols; j++) {
			if (matrix_tru[i][j] == 255) {
				if (arr[i][j] == 255) {
					tp++;
				}
				else if (arr[i][j] == 255) {
					fn ++ ;
				}
			}
			else if (matrix_tru[i][j] == 0) {
				if (arr[i][j] == 255) {
					fp++;
				}

			}
		}
	}
	n = 2 * tp;
	DC = n / (fn + n + fp);
	return DC;
}

int main() {



	//for 5x5
	//int matrix[5][5] = { { 1,23,41,67,92 }, { 47, 96, 91, 93, 42 }, {45, 21, 23, 25, 26}, { 45, 91,176, 194, 201 }, { 220 ,248, 129, 174, 190 } };
	//cout << "Original Array\n";
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << matrix[i][j] << "  ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	//int sum_c1 = 0, sum_c2 = 0, count_c1 = 0, count_c2 = 0, diff_c1 = 0, diff_c2 = 0, prev_c1 = 0, prev_c2 = 0, avg_c1 = 0, avg_c2 = 0;
	//int curr_c1 = matrix[5 / 2][2];
	//int curr_c2 = matrix[3][4];
	///*prev_c1 = curr_c1;
	//prev_c2 = curr_c2;*/
	//int** labels = new int* [5];
	//for (int k = 0; k < 5; k++) {
	//	labels[k] = new int[5];
	//}
	//for (int i = 0; i < 5; i++)
	//{

	//	for (int j = 0; j < 5; j++)
	//	{
	//		labels[i][j] = 0;
	//	}
	//}
	//while (prev_c1 != curr_c1 && prev_c2 != curr_c2) {
	//	for (int i = 0; i < 5; i++) {
	//		for (int j = 0; j < 5; j++) {
	//			if (curr_c1 > matrix[i][j]) {
	//				diff_c1 = curr_c1 - matrix[i][j];
	//			}
	//			else {
	//				diff_c1 = matrix[i][j] - curr_c1;
	//			}
	//			if (curr_c2 > matrix[i][j]) {
	//				diff_c2 = curr_c2 - matrix[i][j];
	//			}
	//			else {
	//				diff_c2 = matrix[i][j] - curr_c2;
	//			}
	//			if (diff_c1 < diff_c2) {
	//				sum_c1 = sum_c1 + matrix[i][j];
	//				count_c1++;
	//				labels[i][j] = 2;
	//			}
	//			else if (diff_c2 <= diff_c1) {
	//				sum_c2 = sum_c2 + matrix[i][j];
	//				count_c2++;
	//				labels[i][j] = 3;
	//			}
	//			
	//		}
	//	}
	//	prev_c1 = curr_c1;
	//	prev_c2 = curr_c2;
	//	if (count_c1 != 0) {
	//		avg_c1 = sum_c1 / count_c1;
	//	}
	//	if (count_c2 != 0) {
	//		avg_c2 = sum_c2 / count_c2;
	//	}

	//	curr_c1 = avg_c1;
	//	curr_c2 = avg_c2;

	//}
	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		if (curr_c1 < curr_c2) {
	//			if (labels[i][j] == 2) {
	//				matrix[i][j] = 255;
	//			}
	//			else if (labels[i][j] == 3) {
	//				matrix[i][j] = 0;
	//			}
	//		}
	//		else if (curr_c2 < curr_c1) {
	//			if (labels[i][j] == 2) {
	//				matrix[i][j] = 0;
	//			}
	//			else if (labels[i][j] == 3) {
	//				matrix[i][j] == 255;
	//			}
	//		}
	//	}
	//}
	//for (int i = 0; i <5; i++)
	//{
	//	for (int j = 0; j <5; j++)
	//	{
	//		cout << matrix[i][j] << "  ";
	//	}
	//	cout << endl;
	//}

//for original
	Mat image = imread("IMD004.bmp");
	/*imshow("Display Window", image);
	waitKey(0);*/
	float** matrix = new float* [image.rows];
	image.convertTo(image, CV_32F);
	for (int k = 0; k < image.rows; k++) {
		matrix[k] = new float[image.cols];
	}
	for (int i = 0; i < image.rows; i++)
	{

		for (int j = 0; j < image.cols; j++)
		{
			matrix[i][j] = image.at<float>(i, j);
		}
	}
	int sum_c1 = 0, sum_c2 = 0, count_c1 = 0, count_c2 = 0, diff_c1 = 0, diff_c2 = 0, prev_c1 = 0, prev_c2 = 0, avg_c1 = 0, avg_c2 = 0;
	float curr_c1 = matrix[10][10];
	float curr_c2 = matrix[image.rows - 10][image.cols - 1];
	/*prev_c1 = curr_c1;
	prev_c2 = curr_c2;*/
	int** labels = new int* [image.rows];
	for (int k = 0; k < image.rows; k++) {
		labels[k] = new int[image.cols];
	}
	for (int i = 0; i < image.rows; i++)
	{

		for (int j = 0; j < image.cols; j++)
		{
			labels[i][j] = 0;
		}
	}
	while (prev_c1 != curr_c1 && prev_c2 != curr_c2) {
		for (int i = 0; i < image.rows; i++) {
			for (int j = 0; j < image.cols; j++) {
				if (curr_c1 > matrix[i][j]) {
					diff_c1 = curr_c1 - matrix[i][j];
				}
				else {
					diff_c1 = matrix[i][j] - curr_c1;
				}
				if (curr_c2 > matrix[i][j]) {
					diff_c2 = curr_c2 - matrix[i][j];
				}
				else {
					diff_c2 = matrix[i][j] - curr_c2;
				}
				if (diff_c1 < diff_c2) {
					sum_c1 = sum_c1 + matrix[i][j];
					count_c1++;
					labels[i][j] = 2;
				}
				else if (diff_c2 <= diff_c1) {
					sum_c2 = sum_c2 + matrix[i][j];
					count_c2++;
					labels[i][j] = 3;
				}

			}
		}
		prev_c1 = curr_c1;
		prev_c2 = curr_c2;
		if (count_c1 != 0) {
			avg_c1 = sum_c1 / count_c1;
		}
		if (count_c2 != 0) {
			avg_c2 = sum_c2 / count_c2;
		}

		curr_c1 = avg_c1;
		curr_c2 = avg_c2;


	}

	//for (int i = 0; i < image.rows; i++)
	//{
	//	for (int j = 0; j < image.cols; j++)
	//	{
	//		cout << labels[i][j] << "  ";
	//	}
	//	//cout << endl;
	//}
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			if (curr_c1 < curr_c2) {
				if (labels[i][j] == 2) {
					matrix[i][j] = 255;
				}
				else if (labels[i][j] == 3) {
					matrix[i][j] = 0;
				}
			}
			else if (curr_c2 < curr_c1) {
				if (labels[i][j] == 2) {
					matrix[i][j] = 0;
				}
				else if (labels[i][j] == 3) {
					matrix[i][j] == 255;
				}
			}
		}
	}
	//}
	//for (int i = 0; i < image.rows; i++)
	//{
	//	for (int j = 0; j < image.cols; j++)
	//	{
	//		cout << matrix[i][j] << "  ";
	//	}
	//	//cout << endl;
	//}

	//for (int i = 0; i < image.rows; i++) {
	//	for (int j = 0; j < image.cols; j++)
	//		image.at<float>(i, j) = matrix[i][j];

	//}
	//imshow("Display Window", image);
	//waitKey(0);
	cout<<<<"Dice Cofficient: "<<dicecoffiecient(matrix, image.rows, image.cols)<<endl;

	
}