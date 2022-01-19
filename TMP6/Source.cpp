//#include <iostream>
//using namespace std;
//
//int hesh(string str, int size)
//{
//	int a = 123, h = 0;
//	for (int i = 0;i < str.size();i++)
//	{
//		h += (str[i] * a + 12321);
//	}
//
//	return (h % size);
//}
//
//struct Node {
//	string val;
//	Node* next;
//
//	Node(string _val) : val(_val), next(nullptr) {}
//};
//
//struct list {
//	Node* first;
//	Node* last;
//
//	list() : first(nullptr), last(nullptr) {}
//
//	bool is_empty() {
//		return first == nullptr;
//	}
//
//	void push_back(string _val) {
//		Node* p = new Node(_val);
//		if (is_empty()) {
//			first = p;
//			last = p;
//			return;
//		}
//		last->next = p;
//		last = p;
//	}
//
//	Node* find(string _val) {
//		Node* p = first;
//		while (p && p->val != _val) p = p->next;
//		return (p && p->val == _val) ? p : nullptr;
//	}
//
//	void remove_first() {
//		if (is_empty()) return;
//		Node* p = first;
//		first = p->next;
//		delete p;
//	}
//
//	void remove_last() {
//		if (is_empty()) return;
//		if (first == last) {
//			remove_first();
//			return;
//		}
//		Node* p = first;
//		while (p->next != last) p = p->next;
//		p->next = nullptr;
//		delete last;
//		last = p;
//	}
//
//	void remove(string _val) {
//		if (is_empty()) return;
//		if (first->val == _val) {
//			remove_first();
//			return;
//		}
//		else if (last->val == _val) {
//			remove_last();
//			return;
//		}
//		Node* slow = first;
//		Node* fast = first->next;
//		while (fast && fast->val != _val) {
//			fast = fast->next;
//			slow = slow->next;
//		}
//		if (!fast) {
//			cout << "not exist" << endl;
//			return;
//		}
//		slow->next = fast->next;
//		delete fast;
//	}
//
//	//void replace(list l, string _val1, string _val2)
//	//{
//	//	string temp;
//	//	temp = l.find(_val2)->val;
//	//	l.find(_val2)->val = l.find(_val1)->val;
//	//	l.find(_val1)->val = temp;
//	//}
//
//	Node* operator[] (const int index) {
//		if (is_empty()) return nullptr;
//		Node* p = first;
//		for (int i = 0; i < index; i++) {
//			p = p->next;
//			if (!p) return nullptr;
//		}
//		return p;
//	}
//
//	void print() {
//		if (is_empty()) return;
//		Node* p = first;
//		while (p) {
//			cout << p->val << " ";
//			p = p->next;
//		}
//		cout << endl;
//	}
//
//	void rehesh(list* l, int size)
//	{
//		if (is_empty()) return;
//		//list *l2 = new list[size];
//		Node* p = first;
//		while (p) 
//		{
//			string s = p->val;
//			//l->remove(s);
//			l[hesh(s, size)].push_back(s);
//			//cout << p->val << " ";
//			p = p->next;
//		}
//
//		//return l2;
//	}
//};
//
//
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	cout << "Введите размер хеш-таблицы: ";
//	list spisok;
//	int n, stopprogramm = 0, choose;
//	double full =0.0,o=1.0;
//	cin >> n;
//	list *l= new list[n];
//
//	cout << "Введите 1 для вода нового слова" << endl;
//	cout << "Введите 2 для поиска слова по подсказке" << endl;
//	cout << "Введите 0 для выхода из программы" << endl;
//	while (stopprogramm == 0)
//	{
//		cin >> choose;
//		if (choose == 1)
//		{
//			cout << "Введите строку для хеширования: ";
//			string str;
//			cin >> str;
//			if (l[hesh(str, n)].is_empty())
//			{
//				full =full +  o/ n;
//				//cout <<(double)(o/n)<< full << endl;
//			}
//			int b = hesh(str, n);
//			l[b].push_back(str);
//			spisok.push_back(str);
//			cout <<"Подсказка: "<< b << endl;
//		}
//
//		if (choose == 2)
//		{
//			cout << "Введите слово для отображения его подсказки: ";
//			string str;
//			cin >> str;
//			cout << "Подсказка: " << hesh(str, n) << endl;
//		}
//
//		if (choose == 0)
//		{
//			stopprogramm++;
//		}
//
//		if (full > 0.5)
//		{
//			full = 0.0;
//			cout << "Произошло удвоение вместимости таблицы"<<endl;
//			n = n * 2;
//			delete[] l;
//			l = new list[n];
//			spisok.rehesh(l, n);
//			
//		}
//	}
//	
//	cout << endl << "Хеш-таблица: "<<endl;
//	for (int i = 0;i < n;i++)
//	{
//		if (!l[i].is_empty())
//		{
//			cout << i << ": ";
//			l[i].print();
//			//cout << endl<<i<<endl;
//		}
//		else
//		{
//			cout << i << ": 0" << endl;
//		}
//	}
//
//	delete[] l;
//	system("PAUSE");
//	return 0;
//}