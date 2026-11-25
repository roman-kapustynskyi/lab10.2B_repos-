#include "pch.h"
#include "CppUnitTest.h"
#include "../PR10.2 B/FileName.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		

				TEST_METHOD(TestPhysicalSort)
				{
					const int N = 3;
					Student* p = new Student[N];

					p[0] = { "Ivanenko", 2, KN, 4, 5 };
					p[0].prog = 5;

					p[1] = { "Petrenko", 1, INF, 4, 4 };
					p[1].chys_metody = 4;

					p[2] = { "Sydorenko", 3, ME, 3, 3 };
					p[2].pedagogika = 3;

					Sort(p, N);

					// Спочатку фізика 3 (Sydorenko), далі фізика 4: Інформатика (Petrenko) перед КН (Ivanenko)
					Assert::AreEqual(string("Sydorenko"), p[0].prizv);
					Assert::AreEqual(string("Petrenko"), p[1].prizv);
					Assert::AreEqual(string("Ivanenko"), p[2].prizv);

					delete[] p;
				}

				TEST_METHOD(TestIndexSort)
				{
					const int N = 3;
					Student* p = new Student[N];

					p[0] = { "Ivanenko", 2, KN, 4, 5 };
					p[0].prog = 5;

					p[1] = { "Petrenko", 1, INF, 4, 4 };
					p[1].chys_metody = 4;

					p[2] = { "Sydorenko", 3, ME, 3, 3 };
					p[2].pedagogika = 3;

					int* I = IndexSort(p, N);

					// Перевіряємо порядок індексів
					Assert::AreEqual(2, I[0]);
					Assert::AreEqual(1, I[1]);
					Assert::AreEqual(0, I[2]);

					// Перевіряємо, що сам масив p не змінився
					Assert::AreEqual(string("Ivanenko"), p[0].prizv);

					delete[] I;
					delete[] p;
				}

				TEST_METHOD(TestBinSearch)
				{
					const int N = 3;
					Student* p = new Student[N];

					p[0] = { "Ivanenko", 2, KN, 4, 5 };
					p[0].prog = 5;

					p[1] = { "Petrenko", 1, INF, 4, 4 };
					p[1].chys_metody = 4;

					p[2] = { "Sydorenko", 3, ME, 3, 3 };
					p[2].pedagogika = 3;

					Sort(p, N);

					// Пошук існуючого студента (після сортування Petrenko стоїть на позиції 1)
					int found = BinSearch(p, N, "Petrenko", INF, 4);
					Assert::AreEqual(1, found);

					// Пошук відсутнього студента
					int notFound = BinSearch(p, N, "Kovalenko", TN, 5);
					Assert::AreEqual(-1, notFound);

					delete[] p;
				}
			};
		}