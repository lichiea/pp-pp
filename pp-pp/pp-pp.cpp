#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "mpi.h"

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");
    MPI_Init(&argc, &argv);
    string opt;
    cout << "           PARALLEL PROGRAMMING, LABORATORY WORKS #1-3" << endl;
    cout << "           Help: all - complete all tasks in order, " << endl;
    cout << "                 task# - perform task # (2-12, 15-29, 31-32), " << endl;
    cout << "                 end - terminates the program" << endl;
    while (opt != "end") {
        cout << endl << "Enter the command: ";
        cin >> opt;
        int a = find_t(opt);
        switch (a) {
        case 0:
            cout << endl << endl << "The program is completed" << endl;
            break;
        case 1:
            task2();
            task3_1();
            task3_2();
            task4();
            task5();
            task6();
            task7();
            task8();
            task9();
            task10();
            task11();
            task12();
            //task15(argc, argv);
            //task16(argc, argv);
            task17();
            task18();
            task19();
            task20();
            task21();
            task22();
            task23();
            task24();
            task25();
            task26();
            task27();
            task28();
            task29();
            task31();
            task32();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3_1();
            task3_2();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 9:
            task9();
            break;
        case 10:
            task10();
            break;
        case 11:
            task11();
            break;
        case 12:
            task12();
            break;
        case 15:
            cout << "------- Task #15. The 'I am!' program ------- " << endl;
            cout.flush();  // гарантированный вывод

            cout << "Before MPI_Init" << endl;
            cout.flush();

            cout << "After MPI_Init" << endl;   // если это не выводится – зависло внутри MPI_Init
            cout.flush();

            int rank;
            MPI_Comm_rank(MPI_COMM_WORLD, &rank);
            cout << "rank: " << rank << endl;
            cout.flush();

            int size_k;
            MPI_Comm_size(MPI_COMM_WORLD, &size_k);
            cout << "size_k: " << size_k << endl;
            cout.flush();

            cout << "I am " << rank << " process from " << size_k << " processes" << endl;
            cout.flush();

            MPI_Finalize();
            cout << "------------------------" << endl << endl;
            cout.flush();
            break;
        case 16:
            //task16(argc, argv);
            break;
        case 17:
            task17();
            break;
        case 18:
            task18();
            break;
        case 19:
            task19();
            break;
        case 20:
            task20();
            break;
        case 21:
            task21();
            break;
        case 22:
            task22();
            break;
        case 23:
            task23();
            break;
        case 24:
            task24();
            break;
        case 25:
            task25();
            break;
        case 26:
            task26();
            break;
        case 27:
            task27();
            break;
        case 28:
            task28();
            break;
        case 29:
            task29();
            break;
        case 31:
            task31();
            break;
        case 32:
            task32();
            break;
        default:
            cout << "Unknown command" << endl;
        }
    }
    MPI_Finalize();
    return 0;
}