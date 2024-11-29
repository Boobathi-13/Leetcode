class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        // Create a list of HashMaps to keep track of picks for each player
        List<Map<Integer, Integer>> vec = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            vec.add(new HashMap<>());
        }
        // Populate the list with the pick data
        for (int[] p : pick) {
            vec.get(p[0]).put(p[1], vec.get(p[0]).getOrDefault(p[1], 0) + 1);
        }
        int x = 0; // Initialize the count of winning players
        // Iterate through each player
        for (int i = 0; i < n; ++i) {
            // Check each picked number for the current player
            for (Map.Entry<Integer, Integer> entry : vec.get(i).entrySet()) {
                // If the count of picks for a number is greater than the player's index, they are a winning player
                if (entry.getValue() > i) {
                    x++; // Increment the count of winning players
                    break; // Exit the loop as we found the player is winning
                }
            }
        }
        return x; // Return the total count of winning players
    }
}