#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "planetLib/planetLib.h"
#include "roadLib/roadLib.h"

//Реализация класса Planet полностью работает, но закомментирована для работы класса Road
/*
int menu(); //меню
int read_dbase(char *filename, Planet*& arr, int& n); //чтение БД из файла
int write_dbase(char *filename, Planet*& arr, int n); //запись БД в файл
void sort_dbase(Planet*& arr, int n); //сортировка БД
int add(Planet*& arr, int& n); //добавление нового объекта в БД
int remove(Planet*& arr, int& n); //удаление объекта из БД
int edit(Planet*& arr, int n); //редактирование БД
void print_dbase(Planet* arr, int n); //вывод БД на экран

int main() {
    setlocale(LC_ALL, "Russian");

    // Planet Z;
    // Z.setName("mars");
    // Z.setD(4878);        //создание объекта класса Planet
    // Z.setLife(true);     //и его вывод на экран
    // Z.setS(2);
    // Z.show();

    int n = 100;
    Planet* arr = new Planet[n];
    char filename[] = "/home/ugryum/labs2sem/lab2/dbase.txt";
    //чтение БД в ОП
    if (read_dbase(filename, arr, n)) {
        cout << "Ошибка чтения БД.\n" << endl;
        return 1;
    }
    print_dbase(arr, n);

    while (true) {
        switch (menu()) {
            case 1:
                read_dbase(filename, arr, n);
                break;
            case 2:
                write_dbase(filename, arr, n);
                break;
            case 3:
                sort_dbase(arr, n);
                break;
            case 4:
                add(arr, n);
                break;
            case 5:
                remove(arr, n);
                break;
            case 6:
                edit(arr, n);
                break;
            case 7:
                print_dbase(arr, n);
                break;
            case 8:
                delete[] arr;
                return 0;
            default:
                cout << " Недопустимый номер операции.\n" << endl;
                break;
        }
    }
    delete[] arr;
    return 0;
}

int menu() {
    cout << "===============ГЛАВНОЕ МЕНЮ===============" << endl;
    cout << "\tl - чтение БД из файла" << endl;
    cout << "\t2 - запись БД в файл" << endl;
    cout << "\t3 - сортировка БД" << endl;
    cout << "\t4 - добавление нового объекта в БД" << endl;
    cout << "\t5 - удаление объекта из БД" << endl;
    cout << "\t6 - редактирование БД" << endl;
    cout << "\t7 - вывод БД на экран" << endl;
    cout << "\t8 - выход" << endl;
    cout << "Для выбора операции введите цифру от 1 до 8." << endl;
    int resp;
    cin >> resp;
    cin.clear();
    cin.ignore(10, '\n');
    return resp;
}

int read_dbase(char *filename, Planet*& arr, int &n) {
    ifstream fin(filename, ios::in);
    if (!fin) {
        cout << "Heт файла " << filename << endl << endl;
        return 1;
    }
    fin >> n;
    if (n > 100) {
        cout << "Переполнение БД. n= " << n << endl << endl;
        return 1;
    }

    delete[] arr;
    arr = new Planet[n];

    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }

    fin.close();

    cout << "База данных считана с файла.\n" << endl;
    return 0;
}

int write_dbase(char *filename, Planet*& arr, int n) {
    ofstream fout(filename, ios::out);
    if (!fout) {
        cout << "Ошибка открытия файла" << endl << endl;
        return 1;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << arr[i] << endl;
    }
    fout.close();

    cout << "База данных записана в файл.\n" << endl;
    return 0;
}

void sort_dbase(Planet*& arr, int n) {
    Planet temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!(arr[j] < arr[j + 1] || arr[j] == arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "База данных отсортирована.\n" << endl;
}

int add(Planet*& arr, int& n) {
    if (n >= 100) {
        cout << "Переполнение БД. n= " << n << endl << endl;
        return 1;
    }

    Planet* newArr = new Planet[n + 1];

    for (int i = 0; i < n; ++i) {
        newArr[i].setName(arr[i].getName());
        newArr[i].setD(arr[i].getD());
        newArr[i].setLife(arr[i].getLife());
        newArr[i].setS(arr[i].getS());
    }

    char name[30];
    int d, s;
    bool life;
    cout << "Введите название планеты." << endl;
    cin >> name;
    cout << "Введите диаметр планеты." << endl;
    cin >> d;
    cout << "Введите наличие жизни на планете." << endl;
    cin >> life;
    cout << "Введите количество спутников планеты." << endl;
    cin >> s;

    newArr[n].setName(name);
    newArr[n].setD(d);
    newArr[n].setLife(life);
    newArr[n].setS(s);

    delete[] arr;

    arr = newArr;
    ++n;

    cout << "Элемент добавлен в базу данных.\n" << endl;
    return 0;
}

int remove(Planet*& arr, int& n) {
    cout << "Введите номер элемента, который хотите удалить." << endl;
    int k;
    cin >> k;

    if (k > n || k < 1) {
        cout << "Элемента с таким номером не существует.\n" << endl;
        return 1;
    }
    --k;

    Planet* newArr = new Planet[n - 1];

    for (int i = 0; i < n; ++i) {
        if (i < k) {
            newArr[i].setName(arr[i].getName());
            newArr[i].setD(arr[i].getD());
            newArr[i].setLife(arr[i].getLife());
            newArr[i].setS(arr[i].getS());
        } else if (i > k) {
            newArr[i - 1].setName(arr[i].getName());
            newArr[i - 1].setD(arr[i].getD());
            newArr[i - 1].setLife(arr[i].getLife());
            newArr[i - 1].setS(arr[i].getS());
        }
    }

    delete[] arr;

    arr = newArr;
    --n;

    cout << "Элемент удалён из базы данных.\n" << endl;
    return 0;
}

int edit(Planet*& arr, int n) {
    cout << "Введите номер элемента, который хотите отредактировать." << endl;
    int k;
    cin >> k;

    if (k > n || k < 1) {
        cout << "Элемента с таким номером не существует.\n" << endl;
        return 1;
    }
    --k;

    cout << "Какой параметр хотите изменить? Введите цифру от 1 до 4.\n\t1. Название планеты\n\t2. Диаметр планеты\n\t3. "
            "Наличие жизни на планете\n\t4. Количество спутников планеты" << endl;
    int m;
    cin >> m;
    cout << "Введиет новое значение." << endl;

    switch(m) {
        case 1:
            char name[30];
            cin >> name;
            arr[k].setName(name);
            break;
        case 2:
            int d;
            cin >> d;
            arr[k].setD(d);
            break;
        case 3:
            bool life;
            cin >> life;
            arr[k].setLife(life);
            break;
        case 4:
            int s;
            cin >> s;
            arr[k].setS(s);
            break;
        default:
            cout << "Неверный ввод.\n" << endl;
            return 1;
    }

    cout << "База данных отредактирована.\n" << endl;
    return 0;
}

void print_dbase(Planet* arr, int n) {
    cout << "База Данных: " << endl;
    cout << left << setw(15) << "Planet name"
         << setw(15) << "Diameter"
         << setw(15) << "Life"
         << setw(15) << "Satellites" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << arr[i].getName()
             << setw(15) << arr[i].getD()
             << setw(15) << arr[i].getLife()
             << setw(15) << arr[i].getS() << endl;
    }
    cout << endl;
}
*/

