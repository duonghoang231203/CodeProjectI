#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    bool contains(int k) {
        Node* current = head;
        while (current != NULL) {
            if (current->key == k) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void addLast(int k) {
        if (contains(k)) {
            return;
        }

        Node* new_node = new Node;
        new_node->key = k;
        new_node->next = NULL;//de bieu thi rang no khong co nut tiep theo, truong 'next' cua no duoc gan bang NULL

        if (head == NULL) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next != NULL) {// neu next khac NULL co nghia la chua den nut cuoi trong danh sach
                current = current->next;
            }
            current->next = new_node;//sau khi tim duoc nut cuoi thi gan new_node 
        }
    }

    void addFirst(int k) {
        if (contains(k)) {
            return;
        }

        Node* new_node = new Node;
        new_node->key = k;
        new_node->next = head;
        head = new_node;
    }

    void addAfter(int u, int v) {
        if (contains(u) || !contains(v)) {//neu ton tai u or v khong ton tai thi ket thuc ham
            return;
        }

        Node* current = head;//duyet danh sach tu dau de tim nut co gia tri v
        while (current != NULL && current->key != v) {//duyet den khi thay v
            current = current->next;
        }

        if (current != NULL) {
            Node* new_node = new Node;
            new_node->key = u;
            new_node->next = current->next;//luc nay current la v thi current->next la u
            current->next = new_node;
        }
    }

    void addBefore(int u, int v) {
        if (contains(u) || !contains(v)) {
            return;
        }

        if (head == NULL || head->key == v) {//neu chuoi chua co gia tri or v la ki tu dau tien thi addFirst(u)
            addFirst(u);
            return;
        }

        Node* current = head;//duyet danh sach tu dau de tim nut co gia tri v
        while (current->next != NULL && current->next->key != v) {//muon them u vao truoc v thi can tro den nut truoc do, nghia la next tro den v 
            current = current->next;
        }

        if (current->next != NULL) {
            Node* new_node = new Node;
            new_node->key = u;
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void remove(int k) {
        if (head == NULL) {
            return;//khong co gi de xoa
        }

        if (head->key == k) {
            Node* temp = head;
            head = head->next;//tro den nut tiep theo sau nut dau tien. Dieu nay loai bo nut dau tien ra khoi danh sach
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->key != k) {
            current = current->next;
        }

        if (current->next != NULL) {//ham kiem tra xem da tim thay k chua. Neu k dc tim thay thi thuc hien
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        list.addLast(key);//su dung addLast se them gia tri vao cuoi danh sach, neu muon xay dung lien ket theo thu tu tu nhien, cac phan tu moi duoc them phia sau danh sach
    }

    string command;
    while (cin >> command) {
        if (command == "addlast") {
            int k;
            cin >> k;
            list.addLast(k);
        } else if (command == "addfirst") {
            int k;
            cin >> k;
            list.addFirst(k);
        } else if (command == "addafter") {
            int u, v;
            cin >> u >> v;
            list.addAfter(u, v);
        } else if (command == "addbefore") {
            int u, v;
            cin >> u >> v;
            list.addBefore(u, v);
        } else if (command == "remove") {
            int k;
            cin >> k;
            list.remove(k);
        } else if (command == "reverse") {
            list.reverse();
        } else if (command == "#") {
            break;
        }
    }

    list.printList();//in

    return 0;
}
