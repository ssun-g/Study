#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int f_line[4], s_line[4];
int flag, Mx, My;
double dist;

int main() {
	for (int i = 0; i < 4; i++)
		scanf("%d", &f_line[i]);

	for (int i = 0; i < 4; i++)
		scanf("%d", &s_line[i]);

	if (f_line[0] == f_line[2] && s_line[0] == s_line[2]) flag = 1;
	else if (f_line[0] == f_line[2] && s_line[1] == s_line[3]) flag = 2;
	else if (f_line[1] == f_line[3] && s_line[0] == s_line[2]) flag = 3;
	else if (f_line[1] == f_line[3] && s_line[1] == s_line[3]) flag = 4;

	switch (flag) {
	case 1:
		Mx = (f_line[0] < s_line[0]) ? 1 : 0;
		if (f_line[0] == s_line[0]) Mx = -1;

		if (Mx == -1) dist = 0;
		else if ((max(f_line[1], f_line[3]) >= min(s_line[1], s_line[3]) && max(f_line[1], f_line[3]) <= max(s_line[1], s_line[3])) || (min(f_line[1], f_line[3]) <= max(s_line[1], s_line[3]) && min(f_line[1], f_line[3]) >= min(s_line[1], s_line[3])))
			dist = max(f_line[0], s_line[0]) - min(f_line[0], s_line[0]);

		else if (Mx == 1 && max(f_line[1], f_line[3]) < min(s_line[1], s_line[3]))
			dist = sqrt((s_line[0] - f_line[0])*(s_line[0] - f_line[0]) + (min(s_line[1], s_line[3]) - max(f_line[1], f_line[3]))*(min(s_line[1], s_line[3]) - max(f_line[1], f_line[3])));

		else if (Mx == 1 && min(f_line[1], f_line[3]) > max(s_line[1], s_line[3]))
			dist = sqrt((s_line[0] - f_line[0])*(s_line[0] - f_line[0]) + (min(f_line[1], f_line[3]) - max(s_line[1], s_line[3]))*(min(f_line[1], f_line[3]) - max(s_line[1], s_line[3])));

		else if (Mx == 0 && max(s_line[1], s_line[3]) < min(f_line[1], f_line[3]))
			dist = sqrt((f_line[0] - s_line[0])*(f_line[0] - s_line[0]) + (min(f_line[1], f_line[3]) - max(s_line[1], s_line[3]))*(min(f_line[1], f_line[3]) - max(s_line[1], s_line[3])));

		else if (Mx == 0 && min(s_line[1], s_line[3]) > max(f_line[1], f_line[3]))
			dist = sqrt((f_line[0] - s_line[0])*(f_line[0] - s_line[0]) + (min(s_line[1], s_line[3]) - max(f_line[1], f_line[3]))*(min(s_line[1], s_line[3]) - max(f_line[1], f_line[3])));
		break;

	case 2:
		Mx = (f_line[0] < min(s_line[0], s_line[2])) ? 1 : 0;
		My = (max(f_line[1], f_line[3]) < s_line[1]) ? 1 : 0;
		if (f_line[0] > max(s_line[0], s_line[2])) Mx = -1;
		if (min(f_line[1], f_line[3]) > s_line[1]) My = -1;

		if (Mx == 0 && My == 0) dist = 0;
		else if (Mx == 0 && My == 1) dist = s_line[1] - max(f_line[1], f_line[3]);
		else if (Mx == 0 && My == -1) dist = min(f_line[1], f_line[3] - s_line[1]);
		else if (Mx == 1 && My == 0) dist = min(s_line[0], s_line[2]) - f_line[0];
		else if (Mx == 1 && My == 1)
			dist = sqrt((min(s_line[0], s_line[2]) - f_line[0])*(min(s_line[0], s_line[2]) - f_line[0]) + (s_line[1] - max(f_line[1], f_line[3]))*(s_line[1] - max(f_line[1], f_line[3])));

		else if (Mx == 1 && My == -1)
			dist = sqrt((min(s_line[0], s_line[2]) - f_line[0])*(min(s_line[0], s_line[2]) - f_line[0]) + (min(f_line[1], f_line[3]) - s_line[1])*(min(f_line[1], f_line[3]) - s_line[1]));

		else if (Mx == -1 && My == 0) dist = f_line[0] - max(s_line[0], s_line[2]);
		else if (Mx == -1 && My == 1)
			dist = sqrt((f_line[0] - max(s_line[0], s_line[2]))*(f_line[0] - max(s_line[0], s_line[2])) + (s_line[1] - max(f_line[1], f_line[3]))*(s_line[1] - max(f_line[1], f_line[3])));

		else if (Mx == -1 && My == -1)
			dist = sqrt((f_line[0] - max(s_line[0], s_line[2]))*(f_line[0] - max(s_line[0], s_line[2])) + (min(f_line[1], f_line[3]) - s_line[1])*(min(f_line[1], f_line[3]) - s_line[1]));
		break;

	case 3:
		Mx = (max(f_line[0], f_line[2]) < s_line[0]) ? 1 : 0;
		My = (min(s_line[1], s_line[3]) > f_line[1]) ? 1 : 0;
		if (min(f_line[0], f_line[2]) > s_line[0]) Mx = -1;
		if (max(s_line[1], s_line[3]) < f_line[1]) My = -1;

		if (Mx == 0 && My == 0) dist = 0;
		else if (Mx == 0 && My == 1) dist = min(s_line[1], s_line[3]) - f_line[1];
		else if (Mx == 0 && My == -1) dist = f_line[1] - max(s_line[1], s_line[3]);
		else if (Mx == 1 && My == 0) dist = s_line[0] - max(f_line[0], f_line[2]);
		else if (Mx == 1 && My == 1)
			dist = sqrt((s_line[0] - max(f_line[0], f_line[2]))*(s_line[0] - max(f_line[0], f_line[2])) + (min(s_line[1], s_line[3]) - f_line[1])*(min(s_line[1], s_line[3]) - f_line[1]));

		else if (Mx == 1 && My == -1)
			dist = sqrt((s_line[0] - max(f_line[0], f_line[2]))*(s_line[0] - max(f_line[0], f_line[2])) + (f_line[1] - max(s_line[1], s_line[3]))*(f_line[1] - max(s_line[1], s_line[3])));

		else if (Mx == -1 && My == 0) dist = min(f_line[0], f_line[2]) - s_line[0];
		else if (Mx == -1 && My == 1)
			dist = sqrt((min(f_line[0], f_line[2]) - s_line[0])*(min(f_line[0], f_line[2]) - s_line[0]) + (min(s_line[1], s_line[3]) - f_line[1])*(min(s_line[1], s_line[3]) - f_line[1]));

		else if (Mx == -1 && My == -1)
			dist = sqrt((min(f_line[0], f_line[2]) - s_line[0])*(min(f_line[0], f_line[2]) - s_line[0]) + (f_line[1] - max(s_line[1], s_line[3]))*(f_line[1] - max(s_line[1], s_line[3])));
		break;

	case 4:
		My = (f_line[1] < s_line[1]) ? 1 : 0;
		if (f_line[1] == s_line[1]) My = -1;

		if (My == -1) dist = 0;
		else if (max(f_line[0], f_line[2]) >= min(s_line[0], s_line[2]) || min(f_line[0], f_line[2]) <= max(s_line[0], s_line[2]))
			dist = max(f_line[1], s_line[1]) - min(f_line[1], s_line[1]);

		else if (My == 1 && max(f_line[0], f_line[2]) < min(s_line[0], s_line[3]))
			dist = sqrt((s_line[1] - f_line[1])*(s_line[1] - f_line[1]) + (min(s_line[0], s_line[2]) - max(f_line[0], f_line[2]))*(min(s_line[0], s_line[2]) - max(f_line[0], f_line[2])));

		else if (My == 1 && min(f_line[0], f_line[2]) > max(s_line[0], s_line[2]))
			dist = sqrt((s_line[1] - f_line[1])*(s_line[1] - f_line[1]) + (min(f_line[0], f_line[2]) - max(s_line[0], s_line[2]))*(min(f_line[0], f_line[2]) - max(s_line[0], s_line[2])));

		else if (Mx == 0 && max(s_line[0], s_line[2]) < min(f_line[0], f_line[2]))
			dist = sqrt((f_line[1] - s_line[1])*(f_line[1] - s_line[1]) + (min(f_line[0], f_line[2]) - max(s_line[0], s_line[2]))*(min(f_line[0], f_line[2]) - max(s_line[0], s_line[2])));

		else if (Mx == 0 && min(s_line[0], s_line[2]) > max(f_line[0], f_line[2]))
			dist = sqrt((f_line[1] - s_line[1])*(f_line[1] - s_line[1]) + (min(s_line[0], s_line[2]) - max(f_line[0], f_line[2]))*(min(s_line[0], s_line[2]) - max(f_line[0], f_line[2])));
		break;
	}
	printf("%.1f\n", dist);

	return 0;
}