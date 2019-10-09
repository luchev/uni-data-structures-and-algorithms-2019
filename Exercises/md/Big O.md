# Big O exercise

## 1

```c++
int foo(int a, int b) {
    return a + b;
}
```

## 2

```c++
for (int i = 0; i < n; i++) {
    cout << i;
}
```

## 3

```c++
for (int i = 0; i < n; i++) {
    for (int k = 0; k < 5; k++) {
        cout << i;
    }
}
```

## 4

```c++
for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
        cout << i;
    }
}
```

## 5

```c++
for (int i = n; i > 0; i--) {
    for (int k = n / 2; k < n; k++) {
        cout << i;
    }
}
```

## 6

```c++
for (int i = 0; i > n; i++) {
    for (int k = n; k > 0; k--) {
        cout << 1;
    }
}
```

## 7

```c++
for (int i = n; i > 0; i /= 2) {
    cout << 1;
}
```

## 8

```c++
for (int i = 0; i < n; i++) {
	for (int k = i; k < n; k++) {
        cout << 1;
        k += n;
    }
}
```

## 9

```c++
for (int i = 0; i < n; i++) {
    cout << 1;
    cout << 420;
    for (int i = 5; i < 10; i++) {
        cout << 420;
    }
    cout << 5 + 72;
    cout << "Some text";
    cout << "More text";
    cout << "There is not even a new line break here";
    cout << 42;
    break;
}
```

