# CSE120-PA3Test

## Description

There are 4 tests in the `piazzatest.c` file. Most of them come from the ideas in piazza posts.

- Test 1:
  
  - A test to check whether you can handle 10 cars with different speed from the same side.
  
- Test 2:
  
  - From [Piazza 393](https://piazza.com/class/k51m7y75yswei?cid=393)
  
  - AB first, then E, and then CD.

- Test 3:

  - From [Piazza 414](https://piazza.com/class/k51m7y75yswei?cid=414)
  
  - Each side take turns to make a car enter the road.

- Test 4:
  
  - Just Test 3 with a little bit modification (delay).

## How to Test

Download `piazzatest.c` to your `pa3/` folder on ieng9 server. Add

```
piazzatest: piazzatest.c aux.h umix.h mycode3.o
	$(CC) $(FLAGS) -o piazzatest piazzatest.c mycode3.o
```

to your `Makefile`. Make the test executable file with command

```
make piazzatest
```

And then

```
./piazzatest <test-id>
```

where `<test-id>` is an integer between 1 and 4. You can check the code to see more details.
