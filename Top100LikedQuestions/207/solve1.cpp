//There are a total of n courses you have to take, labeled from 0 to n-1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
//Example 1:
//
//Input: 2, [[1,0]] 
//Output: true
//Explanation: There are a total of 2 courses to take. 
//             To take course 1 you should have finished course 0. So it is possible.
//Example 2:
//
//Input: 2, [[1,0],[0,1]]
//Output: false
//Explanation: There are a total of 2 courses to take. 
//             To take course 1 you should have finished course 0, and to take course 0 you should
//             also have finished course 1. So it is impossible.
//Note:
//
//The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
//You may assume that there are no duplicate edges in the input prerequisites.

// Here, we use indegree of the node to check whether can topological sort
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 0)
            return false;
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> indegree(numCourses, 0);
        for (int i=0; i<prerequisites.size(); i++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }
        queue<int> q;
        for (int i=0; i<indegree.size(); i++) {
            if  (indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i=0; i<graph[u].size(); i++) {
                indegree[graph[u][i]]--;
                if  (indegree[graph[u][i]] == 0) {
                    q.push(graph[u][i]);
                }
            }
        }
        for (int i=0; i<indegree.size(); i++) {
            if (indegree[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
