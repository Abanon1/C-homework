#include <iostream>
#include <map>
#include <string>

using namespace std;

// Функция для конвертации из одной валюты в другую
double convert(double amount, const string& from, const string& to,
    const map<string, double>& rateToRUB) {
    // Сначала переведём amount из валюты “from” в рубли
    double inRub = amount * rateToRUB.at(from);
    // Затем из рублей в валюту “to”
    double result = inRub / rateToRUB.at(to);
    return result;
}

int main() {
    map<string, double> rateToRUB;
    rateToRUB["RUB"] = 1.0;        // рубль к рублю
    rateToRUB["USD"] = 90.0;      // 1 доллар = 90 рублей (пример)
    rateToRUB["EUR"] = 100.0;     // 1 евро = 100 рублей (пример)
    rateToRUB["CNY"] = 13.0;      // 1 юань = 13 рублей (пример)

    cout << "Hello this is calculator\n";
    cout << "The exchange rate is available : RUB, USD, EUR, CNY\n";

    double amount;
    string from, to;
    cout << "Put amount: ";
    cin >> amount;
    cout << "From? (RUB/USD/EUR/CNY): ";
    cin >> from;
    cout << "to? (RUB/USD/EUR/CNY): ";
    cin >> to;

    // Проверим, что введены валидные валюты
    if (rateToRUB.find(from) == rateToRUB.end() ||
        rateToRUB.find(to) == rateToRUB.end()) {
        cout << "Ошибка: введена неизвестная валюта.\n";
        return 1;
    }

    double converted = convert(amount, from, to, rateToRUB);
    cout << amount << " " << from << " = " << converted << " " << to << "\n";

    return 0;
}