int menu(); //меню
int read_dbase(char *filename, Road*& arr, int& n); //чтение БД из файла
int write_dbase(char *filename, Road*& arr, int n); //запись БД в файл
void sort_dbase(Road*& arr, int n); //сортировка БД
int add(Road*& arr, int& n); //добавление нового объекта в БД
int remove(Road*& arr, int& n); //удаление объекта из БД
int edit(Road*& arr, int n); //редактирование БД
void print_dbase(Road* arr, int n); //вывод БД на экран

int main() {
    setlocale(LC_ALL, "Russian");

    int n = 100;
    Road* arr = new Road[n];
    char filename[] = "/home/ugryum/labs2sem/lab2/road_dbase.txt";
    //чтение БД в ОП
    if (read_dbase(filename, arr, n)) {
        cout << "Ошибка чтения БД.\n" << endl;
        return 1;
    }
    print_dbase(arr, n);

    while (true) {
        switch (menu()) {
            case 1:
                read_dbase(filename, arr, n);
                break;
            case 2:
                write_dbase(filename, arr, n);
                break;
            case 3:
                sort_dbase(arr, n);
                break;
            case 4:
                add(arr, n);
                break;
            case 5:
                remove(arr, n);
                break;
            case 6:
                edit(arr, n);
                break;
            case 7:
                print_dbase(arr, n);
                break;
            case 8:
                delete[] arr;
                return 0;
            default:
                cout << " Недопустимый номер операции.\n" << endl;
                break;
        }
    }
    delete[] arr;
    return 0;
}

int menu() {
    cout << "===============ГЛАВНОЕ МЕНЮ===============" << endl;
    cout << "\tl - чтение БД из файла" << endl;
    cout << "\t2 - запись БД в файл" << endl;
    cout << "\t3 - сортировка БД" << endl;
    cout << "\t4 - добавление нового объекта в БД" << endl;
    cout << "\t5 - удаление объекта из БД" << endl;
    cout << "\t6 - редактирование БД" << endl;
    cout << "\t7 - вывод БД на экран" << endl;
    cout << "\t8 - выход" << endl;
    cout << "Для выбора операции введите цифру от 1 до 8." << endl;
    int resp;
    cin >> resp;
    cin.clear();
    cin.ignore(10, '\n');
    return resp;
}

