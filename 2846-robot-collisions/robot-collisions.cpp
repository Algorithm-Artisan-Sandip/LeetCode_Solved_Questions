class Solution {
public:
void segmentUpdate(int l,int le,int re,vector<pair<int,int>>&h){
    int i=le,j=le+1;
    while(i>=l&&j<=re){
        if(h[i].second==0){i--;continue;}
        if(h[j].second==0){j++;continue;}
        if(h[i].second > h[j].second){
            h[i].second--;h[j++].second=0;
        }else if(h[i].second < h[j].second){
            h[j].second--;h[i--].second=0;
        }else{
            h[i].second=0;i--;
            h[j].second=0;j++;
        }
    }
}
void update(vector<pair<int,int>>&h,vector<pair<int,char>>&d){
    int i=0;
    while(i<d.size()){
        int le=i-1,re;
        while(le+1<d.size()&&(h[le+1].second==0||d[le+1].second=='R'))le++;
        re=le;
        while(re+1<d.size()&&(h[re+1].second==0||d[re+1].second=='L'))re++;
        if(le==i-1){i=re+1;continue;}
        if(re==le)break;
        segmentUpdate(i,le,re,h);
        i=re+1;
    }
}

bool collision(vector<pair<int,int>>&h,vector<pair<int,char>>&d){
    int right=d.size(),left=-1;
    for(int i=0;i<d.size();i++){
        if(h[i].second){
            if(d[i].second=='L')left=i;
            else if(right==d.size())right=i;
        }
    }
    return right<left;
}
    vector<int> survivedRobotsHealths(vector<int>& po, vector<int>& he, string di) {
        // 15 14 13 13   12 15 14 13
        // 15 14 13 12    0 15 14 13
        // 15 14 13 0     0 14 14 13
        // 15 14  0 0     0 13 14 13
        // 15 13  0 0     0  0 14 13
        // 15  0  0 0     0  0 13 13
        // 14  0  0 0     0  0  0 13
        // 13  0  0 0     0  0  0  0
        //sort health,directions by positions vector<pair<int,int>>h,d;
        //now iterate again and again till collision not possible (at max logn times iterations)and find robots in R..RL..L situation and call update(int l,int le,int r,vector<pair<int,int>>&h) to update range
        //store healths in vector<int>res in order as in positions vector and then store in  vector ans all nonzeros health from vector<int>res;
        vector<pair<int,int>>h;
        vector<pair<int,char>>d;
        for(int i=0;i<po.size();i++){
            h.push_back({po[i],he[i]});
            d.push_back({po[i],di[i]});
        }
        sort(h.begin(),h.end());
        sort(d.begin(),d.end());
        //O(n*logn)
        while(collision(h,d))update(h,d);

        vector<int>res(po.size());
        unordered_map<int,int>pos;
        for(int i=0;i<po.size();i++)pos[po[i]]=i;
        for(int j=0;j<h.size();j++){
            res[pos[h[j].first]]=h[j].second;
        }
        vector<int> ans;
        for(auto f:res)if(f)ans.push_back(f);
        return ans;
    }
};