#include <iostream>

using namespace std;

template <typename T>
struct node {
    T val;
    struct node *prev;
    struct node *next;
};

template <typename T>
struct List {
    struct node<T> *head;
    struct node<T> *tail;
};

template <typename T>
struct node<T>* node_init(T v) {
    struct node<T> *n = (struct node<T>*)malloc(sizeof(struct node<T>));
    n->val = v;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

template <typename T>
void add_element(struct List<T> *l, T v) {
    struct node<T>* n = node_init(v);
    if (l->head == NULL) {
        l->head = n;
        l->tail = l->head;
        return;
    }
    n->prev = l->tail;
    l->tail->next = n;
    l->tail = n;
}

template <typename T>
void print_linked_list(struct List<T> *l) {
    struct node<T> *n = l->head;
    while(n != NULL) {
        if (n != l->head)
            cout << " -> ";
        cout << n->val;
        n = n->next;
    }
    cout << endl;
}

template <typename T>
void reverse_linked_list(struct List<T> *l) {
    cout << "Before reversing: ";
    print_linked_list(l);

    struct node<T> *n = l->tail;
    while (n != NULL) {
        struct node<T> *tmp = n->prev;
        n->prev = n->next;
        n->next = tmp;
        n = n->next;
    }
    n = l->tail;
    l->tail = l->head;
    l->head = n;

    cout << "After reversing:  ";
    print_linked_list(l);
}

int main() {
    int i;
    string s = "";
    struct List<int> *int_list = (struct List<int>*)malloc(sizeof(struct List<int>));
    struct List<char> *char_list = (struct List<char>*)malloc(sizeof(struct List<char>));
    struct List<float> *float_list = (struct List<float>*)malloc(sizeof(struct List<float>));
    struct List<string> *string_list = (struct List<string>*)malloc(sizeof(struct List<string>));
    for (i = 0; i < 5; i++) {
        s += "a";
        add_element(int_list, i);
        add_element(float_list, float(i + 0.5));
        add_element(char_list, char(65 + i));
        add_element(string_list, s);
    }
    print_linked_list(int_list);
    print_linked_list(char_list);
    print_linked_list(float_list);
    print_linked_list(string_list);

    cout << "-------------------------------------------\n";

    reverse_linked_list(int_list);
    reverse_linked_list(char_list);
    reverse_linked_list(float_list);
    reverse_linked_list(string_list);

    return 0;
}
