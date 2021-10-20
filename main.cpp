#include <iostream>
#include <vector>
#include <ios>

std::pair<int, int> partition3(std::vector<int> &v, int l, int r) {
    int lt = l;
    int gt = r;
    int pivot = v[l];

    int i = l;
    while (i <= gt) {
        if (v[i] < pivot) {
            std::swap(v[lt], v[i]);
            lt += 1;
            i += 1;
        } else if (v[i] > pivot) {
            std::swap(v[gt], v[i]);
            gt -= 1;
        } else i += 1;
    }

    return std::make_pair(lt, gt);
}

void quicksort(std::vector<int> &v, int l, int r) {
    std::pair<int, int> m;
    while (l < r) {
        m = partition3(v, l, r);
        quicksort(v, l, m.first - 1);
        l = m.second + 1;
    }
}

int search_bigequal(std::vector<int> &v, int l, int r, int value) {
    if (l == r) {
        return value >= v[l] ? (l + 1) : 0;
    }
    int m = (l + r) / 2;

    if (value < v[m]) 
        return search_bigequal(v, l, m, value);

    int ret = search_bigequal(v, m+1, r, value);
    return ret == 0 ? m + 1: ret;
}

int search_big(std::vector<int> &v, int l, int r, int value) {
    if (l == r) {
        return value > v[l] ? (l + 1) : 0;
    }

    int m = (l + r) / 2;

    if (value <= v[m]) 
        return search_big(v, l, m, value);

    int ret = search_big(v, m+1, r, value);
    return ret == 0 ? m + 1 : ret;
}

std::vector<int> answer(std::vector<int> &s, std::vector<int> &e, std::vector<int> &p) {
    quicksort(s, 0, s.size()-1);
    quicksort(e, 0, e.size()-1);
    int n, m;
    std::vector<int> res;

    for (size_t i = 0; i < p.size(); i++) {
        n = 0; m = 0;
        n = search_bigequal(s, 0, s.size() - 1, p[i]);
        m = search_big(e, 0, e.size() - 1, p[i]);
        res.push_back(n - m);
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n , m;
    std::vector<int> s;
    std::vector<int> e;
    std::vector<int> p;

    std::cin >> n >> m;

    int start, end;
    for (size_t i = 0; i < n; i++) {
        std::cin >> start >> end;
        s.push_back(start);
        e.push_back(end);
    }
    
    int point;
    for (size_t i = 0; i < m; i++) {
        std::cin >> point;
        p.push_back(point);
    }

    std::vector<int> result = answer(s, e, p);
    
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}