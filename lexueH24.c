#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 105

const double eps = 1e-12;
const double inf = 1e9;

int dcmp(double x)
{
    if (x <= eps && x >= -eps) return 0;
    return (x > 0) ? 1 : -1;
}

struct Vector
{
    double x, y;
};

struct Vector create_vector(double X, double Y)
{
    struct Vector vec;
    vec.x = X;
    vec.y = Y;
    return vec;
}

int vector_compare(const void *a, const void *b)
{
    struct Vector *vec1 = (struct Vector *)a;
    struct Vector *vec2 = (struct Vector *)b;
    if (vec1->x < vec2->x - eps) return -1;
    else if (vec1->x > vec2->x + eps) return 1;
    else
    {
        if (vec1->y < vec2->y - eps) return -1;
        else if (vec1->y > vec2->y + eps) return 1;
        else return 0;
    }
}

void read_vector(struct Vector *vec)
{
    scanf("%lf%lf", &(vec->x), &(vec->y));
}

typedef struct Vector Point;

struct Line
{
    Point p, q;
};

struct Line create_line(Point P, Point Q)
{
    struct Line ln;
    ln.p = P;
    ln.q = Q;
    return ln;
}

struct Vector vector_add(struct Vector a, struct Vector b)
{
    return create_vector(a.x + b.x, a.y + b.y);
}

struct Vector vector_subtract(struct Vector a, struct Vector b)
{
    return create_vector(a.x - b.x, a.y - b.y);
}

struct Vector vector_multiply(struct Vector a, double b)
{
    return create_vector(a.x * b, a.y * b);
}

double Cross(struct Vector a, struct Vector b)
{
    return a.x * b.y - a.y * b.x;
}

int n, LSH;
double ans;
double lsh[N * N * 10];
Point seg[N];
struct Line line[N][4];

int ins(Point A, Point B, Point C, Point D)
{
    struct Vector v1 = vector_subtract(B, A);
    struct Vector v2 = vector_subtract(D, C);
    double d1 = Cross(vector_subtract(C, A), v1);
    double d2 = Cross(vector_subtract(D, A), v1);
    double d3 = Cross(vector_subtract(A, C), v2);
    double d4 = Cross(vector_subtract(B, C), v2);

    return (dcmp(d1) * dcmp(d2) < 0 && dcmp(d3) * dcmp(d4) < 0);
}

Point GLI(Point P, struct Vector v, Point Q, struct Vector w)
{
    struct Vector u = vector_subtract(P, Q);
    double t = Cross(w, u) / Cross(v, w);
    return vector_add(P, vector_multiply(v, t));
}

int compare_doubles(const void *a, const void *b)
{
    double diff = (*(double *)a) - (*(double *)b);
    if (diff < -eps) return -1;
    else if (diff > eps) return 1;
    else return 0;
}

void unique_doubles(double *arr, int *size)
{
    int j = 1;
    for (int i = 1; i < *size; ++i)
    {
        if (dcmp(arr[i + 1] - arr[j]) != 0)
            arr[++j] = arr[i + 1];
    }
    *size = j;
}

double Plus(double x)
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dcmp(line[i][1].p.x - line[i][1].q.x) == 0 && dcmp(x - line[i][1].p.x) == 0)
            continue;
        double Min = inf, Max = -inf;
        for (int j = 1; j <= 3; ++j)
        {
            if (x < fmin(line[i][j].p.x, line[i][j].q.x) || x > fmax(line[i][j].p.x, line[i][j].q.x))
                continue;
            if (dcmp(line[i][j].p.x - line[i][j].q.x) == 0) continue;
            Point P = GLI(line[i][j].p, vector_subtract(line[i][j].q, line[i][j].p), create_vector(x, -inf), create_vector(0, inf * 2));
            if (P.y < Min) Min = P.y;
            if (P.y > Max) Max = P.y;
        }
        if (Max - Min > eps) seg[cnt++] = create_vector(Min, Max);
    }
    if (cnt == 0) return 0.0;
    qsort(seg, cnt, sizeof(Point), vector_compare);
    double l = seg[0].x, r = seg[0].y, sum = 0.0;
    for (int i = 1; i < cnt; ++i)
    {
        if (seg[i].x - r > eps)
        {
            sum += r - l;
            l = seg[i].x;
            r = seg[i].y;
        }
        else if (seg[i].y - r > eps)
        {
            r = seg[i].y;
        }
    }
    sum += r - l;
    return sum;
}

double Minus(double x)
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dcmp(line[i][2].p.x - line[i][2].q.x) == 0 && dcmp(x - line[i][2].p.x) == 0)
            continue;
        double Min = inf, Max = -inf;
        for (int j = 1; j <= 3; ++j)
        {
            if (x < fmin(line[i][j].p.x, line[i][j].q.x) || x > fmax(line[i][j].p.x, line[i][j].q.x))
                continue;
            if (dcmp(line[i][j].p.x - line[i][j].q.x) == 0) continue;
            Point P = GLI(line[i][j].p, vector_subtract(line[i][j].q, line[i][j].p), create_vector(x, -inf), create_vector(0, inf * 2));
            if (P.y < Min) Min = P.y;
            if (P.y > Max) Max = P.y;
        }
        if (Max - Min > eps) seg[cnt++] = create_vector(Min, Max);
    }
    if (cnt == 0) return 0.0;
    qsort(seg, cnt, sizeof(Point), vector_compare);
    double l = seg[0].x, r = seg[0].y, sum = 0.0;
    for (int i = 1; i < cnt; ++i)
    {
        if (seg[i].x - r > eps)
        {
            sum += r - l;
            l = seg[i].x;
            r = seg[i].y;
        }
        else if (seg[i].y - r > eps)
        {
            r = seg[i].y;
        }
    }
    sum += r - l;
    return sum;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        Point A, B, C;
        read_vector(&A);
        read_vector(&B);
        read_vector(&C);
        if (A.x > B.x)
        {
            Point temp = A;
            A = B;
            B = temp;
        }
        if (B.x > C.x)
        {
            Point temp = B;
            B = C;
            C = temp;
        }
        if (A.x > B.x)
        {
            Point temp = A;
            A = B;
            B = temp;
        }
        lsh[++LSH] = A.x;
        lsh[++LSH] = B.x;
        lsh[++LSH] = C.x;
        line[i][1] = create_line(A, B);
        line[i][2] = create_line(B, C);
        line[i][3] = create_line(A, C);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            for (int k = i + 1; k <= n; ++k)
            {
                for (int l = 1; l <= 3; ++l)
                {
                    Point A = line[i][j].p;
                    Point B = line[i][j].q;
                    Point C = line[k][l].p;
                    Point D = line[k][l].q;
                    if (ins(A, B, C, D))
                    {
                        Point q = GLI(A, vector_subtract(B, A), C, vector_subtract(D, C));
                        lsh[++LSH] = q.x;
                    }
                }
            }
        }
    }
    qsort(lsh + 1, LSH, sizeof(double), compare_doubles);
    unique_doubles(lsh, &LSH);
    double last = 0.0, now;
    for (int i = 1; i <= LSH; ++i)
    {
        now = Plus(lsh[i]);
        if (i > 1)
        {
            ans += (now + last) * (lsh[i] - lsh[i - 1]) / 2.0;
        }
        last = Minus(lsh[i]);
    }
    printf("%.2lf\n", ans - eps);
    return 0;
}