#include <iostream>
//#include <omp.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>
#include <random>
#include <Windows.h>
#include <stdio.h>
#include <omp.h>
#include "mpi.h"

using namespace std;

////------- Задание 15. Программа «I am!» -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    int rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    int size_k;
//    MPI_Comm_size(MPI_COMM_WORLD, &size_k);
//    cout << "I am " << rank << " process from " << size_k << " processes" << endl;
//    MPI_Finalize();
//    return 0;
//}

////------- Задание 16. Программа «На первый-второй рассчитайся!»  -------
//int main(int argc, char* argv[]) {
//	MPI_Init(&argc, &argv);
//    int rank, size;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    if (rank == 0) {
//        printf("%d processes.\n", size);
//    }
//    else if (rank % 2 == 0) {
//        printf("I am %d process: SECOND!\n", rank);
//    }
//    else {
//        printf("I am %d process: FIRST!\n", rank);
//    }
//    MPI_Finalize();
//}

////------- Задание 17. Коммуникации «точка-точка»: простые блокирующие обмены  -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    int rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    int buf;
//    if (rank == 0) {
//        buf = 45;
//        MPI_Send(&buf, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
//    }
//    else if (rank == 1) {
//        MPI_Recv(&buf, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//        printf("receive message '%d'\n", buf);
//    }
//    MPI_Finalize();
//}

////------- Задание 18. Коммуникации «точка-точка»: схема «эстафетная палочка» -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    int rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    int size;
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    const int message = rank;
//    int nextRank = rank + 1;
//    if (nextRank >= size) {
//        nextRank = 0;
//    }
//    MPI_Send(&message, 1, MPI_INT, nextRank, 0, MPI_COMM_WORLD);
//    int prevRank = rank - 1;
//    if (prevRank < 0) {
//        prevRank = size - 1;
//    }
//    int receivedMessage;
//    MPI_Recv(&receivedMessage, 1, MPI_INT, prevRank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//    cout << "[" << rank << "]: received message: " << receivedMessage << "\n";
//    MPI_Finalize();
//}

////------- Задание 19. Коммуникации «точка-точка»: схема «мастер-рабочие»  -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    int rank, size;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    int buf = rank;
//    if (rank == 0) {
//        for (int src = 1; src < size; src++) {
//            MPI_Recv(&buf, 1, MPI_INT, src, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//            printf("receive message '%d'\n", buf);
//        }
//    }
//    else {
//        MPI_Send(&buf, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
//    }
//    MPI_Finalize();
//}

////------- Задание 20. Коммуникации «точка-точка»: простые неблокирующие обмены  -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    int rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    int buf = 45;
//    MPI_Request request;
//    if (rank == 0) {
//        MPI_Isend(&buf, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &request);
//    }
//    else if (rank == 1) {
//        MPI_Irecv(&buf, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
//        MPI_Wait(&request, MPI_STATUS_IGNORE);
//        printf("receive message '%d'\n", buf);
//    }
//    MPI_Finalize();
//}

////------- Задание 21. Коммуникации «точка-точка»: схема «сдвиг по кольцу»  -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    int rank, size;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    int buf = rank;
//    int next = (rank + 1) % size;
//    int prev = (rank - 1 + size) % size;
//    MPI_Request send_request, recv_request;
//    MPI_Isend(&buf, 1, MPI_INT, next, 0, MPI_COMM_WORLD, &send_request);
//    MPI_Irecv(&buf, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, &recv_request);
//    MPI_Wait(&send_request, MPI_STATUS_IGNORE);
//    MPI_Wait(&recv_request, MPI_STATUS_IGNORE);
//    printf("[%d]: receive message '%d'\n", rank, buf);
//    MPI_Finalize();
//}

////------- Задание 22. Коммуникации «точка-точка»: схема «каждый каждому»  -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    MPI_Request request;
//    int rank, size;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    for (int i = 0; i < size; i++) {
//        if (i == rank) { continue; }
//        int message = rank;
//        MPI_Isend(&message, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &request);
//        int receivedMessage;
//        MPI_Irecv(&receivedMessage, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &request);
//        MPI_Wait(&request, MPI_STATUS_IGNORE);
//        cout << "[" << rank << "]: received message '" << receivedMessage << "' from " << i << "\n";
//    }
//    MPI_Finalize();
//}

