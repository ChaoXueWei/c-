#ifndef BANKERALGORITHM_H_
#define BANKERALGORITHM_H_
#include <vector>
using namespace std;
bool matrixGreatAndEqualsJudgment(vector<int> mat1, vector<int> mat2);//�����ڰ�ȫ���㷨��work��need[i]�����С���ж�
bool matrixGreatJudgment(vector<int> mat1, vector<int> mat2);//���������м��㷨�ж���request�����need[pos]�����available�������
vector<int>& addMatrix(vector<int>& mat1, vector<int>& mat2);
void InitMatrix();
void printMatrix(vector<vector<int> > All, vector<vector<int> > need, vector<int> avail);
bool bankAlgorithm();
bool securityAlgorithm(vector<vector<int> > All, vector<vector<int> > need, vector<int> work);
#endif