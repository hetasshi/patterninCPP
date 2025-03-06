#include <iostream>

// абстрактные продукты
class Chair {
public:
    virtual void sit() = 0;
};

class Table {
public:
    virtual void use() = 0;
};

// конкретные продукты: Викторианский стиль, Зембабовский стиль (хз приудмал какой то)
class VictorianChair : public Chair {
public:
    void sit() override {
        std::cout << "Сидим на викторианском стуле йоу\n";
    }
};

class VictorianTable : public Table {
public:
    void use() override {
        std::cout << "Ставим чай на викторианский стол йоу\n";
    }
};

class ZembabovskiyChair : public Chair {
public:
    void sit() override {
        std::cout << "Сидим на зембабовском стульчике йоу\n";
    }
};

class ZembabovskiyTable : public Table {
public:
    void use() override {
        std::cout << "Ставим чай на зембабовский столик йоу\n";
    }

};


// абстрактная фабрика
class FurnitureFactory {
public:
    virtual Chair* createChair() = 0;
    virtual Table* createTable() = 0;
};

// конкретная фабрика
class VictorianFactory : public FurnitureFactory {
public:
    Chair* createChair() override {
        return new VictorianChair();
    }

    Table* createTable() override {
        return new VictorianTable();
    }
};

class ZembabovskyFactory : public FurnitureFactory {
public:
    Chair* createChair() override {
        return new ZembabovskiyChair();
    }

    Table* createTable() override {
        return new ZembabovskiyTable();
    }
};

// пример использования
int main() {
    setlocale(LC_ALL, "Rus");
    FurnitureFactory* factory = new VictorianFactory();
    Chair* chair = factory->createChair();
    Table* table = factory->createTable();

    FurnitureFactory* factory2 = new ZembabovskyFactory();
    Chair* chair2 = factory2->createChair();
    Table* table2 = factory2->createTable();

    chair->sit();   // Сидим на викторианском стуле
    table->use();   // Ставим чай на викторианский стол
    std::cout << "------------" << std::endl;
    chair2->sit(); // Сидим на зембабовском стульчике йоу
    table2->use(); // Ставим чай на зембабовский столик йоу

    delete chair;
    delete table;
    delete factory;

    delete chair2;
    delete table2;
    delete factory2;
    return 0;
}
