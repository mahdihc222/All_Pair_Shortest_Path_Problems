# Problem: VVIP Road Discount

| Time Limit | Memory Limit |
| :--------: | :----------: |
|   2.0 s    |    256 MB    |

## Description

You are given a directed graph with **N** cities and **M** roads. Each road connects two cities and has a specific travel cost (weight).

The government has designated **K** specific roads as **"VVIP Roads"**.

If a traveler's path includes **at least one** VVIP Road, they are granted a special "VVIP Status" for the entire journey. This status reduces the cost of **every edge** on that path by **1** (edge weights cannot go below 0).

Your task is to answer **Q** queries. For each query $(u, v)$, find the minimum cost to travel from city $u$ to city $v$. You should consider both:

1.  Standard paths (no VVIP discount).
2.  VVIP paths (paths that traverse at least one VVIP road and receive the discount on all edges).

## Input Format

1.  The first line contains two integers **N** and **M** — the number of cities and roads.
2.  The next **M** lines describe the roads:
    - `u v w` — a directed road from city $u$ to city $v$ with weight $w$.
3.  The next line contains an integer **K** — the number of VVIP roads.
4.  The next **K** lines describe the VVIP roads:
    - `u v` — indicating that the specific road from $u$ to $v$ is a VVIP road. (Guaranteed to be one of the M roads given above).
5.  The next line contains an integer **Q** — the number of queries.
6.  The next **Q** lines describe the queries:
    - `u v` — find the shortest path from city $u$ to city $v$.

## Output Format

For each query, output a single integer: the minimum travel cost. If city $v$ is unreachable from $u$, output `-1`.

## Constraints

- $2 \le N \le 500$
- $1 \le M \le N^2$
- $1 \le w \le 10^9$
- $1 \le K \le M$
- $1 \le Q \le 10^5$

## Examples

### Example 1

**Input**

```
4 4
1 2 5
2 3 5
3 4 5
1 4 14
1
2 3
1
1 4
```

**Output**

```
12
```

**Explanation**

- **Path A (Direct):** with weight 14. Cost = **14**.
- **Path B (Via VVIP):** .
- Original weights: .
- This path uses the edge , which is in the VVIP list.
- Discount applies to **all** edges: .

- Since , the answer is **12**.

### Example 2

**Input**

```
3 3
1 2 10
2 3 10
1 3 25
1
1 3
1
1 3
```

**Output**

```
20
```

**Explanation**

- **Path A (Through 2):** . Cost = . (No VVIP edge used, no discount).
- **Path B (Direct VVIP):** . Original cost 25. VVIP edge used, so discount applies: .
- Minimum is **20**.
