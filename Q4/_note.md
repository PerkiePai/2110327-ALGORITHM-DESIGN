# Q4 Algorithm Summary - Exam Preparation Guide

Organized by algorithm type with initialization requirements and code examples.

---

## 1. DYNAMIC PROGRAMMING (DP)

### 1.1 Coin Change / Integer Partitions
**File**: [increasing_seq_sum.cpp](increasing_seq_sum.cpp)
- **Problem**: Count ways to partition an integer N
- **Algorithm**: DP - Coin Change Variant
- **Time/Space**: O(N²) 
- **Key Initialization**:
  ```cpp
  vector<ll> mem(N+1, 0);
  mem[0] = 1;  // Base case: 1 way to make 0
  ```
- **Main Logic**:
  ```cpp
  for (ll i = 1; i <= N; i++) {
      for (ll j = i; j <= N; j++) {
          mem[j] += mem[j - i];  // Update ways to make j using value i
      }
  }
  ```
- **Key Point**: Iterate through values first, then amounts (prevents duplicates/permutations)

---

### 1.2 TSP - Traveling Salesman (Max Weight with Bitmask)
**Files**: [journey.cpp](journey.cpp), [journey_pai.cpp](journey_pai.cpp)
- **Problem**: Find max-weight path visiting all N cities exactly once
- **Algorithm**: DP with Bitmask
- **Time/Space**: O(2^N × N²), O(2^N × N)
- **Key Initialization**:
  ```cpp
  const ll NEG_INF = -1e18;
  vector<vector<ll>> mem(1 << n, vector<ll>(n, NEG_INF));
  mem[1][0] = 0;  // Start at city 0 with only city 0 visited
  
  // adj[n][n] = adjacency matrix with weights
  ```
- **Main Logic**:
  ```cpp
  for (int mask = 1; mask < (1 << n); mask++) {
      for (int u = 0; u < n; u++) {
          if (!(mask & (1 << u))) continue;  // u not in mask
          if (mem[mask][u] == NEG_INF) continue;
          
          for (int v = 0; v < n; v++) {
              if (mask & (1 << v)) continue;  // v already visited
              int next_mask = mask | (1 << v);
              mem[next_mask][v] = max(mem[next_mask][v], 
                                      mem[mask][u] + adj[u][v]);
          }
      }
  }
  // Answer: max of mem[(1<<n)-1][i] for all i
  ```
- **Key Point**: Bitmask represents visited cities; start at city 0

---

## 2. BACKTRACKING

### 2.1 N-Queens Problem
**Files**: [n-queen.cpp](n-queen.cpp), [n-queen_pai.cpp](n-queen_pai.cpp)
- **Problem**: Place N queens on N×N board with no conflicts
- **Algorithm**: Backtracking with Diagonal Tracking
- **Time**: O(N!)
- **Key Initialization**:
  ```cpp
  bool col_check[15] = {false};        // Column occupancy
  bool diag1_check[30] = {false};      // "/" diagonal (r+c)
  bool diag2_check[30] = {false};      // "\" diagonal (r-c+N)
  
  // Special case
  if (n == 1) { ans = 1; return; }
  ```
- **Main Logic**:
  ```cpp
  void solve(int row, int n) {
      if (row == n) {
          ans++;
          return;
      }
      
      for (int col = 0; col < n; col++) {
          int d1 = row + col;
          int d2 = row - col + n;
          
          if (col_check[col] || diag1_check[d1] || diag2_check[d2]) 
              continue;
          
          col_check[col] = diag1_check[d1] = diag2_check[d2] = true;
          solve(row + 1, n);
          col_check[col] = diag1_check[d1] = diag2_check[d2] = false;
      }
  }
  ```
- **Key Point**: Two diagonal arrays for both diagonal directions; backtrack after recursive call

---

### 2.2 N-Knight Placement
**File**: [n-knight.cpp](n-knight.cpp)
- **Problem**: Place N knights on N×N board such that no two knights attack each other
- **Algorithm**: Backtracking (Row-by-Row like N-Queens)
- **Time**: O(N!) with pruning
- **Key Initialization**:
  ```cpp
  int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
  bool board[15][15];  // Track knight placements
  long long total_sol = 0;
  
  if (N == 1) { cout << 1 << endl; return 0; }
  ```
