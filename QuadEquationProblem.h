#include "Common.h"
// “QuadEquationProblem” 의자료형정의

//typedef struct {
//	QuadEquation _equation;
//} QuadEquationProblem;

// “QuadEquationProblem” 와직결된함수들
// void QuadEquationProblem_setEquation (QuadEquationProblem aProblem) ;
//이번과제에서는사용할수없는함수

Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem aProblem);
//가지고있는2차방정식의2 차항이0 인지를판단한다

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem aProblem);
//가지고있는2차방정식의판별식의값이음수인지를판단한다.

float QuadEquationProblem_determinant(QuadEquationProblem aProblem);
//가지고있는2차방정식의판별식의값을얻는다.

Solution QuadEquationProblem_solve(QuadEquationProblem aProblem);
//가지고있는2차방정식을풀게하여,해를얻는다.