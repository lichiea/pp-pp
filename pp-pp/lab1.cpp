#include "lab1.h"

int find_t(string t) {
    int a = 0;
    for (int i = 0; i < tasks.size(); i++) {
        if (t == tasks[i]) return a = i;
        else a = -1;
    }
    return a;
}

void task2() {
    cout << "------- Task #2. Multithreaded program 'Hello World!'  ------ - " << endl;
    int i = 4;
    omp_set_num_threads(i);
#pragma omp parallel
    {
        int tid = omp_get_thread_num();
#pragma omp critical
        {
            cout << "Hello World!" << endl;
        }
    }
    cout << "------------------------" << endl << endl;
}

void task3_1() {
    cout << "------- Task #3.1. The 'I am!' program ------- " << endl;
    int k = 0;
    while (k <= 0) {
        cout << "Enter the number of threads (>0): ";
        cin >> k;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }

#pragma omp parallel num_threads(k)
    {
        printf("I am %d thread from %d threads!\n",
            omp_get_thread_num(), //Номер нити в параллельной области 
            omp_get_num_threads() //Количество нитей в параллельной области
        );
    }
    cout << "----------------------------" << endl << endl;
}

void task3_2() {
    cout << "------- Задание #3.2. Программа «I am!»------- " << endl;
    int k = 0;
    while (k <= 0) {
        cout << "Enter the number of threads (>0): ";
        cin >> k;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
#pragma omp parallel num_threads(k)
    {
        int kk = omp_get_thread_num();
        if (kk % 2 == 0) {
            printf("I am %d thread from %d threads!\n",
                omp_get_thread_num(), //Номер нити в параллельной области 
                omp_get_num_threads() //Количество нитей в параллельной области
            );
        }
    }
    cout << "----------------------------" << endl << endl;
}

void task4() {
    cout << "------- Task #4. Shared and Private Variables in OpenMP: The 'Hidden Error' Program------ - " << endl;
    int k = 0;
    while (k <= 0) {
        cout << "Enter the number of threads (>0): ";
        cin >> k;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
    int rank;
#pragma omp parallel private (rank) num_threads(k)
    //#pragma omp parallel num_threads(k)
    {
        rank = omp_get_thread_num();
        Sleep(100);
        printf("I am %d thread.\n", rank);
    }
    cout << "------------------------" << endl << endl;
}

void task5() {
    cout << "------- Task #5. Shared and private variables in OpenMP: the reduction parameter -------" << endl;
    int n = 0;
    int sum = 0;
    int k = 2;
    while (n <= 1) {
        cout << "Enter the number of numbers N (>1): ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
#pragma omp parallel num_threads(k) reduction(+:sum)
    {
        int thread_id = omp_get_thread_num();
        int partial_sum = 0;
        if (thread_id == 0) {
            for (int i = 1; i <= n / 2; i++) {
                partial_sum += i;
            }
        }
        else {

            for (int i = n / 2 + 1; i <= n; i++) {
                partial_sum += i;
            }
        }
        printf("[%d]: Sum = %d\n", thread_id, partial_sum);
        sum += partial_sum;
    }
    printf("Sum = %d\n", sum);
    cout << "------------------------" << endl << endl;
}

void task6() {
    cout << "------- Task #6. Parallelizing Loops in OpenMP: The 'Sum of Numbers' Program------ - " << endl;
    int n = 0;
    int sum = 0;
    int k = 0;
    while (k <= 0) {
        cout << "Enter the number of threads (>0): ";
        cin >> k;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
    while (n <= 1) {
        cout << "Enter the number of numbers N (>1): ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
#pragma omp parallel num_threads(k) reduction(+:sum)
    {
        int thread_id = omp_get_thread_num();
        int partial_sum = 0;
#pragma omp for
        for (int i = 1; i <= n; i++) {
            partial_sum += i;
        }
        printf("[%d]: Sum = %d\n", thread_id, partial_sum);
        sum += partial_sum;
    }
    printf("Sum = %d\n", sum);
    cout << "------------------------" << endl << endl;
}

void task7() {
    cout << "------- Task #7. Parallelizing Loops in OpenMP: The Schedule Parameter -------" << endl;
    int n = 0;
    int sum = 0;
    int k = 0;
    char schedule_type[20];
    while (k <= 0) {
        cout << "Enter the number of threads (>0): ";
        cin >> k;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
    while (n <= 1) {
        cout << "Enter the number of numbers N (>1): ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
    printf("Enter type of schedule (static, dynamic, guided) : ");
    cin >> schedule_type;
#pragma omp parallel num_threads(k) reduction(+:sum)
    {
        int thread_id = omp_get_thread_num();
        int partial_sum = 0;
        if (strcmp(schedule_type, "static") == 0) {
#pragma omp for schedule(static)
            for (int i = 1; i <= n; i++) {
                partial_sum += i;
                printf("[%d]: calculation of the iteration number %d\n", thread_id, i);
            }
        }
        else if (strcmp(schedule_type, "dynamic") == 0) {
#pragma omp for schedule(dynamic)
            for (int i = 1; i <= n; i++) {
                partial_sum += i;
                printf("[%d]: calculation of the iteration number %d\n", thread_id, i);
            }
        }
        else if (strcmp(schedule_type, "guided") == 0) {
#pragma omp for schedule(guided)
            for (int i = 1; i <= n; i++) {
                partial_sum += i;
                printf("[%d]: calculation of the iteration number %d\n", thread_id, i);
            }
        }
        else {
#pragma omp for schedule(static)
            for (int i = 1; i <= n; i++) {
                partial_sum += i;
                printf("[%d]: calculation of the iteration number %d\n", thread_id, i);
            }
        }
        printf("[%d]: Sum = %d\n", thread_id, partial_sum);
        sum += partial_sum;
    }
    printf("Sum = %d\n", sum);
    cout << "------------------------" << endl << endl;
}

void task8() {
    cout << "------- Task #8. Parallelizing Loops in OpenMP: The 'Pi' Program------ - " << endl;
    long long n = 0;
    cout << "Enter the calculation precision: ";
    cin >> n;
    double pi = 0;
    double step = 1.0 / n;
    int num_threads = 10;
#pragma omp parallel for reduction(+:pi)
    for (long long i = 0; i < n; ++i) {
        double x = (i + 0.5) * step;
        pi += 4.0 / (1.0 + x * x);
    }
    pi = pi * step;
    cout << "Number pi: " << pi << endl;
    cout << "------------------------" << endl << endl;
}

void task9() {
    cout << "------- Task #9. Parallelizing Loops in OpenMP: The Matrix Program -------" << endl;
    int n = 0;
    while (n <= 1) {
        cout << "Enter the matrix size (>1): ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> B(n, vector<double>(n));
    vector<vector<double>> C(n, vector<double>(n, 0.0));
    cout << "matrix А: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    cout << "matrix В: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }

#pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double sum = 0.0;
            for (int k = 0; k < n; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    cout << "Result: " << endl;
    cout << fixed << setprecision(0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j];
            if (j < n - 1) cout << " ";
        }
        if (i < n - 1) cout << endl;
    }

    cout << endl << "------------------------" << endl << endl;
}

void task10() {
    cout << "------- Task #10. Parallel Sections in OpenMP: The 'I'm Here' Program -------" << endl;
    int k = 0;
    while (k <= 0) {
        cout << "Enter the number of threads (>0): ";
        cin >> k;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
    omp_set_num_threads(k);
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
#pragma omp sections
        {
#pragma omp section
            {
                cout << "[" << thread_id << "] : came in section 1" << endl;
            }
#pragma omp section
            {
                cout << "[" << thread_id << "] : came in section 2" << endl;
            }
#pragma omp section
            {
                cout << "[" << thread_id << "] : came in section 3" << endl;
            }
        }
#pragma omp barrier
        cout << "[" << thread_id << "] : parallel region" << endl;
    }
    cout << "------------------------" << endl << endl;
}

void task11() {
    cout << "------- Task #11. Thread Race in OpenMP: The 'Sum of Numbers' Program with Atomic -------" << endl;
    int n = 0;
    long long sum = 0;
    int k = 0;
    while (k <= 0) {
        cout << "Enter the number of threads (>0): ";
        cin >> k;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
    while (n <= 1) {
        cout << "Enter the number of numbers N (>1): ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not enter a number!" << endl;
        }
    }
    vector<long long> partial_sums(k, 0);
    omp_set_num_threads(k);
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        long long local_sum = 0;
#pragma omp for
        for (long long i = 1; i <= n; i++) {
            local_sum += i;
        }
        partial_sums[thread_id] = local_sum;
        stringstream buffer;
        buffer << "[" << thread_id << "]: Sum = " << local_sum << endl;
#pragma omp critical
        {
            cout << buffer.str();
        }

#pragma omp atomic
        sum += local_sum;
    }
    cout << "Sum = " << sum << endl;
    cout << "------------------------" << endl << endl;
}

void task12() {
    cout << "------- Task #12. Thread race in OpenMP: the 'Number pi' program with critical------ - " << endl;
    long long n = 0;
    cout << "Enter the calculation precision:: ";
    cin >> n;
    double pi = 0;
    double step = 1.0 / n;
#pragma omp parallel
    {
        double local_sum = 0.0;
#pragma omp for
        for (long long i = 0; i < n; i++) {
            double x = (i + 0.5) * step;
            local_sum += 4.0 / (1.0 + x * x);
        }
#pragma omp critical
        {
            pi += local_sum;
        }
    }
    pi *= step;
    cout << fixed << setprecision(8);
    cout << "Number pi: " << pi << endl;
    cout << "------------------------" << endl << endl;
}