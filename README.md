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
