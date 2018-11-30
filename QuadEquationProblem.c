#include "QuadEquationProblem.h"

Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem aProblem) { 
	//�������ִ�2����������2 ������0 �������Ǵ��Ͽ������ش�
	 
	return FloatValueIsZero(aProblem._equation._c2);
}

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem aProblem) { 
	//�������ִ�2�����������Ǻ����ǰ��������������Ǵ��Ͽ������ش�
	float determinant = QuadEquationProblem_determinant(aProblem) ; 
	if (determinant < 0)
		return TRUE;
	else
		return FALSE;
	 
}

float QuadEquationProblem_determinant(QuadEquationProblem aProblem) {
	//�������ִ�2�����������Ǻ����ǰ�������Ͽ������ش�, D = b^2-4ac
	QuadEquationProblem qeProblem = aProblem;
	
	float determinant = ((qeProblem._equation._c1)*(qeProblem._equation._c1)) 
		- (4 * (qeProblem._equation._c2)*(qeProblem._equation._c0));

	return determinant;
}

Solution QuadEquationProblem_solve(QuadEquationProblem aProblem) { 
	Solution solution;
	float determinant = QuadEquationProblem_determinant(aProblem);
	// ��ü����������Ű����(�̸��׸�main()) ��������ϴ��Լ�������,
	// �̷��԰�ü�ڽŵ��ʿ��ϸ����Ѵ�.
	float sqrtDeterminant = sqrt(determinant); // <math.h>���ݵ��include
	solution._root1 = (-aProblem._equation._c1 + sqrtDeterminant)
		/ (2.0 * aProblem._equation._c2);
	solution._root2 = (-aProblem._equation._c1 - sqrtDeterminant)
		/ (2.0 * aProblem._equation._c2);
	return solution;
}