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
