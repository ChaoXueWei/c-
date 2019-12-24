#ifndef BANKERALGORITHM_H_
#define BANKERALGORITHM_H_
#include <vector>
using namespace std;
bool matrixGreatAndEqualsJudgment(vector<int> mat1, vector<int> mat2);//用于在安全性算法中work和need[i]矩阵大小的判断
bool matrixGreatJudgment(vector<int> mat1, vector<int> mat2);//用于在银行家算法中对于request矩阵和need[pos]矩阵和available矩阵的判
vector<int>& addMatrix(vector<int>& mat1, vector<int>& mat2);
void InitMatrix();
void printMatrix(vector<vector<int> > All, vector<vector<int> > need, vector<int> avail);
bool bankAlgorithm();
bool securityAlgorithm(vector<vector<int> > All, vector<vector<int> > need, vector<int> work);
#endif