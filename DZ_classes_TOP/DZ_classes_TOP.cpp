#include <iostream>
#include <cstring>

class Drob {
private:
    int numerator1 = 0;
    int denominator1 = 1;
    int numerator2 = 0;
    int denominator2 = 1;

public:
    void showFoo() {
        std::cout << "Введите значение числителя 1: " << std::endl;
        std::cin >> numerator1;
        std::cout << "Введите значение знаменателя 1: " << std::endl;
        std::cin >> denominator1;
        std::cout << "Введите значение числителя 2: " << std::endl;
        std::cin >> numerator2;
        std::cout << "Введите значение знаменателя 2: " << std::endl;
        std::cin >> denominator2;
    }

    void sumFoo() {
        int num = numerator1 * denominator2 + denominator1 * numerator2;
        int denum = denominator1 * denominator2;
        int cell;
        if (num > denum) {
            cell = num / denum;
            num = num - denum;
        }
        if (num == denum) {
            cell = 1;

        }

        std::cout << "Сумма дробей равна: " << cell << '(' << num << '/' << denum << ')' << std::endl;
    }

    void difFoo() {
        int num = numerator1 * denominator2 - denominator1 * numerator2;
        int denum = denominator1 * denominator2;
        int cell;
        if (num > denum) {
            cell = num / denum;
            num = num - denum;
        }
        if (num == denum) {
            cell = 1;
        }
        if (denum == 0) {
            std::cout << "На ноль делить нельзя!" << std::endl;
        }

        std::cout << "Разница дробей равна: " << cell << '(' << num << '/' << denum << ')' << std::endl;
    }

    void multFoo() {
        int num = numerator1 * numerator2;
        int denum = denominator1 * denominator2;
        int cell;
        if (num > denum) {
            cell = num / denum;
            num = num - denum;
        }
        if (num == denum) {
            cell = 1;
        }

        std::cout << "Произведение дробей равна: " << cell << '(' << num << '/' << denum << ')' << std::endl;
    }

    void divFoo() {
        int num = numerator1 * denominator2;
        int denum = denominator1 * numerator2;
        int cell;
        if (num > denum) {
            cell = num / denum;
            num = num - denum;
        }
        if (num == denum) {
            cell = 1;
        }

        std::cout << "Деление дробей равно: " << cell << '(' << num << '/' << denum << ')' << std::endl;
    }

};

class Contact {
private:
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

public:
    // Constructor
    Contact(const char* name, const char* home, const char* work,
        const char* mobile, const char* info) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);

        homePhone = new char[strlen(home) + 1];
        strcpy(homePhone, home);

        workPhone = new char[strlen(work) + 1];
        strcpy(workPhone, work);

        mobilePhone = new char[strlen(mobile) + 1];
        strcpy(mobilePhone, mobile);

        additionalInfo = new char[strlen(info) + 1];
        strcpy(additionalInfo, info);
    }

    ~Contact() {
        delete[] fullName;
        delete[] homePhone;
        delete[] workPhone;
        delete[] mobilePhone;
        delete[] additionalInfo;
    }

    // Контактная информация
    void display() const {
        std::cout << "Full Name: " << fullName
            << ", Home Phone: " << homePhone
            << ", Work Phone: " << workPhone
            << ", Mobile Phone: " << mobilePhone
            << ", Additional Info: " << additionalInfo << std::endl;
    }

    // Функция сравнения для поиска по полному имени
    bool matches(const char* name) const {
        return strcmp(fullName, name) == 0;
    }
};

class PhoneBook {
private:
    Contact** contacts;
    int capacity;
    int size;

    void resize() {
        int newCapacity = capacity * 2;
        Contact** newContacts = new Contact * [newCapacity];
        for (int i = 0; i < size; ++i) {
            newContacts[i] = contacts[i];
        }
        delete[] contacts;
        contacts = newContacts;
        capacity = newCapacity;
    }

public:
    PhoneBook(int cap = 10) : capacity(cap), size(0) {
        contacts = new Contact * [capacity];
    }

    ~PhoneBook() {
        for (int i = 0; i < size; ++i) {
            delete contacts[i];
        }
        delete[] contacts;
    }

    // Создание нового контакта
    void addContact(const char* name, const char* home, const char* work,
        const char* mobile, const char* info) {
        if (size == capacity) {
            resize();
        }
        contacts[size++] = new Contact(name, home, work, mobile, info);
    }

    // Удаление контакта по полному имени
    void removeContact(const char* name) {
        for (int i = 0; i < size; ++i) {
            if (contacts[i]->matches(name)) {
                delete contacts[i]; // Free memory
                for (int j = i; j < size - 1; ++j) {
                    contacts[j] = contacts[j + 1]; // Shift elements
                }
                --size;
                std::cout << "Contact " << name << " removed." << std::endl;
                return;
            }
        }
        std::cout << "Contact with name " << name << " not found." << std::endl;
    }

    // Поиск контакта по полному имени
    void searchContact(const char* name) const {
        for (int i = 0; i < size; ++i) {
            if (contacts[i]->matches(name)) {
                contacts[i]->display();
                return;
            }
        }
        std::cout << "Contact with name " << name << " not found." << std::endl;
    }

    // Отобразить все контакты
    void displayAllContacts() const {
        if (size == 0) {
            std::cout << "Phone book is empty." << std::endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            contacts[i]->display();
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    /*
    Задание 1.
    Реализуйте класс Дробь. Необходимо хранить числитель
    и знаменатель в качестве переменных-членов. Реализуйте
    функции-члены для ввода данных в переменные-члены,
    для выполнения арифметических операций (сложение,
    вычитание, умножение, деление, и т.д.).
    */

    {
        Drob drob;
        //int a1, b1, a2, b2;
        drob.showFoo();
        drob.sumFoo();
        drob.difFoo();
        drob.multFoo();
        drob.divFoo();
    }

    /*Создайте приложение «Телефонная книга». Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего класса.
Наполните класс переменными-членами, функциями-
членами, конструкторами, inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память под
ФИО. Предоставьте пользователю возможность добавлять
новых абонентов, удалять абонентов, искать абонентов
по ФИО, показывать всех абонентов*/
    {
PhoneBook phoneBook;

    phoneBook.addContact("Ivanov Ivan Ivanovich", "123456", "654321", "987654321", "Friend");

    phoneBook.addContact("Petrov Petr Petrovich", "234567", "765432", "876543210", "Colleague");

    std::cout << "All contacts in the phone book:" << std::endl;
    phoneBook.displayAllContacts();


    std::cout << "\nSearching for contact 'Ivanov Ivan Ivanovich':" << std::endl;
    phoneBook.searchContact("Ivanov Ivan Ivanovich");


    std::cout << "\nRemoving contact 'Ivanov Ivan Ivanovich':" << std::endl;
    phoneBook.removeContact("Ivanov Ivan Ivanovich");


    std::cout << "\nAll contacts in the phone book after removal:" << std::endl;
    phoneBook.displayAllContacts();
    }
    

    return 0;
}