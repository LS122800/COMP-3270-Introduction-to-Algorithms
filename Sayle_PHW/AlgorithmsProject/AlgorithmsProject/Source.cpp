#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
#include <vector>
#include <random>
#include <chrono>

#pragma region HelperMethods
int max(int a, int b) {
	if (a > b)
	{
		return a;
	}
	else {
		return b;
	}
}

int max3(int a, int b, int c) {
	int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
	return max;
}
#pragma endregion

#pragma region Algorithms
int Algorithm_1(int X[], int size) {
	int maxSoFar = 0;
	int sum = 0;
	int P = 0;
	int Q = size - 1;
	for (int L = P; L <= Q; L++) {
		for (int U = L; U <= Q; U++) {
			sum = 0;
			for (int I = L; I <= U; I++) {
				sum = sum + X[I];
			}
			maxSoFar = max(maxSoFar, sum);
		}
	}
	return maxSoFar;
}

int Algorithm_2(int X[], int size) {
	int maxSoFar = 0;
	int P = 0;
	int Q = size - 1;
	for (int L = P; L <= Q; L++) {
		int sum = 0;
		for (int U = L; U <= Q; U++) {
			sum = sum + X[U];
			maxSoFar = max(maxSoFar, sum);
		}
	}
	return maxSoFar;
}

int MaxSum(int X[], int L, int U) {
	if (L > U) {
		return 0;
	}	
	if (L == U) {
		return max(0, X[0]);
	}
	int M = (L + U) / 2;
	//max crossing to left
	int sum = 0;
	int maxToLeft = 0;
	for (int I = M; I >= L; I--) {
		sum = sum + X[I];
		maxToLeft = max(maxToLeft, sum);
	}
	//max crossing to right
	sum = 0;
	int maxToRight = 0;
	for (int I = M + 1; I < U; I++) {
		sum = sum + X[I];
		maxToRight = max(maxToRight, sum);
	}
	int maxCrossing = maxToLeft + maxToRight;
	int maxInA = MaxSum(X, L, M);
	int maxInB = MaxSum(X, M + 1, U);
	return max3(maxCrossing, maxInA, maxInB);
}

int Algorithm_4(int X[], int size) {
	int maxSoFar = 0;
	int maxEndingHere = 0;
	int P = 0;
	int Q = size - 1;
	for (int I = P; I <= Q; I++) {
		maxEndingHere = max(0, maxEndingHere + X[I]);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
	return maxSoFar;
}
#pragma endregion

void inputFile() {
	//Create a 10 int long array from input file
	//Much of this code is from https://www.geeksforgeeks.org/how-to-input-a-comma-separated-string-in-c/
	int fileArr[10];
	std::vector<int> v;
	std::ifstream inputFile{ "C:/AlgoFiles/test.txt" };

	if (inputFile.is_open()) {
		std::string num;
		std::getline(inputFile, num);
		std::stringstream ss(num);
		for (int i; ss >> i;) {
			v.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		fileArr[i] = v[i];
	}

	int a1Res = Algorithm_1(fileArr, std::size(fileArr));
	int a2Res = Algorithm_2(fileArr, std::size(fileArr));
	int a3Res = MaxSum(fileArr, 0, std::size(fileArr));
	int a4Res = Algorithm_4(fileArr, std::size(fileArr));

	//Output results from file input array
	std::cout << "algorithm-1: " << a1Res << std::endl;
	std::cout << "algorithm-2: " << a2Res << std::endl;
	std::cout << "algorithm-3: " << a3Res << std::endl;
	std::cout << "algorithm-4: " << a4Res << std::endl;
}

void FillArray(int arr[], int size) {
	//Fill them with random int values
	//following 3 lines from: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(-10, 10);
	for (int i = 0; i < size; i++) {
		arr[i] = distr(gen);
	}
}

void MeasureTime(int arr[], int size, int matrix[][8], int row) {
	using namespace std::chrono;

	int totalTime = 0;
	int averageTime;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(t2 - t1);

	for (int i = 0; i < 100; i++) {
		t1 = high_resolution_clock::now();
		Algorithm_1(arr, size);
		t2 = std::chrono::high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1);
		totalTime = totalTime + duration.count();
	}
	
	averageTime = totalTime / 100;
	matrix[row][0] = averageTime;
	totalTime = 0;

	for (int i = 0; i < 100; i++) {
		t1 = high_resolution_clock::now();
		Algorithm_2(arr, size);
		t2 = std::chrono::high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1);
		totalTime = totalTime + duration.count();
	}

	averageTime = totalTime / 100;
	matrix[row][1] = averageTime;
	totalTime = 0;

	for (int i = 0; i < 100; i++) {
		t1 = high_resolution_clock::now();
		MaxSum(arr, 0, size);
		t2 = std::chrono::high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1);
		totalTime = totalTime + duration.count();
	}

	averageTime = totalTime / 100;
	matrix[row][2] = averageTime;
	totalTime = 0;

	for (int i = 0; i < 100; i++) {
		t1 = high_resolution_clock::now();
		Algorithm_4(arr, size);
		t2 = std::chrono::high_resolution_clock::now();
		duration = duration_cast<microseconds>(t2 - t1);
		totalTime = totalTime + duration.count();
	}

	averageTime = totalTime / 100;
	matrix[row][3] = averageTime;
}

