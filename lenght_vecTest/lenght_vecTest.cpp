#include "pch.h"
#include "CppUnitTest.h"
#include "../ForUsingTest/ForUsingTest.cpp"

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <> static std::wstring ToString(const len_vec& q) {
				wstringstream s;
				s.precision(4);        // можно указать сколько знаков выводить в поток
				for (auto i = q.begin(); i != q.end(); i++) {
					s << *i << ' ';
				}
				return s.str();
			}
		}
	}
}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LenghtvecTest
{
	TEST_CLASS(LenghtvecTest)
	{
	public:

		TEST_METHOD(Test_comare_len_vec)
		{
			vec t_input = { { {-5, 0}, {-2, 4} }, { {-1, 0}, {0, 1} }, { {1, 0}, {5, 0} } };
			Assert::AreEqual(lenght_vec(t_input), { 5, 1.41421, 4 });
		}
		
		TEST_METHOD(Test_comare_double)
		{
			vec t_input = { { {-5, 0}, {-2, 4} }, { {-1, 0}, {0, 1} }, { {1, 0}, {3, 3} } };
			vector<double> r_exprcted = { 5, 1.41421, 4 };
			vector<double> r_actual = lenght_vec(t_input);
			Assert::AreEqual(r_actual.size(), r_exprcted.size(), L" different size");
			for (unsigned int i = 0; i < r_actual.size(); i++) {
				wstringstream s;
				s <<"Elements number "<< i+1 << " are different, the values "<< r_actual[i] << " and " << r_exprcted[i] ;
				Assert::IsTrue(abs(r_actual[i]- r_exprcted[i]) < EPS, s.str().c_str());
			}

		}
		TEST_METHOD(TestMethod2) {
			vec t_input = { { {-5, 0}, {-2, 4} },
							{ {-1, 0}, {0, 1}  },
							{ {1, 0},  {5, 0}  }
			};
			vector< double> r_exprcted = { 5, 1.41421, 4 };
			vector< double> r_actual = lenght_vec(t_input);
			for (unsigned int i = 0; i < r_actual.size(); i++) {
				Assert::AreEqual(r_actual[i], r_exprcted[i]);
			}

	};
}