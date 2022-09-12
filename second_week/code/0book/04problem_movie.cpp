/*
    Задачи: Представлена структура Movie, описывающая фильм на Кинопоиске
            title - название фильма
            releaseYear - год выхода
            numVotes - число оценок этого фильма на Кинопоиске
            rating   - рейтинт фильма на Кинопоиске

        

        1)  Напишите метод setReleaseYear, который будет принимать число и устанавливать новый год выхода фильма, 
            равный этому числу. Этот метод не должен ничего возвращать.
            При этом, минимальный год выхода фильма должен быть 1900. При попытке установить меньший год выхода, метод
            всё-равно должен устанавливать год, равный 1900.

        2)  Установите год выхода фильма a на 1998, используя метод setReleaseYear. Напечатайте фильм.
            Попробуйте установить год выхода, равный 1600 Напечатайте фильм.


        3)  Напишите метод void addVote(float x), который будет имитировать проставление оценки x фильму одним пользователем
            numVotes должен увеличиться на 1 и rating должен тоже изменится по формуле

                новыйРейтинг = (старыйРейтиг * староеКоличествоГолосов + x) / (староеКоличествоГолосов + 1)

        4)  У данного фильма 4 голоса со средней оценкой 8.0. Добавьте ещё одну оценку, равную 10.0.
            Напечатайте фильм, новый рейтинг фильма должен быть равен 8.4.

*/

#include <iostream>
using std::cout;
using std::endl;


struct Movie 
{
    char title[100];
    int releaseYear;
    int numVotes;
    float rating;


    void print() const
    {
        cout << title << ", releaseYear = " << releaseYear << ", rating = " << rating 
             << " (" << numVotes << " votes)" << endl;  
    }

    void setReleaseYear(int new_year) {
        if (new_year < 1900) {
            releaseYear = 1900;
        } else {
            releaseYear = new_year;
        }
    }

    void addVote(float x) {
        numVotes++;
        rating = (rating * (numVotes - 1) + x) / (numVotes);
    }
};




int main() 
{
    Movie a = {"Dark City", 2000, 4, 8.0};
    a.addVote(10);
    a.setReleaseYear(1600);
    a.print();
    cout << endl;
}

// done