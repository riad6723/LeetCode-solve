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



/*import UIKit

class ViewController: UIViewController {
    @IBOutlet weak private var topViewLabel: UILabel!
    @IBOutlet weak private var topView: UIView!
    
    var isExpanded: Bool = false
    var frames: CGRect {topView.frame}
    var tableViewHeight: CGFloat {
        (dataSource.count > 3) ? 120.0 : CGFloat(dataSource.count) * tableView.rowHeight
    }
    
    let tableView: UITableView = {
        let tableView = UITableView()
        tableView.rowHeight = 40
        tableView.layer.cornerRadius = 5
        tableView.separatorStyle = .none
        tableView.layer.borderColor = UIColor.systemGray5.cgColor
        tableView.layer.borderWidth = 1.0
        tableView.selectRow(at: IndexPath(row: 0, section: 0), animated: false, scrollPosition: .none)
        tableView.isHidden = true
        return tableView
    }()
    
    let transparentView: UIView = {
        let transparentView = UIView()
        transparentView.backgroundColor = .clear
        transparentView.isHidden = true
        let tapgesture = UITapGestureRecognizer(target: self, action: #selector(hideTableView))
        transparentView.addGestureRecognizer(tapgesture)
        return transparentView
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        addTransparentView()
        addTableView()
        setupTopView()
    }
    
    private func addTransparentView() {
        transparentView.frame = self.view.frame
        view.addSubview(transparentView)
    }
    
    private func addTableView() {
        tableView.delegate = self
        tableView.dataSource = self
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        tableView.frame = CGRect(x: frames.origin.x, y: frames.origin.y + frames.height, width: frames.width, height: tableViewHeight)
        view.addSubview(tableView)
    }
    
    private func setupTopView() {
        let topViewTapGesture = isExpanded ? UITapGestureRecognizer(target: self, action: #selector(hideTableView)) :
        UITapGestureRecognizer(target: self, action: #selector(showTableView))
        topView.addGestureRecognizer(topViewTapGesture)
        topView.backgroundColor = .red
  }

  @objc private func showTableView() {
      tableView.isHidden = false
      transparentView.isHidden = false
      isExpanded = true
  }


  @objc private func hideTableView() {
      tableView.isHidden = true
      transparentView.isHidden = true
      isExpanded = false
  }
    
}

extension ViewController: UITableViewDataSource, UITableViewDelegate {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return dataSource.count

    }
      
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "Cell", for: indexPath)
        cell.textLabel?.text = dataSource[indexPath.row]
        cell.backgroundColor = .red
        return cell
    }

    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 40
    }
          
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        topViewLabel.text = dataSource[indexPath.row]
        hideTableView()
    }
 
  
}*/