- **Main Logic**:
  ```cpp
  bool isSafe(int r, int c) {
      // Check all 8 knight move positions
      for (int i = 0; i < 8; i++) {
          int nr = r + dr[i];
          int nc = c + dc[i];
          
          if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
              if (board[nr][nc]) return false;  // Knight found at attacking position
          }
      }
      return true;
  }
  
  void solve(int row) {
      if (row == N) {
          total_sol++;
          return;
      }
      
      for (int col = 0; col < N; col++) {
          if (isSafe(row, col)) {
              board[row][col] = true;
              solve(row + 1);
              board[row][col] = false;  // Backtrack
          }
      }
  }
  ```
- **Key Point**: Similar to N-Queens; place one knight per row; check if position is safe by looking at all 8 knight attack positions

---

### 2.3 Traveling Tourist (TSP with Backtracking & Pruning)
**File**: [travelling_tourist.cpp](travelling_tourist.cpp)
- **Problem**: Find shortest path visiting K target nodes
- **Algorithm**: Floyd-Warshall + Backtracking with Pruning
- **Time**: O(N³ + K! × K)
- **Key Initialization**:
  ```cpp
  const ll INF = 1e15;
  vector<vector<ll>> dist(N+1, vector<ll>(N+1, INF));
  
  // Read graph and set dist[i][i] = 0
  
  // Floyd-Warshall
  for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
      }
  }
  
  vector<bool> visited(K, false);
  ll min_cost = INF;
  ```
- **Main Logic**:
  ```cpp
  void backtrack(int idx, ll cur_cost, int cur_pos) {
      if (cur_cost >= min_cost) return;  // Pruning
      if (idx == K) {
          min_cost = min(min_cost, cur_cost);
          return;
      }
      
      for (int i = 0; i < K; i++) {
          if (visited[i]) continue;
          visited[i] = true;
          backtrack(idx + 1, cur_cost + dist[cur_pos][targets[i]], targets[i]);
          visited[i] = false;
      }
  }
  ```
- **Key Point**: Precompute all-pairs distances first; prune early if current cost exceeds best

---

### 2.4 Grid Transmitter Coverage (IDDFS Backtracking)
**File**: [guitar_array_3.cpp](guitar_array_3.cpp)
- **Problem**: Place minimum transmitters to cover all targets (alignment, diagonal, knight moves)
- **Algorithm**: IDDFS (Iterative Deepening DFS) with Bitwise Coverage
- **Key Initialization**:
  ```cpp
  bitset<144> precomputed[12][12];  // Coverage from each position
  vector<int> coverage_list[144];    // Positions that can cover each target
  vector<int> targets;               // Uncovered target indices
  
  // Precompute: for each position, what targets it covers
  // Precompute: for each target, what positions can cover it
  ```
- **Main Logic**:
  ```cpp
  bool iddfs(int depth, bitset<144> coverage) {
      if (targets.empty()) return true;  // All covered
      if (depth == 0) return false;
      
      // Find hardest target (covered by fewest positions)
      int best_target = ...; 
      
      for (int pos : coverage_list[best_target]) {
          bitset<144> new_coverage = coverage;
          // Mark newly covered targets
          remove_covered_targets();
          if (iddfs(depth - 1, new_coverage)) return true;
          // Backtrack
      }
      return false;
  }
  ```
- **Key Point**: Start with k=1, increment depth; branch on target covered by fewest positions

---

## 3. GRAPH SEARCH & HEURISTICS

### 3.1 15-Puzzle Solver (IDDFS + A* Heuristic)
**File**: [15-puzzle.cpp](15-puzzle.cpp)
- **Problem**: Solve 15-puzzle puzzle (4×4 sliding tiles)
- **Algorithm**: IDDFS with Manhattan Distance Heuristic
- **Key Initialization**:
  ```cpp
  struct Board {
      int grid[4][4];
      int empty_r, empty_c;  // Empty cell position
  };
  
  int targetPos[16][2];  // Goal positions for each number
  const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
  
  set<Board> visited;  // To prevent cycles
  int minThreshold = heuristic(initial_board);
  ```
