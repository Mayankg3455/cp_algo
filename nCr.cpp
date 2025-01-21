#define ll long long
ll mod = 1e9 + 7;

ll fast_power(ll a, ll b)
{
    ll res = 1;

    while(b > 0)
    {
        if(b&1)
        {
            res = (res*a)%mod;
        }

        a = (a*a)%mod;
        b >>= 1;
    }

    return res;
}
class factorial_ops
{
    
    vector<ll> factorial,inv_factorial;
    int n;
    public:
    factorial_ops(int n)
    {
        this->n = n;
        factorial.resize(n+1,1);
        inv_factorial.resize(n+1,1);
    }

    void populate_factorial()
    {
        factorial[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            factorial[i] = (factorial[i-1]*i)%mod;
        }

        inv_factorial[n] = fast_power(factorial[n],mod-2);
        for(int i = n-1; i >= 0; i--)
        {
            inv_factorial[i] = (inv_factorial[i+1]*(i+1))%mod;
        }
    }

    ll nCr(int n, int r)
    {
         if (r < 0 || r > n) return 0;
        return factorial[n]*((inv_factorial[r]*inv_factorial[n-r])%mod)%mod;
    }
};
