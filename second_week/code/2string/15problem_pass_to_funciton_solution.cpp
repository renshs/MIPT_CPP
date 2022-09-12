/*
    Решения:
    
    1)  В случае:

            void print(String s)
            {
                cout << s << endl;
            }

            int main() 
            {
                String a = "Cat";
                print(a);
            }

        Вызовутся следующие методы:

            1)  Конструктор строки из "Cat"
            

            2)  При передаче объекта в функцию по значению, он должен быть скопирован. 
                Соответственно при вызове  print(a)  объект a должен скопироваться в объект s функции print.
                Для обычных типов вроде int тут бы произошло побайтовое копирование, но для классов вызывается конструктор копирования.


            3)  Внутри функции print объект s печатается на экран. Затем мы выходим из функции print и уничтожаем все локальные объекты этой функции.
                Соответственно вызовется деструктор для объекта s.


            4)  Затем мы выходим из функции main и уничтожаем все объекты, локальные для функции main.
                Соответственно вызовется деструктор для объекта a.




    3)  В случае:

            void print(const String& s)
            {
                cout << s << endl;
            }

            int main() 
            {
                String a = "Cat";
                print(a);
            }

        Вызовутся следующие методы:

            1)  Конструктор строки из "Cat"
    
            
                При передаче объекта в функцию по ссылке, этот объект в функцию не копируется.
                Поэтому никаких конструкторов копирования не вызывается.


            2)  Деструктор для строки a из функии main.


        Получается, что обычно передавать объекты в функции более эффективно по ссылке, а не по значению.

*/