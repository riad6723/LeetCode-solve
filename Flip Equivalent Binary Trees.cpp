/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        //base case
        if(root1 == nullptr and root2 == nullptr) return true;
        if(root1 == nullptr or root2 == nullptr) return false;
        if(root1->val != root2->val) return false;

        bool left1 = flipEquiv(root1->left, root2->left);
        bool right1 = flipEquiv(root1->right, root2->right);
        bool left2 = flipEquiv(root1->left, root2->right);
        bool right2 = flipEquiv(root1->right, root2->left);

        if((left1 and right1) or (left2 and right2)) return true;
        return false;
    }
};


/*
import UIKit

class ViewController: UIViewController, UIPageViewControllerDataSource, UIPageViewControllerDelegate {
    func pageViewController(_ pageViewController: UIPageViewController, viewControllerBefore viewController: UIViewController) -> UIViewController? {
        if let vc = viewController as? leftCardViewController {
            print("out of scope left")
            currenctIndex = 0
            return nil
        }
        currenctIndex = 1
        return leftVC
    }
    
    func pageViewController(_ pageViewController: UIPageViewController, viewControllerAfter viewController: UIViewController) -> UIViewController? {
        print("right swap")
        if let vc = viewController as? rightCardViewController {
            print("out of scope right")
            currenctIndex = 1
            return nil
        }
        currenctIndex = 0
        return rightVC
    }
    
    var currenctIndex = 0
    let pageController = UIPageViewController(transitionStyle: .scroll, navigationOrientation: .horizontal, options: nil)
    let leftVC = leftCardViewController.makeViewController()
    let rightVC = rightCardViewController.makeViewController()
    @IBOutlet weak var cardHolder: UIView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupPageController()
        cardHolder.backgroundColor = .black
        setupScrollViewObserver()
    }
    
    private func setupPageController() {
        self.pageController.dataSource = self
        self.pageController.delegate = self
        self.pageController.view.backgroundColor = .clear
        self.pageController.view.frame = CGRect(x: 0,y: 0,width: self.cardHolder.frame.width,height: self.cardHolder.frame.height)
        addChild(self.pageController)
        cardHolder.addSubview(self.pageController.view)
        self.pageController.didMove(toParent: self)
        pageController.setViewControllers([leftVC], direction: .forward, animated: true, completion: nil)
    }
}

extension ViewController: UIScrollViewDelegate {
    private func setupScrollViewObserver() {
        for view in pageController.view.subviews {
            if let scrollView = view as? UIScrollView {
                scrollView.delegate = self
                //scrollView.isScrollEnabled = false
            }
        }
    }
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        // Calculate current drag distance
        let dragDistance = scrollView.contentOffset.x - cardHolder.frame.width
        print(dragDistance)
        
        // Disable scroll if drag distance exceeds the limit
        if currenctIndex == 0, dragDistance<0 {
            scrollView.isScrollEnabled = false
        } else if currenctIndex == 1, dragDistance>0 {
            scrollView.isScrollEnabled = false
        } else {
            scrollView.isScrollEnabled = true
        }
    }
}


*/
