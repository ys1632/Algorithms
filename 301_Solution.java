import java.util.*;

public class Solution_301 {
    public static void main(String[] args) {
        System.out.println(removeInvalidParentheses("()())()"));
    }

    public List<String> removeInvalidParentheses(String s) {
        Queue<String> q = new LinkedList<String>();
        HashSet<String> visited = new HashSet<String>();
        List<String> res = new ArrayList<String>();
        
        if (s == null || s == "") {
            res.add(s);
            return res;
        }
        
        q.add(s);
        visited.add(s);
        boolean found = false;
        while(!q.isEmpty()) {
            String str = q.poll();
            if (isValid(str)) {
                res.add(str);
                found = true;
            }
            
            if (found) continue;
            
            for (int i = 0; i < str.length(); i++) {
                if (str.charAt(i) != '(' && str.charAt(i) != ')') continue;
                String str2 = str.substring(0, i) + str.substring(i+1);
                if (visited.contains(str2)) continue;
                q.add(str2);
                visited.add(str2);
            }
        }
        
        return res;
        
    }
    
    public boolean isValid(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') count++;
            if (s.charAt(i) == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
}