#include <iostream>
#include <string>
#include <vector>

long p = 1000000007; int x = 263;
int m;

long double s_pow(long long a, int power) {
    if (power == 0) { 
        return 1;
    }
    if (power % 2 == 0) {
        return static_cast<long long>(s_pow((a * a)%p, power / 2)) % p;
    }

    return static_cast<long long>(a % p * s_pow(a % p, power - 1)) % p;
}

int hash(std::string S) {
    long long result = 0;

    for (int i = 0; i < S.size(); i++) {
        result += (int(S[i]) * static_cast<long long>(s_pow(x, i)) % p) % p;
        result %= p;
    }
   
    return result % m;
}


int main() {
    std::vector<int> window_indices;
    std::string pattern, text;
    std::cin >> pattern;
    std::cin >> text;

    m = pattern.size();

    long long pattern_hash = hash(pattern);
    long long last = static_cast<long long>(s_pow(x, pattern.size() - 1)) % p;

    std::string window = text.substr(text.size() - pattern.size(), pattern.size());
    long long window_hash = hash(window);

    if (window_hash == pattern_hash) {
        if (pattern.compare(window) == 0)
            window_indices.push_back(text.size() - pattern.size());
    }

    long long prev;

    for (int i = text.size() - pattern.size() - 1; i >= 0; i--) {
        window = text.substr(i, pattern.size());
        
        prev = (int(text[i + pattern.size()]) * last);
        // prev %= p;

        long long tmp = (window_hash - prev);
        tmp %= p;

        if (tmp < 0)
            tmp += p;
        
        window_hash = (tmp * x + int(window[0]));
        window_hash %= m;

        if (window_hash == pattern_hash) {
            if (pattern.compare(window) == 0)
                window_indices.push_back(i);
        }

    }

    for (int i = window_indices.size() - 1; i >= 0; i--) {
        std::cout << window_indices[i] << " "; 
    }
    std::cout << std::endl;


    return 0;
}