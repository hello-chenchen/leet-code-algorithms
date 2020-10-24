//NOTICE: f(x) = !f(x-1)
class Solution {
    public boolean divisorGame(int N) {
        return 0 == N % 2 ? true : false;
    }
}