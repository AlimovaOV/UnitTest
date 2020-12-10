#include <vector>
#include <iterator>
#include <utility>
#include <iostream>     
#include <sstream> 

#define EPS 1E-05

using namespace std;
typedef pair<double, double> point;
typedef vector < pair< point, point > > vec;
typedef vector < double> lvec;

bool operator == (lvec a, lvec b) {
    if (a.size() == b.size()) {
        auto j = b.begin();
        for (auto i = a.begin(); (i != a.end()); i++) {
            if (!(abs(*i - *(j++)) < EPS)) return false;
        }
        return true;
    }
    else return false;
}
/*
bool operator == (vec a, vec b) {
    if (a.size() == b.size()) {
        auto j = b.begin();
        for (auto i = a.begin(); (i != a.end()); i++) {
            if ((*i).first.first - (*j).first.first > EPS) return false;
            else if ((*i).first.second - (*j).first.second > EPS) return false;
            else if ((*i).second.first - (*j).second.first > EPS) return false;
            else if ((*i).second.second - (*j).second.second > EPS) return false;
            else j++;
        }
        return true;
    }
    else return false;
}
*/
vec create(stringstream& lcin) {
    vec rez;
    while (!lcin.eof()) {
        float x1, y1, x2, y2;
        lcin >> x1 >> y1 >> x2 >> y2;
        rez.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
    }
    return rez;
}
lvec lenght_vec(vec a) {
    lvec rez;
    double r;
    for (auto i = a.begin(); i != a.end(); i++) {
        r = sqrt(pow((*i).first.first - (*i).second.first, 2) + pow((*i).first.second - (*i).second.second, 2));
        //rez.push_back( (float) ( (int)(r * 100000)) /100000  );
        rez.push_back(r);
    }
    return rez;
}

int main()
{
    int k;
    cin >> k;
    stringstream ss;
    int a, b, c, d;
    for (int i = 0; i < k - 1; i++) {
        cin >> a >> b >> c >> d;  // вводим координаты начала и конца
                                  // отрезка с клавиатуры
                                  // формируем поток ввода для функции
        ss << a << ' ' << b << ' ' << c << ' ' << d << ' ';
    }
                                // т.к в функции будем считывать поток до конца eof(),    
                                // после последнего набора пробел не
                                // нужен(соответственно, цикл до k-1)
    cin >> a >> b >> c >> d;
    ss << a << ' ' << b << ' ' << c << ' ' << d;
    vec t = create(ss);
    for (int i = 0; i < k; i++) {
        cout << t[i].first.first << " " << t[i].first.second << " ";
        cout << t[i].second.first << " " << t[i].second.second << endl;
    }
    return 0;
}
