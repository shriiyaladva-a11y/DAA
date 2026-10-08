#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    int p[20];
        int m[20][20];
    int i, j, k, L, cost;

    // Take number of matrices from user
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    // Take dimensions from user
    printf("Enter %d dimensions:\n", n + 1);

    for (i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    // Cost of multiplying one matrix is 0
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    // L represents length of matrix chain
    for (L = 2; L <= n; L++)
    {
        // i represents starting matrix
        for (i = 1; i <= n - L + 1; i++)
        {
            // j represents ending matrix
            j = i + L - 1;

            // Initially set cost to maximum value
            m[i][j] = INT_MAX;

            // Try every possible split
            for (k = i; k < j; k++)
            {
                cost = m[i][k]
                     + m[k + 1][j]
                     + p[i - 1] * p[k] * p[j];

                // Store minimum cost
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                }
            }
        }
    }

    // Display final answer
    printf("Minimum number of multiplications = %d\n", m[1][n]);

    return 0;
}
