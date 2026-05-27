class Solution {
public:
    string capitalizeTitle(string title) {
        // Convert the entire string to lowercase
        transform(title.begin(), title.end(), title.begin(), ::tolower);
        
        int wordStart = 0;
        int wordSize = title.size();
        
        // Iterate through the string (i == wordSize handles the last word)
        for(int i = 0; i <= wordSize; i++) {
            // Check if we hit a space or reached the end of the string
            if(i == wordSize || title[i] == ' ') {
                int currentWordLen = i - wordStart;
                
                // Capitalise first letter only if the word has 3 or more characters
                if(currentWordLen > 2) {
                    title[wordStart] = toupper(title[wordStart]);
                }
                
                // Move pointer to the beginning of the next word
                wordStart = i + 1;
            }
        }
        return title;
    }
};
