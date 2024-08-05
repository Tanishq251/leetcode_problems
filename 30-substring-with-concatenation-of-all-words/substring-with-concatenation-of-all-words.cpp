class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;
        
        int word_len = words[0].size();
        int concat_len = word_len * words.size();
        
        if (s.size() < concat_len) return result;

        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }
        
        for (int i = 0; i < word_len; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> seen_words;
            
            for (int j = i; j <= s.size() - word_len; j += word_len) {
                string word = s.substr(j, word_len);
                
                if (word_count.find(word) != word_count.end()) {
                    seen_words[word]++;
                    count++;
                    
                    while (seen_words[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        seen_words[left_word]--;
                        count--;
                        left += word_len;
                    }
                    
                    if (count == words.size()) {
                        result.push_back(left);
                    }
                } else {
                    seen_words.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }
        
        return result;
    }
};
