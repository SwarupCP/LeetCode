class Solution {
    int n;

    int getNextIndex(int start, int currentJobEnd, int[][] array) {
        int end = n - 1;
        int result = n; 

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (array[mid][0] >= currentJobEnd) {
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return result;
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        n = startTime.length;

        int[][] array = new int[n][3];
        int[] dp = new int[n + 1];

        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        Arrays.sort(array, (a, b) -> Integer.compare(a[0], b[0]));

        for (int index = n - 1; index >= 0; index--) {
            int next = getNextIndex(index + 1, array[index][1], array);

            int take = array[index][2] + dp[next];
            int notTake = dp[index + 1];

            dp[index] = Math.max(take, notTake);
        }

        return dp[0];
    }
}
