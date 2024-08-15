#include <fstream>
#include <iostream>
using namespace std;

struct list1 {
	int a;
	list1 *next;
};

struct listc {
	char a;
	listc *next;
};

struct listw6 {
	char w[9];
	listw6 *next;
};

struct listw7
{
	char w[8];
	listw7 *next;
};

struct list8 {
	int c;
	list8 *next;
};

struct list9 {
	int c;
	list9 *next;
};

struct list10 {
	int c;
	list10 *next;
};

struct list11 {
	float c;
	list11 *next;
};

struct stack24c {
	float c;
	stack24c *down;
};

struct stack24k {
	char c;
	stack24k *down;
};

struct tree30 {
	int a;
	tree30 *l, *r;
};

struct stack30 {
	tree30 *data;
	stack30 *down;
};

struct tree35 {
	int a;
	tree35 *l, *r;
};

struct row50
{
	int num;
	float start;
	float finish;
};

struct row50lite {
	int num;
	float time;
};

struct treeForShuffles
{
	int data;
	treeForShuffles *l;
	treeForShuffles *r;
};

struct stackForShuffles {
	treeForShuffles *data;
	stackForShuffles *down;
};

struct queueForShuffles {
	treeForShuffles *data;
	queueForShuffles *next;
};

struct stackForShufflesEndTree {
	treeForShuffles *data;
	stackForShufflesEndTree *down;
	bool isReady;
};

struct listForShufflesWidthTree {
	treeForShuffles *data;
	listForShufflesWidthTree *next;
};

struct queueForShufflesWidthTree {
	listForShufflesWidthTree *begin;
	listForShufflesWidthTree *end;
};
//<ÎÁÕÎÄÛ ÄÅÐÅÂÜÅÂ>

//ÄÎÁÀÂËÅÍÈÅ Â ÁÈÍÀÐÍÎÅ ÄÅÐÅÂÎ
treeForShuffles *addToBinarTree(treeForShuffles *T, int a) {
	if (T == NULL) {
		T = new treeForShuffles;
		T->data = a;
		T->l = NULL;
		T->r = NULL;
		return T;
	}

	if (a < T->data)
		T->l = addToBinarTree(T->l, a);
	else
		T->r = addToBinarTree(T->r, a);
	return T;
}

//ÏÐßÌÎÉ ÎÁÕÎÄ
void linearTreeShuffle(treeForShuffles *T) {
	treeForShuffles *p = T;
	stackForShuffles *s = NULL;
	stackForShuffles *ps;

	while (p != NULL)
	{
		//using of p->data
		cout << p->data;
		if (p->l != NULL && p->r != NULL) {
			ps = s;
			s = new stackForShuffles;
			s->data = p->r;
			s->down = ps;
			p = p->l;
		}
		else if (p->l == NULL && p->r == NULL) {
			if (s != NULL) {
				p = s->data;
				s = s->down;
			}
			else
				p = NULL;
		}
		else if (p->l != NULL)
			p = p->l;
		else
			p = p->r;
	}
}

//ÎÁÐÀÒÍÛÉ ÎÁÕÎÄ
void reverceTreeShuffle(treeForShuffles *T) {

	treeForShuffles *p = T;
	stackForShuffles *s = NULL;
	stackForShuffles *ps;
	while (true) {
		while (p != NULL) {
			ps = s;
			s = new stackForShuffles;
			s->data = p;
			s->down = ps;
			p = p->l;
		}
		if (s != NULL) {
			p = s->data;
			s = s->down;
			//using of p->data
			cout << p->data;
			p = p->r;
		}
		else break;
	}
}

//ÊÎÍÖÅÂÎÉ ÎÁÕÎÄ
void endTreeShuffle(treeForShuffles *T) {
	treeForShuffles *p = T;
	stackForShufflesEndTree *s = NULL;
	stackForShufflesEndTree *ps;
	bool F;
	do {
		while (p != NULL) {
			ps = s;
			s = new stackForShufflesEndTree;
			s->data = p;
			s->isReady = false;
			s->down = ps;
			p = p->l;
		}
		if (s != NULL) {
			do {
				p = s->data;
				F = s->isReady;
				s = s->down;
				if (F)
					//using of p->data
					cout << p->data;
			} while (F && s != NULL);
			if (!F) {
				ps = s;
				s = new stackForShufflesEndTree;
				s->data = p;
				s->isReady = true;
				s->down = ps;
				p = p->r;
			}
		}
	}
	while (s != NULL);
}


