#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;

vector<long long> GenerateFibonacci(int n) {
    if (n <= 0) {
        throw invalid_argument("n dolzhno byt naturalnym chislom bolshe 0.");
    }
    vector<long long> fibonacci;
    fibonacci.push_back(0);
    if (n > 1) fibonacci.push_back(1);
    for (int i = 2; i < n; ++i) {
        fibonacci.push_back(fibonacci[i - 1] + fibonacci[i - 2]);
    }
    return fibonacci;
}

bool IsPalindrome(int num) {
    if (num < 0) {
        throw invalid_argument("Chislo dolzhno byt polozhitel'nym.");
    }
    string str = to_string(num);
    string reversed(str.rbegin(), str.rend());
    return str == reversed;
}

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* ReverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

void PrintList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void RunTests() {
    auto fib = GenerateFibonacci(10);
    assert(fib.size() == 10);
    assert(fib[0] == 0);
    assert(fib[1] == 1);
    assert(fib[9] == 34);

    assert(IsPalindrome(121) == true);
    assert(IsPalindrome(123) == false);
    assert(IsPalindrome(0) == true);

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    Node* reversedHead = ReverseLinkedList(head);

    assert(reversedHead->data == 3);
    assert(reversedHead->next->data == 2);
    assert(reversedHead->next->next->data == 1);

    delete reversedHead->next->next;
    delete reversedHead->next;
    delete reversedHead;

    cout << "Vse testy proideny uspeshno!\n";
}

int main() {
    try {
        cout << "Chisla Fibonacchi (pervye 10): ";
        auto fibonacci = GenerateFibonacci(10);
        for (auto num : fibonacci) {
            cout << num << " ";
        }
        cout << "\n";

        int num;
        cout << "Vvedite chislo dlya proverki na palindrom: ";
        cin >> num;
        cout << (IsPalindrome(num) ? "Chislo yavlyaetsya palindromom.\n" : "Chislo ne yavlyaetsya palindromom.\n");

        Node* head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(3);
        cout << "Original'nyi spisok: ";
        PrintList(head);

        Node* reversedHead = ReverseLinkedList(head);
        cout << "Razvernutyi spisok: ";
        PrintList(reversedHead);

        delete reversedHead->next->next;
        delete reversedHead->next;
        delete reversedHead;

        RunTests();

    } catch (const exception& ex) {
        cerr << "Oshibka: " << ex.what() << endl;
    }

    return 0;
}
