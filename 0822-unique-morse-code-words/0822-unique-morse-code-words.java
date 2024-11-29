class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
                ".--","-..-","-.--","--.."};
        char[] alphabet = {
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
        };

        String[] new_morse_code_arr = new String[words.length];
        int index=0;

        String check;
        for (String word : words) {
            check = word;
            for (int j = 0; j < check.length(); j++) {
                for (int k = 0; k < alphabet.length; k++) {
                    if (check.charAt(j) == alphabet[k]) {
                        if (new_morse_code_arr[index] == null) {
                            new_morse_code_arr[index] = "";
                        }
                        new_morse_code_arr[index] = new_morse_code_arr[index] + morse_code[k];
                    }
                }
            }
            index++;
        }

        HashSet<String> hs = new HashSet<>(Arrays.asList(new_morse_code_arr));

        return hs.size();
    }
}