//ØÈÐÎÊÈÉ ÎÁÕÎÄ
void push(queueForShufflesWidthTree *&q, treeForShuffles *T) {
	if (q->end == NULL)
	{
		q->begin = new listForShufflesWidthTree;
		q->end = q->begin;
	}
	else
	{
		q->end->next = new listForShufflesWidthTree;
		q->end = q->end->next;
	}
	q->end->data = T;
	q->end->next = NULL;
}

treeForShuffles *pop(queueForShufflesWidthTree *&q) {
	treeForShuffles *p;
	if (q->begin != NULL)
	{
		p = q->begin->data;
		q->begin = q->begin->next;
		if (q->begin == NULL)
			q->end = NULL;
		return p;
	}
	return NULL;
}

void widthTreeShuffle(treeForShuffles *T) {
	queueForShufflesWidthTree *q = new queueForShufflesWidthTree;
	q->begin = NULL;
	q->end = NULL;
	treeForShuffles *p = T;
	if (p != NULL) {
		push(q, p);
		do {
			p = pop(q);

			//using of p->data
			cout << p->data;

			if (p->l != NULL)
				push(q, p->l);
			if (p->r != NULL)
				push(q, p->r);
		} while (q->begin != NULL);
	}
}

//</ÎÁÕÎÄÛ ÄÅÐÅÂÜÅÂ>


//<ÏÐßÌÛÅ ÀËÃÎÐÈÒÌÛ ÑÎÐÒÈÐÎÂÊÈ>



//</ÏÐßÌÛÅ ÀËÃÎÐÈÒÌÛ ÑÎÐÒÈÐÎÂÊÈ>


void F1() {
	ifstream in("1.txt");
	int c = 0;
	bool f;
	list1 *list = new list1;
	in >> c;
	list->a = c;
	list->next = NULL;
	list1 *p;
	while (in.peek()!=EOF)
	{
		in >> c;
		f = false;
		p = list;
		while (p != NULL)
		{
			if (p->a == c){
				f = true;
				break;
			}
			p = p->next;
		}
		if (!f)
		{
			list1 *p1 = new list1;
			p1->a = c;
			p1->next = list;
			list = p1;
		}
	}
}

void F2() {
	ifstream in("2.txt");
	list1 *head = new list1;
	list1 *p;
	int c,prev;
	in >> c;
	prev = c;
	head->a = c;
	head->next = NULL;
	while (in.peek() != EOF)
	{
		in >> c;
		if (c != prev)
		{
			p = new list1;
			p->a = c;
			p->next = head;
			head = p;
			prev = c;
		}
	}
}

void F3() {
	ifstream in("3.txt");
	char c;
	listc *l1 = new listc;
	listc *l2 = new listc;
	listc *p = l1;

	in >> c;
	while (c != ',')
	{
		p->a = c;
		in >> c;
		if (c != ',')
			p = p->next = new listc;
	}
	p->next = NULL;

	p = l2;
	while (in.peek() != EOF)
	{
		in >> c;
		p->a = c;
		if (in.peek() != EOF)
			p = p->next = new listc;
	}
	p->next = NULL;

	bool equal = true;
	listc *p1 = l1;
	listc *p2 = l2;

	while (equal && p1 != NULL && p2 != NULL)
	{
		if (p1->a != p2->a)
			equal = false;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1 != p2)
		equal = false;
}

void F3rev() {
	ifstream in("3.txt");
	char c;
	listc *l1 = NULL;
	listc *l2 = NULL;
	listc *p;

	in >> c;
	while (c != ',')
	{
		p = new listc;
		p->a = c;
		p->next = l1;
		l1 = p;
		in >> c;
	}

	while (in.peek() != EOF)
	{
		in >> c;
		p = new listc;
		p->a = c;
		p->next = l2;
		l2 = p;
	}

	bool equal = true;
	listc *p1 = l1;
	listc *p2 = l2;

	while (equal && p1 != NULL && p2 != NULL)
	{
		if (p1->a != p2->a)
			equal = false;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1 != p2)
		equal = false;
}

void F4() {
	ifstream in("4.txt");
	char c;
	listc *S1 = NULL;
	listc *S2 = NULL;
	listc *p;

	in >> c;
	while (c != ',')
	{
		p = new listc;
		p->a = c;
		p->next = S1;
		S1 = p;
		in >> c;
	}

	while (in.peek() != EOF)
	{
		in >> c;
		p = new listc;
		p->a = c;
		p->next = S2;
		S2 = p;
	}

	bool enter = false;

	listc *p1;
	listc *p2;

	p = S2;
	while (!enter && p != NULL)
	{
		p1 = S1;
		p2 = p;
		while (p1 != NULL && p2!= NULL)
		{
			if (p1->a != p2->a)
				break;
			p1 = p1->next;
			p2 = p2->next;
		}
		if (p1 == NULL)
			enter = true;
		p = p->next;
	}
}

