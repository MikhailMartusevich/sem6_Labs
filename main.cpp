#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct Node {
    std::string data;
    Node *next;
};

class List {
public:
    Node *head;
    Node *tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void add_node(std::string value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
            // tail->next = temp;
            // tail = tail->next;
        }
    }

    void delete_node(std::string value) {
        Node *curr = head;
        Node *prev = nullptr;
        
        while (curr != nullptr) {
            if (curr->data == value) {
                if (prev == nullptr) {
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
            }
            prev = curr;
            curr = curr->next;
        }

        delete curr;
    }

    bool Find(std::string value) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void Show() {
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

double s_pow(double a, int power) {
    if (power == 0) { 
        return 1;
    }
    if (power % 2 == 0) {
        return s_pow(a * a, power / 2);
    }

    return a * s_pow(a, power - 1);
}

int m = 0;
std::vector<List> hash_table;

int hash(std::string S) {
    long p = 1000000007; int x = 263;
    long long result = 0;

    for (int i = 0; i < S.size(); i++) {
        result += (int(S[i]) * static_cast<long long>(s_pow(x, i))) % p;
    }
    result = ((result % p) + p) % p;
    
    return result % m;
}

void Add(std::string S) {
    int hash_index = hash(S);
    if (!hash_table[hash_index].Find(S))
        hash_table[hash_index].add_node(S);
}   

void Del(std::string S) {
    int hash_index = hash(S);
    hash_table[hash_index].delete_node(S);
}

void Find(std::string S) {
    int hash_index = hash(S);
    bool contains = hash_table[hash_index].Find(S);

    if (contains)
        std::cout << "yes" << std::endl;
    else 
        std::cout << "no" << std::endl;
}

void Check(int i) {

    hash_table[i].Show();

    std::cout << std::endl;
}

int main() {
    int n;
    std::vector<std::pair<std::string, std::string>> commands;

    std::cin >> m;
    hash_table.resize(m);

    std::cin >> n;

    std::string action, str;
    
    for (size_t i = 0; i < n; i++) {
        std::cin >> action >> str;
        commands.push_back(std::make_pair(action, str));
    }

    for (size_t i = 0; i < commands.size(); i++) {
        if (commands[i].first == "add")
            Add(commands[i].second);
        else if (commands[i].first == "del")
            Del(commands[i].second);
        else if (commands[i].first == "find")
            Find(commands[i].second);
        else 
            Check(std::stoi(commands[i].second));
    }

    return 0;
}