class Solution {
public:

    void helper(vector<vector<int>>& graph, int i, int target, vector<vector<int>>& output, vector<int>& path){
        if(i==target){
            output.push_back(path);
            return;
        }

        for(int j=0;j<graph[i].size();j++){
            path.push_back(graph[i][j]);
            helper(graph, graph[i][j],target,output, path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int s=graph.size();
        int target=s-1;
        vector<vector<int>> output;
        vector<int>path;
        path.push_back(0);
        for(int i=0;i<graph[0].size();i++){
            path.push_back(graph[0][i]);
            helper(graph, graph[0][i], target,output, path);
            path.pop_back();
        }

        return output;
    }
};