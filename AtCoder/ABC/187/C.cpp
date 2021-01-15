#include<iostream>
#include<set>

using namespace std;

int N;
set<string> rec;

int main()
{
    cin >> N;
    string s, ss[N];
    for (int i = 0; i < N; i++) {
        cin >> ss[i];
    }
    for (int i = 0; i < N; i++) {
        s = ss[i];
        if (s[0] == '!') {
            string p(s, 1);
            if (rec.find(p) != rec.end()) {
                cout << p << endl;
                return 0;
            }
        } else {
            string p(s);
            p.insert(0, "!");
            if (rec.find(p) != rec.end()) {
                cout << s << endl;
                return 0;
            }
        }
        rec.insert(s);
    }
    cout << "satisfiable" << endl;
}
