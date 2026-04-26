# Greedy Algorithms - Comprehensive Study Guide

Complete reference for all greedy problems across Q3 and Q4 with initialization, code examples, and key insights.

---

## 1. FRACTIONAL KNAPSACK

**File**: [fractional_knapsack.cpp](fractional_knapsack.cpp)

**Problem**: Maximize total value by selecting items (fractions allowed) within weight capacity W

**Why Greedy**: Selecting items by highest value-to-weight ratio is optimal since we can take partial items. At each step, the greedy choice (highest ratio) maximizes value for remaining capacity.

**Greedy Strategy**:
1. Compute value-to-weight ratio for each item
2. Sort items by ratio in **descending order**
3. Greedily fill knapsack with highest-ratio items first
4. Take fractional items when needed at the end

**Key Initialization**:
```cpp
int n, w;
cin >> n >> w;

vector<double> value(n), weight(n);
for (int i = 0; i < n; i++) {
    cin >> value[i] >> weight[i];
}

// Create pairs: (ratio, (value, weight))
vector<pair<double, pair<double, double>>> items(n);
for (int i = 0; i < n; i++) {
    double ratio = value[i] / weight[i];
    items[i] = {ratio, {value[i], weight[i]}};
}

// Sort by ratio descending
sort(items.rbegin(), items.rend());
```

**Main Algorithm**:
```cpp
double total_value = 0;
double remaining_capacity = w;

for (int i = 0; i < n; i++) {
    if (remaining_capacity <= 0) break;
    
    double ratio = items[i].first;
    double v = items[i].second.first;
    double wt = items[i].second.second;
    
    double take = min(wt, remaining_capacity);
    total_value += take * ratio;  // Or: (take / wt) * v
    remaining_capacity -= take;
}

cout << fixed << setprecision(2) << total_value << endl;
```

**Proof of Optimality**:
- For fractional knapsack, the greedy choice of taking the highest value-weight ratio item is always optimal
- If an optimal solution doesn't follow this order, we can swap items to improve or maintain the solution
- This is the **exchange argument**: any non-greedy solution can be converted to greedy without losing optimality

**Complexity**: O(n log n) - sorting dominates

**Key Points**:
- ✓ Works ONLY for fractional items (0/1 knapsack requires DP)
- ✓ Must sort in descending order of ratio
- ✓ Take full items while possible, then fractional last item
- ✓ Use `setprecision()` for output formatting

---

## 2. ACTIVITY / CLASS SELECTION

**File**: [class_selection.cpp](class_selection.cpp)

**Problem**: Select maximum number of non-overlapping classes where each class has start and end time

**Why Greedy**: Selecting the class that finishes earliest leaves maximum time for future classes. This locally optimal choice leads to a globally optimal solution (maximum count).

**Greedy Strategy**:
1. Sort classes by **end time** (finish time) in ascending order
2. Always select the class that finishes earliest
3. Skip classes that overlap with last selected class
4. Repeat until all classes processed

**Key Initialization**:
```cpp
int n;
cin >> n;

vector<pair<int, int>> classes(n);  // (end_time, start_time)
for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    classes[i] = {end, start};  // Store as (end, start) for sorting by end
}

// Sort by end time (first element of pair)
sort(classes.begin(), classes.end());
```

**Main Algorithm**:
```cpp
int count = 1;
int last_end = classes[0].first;  // End time of first selected class

for (int i = 1; i < n; i++) {
    int start = classes[i].second;
    int end = classes[i].first;
    
    // Non-overlapping: class starts after or when last one ends
    if (start >= last_end) {
        count++;
        last_end = end;  // Update to current class's end time
    }
}

cout << count << endl;
```

**Proof of Optimality (Exchange Argument)**:
- Suppose optimal solution doesn't include the earliest-finishing class
- We can replace first class in optimal solution with earliest-finishing class
- This gives same or better remaining time for future classes
- Therefore, greedy solution is optimal

**Complexity**: O(n log n) - sorting dominates

**Key Points**:
- ✓ **Sort by END time**, not start time
- ✓ Select first class automatically (count = 1)
- ✓ Check `start >= last_end` (inclusive) for non-overlap
- ✓ Update `last_end` after selecting each class
- ✓ This is also called "Earliest Deadline First" (EDF) scheduling

**Example**:
```
Input: 4 classes
(10, 20), (12, 25), (20, 30), (5, 15)

Sorted by end: (5, 15), (10, 20), (12, 25), (20, 30)

Selection:
1. Select (5, 15), last_end = 15
2. Check (10, 20): 10 < 15, skip
3. Check (12, 25): 12 < 15, skip
4. Check (20, 30): 20 >= 15, select, last_end = 30

Answer: 2 classes
```

---

## 3. MINIMUM SPANNING TREE (PRIM'S ALGORITHM)

