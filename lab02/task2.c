#include <stdio.h>
#include <math.h>

int main() {
    double x, epsilon;

    printf("Enter argument X: ");
    if (scanf("%lf", &x) != 1) return 1;

    printf("Enter desired precision epsilon (e.g., 0.00001): ");
    if (scanf("%lf", &epsilon) != 1) return 1;

    if (epsilon <= 0) {
        fprintf(stderr, "Error: precision must be a positive number.\n");
        return 1;
    }

    double sum = 1.0; 
    double term = 1.0;      
    int n = 1;
    int max_iterations = 100000; 
    int converged = 0;

    while (n <= max_iterations) {
        term = term * (x / n);
        sum += term;

        if (fabs(term) < epsilon) {
            converged = 1;
            break;
        }
        n++;
    }

    if (!converged) {
        printf("Warning: iteration limit reached (%d), precision not guaranteed!\n", max_iterations);
    }

    double exact_value = exp(x);
    double absolute_error = fabs(sum - exact_value);

    printf("\n--- Results for e^(%.2lf) ---\n", x);
    printf("Computed series sum:     %.7lf\n", sum);
    printf("Standard library (exp):  %.7lf\n", exact_value);
    printf("Absolute error:          %.7le\n", absolute_error);
    printf("Iterations spent:        %d\n", n);

    return 0;
}
