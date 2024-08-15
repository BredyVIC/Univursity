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

struct list12 {
	int c;
	list12 *next;
};

struct list13 {
	int c;
	list13 *next;
};

struct stack23 {
	char l[50];
	stack23 *down;
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
//<Œ¡’Œƒ€ ƒ≈–≈¬‹≈¬>

//ƒŒ¡¿¬À≈Õ»≈ ¬ (¡»Õ¿–ÕŒ≈) ƒ≈–≈¬Œ œŒ»— ¿
treeForShuffles *addToBinarSearchTree(treeForShuffles *T, int a) {
	if (T == NULL) {
		T = new treeForShuffles;
		T->data = a;
		T->l = NULL;
		T->r = NULL;
		return T;
	}

	if (a < T->data)
		T->l = addToBinarSearchTree(T->l, a);
	else
		T->r = addToBinarSearchTree(T->r, a);
	return T;
}

//œ–ﬂÃŒ… Œ¡’Œƒ
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

//Œ¡–¿“Õ€… Œ¡’Œƒ
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

// ŒÕ÷≈¬Œ… Œ¡’Œƒ
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


//ÿ»–Œ »… Œ¡’Œƒ
void pushwidthTree(queueForShufflesWidthTree *&q, treeForShuffles *T) {
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

treeForShuffles *popwidthTree(queueForShufflesWidthTree *&q) {
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
		pushwidthTree(q, p);
		do {
			p = popwidthTree(q);

			//using of p->data
			cout << p->data;

			if (p->l != NULL)
				pushwidthTree(q, p->l);
			if (p->r != NULL)
				pushwidthTree(q, p->r);
		} while (q->begin != NULL);
	}
}

//</Œ¡’Œƒ€ ƒ≈–≈¬‹≈¬>


//<œ–ﬂÃ€≈ ¿À√Œ–»“Ã€ —Œ–“»–Œ¬ »>

//¬ Àﬁ◊≈Õ»ﬂ
void inclusionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int index = i;
		while (index > 0 && a[index - 1] > x) {
			a[index] = a[index - 1];
			index--;
		}
		a[index] = x;
	}
}

//¬€¡Œ–
void selectionSort(int a[], int n) {
	int min;
	int k;
	for (int i = 0; i < n - 1; i++) {
		min = a[i];
		k = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < min) {
				min = a[j];
				k = j;
			} 
		a[k] = a[i];
		a[i] = min;
	}
}

//Œ¡Ã≈Õ, œ”«€–® 
void bubbleSort(int a[], int n) {
	int x;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (a[j] > a[j + 1]) {
				x = a[j];
				a[j] = a[j + 1];
				a[j + 1] = x;
			}
}

//</œ–ﬂÃ€≈ ¿À√Œ–»“Ã€ —Œ–“»–Œ¬ »>


//<IMPROOOOOOOOVED ¿À√Œ–»“Ã€ —Œ–“»–Œ¬ »>

//ÿ≈ÀÀ>>¬ Àﬁ◊≈Õ»ﬂ
void shellSort(int a[], int n) {
	int i, j;
	int l = 0;
	int x;
	int h[20] = { 1 };
	while (h[l] <= n / 9) {
		l++;
		h[l] = 3 * h[l - 1] + 1;
	}

	for (int m = l; m >= 0; m--)
		for (int k = 0; k < h[m]; k++) {
			i = h[m] + k;
			while (i <= n - 1) {
				x = a[i];
				j = i - h[m];
				while (j >= 0 && x < a[j]) {
					a[j + h[m]] = a[j];
					j = j - h[m];
				}
				a[j + h[m]] = x;
				i = i + h[m];
			}
		}
}

//œ»–¿Ã»ƒ¿À‹Õ€…, ƒ–≈¬≈—Õ€…>>¬€¡Œ–
void helppyramidSort(int a[], int i, int j) {
	int max = i;
	int t;
	do {
		t = max;
		int lt = 2 * t + 1;
		int rt = 2 * (t + 1);
		if (lt <= j && a[lt] > a[t])
			max = lt;
		if (rt <= j && a[rt] > a[max])
			max = rt;
		if (t == max)
			break;
		int x = a[t];
		a[t] = a[max];
		a[max] = x;
	} while (true);
}

void pyramidSort(int a[], int n) {
	for (int i = (n - 1) / 2; i > 0; i--)
		helppyramidSort(a, i, n - 1);

	for (int i = n - 1; i >= 1; i--) {
		helppyramidSort(a, 0, i);
		int x = a[0];
		a[0] = a[i];
		a[i] = x;
	}
}

