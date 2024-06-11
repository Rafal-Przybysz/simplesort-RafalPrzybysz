#include <iostream>
#include <ostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "benchmark.h"
#include "../SortLib/BubbleSort.h"
#include "../SortLib/InsertionSort.h"
#include "../SortLib/SelectionSort.h"

int main()
{
	setlocale(LC_ALL, "pl-pl");
	std::vector<unsigned int> v;

	// wygenerowanie losowej zawartoœci kolekcji
	size_t n;
	std::cout << "Podaj liczbê elementów:";
	std::cin >> n;

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator((unsigned int)seed);

	for (size_t i = 0; i < n; i++)
		v.push_back(generator() /*% 1000*/);

	// wyœwietlenie zawartoœci kolekcji przed sortowaniem
	std::cout << "Kolekcja nieposortowana:" << std::endl;
	for (auto value : v)
		std::cout << value << std::endl;
	std::cout << std::endl;

	Benchmark<std::chrono::nanoseconds> b;
	bubbleSort(v.begin(), v.end());
	auto t = b.elapsed();

	// wyœwietlenie zawartoœci kolekcji po posortowaniu
	std::cout << "Kolekcja posortowana:" << std::endl;
	for (auto value : v)
		std::cout << value << std::endl;
	std::cout << std::endl;


	std::cout << "Czas sortowania: " << t << std::endl;
}
