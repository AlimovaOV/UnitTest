#include "pch.h"
#include "CppUnitTest.h"
#include "../ForUsingTest/ForUsingTest.cpp"

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <> static std::wstring ToString(const vec& q) {
				wstringstream s;
				for (auto i = q.begin(); i != q.end(); i++) {
					s << "{{" << i->first.first << ", " << i->first.second << "},{";
					s << i->second.first << ", " << i->second.second << "}}, ";
				}			
				return s.str();
			}

			template <> static std::wstring ToString(const pair<double, double>& q) {
				wstringstream s;
				s << q.first << ' ' << q.second << ' ';
				return s.str();
			}
		}
	}
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CreateTest
{
	TEST_CLASS(CreateTest)
	{
	public:

		TEST_METHOD(TestMethod_compare_element) {
			stringstream ss;
			ss << "-5 0 -2 4 -1 0 0 1 1 0 5 0";     //создаем поток ввода
			vec t_actual = create(ss);
								// обратить внимание на разные способы задания значений 
								// элементам вектора сложной структуры
			vec t_exprcted = { { {-5, 0}, {-2, 4} },
								 { make_pair(-1, 0), {0, 1} },
								 make_pair(make_pair(1, 0), make_pair(5, 0))
							 };
								// Если размеры векторов различны, то выведется сообщение, 
								// указанное в третьем параметре AreEqual() – тип строки 
								// wstring (2 байта на каждый символ) поэтому нужен 
								// квалификатор «L» перед строковой константой. 
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
								// Здесь размеры одинаковые, сверяем координаты
			for (unsigned int i = 0; i < t_actual.size(); i++) {
				Assert::AreEqual(t_actual[i].first.first, t_exprcted[i].first.first);
				Assert::AreEqual(t_actual[i].first.second, t_exprcted[i].first.second);
				Assert::AreEqual(t_actual[i].second.first, t_exprcted[i].second.first);
				Assert::AreEqual(t_actual[i].second.second, t_exprcted[i].second.second);
			}
		}


		TEST_METHOD(TestMethod_compare_pair)
		{
			stringstream ss;
			ss << "-5 0 -2 4 -1 0 0 1 1 0 5 0";
			vec t_actual = create(ss);
			vec t_exprcted = { { {-5, 0}, {-2, 4} }, { {-1, 0}, {0, 1} }, { {1, 0}, {5, 0} } };
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			for (unsigned int i = 0; i < t_actual.size(); i++) {
				Assert::AreEqual(t_actual[i].first, t_exprcted[i].first);
				Assert::AreEqual(t_actual[i].second, t_exprcted[i].second);
			}
		}

		TEST_METHOD(TestMethod_compare_vector)
		{
			stringstream ss;
			ss << "-5 0 -2 4 -1 0 0 1 1 0 5 0";
			vec t_exprcted = { { {-5, 0}, {-2, 4} }, { {-1, 0}, {0, 1} }, { {1, 0}, {5, 0} } };
			Assert::AreEqual(create(ss), t_exprcted);
		}
/*
		TEST_METHOD(Test_compare_vector_double)
		{
			stringstream ss;
			ss << "-5.7 0.25 -2.27 4.44 -1 0 0 1 1 0 5 0";
			vec t_exprcted = { { {-5.7, 0.25}, {-2.27, 4.44} }, { {-1, 0}, {0, 1} }, { {1, 0}, {5, 0} } };
			Assert::AreEqual(create(ss), t_exprcted);
		}
*/
		TEST_METHOD(TestMethod4)
		{
			stringstream ss;
			ss.setstate (ios::eofbit);
			vec t_exprcted = {};
			Assert::AreEqual(create(ss), t_exprcted);
		}
		TEST_METHOD(TestMethod5)
		{
			stringstream ss;
			ss << "-5 0 -2 4 -1 0 0 1 1 0 5 0";
			vec t_exprcted = { { {-5, 0}, {-2, 4} }, { {-1, 0}, {0, 1} }, { {1, 0}, {5, 0} } };
			Assert::AreEqual(create(ss), t_exprcted);
		}
	};
}
