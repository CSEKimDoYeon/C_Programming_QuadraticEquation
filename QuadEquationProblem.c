#include "QuadEquationProblem.h"

Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem aProblem) { 
	//가지고있는2차방정식의2 차항이0 인지를판단하여돌려준다
	 
	return FloatValueIsZero(aProblem._equation._c2);
}

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem aProblem) { 
	//가지고있는2차방정식의판별식의값이음수인지를판단하여돌려준다
	float determinant = QuadEquationProblem_determinant(aProblem) ; 
	if (determinant < 0)
		return TRUE;
	else
		return FALSE;
	 
}

float QuadEquationProblem_determinant(QuadEquationProblem aProblem) {
	//가지고있는2차방정식의판별식의값을계산하여돌려준다, D = b^2-4ac
	QuadEquationProblem qeProblem = aProblem;
	
	float determinant = ((qeProblem._equation._c1)*(qeProblem._equation._c1)) 
		- (4 * (qeProblem._equation._c2)*(qeProblem._equation._c0));

	return determinant;
}

Solution QuadEquationProblem_solve(QuadEquationProblem aProblem) { 
	Solution solution;
	float determinant = QuadEquationProblem_determinant(aProblem);
	// 객체에게일을시키는쪽(이를테면main()) 에서사용하는함수이지만,
	// 이렇게객체자신도필요하면사용한다.
	float sqrtDeterminant = sqrt(determinant); // <math.h>를반드시include
	solution._root1 = (-aProblem._equation._c1 + sqrtDeterminant)
		/ (2.0 * aProblem._equation._c2);
	solution._root2 = (-aProblem._equation._c1 - sqrtDeterminant)
		/ (2.0 * aProblem._equation._c2);
	return solution;
}