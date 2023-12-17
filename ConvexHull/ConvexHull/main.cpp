#include <iostream>
#include <chrono>
#include "ConvexHull.h"

void print(Point& p) {
	std::cout << "(" << p.x << ", " << p.y << ")";
}

void print(std::vector<Point>& S) {
	for (int i = 0; i < S.size(); i++) {
		print(S[i]);
		std::cout << " ";
	}
	std::cout << std::endl;
}

bool isSame(std::vector<Point>& S, std::vector<Point>& T) {
	if (S.size() != T.size()) {
		return false;
	}
	for (int i = 0; i < S.size(); i++) {
		if (!(S[i] == T[i])) {
			return false;
		}
	}
	return true;
}

bool isSame(std::vector<std::vector<Point>>& S) {
	for (int i = 1; i < S.size(); i++) {
		if (!isSame(S[0], S[i])) {
			return false;
		}
	}
	return true;
}

bool inVector(std::vector<Point>& S, Point& p) {
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == p) {
			return true;
		}
	}
	return false;
}

void addOne(Point& p, int limit) {
	if (p.x < limit && p.y == limit) {
		p.x++;
		p.y = -limit;
	}
	else {
		p.y++;
	}
}

bool addOne(std::vector<Point>& S, int limit) {
	bool flag = true;
	addOne(S[0], limit);
	int i = 0;
	while (true) {
		if (S[i].x == limit && S[i].y == limit + 1) {
			S[i].x = -limit;
			S[i].y = -limit - 1;
			i++;
			if (i == S.size()) {
				flag = false;
				break;
			}
			else {
				addOne(S[i], limit);
			}
		}
		else {
			break;
		}
	}
	return flag;
}

void test(int limit, int n) {
	long long int sum = 0;
	for (int i = 0; i <= n; i++) {
		long long int product = 1;
		for (int j = 0; j < i; j++) {
			product *= pow(2 * limit + 1, 2) - j;
		}
		sum += product;
	}
	long long int count = 0;
	double rate;
	ConvexHull CH;
	Point p;
	p.x = -limit;
	p.y = -limit - 1;
	std::vector<Point> S(n, p);
	bool flag1 = true;
	while (flag1) {
		std::vector<Point> T;
		bool flag2 = true;
		int digit = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (S[i].x != -limit || S[i].y != -limit - 1) {
				digit = i;
				break;
			}
		}
		for (int i = 0; i < digit + 1; i++) {
			if (S[i].x != -limit || S[i].y != -limit - 1) {
				if (!inVector(T, S[i])) {
					T.push_back(S[i]);
				}
				else {
					flag2 = false;
					break;
				}
			}
			else {
				flag2 = false;
				break;
			}
		}
		if (flag2) {
			std::vector<std::vector<Point>> convexHull;
			convexHull.push_back(CH.extremePoint(T));
			convexHull.push_back(CH.extremeEdge(T));
			convexHull.push_back(CH.incrementalConstruction(T));
			convexHull.push_back(CH.JarvisMarch(T));
			convexHull.push_back(CH.GrahamScan(T));
			convexHull.push_back(CH.divideAndConquer1(T));
			convexHull.push_back(CH.divideAndConquer2(T));
			if (!isSame(convexHull)) {
				print(T);
				std::cin.get();
			}
			count++;
			if (count % 10000 == 0) {
				rate = (double)count / (double)sum * 100;
				std::cout << rate << std::endl;
			}
		}
		flag1 = addOne(S, limit);
	}
	rate = (double)count / (double)sum * 100;
	std::cout << rate << std::endl;
}

