class Solution {
    func numberOfSubarrays(_ nums: [Int], _ k: Int) -> Int {
        let n = nums.count
        var preSum = Array(repeating: 0, count: n+10)
        var ans: Int = 0

        for i in 0..<n {
            if nums[i]%2 == 1 {
                preSum[i+1] = preSum[i] + 1
            } else {
                preSum[i+1] = preSum[i]
            }
        }

        var Map = Dictionary<Int,Int>()
        Map[0] = 1

        for i in 1...n {
            let sum = preSum[i] - k
            guard let value = Map[sum] else {
                Map[preSum[i]] = (Map[preSum[i]] ?? 0) + 1
                continue
            }

            ans += value
            Map[preSum[i]] = (Map[preSum[i]] ?? 0) + 1
        }

        return ans
    }
}
