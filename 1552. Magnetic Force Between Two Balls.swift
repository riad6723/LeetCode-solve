class Solution {

    enum State {
        case possible
        case impossible
    }

    func check(_ position: inout [Int], _ m: Int, _ distance: Int) -> State {
        let n = position.count
        var prev = position.first!
        var cnt = 1

        for i in 1..<n {
            let curr = position[i]
            if curr - prev >= distance {
                prev = curr
                cnt+=1
            }
        }

        if cnt >= m {
            return .possible
        } else {
            return .impossible
        }
    }

    func maxDistance(_ pos: [Int], _ m: Int) -> Int {
        var l: Int = 1
        var r: Int = 1000000000
        var position: [Int] = pos
        position.sort()

        while r-l > 3 {
            var mid = (l+r)/2
            if check(&position,m,mid) == .possible {
                l=mid
            } else {
                r=mid
            }
        }

        for i in (l...r).reversed() {
            if check(&position,m,i) == .possible {
                return i
            }
        }
        return 0
    }
}
