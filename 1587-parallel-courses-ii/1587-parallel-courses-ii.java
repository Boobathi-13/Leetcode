class Solution {

    ArrayList<ArrayList<Integer>> graph;
    int n, k;
    HashMap<Integer, Integer> map = new HashMap<>();

    public int minNumberOfSemesters(int n, int[][] relations, int k) {
        /*
         * This question is a N Hard Problem which means it can never have a polynomial
         * time complexity. It will always have an exponential time complexity. We will
         * solve this question using Topological Sort + Bitmask
         * // Consider Bitmask as just an integer which is used to tell the state of the
         * system. Lets say we have 2 courses so I will maintain a mask of 11 initially.
         * 0th bit corresponds to course 0 while 1st bit corresponds to course 1.
         * Initially both the courses are not taken therefore we will make their bits as
         * 1 hence initially mask will be 11. Now at instant, we can have courses>=k, we
         * have to choose which `k` courses to take. Since we don't know which `k`
         * courses will lead to minimum semesters, hence we will evaluating all possible
         * combinations of the available courses.
         */

        this.n = n;
        this.k = k;
        // For simplicity, I will convert this graph to be a 0-indexed one
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++)
            graph.add(i, new ArrayList<>());

        for (int relation[] : relations) {
            graph.get(relation[0] - 1).add(relation[1] - 1);
        }

        this.graph = graph;

        int indegree[] = new int[n];
        for (int i = 0; i < n; i++) {
            for (int child : graph.get(i)) {
                indegree[child] += 1;
            }
        }

        // Lets prepare the mask. Initially set all bits to 1 (Note a bit as 1 means
        // 'not visited' while 0 means visited)

        int mask = 0;
        for (int i = 0; i < n; i++)
            mask |= 1 << i;

        return recurse(mask, indegree);
    }

    private int recurse(int mask, int indegree[]) {
        if (mask == 0)
            return 0;

        if(map.containsKey(mask))
        return map.get(mask);

        List<Integer> nodes = new ArrayList<>(); // instead of queue, I am using a list.

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0 && indegree[i] == 0)
                nodes.add(i);
        }

        int ans = Integer.MAX_VALUE;

        for (List<Integer> kNodes : generateCombinations(nodes, Math.min(k, nodes.size()))) {
            int newMask = mask;
            int newIndegree[] = indegree.clone();

            /*
             * lets say mask = 11 and now node represents 0th node . As we are considering
             * this node, we have to change its bit in the mask to 0.
             * newMask = 11 , 1<<node = 01 so newMask^(1<<node) = 11 ^ 01 = 10
             */

            for (int node : kNodes) {
                newMask ^= (1 << node);
                for (int child : graph.get(node)) {
                    newIndegree[child]--;
                }
            }
            
            ans = Math.min(ans, 1 + recurse(newMask, newIndegree));
        }
        
        map.put(mask, ans);
        return ans;
    }

    private List<List<Integer>> generateCombinations(List<Integer> nodes, int k) {
        List<List<Integer>> result = new ArrayList<>();
        generateHelper(nodes, k, 0, new ArrayList<>(), result);
        return result;
    }

    private void generateHelper(List<Integer> nodes, int k, int start, List<Integer> list, List<List<Integer>> result) {
        if (k == 0) {
            result.add(new ArrayList<>(list));
            return;
        }

        for (int i = start; i < nodes.size(); i++) {
            list.add(nodes.get(i));
            generateHelper(nodes, k - 1, i + 1, list, result);
            list.remove(list.size() - 1);
        }
    }
}