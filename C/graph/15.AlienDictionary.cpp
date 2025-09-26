#include <bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int N, int K)
{
    // Adjacency list creation
    vector<int> adj[K];
    vector<int> InDeg(K, 0);

    for (int i = 0; i < N - 1; i++)
    {
        string str1 = dict[i], str2 = dict[i + 1];
        int j = 0, k = 0;

        while (j < str1.size() && k < str2.size() && str1[j] == str2[k])
        {
            j++, k++;
        }

        if (j == str1.size())
            continue;

        adj[str1[j] - 'a'].push_back(str2[k] - 'a');
        InDeg[str2[k] - 'a']++;
    }

    queue<int> q;
    for (int i = 0; i < K; i++)
        if (!InDeg[i])
            q.push(i);

    string ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        char c = 'a' + node;
        ans += c;

        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;
            if (!InDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    return ans;
}
int main()
{
    int N, K;
    cout << "Enter the number of words (N) and the number of unique characters (K): ";
    cin >> N >> K;

    string dict[N];
    cout << "Enter the words:\n";
    for (int i = 0; i < N; i++)
    {
        cin >> dict[i];
    }

    string order = findOrder(dict, N, K);

    if (order.empty())
    {
        cout << "Invalid order (Cycle detected or inconsistent dictionary).\n";
    }
    else
    {
        cout << "The order of characters in the alien language is: " << order << endl;
    }

    return 0;
}