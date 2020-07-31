## IKCompile

![](https://github.com/timrockefeller/IKCompile/workflows/AutoRelease/badge.svg)

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
  no|      type|src
----+----------+-----
   0|       VAR|VAR
   1|IDENTIFIER|x
   2|     COMMA|,
   3|IDENTIFIER|sqr
   4|     COMMA|,
   5|IDENTIFIER|temp
   6| SEMICOLON|;
   7| PROCEDURE|PROCEDURE
   8|IDENTIFIER|square
   9| SEMICOLON|;
  10|     BEGIN|BEGIN
  11|IDENTIFIER|sqr
  12|ASSIGNMENT|:=
  13|IDENTIFIER|x
  14|      MULT|*
  15|IDENTIFIER|x
  16|       END|END
  17| SEMICOLON|;
  18|     BEGIN|BEGIN
  19|IDENTIFIER|x
  20|ASSIGNMENT|:=
  21|    NUMBER|1
  22| SEMICOLON|;
  23|     WHILE|WHILE
  24|IDENTIFIER|x
  25|        LE|<=
  26|    NUMBER|10
  27|        DO|DO
  28|     BEGIN|BEGIN
  29|      CALL|CALL
  30|IDENTIFIER|square
  31| SEMICOLON|;
  32|     WRITE|!
  33|IDENTIFIER|sqr
  34| SEMICOLON|;
  35|IDENTIFIER|x
  36|ASSIGNMENT|:=
  37|IDENTIFIER|x
  38|      PLUS|+
  39|    NUMBER|1
  40|       END|END
  41|       END|END
  42|    PERIOD|.
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

## License

Under GPL-v3 license. All right reserved.
