class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                s.push(asteroids[i]);
            } else {
                bool destroyed = false;

                while (!s.empty() && s.top() > 0) { 
                    if (s.top() < -asteroids[i]) {
                        s.pop();
                        continue;
                    } 
                    else if (s.top() == -asteroids[i]) {
                        s.pop();
                        destroyed = true;
                        break;
                    } 
                    else {
                        destroyed = true;
                        break;
                    }
                }

                if (!destroyed) {
                    s.push(asteroids[i]); 
                }
            }
        }
        vector<int> res(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }

        return res;
    }
};
