#include <math.h>

#include "Common.h"
#include "AppIO.h"
#include "QuadEquationProblem.h"

int main()
{
	QuadEquationProblem qeProblem; // ���������� ��ü����.
	Boolean solvingIsRequested; // ����ڰ� y�� �Է��Ͽ� ����Ǯ�̸� ��û�ߴ����� ����.
	QuadEquation equation; // ���������� equation.
	Solution solution; // ������������ �ظ� ������ �ִ� ��ü.

	AppIO_out_msg_startSolvingQuadEquation(); // "���������� Ǯ�̸� �����մϴ�."
	solvingIsRequested = AppIO_in_solvingIsRequested(); // "�������� Ǯ���� y �Է�."

	while (solvingIsRequested) { // solvingIsRequested�� y���� true �� �� ����.
		AppIO_in_quadEquation(&equation._c0, &equation._c1, &equation._c2); // �����, 1����, 2���� �Է�
		AppIO_out_quadEquation(equation._c0, equation._c1, equation._c2); // �����, 1����, 2���� ���

		qeProblem._equation = equation;// ��¿������main()������ü�ǼӼ�������������
		
		if (QuadEquationProblem_secondOrderTermCoefficientIsZero(qeProblem)) {
			AppIO_out_msg_secondOrderTermCoefficientIsZero(); // 2������ ����� 0���� �Ǻ�.
		}
		else {
			if (QuadEquationProblem_determinantIsNegative(qeProblem)) { // �Ǻ����� 0 �������� �Ǻ�.
				float determinant = QuadEquationProblem_determinant(qeProblem);
				AppIO_out_msg_determinantIsNegative(determinant); // �Ǻ����� 0 �����̸� �����޽��� ���.
			}
			else {
				solution = QuadEquationProblem_solve(qeProblem); // ������������ �ظ� solution ��ü�� ����.
				AppIO_out_solution(solution._root1, solution._root2); // solution ��ü�� ����ִ� x1, x2 ���� ���.
			}
		}
		solvingIsRequested = AppIO_in_solvingIsRequested(); 
	}
	AppIO_out_msg_endSolvingQuadEquation(); // y�� �Է����� �ʾ��� ��� ���� �޽��� ���.

	system("pause"); // ���α׷��� �ڵ� ������� �ʵ��� �ϴ� �ڵ�. �Ͻ�����
	return 0;
}