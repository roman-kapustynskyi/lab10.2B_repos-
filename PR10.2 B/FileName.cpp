#include<iostream>
#include<iomanip>
#include<string>
#include <Windows.h>
using namespace std;
enum Spec { KN, INF, ME, FI, TN };


struct Student {
	string prizv;
	int kurs;
	Spec spec;
	int fizyka;
	int matematika;
	union {
		int prog;
		int chys_metody;
		int pedagogika;
	};
};
void Create(Student* p, const int N)
{
	for (int i = 0;i < N;i++) {
		cout << "Student№ " << i + 1 << endl;
		cin.ignore();
		cout << "прізвище ";
		getline(cin, p[i].prizv);
		cout << "курс ";
		cin >> p[i].kurs;
		cout << "0 - КН, 1 - Інформатика, 2 - МЕ, 3 - ФІ, 4 - ТН";
		int x;
		cin >> x;
		while (x < 0 || x > 4) {
			cout << "Помилка! Введіть число від 0 до 4: ";
			cin >> x;
		}
		p[i].spec = (Spec)x;
		cout << "фізика ";
		cin >> p[i].fizyka;
		cout << "математика ";
		cin >> p[i].matematika;

		switch (p[i].spec) {
		case KN:
			cout << " з програмування ";
			cin >> p[i].prog;
			break;
		case INF:
			cout << " з чисельних методів ";
			cin >> p[i].chys_metody;
			break;
		default:
			cout << "з педагогіки ";
			cin >> p[i].pedagogika;
			break;
		}
	}
}
void Print(Student* p, const int N)
{
	string specStr[] = { "КН", "Інформатика", "МЕ", "ФІ", "ТН" };

	cout << string(111, '=') << endl;
	cout << "| № | Прізвище        | Курс | Спеціальність | Фізика | Математика | Програмування | Чис. методи | Педагогіка |" << endl;
	cout << string(111, '-') << endl;

	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(15) << left << p[i].prizv << " ";
		cout << "| " << setw(4) << right << p[i].kurs << " ";
		cout << "| " << setw(13) << left << specStr[p[i].spec] << " ";
		cout << "| " << setw(6) << right << p[i].fizyka << " ";
		cout << "| " << setw(10) << right << p[i].matematika << " ";

		switch (p[i].spec) {
		case KN:
			cout << "| " << setw(13) << right << p[i].prog << " "
				<< "| " << setw(11) << "" << " "
				<< "| " << setw(10) << "" << " |" << endl;
			break;
		case INF:
			cout << "| " << setw(13) << "" << " "
				<< "| " << setw(11) << right << p[i].chys_metody << " "
				<< "| " << setw(10) << "" << " |" << endl;
			break;
		default:
			cout << "| " << setw(13) << "" << " "
				<< "| " << setw(11) << "" << " "
				<< "| " << setw(10) << right << p[i].pedagogika << " |" << endl;
			break;
		}
	}
	cout << string(111, '=') << endl;
}

void Sort(Student* p, const int N){
	string specStr[] = { "КН", "Інформатика", "МЕ", "ФІ", "ТН" };
	for (int i = 0; i < N;i++) {
		for (int j = 0;j < N - i - 1;j++) {
			if ((p[j].fizyka > p[j + 1].fizyka) ||
				(p[j].fizyka == p[j + 1].fizyka && specStr[p[j].spec] > specStr[p[j + 1].spec]) ||
				(p[j].fizyka == p[j + 1].fizyka && specStr[p[j].spec] == specStr[p[j + 1].spec] && p[j].prizv > p[j + 1].prizv)) {
				Student tmp;
					tmp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = tmp;
					
			}
		}
}

}


