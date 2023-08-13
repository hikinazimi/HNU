#include <iostream>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    getchar(); // �Ե������Ļ��з� 
    int soneA = 0, soneB = 0; // ���˳���100��
    for (int i = 0; i < t; i++) {
        int scoreA = 0, scoreB = 0, oneA = 0, oneB = 0;
        int ball[] = { 15, 1, 1, 1, 1, 1, 1};
        bool turnA = true, waytored = true, prered = false; // �������� 
        while (1) {
            string cins, jida, jinqiu;
            getline(cin, cins);
            bool havegoal = false; // ����������뼰����
            if (cins.find(' ') != string:: npos) {
                int blank_pos = cins.find(' ');
                havegoal = true;
                jida = cins.substr(0, blank_pos);
                jinqiu = cins.substr(blank_pos + 1);
            } else jida = cins;
            if (cins == "-1") { // һ����Ϸ���������� ͬʱ������һ��
                if (oneA >= 100) soneA++; //���ֽ��� ��鵥���Ƿ�100 ������߲��ᳬ��200 ����ֱ��++ 
                if (oneB >= 100) soneB++;
                oneA = 0;
                oneB = 0;
                cout << scoreA << ":" << scoreB << endl;
                break;
            }
            if (jida[0] == 'N') { //���δ���� ֱ�ӻ���һ����
                int max = 4;
                if (ball[0] <= 0) { // ��������Ѿ����� ��ʱ�Ǵ����Ļ��� ��ôҪ�Ƚ�Ӧ�ô����ķ���4��˭�� �ټӸ��Է� 
                    for (int j = 1; j < 7; j++) {
                        if (ball[j] > 0) {
                            if (j + 1 > max) max = j + 1;
                            break;
                        }
                    }
                }
                if (turnA) scoreB += max;
                else scoreA += max;
                turnA = !turnA; // ����û�л����� ����
                if (oneA >= 100) soneA++; // ÿ�λ��˴��� ����鵥���Ƿ�100 ������ 
                if (oneB >= 100) soneB++;
                oneA = 0;
                oneB = 0;
                prered = false; // ���˺�Ĭ��δ�򵽺��� 
                waytored = true; // ���˺����Ȼ������
                continue;
            }
            //---------�����򲿷�------------
            int alen = jida.length(); //ÿ�λ����������� 0: ����r  1: ����y  2:����g  3:������c  4:����b  5:����p  6:����B
            int jiball[] = { 0, 0, 0, 0, 0, 0, 0}; // ��¼���򵽵�ÿ����ĸ���
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
            int jinum = 0;// �������ļ�����
            for (int j = 0; j < 7; j++) {
                if (jiball[j] != 0) jinum++;
            }
            bool iswrong = false;// �Ƿ񷸹�
            if (jinum > 1) iswrong = true; // �������һ���򷸹�
            else {
                //������������ ��Ҫһֱ�����
                if (ball[0] <= 0) { // �����Ѵ��� ����waytored
                    if (!prered) { //���ǰһ�δ�����һ������ �������Ĳ���������� ���������������Ž����ж�
                        int jiwhich = 0; //��������һ����
                        for (jiwhich = 0; jiwhich < 7; jiwhich++) {
                            if (jiball[jiwhich] > 0) break;
                        }
                        int forwhich = 1; //Ӧ�û���������
                        for (forwhich = 1; forwhich < 7; forwhich++) {
                            if (ball[forwhich] > 0) break;
                        }
                        if (jiwhich != forwhich) iswrong = true;
                    }

                }
                // ����û�д��� �ж��Ƿ�Ӧ�ô���� �ж�waytored
                else {
                    if (waytored) {
                        if (jiball[0] == 0) iswrong = true;
                    } else {
                        if (jiball[0] != 0) iswrong = true;
                    }
                }
            }
            //-------���û�н���----------
            if (!havegoal) {
                // �ж��Ƿ񵥸�100
                if (oneA >= 100) soneA++;
                if (oneB >= 100) soneB++;
                oneA = 0;
                oneB = 0;
                // ������򷸹� �Է��ӷ�
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
                turnA = !turnA; // û���� ����
                waytored = true; // ���˺����Ȼ������
                prered = false; // ���˺�Ĭ��δ������� 
            }
            //---------�������------------
            else {
                int goalball[] = { 0, 0, 0, 0, 0, 0, 0}; // ��������
                int blen = jinqiu.length();
                for (int j = 0; j < blen; j++) { //�жϽ�����ɫ�Լ���Ӧ����
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
                int goalnum = 0; // ���˼�����
                for (int j = 0; j < 7; j++) {
                    if (goalball[j] != 0) goalnum++;
                }
                //��������ʱ��û�з��� �����жϽ����Ƿ񷸹�
                if (!iswrong) {
                    if (goalnum > 1) iswrong = true; //��������򷸹�
                    else {
                        int jiwhich = 0; //��������һ����
                        for (jiwhich = 0; jiwhich < 7; jiwhich++) {
                            if (jiball[jiwhich] > 0) break;
                        }
                        int goalwhich = 0; //������һ����
                        for (goalwhich = 0; goalwhich < 7; goalwhich++) {
                            if (goalball[goalwhich] > 0) break;
                        }
                        if (goalwhich != jiwhich) iswrong = true; // ����ͽ���ͬ ����
                    }
                }
                // ������ ���ҷ���
                if (iswrong) {
                    // ����֮ǰ �ж��Ƿ񵥸�100
                    if (oneA >= 100) soneA++;
                    if (oneB >= 100) soneB++;
                    oneA = 0;
                    oneB = 0;
                    // ��ȡ��ֵ���ķ������ķ�
                    int max = 0;
                    for (int j = 6; j >= 0; j--) {
                        if (jiball[j] > 0 || goalball[j] > 0) {
                            max = j + 1;
                            break;
                        }
                    }
                    if (max < 4) max = 4;
                    if (goalball[0] != 0) ball[0] -= goalball[0]; // ������˺��� �������û� ��¼���ĺ�����
                    if (turnA) scoreB += max;
                    else scoreA += max;
                    turnA = !turnA; // ���� ���˻���
                    waytored = true;// ���˺� ����Ҫ�����
                    prered = false; //����prered ���˺�Ĭ�϶�û�����ȴ������ 
                }
                // ������ ����û�з���
                else {
                    //������������ ֻ��һ���� ������� ��������������Ӧ����ķ�ֵ���Ǵ�С����� ���Ե��ű��� 
                    int s = 0;
                    int which = 0;
                    for (which = 0; which < 7; which++) {
                        if (goalball[which] != 0) {
                            s += (which + 1) * goalball[which];
                            break;
                        }
                    }
                    if ((ball[0] <= 0) && (which != 0) && (!prered)) {
                        ball[which] = 0; // ��������Ѿ�ȫ����� ������һ�������������� ��˳�������� ��ʱ����������û�
                    }
                    if (goalball[0] != 0) {
                        ball[0] -= goalball[0]; // ������˺��� �������û� ��¼���ĺ�����
                        if (ball[0] <= 0) prered = true; // �����������һ������ ��һ��������������
                    }
                    else prered = false; // ������δ���Ĳ��Ǻ��� ��ô��һ�λ���� ǰһ�λ��򲻻��Ǻ��� 
                    if (turnA) {
                        scoreA += s;
                        oneA += s;
                    } else {
                        scoreB += s;
                        oneB += s;
                    }
                    waytored = !waytored; // ���� ���� �����
                }
            }
        }
    }
    cout << soneA << ":" << soneB;
    return 0;
}
