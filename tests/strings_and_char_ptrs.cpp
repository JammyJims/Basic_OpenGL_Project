#include <iostream>
#include <string>

// this function prints the entire string that has been null terminated
void print(const char *str) {
    using namespace std;
    // copy the ptr
    const char *ptr = str;
    while (*ptr != '\0') {
        cout << *ptr;
        ptr++;
    }
    return;
}
int main() {
    using namespace std;
    const char *string1 =   "hello world\n"
                            "This is another line of code\n"
                            "int main() { \n"
                            "   some code\n"
                            "}\n";
    string some_string = "this is a datastructure of type string";
    string string3 = "abc\n"
                     "def\n"
                     "ghi\n"
                     "jkl\n";

    const char *string4 =   "can I actually dereference a const char ptr?\n"
                            "also would be nice if I can find the size or\n"
                            "number of characters as well.\n" ;
    cout << string1 << endl;
    cout << some_string << endl;
    cout << string3 << endl;
    cout << string4 << endl;
    cout << "6th string element is = " << *(string4 + 6) << endl;
    cout << "6th string element is = " << string4[6] << endl;
    cout << "below is string1:" << endl;
    print (string1);
}