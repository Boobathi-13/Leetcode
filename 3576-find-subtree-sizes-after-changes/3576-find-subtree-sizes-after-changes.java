class Solution {
    private void solveDFS(int[] parent, int node, String s, Map<Character, Integer> map, int[] newPar,
            List<List<Integer>> adj) {
        char curr = s.charAt(node);

        // edge
        if (map.containsKey(curr)) {
            newPar[node] = map.get(curr);
        } else {
            newPar[node] = parent[node];
        }

        // Solve it
        int prev = map.getOrDefault(curr, -1);
        map.put(curr, node);
        for (int ad : adj.get(node)) {
            solveDFS(parent, ad, s, map, newPar, adj);
        }

        if (prev == -1) {
            map.remove(curr);
        } else {
            map.put(curr, prev);
        }
    }

    private int calculateSubtreeSizesDFS(int node, List<List<Integer>> newTree, int[] subtreeSizes) {
        int size = 1;
        for (int child : newTree.get(node)) {
            size += calculateSubtreeSizesDFS(child, newTree, subtreeSizes);
        }
        subtreeSizes[node] = size;
        return size;
    }

    // DRIVE CODE
    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 1; i < n; i++) {
            adj.get(parent[i]).add(i);
        }

        Map<Character, Integer> map = new HashMap<>();
        int[] newPar = new int[n];
        Arrays.fill(newPar, -1);
        solveDFS(parent, 0, s, map, newPar, adj);


        
        List<List<Integer>> adj_ = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj_.add(new ArrayList<>());
        }
        for (int i = 1; i < n; i++) {
            adj_.get(newPar[i]).add(i);
        }

        int[] subtreeSizes = new int[n];
        calculateSubtreeSizesDFS(0, adj_, subtreeSizes);
        return subtreeSizes;
    }
}