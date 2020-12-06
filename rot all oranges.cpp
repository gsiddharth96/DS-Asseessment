#include <bits/stdc++.h>
using namespace std;
bool issafe(int i, int j, int R, int C)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
} 
int rotOranges(vector<vector<int> >&v , int R, int C)
{
    bool changed = false;
    int no = 2;
    while (true) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (v[i][j] == no) {
                    if (issafe(i + 1, j, R, C) && v[i + 1][j] == 1) {
                        v[i + 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j + 1, R, C) && v[i][j + 1] == 1) {
                        v[i][j + 1] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i - 1, j, R, C) && v[i - 1][j] == 1) {
                        v[i - 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j - 1, R, C) && v[i][j - 1] == 1) {
                        v[i][j - 1] = v[i][j] + 1;
                        changed = true;
                    }
                }
            }
        }
        if (!changed)
            break;
        changed = false;
        no++;
    }
 
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) 
		{
            if (v[i][j] == 1)
                return -1;
        }
    }

    return no - 2;
}
 
int main()
{
 	static int R,C;
	cin>>R>>C;
	vector<vector<int> >arr(R);
	for(int i=0; i<R; ++i)
	{
		vector<int>t;
		for(int j=0; j<C; ++j)
		{
			int k;
			cin>>k;
			t.push_back(k);
		}
		arr.push_back(t);
	}
	int time,fresh, rot;
	time= rotOranges(arr, R, C);
	fresh=0; rot=0;
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
			if(arr[i][j]==1
				fresh++;
			if(arr[i][j]==2)
				rot++;
		}
	}
	cout<<"time frames:"<<time<<endl;
	cout<<"fresh oranges:"<<fresh<<endl;
	cout<<"Rotten oranges:"<<rot<<endl;
	
	return 0;
}


































