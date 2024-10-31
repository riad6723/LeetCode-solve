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
 import UIKit

enum SwipeDirection {
    case left
    case right
}

class ViewController: UIViewController {
    @IBOutlet weak var leftView: UIView!
    @IBOutlet weak var rightView: UIView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let leftCardGesture = UIPanGestureRecognizer(target: self, action: #selector(handleLeftGesture))
        leftView.addGestureRecognizer(leftCardGesture)
    }
    
    @objc private func handleLeftGesture(_ gesture: UIPanGestureRecognizer) {
        let translation = gesture.translation(in: leftView)
        
        switch gesture.state {
        case .changed:
            // Move leftView left as the user swipes, making it follow the gesture
            if translation.x < 0 { // Only move if swiping left
                leftView.transform = CGAffineTransform(translationX: translation.x, y: 0)
                leftView.alpha = 1 + (translation.x / self.view.frame.width) // Gradually fade out

                // Make rightView "peek" in from the right side
                rightView.transform = CGAffineTransform(translationX: translation.x, y: 0) // Adjust factor as needed
            }
            
        case .ended:
            if translation.x < -50 { // If swipe exceeds threshold
                UIView.animate(withDuration: 0.5, delay: 0, options: .curveEaseIn, animations: {
                    self.leftView.transform = CGAffineTransform(translationX: -self.view.frame.width, y: 0)
                    self.leftView.alpha = 0 // Fade out
                    //self.rightView.transform = .identity // Snap rightView into place
                    self.view.layoutIfNeeded()
                }, completion: { _ in
                    self.leftView.isHidden = true
                    self.leftView.transform = .identity // Reset transform
                    NSLayoutConstraint.activate([
                        self.rightView.leadingAnchor.constraint(equalTo: self.view.leadingAnchor, constant: 0),
                        self.rightView.trailingAnchor.constraint(equalTo: self.view.trailingAnchor, constant: 0),
                    ])
                })
                
            } else {
                // If swipe doesn't exceed threshold, reset the position of both views
                UIView.animate(withDuration: 0.3, animations: {
                    self.leftView.transform = .identity
                    self.leftView.alpha = 1
                    self.rightView.transform = .identity
                })
            }
            
        default:
            break
        }
    }


    private func resetCardPosition(cardView: UIView) {
            UIView.animate(withDuration: 0.3) {
                cardView.transform = .identity
            }
        }
}

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
