#include <iostream>
#include <set>

using namespace std;

// Generate prime numbers upto n
void primeGen(int n) {
    set<int> prime;

    for (int  i = 2; i <= n; i++)
    {
        prime.insert(i);
    }

    set<int>::iterator it;
    for (int i = 2; i*i <= n; i++)
    {
        // The loop runs to i square < n since if i square less than n, all numbers within n are mulitples of i or lower
        it = prime.find(i);
        if (it != prime.end()) {
            // This for loop finds multiples of i and removes them from the list
            for (int j = 2*i; j <= n; j += i) {
                it = prime.find(j);
                if (it != prime.end()) {
                    // Remove the dereference to the objects the iterator points to
                    prime.erase(*it);
                }
            }
        }
    }
    
    // Write out each number thats left since all possible muliples are removed
    for (set<int>::iterator iter = prime.begin(); iter != prime.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}


int main() {
    
    int n; 
    cout << "Enter upper bound for prime number generation: " << endl;
    cin >> n;
    primeGen(n);
    return 0;
}