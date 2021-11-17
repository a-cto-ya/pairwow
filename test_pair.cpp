#include <iostream>
#include <vector>
#include <algorithm>
#include<ctime>

using namespace std;

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair() {
    }

    Pair(const T1 _first, const T2 _second) {
        first = _first;
        second = _second;
    }

    Pair(const Pair& copied) {
        first = copied.first;
        second = copied.second;
    }

    Pair& operator=(const Pair& copied) {
        first = copied.first;
        second = copied.second;
        return(*this);
    }

    ~Pair() {
    }

    bool operator<(const Pair& other) const {
       if (first == other.first) {
            return(second < other.second);
       } else {
           return(first < other.first);
       }
    }
};

template<typename T>
void mySort(vector<T>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int im = i;
        for (int j = i; j < n; ++j) {
            if (a[j] < a[im]) im = j;
        }
        T t = a[i];
        a[i] = a[im];
        a[im] = a[i];
    }
}

int main() {
    srand(time(NULL));
    int n = 10 + rand() % 10;
    vector<pair<int, double> > a(n);
    vector<Pair<int, double> > b(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = rand() % 100;
        a[i].second = 0.5 + rand() % 100;
        b[i].first = a[i].first;
        b[i].second = a[i].second;
    }
    sort(a.begin(), a.end());
    mySort(b);
    for (int i = 0; i < n; ++i) {
        cout << a[i].first << " " << a[i].second << " " << b[i].first << " " << b[i].second << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first) {
            cout << "a[" << i << "].first != b[" << i << "].first: " << a[i].first << " != " << b[i].first << endl;
        }
        if (a[i].second != b[i].second) {
            cout << "a[" << i << "].second != b[" << i << "].second: " << a[i].second << " != " << b[i].second << endl;
        }
    }
}
