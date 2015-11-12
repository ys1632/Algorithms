class Codec {
private:
    queue<TreeNode*> q;
    queue<TreeNode*> q2;
    vector<string> vec;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        if (root == NULL) return "";
        q.push(root);
        while (!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            if (cur != NULL) {
                q.push(cur->left);
                q.push(cur->right);
            }
            if (cur == NULL) {
                res += "null,";
            }
            else {
                res += to_string(cur->val) + ",";
            }
            
        }
        //delete extra "," at the end 
        res.pop_back();

        //remove all "null" at the end
        while(res.find('l', res.length() - 1) == res.length() - 1) {
            res.erase(res.length() - 5);
        }
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() < 1) return NULL;
        int prePos = 0;
        int curPos = 0;
        while (data.find(',', prePos + 1) != string::npos) {
            curPos = data.find(',', prePos + 1);
            vec.push_back(data.substr(prePos + 1, curPos - 1 - (prePos + 1) + 1 ) );
            prePos = curPos;
        }
        vec.push_back(data.substr(prePos + 1, data.length() - 1 - (prePos + 1) + 1) );
        
        TreeNode * root = new TreeNode(stoi(vec[0]));
        q2.push(root);
        int i = 1;
        while (i < vec.size() && !q2.empty()) {
            TreeNode * cur = q2.front();
            q2.pop();
            if (i < vec.size() && vec[i].compare("null") != 0) {
                TreeNode * newNode = new TreeNode(stoi(vec[i]));
                cur->left = newNode;
                q2.push(newNode);
            }
            i++;
            if (i < vec.size() && vec[i].compare("null") != 0) {
                TreeNode * newNode = new TreeNode(stoi(vec[i]));
                cur->right = newNode;
                q2.push(newNode);
            }
            i++;
        }
        return root;
        
    }
};