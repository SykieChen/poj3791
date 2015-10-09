#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void solve(int ctKeys, double letterFreq[26]) {
	//�����п��ܵ��ݻ���ʽģ�����
	//ɸ���޷���ɷ���ķ�ʽ
	double avrStrike[26][26];//[m][n]������n����ĸʱʹ����m��������ʱ��ƽ��������
	int ctLetter[26][26];//��ʱ��m�����ϵ���ĸ��
	double thisStrike = 0.0;//��ǰ�ݻ���ʽ�µ�ƽ��������
	//�趨ѡ����
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			avrStrike[i][j] = 9999.9;
		}
	}
	//�׼����������ֹ����Խ��
	for (int i = 0; i < 8; i++) {
		thisStrike += letterFreq[i] * (i + 1);
		avrStrike[0][i] = thisStrike;
		ctLetter[0][i] = i + 1;
	}
	//������λ��ʼ�ݻ�
	int maxLetters = 0;
	for (int i = 1; i < ctKeys; i++) {//i Ϊ��λ��
		for (int j = i; j < 26; j++) {//��ǰ���Ͽ�ʼ����ĸ���ӿ��ܵ���ǰ��ĸ��z��ѯ
			maxLetters = 26 - (ctKeys - i - 1);//��ǰ�����Է��õ������ĸ��
			if (maxLetters > 8) maxLetters = 8;
			if (j + maxLetters > 26) maxLetters = 26 - j;//��ֹ����Խ��
			thisStrike = avrStrike[i - 1][j - 1];//��ȡ֮ǰ·�����ܻ��������ڱȽ�
			if (thisStrike > 8999.0) {
				break;
			}//ɸ�������ڵ����
			for (int k = 0; k < maxLetters; k++) {//�����ڵ�ǰ���Ϸ��ò�ͬ��������ĸ���Ƚϻ�����
				/*if (letterFreq[j + k] < 0) {
					cout << "ERR" << endl;
				}*/
				thisStrike += letterFreq[j + k] * (k + 1);
				//cout << thisStrike << endl;
				if (thisStrike < avrStrike[i][j + k]) {//����ǰ�������������٣�ˢ�±���Ļ������������浱ǰ���䷽��
					avrStrike[i][j + k] = thisStrike;
					ctLetter[i][j + k] = k + 1;
				}
			}
		}
	}
	//�ݻ����
	//�������
	printf("%.3f ", avrStrike[ctKeys - 1][25]);
	char strBuff[53];//����������У�������������
	int p = 25 + ctKeys - 1;//26��ĸ+�ո���
	strBuff[p + 1] = '\0';
	int idx = 25;//��ĸ������
	for (int i = ctKeys - 1; i >= 0; i--) {
		for (int j = 0; j < ctLetter[i][idx]; j++) {
			strBuff[p--] = 'A' + idx - j;
		}
		if (p > 0) strBuff[p--] = ' ';
		idx -= ctLetter[i][idx];
	}
	printf("%s\n", strBuff);
	return;
}




double letterFreq[26] = { 8.167,1.492,2.782,4.253,12.702,2.228,2.015,6.094,6.966,0.153,0.772,4.025,2.406,6.749,7.507,1.929,0.095,5.987,6.327,9.056,2.758,0.978,2.360,0.150,1.974,0.075 };




int main() {
	//������İٷֱ�ת��Ϊ����
	int ctKeys = 8;
	//double letterFreq[26] = { 8.167,1.492,2.782,4.253,12.702,2.228,2.015,6.094,6.966,0.153,0.772,4.025,2.406,6.749,7.507,1.929,0.095,5.987,6.327,9.056,2.758,0.978,2.360,0.150,1.974,0.075 };
	for (int i = 0; i < 26; i++) letterFreq[i] /= 100.0;
	solve(ctKeys, letterFreq);
	return 0;
}