////------- Задание 23. Коллективные коммуникации: широковещательная рассылка данных  -------
//int main(int argc, char* argv[]) {
//    int rank, size;
//    const int MAX_LEN = 100;
//    char buf[MAX_LEN] = { 0 };
//    int n = 0;
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    if (rank == 0) {
//        cout << "Number: ";
//        cin >> n;
//        cout << "String: ";
//        cin >> buf;
//    }
//    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
//    MPI_Bcast(buf, n, MPI_CHAR, 0, MPI_COMM_WORLD);
//    map<char, int> local_count;
//    for (int i = 0; i < n; i++) {
//        char current_char = buf[i];
//        if ((current_char - 'a') % size == rank) {
//            local_count[current_char]++;
//        }
//    }
//    if (rank == 0) {
//        map<char, int> global_count = local_count;
//        for (int proc = 1; proc < size; proc++) {
//            for (char ch = 'a'; ch <= 'z'; ch++) {
//                int received_count;
//                MPI_Recv(&received_count, 1, MPI_INT, proc, ch, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//                global_count[ch] += received_count;
//            }
//        }
//        for (auto& pair : global_count) {
//            if (pair.second > 0) {
//                cout << pair.first << " = " << pair.second << endl;
//            }
//        }
//    }
//    else {
//        for (auto& pair : local_count) {
//            MPI_Send(&pair.second, 1, MPI_INT, 0, pair.first, MPI_COMM_WORLD);
//        }
//    }
//    MPI_Finalize();
//}

////------- Задание 24. Коллективные коммуникации: операции редукции  -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    int rank, size;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    int N;
//    if (rank == 0) {
//        cout << "accuracy of calculations: ";
//        scanf_s("%d", &N);
//    }
//    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
//    double sum = 0.0;
//    double step = 1.0 / N;
//    for (int i = rank; i < N; i += size) {
//        double x = (i + 0.5) * step;
//        sum += 4.0 / (1.0 + x * x);
//    }
//    double pi;
//    MPI_Reduce(&sum, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
//    if (rank == 0) {
//        pi *= step;
//        printf("pi = %.8f\n", pi);
//    }
//    MPI_Finalize();
//}

////------- Задание 25. Коллективные коммуникации: функции распределения и сбора данных  -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    int rank, size;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    int n;
//    if (rank == 0) {
//        cout << "matrix size: ";
//        scanf_s("%d", &n);
//    }
//    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
//    double* A = NULL, * B = NULL, * C = NULL;
//    double* local_A = (double*)malloc(n * n * sizeof(double));
//    double* local_C = (double*)malloc(n * n * sizeof(double));
//    if (rank == 0) {
//        A = (double*)malloc(n * n * sizeof(double));
//        B = (double*)malloc(n * n * sizeof(double));
//        C = (double*)malloc(n * n * sizeof(double));
//        cout << "matrix A: " << endl;
//        for (int i = 0; i < n * n; i++) {
//            scanf_s("%lf", &A[i]);
//        }
//        cout << "matrix B: " << endl;
//        for (int i = 0; i < n * n; i++) {
//            scanf_s("%lf", &B[i]);
//        }
//    }
//    MPI_Scatter(A, n * n / size, MPI_DOUBLE, local_A, n * n / size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
//    MPI_Bcast(B, n * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            local_C[i * n + j] = 0.0;
//            for (int k = 0; k < n; k++) {
//                local_C[i * n + j] += local_A[i * n + k] * B[k * n + j];
//            }
//        }
//    }
//    MPI_Gather(local_C, n * n / size, MPI_DOUBLE, C, n * n / size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
//    if (rank == 0) {
//        cout << "matrix C:" << endl;
//        for (int i = 0; i < n * n; i++) {
//            printf("%lf ", C[i]);
//            if ((i - 1) % n == 0) cout << endl;
//        }
//        free(A);
//        free(B);
//        free(C);
//    }
//    free(local_A);
//    free(local_C);
//    MPI_Finalize();
//}

////------- Задание 26. Группы и коммуникаторы  -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    int world_rank, world_size;
//    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//    int color = (world_rank % 2 == 0) ? 0 : MPI_UNDEFINED;
//    MPI_Comm new_comm;
//    MPI_Comm_split(MPI_COMM_WORLD, color, world_rank, &new_comm);
//    char message[12] = "no"; 
//    if (world_rank == 0) {
//        cout << "Enter message: ";
//        cin >> message;
//    }
//    if (new_comm != MPI_COMM_NULL) {
//        MPI_Bcast(message, 12, MPI_CHAR, 0, new_comm);
//    }
//    int new_rank = -1, new_size = -1;
//    if (new_comm != MPI_COMM_NULL) {
//        MPI_Comm_rank(new_comm, &new_rank);
//        MPI_Comm_size(new_comm, &new_size);
//    }
//    if (new_comm != MPI_COMM_NULL) {
//        cout << "MPI_COMM_WORLD: " << world_rank << " from " << world_size
//             << ". New comm: " << new_rank << " from " << new_size
//             << ". Message = " << message << endl;
//    }
//    else {
//        cout << "MPI_COMM_WORLD: " << world_rank << " from " << world_size
//             << ". New comm: no from no. Message = no" << endl;
//    }
//    if (new_comm != MPI_COMM_NULL) {
//        MPI_Comm_free(&new_comm);
//    }
//    MPI_Finalize();
//    return 0;
//}

////------- Задание 31. Программа «I am» -------
//int main(int argc, char* argv[]) {
//    MPI_Init(&argc, &argv);
//    int rank_mpi, size_mpi;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank_mpi);
//    MPI_Comm_size(MPI_COMM_WORLD, &size_mpi);
//    int n;
//    if (rank_mpi == 0) {
//        cout << "Enter the number of threads: ";
//        cin >> n;
//    }
//    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
//    omp_set_num_threads(n);
//#pragma omp parallel
//    {
//        int rank_omp = omp_get_thread_num();
//        int size_omp = omp_get_num_threads();
//        printf("I am %d thread from %d process. Number of hybrid threads = %d.\n",
//            rank_omp, rank_mpi, size_omp * size_mpi);
//    }
//    MPI_Finalize();
//}

////------- Задание 32. Программа «Число 𝜋» -------
int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    int rank_mpi, size_mpi;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank_mpi);
    MPI_Comm_size(MPI_COMM_WORLD, &size_mpi);
    int N;
    if (rank_mpi == 0) {
        cout << "Enter the precision (N): ";
        cin >> N;
    }
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    double step = 1.0 / N;
    double sum = 0.0;
#pragma omp parallel for reduction(+:sum)
    for (int i = rank_mpi; i < N; i += size_mpi) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    double local_pi = sum * step;
    double pi;
    MPI_Reduce(&local_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank_mpi == 0) {
        cout << fixed << setprecision(8) << "pi: " << pi << endl;
    }
    MPI_Finalize();
}