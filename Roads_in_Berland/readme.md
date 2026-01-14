# C. Roads in Berland

| Time Limit | Memory Limit  |
| :--------: | :-----------: |
| 2 seconds  | 256 megabytes |

## Description

There are **n** cities numbered from 1 to **n** in Berland. Some of them are connected by two-way roads. Each road has its own length — an integer number from 1 to 1000. It is known that from each city it is possible to get to any other city by existing roads. Also for each pair of cities it is known the shortest distance between them.

Berland Government plans to build **k** new roads. For each of the planned road it is known its length, and what cities it will connect.

To control the correctness of the construction of new roads, after the opening of another road Berland government wants to check the sum of the shortest distances between all pairs of cities. Help them — for a given matrix of shortest distances on the old roads and plans of all new roads, find out how the sum of the shortest distances between all pairs of cities changes after construction of each road.

## Input

The first line contains integer **n** ($2 \le n \le 300$) — amount of cities in Berland.

Then there follow **n** lines with **n** integer numbers each — the matrix of shortest distances. $j$-th integer in the $i$-th row — $d_{i, j}$, the shortest distance between cities $i$ and $j$.

It is guaranteed that $d_{i, i} = 0, d_{i, j} = d_{j, i}$, and a given matrix is a matrix of shortest distances for some set of two-way roads with integer lengths from 1 to 1000, such that from each city it is possible to get to any other city using these roads.

Next line contains integer **k** ($1 \le k \le 300$) — amount of planned roads.

Following **k** lines contain the description of the planned roads. Each road is described by three space-separated integers $a_i, b_i, c_i$ ($1 \le a_i, b_i \le n, a_i \ne b_i, 1 \le c_i \le 1000$) — $a_i$ and $b_i$ — pair of cities, which the road connects, $c_i$ — the length of the road. It can be several roads between a pair of cities, but no road connects the city with itself.

## Output

Output **k** space-separated integers $q_i$ ($1 \le i \le k$). $q_i$ should be equal to the sum of shortest distances between all pairs of cities after the construction of roads with indexes from 1 to $i$.

Roads are numbered from 1 in the input order. Each pair of cities should be taken into account in the sum exactly once, i.e. we count unordered pairs.

## Examples

### Example 1

**Input**
2
0 5
5 0
1
1 2 3

**Output**
3

**Input**
3
0 4 5
4 0 9
5 9 0
2
2 3 8
1 2 1

**Output**
17 12
