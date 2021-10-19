#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>

int cmp(const void * x1, const void * x2) {
    return ( *(int*)x1 - *(int*)x2 );
}
// 0 7 1 -> 0 1 7 -> 1 | 5 10 1 -> 1 5 10 -> 0: 1 - 0 = 1
// 0 7 6 -> 0 6 7 -> 1 | 5 10 6 -> 5 6 10 -> 1: 1 - 1 = 0
// 0 7 11 -> 0 7 11 -> 2 | 5 10 11 -> 5 10 11 -> 2: 2 - 2 = 0

int n_count(std::vector<int> v, int p) {
    v.push_back(p);
    // qsort(&v[0], v.size(), sizeof(int), cmp);
    std::sort(v.begin(), v.end());
    int* pr = static_cast<int*>(std::bsearch(&p, v.data(), v.size(), sizeof(int), cmp));
    return pr - v.data();
}

std::vector<int> count_points(std::vector<int> s, std::vector<int> e, std::vector<int> p) {
    // qsort(&s[0], s.size(), sizeof(int), cmp);
    // qsort(&e[0], e.size(), sizeof(int), cmp);
    
    int n, m;
    std::vector<int> result;

    for (size_t i = 0; i < p.size(); i++) {
        n = 0; m = 0;
        n = n_count(s, p[i]);
        m = n_count(e, p[i]);

        result.push_back(n-m);
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false)
    int n = 0, m = 0;
    std::cin >> n >> m;
    
    int start, end;
    int point;

    std::vector<int> starts;
    std::vector<int> ends;
    std::vector<int> points;
    std::vector<int> result;

    for (size_t i = 0; i < n; i++) {
        std::cin >> start >> end;
        starts.push_back(start);
        ends.push_back(end);
    }

    for (size_t i = 0; i < m; i++) {
        std::cin >> point;
        points.push_back(point);
    }
    
    result = count_points(std::move(starts), std::move(ends), std::move(points));

    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    

    return 0;
}