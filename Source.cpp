#include <iostream>
#include <cmath>    //sqrt(), atan2() �Լ� 

struct rect
{
	double x;
	double y;
};

struct polar
{
	double distance;
	double angle;            //radian
};

//�Լ� ����
void show_polar(polar dapos);
polar rect_to_polar(rect xypos);

//
int main(void)
{
	using namespace std;
	rect rplace;
	polar pplace;

	cout << "x���� y���� �Է��Ͻʽÿ�: ";
	while (cin >> rplace.x >> rplace.y)    //���� ��ǥ ������ �Է� (�ٸ� ���� �Է� �� ���� Ż��)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "x���� y���� �Է��Ͻʽÿ�(�������� q�� �Է�): ";
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}

//�� ��ǥ�� ȭ�鿡 ���
void show_polar(const polar dapos)
{
	using namespace std;
	const double Rad_to_deg = 57.2957951;              // 180/pi

	cout << "�Ÿ� = " << dapos.distance;
	cout << ", ���� = " << dapos.angle * Rad_to_deg;
	cout << "��\n";
}

//���� ��ǥ�� �� ��ǥ�� ��ȯ
polar rect_to_polar(rect xypos)
{
	polar answer;

	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);    //��Ÿ����� ���� �̿�
	answer.angle = atan2(xypos.y, xypos.x);                           //arctan �̿�
	return answer;
}
