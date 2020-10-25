import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.lang.Math;
class Solution {
    class TimeData {
        boolean m_isValide;
        String m_timeStr;
        TimeData() {
            m_isValide = false;
            m_timeStr = "";
        }

        TimeData(boolean isValide, String timeStr) {
            m_isValide = isValide;
            m_timeStr = timeStr;
        }
    }
    public List<String> readBinaryWatch(int num) {
        List<String> result = new ArrayList<String>();
        int cycle = 10 - num;
        int[] nums = new int[10];
        for(int i = 0; i < num; i++) {
            nums[i] = 1;
        }

        TimeData timeData = formatTime(nums);
        if(timeData.m_isValide) {
            result.add(timeData.m_timeStr);
        }
        for(int i = 0; i < num; i++) {
            for(int j = num - i; j < 10 - i; j++) { //swap
                // System.out.println("num: " + num + " i: " + i + " j: " + j);
                nums[j] = 1;
                nums[j-1] = 0;

                timeData = formatTime(nums);
                if(timeData.m_isValide) {
                    result.add(timeData.m_timeStr);
                }
            }
        }

        return result;
    }

    private TimeData formatTime(int[] nums) {
        System.out.println(Arrays.toString(nums));
        TimeData data = new TimeData();
        int minTime = 0;
        for(int i = 0; i < 6; i++) {
            minTime += nums[i] * Math.pow(2, i);
        }

        System.out.println(minTime);
        if(minTime > 59) {
            return data;
        }

        int hourTime = 0;
        for(int i = 6; i < 10; i++) {
            hourTime += nums[i] * Math.pow(2, i - 6);
        }

        System.out.println(hourTime);
        if(hourTime > 11) {
            return data;
        }

        data.m_isValide = true;
        data.m_timeStr = String.valueOf(hourTime) + ":" + String.format("%02d", minTime);
        System.out.println(data.m_timeStr);
        return data;
    }
}