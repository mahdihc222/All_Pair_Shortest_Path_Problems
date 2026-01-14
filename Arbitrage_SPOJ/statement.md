# ARBITRAG – Arbitrage

## Problem Description

Arbitrage is the use of discrepancies in currency exchange rates to transform one unit of a currency into more than one unit of the same currency.

For example, suppose that:

- 1 US Dollar buys **0.5 British Pounds**
- 1 British Pound buys **10.0 French Francs**
- 1 French Franc buys **0.21 US Dollars**

Then a trader can start with **1 US Dollar** and convert:

1 × 0.5 × 10.0 × 0.21 = 1.05 US Dollars


This results in a **5% profit**, which means arbitrage is possible.

Your job is to write a program that takes a list of currency exchange rates as input and then determines whether arbitrage is possible or not.

---

## Input

The input file will contain one or more test cases.

On the first line of each test case there is an integer **n** (`1 ≤ n ≤ 30`), representing the number of different currencies.

The next **n** lines each contain the name of one currency.
Within a name, no spaces will appear.

The next line contains one integer **m**, representing the length of the table to follow.

The last **m** lines each contain:
ci rij cj

where:
- `ci` is the source currency
- `rij` is a real number representing the exchange rate from `ci` to `cj`
- `cj` is the destination currency

Note that `ci` and `cj` may be the same currency.
Exchanges which do not appear in the table are impossible.

Test cases are separated from each other by a blank line.

Input is terminated by a value of zero (**0**) for `n`.

---

## Output

For each test case, print one line telling whether arbitrage is possible or not in the following format:

```
Case k: Yes
or
Case k: No
```

where `k` is the test case number (starting from 1).

---

## Example

### Input
```
3
USDollar
BritishPound
FrenchFranc

3
USDollar 0.5 BritishPound
BritishPound 10.0 FrenchFranc
FrenchFranc 0.21 USDollar

3
USDollar
BritishPound
FrenchFranc

6
USDollar 0.5 BritishPound
USDollar 4.9 FrenchFranc
BritishPound 10.0 FrenchFranc
BritishPound 1.99 USDollar
FrenchFranc 0.09 BritishPound
FrenchFranc 0.19 USDollar

0
```

### Output
```

Case 1: Yes
Case 2: No

```

---

## Constraints

- Maximum number of currencies: **30**
- Multiple test cases
- Floating-point precision must be handled carefully

---

## License

This problem is intended for educational and competitive programming practice.
