# Logistics Routes – Problem Variations

This repository contains multiple variations of shortest-path problems on weighted graphs, each introducing a different **constraint, discount, or penalty rule**.  
All problems are inspired by real-world logistics, toll systems, and conditional route optimization.

Below is a brief description of each variant implemented in this repository.

---

## 📂 File Descriptions

### **City_Tolls.cpp**

Implements shortest-path computation where each city may impose an additional toll cost.  
Useful for modeling urban congestion charges or city-entry fees.

---

### **Conditional_Discount_Two_hubs.cpp**

Applies a discount **only if the path passes through two specific hub cities**.  
Models logistics incentives that require visiting multiple checkpoints.

---

### **Discounted_Only_After.cpp**

Edge cost discounts are applied **only after passing a certain city**.  
Before reaching that city, all edges retain their original costs.

---

### **List_of_Roads_included.cpp**

Instead of only computing distances, this version also **outputs or tracks the actual roads used** in the shortest path.  
Helpful for route reconstruction and auditing.

---

### **Logistic_Routes_Discount_Vertex.cpp**

The main problem variant where **all edges on a path get discounted if the route passes through a specific vertex**.  
Represents a government quality-control or incentive city.

---

### **Logistic_Routes_Including_mandatory_city.cpp**

Finds the shortest path **that must include a mandatory city**, regardless of whether it is optimal otherwise.  
Common in constrained delivery or compliance-based routing.

---

### **Logistic_Routes_Penalty_Vertex.cpp**

Instead of a discount, passing through a specific vertex **adds a penalty** to the path cost.  
Models delays, inspections, or congestion zones.

---

### **Time_Limited_Discount.cpp**

Discounts apply **only within a certain time or step limit** in the path.  
Represents temporary promotions or time-sensitive incentives.

---

### **Two_Phase_Discount.cpp**

Uses a **two-phase shortest path model**:

- Phase 1: before meeting a condition (e.g., reaching a city)
- Phase 2: after the condition, with modified edge costs  
  Commonly solved using state-expanded Dijkstra or Floyd–Warshall.

---

## 📝 Notes

- All variants are based on **graph shortest-path algorithms**.
- Techniques used across files include:
  - Dijkstra with state tracking
  - Floyd–Warshall
  - Graph transformation
- Designed for **competitive programming and algorithmic practice**.

---

## 📄 README

See `readme.md` for the main problem statement and input/output format.

---

## License

This repository is intended for **educational and competitive programming use**.