void F5() {
	ifstream in("5.txt");

	listc *S1 = new listc;
	listc *S2 = new listc;
	listc *p;
	char c;

	p = S1;
	in >> c;
	while (c != ',')
	{
		p->a = c;
		in >> c;
		if (c != ',')
			p = p->next = new listc;
	}
	p->next = S1;

	p = S2;
	while (in.peek() != EOF)
	{
		in >> c;
		p->a = c;
		if (in.peek() != EOF)
		{
			p = p->next = new listc;
		}
	}
	p->next = S2;

	listc *p1;
	listc *p2;
	listc *p1head;
	bool equals = false;

	p = S2;
	do
	{
		p1 = S1;
		do{
			if (p1->a == p->a)
				break;
			p1 = p1->next;
		} while (p1 != S1);

		if (p1->a == p->a)
		{
			p1head = p1;
			p2 = p;
			do
			{
				if (p1->a != p2->a)
					break;
				p1 = p1->next;
				p2 = p2->next;
			} while (p1 != p1head);
			if (p1 == p1head)
				equals = true;
		}
		p = p->next;
	} while (!equals && p != S2);

}

listw6 *F6f(listw6 *s, char c) {
	while (s != NULL) {	
		if (s->w[0] == c && s->w[7] == c)
			break;
		s = s->next;
	}
	return s;
}

void F6() {
	char c = 'a';
	ifstream in("6.txt");

	listw6 *head = new listw6;
	listw6 *p = head;
	do
	{
		in >> p->w;
		if (in.peek() != EOF)
			p = p->next = new listw6;
	} while (in.peek() != EOF);
	p->next = NULL;

	p = F6f(head, c);
	while (p != NULL) {
		cout << p->w << "\n";
		p = F6f(p->next, c);
	}
}

void printRange7(listw7 *head) {
	listw7 *p;
	for (int i = 1; i <= 7; i++)
	{
		p = head;
		while (p != NULL)
		{
			if (p->w[i] == '\0')
				cout << p->w << " ";
			p = p->next;
		}
	}
}

void F7() {
	ifstream in("7.txt");
	listw7 *head = new listw7;
	listw7 *p = head;

	while (in.peek() != EOF)
	{
		in >> p->w;
		if (in.peek() != EOF)
			p = p->next = new listw7;
	}
	p->next = NULL;

	printRange7(head);
}

void summ8(list8 *p, int k, int n) {
	if (k > n)
	{
		cout << "Error: k>n";
		return;
	}
	if (k < 1)
	{
		cout << "Error: k<1";
		return;
	}
	int sum = 0;
	int i = 1;
	while (p != NULL && i <= n)
	{
		if (i>=k)
			sum += p->c;
		i++;
		p = p->next;
	}
	i--;
	if (i < n)
	{
		cout << "Error: n>N";
		return;
	}
	cout << sum;
}

void F8() {
	ifstream in("8.txt");

	list8 *head = new list8;
	list8 *p = head;
	while (in.peek() != EOF)
	{
		in >> p->c;
		if (in.peek() != EOF)
			p = p->next = new list8;
	}
	p->next = NULL;

	int k = 15, n = 16;
	summ8(head, k, n);
}

void summ9(list9 *head) {
	while (head->next->next != NULL)
		head = head->next;
	cout << head->c + head->next->c;
}

void F9() {
	ifstream in("9.txt");
	list9 *head = new list9;
	list9 *p = head;
	while (in.peek() != EOF)
	{
		in >> p->c;
		if (in.peek() != EOF)
			p = p->next = new list9;
	}
	p->next = NULL;

	summ9(head);
}

void swap10(list10 *&list) {
	list10 *head = list;
	while (list->next->next != NULL)
		list = list->next;
	list10 *oldE = list->next;
	oldE->next = head->next;
	
	list->next = head;
	head->next = NULL;

	list = oldE;
}

void F10() {
	ifstream in("10.txt");
	list10 *head = new list10;
	list10 *p = head;
	while (in.peek() != EOF)
	{
		in >> p->c;
		if (in.peek() != EOF)
			p = p->next = new list10;
	}
	p->next = NULL;
	swap10(head);
}

void mid11(list11 *p) {
	float sum = 0;
	int n = 0;

	while (p != NULL)
	{
		sum += p->c;
		n++;
		p = p->next;
	}

	cout << sum/n;
}

void F11() {
	ifstream in("11.txt");
	list11 *head = new list11;
	list11 *p = head;
	while (in.peek() != EOF)
	{
		in >> p->c;
		if (in.peek() != EOF)
			p = p->next = new list11;
	}
	p->next = NULL;
	mid11(head);
}

