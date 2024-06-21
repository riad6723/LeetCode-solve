class Solution {
    func maxSatisfied(_ customers: [Int], _ grumpy: [Int], _ minutes: Int) -> Int {
        var n = customers.count
        var preSum = Array(repeating: 0, count: n+10)
        var fullSum = Array(repeating: 0, count: n+10)
        var ans = 0
        
        for i in 0..<n {
            preSum[i+1] = preSum[i] + customers[i] * (1 - grumpy[i])
            fullSum[i+1] = fullSum[i] + customers[i]
        }

        if minutes >= n {
            return fullSum[n]
        }

        for i in 0..<n {
            let l = i+1
            let r = l+minutes-1
            guard r <= n else {
                break
            }
            let middleSum = fullSum[r] - fullSum[l-1]
            let leftSum = preSum[l-1]
            let rightSum = preSum[n] - preSum[r]
            ans = max(ans, middleSum + leftSum + rightSum)
        }

        return max(ans, preSum[n])
    }
}
