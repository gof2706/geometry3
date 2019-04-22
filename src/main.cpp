#include "geometry.h"
extern float getarea(float r);
extern float getperim(float r);
int main()
{
    int x1, y1, x2, y2;
    float r1, r2, d, flag = 0, s1, s2, perim1, perim2;
    cout << "Input x1, y1, r1:" << endl;
    cin >> x1 >> y1 >> r1;
    cout << endl;
    perim1 = getperim(r1);
    s1 = getarea(r1);
    cout << "Input x2, y2, r2:" << endl;
    cin >> x2 >> y2 >> r2;
    perim2 = getperim(r2);
    s2 = getarea(r2);
    cout << endl;
    d = r1 + r2;
    if ((r1 < r2 || r2 < r1) && x1 == x2 && y1 == y2) {
        flag = 0;
    } else if (r1 == r2 && x1 == x2 && y1 == y2) {
        flag = 1;
    }
    if (d + r1 < r2) {
        flag = 0;
    } else if (((d + r1) == r2) || d + r1 > r2) {
        flag = 1;
    }
    if (d > r1 + r2) {
        flag = 1;
    } else if ((d == r1 + r2) || d < (r1 + r2)) {
        flag = 1;
    }

    cout << "1" << endl;
    printf("circle(%d %d , %.1f)\n", x1, y1, r1);
    printf("perimetr = %.3f\n", perim1);
    printf("area = %.3f\n", s1);
    if (flag == 1) {
        printf("intersects: \n circle \n ");
    }
    cout << "2" << endl;
    printf("circle(%d %d , %.1f)\n", x2, y2, r2);
    printf("perimetr = %.3f\n", perim2);
    printf("area = %.3f\n", s2);
    if (flag == 1) {
        printf("intersects: \n circle \n ");
    }
    system("PAUSE");
    return 0;
}
