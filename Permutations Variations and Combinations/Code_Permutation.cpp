/*
 *
 */
#include <iostream>
using namespace std;

void decode_permutation(int num, int n, int *permutation)
{
    int *p = new int[n];
    int *lehmer = new int[n]; // Масив, в който ще запишем остатъците от деленето. Тези остатъци ни казват кой елемент от масива p да изберем на всяка стъпка.
    for (int i = 0; i < n; i++)
        p[i] = i + 1;

    for (int i = 1; i <= n; i++)
    {
        //Тук числото num се разлага по базите на факториелите

        // Операцията num % i взема остатъка, който
        // представлява индекса на числото в текущия списък с налични числа.
        lehmer[n - i] = num % i;
        num /= i;
    }

    int size = n;
    //Този цикъл превръща индексите в реални числа
    for (int i = 0; i < n; i++)
    {
        int index = lehmer[i];
        permutation[i] = p[index];
        for (int j = index; j < size - 1; j++)
            p[j] = p[j + 1];
        size--;
    }
    delete[] p;
    delete[] lehmer;
}

int main()
{
    int n = 4;
    int rank = 5;
    int *permutation = new int[n];
    decode_permutation(rank, n, permutation);
    cout << "Permutation:" << endl;

    for (int i = 0; i < n; i++)
        cout << permutation[i] << " ";
    cout << endl;
    delete[] permutation;
    return 0;
}