- **Main Logic (Heuristic)**:
  ```cpp
  int manhattan(const Board& b) {
      int h = 0;
      for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
              if (b.grid[i][j] == 0) continue;
              int target_r = targetPos[b.grid[i][j]][0];
              int target_c = targetPos[b.grid[i][j]][1];
              h += abs(i - target_r) + abs(j - target_c);
          }
      }
      return h;
  }
  
  void iddfs(Board b, int depth, int g, int& minThreshold) {
      int h = manhattan(b);
      if (g + h > depth) {
          minThreshold = min(minThreshold, g + h);
          return;
      }
      if (is_goal(b)) { /* found */ return; }
      
      for (int d = 0; d < 4; d++) {
          // Swap empty with neighbor, recurse, backtrack
      }
  }
  ```
- **Key Point**: Manhattan distance sums absolute differences to target positions; IDDFS increases depth limit iteratively

---

### 3.2 Strange House Puzzle (BFS State Search)
**File**: [strange_house.cpp](strange_house.cpp)
- **Problem**: Transform initial state to target state via swaps
- **Algorithm**: BFS with Parent Tracking
- **Key Initialization**:
  ```cpp
  struct Node {
      int state[2*N+1];
      int moves = 0;
  };
  
  queue<Node> q;
  map<vector<int>, int> parent;  // For path reconstruction
  
  q.push(initial);
  parent[initial_state] = -1;
  ```
- **Main Logic**:
  ```cpp
  while (!q.empty()) {
      Node cur = q.front(); q.pop();
      
      if (is_goal(cur)) {
          // Reconstruct path from parent map
          return reconstruct_path(cur.state);
      }
      
      for (int i = 0; i < 2*N+1; i++) {
          for (int j = i+1; j < 2*N+1; j++) {
              // Swap positions i and j
              swap(cur.state[i], cur.state[j]);
              if (parent.find(new_state) == parent.end()) {
                  parent[new_state] = current;
                  q.push(new_node);
              }
              // Swap back
          }
      }
  }
  ```
- **Key Point**: BFS guarantees shortest path; track parent for path reconstruction

---

## 4. BRANCH & BOUND

### 4.1 0/1 Knapsack with Branch & Bound
**File**: [01-knapsack.cpp](01-knapsack.cpp)
- **Problem**: Select items maximizing value within weight constraint
- **Algorithm**: Branch & Bound with Fractional Knapsack Bound
- **Key Initialization**:
  ```cpp
  struct Item { ll weight, value; };
  vector<Item> items(n);  // Read items
  sort(items.begin(), items.end(), 
       [](const Item& a, const Item& b) {
           return (a.value / a.weight) > (b.value / b.weight);
       });
  
  ll max_cur_v = 0;  // Best solution found so far
  ll capacity;
  ```
- **Main Logic (Pruning Bound)**:
  ```cpp
  ll fractional_bound(int idx, ll cur_w, ll cur_v) {
      // Greedy packing of remaining items (can take fractional items)
      ll bound = cur_v;
      ll w = cur_w;
      for (int i = idx; i < n && w < capacity; i++) {
          ll take = min(items[i].weight, capacity - w);
          bound += (take / items[i].weight) * items[i].value;
          w += take;
      }
      return bound;
  }
  
  void branch_bound(int idx, ll cur_w, ll cur_v) {
      if (fractional_bound(idx, cur_w, cur_v) <= max_cur_v) 
          return;  // Prune
      
      if (idx == n || cur_w == capacity) {
          max_cur_v = max(max_cur_v, cur_v);
          return;
      }
      
      // Try taking item idx
      if (cur_w + items[idx].weight <= capacity) {
          branch_bound(idx + 1, cur_w + items[idx].weight, 
                       cur_v + items[idx].value);
      }
      
      // Try skipping item idx
      branch_bound(idx + 1, cur_w, cur_v);
  }
  ```
