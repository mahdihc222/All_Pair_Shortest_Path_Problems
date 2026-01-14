# Shortest Routes Between Cities

## Problem Description

There are **n cities** and **m roads** between them. Your task is to process **q queries**, where for each query you must determine the **length of the shortest route** between two given cities.

## All roads are **two-way (bidirectional)** and have a positive length.

## Input

The first line contains three integers:
n m q

where:

- `n` = number of cities
- `m` = number of roads
- `q` = number of queries

The next **m lines** describe the roads. Each line contains three integers:
a b c
meaning there is a road between cities `a` and `b` with length `c`.

The next **q lines** describe the queries. Each line contains two integers:
a b

For each query, determine the length of the shortest route between cities `a` and `b`.

---

## Output

For each query, print:

- the length of the **shortest route** between the given cities, or
- `-1` if **no route exists**.

Each answer should be printed on its own line.

---

## Constraints

- \(1 \le n \le 500\)
- \(1 \le m \le n^2\)
- \(1 \le q \le 10^5\)
- \(1 \le a, b \le n\)
- \(1 \le c \le 10^9\)

---

## Example

### Input

4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

### Output

5
5
8
-1
3

---

```

```
