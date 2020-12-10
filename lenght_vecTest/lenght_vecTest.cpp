#include "pch.h"
#include "CppUnitTest.h"
#include "../ForUsingTest/ForUsingTest.cpp"

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <> static std::wstring ToString(const lvec& q) {
				wstringstream s;
				s.precision(4);
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

		TEST_METHOD(TestMethod1)
		{
			vec t_input = { { {-5, 0}, {-2, 4} }, { {-1, 0}, {0, 1} }, { {1, 0}, {5, 0} } };
			Assert::AreEqual(lenght_vec(t_input), { 5, 1.41421, 4 });
		}
		TEST_METHOD(TestMethod2)
		{
			vec t_input = { { {-5, 0}, {-2, 4} }, { {-1, 0}, {0, 1} }, { {1, 0}, {5, 0} } };
			vector<double> r_exprcted = { 5, 1.41421, 4 };
			vector<double> r_actual = lenght_vec(t_input);
			for (unsigned int i = 0; i < r_actual.size(); i++) {	
				Assert::IsTrue(abs(r_actual[i]- r_exprcted[i]) < EPS, L"the elements are different");
			}

		}
	};
}