- **Key Point**: Prune branches where upper bound < current best; use fractional knapsack as bound estimator

---

## 5. GREEDY ALGORITHMS

### 5.1 Goat Problem / Increasing Consecutive (Frequency Count)
**Files**: [goat_dual.cpp](goat_dual.cpp), [increasing_cons.cpp](increasing_cons.cpp)
- **Problem**: Count duplicates and compute sum of squared frequencies
- **Algorithm**: Greedy / Map Counting
- **Time**: O(n log n)
- **Key Initialization**:
  ```cpp
  map<ll, ll> freq;
  for (ll x : arr) {
      freq[x]++;
  }
  ```
- **Main Logic**:
  ```cpp
  ll result = 0;
  for (auto& p : freq) {
      if (p.second > 1) {  // Has duplicates
          result += p.second * p.second;  // Sum of squares
      }
  }
  ```
- **Key Point**: Map auto-sorts; iterate through and apply formula

---

### 5.2 Tower Defense (Greedy Placement with Coverage)
**File**: [tower_defense_2.cpp](tower_defense_2.cpp)
- **Problem**: Place K towers to maximize monster coverage within range W
- **Algorithm**: Greedy Sequential Placement
- **Key Initialization**:
  ```cpp
  map<int, int> monsters_at;  // Consolidate duplicates
  vector<pair<int, int>> positions;  // (pos, health)
  int W = range, K = towers;
  ```
- **Main Logic**:
  ```cpp
  for (auto& p : positions) {
      int pos = p.first;
      // Calculate how many towers needed to cover pos to pos+W
      // Place towers greedily from this position
      int tower_pos = pos + W;  // Place as far right as possible
      towers_placed++;
      // Damage all monsters in range [tower_pos-W, tower_pos]
  }
  ```
- **Key Point**: Process positions in order; place towers to cover maximum range to the right

---

## 6. INCOMPLETE / TEMPLATE

(All major Q4 problems are now covered above)

---

## QUICK REFERENCE TABLE

| Problem | Algorithm | Complexity | Key Init | Key Point |
|---------|-----------|-----------|----------|-----------|
| Increasing Seq Sum | DP Coin Change | O(N²) | `mem[0]=1` | Iterate values then amounts |
| Journey (TSP) | DP Bitmask | O(2^N×N²) | `mem[1][0]=0` | Bitmask = visited cities |
| N-Queens | Backtracking | O(N!) | 3 boolean arrays | Two diagonals: r+c, r-c+N |
| N-Knights | Backtracking | O(N!) | `board[15][15]` | Check 8 knight positions |
| Travelling Tourist | Floyd-W + BT | O(N³+K!) | Floyd-Warshall first | Prune on cost ≥ min_cost |
| Guitar Coverage | IDDFS | O(?) | Precomputed coverage | Branch on hardest target |
| 15-Puzzle | IDDFS+A* | O(?) | Manhattan heuristic | Prevent cycles with set |
| Strange House | BFS | O(states) | queue + parent map | Track parent for path |
| 01-Knapsack | Branch & Bound | O(2^n) pruned | Sort by ratio | Fractional bound for pruning |
| Goat Dual | Frequency Map | O(n log n) | Hash map | Sum squares of counts |
| Tower Defense | Greedy | O(n) | Consolidate positions | Place right-most in range |

---

## EXAM TIPS

1. **DP**: Always initialize base cases correctly (especially `mem[0]=1` or `mem[0][...]=0`)
2. **Backtracking**: Don't forget to reset state after recursion (backtrack step)
3. **Bitmask DP**: Test with small N first; verify bit operations
4. **BFS**: Use `visited` set to avoid revisiting states
5. **Heuristics**: Manhattan distance = sum of absolute differences to goal
6. **Pruning**: Compare current upper bound with best solution found
7. **Diagonals in Grid**: Use `r+c` and `r-c+offset` for both directions
8. **Graph Preprocessing**: Floyd-Warshall/Dijkstra before backtracking if needed
