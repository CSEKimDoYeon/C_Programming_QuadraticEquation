#include <stdio.h> // scanf �Լ��� ����ϱ� ���� ����.
#include "Common.h"
#include "AppIO.h" // AppIO.h�� ���ǵǾ� �ִ� �Լ��� �����ϱ� ���ؼ� ���. 

void AppIO_out_msg_startSolvingQuadEquation() { // ���� �޽��� ���
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>\n");
}
void AppIO_out_msg_endSolvingQuadEquation() { // ���� �޽��� ���.
	printf("\n<<< ���������� Ǯ�̸� �����մϴ� >>>\n");
}

Boolean AppIO_in_solvingIsRequested() // ����ڿ��� ���� Ǯ�� ���θ� �Է¹޴� �Լ�.
{
	char answer;
	printf("\n? ��������Ǯ����'y', Ǯ�̸������Ϸ���ٸ��ƹ�Ű��ġ�ÿ�: ");
	char inputLine[255];
	scanf("%s", inputLine);
	// ��return�� key ���Է¿Ϸ�������������´�.
	answer = inputLine[0]; // ���ڿ���ù��°���ڸ��Է°����ι޴´�.
	if (answer == 'y')
		return TRUE;
	else
		return FALSE;
}

void AppIO_in_quadEquation(float* p_c0, float* p_c1, float* p_c2) // ���, 1��, 2������ ����� �Է¹޴� �Լ�.
{
	printf("? 2 �����ǰ�����Է��Ͻÿ� :");
	scanf("%f", p_c2);
	printf("? 1 �����ǰ�����Է��Ͻÿ� :");
	scanf("%f", p_c1);
	printf("? ������ǰ�����Է��Ͻÿ� :");
	scanf("%f", p_c0);
}

void AppIO_out_quadEquation(float c0, float c1, float c2) { // ���, 1��, 2������ ����� ���.
	Boolean aNonZeroTermDoesExist = FALSE;
	printf(">�־��� ������ : ");
	if (!FloatValueIsZero(c2)) { // �����0 ��������������ʴ´�.
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x*x", c2);
	}
	if (!FloatValueIsZero(c1)) { // �����0 ��������������ʴ´�.
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x", c1);
	}
	if (!FloatValueIsZero(c0)) { // �����0 ��������������ʴ´�.
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f)", c0);
	}
	if (!aNonZeroTermDoesExist) {
		printf("0"); // ������ǰ����0 �̾, ��µ����̾���.
	}
	printf(" = 0\n");
}

void AppIO_out_msg_determinantIsNegative(float aDeterminant){ // �Ǻ����� ���� �����̸� ���� �޽����� ����.
	printf("[����] �Ǻ����� ���� �����̾, �ذ� �������� �ʽ��ϴ�\n");
	printf("-�Ǻ����ǰ�: %f\n", aDeterminant);
}

void AppIO_out_solution(float root1, float root2) { // ������������ �ظ� ����Ѵ�.
	printf(">�������� �ش� ������ �����ϴ�.\n");
	printf("x1 = %f\n", root1);
	printf("x2 = %f\n", root2);
}

void AppIO_out_msg_secondOrderTermCoefficientIsZero() { // 2������ ����� 0�� ��� ���� �޽����� ����.
	printf("[����] �������� ����� 0�̾, ������������ �ƴմϴ�.\n");
}