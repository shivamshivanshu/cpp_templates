#ifdef LOCAL_JUDGE
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define fo(i, n) for (decltype(n) i = 0; i < (n); i++)
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define sortall(x) std::sort(all(x))
#define sortrev(x) std::sort(all(x), greater<>())
#define FAST std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

#ifdef LOCAL_JUDGE
template <typename... Args> void dbg_impl(const char *names, Args &&...args)
{
    std::cerr << "[" << names << "] = ";
    ((std::cerr << args << ' '), ...);
    std::cerr << '\n';
}
#define dbg(...) dbg_impl(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long int;
using ull = unsigned long long int;
using str = std::string;
using pii = std::pair<int, int>;
using pl = std::pair<ll, ll>;
using vi = std::vector<int>;
using vl = std::vector<ll>;
using vpii = std::vector<pii>;
using vpl = std::vector<pl>;
using vvi = std::vector<vi>;
using vvl = std::vector<vl>;
using vs = std::vector<std::string>;
using sl = std::set<ll>;

std::mt19937_64 rang(static_cast<uint64_t>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
int rng(int lim)
{
    std::uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}

template <typename T>
concept Iterable = requires(T t) {
    begin(t);
    end(t);
} && !std::is_convertible_v<T, std::string_view>;

template <typename F, typename T> void io(F f, T &var)
{
    if constexpr (Iterable<T>)
    {
        bool first = true;
        for (auto &e : var)
        {
            if (!first)
                std::cout << ' ';
            first = false;
            f(e);
        }
    }
    else
    {
        f(var);
    }
}

template <typename F, typename T, typename... Types> void io(F f, T &var1, Types &...var2)
{
    io(f, var1);
    io(f, var2...);
}

template <typename... Types> void inp(Types &...args)
{
    io([](auto &x) { std::cin >> x; }, args...);
}

template <typename T> void print(const T &var)
{
    io([](const auto &x) { std::cout << x; }, const_cast<T &>(var));
    std::cout << '\n';
}

template <typename T, typename... Types> void print(const T &var1, const Types &...var2)
{
    io([](const auto &x) { std::cout << x; }, const_cast<T &>(var1));
    std::cout << ' ';
    print(var2...);
}

template <class T> bool chmin(T &a, T b)
{
    return b < a ? a = b, true : false;
}
template <class T> bool chmax(T &a, T b)
{
    return b > a ? a = b, true : false;
}

template <typename T> bool isPrime(T n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (T i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

template <typename T> T power(T a, T b, T m)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % m;
    if (b % 2)
        return ((__int128)a * power(a, b - 1, m)) % m;
    auto tmp = power(a, b / 2, m);
    return ((__int128)tmp * tmp) % m;
}

ll inv(ll a, ll m = 1000000007LL)
{
    if (a == 1)
    {
        return 1;
    }
    return power(a, m - 2, m);
}

struct DSU
{
    vi p, rnk;
    DSU(int n) : p(static_cast<size_t>(n)), rnk(static_cast<size_t>(n), 0)
    {
        iota(all(p), 0);
    }
    int find(int x)
    {
        return p[static_cast<size_t>(x)] == x ? x : p[static_cast<size_t>(x)] = find(p[static_cast<size_t>(x)]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        auto ua = static_cast<size_t>(a), ub = static_cast<size_t>(b);
        if (rnk[ua] < rnk[ub])
            swap(a, b), swap(ua, ub);
        p[ub] = a;
        if (rnk[ua] == rnk[ub])
            rnk[ua]++;
        return true;
    }
};

constexpr ll INF = static_cast<ll>(1e18);
constexpr ll mod = 1000000007LL;
constexpr int N = 200005, M = N;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};
const std::string yes = "YES", no = "NO";

void solve()
{
}

int32_t main()
{
#ifdef LOCAL_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
#endif
    FAST;
    int test_case = 1;
    // std::cin >> test_case;
    while (test_case--)
    {
        solve();
    }
    return 0;
}
