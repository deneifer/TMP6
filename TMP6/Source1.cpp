//#include <iostream>
//#include <cstdlib>
//#include <string>
//
//using namespace std;
//
//
//int hesh(string str, int size)
//{
//	int a = 127, h = 0;
//	for (int i = 0;i < str.size();i++)
//	{
//		h += (str[i] * a);
//	}
//
//	return (h % size);
//}
//
//struct Node {
//	string val[2];
//	Node* next;
//
//	Node(string _val, string pod)
//	{
//		val[0] = _val;
//		val[1] = pod;
//		next=nullptr;
//	}
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
//	void push_back(string _val,string pod) {
//		Node* p = new Node(_val,pod);
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
//		while (p && p->val[0] != _val) p = p->next;
//		cout << p->val[1] << endl;
//		return (p && p->val[0] == _val) ? p : nullptr;
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
//		if (first->val[0] == _val) {
//			remove_first();
//			return;
//		}
//		else if (last->val[0] == _val) {
//			remove_last();
//			return;
//		}
//		Node* slow = first;
//		Node* fast = first->next;
//		while (fast && fast->val[0] != _val) {
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
//			cout << p->val[0] << ":"<<p->val[1];
//			p = p->next;
//		}
//		cout << endl;
//	}
//
//	void HELP() {
//		if (is_empty()) return;
//		Node* p = first;
//		while (p) {
//			cout << p->val[1] << " ";
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
//			string s = p->val[0];
//			string s2 = p->val[1];
//			//l->remove(s);
//			l[hesh(s, size)].push_back(s,s2);
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
//	setlocale(LC_ALL, "Russian");
//	cout << "Введите размер хеш-таблицы: ";
//	list spisok;
//	int n, stopprogramm = 0;
//	string choose;
//	double full = 0.0, o = 1.0;
//	cin >> n;
//	list* l = new list[n];
//
//	cout << "Введите 1 для вода нового слова" << endl;
//	cout << "Введите 2 для вывода слов из хеш-таблицы" << endl;
//	cout << "Введите HELP для поиска подсказки" << endl;
//	cout << "Введите 0 для выхода из программы" << endl;
//	while (stopprogramm == 0)
//	{
//		cin >> choose;
//		if (choose == "1")
//		{
//			cout << "Введите слово: ";
//			string str;
//			cin>> str;
//			cout << "Введите подсказку: ";
//			string str2;
//			cin.ignore();
//			getline(cin,str2);
//			if (l[hesh(str, n)].is_empty())
//			{
//				full = full + o / n;
//				//cout <<(double)(o/n)<< full << endl;
//			}
//			int b = hesh(str, n);
//			l[b].push_back(str,str2);
//			spisok.push_back(str,str2);
//			cout << "Ключ: " << b << endl;
//		}
//
//		if (choose == "2")
//		{
//			cout << endl << "Хеш-таблица: " << endl;
//			for (int i = 0;i < n;i++)
//			{
//				if (!l[i].is_empty())
//				{
//					cout << i << ": ";
//					l[i].print();
//					//cout << endl<<i<<endl;
//				}
//				else
//				{
//					cout << i << ": 0" << endl;
//				}
//			}
//		}
//
//
//		if (choose == "3")
//		{
//			string k;
//			cin >> k;
//			l[hesh(k, n)].remove(k);
//		}
//
//		if (choose == "HELP")
//		{
//			cout << "Введите слово для отображения подсказки: ";
//			string str;
//			cin >> str;
//			cout << "Подсказка: ";/* l[hesh(str, n)].HELP();*/
//		/*	cout << endl;*/
//			l[hesh(str, n)].find(str);
//		}
//
//		if (choose == "0")
//		{
//			stopprogramm++;
//		}
//
//		if (full > 0.5)
//		{
//			full = 0.0;
//			cout << "Произошло удвоение вместимости таблицы" << endl;
//			n = n * 2;
//			delete[] l;
//			l = new list[n];
//			spisok.rehesh(l, n);
//
//		}
//	}
//
//	//cout << endl << "Хеш-таблица: " << endl;
//	//for (int i = 0;i < n;i++)
//	//{
//	//	if (!l[i].is_empty())
//	//	{
//	//		cout << i << ": ";
//	//		l[i].print();
//	//		//cout << endl<<i<<endl;
//	//	}
//	//	else
//	//	{
//	//		cout << i << ": 0" << endl;
//	//	}
//	//}
//
//	delete[] l;
//	system("PAUSE");
//	return 0;
//}