float TimeComplexity1(int inputSize) {
	float ret = ((4 * (inputSize * inputSize * inputSize) + 15 * (inputSize * inputSize) + 17 * inputSize) / 6) + 2;
	ret = ret / 1700;
	return(ret);
}

float TimeComplexity2(int inputSize) {
	float ret = ((7 * (inputSize * inputSize) + 15 * inputSize) / 2) + 4;
	ret = ret / 400;
	return(ret);
}

float TimeComplexity3(int inputSize) {
	float ret = 2 * inputSize * log2(inputSize) + (18 * inputSize);
	ret = ret / 200;
	return(ret);
}

float TimeComplexity4(int inputSize) {
	float ret = (20 * inputSize) + 4;
	ret = ret / 900;
	return(ret);
}

int main() {
	//create an array from a .txt file of comma separated ints and run the algorithms on that array;
	inputFile();
	//Create 19 int arrays of length 10,15,...,95,100 and fill them with random numbers
	int A1[10];
	FillArray(A1, std::size(A1));
	int A2[15];
	FillArray(A2, std::size(A2));
	int A3[20];
	FillArray(A3, std::size(A3));
	int A4[25];
	FillArray(A4, std::size(A4));
	int A5[30];
	FillArray(A5, std::size(A5));
	int A6[35];
	FillArray(A6, std::size(A6));
	int A7[40];
	FillArray(A7, std::size(A7));
	int A8[45];
	FillArray(A8, std::size(A8));
	int A9[50];
	FillArray(A9, std::size(A9));
	int A10[55];
	FillArray(A10, std::size(A10));
	int A11[60];
	FillArray(A11, std::size(A11));
	int A12[65];
	FillArray(A12, std::size(A12));
	int A13[70];
	FillArray(A13, std::size(A13));
	int A14[75];
	FillArray(A14, std::size(A14));
	int A15[80];
	FillArray(A15, std::size(A15));
	int A16[85];
	FillArray(A16, std::size(A16));
	int A17[90];
	FillArray(A17, std::size(A17));
	int A18[95];
	FillArray(A18, std::size(A18));
	int A19[100];
	FillArray(A19, std::size(A19));

	int timeMatrix[19][8];

	MeasureTime(A1, std::size(A1), timeMatrix, 0);
	MeasureTime(A2, std::size(A2), timeMatrix, 1);
	MeasureTime(A3, std::size(A3), timeMatrix, 2);
	MeasureTime(A4, std::size(A4), timeMatrix, 3);
	MeasureTime(A5, std::size(A5), timeMatrix, 4);
	MeasureTime(A6, std::size(A6), timeMatrix, 5);
	MeasureTime(A7, std::size(A7), timeMatrix, 6);
	MeasureTime(A8, std::size(A8), timeMatrix, 7);
	MeasureTime(A9, std::size(A9), timeMatrix, 8);
	MeasureTime(A10, std::size(A10), timeMatrix, 9);
	MeasureTime(A11, std::size(A11), timeMatrix, 10);
	MeasureTime(A12, std::size(A12), timeMatrix, 11);
	MeasureTime(A13, std::size(A13), timeMatrix, 12);
	MeasureTime(A14, std::size(A14), timeMatrix, 13);
	MeasureTime(A15, std::size(A15), timeMatrix, 14);
	MeasureTime(A16, std::size(A16), timeMatrix, 15);
	MeasureTime(A17, std::size(A17), timeMatrix, 16);
	MeasureTime(A18, std::size(A18), timeMatrix, 17);
	MeasureTime(A19, std::size(A19), timeMatrix, 18);

	//T(n) calculations
	int row = -1;
	for (int i = 10; i <= 100; i += 5) {
		row++;
		int t1 = static_cast<int>(ceil(TimeComplexity1(i)));
		timeMatrix[row][4] = t1;
		int t2 = static_cast<int>(ceil(TimeComplexity2(i)));
		timeMatrix[row][5] = t2;
		int t3 = static_cast<int>(ceil(TimeComplexity3(i)));
		timeMatrix[row][6] = t3;
		int t4 = static_cast<int>(ceil(TimeComplexity4(i)));
		timeMatrix[row][7] = t4;
	}

	//output data to file "sayle_phw_output.txt"
	std::ofstream output("sayle_phw_output.txt");
	output << "Algorithm_1 " << "Algorithm_2 " << "Algorithm_3 " << "Algorithm_4 " << std::endl;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 8; j++) {
			output << timeMatrix[i][j] << ", ";
		}
		output << std::endl;
	}
}