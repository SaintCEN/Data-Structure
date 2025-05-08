#include <bits/stdc++.h>
using namespace std;

struct Person
{
    char sex;
    pair<int, int> parents;
};

unordered_set<int> getAncestors(int id, unordered_map<int, Person> &people)
{
    unordered_set<int> ancestors;
    queue<pair<int, int>> q;

    int father = people[id].parents.first;
    int mother = people[id].parents.second;
    if (father != -1)
    {
        q.push({father, 1});
        ancestors.insert(father);
    }
    if (mother != -1)
    {
        q.push({mother, 1});
        ancestors.insert(mother);
    }

    while (!q.empty())
    {
        auto [currentId, level] = q.front();
        q.pop();

        if (level < 4)
        {
            Person &p = people[currentId];
            int dad = p.parents.first;
            int mom = p.parents.second;
            if (dad != -1 && !ancestors.count(dad))
            {
                q.push({dad, level + 1});
                ancestors.insert(dad);
            }
            if (mom != -1 && !ancestors.count(mom))
            {
                q.push({mom, level + 1});
                ancestors.insert(mom);
            }
        }
    }
    return ancestors;
}

void check(int a, int b, unordered_map<int, Person> &people)
{
    Person &pA = people[a];
    Person &pB = people[b];

    if (pA.sex == pB.sex)
    {
        cout << "Never Mind" << endl;
        return;
    }

    auto ancestorsA = getAncestors(a, people);
    auto ancestorsB = getAncestors(b, people);

    for (int ancestor : ancestorsA)
    {
        if (ancestorsB.count(ancestor))
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    int N, K;
    cin >> N;
    unordered_map<int, Person> people;

    for (int i = 0; i < N; ++i)
    {
        int id, father, mother;
        char sex;
        scanf("%d %c %d %d", &id, &sex, &father, &mother);
        people[id] = {sex, {father, mother}};
    }

    cin >> K;
    while (K--)
    {
        int a, b;
        cin >> a >> b;
        check(a, b, people);
    }

    return 0;
}