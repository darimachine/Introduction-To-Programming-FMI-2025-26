#include <iostream>
#include <string>
using namespace std;

// https://en.cppreference.com/w/cpp/string/basic_string.html

int main() {
    // string "опакова"(wrap-ва) char* в себе си и
    // предлага готови функции за много по-лесна
    // работа със символни низове(и по-лесно
    // управление на динамична памет)

    // начини за създаване
    string s = "abc";
    string s1("abc");
    string s2 = s;
    string s3 = string(s);
    string s4 = string("a");
    string s5 = "";

    cout << s.at(1) << endl; // връща символа на индекс 1
    cout << s[1] << endl; // същото (operator overloading / предефиниране на оператори)
    // още примери за operator overloading
    cout << s + s4 << endl; // + конкатенира два стринга
    cout << (s4 += "768") << endl;

    // лексикографско сравнение на стрингове
    // ==  !=  <  >  <=  >=
    cout << (s1 == s2) << " " << (s5 == "string") << " " << (s != s3) << endl;
    cout << (s < s4) << " " << (s >= s2) << endl;

    cout << s.empty() << endl;
    // size - размер на char масива(с '\0'), length - дължина на стринга(без '\0')
    cout << s.size() << " != " << s.length() << endl;

    cout << s.erase(1).erase(1) << endl; // премахва символа на индекс 1
    s.clear(); // изчиства низа
    cout << s << endl;

    // append добавя аргумента си към края на стринга,
    // който го е извикал, и може да се chain-ва
    cout << s.append("a").append(string("bc")) << endl;
    s.push_back('d');
    cout << s << endl;
    s.pop_back();
    cout << s << endl;

    string swap1 = "str1", swap2 = "str2";
    cout << swap1 << " " << swap2 << endl;
    swap(swap1, swap2);
    cout << swap1 << " " << swap2 << endl;

    s = "aabbvdfsa";
    cout << s.find('a') << endl; // връша индекса на първото срещане
    cout << s.rfind('a') << endl; // връща индекса на последното срещане
    cout << s.find('z') << endl;

    // ""s -> s в края указва, че този литерал е от тип string
    cout << "Emil Trifonov"s.compare("Serhan Chavdarliev") << endl;
    cout << "Aleksandur Aleksandrov"s.starts_with("Aleks") << endl;
    cout << "Chovek Chovekov"s.ends_with("va") << endl;
    cout << "ABCDEFG"s.contains("ABCDe") << endl;
    cout << "String s dumi"s.substr(0, 7) << endl;

    cout << s.c_str() << endl; // връща указателя(като константен), който сочи към char масива, пазещ самия низ

    string toread;
    cin >> toread; // cin чете с разделители ' ' и '\n'
    cout << toread << endl;
    getline(cin, toread); // getline чете само с разделител '\n'
    cout << toread << endl;
    getline(cin, toread, '0'); // може и експлицитно да се зададе какъв да е разделителят
    cout << toread << endl;

    // операции с числа
    string num = "-11111111.345423";
    cout << "Signed int: " << stoi(num) << endl;
    cout << "Signed long: " << stol(num) << endl;
    cout << "Signed long long: " << stoll(num) << endl;
    cout << "Unsigned long: " << stoul(num) << endl;
    cout << "Unsigned long long: " << stoull(num) << endl;
    cout << "Float: " << stof(num) << endl;
    cout << "Double: " << stod(num) << endl;

    try {
        string badnum = "a123";
        cout << stoi(badnum) << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    int number = 1;
    string numberToString = to_string(number);
    cout << numberToString << endl;
}

// във функцията се работи с копие на подадения низ
// подходящо, когато искаме да създадем модифицирано
// копие на низа, с който работим
void passByCopy(string s) { /*...*/ }

// стрингът се подава по референция и промените във
// функцията ще му се отразят
// подходящо, когато искаме да променим стринга,
// с който работим
void passByRef(string& s) { /*...*/ }

// стрингът се подава по константа референция
// подходящо, когато изобщо не искаме да го променяме
void passByConstRef(const string& s) { /*...*/ }