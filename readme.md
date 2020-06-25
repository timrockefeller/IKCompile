## IKCompile

IIK Compile.

Stepping to Universal Complier.

## Dev Route

- [x] Tokenizer
  - [x] PL0 support
  - [ ] Arrange Code Logic
- [x] Parser
- [ ] Emiter

## Build

```shell
mkdir build
cd build
cmake ..
```
Follow the instruction show in cmake documentation.

## Usage

A client tool assigned in `src/test/02_cli`

### Overall

```shell
$ ./bin/ikcl-pl0.exe help
```
output:
```
IKCL-PL0 client commands:

  tok   <file>                 --- List Tokens of the file.
  par   <file>                 --- Parse the file.
  bye                          --- Exit the client.
```
### Tokenizer
```shell
$ ./bin/ikcl-pl0.exe tok asset/test.PL0 
```
output:
```
no      |type   |src
0       |0      |VAR
1       |8      |x
2       |27     |,
3       |8      |sqr
4       |27     |,
5       |8      |temp
6       |29     |;
7       |2      |PROCEDURE
8       |8      |square
9       |29     |;
10      |6      |BEGIN
11      |8      |sqr
12      |10     |:=
13      |8      |x
14      |14     |*
15      |8      |x
16      |7      |END
17      |29     |;
18      |6      |BEGIN
19      |8      |x
20      |10     |:=
21      |9      |1
22      |29     |;
23      |4      |WHILE
24      |8      |x
25      |23     |<=
26      |9      |10
27      |5      |DO
28      |6      |BEGIN
29      |3      |CALL
30      |8      |square
31      |29     |;
32      |11     |!
33      |8      |sqr
34      |29     |;
35      |8      |x
36      |10     |:=
37      |8      |x
38      |16     |+
39      |9      |1
40      |7      |END
41      |7      |END
42      |28     |.
```

### Parse

```shell
$ ./bin/ikcl-pl0.exe par asset/test_fault.PL0 
```
output:
```
[!!] syntax error: +
on token 42
```
