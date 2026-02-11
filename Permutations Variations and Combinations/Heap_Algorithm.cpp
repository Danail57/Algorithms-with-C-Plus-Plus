/*Генерирай всички пермутации на n
 *елемента по такъв начин, че всяка следваща
 *пермутация да се получава от предишната
 *чрез размяна на само два съседни елемента
 *.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print (const vector<int>& v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

void generate_minimal_change(int n, vector<int>& array)
{
    if (n == 1) {
        print(array);
        return;
    }
    for (int i = 0; i < n; i++) {
        generate_minimal_change(n - 1, array);
        if (n % 2 == 0) {
            swap(array[i], array[n - 1]);
        }
        else {
            swap(array[0], array[n - 1]);
        }
    }
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";  
    cin >> n;
    vector<int> array;
    for (int i = 1; i <= n; i++)
        array.push_back(i);
    cout << "Permutations with minimal change: "<< endl;
    generate_minimal_change(n, array);
    return 0;
}
