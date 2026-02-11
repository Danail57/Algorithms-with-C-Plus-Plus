/*Напиши програма, която приема 3 символа от
 *клавиатурата (напр. 'A', 'B', 'C') и извежда
 *всички техни пермутации в лексикографски (азбучен) ред
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char chars[3];
    cout << "Write 3 characters: ";
    for(int i = 0; i < 3; i++)
        cin >> chars[i];

    sort(chars, chars + 3);
    cout << "All permutations in lexicographic order: " << endl;
    do {
        for (int i = 0; i < 3; i++)
            cout << chars[i] << " ";
        cout << endl;
    } while (next_permutation(chars, chars + 3));
}
