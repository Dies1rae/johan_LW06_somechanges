#include <iostream>
#include <string>
#include <clocale>
#include <algorithm>
#include <cstring>

using namespace std;

//s3ns3_n3t
std::string ReadLine() {
    std::string s;
    std::getline(std::cin, s);
    return s;
}
int ReadLineWithNumber() {
    int result;
    std::cin >> result;
    ReadLine();
    return result;
}

/* Очистка командной строки через встроенный метод CLS */
void ClearCmdLog(void) {
    system("cls");
}

/* Отключение синхронизации потоков вывода/ввода ЯП С от потоков вывода/ввода ЯП С++ */ 
auto tied_before = cin.tie();;
void IOSpeedBoost_ON(void) {
    //ios_base::sync_with_stdio(false); //To hard
    tied_before = cin.tie(nullptr);
}
void IOSpeedBoost_OFF(void) {
    //ios_base::sync_with_stdio(false); //To hard
    cin.tie(tied_before);
}


/* Задание #3:
Дана строка. Подсчитать количество содержащихся в ней прописных букв. */
int CountTheCapitalLetters(const std::string &str) {
    return count_if(str.begin(), str.end(), [](const char& A) {
        if (A >= 'A' && A <= 'Z') {
            return 1;
        }
        return 0;
        });
}

/* Задание #2:
Дана строка-предложение.
Преобразовать строку так, чтобы каждое слово начиналосьс заглавной буквы. */
std::string CapitalizeTheFirstLetter(std::string& str) {
    str[0] = toupper(str[0]);
    for (size_t i = 1; i < str.size(); ++i) { // better not do this like i == 0 and i - 1 in same one)))
        if ((i == 0) or (str[i - 1] == ' ')) {
            str[i] = toupper(str[i]);
        }
    }
    return (str);
}

/* Задание #1:
Даны две строки: S1 и S2.
Определить количество вхождений строки S2 в строку S1. */
int NumberOfOccurrencesOfASubstringPerstring(const std::string& src_string, const std::string& sub_string) {
    int occurrences_counter = 0;
    const char* tmp_str = src_string.c_str();
    while (tmp_str = strstr(tmp_str, sub_string.c_str())) {
        occurrences_counter++;
        tmp_str++;
    }
    return occurrences_counter;
}

/* Init. function for all of my tasks */
bool Initialization(void) {
    std::cout << "Select a task to check:\n";
    size_t ptr = 0;
    for (; ptr < 4; ++ptr) {
        std::cout << (ptr) << ". " << "Task #" << (ptr) << '\n';
    }
    while (ptr) {
        std::cout << "Your choice is: ";
        int choice = ReadLineWithNumber();
        if (choice == 1) {
            ClearCmdLog();
            /* Условия задачи: */
            std::cout << "Task #1:\nTwo lines are given : S1 and S2.\nDetermine the number of occurrences of std::string S2 in std::string S1.\n";
            /* Реализация (решение) поставленной задачи: */
            std::cout << "\nImplementation of the task:\n";
            std::string src_string, sub_string;
            std::cout << "Enter your a src std::string: ";
            src_string = ReadLine();
            std::cout << "Enter your a sub std::string: ";
            sub_string = ReadLine();
            std::cout << "Occurrences of a substd::string per source std::string: " << NumberOfOccurrencesOfASubstringPerstring(src_string, sub_string) << " time(-s)\n";
            std::cout << "Press 'F' to pay respect..." << std::endl;
            system("PAUSE");
            return true;
        } else if (choice == 2) {
            ClearCmdLog();
            /* Условия задачи: */
            std::cout << "Task #2:\nA sentence std::string is given.\nConvert the std::string so that each word starts with a capital letter.\n";
            /* Реализация (решение) поставленной задачи: */
            std::cout << "\nImplementation of the task:\n";
            std::cout << "Enter a your std::string: ";
            std::string str; //never in one std::string
            str = ReadLine();
            std::cout << "This is your std::string before all the manipulations: " << str << '\n';
            std::cout << "This is your std::string after all the manipulations: " << CapitalizeTheFirstLetter(str) << '\n';
            std::cout << "Press 'F' to pay respect..." << std::endl;
            system("PAUSE");
            return true;
        } else if (choice == 3) {
            ClearCmdLog();
            /* Условия задачи: */
            std::cout << "Task #3:\nGiven a std::string. Count the number of uppercase letters it contains.\n";
            /* Реализация (решение) поставленной задачи: */
            std::cout << "\nImplementation of the task:\n";
            std::cout << "Enter a your std::string: ";
            std::string str;
            str = ReadLine();
            std::cout << "The number of capital letters in your std::string is: " << CountTheCapitalLetters(str) << '\n';
            std::cout << "Press 'F' to pay respect..." << std::endl;
            system("PAUSE");
            return true;
        } else if (choice == 0) {
            return false;
        } else {
            cerr << "Wrong choice! Try it again!\a\n";
        }
    }
}

/* Entry point */
int main() {
    IOSpeedBoost_ON();

    bool main_loop = Initialization();
    while (main_loop) {
        ClearCmdLog();
        main_loop = Initialization();
    }
    ClearCmdLog();
    std::cout << "Thank you for using my app!\nSee you later!" << std::endl;

    IOSpeedBoost_OFF();
    return 0;
}

//убрал немножк мусор, почистил функции и кодстиль, кое что переделал
//по хорошему еще надо добавить сюда проверки на не 0 строки(зациклить пустой ввод) в каждом методе
//а вообще красава