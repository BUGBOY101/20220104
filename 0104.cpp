#define	_CRT_SECURE_NO_WARNINGS 1

//第三题
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10;
struct student {
	char name[20];//姓名
	double math;//数学
	double computer;//计算机
	double english;//英语
	double pe;//体育
}stu[N];//结构体数组
bool cmp(student a, student b) {
	return (a.math + a.computer + a.english + a.pe) > (b.math + b.computer + b.english + b.pe);
}
int main() {
	int i;
	int n = 3;
	for (i = 0; i < n; i++) {
		//创建结构体数据库
		cin >> stu[i].name >> stu[i].math >> stu[i].computer >> stu[i].english >> stu[i].pe;
	}
	//按总分从高到低排序
	sort(stu, stu + n, cmp);
	//输出排序后的数据
	for (i = 0; i < n; i++) {
		printf("%-8s %6.2lf %6.2lf %6.2lf %6.2lf\n", stu[i].name, stu[i].math, stu[i].computer, stu[i].english, stu[i].pe);
	}
}

//第五题
#include<iostream>
using namespace std;
typedef struct Lnode {
	long id;//学号
	char name[20];//姓名
	int age;//年龄
	struct Lnode* next;
}Lnode,*Linklist;
//创建含n个元素的链表
//尾插法建立单链表

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
			cout << "请输入学生的学号，姓名，年龄：";
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
	cout << "请输入链表元素个数：";
	cin >> n;
	CreateList(L, n);
	cout << "请输入您要查找的年龄值为：";
	cin >> x;
	Linklist p = L->next;
	while (p) {
		if (p->age == x) {
			//删除该结点
			if (p->next == NULL) {//最后一个节点
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