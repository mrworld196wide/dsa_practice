map<char,int>ma;
        int n=s.size();
        int i;
        deque<int>dq;
        int c=0;
        for(i=0;i<n;i++)
        {

            if(!dq.empty() and dq.front()==i-k){
                int curr=dq.front();
                if(ma[s[curr]]==1)
                ma.erase(s[curr]);
                else
                ma[s[curr]]--;

                dq.pop_front();
            }

            dq.push_back(i);
            ma[s[i]]++;

            if(i>=k-1)
            {
                if(ma.size()==k-1)
                c++;
            }
        }
        return c;