int* IndexSort(Student* p, const int N) {
	int* I = new int[N];
	string specStr[] = { "КН", "Інформатика", "МЕ", "ФІ", "ТН" };
	for (int i = 0; i < N; i++)
		I[i] = i;
	for (int i = 0; i < N;i++) {
		for (int j = 0;j < N - i - 1;j++) {
			if ((p[I[j]].fizyka > p[I[j + 1]].fizyka) ||
				(p[I[j]].fizyka == p[I[j + 1]].fizyka && specStr[p[I[j]].spec] > specStr[p[I[j + 1]].spec]) ||
				(p[I[j]].fizyka == p[I[j + 1]].fizyka && specStr[p[I[j]].spec] == specStr[p[I[j + 1]].spec] && p[I[j]].prizv > p[I[j + 1]].prizv)) {
				int tmp = I[j];
				I[j] = I[j + 1];
				I[j + 1] = tmp;
			}
		}
	}
	return I;
}
void PrintIndexSorted(Student* p, int* I, const int N)
{
	string specStr[] = { "КН", "Інформатика", "МЕ", "ФІ", "ТН" };

	cout << string(111, '=') << endl;
	cout << "| № | Прізвище        | Курс | Спеціальність | Фізика | Математика | Програмування | Чис. методи | Педагогіка |" << endl;
	cout << string(111, '-') << endl;

	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(15) << left << p[I[i]].prizv << " ";
		cout << "| " << setw(4) << right << p[I[i]].kurs << " ";
		cout << "| " << setw(13) << left << specStr[p[I[i]].spec] << " ";
		cout << "| " << setw(6) << right << p[I[i]].fizyka << " ";
		cout << "| " << setw(10) << right << p[I[i]].matematika << " ";

		switch (p[I[i]].spec) {
		case KN:
			cout << "| " << setw(13) << right << p[I[i]].prog << " "
				<< "| " << setw(11) << "" << " "
				<< "| " << setw(10) << "" << " |" << endl;
			break;
		case INF:
			cout << "| " << setw(13) << "" << " "
				<< "| " << setw(11) << right << p[I[i]].chys_metody << " "
				<< "| " << setw(10) << "" << " |" << endl;
			break;
		default:
			cout << "| " << setw(13) << "" << " "
				<< "| " << setw(11) << "" << " "
				<< "| " << setw(10) << right << p[I[i]].pedagogika << " |" << endl;
			break;
		}
	}
	cout << string(111, '=') << endl;
}


int BinSearch(Student* p, const int N, const string prizv, const Spec spec, const int fizyka)
{
    string specStr[] = { "КН", "Інформатика", "МЕ", "ФІ", "ТН" };
    int L = 0, R = N - 1, m;

    do {
        m = (L + R) / 2;
        if (p[m].fizyka == fizyka && p[m].spec == spec && p[m].prizv == prizv)
            return m;

        if ((p[m].fizyka < fizyka) ||
            (p[m].fizyka == fizyka && specStr[p[m].spec] < specStr[spec]) ||
            (p[m].fizyka == fizyka && specStr[p[m].spec] == specStr[spec] && p[m].prizv < prizv))
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);

    return -1;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	int menuItem;
	cout << "Кількість студентів: "  << endl;
	cin >> N;
	cout << endl;
	Student* p = new Student[N];
	do {
		cout << "1 - введення ";
		cout << "2 - вивід ";
		cout << "3 - фіз.сортування ";
		cout << "4 - індекс ";
		cout << "5 - пошук ";
		cout << "0 - вихід ";
		cout << endl;
		cin >> menuItem;
		switch (menuItem) {
		case 1:Create(p, N);
			break;
		case 2:Print(p, N);
			break;
		case 3:Sort(p, N);
			break;
		case 4: {
			int* I = IndexSort(p, N);PrintIndexSorted(p, I, N);delete[] I;
			break;
		}
		case 5: {
			string prizv;
			int ispec, fizyka;
			cout << "Введіть ключі пошуку:" << endl;
			cin.ignore();
			cout << " прізвище: ";
			getline(cin, prizv);
			cout << " спеціальність (0 - КН, 1 - Інформатика, 2 - МЕ, 3 - ФІ, 4 - ТН): ";
			cin >> ispec;
			cout << " оцінка з фізики: ";
			cin >> fizyka;

			int found = BinSearch(p, N, prizv, (Spec)ispec, fizyka);
			if (found != -1)
				cout << "Знайдено студента в позиції " << found + 1 << endl;
			else
				cout << "Шуканого студента не знайдено" << endl;
			break;
		}
		
			break;
		case 0:
			break;
		default:

			break;
		}
	} while (menuItem != 0);
	
	delete[]p;

	return 0;
}



