class Solution {
public:
    string reverseWords(string s) {
        auto trim = [](string &s){
            int n = s.size();
            int i=0,j=0;

            while(j<n && s[j] == ' ') j++;
            while(j<n){
                if(s[j] == ' ' && (j == n-1 || s[j+1]== ' ')){
                    j++;
                }
                else{
                    s[i++] = s[j++];
                }
            }
            s.resize(i);
        };

        auto reverse = [](string &s, int left, int right){
            while(left<right){
                swap(s[left++], s[right--]);
            }
        };

        trim(s);
        int n = s.size();

        reverse(s,0,n-1);

        int start=0;
        for(int  i =0; i<=n; i++){
            if(i == n || s[i]== ' '){
                reverse(s,start,i-1);
                start = i+1;
            }
        }

        return s;
    }
};