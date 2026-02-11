/*
 *
 */
#include <iostream>
using namespace std;

int counter = 0;
void generate_permutation(int array[], int n, int index)
// array[] - масивът с числа
// n - общият брой елементи
// index - текущата позиция, за която търсим число
{
    if (index == n)
        //Ако index достигне n, означава, че сме
        //подредили всички числа.
    {
        for(int i = 0; i < n; i++)
            cout << array[i] << " ";
        cout << endl;
        counter++;
        return;
    }

    for (int i = index; i < n; i++)
    {
        swap(array[index], array[i]); //Вземаме числото от позиция i и го поставяме на текущата позиция index.
        generate_permutation(array, n, index + 1); // Викаме функцията за следващия индекс (index + 1), за да фиксираме останалите числа.
        swap(array[index], array[i]);// Връщаме масива в първоначалното му състояние, за да може следващата итерация на цикълa да работи с правилните данни
    }
}

int main()
{
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    int* array = new int[n];
    for (int i = 0; i < n; i++)
        array[i] = i + 1;
    generate_permutation(array, n, 0);
    cout << "Total permutations: " << counter << endl;
    delete[] array;
    return 0;
}
