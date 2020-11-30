import java.util.HashSet;
import java.util.Set;

class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int[] preNode = {0,0};
        int result = 0;
        Set<String> obstaclesSet = new HashSet<String>();
        for (int[] obs : obstacles) {
            obstaclesSet.add(obs[0] + "," + obs[1]);
        }

        int direct = 0;
        for(int i = 0; i < commands.length; i++) {
            if(-2 == commands[i]) {
                direct = 0 == direct ? 3 : direct - 1;
            } else if(-1 == commands[i]) {
                direct = 3 == direct ? 0 : direct + 1;
            } else {
                for(int n = 0; n < commands[i]; n++) {
                    int[] nowNode = commandNode(preNode, direct);
                    if(!obstaclesSet.contains((nowNode[0]) + "," + (nowNode[1]))) {
                        preNode = nowNode;
                        result = Math.max(result, preNode[0] * preNode[0] + preNode[1] * preNode[1]);
                    } else {
                        break;
                    }
                }
            }
        }
        return result;
    }

    private int[] commandNode(int[] preNode, int direct) {
        int[] result = {preNode[0], preNode[1]};
        switch(direct) {
            case 0:
                result[1] += 1;
                break;
            case 1:
                result[0] += 1;
                break;
            case 2:
                result[1] -= 1;
                break;
            case 3:
                result[0] -= 1;
                break;
            default:
                break;
        }

        return result;
    }
}