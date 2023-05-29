template <typename T>
class Stack;

template <typename T>
class Node {
	Node<T>* next;
	T data;

    // `static` makes it not related to a single `Node`
    // but related to the `Node` class itself.
    static int nodeCounter;

    Node(T d, Node<T>* n) {
        data = d;
        next = n;
        nodeCounter++;
    }

    ~Node() {
        nodeCounter--;
    }

    friend class Stack<T>;
};

// init `nodeCounter`
template <typename T>
int Node<T>::nodeCounter = 0;

template <typename T>
class Stack {
    Node<T>* top = nullptr;
public:
    // Create a node and push it into `Stack`
    Stack& push(T data) {
        top = new Node<T>(data, top);

        return *this;
    }

    // Remove and return of the last element at the top of the `Stack`
    T pop() {
        T data;
        Node<T>* toRemove = top;
        top = toRemove->next;
        data = toRemove->data;

        // `delete` calls the `~Node()` destructor
        delete toRemove;

        return data;
    }

    operator bool() const {
        return top == nullptr;
    }

    operator int() const {
        return depth();
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int depth() const {
        return Node<T>::nodeCounter;
    }

    // `virtual` allows destructor to follow heirarchy,
    // will take care of super class parts.
    // it's good to keep destructors as `virtual`
    virtual ~Stack() {
        // remove and delete all `Nodes`
        Node<T>* toDelete;
        while (top != nullptr) {
            // First.. always add a temp pointer to top
            toDelete = top;

            top = toDelete->next;

            delete toDelete;
        }
    }
};