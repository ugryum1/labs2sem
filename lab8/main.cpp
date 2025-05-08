#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <map>

using namespace std;

void task1() {
    cout << "Задание №1." << endl;
    string surname, name, patronymic;
    cout << "Введите 3 строки - фамилию, имя и отчество." << endl;
    getline(cin, surname);
    getline(cin, name);
    getline(cin, patronymic);

    string initials = surname + " " + name[0] + "." + patronymic[0] + ".";
    cout << initials << endl << endl;
}

void task2() {
    cout << "Задание №2." << endl;
    string firstWord, secondWord;
    cout << "Введите 2 слова одинаковой длины в двух разных строках." << endl;
    getline(cin, firstWord);
    getline(cin, secondWord);

    if (firstWord.size() != secondWord.size()) {
        cout << "Слова должны быть одинаковой длины." << endl << endl;
        return;
    }

    string result = "";
    for (int i = 0; i < firstWord.size(); ++i) {
        result += firstWord[i];
        result += secondWord[i];
    }

    cout << result << endl << endl;
}

void task3() {
    cout << "Задание №3." << endl;
    ifstream inputFile("/home/ugryum/labs2sem/lab8/fileForTask3.txt");
    ofstream outputFile("/home/ugryum/labs2sem/lab8/NewFileForTask3.txt");

    if (!inputFile.is_open()) {
        cout << "Ошибка открытия fileForTask3.txt" << endl << endl;
        return;
    }

    if (!outputFile.is_open()) {
        cout << "Ошибка открытия NewFileForTask3.txt" << endl << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        for (char c : line) {
            if (c == '!') {
                outputFile << "!!!";
            } else {
                outputFile << c;
            }
        }
        outputFile << "\n";
    }

    inputFile.close();
    outputFile.close();

    cout << "Обработка завершена. Результат записан в NewFileForTask3.txt." << endl << endl;
}

template <typename T>
void printVector(const vector<T> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void task4() {
    cout << "Задание №4." << endl;
    vector<float> firstVector(25, 0.0);
    vector<float> secondVector(25, 0.0);
    vector<float> result(25, 0.0);

    for(int i = 0; i < 25; ++i) {
        float value = static_cast<float>(i);
        firstVector[i] = value / 2;
        secondVector[i] = value / 4;
    }

    for(int i = 0; i < 25; ++i) {
        result[i] = firstVector[i] + secondVector[i];
    }

    cout << "firstVector:\t";
    printVector(firstVector);
    cout << "secondVector:\t";
    printVector(secondVector);
    cout << "result:\t\t";
    printVector(result);
    cout << endl;
}

class Planet {
    private:
        string name;
        int satellites;
    public:
        Planet() : name(""), satellites(0) {}
        Planet(string name, int satellites) : name(name), satellites(satellites) {}

        friend ostream &operator<<(ostream& out, Planet planet) {
            out << "[" << planet.name << ", " << planet.satellites << "]";
            return out;
        }

        string getName() {
            return name;
        }
        int getSatellites() {
            return satellites;
        }
};

void task5() {
    cout << "Задание №5." << endl;
    vector<Planet> planets(9);
    planets[0] = Planet("Меркурий", 0);
    planets[1] = Planet("Венера", 0);
    planets[2] = Planet("Земля", 1);
    planets[3] = Planet("Марс", 2);
    planets[4] = Planet("Юпитер", 69);
    planets[5] = Planet("Сатурн", 62);
    planets[6] = Planet("Уран", 27);
    planets[7] = Planet("Нептун", 14);
    planets[8] = Planet("Плутон", 10);

    printVector(planets);

    int index = 0;
    int maxSatellites = 0;
    for (int i = 0; i < 9; ++i) {
        int satellites = planets[i].getSatellites();
        if (satellites > maxSatellites) {
            maxSatellites = satellites;
            index = i;
        }
    }

    cout << "Максимальное количество спутников у планеты " << planets[index].getName()
         << ": " << planets[index].getSatellites() << " спутников." << endl << endl;
}

void countPositive(const list<int> lst) {
    int count = 0;
    for (int i : lst) {
        if (i > 0) {
            ++count;
        }
    }
    cout << "Количество положительных элементов: " << count << endl << endl;
}

void task6() {
    cout << "Задание №6." << endl;
    list<int> numbers = { -5, 10, 0, 3, -2, 8, 7 };
    countPositive(numbers);
}

class Card {
    private:
        string title;   // заглавие книги
        string author;  // автор
        int number;     // количество имеющихся экземпляров
    public:
        Card() : title(""), author(""), number(0) {}
        Card(string t, string a, int n) : title(t), author(a), number(n) {}

        string getAuthor() {
            return author;
        }
        string getBook() {
            return title;
        }

        void print() {
            cout << "Книга: " << title << ", автор: " << author << ", количество: " << number << endl;
        }
};

void task7() {
    cout << "Задание №7." << endl;
    list<Card> library = {
        Card("Война и мир", "Лев Толстой", 5),
        Card("Преступление и наказание", "Федор Достоевский", 3),
        Card("Анна Каренина", "Лев Толстой", 2),
        Card("Идиот", "Федор Достоевский", 4),
        Card("Мертвые души", "Николай Гоголь", 1)
    };

    cout << "Список книг: " << endl;
    for (auto i : library) {
        i.print();
    }
    cout << endl;

    string author;
    cout << "Ввеите автора." << endl;
    getline(cin, author);

    bool found = false;
    int count = 0;
    for (auto i : library) {
        if (author == i.getAuthor()) {
            found = true;
            ++count;
        }
    }

    if (found) {
        cout << "Книги автора " << author << ": ";

        int newCount = 0;
        for (auto i : library) {
            if (author == i.getAuthor()) {
                ++newCount;
                cout << i.getBook() << (newCount < count ? ", " : ".\n\n");
            }
        }
    } else {
        cout << "У автора " << author << " нет книг в каталоге." << endl << endl;
    }
}

void task8() {
    cout << "Задание №8." << endl;
    map<int, double> myMap;
    for (int i = 1; i <= 9; ++i) {
        myMap[i] = i + i * 0.1;
    }

    cout << "Исходное отображение:" << endl;
    for (auto c : myMap) {
        cout << c.first << " - " << c.second << endl;
    }
    cout << endl;

    for (auto i = myMap.begin(); i != myMap.end(); ) {
        if (i->first % 2 == 0) {
            i = myMap.erase(i);
        } else {
            ++i;
        }
    }

    cout << "Отображение после удаления пар с чётными ключами:" << endl;
    for (auto c : myMap) {
        cout << c.first << " - " << c.second << endl;
    }
    cout << endl;
}

void task9() {
    cout << "Задание №9." << endl;
    map<string, string> myMap;
    myMap["5671234"] = "Ivanov";
    myMap["3214567"] = "Petrov";
    myMap["9871234"] = "Sidorov";

    string myArr[4] = {"1112233", "9871234", "5671234", "5556688"};

    cout << "Фамилии, соответствующие найденным номерам: " << endl;
    for (int i = 0; i < 4; ++i) {
        for (auto c : myMap) {
            if (myArr[i] == c.first) {
                cout << c.second << endl;
                break;
            }
        }
    }
}

int main() {
    // вариант 21
    task1();
    task2();
    task3();

    // вариант (21 % 10) + 1 = 2
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();

    return 0;
}
