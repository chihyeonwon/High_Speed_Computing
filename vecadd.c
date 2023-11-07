#include <stdio.h>
#include <mpi.h>

#define N 24

int main(int argc, char* argv[]) {
    int np, pid, i;
    float A[N], B[N], C[N];
    MPI_Status status;


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    // Initialization of A and B
    if (pid == 0) {
        for (i = 0; i < N; i++) {
            A[i] = i;
            B[i] = N - i;
        }
    }

    // 1. Decomposition ����
    if (pid == 0) {
        for (i = 1; i < np; i++) {
            MPI_Send(&A[i * N/np], N/np, MPI_FLOAT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&B[i * N/np], N/np, MPI_FLOAT, i, 0, MPI_COMM_WORLD);
        }
        for (i = 0; i < N/np; i++) {
           A[i] = A[i]; 
           B[i] = B[i];
        }
    } else {
        MPI_Recv(A, N/np, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(B, N/np, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &status);
    }

    // 2. Addition �л��ѰŸ� ��ħ
    for (i = 0; i < N/np; i++) {
        C[i] = A[i] + B[i];
    }

    // 3. composition ����� ��� ������ ���� c�� ��ħ
    if (pid == 0) {
        for (i = 1; i < np; i++) {
            MPI_Recv(&C[i * N/np], N/np, MPI_FLOAT, i, 0, MPI_COMM_WORLD, &status);
        }
    } else {
        MPI_Send(C, N/np, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
    }

    // Print results
    if (pid == 0) {
        for (i = 0; i < N; i++) {
            printf("%2.1f ", C[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
}