void F24() {
	ifstream in("24.txt");
	char c;
	stack24c *digits = NULL;
	stack24k *comms = NULL;

	stack24c *pc;
	stack24k *pk;

	float a, b;
	char comm;

	while (in.peek() != EOF)
	{
		in >> c;
		if (c >= '0' && c <= '9')
		{
			pc = digits;
			digits = new stack24c;
			digits->c = c - '0';
			digits->down = pc;
		}
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			pk = comms;
			comms = new stack24k;
			comms->c = c;
			comms->down = pk;
		}
		if (c == ')')
		{
			a = digits->c;
			digits = digits->down;
			b = digits->c;
			comm = comms->c;
			comms = comms->down;

			b = comm == '+' ? b + a :
				(comm == '-' ? b - a :
				(comm == '*' ? b * a :
					b / a));

			digits->c = b;
		}
	}

	cout << digits->c;
}

tree30 *addtree30(tree30 *T, int a) {
	if (T == NULL) {
		T = new tree30;
		T->a = a;
		T->l = NULL;
		T->r = NULL;
		return T;
	}

	if (a < T->a)
		T->l = addtree30(T->l, a);
	else
		T->r = addtree30(T->r, a);
	return T;
}

int summ30(tree30 *T) {
	tree30 *p = T;
	stack30 *s = NULL;
	stack30 *ps;

	int summ = 0;

	while (p != NULL)
	{
		summ += p->a;
		if (p->l != NULL && p->r != NULL) {
			ps = s;
			s = new stack30;
			s->data = p->r;
			s->down = ps;
			p = p->l;
		}
		else if (p->l == NULL && p->r == NULL) {
			if (s != NULL) {
				p = s->data;
				s = s->down;
			}
			else
				p = NULL;
		}
		else if (p->l != NULL)
			p = p->l;
		else
			p = p->r;
	}
	return summ;
}

void F30() {
	ifstream in("30.txt");
	tree30 *T = NULL;
	int c;
	while (in.peek() != EOF)
	{
		in >> c;
		T = addtree30(T, c);
	}
	cout << summ30(T);
}

tree35 *addtree35(tree35 *T, int a) {
	if (T == NULL) {
		T = new tree35;
		T->a = a;
		T->l = NULL;
		T->r = NULL;
		return T;
	}

	if (a < T->a)
		T->l = addtree35(T->l, a);
	else
		T->r = addtree35(T->r, a);
	return T;
}

int find35(tree35 *T, int a, int k) {
	if (T == NULL)
		return -1;
	if (T->a == a)
		return k;
	k++;
	if (a < T->a)
		k = find35(T->l, a, k);
	else 
		k = find35(T->r, a, k);
	return k;
}

void F35() {
	tree35 *T = NULL;
	ifstream in("35.txt");

	int a;
	in >> a;
	while (a != 0) {
		T = addtree35(T, a);
		in >> a;
	}

	int k = 0, e = 0;
	cout << "Your element to find: ";
	cin >> e;
	k = find35(T, e, k);
	if (k == -1)
		cout << "Element does not exist.";
	else
		cout << "Element's path lenght from root" << k;
}

void F50() {
	ifstream in("50.txt");
	row50 table[50];
	int n = 0;
	while (in.peek() != EOF)
	{
		in >> table[n].num >> table[n].start >> table[n].finish;
		n++;
	}
	//
	row50lite tablelite[50];
	for (int i = 0; i < n; i++)
	{
		tablelite[i].num = table[i].num;
		tablelite[i].time = table[i].finish - table[i].start;
	}
	int i1=0, i2=0, i3=0;
	for (int i = 1; i < n; i++)
		if (tablelite[i].time < tablelite[i1].time)
			i1 = i;

	for (int i = 1; i < n; i++)
		if (i != i1 && tablelite[i].time < tablelite[i2].time)
			i2 = i;
	
	for (int i = 1; i < n; i++)
		if (i != i1 && i != i2 && tablelite[i].time < tablelite[i3].time)
			i3 = i;
	printf_s("%d\t%.3f\n",tablelite[i1].num,tablelite[i1].time);
	printf_s("%d\t%.3f\n",tablelite[i2].num,tablelite[i2].time);
	printf_s("%d\t%.3f",tablelite[i3].num,tablelite[i3].time);
}

void main() {

	treeForShuffles *T = NULL;
	ifstream in("35.txt");

	int a;
	in >> a;
	while (a != 0) {
		T = addToBinarTree(T, a);
		in >> a;
	}
	widthTreeShuffle(T);
	getchar();
}