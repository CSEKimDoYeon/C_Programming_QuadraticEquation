#include "Common.h"
// ��QuadEquationProblem�� ���ڷ�������

//typedef struct {
//	QuadEquation _equation;
//} QuadEquationProblem;

// ��QuadEquationProblem�� ��������Լ���
// void QuadEquationProblem_setEquation (QuadEquationProblem aProblem) ;
//�̹����������»���Ҽ������Լ�

Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem aProblem);
//�������ִ�2����������2 ������0 �������Ǵ��Ѵ�

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem aProblem);
//�������ִ�2�����������Ǻ����ǰ��������������Ǵ��Ѵ�.

float QuadEquationProblem_determinant(QuadEquationProblem aProblem);
//�������ִ�2�����������Ǻ����ǰ�����´�.

Solution QuadEquationProblem_solve(QuadEquationProblem aProblem);
//�������ִ�2����������Ǯ���Ͽ�,�ظ���´�.