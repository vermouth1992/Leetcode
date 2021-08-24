/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (18.04%)
 * Total Accepted:    195.6K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given an array of points where points[i] = [xi, yi] represents a point on
 * the X-Y plane, return the maximum number of points that lie on the same
 * straight line.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= points.length <= 300
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * All the points are unique.
 * 
 * 
 */

#include "common.hpp"


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction {
    // a fraction class
public:
    Fraction(const Fraction &f) {
        num = f.num;
        den = f.den;
    }

    Fraction(int den_, int num_) {
        // reduce to the canonical form. If negative, make num positive and den negative.
        // if zero, make num == 1
        if (num_ == 0) {
            // vertical line
            den = 2;
            num = 0;
        } else if (den_ == 0) {
            den = 0;
            num = 1;
        } else {
            if (den_ < 0) {
                if (num_ < 0) {
                    den_ = -den_;
                    num_ = -num_;
                    // all positive reduce
                    int g = gcd(den_, num_);
                    den = den_ / g;
                    num = num_ / g;
                } else {
                    // reduce
                    int g = gcd(-den_, num_);
                    den = den_ / g;
                    num = num_ / g;
                }
            } else {
                if (num_ < 0) {
                    den_ = -den_;
                    num_ = -num_;
                    // reduce
                    int g = gcd(-den_, num_);
                    den = den_ / g;
                    num = num_ / g;
                } else {
                    // reduce
                    int g = gcd(den_, num_);
                    den = den_ / g;
                    num = num_ / g;
                }       
            }
        }
    }

    bool is_infinite() const {
        return num == 0;
    }

    bool operator<(const Fraction &other) const {
        // vertical line
        if (other.num == 0) {
            return num != 0;
        } else if (num == 0) {
            return false;
        }
        return (den * other.num) < (other.den * num);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.den << " / " << f.num;
        return os;
    }
    
private:
    int den;
    int num;
};


struct Point {
    Point(int x, int y): x(x), y(y) {

    }

    bool operator<(const Point &p2) const {
        if (x < p2.x) return true;
        if (x > p2.x) return false;
        if (y < p2.y) return true;
        if (y > p2.y) return false;
        return false;
    }

    int x;
    int y;

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }

};

class Line {
public:
    Line(const Point &p1, const Point &p2): 
        slope(p1.y - p2.y, p1.x - p2.x),
        intercept(p2.y * p1.x - p1.y * p2.x, p1.x - p2.x) {
        if (slope.is_infinite()) {
            intercept = Fraction(p1.x, 1);
        }
    }

    bool operator<(const Line &other) const {
        if (slope < other.slope) return true;
        if (other.slope < slope) return false;
        if (intercept < other.intercept) return true;
        if (other.intercept < intercept) return false;
        return false;
    }

    friend ostream& operator<<(ostream& os, const Line& l) {
        os << l.slope << " - " << l.intercept;
        return os;
    }

private:
    Fraction slope;
    Fraction intercept;
};


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 1;
        // enumerate all the lines
        std::map<Line, std::set<Point>> enumeration;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                Point p1(points[i][0], points[i][1]);
                Point p2(points[j][0], points[j][1]);
                Line l(p1, p2);
                if (enumeration.find(l) == enumeration.end()) {
                    enumeration[l] = std::set<Point>();
                }
                enumeration.at(l).insert(p1);
                enumeration.at(l).insert(p2);

                std::cout << l << p1 << p2 << std::endl;
            }
        }

        for (auto &it : enumeration) {
            std::cout << it.first << std::endl;
            for (auto &p: it.second) {
                std::cout << p;
            }
            std::cout << std::endl;
        }

        int max_num = 0;
        for (auto &it : enumeration) {
            if (it.second.size() > max_num) {
                max_num = it.second.size();
            }
        }
        return max_num;
    }
};


int main() {
    std::vector<vector<int>> points {{3, 3}, {1, 4}, {1, 1}, {2, 1}, {2, 2}};
    std::cout << Solution().maxPoints(points) << std::endl;
}