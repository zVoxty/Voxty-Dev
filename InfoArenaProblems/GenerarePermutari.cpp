#include <algorithm>
#include <stdio.h>
#include <vector>
 
int main()
{
    freopen("permutari.in", "r", stdin);
    freopen("permutari.out", "w", stdout);
 
    int permutationNumber;
    scanf("%d", &permutationNumber);
 
    std::vector<int> permutationContainer;
     
    for (int i = 1; i <= permutationNumber; i++)
    {
        permutationContainer.push_back(i);
    }
 
    do
    {
        for (int i = 0; i < permutationNumber; i++)
        {
            printf("%d ", permutationContainer[i]);
        }
        printf("\n");
    } while (next_permutation(permutationContainer.begin(),permutationContainer.end()));
     
    return 0;
}