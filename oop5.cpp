#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Book {
public:
    Book(string title, string author, int year, int id) : title(title), author(author), year(year), id(id) {}

    void displayInfo() const {
        cout << "ID: " << id << ", Книга: " << title << ", Автор: " << author << ", Рiк: " << year << endl;
    }

    // Оператор порівняння за назвою книги
    bool operator<(const Book& other) const {
        return title < other.title;
    }

    // Функція для редагування інформації про книгу
    void editBook() {
        cout << "Введiть нову назву книги: ";
        cin.ignore();
        getline(cin, title);
        cout << "Введiть нового автора: ";
        getline(cin, author);
        cout << "Введiть новий рiк: ";
        cin >> year;
    }

    int getId() const {
        return id;
    }

private:
    int id;
    string title;
    string author;
    int year;
};

int main() {
    setlocale(LC_ALL, "ukr");
    vector<Book> library;
    library.push_back(Book("To Kill a Mockingbird", "Harper Lee", 1960, 1));
    library.push_back(Book("1984", "George Orwell", 1949, 2));
    library.push_back(Book("The Catcher in the Rye", "J.D. Salinger", 1951, 3));

    char num;
    while (true) {
        cout << "1.Вiдобразити iнформацiю про книги\n";
        cout << "2.Сортування за назвою\n";
        cout << "3.Редагувати книгу\n";
        cout << "4.Видалити книгу\n";
        cout << "5.Вихiд\n";

        cin >> num;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Сброс символа новой строки

        switch (num) {
        case '1':
            cout << "Iнформацiя про книги в бiблiотецi:" << endl;
            for (const auto& book : library) {
                book.displayInfo();
            }
            break;

        case '2':
            // Використовуємо std::sort для сортування за назвою книги
            sort(library.begin(), library.end());

            cout << "\nБiблiотека пiсля сортування за назвою книги:" << endl;
            for (const auto& book : library) {
                book.displayInfo();
            }
            break;

        case '3':
            int editId;
            cout << "Введiть ID книги для редагування: ";
            cin >> editId;

            for (auto& book : library) {
                if (editId == book.getId()) {
                    book.editBook();
                    cout << "Iнформацiя про книгу вiдредагована успiшно.\n";
                    break;
                }
            }
            break;

        case '4':
            cout << "error :(\n";
            break;

        case '5':
            cout << "Закриття програми\n";
            return 0;

        default:
            cout << "Невiрний вибiр. Введiть правильну цифру.\n";
            break;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    setlocale(LC_ALL, "ukr");
    std::vector<string> favoriteFruits;

    cout << "Ласкаво просимо до гри 'Сортування фруктів'!" << endl;
    cout << "Введіть свої улюблені фрукти (введіть '0', щоб завершити введення):" << endl;

    std::string fruit;
    while (true) {
        cout << "Фрукт: ";
        cin >> fruit;

        if (fruit == "0") {
            break;
        }
        favoriteFruits.push_back(fruit);
    }
    int prov;
    cout << "Сортувати по зростанню, чи зменшенню алфавіту? 1 - зростання, 2 - зменшення: ";
    cin >> prov;
    sort(favoriteFruits.begin(), favoriteFruits.end());
    if (prov == 2) {
        reverse(favoriteFruits.begin(), favoriteFruits.end());
    }
    cout << "\nВаші улюблені фрукти в алфавітному порядку:" << endl;
    for (const auto& favoriteFruit : favoriteFruits) {
        cout << favoriteFruit << std::endl;
    }

    cout << "Гра завершена. Дякуємо за участь!" << endl;
    return 0;
}

#include <iostream>
#include <list>
#include <string>
#include <iomanip>
using namespace std;
class Joke {
public:
    Joke(string text) : text(text), votes(0), totalRating(0) {}

    void tellJoke() const {
        cout << "Жарт: " << text << std::endl;
        cout << "Оцінка: " << std::fixed << std::setprecision(2) << getAverageRating() << " (Голосів: " << votes << ")" << endl;
    }
    void rateJoke(int rating) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
        }
        else {
            cout << "Оцінка повинна бути від 1 до 5!" << endl;}}
    double getAverageRating() const {
        return (votes > 0) ? static_cast<double>(totalRating) / votes : 0.0;
    }
private:
    string text;
    int votes;
    int totalRating;
};

int main() {
    setlocale(LC_ALL, "ukr");
    std::list<Joke> jokeList;
    int players;
    cout << "Введіть кількість гравців: ";
    cin >> players;
    jokeList.push_back(Joke("Чому програмісти так погано сплять? Тому що вони давно звикли до багів!"));
    jokeList.push_back(Joke("Нікого робота програми не дивує так часто, як її творця!"));
    jokeList.push_back(Joke("Що робить програміст після розставання? Переходить на інший репозиторій!"));
    jokeList.push_back(Joke("Є два способи писати безпомилкові комп’ютерні програми. І лише третій — правильний."));

    cout << "Ласкаво просимо до програми для оцінювання жартів!" << endl;
    for (int i = 1; i < players + 1; i++) {
        cout << "Гравець " << i << " оцініть жарти" << endl;
        for (auto& joke : jokeList) {
            joke.tellJoke();

            int userRating;
            cout << "Ваша оцінка (1-5): ";
            cin >> userRating;

            joke.rateJoke(userRating);
        }
    }

    cout << "\nЖарти з високим рейтингом:" << endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        }
    }

    return 0;
}
#include <iostream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");

    std::map<std::string, double> studentGrades;
    vector<string> search1;
    vector<double> search2;

    studentGrades["Ann"] = 4.5;
    studentGrades["Borys"] = 3.8;
    studentGrades["Catrine"] = 4.2;
    studentGrades["Dmytro"] = 4.0;

    std::cout << "Інформація про студентів:" << std::endl;
    for (const auto& student : studentGrades) {
        std::cout << student.first << ": " << student.second << std::endl;
    }
    while (true) {
        std::string searchStudent;
        std::cout << "\nВведіть ім'я студента для пошуку середнього балу, введіть 0 для виходу: ";
        std::cin >> searchStudent;
        search1.push_back(searchStudent);
        auto it = studentGrades.find(searchStudent);
        if (searchStudent == "0") {
            break;
        }
        if (it != studentGrades.end()) {
            std::cout << "Середній бал студента " << searchStudent << ": " << it->second << std::endl;
            search2.push_back(it->second);
        }
        else {
            std::cout << "Студент з іменем " << searchStudent << " не знайдений." << std::endl;
            search2.push_back(NULL);
        }
    }
    for (int i = 0; i < search1.size() - 1; i++) {
        cout << "Запит: " << search1[i] << " Результат: ";
        if (search2[i] != NULL) {
            cout << search2[i];
        }
        else {
            cout << "жодного";
        }
        cout << endl;
    }
    return 0;
}
