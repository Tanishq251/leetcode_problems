class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int count =1;

        for(int i=1;i<=n;i++){
            if(i<n && chars[i]==chars[i-1]){
                count++;
            }
            else{
                chars[index++] = chars[i-1];

                if(count>1){
                    for(char c : to_string(count)){
                        chars[index++] = c;
                    }
                }
                count =1;
            }
        }
        return index;
    }
};