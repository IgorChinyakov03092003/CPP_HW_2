#include <iostream>
#include <random>

#ifdef _WIN32
	#include <windows.h>
	#define msleep(x) Sleep(x)
#else
	#include <unistd.h>
	#define msleep(x) usleep(x * 1000)
#endif

using namespace std;

// размеры поля
#define HEIGHT 20
#define WIDTH 20

// структура хранения состояния клетки
struct Point {
	int is_alive = 1;
};

// генерация первого поколения
void generator(Point world[][HEIGHT]) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10000);

	for (int i = 0; i < WIDTH;i++) {
		for (int j = 0; j < HEIGHT;j++) {
			int num = dis(gen);
			if (num % 2 == 0) {
				world[i][j].is_alive = 1;
			}
			else {
				world[i][j].is_alive = 0;
			}
		}
	}
}

// вывод игрового поля на экран
void PrintWorld(Point world[][HEIGHT]) {
	for (int i = 0; i < WIDTH;i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (world[i][j].is_alive == 1) {
				cout << '@';	// живые клетки
			}
			else {
				cout << ' '; // мертвые клетки
			}
			cout << ' ';
		}
		cout << endl;
	}
}

// счетчик живых клеток
int LiveCounter(Point world[][HEIGHT]) {
	int c = 0;
	for (int i = 0; i < WIDTH;i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (world[i][j].is_alive == 1) {
				c++;
			}
		}
	}
	return c;
}

// считать координаты соседей клетки
void NeighborPoints(int NB[][2], int x, int y) {
	int k = 0;
	for (int i = x - 1;i <= x + 1;i++) {
		for (int j = y - 1;j <= y + 1;j++) {
			if (i == x && j == y) {
				continue; // пропускаем саму точку
			}
			NB[k][0] = i;
			NB[k][1] = j;
			k++;	// добавляем координаты соседей в NB
		}
	}
}

// количество живых соседей у клетки (x,y)
int NumberOfAliveNeighbors(Point world[][HEIGHT], int x, int y) {
	int c = 0;
	int NB[8][2];
	int x1;
	int y1;
	NeighborPoints(NB, x, y);
	for (int i = 0; i < 8;i++) {
		x1 = NB[i][0];
		y1 = NB[i][1];
		if (x1 < 0 || y1 < 0) {
			continue;
		}
		if (x1 >= WIDTH || y1 >= HEIGHT) {
			continue;		// отброс недопустимых значений
		}
		if (world[x1][y1].is_alive == 1) {
			c++;
		}
	}
	return c;
}

// генерация следующего поколения
void NextGen(Point newworld[][HEIGHT], Point oldworld[][HEIGHT]) {
	int aliveNB;
	Point p;
	for (int i = 0; i < WIDTH;i++) {
		for (int j = 0; j < HEIGHT;j++) {
			p = oldworld[i][j];
			aliveNB = NumberOfAliveNeighbors(oldworld, i, j);
			if (p.is_alive == 0) {
				if (aliveNB == 3) {
					newworld[i][j].is_alive = 1;
				}
			}
			else {
				if (aliveNB < 2 || aliveNB>3) {
					newworld[i][j].is_alive = 0;
				}
			}		// определение новых живых/неживых клеток
		}
	}
}

// сохранение предыдущего поколения
void SaveWorld(Point orig[][HEIGHT], Point copy[][HEIGHT]) {
	for (int i = 0; i < WIDTH;i++) {
		for (int j = 0; j < HEIGHT;j++) {
			copy[i][j] = orig[i][j];
		}
	}
}

// сравнение текущего и предыдущего поколений
int Comparison(Point first[][HEIGHT], Point second[][HEIGHT]) {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (first[i][j].is_alive != second[i][j].is_alive) {
				return -1;		// неодинаковые миры
			}
		}
	}
	return 0;	//если вернулся 0, то миры одинаковы
}

int main() {
	Point newworld[WIDTH][HEIGHT];
	Point oldworld[WIDTH][HEIGHT];
	generator(newworld);			// генерация первого поколения в newworld
	int AlivePoints = -1;			// счетчик живых клеток
	bool IsOptimal = false;			// индикатор стабильности
	do {
		PrintWorld(newworld);
		SaveWorld(newworld, oldworld);
		NextGen(newworld, oldworld);			
		// вывод текущего поколения, его сохранение и создание следующего

		IsOptimal = Comparison(newworld, oldworld) == 0;
		AlivePoints = LiveCounter(newworld);
		// обновление индикатора стабильности и счетчика живых клеток

		if (IsOptimal) {
			cout << "Reached optimal configuration!" << endl;
		}
		// случай когда достигнута стабильная конфигурация

		if (AlivePoints == 0) {
			cout << "All points are dead!" << endl;
		}
		// случай когда все клетки мертвы
		msleep(1000); // задержка
	} while (AlivePoints != 0 && !IsOptimal);	// программа работает пока либо все точки не умрут, либо не "наступит стабильность"
	return 0;
}