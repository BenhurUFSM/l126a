## Exercícios

- O que será impresso por cada trecho de código C abaixo?

```c
int a;
int b;
a = 5;
b = a;
a = 7;
printf("%d %d\n", a, b);
```
```c
int a;
int b;
a = 5;
b = 7;
a = a + b;
b = a - b;
a = a - b;
printf("%d %d\n", a, b);
```
```c
int a;
int b;
a = 3;
b = 7;
a = a + b;
b = a / 2;
a = b / 2;
printf("%d %d\n", a, b);
```
```c
float a;
int b;
a = 3;
b = 7;
a = a + b;
b = a / 2;
a = b / 2;
printf("%f %d\n", a, b);
```
```c
float a;
int b;
a = 3;
b = 7;
a = a + b;
b = a / 2.;
a = b / 2.;
printf("%f %d\n", a, b);
```
```c
float a;
float b;
a = 3;
b = 7;
a = a + b;
b = a / 2;
a = b / 2;
printf("%f %f\n", a, b);
```
```c
int a = 3;
int b = 8;
while (a < b) {
    printf("%d ", a);
    a += (a + b) / 2;
}
printf("%d\n", a);
```
```c
int a = 3;
int b = 8;
while (a < b*2) {
    printf("%d %d ", a, b);
    a += (a + b--) / 2;
}
printf("%d %d\n", a, b);
```
```c
int a = 3;
int b = 8;
while (a < b*2) {
    printf("%d %d ", a, b);
    a += (a + --b) / 2;
}
printf("%d %d\n", a, b);
```
