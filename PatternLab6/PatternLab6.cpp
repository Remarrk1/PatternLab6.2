#include <iostream>
#include <locale.h>
using namespace std;

// Абстрактный класс "Открытка"
struct PostCard {
    virtual void displayInfo() = 0;
};

// Конкретные классы открыток

// Новогодние открытки
struct NYCard : PostCard {
    void displayInfo() {
        cout << "Открытка на Новый Год" << endl;
    }
};

// Открытки на день рождения
struct BDCard : PostCard {
    void displayInfo() {
        cout << "Открытка на День Рождения" << endl;
    }
};

// Открытки на 8 марта
struct WomenDayCard : PostCard {
    void displayInfo() {
        cout << "Открытка на 8 марта" << endl;
    }
};

// Абстрактный класс "Подарок"
struct Present {
    virtual void displayInfo() = 0;
};

// Конкретные классы подарков

// Новогодние подарки
struct NYPresent : Present {
    void displayInfo() {
        cout << "Подарок на Новый Год" << endl;
    }
};

// Подарки на день рождения
struct BDPresent : Present {
    void displayInfo() {
        cout << "Подарок на День Рождения" << endl;
    }
};

// Подарки на 8 марта
struct WomenDayPresent : Present {
    void displayInfo() {
        cout << "Подарок на 8 марта" << endl;
    }
};

// Абстрактный класс "Торт"
struct Cake {
    virtual void displayInfo() = 0;
};

// Конкретные классы тортов

// Новогодний торт
struct NYCake : Cake {
    void displayInfo() {
        cout << "Новогодний торт" << endl;
    }
};

// Торт на день рождения
struct BDCake : Cake {
    void displayInfo() {
        cout << "Торт на День Рождения" << endl;
    }
};

// Абстрактная фабрика
struct AbstractFactory {
    virtual PostCard* createPostCard() = 0;
    virtual Present* createPresent() = 0;
    virtual Cake* createCake() = 0;
};

// Фабрика для создания новогодних продуктов
struct NYFactory : AbstractFactory {
    PostCard* createPostCard() {
        return new NYCard();
    }

    Present* createPresent() {
        return new NYPresent();
    }

    Cake* createCake() {
        return new NYCake();
    }
};

// Фабрика для создания продуктов на день рождения
struct BDFactory : AbstractFactory {
    PostCard* createPostCard() {
        return new BDCard();
    }

    Present* createPresent() {
        return new BDPresent();
    }

    Cake* createCake() {
        return new BDCake();
    }
};

// Фабрика для создания продуктов на 8 марта
struct WomenDayFactory : AbstractFactory {
    PostCard* createPostCard() {
        return new WomenDayCard();
    }

    Present* createPresent() {
        return new WomenDayPresent();
    }

    Cake* createCake() {
        // Возвращаем nullptr, т.к. на 8 марта нет специального торта
        return nullptr;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание новогодних продуктов
    AbstractFactory* nyFactory = new NYFactory();
    PostCard* nyCard = nyFactory->createPostCard();
    Present* nyPresent = nyFactory->createPresent();
    Cake* nyCake = nyFactory->createCake();

    nyCard->displayInfo();
    nyPresent->displayInfo();
    if (nyCake) {
        nyCake->displayInfo();
    }

    // Создание продуктов на день рождения
    AbstractFactory* bdFactory = new BDFactory();
    PostCard* bdCard = bdFactory->createPostCard();
    Present* bdPresent = bdFactory->createPresent();
    Cake* bdCake = bdFactory->createCake();

    bdCard->displayInfo();
    bdPresent->displayInfo();
    if (bdCake) {
        bdCake->displayInfo();
    }

    // Создание продуктов на 8 марта
    AbstractFactory* womenDayFactory = new WomenDayFactory();
    PostCard* womenDayCard = womenDayFactory->createPostCard();
    Present* womenDayPresent = womenDayFactory->createPresent();
    Cake* womenDayCake = womenDayFactory->createCake();

    womenDayCard->displayInfo();
    womenDayPresent->displayInfo();
    if (womenDayCake) {
        womenDayCake->displayInfo();
    }

    delete nyFactory;
    delete nyCard;
    delete nyPresent;
    delete nyCake;

    delete bdFactory;
    delete bdCard;
    delete bdPresent;
    delete bdCake;

    delete womenDayFactory;
    delete womenDayCard;
    delete womenDayPresent;
    delete womenDayCake;

    return 0;
}
