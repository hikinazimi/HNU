#include <iostream>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    getchar(); // 吃掉残留的换行符 
    int soneA = 0, soneB = 0; // 单杆超过100分
    for (int i = 0; i < t; i++) {
        int scoreA = 0, scoreB = 0, oneA = 0, oneB = 0;
        int ball[] = { 15, 1, 1, 1, 1, 1, 1};
        bool turnA = true, waytored = true, prered = false; // 以上重置 
        while (1) {
            string cins, jida, jinqiu;
            getline(cin, cins);
            bool havegoal = false; // 下面完成输入及其拆分
            if (cins.find(' ') != string:: npos) {
                int blank_pos = cins.find(' ');
                havegoal = true;
                jida = cins.substr(0, blank_pos);
                jinqiu = cins.substr(blank_pos + 1);
            } else jida = cins;
            if (cins == "-1") { // 一局游戏结束输出结果 同时进入下一局
                if (oneA >= 100) soneA++; //单局结束 检查单杆是否100 单杆最高不会超过200 所以直接++ 
                if (oneB >= 100) soneB++;
                oneA = 0;
                oneB = 0;
                cout << scoreA << ":" << scoreB << endl;
                break;
            }
            if (jida[0] == 'N') { //如果未打中 直接换另一个人
                int max = 4;
                if (ball[0] <= 0) { // 如果红球已经打完 此时是打彩球的环节 那么要比较应该打的球的分与4分谁大 再加给对方 
                    for (int j = 1; j < 7; j++) {
                        if (ball[j] > 0) {
                            if (j + 1 > max) max = j + 1;
                            break;
                        }
                    }
                }
                if (turnA) scoreB += max;
                else scoreA += max;
                turnA = !turnA; // 本次没有击中球 换人
                if (oneA >= 100) soneA++; // 每次换人打球 都检查单杆是否100 并重置 
                if (oneB >= 100) soneB++;
                oneA = 0;
                oneB = 0;
                prered = false; // 换人后默认未打到红球 
                waytored = true; // 换人后首先击打红球
                continue;
            }
            //---------击打球部分------------
            int alen = jida.length(); //每次击打的球的数组 0: 红球r  1: 黄球y  2:绿球g  3:咖啡球c  4:篮球b  5:粉球p  6:黑球B
            int jiball[] = { 0, 0, 0, 0, 0, 0, 0}; // 记录击打到的每种球的个数
            for (int j = 0; j < alen; j++) {
                switch (jida[j]) {
                    case 'r': jiball[0]++; break;
                    case 'y': jiball[1]++; break;
                    case 'g': jiball[2]++; break;
                    case 'c': jiball[3]++; break;
                    case 'b': jiball[4]++; break;
                    case 'p': jiball[5]++; break;
                    case 'B': jiball[6]++; break;
                }
            }
            int jinum = 0;// 击打了哪几种球
            for (int j = 0; j < 7; j++) {
                if (jiball[j] != 0) jinum++;
            }
            bool iswrong = false;// 是否犯规
            if (jinum > 1) iswrong = true; // 击打多于一种球犯规
            else {
                //如果红球打完了 就要一直打彩球
                if (ball[0] <= 0) { // 红球已打完 无视waytored
                    if (!prered) { //如果前一次打进最后一个红球 接下来的彩球是任意的 如果彩球不是任意球才进行判断
                        int jiwhich = 0; //击打到了哪一种球
                        for (jiwhich = 0; jiwhich < 7; jiwhich++) {
                            if (jiball[jiwhich] > 0) break;
                        }
                        int forwhich = 1; //应该击打哪种球
                        for (forwhich = 1; forwhich < 7; forwhich++) {
                            if (ball[forwhich] > 0) break;
                        }
                        if (jiwhich != forwhich) iswrong = true;
                    }

                }
                // 红球还没有打完 判断是否应该打红球 判断waytored
                else {
                    if (waytored) {
                        if (jiball[0] == 0) iswrong = true;
                    } else {
                        if (jiball[0] != 0) iswrong = true;
                    }
                }
            }
            //-------如果没有进球----------
            if (!havegoal) {
                // 判断是否单杆100
                if (oneA >= 100) soneA++;
                if (oneB >= 100) soneB++;
                oneA = 0;
                oneB = 0;
                // 如果打球犯规 对方加分
                if (iswrong) {
                    int max = 0;
                    for (int j = 6; j >= 0; j--) {
                        if (jiball[j] > 0) {
                            max = j + 1;
                            break;
                        }
                    }
                    if (max < 4) max = 4;
                    if (turnA) scoreB += max;
                    else scoreA += max;
                }
                turnA = !turnA; // 没进球 换人
                waytored = true; // 换人后率先击打红球
                prered = false; // 换人后默认未打进红球 
            }
            //---------如果进球------------
            else {
                int goalball[] = { 0, 0, 0, 0, 0, 0, 0}; // 进球数组
                int blen = jinqiu.length();
                for (int j = 0; j < blen; j++) { //判断进球颜色以及对应数量
                    if ((jinqiu[j] >= '0') && (jinqiu[j] <= '9')) {
                        goalball[0] = (goalball[0]) * 10 + jinqiu[j] - 48;
                    } else {
                        switch (jinqiu[j]) {
                            case 'r': break;
                            case 'y': goalball[1]++; break;
                            case 'g': goalball[2]++; break;
                            case 'c': goalball[3]++; break;
                            case 'b': goalball[4]++; break;
                            case 'p': goalball[5]++; break;
                            case 'B': goalball[6]++; break;
                        }
                    }
                }
                int goalnum = 0; // 进了几种球
                for (int j = 0; j < 7; j++) {
                    if (goalball[j] != 0) goalnum++;
                }
                //如果击球的时候没有犯规 下面判断进球是否犯规
                if (!iswrong) {
                    if (goalnum > 1) iswrong = true; //打进多种球犯规
                    else {
                        int jiwhich = 0; //击打了哪一种球
                        for (jiwhich = 0; jiwhich < 7; jiwhich++) {
                            if (jiball[jiwhich] > 0) break;
                        }
                        int goalwhich = 0; //进了哪一种球
                        for (goalwhich = 0; goalwhich < 7; goalwhich++) {
                            if (goalball[goalwhich] > 0) break;
                        }
                        if (goalwhich != jiwhich) iswrong = true; // 击球和进球不同 犯规
                    }
                }
                // 进球了 并且犯规
                if (iswrong) {
                    // 换人之前 判断是否单杆100
                    if (oneA >= 100) soneA++;
                    if (oneB >= 100) soneB++;
                    oneA = 0;
                    oneB = 0;
                    // 获取分值最大的犯规的球的分
                    int max = 0;
                    for (int j = 6; j >= 0; j--) {
                        if (jiball[j] > 0 || goalball[j] > 0) {
                            max = j + 1;
                            break;
                        }
                    }
                    if (max < 4) max = 4;
                    if (goalball[0] != 0) ball[0] -= goalball[0]; // 如果进了红球 红球不再拿回 记录进的红球数
                    if (turnA) scoreB += max;
                    else scoreA += max;
                    turnA = !turnA; // 犯规 换人击打
                    waytored = true;// 换人后 首先要打红球
                    prered = false; //重置prered 换人后默认都没有事先打进红球 
                }
                // 进球了 并且没有犯规
                else {
                    //不犯规的情况下 只进一种球 算出分数 由于数组索引对应的球的分值就是从小到大的 所以倒着遍历 
                    int s = 0;
                    int which = 0;
                    for (which = 0; which < 7; which++) {
                        if (goalball[which] != 0) {
                            s += (which + 1) * goalball[which];
                            break;
                        }
                    }
                    if ((ball[0] <= 0) && (which != 0) && (!prered)) {
                        ball[which] = 0; // 如果红球已经全部打进 并且这一个彩球不是任意球 按顺序打进彩球 此时彩球进不再拿回
                    }
                    if (goalball[0] != 0) {
                        ball[0] -= goalball[0]; // 如果进了红球 红球不再拿回 记录进的红球数
                        if (ball[0] <= 0) prered = true; // 如果打进了最后一个红球 下一个彩球是任意球
                    }
                    else prered = false; // 如果本次打进的不是红球 那么下一次击打的 前一次击打不会是红球 
                    if (turnA) {
                        scoreA += s;
                        oneA += s;
                    } else {
                        scoreB += s;
                        oneB += s;
                    }
                    waytored = !waytored; // 红球 彩球 交替打
                }
            }
        }
    }
    cout << soneA << ":" << soneB;
    return 0;
}
