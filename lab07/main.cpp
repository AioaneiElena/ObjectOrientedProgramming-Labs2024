#include <iostream>
#include <vector>
#include <list>
#include <functional>

template <class Key, class Value>
struct KeyValuePair {
    Key key;
    Value value;
    KeyValuePair(const Key& k, const Value& v) : key(k), value(v) {}
};

template <class Key, class Value>
class Dictionary {
private:
    std::vector<std::list<KeyValuePair<Key, Value>>> hash_table;
    std::function<size_t(const Key&)> hash_function;

public:
    Dictionary() {
        hash_table.resize(100); 
        hash_function = std::hash<Key>();
    }

    void set(const Key& key, const Value& value) {
        size_t index = hash_function(key) % hash_table.size();
        for (auto& pair : hash_table[index]) {
            if (pair.key == key) {
                pair.value = value;
                return;
            }
        }
        hash_table[index].push_back(KeyValuePair<Key, Value>(key, value));
    }

   
    Value get(const Key& key) const {
        size_t index = hash_function(key) % hash_table.size();
        for (const auto& pair : hash_table[index]) {
            if (pair.key == key) {
                return pair.value;
            }
        }
        throw std::out_of_range("Cheia nu a fost gasita in dictionar.");
    }

    Value& operator[](const Key& key) {
        size_t index = hash_function(key) % hash_table.size();
        for (auto& pair : hash_table[index]) {
            if (pair.key == key) {
                return pair.value;
            }
        }
        hash_table[index].push_back(KeyValuePair<Key, Value>(key, Value()));
        return hash_table[index].back().value;
    }
};

int main() {
    Dictionary<std::string, std::string> dict1;
    dict1.set("Ana", "Maria");
    std::cout << dict1.get("Ana") << std::endl;  

    Dictionary<int, int> dict2;
    dict2[1] = 2;
    std::cout << dict2[1] << std::endl;  

    Dictionary<int, int*> dict3;
    dict3.set(3, new int[100]);
    std::cout << dict3.get(3) << std::endl; 

    return 0;
}