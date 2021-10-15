#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

struct Element {
    char key {0};
    int value {0};
    Element* left {nullptr};
    Element* right {nullptr};
};


struct priorityQueue {
    std::vector<Element> queue;

    Element extractMin() {
        auto it = std::min_element(this->queue.begin(), this->queue.end(), [](const Element &x1, const Element &x2) {return x1.value < x2.value;});
        Element min = *it;
        this->queue.erase(it);
        return min;
    }
    
    void insert(Element elem) {
        this->queue.push_back(elem);
    } 
};

void getCodes(Element head, std::string code, std::map<char, std::string>& codes);

void huffmanEncode(std::string s) {
    std::string encodedS;
    std::map<char, int> m;
    std::map<char, std::string> codes;
    priorityQueue pq;

    // находим частоту символов в строке
    for (size_t i = 0; i < s.size(); i++) {
        if (!m.count(s[i]))
            m.insert(std::make_pair(s[i], 1));
        else
            m[s[i]] += 1;
    }

    if (m.size() == 1) {
        codes.insert(std::make_pair(s[0], "0"));
    } 
    else {

        // кладем пары <символ, частота> в очередь с приоритетом
        for (auto it = m.begin(); it != m.end(); it++) {
            Element elem;
            elem.key = it->first;
            elem.value = it->second;
            elem.left = nullptr;
            elem.right = nullptr;
            pq.insert(elem);
        }
    
        int n = pq.queue.size();
        for (int k = n+1; k <= 2 * n - 1; k++) {
            Element first_min = pq.extractMin();
            Element second_min = pq.extractMin();
    
            Element new_element;
            new_element.key = k + '0';
            new_element.value = first_min.value + second_min.value;
            new_element.left = new Element(first_min);
            new_element.right = new Element(second_min);
    
            pq.insert(new_element);
        }
    
        // for (size_t i = 0; i < pq.queue.size(); i++) {
        //     std::cout << pq.queue[i].key << ": " << pq.queue[i].value << std::endl;
        // }
    
        std::string code = "";
        getCodes(pq.queue[0], code, codes);
    }

    for (size_t i = 0; i < s.size(); i++) {
        encodedS += codes[s[i]];
    }

    std::cout << codes.size() << " " << encodedS.size() << std::endl;

    for (auto it = codes.begin(); it != codes.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    std::cout << encodedS << std::endl;
        
}


void getCodes(Element head, std::string code, std::map<char, std::string>& codes) {
    Element temp = head;
    if (temp.left != nullptr) {
        std::string new_code = code;
        new_code.push_back('0');
        getCodes(*temp.left, new_code, codes);
    }
    
    if (temp.right != nullptr) {
        code.push_back('1');
        getCodes(*temp.right, code, codes);
    }

    if (temp.right == nullptr && temp.left == nullptr)
        codes.emplace(std::make_pair(temp.key, code));
}


int main() {
    std::string s;

    std::cin >> s; 

    huffmanEncode(s);
    
    return 0;
}
