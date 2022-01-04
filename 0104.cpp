#define	_CRT_SECURE_NO_WARNINGS 1

//������
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10;
struct student {
	char name[20];//����
	double math;//��ѧ
	double computer;//�����
	double english;//Ӣ��
	double pe;//����
}stu[N];//�ṹ������
bool cmp(student a, student b) {
	return (a.math + a.computer + a.english + a.pe) > (b.math + b.computer + b.english + b.pe);
}
int main() {
	int i;
	int n = 3;
	for (i = 0; i < n; i++) {
		//�����ṹ�����ݿ�
		cin >> stu[i].name >> stu[i].math >> stu[i].computer >> stu[i].english >> stu[i].pe;
	}
	//���ִܷӸߵ�������
	sort(stu, stu + n, cmp);
	//�������������
	for (i = 0; i < n; i++) {
		printf("%-8s %6.2lf %6.2lf %6.2lf %6.2lf\n", stu[i].name, stu[i].math, stu[i].computer, stu[i].english, stu[i].pe);
	}
}

//������
#include<iostream>
using namespace std;
typedef struct Lnode {
	long id;//ѧ��
	char name[20];//����
	int age;//����
	struct Lnode* next;
}Lnode,*Linklist;
//������n��Ԫ�ص�����
//β�巨����������

void CreateList(Linklist& L, int n) {
	int i;
	L = (Lnode*)malloc(sizeof(Lnode));
	if (L == NULL) {
		return;
	}
	L->next = NULL;
	Lnode* p, * q;
	q = L;
	for (i = 0; i < n; i++) {
		p = (Lnode*)malloc(sizeof(Lnode));
		if (p != NULL) {
			cout << "������ѧ����ѧ�ţ����������䣺";
			cin >> (p->id) >> p->name >> p->age;
			/*q->next = p;
			p->next = NULL;
			q = p;*/
			q->next = p;
			q = p;
		}
	}
	q->next = NULL;
}


void print(Linklist L) {
	Linklist p = L->next;
	while (p!=NULL) {
		cout << p->id << " " << p->name << " " << p->age << endl;
		p = p->next;
	}
}
void deletelist(Linklist& L, Linklist p) {
	Linklist q = L->next;
	while (q ->next!= p&&q) {
		q = q->next;
	}
	q->next = p->next;
	free(p);
}
int main() {
	int x, n;
	Linklist L;
	cout << "����������Ԫ�ظ�����";
	cin >> n;
	CreateList(L, n);
	cout << "��������Ҫ���ҵ�����ֵΪ��";
	cin >> x;
	Linklist p = L->next;
	while (p) {
		if (p->age == x) {
			//ɾ���ý��
			if (p->next == NULL) {//���һ���ڵ�
				deletelist(L, p);
			}
			else {
				p->id = p->next->id;
				strcpy(p->next->name, p->name);
				p->age = p->next->age;
				p->next = p->next->next;
			}
			
			break;
		}
		else
			p = p->next;
	}
	print(L);
}