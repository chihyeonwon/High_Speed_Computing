# High_Speed_Computing
컴퓨터공학과 초고속컴퓨팅 정리입니다.

## Install XShell, MobaXterm
[MobaXterm](https://securityspecialist.tistory.com/141)
![image](https://github.com/wonttan/High_Speed_Computing/assets/58906858/c735a0f0-9ccf-48d9-866b-43da42c50b0b)

## 23년 9월 4일 초고속컴퓨팅 과제1
![image](https://github.com/wonttan/High_Speed_Computing/assets/58906858/96e53351-e401-446a-866f-53c308e5cb71)
```
ssh 서버에 접속하여 add.c 파일을 작성한 후 컴파일하고 실행한다.
```

## 23년 9월 5일 초고속컴퓨팅
>add 3 4
```
int argc; // argc = 3 (argument counter) 개수가 3개
char *argv[]; // 포인터배열 argv[0] = 'add', argv[1] = '3', argv[2] = '4' (argument vector=array)

#include <stdio.h>
#include <string.h>
main(int argc, char *argv[])
{
  printf("%d\n", atoi(argv[1] + atoi(argv[2]));
}
```
```
#include <stdio.h>
#include <string.h>

main(int argc, char *argv[])
{
  int a, b, c;
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = a + b; 

  printf("%d\n", c);
}
```
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
  int a, b, c;

  if(argc != 3) exit(1);

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = a + b;

  printf("%d\n", c);

  exit(0);
}
```
![image](https://github.com/wonttan/High_Speed_Computing/assets/58906858/2cea1e84-a4ab-4e68-9308-f6507c775075)
```
add 4 5 이런식으로 실행해야함
echo s?
-> 1 
echo s?
-> 0

s가 처음에는 오류라서 1인데 그 다음번에는 정상이라서 0
```
```
parallel vs multi-tasking

변수명 
보기좋고 이해하기 쉬운 프로그램 작성
탭키 x, 스페이스 3번 사용(리눅스, 비주얼은 탭키가 얼마안됨)

Flynn's taxonomy : 플린 분류 (플린은 Parallel의 개념을 정의함)
명령어와 데이터 입력의 개수에 따라 분류

SISD < 하나의 명령어로 여러개의 데이터를 처리
SIMD
MISD - 가능하지않음
MIMD

SIMD and MIMD <- 여러개의 명령어 여러개의 데이터 처리 -> Parallel Processing

SIMD (Single Instruction Multi Data) : Graphic Card 그래픽 카드 GPU 한개의 명령어로 여러개의 데이터 처리

MIMD (Multi Instruction Multi Data) : 여러개의 명령어로 여러개의 데이터 처리

statement vs instruction

statement <- 사람이 이해하기 쉬운 high level
instruction <- 기계가 실행할 수 있는 명령어 low level

본 노이만 머신

하나의 컴퓨터에서 cpu가 main memory와 버스로 연결
계산하는 기능은 CPU
기억하는 기능은 MEMORY
CPU와 MEMORY로 분리

버스에 캐시메모리 넣음 Memory, CPU하고 연결하려

양자컴퓨터는 다같이하는듯

SIMD(그래픽카드 너무 오래됨) 하나의 CU 여러개의 ALU
MIMD(여러개의 CPU가 여러개의 메모리를 공유) 2개의 종류(Shared, Distributed)
1. Shared : 공유메모리 Multi-core, hpc, 운영체제, 컴파일러
2. Distributed : 분산메모리 most super computer, hpc+hpa+hpb, 네트워크 프로그램, 확장하기 쉬움
```
## 23.09.12 
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/75a9f7c9-fc62-4ab4-bab6-73d2b93e4af0)
```
Shared Memory : memomory-cpu 100cpus (하나의 OS만 존재해서 데이터 충돌(data confliction)이 일어나는 문제가 발생한다.) extend difficult
Semaphore 세마포 : 공유메모리의 데이터 충돌 문제를 해결할 수 있다.
multi-tasking , time-sharing 시분할
Distributed Memory : memory-cpu (많은 OS가 있을 수 있기 때문에 확장하기 좋다.) 
지금은 hpclab만 쓰지만 parllel programming을 하기 위해서 hpa와 hpb 을 동시에 사용할 것이다.
openmp, mpi

운영체체가 자동적으로 세마포의 기능을 해 줄 것이다.
mpi는 send와 recv 두 개 가지고 함

Shared Memory(OS,Semaphore)
Distributed(p0->p1) <- Shared Memory에서도 가능하다.(컴퓨터한대에서 p1->p2 가능) time-sharing 덕분이다.
메시지 전송하는 프로그램을 한 컴퓨터에서 만들 수 있다.(시분할) 대화식에 적합
```
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/046858b0-5462-412c-86ac-2b8dfbdd37fd)   
#### measure time stamp by this program (NOT TIME)
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/da305b9f-5cc0-4f65-8bbe-e52831efc08d)    
#### 다음주 과제
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/9619a5f7-2621-42c7-af57-356a530b0546)    
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/fef2757c-18f0-408a-9849-c8e287ec556c)    
#### 중간시험 
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/e5b7ab78-8f96-476b-aeb7-564d755ad5d7)    
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/554efbb5-dc5b-4180-a119-71f361298573)    
```
Computer Structure Review

Computer A의 실행시간이 10 B의 실행시간이 15일때 A의 성능은 A Performance/B Performance = B execution time/ A execution time = 15/10 1.5배 좋다.
Execution time이 적을 수록 좋다<- Performance와 반비례 관계이다.

두 번째 과제에서 gettimeofday 함수를 사용해야 한다. 클럭이 실행되는 타임스탬프를 계산해주는 함수. not time

how long it takes. 실행시간을 구하여라.
same directory에서 turnin 명령어를 써라.
combine area.c with millieseconds

open the zoom and ask to professor. 다음 주는 출석 없는데 질문이 있으면 줌으로 해라.

midterm에서 value의 의미를 알아야함
Clock rate = 3 * 10^9 HZ = number of clock cycle
CPU Time = 1/Clock rate = 0.33 ns (theoretical time)

CPU : 800MHz Mult 4cycles Add 2cycles -> how many cycles -> (4+2) 6 cycles * N =200 6*200 = 1200
1200/800*10^6 = 1.5*10^-6

+ : ADD ++ : INC for(i=0;i<N;i+=1)

CPU cycle의 개수는 instruction의 수 x instruction 1개 당 cycle의 수로 표현할 수 있다.
1000000 * 0.43 * 1 + 1000000 * 0.21 * 2 ~
1000000(0.43*1+0.23*2+~)

cpu time = execution time = 1/performance

GHz Millions of floationg point operations per second(M : Mega)

FLOPS = Floating point operations/execution time
MFLOPS = FLOPS * 10^-6
GFLOPS = FLOPS * 10^-9

0.2MFLOPS = 0.0002GFLOPS

숙제는 GFLOPS

FLOPS가 몇 개인지 계산(손으로 찾아야함)

FLOPS * 10^-6 = 10^6 곱하면 줄어듬 -> GFLOPS

좋은 점: 서로 다른 컴퓨터를 비교하는 데 좋다.
나쁜 점: 더하기, 빼기, 나누기에 같은 부동 소수점 계산을 하는 문제점이 있다. (같지않음에도)

파일이름 area.c

+= floating point process가 적은쪽으로 짜봐라
시간비교도 해보고 flops 개수가 다름

시간 계산은 for부터 print 앞까지 print는 시간이많이 걸리는 함수다.
finding flops의 개수 
```
## Lecture 3
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/aff3dece-d1e0-4721-a713-77b54f16ae36)     
```
Shared memory IPC 0666; 유닉스에서 data 공유 마스

다음 주 월요일 실습시간에 Shared memory를 교수님꺼랑 비교
key data 를 치면 친 값이 더해져 나간다.
세마포

id 만들고 shared memory만드는 부분

client (key = 아무숫자나 치면됨)

다음주 수업에는 client 만들고
서브프로그램은 28일까지

#pragma omp parallel for는 for 루프를 여러 스레드로 분할하여 각 스레드가 반복문의 일부를 병렬로 실행하도록 합니다.
 이를 통해 성능을 향상시키고 다중 코어를 활용할 수 있습니다.

# <-로 시작하는건 cpp(c 전처리 pre processor) 언어다

1fork -> 4 thread -> 1join
```
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/23bb4f92-7518-4f15-9b8a-43542477fe89)
```
id 마다 num_thread 는 4
tid 는 id 번호(0~3)라서 랜덤임 -> 자기편한대로 실행해서
critical section <- zone with 세마포 임계구역 <- 이거 넣어주면 manual 세마포
output 결과값은 보장가능 

과제에는 세마포가 있어야한다.
```
## 23.09.26

#### Parallel Sorting Swap
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/9e661c2b-746f-4acb-a324-766df2984f30)    
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/749f3705-0f44-4168-babf-0d05f01f5ec0)
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/355b3d86-682c-49c0-9735-be45dc4c18ea)    
![image](https://github.com/wonchihyeon/High_Speed_Computing/assets/58906858/6f00cf6d-9836-434a-8c95-d4c940409f4e)  
```
Sortingn odd,even 분리해서 병렬로 구함 swap value

홀수번째에있는것 앞뒤로 Compare & Swap
짝수번째에있는거 앞뒤로 Compare & Swap

OpenMP # 전처리기 넣으면서 Block이 추가된다.

#pragma omp parallel for 여기에 shared, private를 써서 넣으면 스레드 별로 구분되어져서 계산되어짐

#pragma omp parllel for <- A[i] A는 shared memory이고 i를 pragma omp parallel for가 계산해줌

omp_set_num_thread(NT) <- #nt (number of thread 스레드의 수)를 선언해준다.
```
## 23.10.10 
(OpenMP 보조 지시어)[https://m.blog.naver.com/njuhb/140156068178]    
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/3e53605a-25be-4f33-a704-053107e3df59)
```
parallel program을 컴파일할때는 cc -fopenmp area.c -o area 의 형태로 컴파일한다.

전역변수 area로 계산결과를 취합할 때 한 개의 스레드만 진입할 수 있도록 pragma omp atomic을 사용한다.
대신에 reduction 보조 지시어를 사용하여 reduction (+:area) 이렇게 (operater:전역변수) 이렇게 사용도 가능하다.

Splitting #pragma omp for로 나눈다.

동기화 -> 시간버는용도

```
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/55ae8727-9738-47c5-b4ff-a7e6e176a2d0)    
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/9791a17e-44b6-49d0-95b2-87259b90fe3a)    
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/b40bbc4d-cf17-43b1-8298-ea5f66f64287)     
```
A[i-1]에서 thread1의 초깃값을 알 수 없기 때문
thread0 에서 thread1으로 갈 때 값을 잃었다. 랜덤한 값 출력

solution 해결방법 -> 이때 split해서 thread0이 모두 끝나면 B가 실행되도록
for 구문을 분리한다. #pragma omp parallel for로

synchronization

A[12] = Vector Array 벡터
sum = Scalar 스칼라

sum은 전역변수이름 
reduction(+:sum)

A[0]~A[3] 까지 합한 것을 local area <- private
sum += local area <- sum is public

총 12개 쓰레드4개면 하나의 스레드가 3개씩 계산한다.

thread는 순서가 랜덤임

각스레드가 끝난 결과값을 모두 더함
각스레드가 끝난 결과값으 모두 곱함

각 스레드의 마지막 꺼를 다더함
각 스레드의 마지막 꺼를 다곱함

oscillation 진동 +1, -1으로 변경해가면서 더함

진동하는 것을 private oscillation 을 넣어준다.
```

#### 중간고사 
```
온라인 시험 월요일
다다음주 월요일 
```

```
reduction이 critical/atomic 보다 빠른 이유? 두번씩 나눠서 계산
```
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/a918c58c-06d0-406d-b31d-0878009378a1)     
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/f75ad9ee-620f-43c2-9e2a-8e97a90f1ab7)     
```
MPI (Message Passing Interface)

공유메모리-> openMP 사용 가능

portable library 이식성이 있는 라이브러리

MPI 프로그램<- Window, IOS, LINUX 어디에서나 가능

-L location 경로
-lmpich libmpich.a
-lm
-I : include 파일 경로

lib 경로에 -lmpich 이름으로 저장된다.
libmpich.a이름으로 저장된다.

mpicc ~.c
mpiexec -n 10 a.out

mpich ch<- 카멜레온 약자 chameleon
```
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/2ce92745-ea56-4b81-9e7e-311a4e0058ac)

```
MPI_init, MPI_Finalize 이 함수는 필 수적이다.

#include "~.h" user 파일
#include <> system 파일

Convention 약속
MPI_Aaa : function 
MPI_AAA : MPI-defined identifier 

얼마나 많은 processor가 있을 까를 결정한다.
omp_get_num_thread()
->
int MPI_Comm_size(
   MPI_Comm comm <- in
   int *number_of_processes <- out call by value 함수에서 변수를 바꿀때 포인터쓴다. 
}

omp_get_thread_num()
->
int MPI_Comm_rank(
   MPI_Comm comm
   int *rank
}

int MPI_Send, int MPI_Recv

다똑같은데
send 파라미터 6개(dest출발) ,recv 파라미터 7개(source)(status 추가)

6개를 지역변수로 선언(np, pid, dest, tag, message, status)

mpiexec -n 10 hello
&np <- 10
&pid <- 0~9

MPI_Get_Processor_name(processor_name, &name_len)
printf("%s, rank %d\n", processor_name, pid);

pid == 0 <- send
sprintf("message,)
for(dest =1; dest <np; dest++) {
  MPI_Send(message, strlen(message)+1 <- message +1 <- '\0'
MPI_COMM_WORLD <- everything, ignore

보내는 입장에서는 9번 보내는데 받는쪽에서는 한번만 받는다.
else MPI_Recv(message, 100, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &Status)
MPI_Finalize();

받을때 0한테 다 받는다.

MPI_COMM_WORLD <- 무시 ignore 전체를 나타내는 숫자다

hpclab은 6개밖에 없는데 
processes: 운영체제서 오는 거 
processors : cpu를 실제로 나타내는 것
```
#### 중간고사 문제 MPI_Recv를 채우시오
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/cc3bb7e7-6f7e-4a79-9bc5-9aab6a18498e)
```
exam

p2p : peer 2 peer, point 2 point 까지

pid가 달라서 다른 값을 가진다
p0 는 0 1 2 3 4 5
p1 은 6 7 8 9 10

MPI_SEND를 채우시오
MPI_Send(A, N/2, MPI_FLOAT, 0, tag, MPI_COMM_WORLD);

MPI_Recv를 채우시오
MPI_Recv(A+N/2, N/2, MPI_FLOAT, 1, tag, MPI_COMM_wORLD, &status)
A+N/2 N/2만큼 더 가야한다. tag가 0이 아니라 1이 되어야 함

3번일때 MPI_Recv를 채우시오
MPI_Recv(A+N/3, N/3, MPI_FLOAT, 1, tag, ~)
MPI_Recv(A+2*(N/3), N/3, MPI_FLOAT, 2, tag, ~)

N/3을 local_N에 넣어서 사용 2프로세스가 보냄
N/2을 local_N 1프로세스가 보냄

N ->4
mpiexec -n 4 prog

N/3의 3을 MPI_size를 사용해서 대체 가능하다.

SPMD Single Program으로 Multi Data

main 프로그램 안에 데이터 Send, Receive를 넣어서 데이터 돌아다님
```
## Araa OpenMP
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/61e1ea16-9cc8-42f3-8208-0a73ce708b51)
## Area MPI
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/07c96632-cc72-41fe-8179-8abb291a2d65)

## 23.10.31
### HPC(High Performance Computing)
```
2개의 array를 더하는데 # decomposition
루프를 24번하지말고 각각에서 더하고

hpclab(6)
hpalab(16)
hpb(16) ->38개 프로세스

mpiexec -n 5 -machinefile mf greetings

mfile

2개는 hpa, 3개는 hpb 프로세서로 돌림
```
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/287715e7-2ac3-413e-b034-a50b2e980626)     
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/968d054c-9e4c-49a2-a025-61dc048da5c7)          
![image](https://github.com/chihyunwon/High_Speed_Computing/assets/58906858/1614a58e-5a0f-4d61-a86f-bb6802b25bf1)        
```
collective communication :그룹 커뮤니케이션

브로드캐스팅 : root p0가 다른 프로세스에게 같은 메시지를 보낸다.

mpi_Bcast

message in -> root out -> 다른 모든 프로세서

send, recv 5줄을 mpi_bcast 한줄로 축약가능하다.

root = 보내는 pid 번호

mpi_reduce => reduce -> +,- 같은 연산작업

MPI_Reduce(operand연산자, result(get value from the root), count(how many), type, operator, root, comm)

operator에는 여러가지가있는데 sum, prod가 자주 쓰인다.

land -> logical and
band -> binary and 

float area, local_area로 hw에는 수정하면된다.

MPI_Reduce(local_data, &data

local_data를 global data(data)

MPI_Send(&data)가 MPI_Send(&local data)로 수정되어야 함

Dot product가 과제 hw5랑 비슷하다.

dot_prod 함수에서 루프 n <- local_n

과제에서 두번째 부분이다. composition

local_dot을 dot에 더한 후에 return 한다.

root 빼고 나머지는 같은 행동을 각각 할때

1. bcast 는 같은 메시지를 전달하는거 0이아니라 root 왜냐면 root는 반드시 0이아니다 임의의 프로세스가 될 수 있기 때문
2. reduce는 같은 메시지를 받아서 축적되서 한 값으로 계산되는 것 

MPI_Reduce(operand root가아닌 것, root result)

maxloc, minloc 몇번째위치 sort

reduce는 받아서 data에 받은 다음 축적해서 더함

다음 주 월요일에 저번 hw4를 reduce를 쓰는 것으로 수정하는 과정

array를 줄 때 포인터를 쓰지 않고 x[], y[]

이번숙제 decomposition, 분산(e.g.2는)만 한거, composition,

n은 local dot의 size

최종적으로 root에 보낸다.

파트너 7파트너 3

eor_bits 나중에 숙제는 sum이 아니라 곱셈

eor_bits >> 1 -> 처음에는 8개 그다음에는 4개 그다음엔 2개

eor_bit가 반씩 줄어들면서 3번만 하면 되고

eor_bits가 자기 바트너 정하고 파트너한테

N = 3 일때 파트너 구하는 것

N=3 i=0, eor_bits =4 8이였는데 4로 줄어듬
파트너 0에 대한 것은 0<-4, 1<-5, 2<-6, 3<-7

i=1 eor_bits=2, 0<-2, 1<-3  step2

i=2, eor_bits=1 partner 0<-1  step1

P2P의 복잡도를 collective를 사용해서 logN으로 줄였다.
```
## 23.11.07 
![image](https://github.com/mr-won/High_Speed_Computing/assets/58906858/df482cf7-09da-4251-887c-f7b6eba5c86e)    
![image](https://github.com/mr-won/High_Speed_Computing/assets/58906858/815d7c6e-8eae-42dd-a6bb-013d847e8062)    
```
Scatter 뿌리다(decomposition). Gather 모으다(composition)

배열을 분리해서 뿌리면(send)하면 분해하는 것과 같다
p0 one task, send data, send_count
all other task , recv_data, recv_count, root =0

p0 A가 send B가 recv

recv_data 빼고 다 in

mpi_scatter의 앞의 3개 매개변수는 mpi_send를 위한 것, 뒤의 3개 매개변수는 mpi_recv를 위한 것

gather의 포맷은 scatter와 비슷하다.(send,recv의 의미만 다를뿐)
포맷은 send, recv 순서가 고정이니까 scatter일때 send가 A가 앞에 gather일때 send가 B가 앞에

p0 A가 recv B가 send
```
![image](https://github.com/mr-won/High_Speed_Computing/assets/58906858/0029f24c-5321-43ff-a485-4b4e17d4082d)    
![image](https://github.com/mr-won/High_Speed_Computing/assets/58906858/c926ba9d-16a4-41d9-b27b-3cee46cec1b2)    
```
11일까지인 숙제 Bcast2를 만든다.

N은 parallel prefix sum 알고리즘과 같다.

print N

p2p send & recv

i = 0 부터가 아니라 N 만큼

8개가 있으면 STEP이 LOG(8) => 3
16개가 있으면 STEP이 LOG(16) => 4
지난주에 한 예제를 참고

차이가 있다면 Reduce하는 것인데 bcast는 반대방향

프로그램은 10줄이 안되면서 쉽다.
```
## Scatterv and Gatherv

```
다음주 Scatterv and Gatherv
v is very
```
## hw6 과제답
![image](https://github.com/mr-won/High_Speed_Computing/assets/58906858/e8a540d3-fe05-474e-844b-a5d1e4d6c062)
```
실행할 때 mpiexec -np 4 ./bcast
```
## 23.11.14
![image](https://github.com/mr-won/High_Speed_Computing/assets/58906858/62276b94-b52f-49b0-a007-0a5b1d258ad4)      
![image](https://github.com/mr-won/High_Speed_Computing/assets/58906858/714eaa42-c884-43aa-9c18-f441d4c60975)     
```
루프를 줄이는 게 좋다.

Scatterv, Gaterv는 메시지의 크기가 다양할 때 쓴다.

displacements : 4개로 나누는데 not same size
gap  0부터 떨어진 것 displacements
displs[0] = 1 0에서 1만큼 떨어진 곳 1

p1이 가지는 값은 무엇인가 20 30 40 <- 기말고사 시험

hw7에 사용됨

gather는 리버스다.

gather하면서 p0가 덮어써진다.

Homework 7

여러개의 프로세스가 같은 일을 하도록

colletive도 되고 p2p도 되는데 보내고자 하는 데이터형을 만들어서 보낸다.

타입이름을 쓸 수 없다. MPI_INT, MPI_FLOAT, MPI_CHAR MPI가 만들어놨는데
INDATA_T는 MPI_INDATA라고 쓸 수 없다. 유저가 만든 것은 정의할 수 없다.

array랑 structor는 메모리 상에 연속된 데이터라 포인터를 사용하기 쉽다.

그래서 type을 만들건데 MPI_Type_struct로 만든다.

MPI_Aint displacements <- 포인터 각 변수가 위치한 주소를 가르킨다.

MPI_Type_commit은 MPI_Type_struct의 마지막 변수로 만든 것을 넣어서 호출하는 용도임

1. structure type
Array type가 비슷하지만 서로 다른 데이터 타입과 위치를 가진다.

밑에서 위로 찍힌다.

주소를 사용해서 a에 합치는 방법 <- constructor 
bcast a

2. vector type

stride datatype 보폭

벡터는 배열은 비슷한데 안의 내용의 타입이 다른것
stride < - 벡터의 크기

block length <- 각 벡터의 크기
vector의 타입

열을보낸다 몇개의 열 5

stride 0 5 <- 이전 요소를 기준으로 한다.

mpi_commit  후

보낸다. A벡터 3열에 위치한 것을 2열에 위치하도록 보낸다.
받는 것을 적어라 하면 A[0][1] <- 기말고사 시험

대각선으로 받겠다하면 column_type2를 만드는 데 stride를 6으로 하고
column_type1으로 보내고 column_type2으로 받으면 된다.

3. index type
앞에서 한거랑 같음 displs, length(count)
크기가 다를 때 사용한다.

상위 삼각형<- 상 삼각행렬
크기가 다르다. -> index Type
dipls를 사용한 index type을 사용하여 해결한다.

첫 번재 행 block_lengths[i] = N-i; // 5 4 3 2 1
row면 block_lengths[i] =i+1

hw7은 scatterv랑 gatherv를 사용해서 만든다.
```
![image](https://github.com/mr-won/High_Speed_Computing/assets/58906858/2cfe8f6e-0e6c-443b-8e7c-303a61892076)
## HW8
![image](https://github.com/mr-won/High_Speed_Computing/assets/58906858/0b3d7538-a3da-4ba9-a2d4-2de7bb297c68)



