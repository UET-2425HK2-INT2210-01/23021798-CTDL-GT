#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;

class Point {
    public:
        float x;
        float y;

        void import()
        {
            cin >> x >> y;
        }
};

class Line {
    public:
        Point first;
        Point second;

        float alpha;
        float beta;

        Line(Point A, Point B) : first(A), second(B) {caculate();}
        void caculate()
        {
            alpha = (first.y - second.y) / (first.x - second.x); 
            beta = first.y - alpha * first.x;
        }
};

int main()
{
    Point A, B, C, D;
    A.import(); B.import(); C.import(); D.import();
    Line AB(A, B);
    Line CD(C, D);

    if (AB.alpha != CD.alpha)
    {
        float x_intersection = (CD.beta - AB.beta) / (AB.alpha - CD.alpha);
        float y_intersection = AB.alpha * x_intersection + AB.beta;
        cout << fixed << setprecision(2) << x_intersection << " " << y_intersection;
    }
    else if (AB.beta == CD.beta) cout << "MANY";
    else cout << "NO";
}