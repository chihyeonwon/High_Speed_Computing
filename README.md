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
