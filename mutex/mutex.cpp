// mutex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <omp.h>
#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
std::mutex mtx;
void fir(char a) {
   int n = 5; // количество уровней елочки

   for (int i = 1; i <= n; i++) {
      // печатаем пробелы перед звездочками
      for (int j = 1; j <= n - i; j++) {
         std::cout << " ";
      }

      // печатаем звездочки
      for (int k = 1; k <= 2 * i - 1; k++) {
         std::cout << a;
      }

      std::cout << std::endl;
   }

   // печатаем ствол елочки
   for (int i = 1; i <= n - 1; i++) {
      std::cout << " ";
   }
   std::cout << "|";
   std::cout << std::endl;
   return;
}

void fir_mutex(char a) {
   mtx.lock();
   int n = 5; // количество уровней елочки

   for (int i = 1; i <= n; i++) {
      // печатаем пробелы перед звездочками
      for (int j = 1; j <= n - i; j++) {
         std::cout << " ";
      }

      // печатаем звездочки
      for (int k = 1; k <= 2 * i - 1; k++) {
         std::cout << a;
      }

      std::cout << std::endl;
   }

   // печатаем ствол елочки
   for (int i = 1; i <= n - 1; i++) {
      std::cout << " ";
   }
   std::cout << "|";
   std::cout << std::endl;
   mtx.unlock();
   return;
}

int main() {
   std::vector <char> arr = { 'a', 'b', 'c', 'd', 'e' };
   int size = arr.size();
   std::vector<std::thread> threads_first;
   for (int i = 0; i < arr.size(); i++) {
      threads_first.push_back(std::thread(fir, arr[i]));
   }
   for (auto& thread : threads_first) {
      thread.join();
   }

   std::cout << "-------------------------" << std::endl;
   std::vector<std::thread> threads_second;
   for (int i = 0; i < arr.size(); i++) {
      threads_second.push_back(std::thread(fir_mutex, arr[i]));
   }
   for (auto& thread : threads_second) {
      thread.join();
   }

   return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
