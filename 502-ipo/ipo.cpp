class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        ios_base::sync_with_stdio(0);
        int i = 0;
        int n = profits.size();
        
        vector<pair<int, int>> projects;
        for (int j = 0; j < n; j++)
        {
            projects.push_back({capital[j], profits[j]});
        }
        
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxHeap;
        
        for (int p = 0; p < k; p++)
        {
            while (i < n && projects[i].first <= w)
            {
                maxHeap.push(projects[i].second);
                i++;
            }
            
            if (maxHeap.empty())
            {
                return w;
            }
            
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};
