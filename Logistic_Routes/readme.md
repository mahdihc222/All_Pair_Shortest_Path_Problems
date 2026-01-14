# Discounted Shortest Paths via Quality Control City

## Problem Description

A logistics company manages a delivery network represented as a **weighted directed graph**.

- Each **node** represents a city.
- Each **directed edge** represents a road with a specific cost (fuel/tolls).

The government has established a **quality control center** at a specific city **V**.  
To promote quality control, the government introduces a **discount campaign**:

> **If a delivery path passes through city V, the cost of each road (edge) on that path is reduced by 1 unit.**

Your task is to calculate the **shortest possible travel cost** between given pairs of cities, taking this discount rule into account.

---

## Input

1. The first line contains two integers:

n m

where:

- `n` = number of cities
- `m` = number of roads

2. The next `m` lines describe the roads. Each line contains: a b c

meaning there is a **directed road** from city `a` to city `b` with cost `c`.

3. The next line contains a single integer: V

representing the city where the quality control center is located.

4. The next line contains an integer: q
   representing the number of queries.

5. The next `q` lines each contain:

a b

asking for the shortest route cost from city `a` to city `b`.

---

## Output

For each query, print:

- the **shortest route cost** considering the discount rule, or
- `-1` if there is no route between the cities.

Each answer should be printed on a new line.

---

## Discount Rule Clarification

- If a path **passes through city V at least once**, then:
- **Every edge on that path** has its cost reduced by **1**.
- If a path **does not pass through city V**, edge costs remain unchanged.

---

## Constraints

- 1 ≤ n ≤ 500
- 1 ≤ m ≤ n²
- 0 ≤ a, b < n
- 1 ≤ c ≤ 10⁹
- 0 ≤ V < n
- 1 ≤ q ≤ 10⁵

---

## Example

### Sample Input

```
4 5
0 2 5
0 1 3
1 2 3
0 3 7
2 3 2
1
2
0 2
0 3
```

### Sample Output

```
4
5
```

---

##Variations

---

## License

This problem is intended for educational and competitive programming practice.
