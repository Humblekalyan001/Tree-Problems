//Recursive 
class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == nullptr && q == nullptr )  // 1st check
        {
            return true;
        }
        else if ((p && q == nullptr) || (p == nullptr && q))  // 2nd check
        {
            return false;
        }
        else if(p->val == q->val)
        {
           return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        else
            return false;
        
    }
};
//iterative

  class Solution {
  public:
      bool isSameTree(TreeNode* p, TreeNode* q) {
          queue<TreeNode *> queue;
          queue.push(p);
          queue.push(q);
          while (queue.size()!=0){
              TreeNode * q2=queue.front();
              queue.pop();
              TreeNode * q1=queue.front();
              queue.pop();
              if (q1==nullptr && q2==nullptr) continue;
              if (q1==nullptr || q2==nullptr) return false;
              if (q1->val!=q2->val) return false;
              queue.push(q1->left);
              queue.push(q2->left);
              queue.push(q1->right);
              queue.push(q2->right);
          }
          return true;
      }
  };
