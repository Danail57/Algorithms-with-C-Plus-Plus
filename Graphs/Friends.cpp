/*"Приятелски кръгове"
 *Даден е списък с хора и техните приятелства.
 *Напиши програма, която проверява дали човек А е
 *свързан с човек Б (директно или чрез общи приятели).
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
using namespace std;

map <string, vector<string>> adj;

bool are_connected(string start, string target)
{
    if (start == target)
        return true;
    if (adj.find(start) == adj.end())
        return false;

    set <string> visited;
    queue<string> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        string current = q.front();
        q.pop();
        for (const string& friend_name : adj[current])
        {
            if (friend_name == target)
                return true;
            if (visited.find(friend_name) == visited.end()) {
                visited.insert(friend_name);
                q.push(friend_name);
            }
        }
    }
    return false;
}

int main()
{
    adj["Ivan"] = {"Maria", "Petar"};
    adj["Maria"] = {"Ivan", "Georgi"};
    adj["Petar"] = {"Ivan"};
    adj["Georgi"] = {"Maria"};
    adj["Elena"] = {"Nicolay"};
    adj["Nicolay"] = {"Elena"};

    string a = "Ivan";
    string b = "Georgi";
    cout << "Are they connected " << a << " and " << b << "? " << (are_connected(a, b) ? "Yes" : "No")<< endl;
}
