class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            // Determine how many words can fit in the current line
            int totalChars = words[index].length();
            int last = index + 1;
            while (last < n) {
                if (totalChars + words[last].length() + (last - index) > maxWidth) break;
                totalChars += words[last].length();
                last++;
            }

            // Create the current line
            string line;
            int numWords = last - index;
            if (last == n || numWords == 1) {
                // Last line or a line with a single word: left-justified
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                // Fully justify the current line
                int totalSpaces = maxWidth - totalChars;
                int spaceBetweenWords = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int i = index; i < last - 1; i++) {
                    line += words[i];
                    line += string(spaceBetweenWords + (i - index < extraSpaces ? 1 : 0), ' ');
                }
                line += words[last - 1];  // Add the last word
            }

            result.push_back(line);
            index = last;
        }

        return result;
    }
};
