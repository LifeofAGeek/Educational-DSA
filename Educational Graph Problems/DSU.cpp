// my DUS template
struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
        // iota(begin(parent), end(parent), 0);
    }

    int find(int x) {
        if (parent[x] < 0)
            return x;
        else
            return parent[x] = find(parent[x]);  // path compression
    }

    bool merge(int x, int y) {  // union by rank
        int a = find(x);
        int b = find(y);

        if (a == b) return false;

        if (rank[a] > rank[b]) {
            // a would be parent
            parent[b] = a;
            rank[a] += rank[b];
        } else {
            // b would be parent
            parent[a] = b;
            rank[b] += rank[a];
        }
        return true;
    }
};
