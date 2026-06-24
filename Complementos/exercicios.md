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
```c
int b = 5, a = 3;
for (int i = 0; i < b; i++) {
    printf("%d\n", a);
}
```
```c
int b = 5, a = 3;
for (int i = 0; i < b; i++) {
    printf("%d\n", ++a);
}
```
```c
int b = 5, a = 3;
for (int i = 0; i < b; i++) {
    printf("%d\n", a++);
}
```
```c
int b = 5, a = 3;
for (int i = 0; i < b; i++) {
    printf("%d\n", a++ + i);
}
```
```c
int b = 5, a = 3;
for (int i = 0; i < b; i++) {
    printf("%d\n", a++ + --b);
}
```
```c
int b = 7, a = 3;
for (int i = 0; a < b; i++) {
    printf("%d\n", a++ + --b);
}
```
```c
int v[10];
for (int i = 0; i < 5; i++) {
    v[i] = i;
    v[i + 5] = 5 - i;
}
for (int i = 9; i > 0; i--) {
    printf("%d ", v[i]);
}
```
```c
int v[10] = { 1, 2, 3, 4 };
for (int i = 0; i < 5; i++) {
    v[i] = i;
    v[i + 5] = 5 - i;
    for (int j = 3; j < 7; j++) {
        printf("%d ", v[j]);
    }
}
```
```c
int v[10] = { 1, 2, 3, 4 };
for (int i = 0; i < 5; i++) {
    v[i] = i;
    v[i + 5] = 5 - i;
    for (int i = 3; i < 7; i++) {
        printf("%d ", v[i]);
    }
}
```
```c
int v[10] = { 1, 2, 3, 4 };
for (int i = 0; i < 5; i += 2) {
    v[i] = i;
    v[i + 5] = 5 - i;
    for (int j = 3; j < 7; j++) {
        printf("%d ", v[i]);
    }
}
```
```c
char s[] = "3 Abacates";
int t = strlen(s);
for (int i = 0; i < t; i += 2) {
    if (s[i] >= 'a' && s[i] <= 'z') {
        s[i] = s[i] - 'a' + 'A';
    } else if (s[i] >= 'A' && s[i] <= 'Z') {
        s[i] = s[i] - 'A' + 'a';
    }
    printf("%s\n", s);
}
```c
char s[] = "Abacates";
int t = strlen(s);
int i = 2;
int j = t - i;
while (i < j) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
    i++;
    j--;
}
printf("%s\n", s);
```
```c
int f(int x) {
    return x+1;
}
int main() {
    char s[] = "Abacates";
    int t = strlen(s);
    int i = 2;
    int j = t - i;
    while (i < j) {
        s[i] = f(s[j]);
        i++;
        j--;
    }
    printf("%s\n", s);
}
```
```c
int f(int x) {
    printf("%c ", x);
    return x+1;
}
int main() {
    char s[] = "Abacates";
    int t = strlen(s);
    int i = 2;
    int j = t - i;
    while (i < j) {
        s[i] = f(s[j]);
        i++;
        j--;
    }
    printf("%s\n", s);
}
```
```c
void f(int *x) {
    *x += 1;
}
int main() {
    char s[] = "Abacates";
    int t = strlen(s);
    int i = 2;
    int j = t - i;
    while (i < j) {
        f(&s[i]);
        i++;
        j--;
    }
    printf("%s\n", s);
}
```
```c
void f(int *x) {
    *x = *(x+1);
}
int main() {
    char s[] = "Abacates";
    int t = strlen(s);
    int i = 2;
    int j = t - i;
    while (i < j) {
        f(&s[i]);
        i++;
        j--;
    }
    printf("%s\n", s);
}
```
```c
int f(int a, int b) {
    a += b;
    return a + b;
}
int main() {
    int a = 5;
    int b = 9;
    for (int i = 0; i < 2; i++) {
        b = f(a, b);
    }
    printf("%d %d\n", a, b);
}
```
```c
typedef struct {
    int x;
    int y;
} d;
int main() {
    d a = { 5, 8 };
    d b;
    b = a;
    b.x = a.y;
    a.x = b.y + b.x;
    printf("%d %d\n", a.x, b.x);
}
```
```c
typedef struct {
    int x;
    int y;
} d;
int main() {
    d a = { 5, 8 };
    d *b;
    b = &a;
    b->x = a.y;
    a.x = b->y + b->x;
    printf("%d %d\n", a.x, b->x);
}
```
```c
typedef struct {
    int x;
    int y;
} d;
int main() {
    d a = { .y = 8 };
    d *b;
    b = &a;
    b->x = a.y;
    a.x = b->y + b->x;
    printf("%d %d\n", a.x, b->x);
}
```
```c
typedef struct {
    int x;
    int y;
} d;
void f(d c, d *p) {
    c.x += p->y;
    p->x -= c.x;
}
int main() {
    d a = { .y = 8 };
    d b = { 10, 4 };
    f(a, &b);
    printf("%d %d\n", a.x, b.x);
}
```
