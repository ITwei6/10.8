#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
//int main()
//{
//	vector<int> v= { 4,1,8,5,3,7,0,9,2,6 };
//	//给内置类型进行排序,即就是用大小进行比较
//	sort(v.begin(), v.end());
//	//默认是升序
//
//	//如果向降序则需要传递仿函数对象
//	sort(v.begin(), v.end(), greater<int>());
//}
//struct Goods
//{
//	string _name;   //名称
//	double _price; // 价格
//	int _evaluate; // 评价
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		,_price(price)
//		,_evaluate(evaluate)
//	{}
//};
////对应自定义类型的比较，就需要使用仿函数
//
//struct Compare_eval_Greater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._evaluate > gr._evaluate;
//	}
//};
//struct Compare_eval_Less
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._evaluate < gr._evaluate;
//	}
//};
//
//struct Compare_name_Greater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._name > gr._name;
//	}
//};
//struct Compare_name_Less
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._name < gr._name;
//	}
//};
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//
//
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//	ComparePriceLess com;
//	//函数对象
//	sort(v.begin(), v.end(),com);
//
//	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {return gl._price > gr._price; });
//	//其实lambda底层本质也是跟函数对象的处理方式是一样的，首先会创建一个类，类里重载operator(),然后会定义一个函数对象作为仿函数。
//
//}
////int main()
////{
////	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
////	sort(v.begin(), v.end(), ComparePriceLess());//通过价格比较--升序
////	sort(v.begin(), v.end(), ComparePriceGreater());//通过价格比较--降序
////
////	//按照价格进行比较，那我想要用评价进行比较呢？名称进行比较呢？
////
////	sort(v.begin(), v.end(), Compare_eval_Greater());//通过评价比较--降序
////	sort(v.begin(), v.end(), Compare_eval_Less());//通过评价比较--升序
////
////
////	sort(v.begin(), v.end(), Compare_name_Greater());//通过名字比较--降序
////	sort(v.begin(), v.end(), Compare_name_Less());//通过名字比较--升序
////
////	//每次如果要按照不同的方式进行比较时，就需要再写一个类仿函数，太麻烦了。
////	//如果每次比较的逻辑不一样，还要去实现多个类，
////}
////
////int main()
////{
////	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
////
////	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {return gl._price > gr._price; });
////	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {return gl._price < gr._price; });
////
////	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {return gl._evaluate > gr._evaluate; });
////	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {return gl._evaluate < gr._evaluate; });
////	//lambda表达式就是一个匿名对象
////}
//
//int main()
//{
//	int a = 1, b = 2;
//	double rate1 = 10.0,rate2=10.2;
//    
//	auto fun1 = [rate1](int a, int b) {return (a + b)*rate1; };
//	//捕捉列表，捕捉变量rate1后，函数体里就可以用该变量--->传值方式捕捉
//
//	auto fun2 = [&rate1](int a, int b) {return (a + b) * rate1; };
//	//捕捉列表，捕捉变量rate1后，函数体里就可以用该变量--->引用方式捕捉
//
//	auto fun3 = [=](int a, int b) {return (a + b) * rate1/rate2; };
//	//捕捉列表，捕捉全部变量，函数体里就可以用该作用域里的所有变量--->传值方式捕捉
//
//	auto fun4 = [&](int a, int b) {return (a + b) * rate1 / rate2; };
//	//捕捉列表，捕捉全部变量，函数体里就可以用该作用域里的所有变量--->引用方式捕捉
//	cout << typeid(fun1).name() << endl;
//	cout << typeid(fun2).name() << endl;
//	cout << typeid(fun3).name() << endl;
//	cout << typeid(fun4).name() << endl;
//
//}

#include <functional>

template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}
//f函数指针
double f(double i)
{
	return i / 2;
}

//functor()函数对象
struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};
int main()
{
	// 函数名
	cout << useF(f, 11.11) << endl;
	// 函数对象
	cout << useF(Functor(), 11.11) << endl;
	// lamber表达式
	cout << useF([](double d){ return d / 4; }, 11.11) << endl;

	cout << endl;

	function<double(double)> f1 = f;
	function<double(double)> f2 = Functor();
	function<double(double)> f3 = [](double d) { return d / 4; };
	//将函数指针 /函数对象 /lambda函数包装到包装器里
	
	//cout << useF(f1, 11.11) << endl;
	//// 函数对象
	//cout << useF(f2, 11.11) << endl;
	//// lamber表达式
	//cout << useF(f3, 11.11) << endl;
	vector<function<double(double)>> v = { f1,f2,f3 };
	for (auto f : v)
	{
		cout << useF(f,11.11) << endl;
	}

	return 0;
}
