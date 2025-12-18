class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> prefStrategy(n + 1, 0), prefPrice(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefStrategy[i + 1] = prefStrategy[i] + 1LL * strategy[i] * prices[i];
            prefPrice[i + 1] = prefPrice[i] + prices[i];
        }

        long long baseProfit = prefStrategy[n];
        long long ans = baseProfit;

        int half = k / 2;

        for (int l = 0; l + k <= n; l++) {
            long long oldContribution =
                prefStrategy[l + k] - prefStrategy[l];

            long long newContribution =
                prefPrice[l + k] - prefPrice[l + half];

            long long candidate =
                baseProfit - oldContribution + newContribution;

            ans = max(ans, candidate);
        }

        return ans;
    }
};
