#include <iostream>
#include <cmath>    //sqrt(), atan2() 함수 

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

//함수 원형
void show_polar(polar dapos);
polar rect_to_polar(rect xypos);

//
int main(void)
{
	using namespace std;
	rect rplace;
	polar pplace;

	cout << "x값과 y값을 입력하십시오: ";
	while (cin >> rplace.x >> rplace.y)    //직각 좌표 정보를 입력 (다른 형값 입력 시 루프 탈출)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "x값과 y값을 입력하십시오(끝내려면 q를 입력): ";
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}

//극 좌표를 화면에 출력
void show_polar(const polar dapos)
{
	using namespace std;
	const double Rad_to_deg = 57.2957951;              // 180/pi

	cout << "거리 = " << dapos.distance;
	cout << ", 각도 = " << dapos.angle * Rad_to_deg;
	cout << "도\n";
}

//직각 좌표를 극 좌표로 변환
polar rect_to_polar(rect xypos)
{
	polar answer;

	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);    //피타고라스의 정리 이용
	answer.angle = atan2(xypos.y, xypos.x);                           //arctan 이용
	return answer;
}
