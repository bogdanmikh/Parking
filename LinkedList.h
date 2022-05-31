// Добавлять числа в конец pushBack
// Добавлять числа в начало pushFront
// Удалять числа под индексом erase
// Получить размер
// Получить число под индексом

template <typename T>
class Node {
public:
    T value;
    Node<T> *next;

    Node(T value) {
        this->value = value;
        this->next = nullptr;
    }
};

template <typename T>

class LinkedList {
private:
    int size = 0;
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;
public:
    void pushBack(T value) {
        if (first == nullptr) {
            first = new Node<T>(value);
            last = first;
            size++;
            return;
        }
        last->next = new Node<T>(value);
        last = last->next;
        size++;
    }

    void pushFront(T value) {
        if(first == nullptr) {
            first = new Node<T>(value);
            last = first;
            size++;
            return;
        }
        Node<T> *newItem = new Node<T>(value);
        newItem->next = first;
        first = newItem;
        size++;
    }

    void erase(int index) {
        Node<T> *current = first;
        for(int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        current->next = current->next->next;
        size--;
    }

    void sort() {}

    int getSize() const { return size; }

    T get(int index) const {
        Node<T> *current = first;
        for(int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }
};

