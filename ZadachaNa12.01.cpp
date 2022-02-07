#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int max_size = 100;

int main()
{
    int size;
    int s1, end;
    cin >> size;
    vector<int> from(size, -1);
    vector<int> used(size, 0);
    vector<int> path(size);
    int mm[max_size][max_size];
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            cin >> mm[i][j];
        }
    }

    cin >> s1 >> end;
    queue<int> s2;
    s2.push(s1);
    path[s1] = 0;
    used[s1] = 1;
    while (!s2.empty())
    {
        int temp = s2.front();
        s2.pop();
        for (int i = 0; i < size; ++i)
        {
            if (mm[temp][i] && (!used[i]))
            {
                path[i] = path[temp] + 1;
                from[i] = temp;
                s2.push(i);
                used[i] = true;
            }
        }

    }
    cout << "Кратчайший путь = " << path[end];
    return 0;
}