**File**: [cable_company.cpp](cable_company.cpp)

**Problem**: Connect all N nodes with minimum total edge cost while forming a tree (no cycles)

**Why Greedy**: At each step, adding the minimum-cost edge that connects an unvisited node to the MST is optimal. No local choice can violate the global optimality (Prim's correctness).

**Greedy Strategy (Prim's Algorithm)**:
1. Start from an arbitrary node (usually node 0)
2. Maintain a set of visited nodes and costs to unvisited nodes
3. Repeatedly select the **minimum-cost edge** connecting visited to unvisited node
4. Mark the new node as visited and update costs
5. Repeat until all nodes visited

**Key Initialization**:
```cpp
int N;
cin >> N;

// Adjacency matrix: mem[i][j] = edge cost from i to j
vector<vector<int>> mem(N, vector<int>(N));
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        cin >> mem[i][j];
    }
}

// Prim's algorithm tracking
vector<int> cost(N, INT_MAX);        // Minimum cost to reach each node
vector<bool> in_mst(N, false);       // Whether node is in MST
cost[0] = 0;                          // Start from node 0

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
pq.push({0, 0});  // (cost, node)
```

**Main Algorithm**:
```cpp
int total_cost = 0;

while (!pq.empty()) {
    auto [c, u] = pq.top();
    pq.pop();
    
    if (in_mst[u]) continue;  // Already processed
    
    in_mst[u] = true;
    total_cost += c;
    
    // Update costs for all adjacent unvisited nodes
    for (int v = 0; v < N; v++) {
        if (!in_mst[v] && cost[v] > mem[u][v]) {
            cost[v] = mem[u][v];
            pq.push({cost[v], v});
        }
    }
}

cout << total_cost << endl;
```

**Alternative Implementation (Without Priority Queue)**:
```cpp
int total_cost = 0;

for (int count = 0; count < N; count++) {
    // Find minimum cost edge from MST to outside
    int min_cost = INT_MAX;
    int min_node = -1;
    
    for (int u = 0; u < N; u++) {
        if (in_mst[u] && cost[u] < min_cost) {
            min_cost = cost[u];
            min_node = u;
        }
    }
    
    in_mst[min_node] = true;
    total_cost += min_cost;
    
    // Update costs
    for (int v = 0; v < N; v++) {
        if (!in_mst[v] && cost[v] > mem[min_node][v]) {
            cost[v] = mem[min_node][v];
        }
    }
}

cout << total_cost << endl;
```

**Proof of Optimality (Cut Property)**:
- For any cut of the graph separating visited from unvisited nodes
- The minimum-cost edge crossing the cut is in some MST
- Therefore, Prim's greedy choice is always safe

**Complexity**:
- With priority queue: O(E log V) or O(N² log N) for dense graphs
- Without priority queue: O(N²)

**Key Points**:
- ✓ Start from arbitrary node (usually 0)
- ✓ Use `in_mst` to track visited nodes, not just cost check
- ✓ Update costs when finding cheaper edges
- ✓ Greedy choice: always pick minimum-cost edge to unvisited
- ✓ For complete graph, O(N²) without priority queue is simpler
- ✓ Alternative: Use Kruskal's algorithm (sort edges, use DSU)

---

## 4. TOWER DEFENSE (GREEDY PLACEMENT)

**File**: [../Q4/tower_defense_2.cpp](../Q4/tower_defense_2.cpp)

**Problem**: Place K towers to damage monsters. Each tower at position P damages monsters in range [P-W, P+W]. Find final state of all monsters.

**Why Greedy** (Partial): Process monsters left-to-right and place towers to cover maximum range. Placing towers as far right as possible within range maximizes coverage of future monsters.

**Greedy Strategy**:
1. Consolidate monsters by position (group duplicates)
2. Process monsters from **left to right**
3. For each monster, calculate optimal tower placement
4. Place tower to cover this monster and as much range as possible (greedy: place at position + W)
5. Damage all monsters in tower range
6. Continue until no towers left or all monsters damaged

**Key Initialization**:
```cpp
int K, W, n;
cin >> K >> W >> n;

map<int, int> monster_health;  // position -> health
for (int i = 0; i < n; i++) {
    int pos, health;
    cin >> pos >> health;
    monster_health[pos] += health;  // Consolidate by position
}

// Convert to vector for easier processing
vector<pair<int, int>> monsters(monster_health.begin(), monster_health.end());
// monsters is automatically sorted by position (map property)
```

**Main Algorithm**:
```cpp
int towers_placed = 0;

for (auto& [pos, health] : monsters) {
    if (towers_placed >= K) break;
    if (health <= 0) continue;
    
    // Greedy placement: place tower at pos + W (rightmost in range)
    int tower_pos = pos + W;
    towers_placed++;
    
    // Damage all monsters in range [tower_pos - W, tower_pos]
    for (auto& [m_pos, m_health] : monsters) {
        if (m_pos >= tower_pos - W && m_pos <= tower_pos) {
            m_health--;
            if (m_health == 0) {
                monster_health.erase(m_pos);  // Remove if dead
            }
        }
    }
}

// Output remaining monsters
for (auto& [pos, health] : monsters) {
    if (health > 0) {
        cout << pos << " " << health << "\n";
    }
}
```

**Greedy Justification**:
- Placing tower at `pos + W` (rightmost) covers range `[pos, pos + 2W]`
- This maximizes coverage to the right for future monsters
- Processing left-to-right ensures we don't miss monsters on the left

**Complexity**: O(M log M + K × M) where M = distinct monster positions

**Key Points**:
- ✓ Use map to consolidate duplicate positions automatically
- ✓ Process left-to-right (map is sorted)
- ✓ Greedy placement: rightmost position in range
- ✓ Each tower damages all monsters in its range (range = W in both directions)
- ✓ Check `towers_placed < K` to respect tower limit

---

## COMPARISON TABLE

| Problem | File | Greedy Choice | Why Optimal | Complexity | Key Init |
|---------|------|---|---|---|---|
| **Fractional Knapsack** | Q3/fractional_knapsack.cpp | Highest value/weight ratio | Can't do better per unit capacity | O(n log n) | Sort by ratio |
| **Activity Selection** | Q3/class_selection.cpp | Earliest finish time | Leaves most time for others | O(n log n) | Sort by end time |
| **MST (Prim's)** | Q3/cable_company.cpp | Min-cost edge to unvisited | Cut property theorem | O(N² log N) | `cost[0]=0` |
| **Tower Defense** | Q4/tower_defense_2.cpp | Rightmost placement in range | Max coverage to right | O(M² + K×M) | Map monsters |

---

## GENERAL GREEDY PRINCIPLES

### When Does Greedy Work?

1. **Optimal Substructure**: Optimal solution contains optimal solutions to subproblems
2. **Greedy Choice Property**: Local optimal choice leads to global optimum
3. **Exchange Argument**: Can show any non-greedy solution can be converted to greedy

### Proof Techniques

**Exchange Argument**:
```
Assume optimal solution O differs from greedy solution G at step i.
- Replace G's choice at i with O's choice
- Show this doesn't make solution worse
- Repeat until O = G
- Therefore, G is optimal
```

**Cut Property (for MST)**:
```
For any cut (S, V-S):
- Minimum edge crossing the cut is in some MST
- Therefore, Prim's greedy choice is always safe
```

**Activity Selection Proof**:
```
For earliest-finish activity a1:
- Removing a1 from optimal gives optimal subproblem
- Therefore, selecting a1 greedily leads to optimal overall
```

### Common Greedy Problems

✓ **Always greedy-solvable**:
- Fractional knapsack
- Activity selection
- Huffman coding
- Dijkstra's algorithm
- Prim's/Kruskal's MST

✗ **NOT greedy-solvable** (use DP):
- 0/1 knapsack
- Longest increasing subsequence
- Coin change (arbitrary denominations)
- Traveling salesman problem

---

## EXAM CHECKLIST

- [ ] Always check if problem asks for **maximum count/subset** → likely activity selection
- [ ] If **fractional items allowed** → fractional knapsack (greedy works)
- [ ] If **0/1 items** → knapsack DP (greedy fails)
- [ ] **MST problem** → prove why Prim's/Kruskal's greedy choice is safe
- [ ] **Scheduling/interval** → sort by **end time**, not start time
- [ ] **Verify greedy choice property** before coding
- [ ] **Compare with optimal solution** for small test cases
- [ ] Remember: **Exchange argument** is key proof technique for greedy

---

## QUICK CODE TEMPLATE: ACTIVITY SELECTION

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> act(n);  // (end, start)
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        act[i] = {e, s};
    }
    
    sort(act.begin(), act.end());  // Sort by end time
    
    int count = 1;
    int last_end = act[0].first;
    
    for (int i = 1; i < n; i++) {
        if (act[i].second >= last_end) {
            count++;
            last_end = act[i].first;
        }
    }
    
    cout << count << endl;
    return 0;
}
```

---

## QUICK CODE TEMPLATE: FRACTIONAL KNAPSACK

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    
    vector<pair<double, pair<double, double>>> items(n);
    for (int i = 0; i < n; i++) {
        double v, w;
        cin >> v >> w;
        items[i] = {v/w, {v, w}};
    }
    
    sort(items.rbegin(), items.rend());  // Sort by ratio descending
    
    double total = 0;
    for (int i = 0; i < n && W > 0; i++) {
        double take = min(items[i].second.second, (double)W);
        total += take * items[i].first;
        W -= take;
    }
    
    cout << fixed << setprecision(2) << total << endl;
    return 0;
}
```