int read_dbase(char *filename, Road*& arr, int &n) {
    ifstream fin(filename, ios::in);
    if (!fin) {
        cout << "Heт файла " << filename << endl << endl;
        return 1;
    }
    fin >> n;
    if (n > 100) {
        cout << "Переполнение БД. n= " << n << endl << endl;
        return 1;
    }

    delete[] arr;
    arr = new Road[n];

    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }

    fin.close();

    cout << "База данных считана с файла.\n" << endl;
    return 0;
}

int write_dbase(char *filename, Road*& arr, int n) {
    ofstream fout(filename, ios::out);
    if (!fout) {
        cout << "Ошибка открытия файла.\n" << endl;
        return 1;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << arr[i] << endl;
    }
    fout.close();

    cout << "База данных записана в файл.\n" << endl;
    return 0;
}

void sort_dbase(Road*& arr, int n) {
    Road temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!(arr[j] < arr[j + 1] || arr[j] == arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "База данных отсортирована.\n" << endl;
}

int add(Road*& arr, int& n) {
    if (n >= 100) {
        cout << "Переполнение БД. n= " << n << endl << endl;;
        return 1;
    }

    Road* newArr = new Road[n + 1];

    for (int i = 0; i < n; ++i) {
        newArr[i].setName(arr[i].getName());
        newArr[i].setLength(arr[i].getLength());
        newArr[i].setDir(arr[i].getDir());
        newArr[i].setStripes(arr[i].getStripes());
    }

    char name[30];
    int length, stripes;
    bool dir;
    cout << "Введите название дороги." << endl;
    cin >> name;
    cout << "Введите продолжительность дороги." << endl;
    cin >> length;
    cout << "Имеет ли дорога направление (true, если не кольцевая)." << endl;
    cin >> dir;
    cout << "Введите среднее количество полос на дороге." << endl;
    cin >> stripes;

    newArr[n].setName(name);
    newArr[n].setLength(length);
    newArr[n].setDir(dir);
    newArr[n].setStripes(stripes);

    delete[] arr;

    arr = newArr;
    ++n;

    cout << "Элемент добавлен в базу данных.\n" << endl;
    return 0;
}

int remove(Road*& arr, int& n) {
    cout << "Введите номер элемента, который хотите удалить." << endl;
    int k;
    cin >> k;

    if (k > n || k < 1) {
        cout << "Элемента с таким номером не существует.\n" << endl;
        return 1;
    }
    --k;

    Road* newArr = new Road[n - 1];

    for (int i = 0; i < n; ++i) {
        if (i < k) {
            newArr[i].setName(arr[i].getName());
            newArr[i].setLength(arr[i].getLength());
            newArr[i].setDir(arr[i].getDir());
            newArr[i].setStripes(arr[i].getStripes());
        } else if (i > k) {
            newArr[i - 1].setName(arr[i].getName());
            newArr[i - 1].setLength(arr[i].getLength());
            newArr[i - 1].setDir(arr[i].getDir());
            newArr[i - 1].setStripes(arr[i].getStripes());
        }
    }

    delete[] arr;

    arr = newArr;
    --n;

    cout << "Элемент удалён из базы данных.\n" << endl;
    return 0;
}

int edit(Road*& arr, int n) {
    cout << "Введите номер элемента, который хотите отредактировать." << endl;
    int k;
    cin >> k;

    if (k > n || k < 1) {
        cout << "Элемента с таким номером не существует.\n" << endl;
        return 1;
    }
    --k;

    cout << "Какой параметр хотите изменить? Введите цифру от 1 до 4.\n\t1. Название дороги\n\t2. Протяжённость дороги\n\t3. "
            "Направление дороги\n\t4. Среднее количество полос дороги" << endl;
    int m;
    cin >> m;
    cout << "Введите новое значение." << endl;

    switch(m) {
        case 1:
            char name[30];
            cin >> name;
            arr[k].setName(name);
            break;
        case 2:
            int length;
            cin >> length;
            arr[k].setLength(length);
            break;
        case 3:
            bool dir;
            cin >> dir;
            arr[k].setDir(dir);
            break;
        case 4:
            int stripes;
            cin >> stripes;
            arr[k].setStripes(stripes);
            break;
        default:
            cout << "Неверный ввод.\n" << endl;
            return 1;
    }

    cout << "База данных отредактирована.\n" << endl;
    return 0;
}

void print_dbase(Road* arr, int n) {
    cout << "База Данных: " << endl;
    cout << left << setw(15) << "Road name"
         << setw(15) << "Length"
         << setw(15) << "Dirrection"
         << setw(15) << "Stripes" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << arr[i].getName()
             << setw(15) << arr[i].getLength()
             << setw(15) << arr[i].getDir()
             << setw(15) << arr[i].getStripes() << endl;
    }
    cout << endl;
}