std::vector<Point> generatePoints() {
	Point p;
	std::vector<Point> S;
	p.x = -19; p.y = -51; S.push_back(p);
	p.x = 49; p.y = 25; S.push_back(p);
	p.x = 100; p.y = -86; S.push_back(p);
	p.x = -14; p.y = 32; S.push_back(p);
	p.x = -86; p.y = 95; S.push_back(p);
	p.x = -49; p.y = 36; S.push_back(p);
	p.x = -22; p.y = 7; S.push_back(p);
	p.x = 70; p.y = -30; S.push_back(p);
	p.x = 69; p.y = -49; S.push_back(p);
	p.x = 31; p.y = -74; S.push_back(p);
	p.x = 36; p.y = 48; S.push_back(p);
	p.x = -80; p.y = 30; S.push_back(p);
	p.x = -49; p.y = 21; S.push_back(p);
	p.x = -8; p.y = 95; S.push_back(p);
	p.x = -31; p.y = -39; S.push_back(p);
	p.x = -53; p.y = 73; S.push_back(p);
	p.x = -95; p.y = 12; S.push_back(p);
	p.x = 83; p.y = -41; S.push_back(p);
	p.x = -99; p.y = 68; S.push_back(p);
	p.x = 19; p.y = 73; S.push_back(p);
	p.x = 41; p.y = 47; S.push_back(p);
	p.x = -15; p.y = -56; S.push_back(p);
	p.x = -41; p.y = -8; S.push_back(p);
	p.x = -98; p.y = 80; S.push_back(p);
	p.x = -23; p.y = 40; S.push_back(p);
	p.x = 25; p.y = 71; S.push_back(p);
	p.x = -65; p.y = 32; S.push_back(p);
	p.x = -47; p.y = -89; S.push_back(p);
	p.x = 17; p.y = 0; S.push_back(p);
	p.x = -88; p.y = -62; S.push_back(p);
	p.x = 2; p.y = 92; S.push_back(p);
	p.x = 95; p.y = 18; S.push_back(p);
	p.x = 9; p.y = -96; S.push_back(p);
	p.x = -41; p.y = 56; S.push_back(p);
	p.x = -5; p.y = -88; S.push_back(p);
	p.x = -63; p.y = -67; S.push_back(p);
	p.x = 38; p.y = 12; S.push_back(p);
	p.x = -72; p.y = -84; S.push_back(p);
	p.x = 41; p.y = -18; S.push_back(p);
	p.x = 95; p.y = -13; S.push_back(p);
	p.x = -6; p.y = -91; S.push_back(p);
	p.x = 60; p.y = 19; S.push_back(p);
	p.x = 44; p.y = -19; S.push_back(p);
	p.x = 92; p.y = -74; S.push_back(p);
	p.x = -38; p.y = 65; S.push_back(p);
	p.x = 58; p.y = -19; S.push_back(p);
	p.x = -75; p.y = -4; S.push_back(p);
	p.x = -63; p.y = -42; S.push_back(p);
	p.x = 15; p.y = 74; S.push_back(p);
	p.x = -25; p.y = -29; S.push_back(p);
	p.x = -2; p.y = 11; S.push_back(p);
	p.x = -5; p.y = 84; S.push_back(p);
	p.x = -71; p.y = -61; S.push_back(p);
	p.x = 36; p.y = -35; S.push_back(p);
	p.x = -66; p.y = 14; S.push_back(p);
	p.x = 0; p.y = -32; S.push_back(p);
	p.x = -61; p.y = -62; S.push_back(p);
	p.x = -60; p.y = 18; S.push_back(p);
	p.x = -15; p.y = -68; S.push_back(p);
	p.x = -64; p.y = -14; S.push_back(p);
	p.x = -18; p.y = 91; S.push_back(p);
	p.x = -75; p.y = 35; S.push_back(p);
	p.x = 83; p.y = 21; S.push_back(p);
	p.x = -56; p.y = -65; S.push_back(p);
	p.x = 19; p.y = -31; S.push_back(p);
	p.x = -11; p.y = 11; S.push_back(p);
	p.x = -44; p.y = -10; S.push_back(p);
	p.x = 89; p.y = 45; S.push_back(p);
	p.x = -74; p.y = 6; S.push_back(p);
	p.x = 1; p.y = -1; S.push_back(p);
	p.x = 16; p.y = -65; S.push_back(p);
	p.x = 35; p.y = 99; S.push_back(p);
	p.x = -80; p.y = -7; S.push_back(p);
	p.x = 18; p.y = -41; S.push_back(p);
	p.x = -45; p.y = -42; S.push_back(p);
	p.x = 77; p.y = -33; S.push_back(p);
	p.x = 41; p.y = 11; S.push_back(p);
	p.x = 35; p.y = 87; S.push_back(p);
	p.x = -57; p.y = -8; S.push_back(p);
	p.x = -93; p.y = -28; S.push_back(p);
	p.x = -41; p.y = 37; S.push_back(p);
	p.x = -39; p.y = 96; S.push_back(p);
	p.x = 17; p.y = -24; S.push_back(p);
	p.x = -99; p.y = -38; S.push_back(p);
	p.x = -60; p.y = 56; S.push_back(p);
	p.x = -76; p.y = -98; S.push_back(p);
	p.x = 97; p.y = -32; S.push_back(p);
	p.x = 2; p.y = -86; S.push_back(p);
	p.x = -46; p.y = -63; S.push_back(p);
	p.x = 48; p.y = -26; S.push_back(p);
	p.x = -49; p.y = 75; S.push_back(p);
	p.x = 91; p.y = 43; S.push_back(p);
	p.x = 64; p.y = 71; S.push_back(p);
	p.x = 86; p.y = 86; S.push_back(p);
	p.x = 87; p.y = -47; S.push_back(p);
	p.x = 10; p.y = 27; S.push_back(p);
	p.x = -10; p.y = -15; S.push_back(p);
	p.x = 82; p.y = -24; S.push_back(p);
	p.x = -90; p.y = -85; S.push_back(p);
	return S;
}

void test() {
	ConvexHull CH;
	std::vector<Point> S = generatePoints();
	std::vector<std::vector<Point>> convexHull;
	convexHull.push_back(CH.extremePoint(S));
	convexHull.push_back(CH.extremeEdge(S));
	convexHull.push_back(CH.incrementalConstruction(S));
	convexHull.push_back(CH.JarvisMarch(S));
	convexHull.push_back(CH.GrahamScan(S));
	convexHull.push_back(CH.divideAndConquer1(S));
	convexHull.push_back(CH.divideAndConquer2(S));
	if (!isSame(convexHull)) {
		print(S);
		std::cin.get();
	}
}

int main() {
	auto start = std::chrono::high_resolution_clock::now();
	test(2, 5);
	//test();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << duration.count() << std::endl;
	return 0;
}
