//
//  ViewController.swift
//  dropDownMenu
//
//  Created by Ajijul Hakim Riad on 29/7/24.
//



class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> increasing(n+10, 0);
        vector<int> decreasing(n+10, 0);
        int ans = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(rating[j] < rating[i]) {
                    increasing[i]++;
                    ans+=increasing[j];
                }
                else if(rating[j] > rating[i]) {
                    decreasing[i]++;
                    ans+=decreasing[j];
                }
            }
        }

        return ans;
    }
};



/*
import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var scrollView: UIScrollView!
    @IBOutlet weak var contentView: UIView!
    @IBOutlet weak private var topViewLabel: UILabel!
    @IBOutlet weak private var topView: UIView!
    
    var isExpanded: Bool = false
    var frames: CGRect { topView.frame }
    var tableViewHeight: CGFloat {
        return (dataSource.count > 3) ? 120.0 : CGFloat(dataSource.count) * tableView.rowHeight
    }
    
    let dataSource = ["Option 1", "Option 2", "Option 3", "Option 4"]
    
    let tableView: UITableView = {
        let tableView = UITableView()
        tableView.rowHeight = 40
        tableView.layer.cornerRadius = 20
        tableView.separatorStyle = .none
        tableView.layer.borderColor = UIColor.white.cgColor
        tableView.isHidden = true
        return tableView
    }()
    
    let transparentView: UIView = {
        let transparentView = UIView()
        transparentView.backgroundColor = UIColor.black.withAlphaComponent(0.5)
        transparentView.isHidden = true
        return transparentView
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        addTransparentView()
        addTableView()
        let tapGesture = UITapGestureRecognizer(target: self, action: #selector(handleTap))
        topView.addGestureRecognizer(tapGesture)
    }
    
    @IBAction func didTapped(_ sender: Any) {
        print("tapped")
    }
    
    @objc private func handleTap() {
        if isExpanded {
            hideTableView()
        } else {
            showTableView()
        }
    }
    
    private func addTransparentView() {
        transparentView.frame = self.contentView.bounds
        let tapGesture = UITapGestureRecognizer(target: self, action: #selector(hideTableView))
        transparentView.addGestureRecognizer(tapGesture)
        contentView.addSubview(transparentView)
        contentView.bringSubviewToFront(transparentView)
    }
    
    private func addTableView() {
        tableView.delegate = self
        tableView.dataSource = self
        tableView.register(UINib(nibName: "AnotherTableViewCell", bundle: nil), forCellReuseIdentifier: "Cell")
        tableView.frame = CGRect(x: frames.origin.x, y: frames.origin.y + frames.height, width: frames.width, height: 0) // Initially set height to 0
        contentView.addSubview(tableView)
    }

    @objc private func showTableView() {
        transparentView.isHidden = false
        tableView.isHidden = false
        UIView.animate(withDuration: 0.3, animations: {
            self.tableView.frame.size.height = self.tableViewHeight
            self.updateScrollViewContentSize()
        }) { (finished) in
            self.isExpanded = true
        }
    }

    @objc private func hideTableView() {
        UIView.animate(withDuration: 0.3, animations: {
            self.tableView.frame.size.height = 0
            self.updateScrollViewContentSize()
        }) { (finished) in
            self.tableView.isHidden = true
            self.transparentView.isHidden = true
            self.isExpanded = false
        }
    }
    
    private func updateScrollViewContentSize() {
        let contentHeight = max(contentView.frame.height, topView.frame.maxY + tableView.frame.height)
        scrollView.contentSize = CGSize(width: contentView.frame.width, height: contentHeight)
    }
}

extension ViewController: UITableViewDataSource, UITableViewDelegate {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return dataSource.count
    }
      
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = tableView.dequeueReusableCell(withIdentifier: "Cell", for: indexPath) as? AnotherTableViewCell else {
            return UITableViewCell()
        }
        cell.upperLabel?.text = dataSource[indexPath.row]
        cell.lowerLabel.text = "vacava"
        return cell
    }

    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        topViewLabel.text = dataSource[indexPath.row]
        hideTableView()
    }
}

*/
