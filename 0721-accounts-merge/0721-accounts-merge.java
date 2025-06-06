class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, Set<String>> adj = new HashMap<>();

        for(List<String> account : accounts) {
            String email1 = account.get(1);
            for(int i = 2; i < account.size(); i++) {
                String curEmail = account.get(i);
                adj.computeIfAbsent(email1, k->new HashSet<>()).add(curEmail);
                adj.computeIfAbsent(curEmail, k->new HashSet<>()).add(email1);
            }
        }
        Set<String> visited = new HashSet<>();
        List<List<String>> result = new ArrayList<>();

        for(List<String> account : accounts) {
            String email1 = account.get(1);
            if(visited.contains(email1))
                continue;
            ArrayList<String> mergedEmails = new ArrayList<>();
            dfs(email1, adj, mergedEmails, visited);
            if(mergedEmails.size() > 1)
                Collections.sort(mergedEmails);
            mergedEmails.add(0, account.get(0));//add name
            result.add(mergedEmails);
        }
        return result;
    }

    void dfs(String email, Map<String, Set<String>> adj, List<String> mergedEmails, Set<String> visited) {
        if(visited.contains(email))
            return;
        mergedEmails.add(email);
        visited.add(email);
        for(String nextEmail : adj.getOrDefault(email, Collections.emptySet())) {
            dfs(nextEmail, adj, mergedEmails, visited);
        }
    }
}