//¡€—“–¿ﬂ>>œ”«€–® 
void quickSort(int a[], int top, int bottom) {
	int center = a[(bottom + top) / 2], left = top, right = bottom, b;

	while (left <= right) {
		while (a[left] < center)
			left++;

		while (a[right] > center)
			right--;

		if (left <= right) {
			b = a[right];
			a[right] = a[left];
			a[left] = b;
			left++;
			right--;
		}
	}

	if (right > top)
		quickSort(a, top, right);

	if (left < bottom)
		quickSort(a, left, bottom);
}

//</IMPROOOOOOOOVED ¿À√Œ–»“Ã€ —Œ–“»–Œ¬ »>


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

int findmin12(list12 *head) {
	list12 *p = head;
	int min = p->c;
	do
	{
		if (p->c < min)
			min = p->c;
		p = p->next;
	} while (p != head);
	return min;
}

void deletemin12(list12 *&head){
	if (head == NULL)
		return;
	list12 *p = head;

	int min = findmin12(p);

	p = head;
	while (p->c == min && p->next != head)
		p = p->next;

	if (p->c == min)
	{
		head = NULL;
		return;
	}
	head = p;
	do
	{
		if (p->next->c == min)
			p->next = p->next->next;
		else
			p = p->next;
	} while (p->next != head);
}

void F12() {
	ifstream in("12.txt");
	list12 *head = new list12;
	list12 *p = head;

	while (in.peek() != EOF)
	{
		in >> p->c;
		p->next = new list12;
		if (in.peek() != EOF)
			p = p->next;
	}
	p->next = head;

	deletemin12(head);
}

int findmax13(list13 *head, int prev) {
	if (head == NULL)
		return prev;
	int next = findmax13(head->next, head->c);

	if (next < head->c)
		next = head->c;
	return next;
}

void deletemax13(list13 *&head) {
	if (head == NULL)
		return;
	list13 *p = head;

	int max = findmax13(head->next,head->c);

	while (p!=NULL && p->c == max)
	{
		if (p->c == max)
			p = p->next;
	}
	head = p;
	if (head == NULL)
		return;
	while (p!=NULL)
	{
		if (p->next != NULL && p->next->c == max)
			p->next = p->next->next;
		else
			p = p->next;
	}
}

void F13() {
	ifstream in("13.txt");
	list13 *head = new list13;
	list13 *p = head;

	while (in.peek() != EOF)
	{
		in >> p->c;
		p->next = new list13;
		if (in.peek() != EOF)
			p = p->next;
	}
	p->next = NULL;

	deletemax13(head);
}

void F23() {
	ifstream in("23.txt");
	ofstream on("23out.txt");
	stack23 *s = NULL;
	stack23 *p;

	char *word;
	while (in.peek() != EOF)
	{
		p = s;
		s = new stack23;
		in.getline(s->l,50);
		s->down = p;
	}
	word = s->l;
	s = s->down;

	int i, j;
	while (s != NULL)
	{
		i = 0;
		while (s->l[i] != '\0')
		{
			if (s->l[i] == word[0])
			{
				j = 0;
				while (word[j]!='\0')
				{
					if (word[j] != s->l[i + j])
						break;
					j++;
				}
				if (word[j] == '\0')
				{
					on << s->l << endl;
					break;
				}
			}
			i++;
		}
		s = s->down;
	}
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

void sort43(int arr[50][50], int a, int n) {
	//run on arr[x][a]
	int max;
	int k;
	int swaps = 0;
	int compares = 0;
	for (int i = 0; i < n - 1; i++) {
		max = arr[i][a];
		k = i;
		for (int j = i + 1; j < n; j++) {
			compares++;
			if (arr[j][a] > max) {
				max = arr[j][a];
				k = j;
			}
		}
		swaps++;
		arr[k][a] = arr[i][a];
		arr[i][a] = max;
	}
}

void F43() {
	int n=10, m=2;
	int arr[50][50];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = (i+1) * (j+1) * 97 % 10;
	int a = 1;
	sort43(arr, a, n);
}

void sort44(int arr[50][50], int p, int m) {
	//run on arr[p][x]
	int compares = 0;	
	int x;
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < m - 1 - i; j++) {
			compares++;
			if (arr[p][j] < arr[p][j + 1]) {
				x = arr[p][j];
				arr[p][j] = arr[p][j + 1];
				arr[p][j + 1] = x;
			}
		}
}

void F44() {
	int n = 2, m = 10;
	int arr[50][50];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = (i + 1) * (j + 1) * 97 % 10;
	int p = 1;
	sort44(arr, p, m);
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
	F44();
	getchar();
}