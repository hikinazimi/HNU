#include<iostream>
#include<stack>
using namespace std;
int isValid(string s)
{
    int len = s.length();
    stack<char>q;
    int ret = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '<' || s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            q.push(s[i]);
        }
        else if (q.empty()||(s[i]=='>'&&q.top()!='<')||(s[i]==']'&&q.top()!='[') || (s[i] == '}' && q.top() != '{')||(s[i]==')'&&q.top()!='('))
            return 0;
        else       
            q.pop();
    }
    if (q.empty())
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int flag = isValid(s);
        if (flag == 1)
            cout << "Yes"<<endl;
        else
            cout << "No"<<endl;
    }
}
