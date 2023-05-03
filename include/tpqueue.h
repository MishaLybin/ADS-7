// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T>
class TPQueue {
   private:
    struct Item {
        T data;
        Item* next = nullptr;
    };
    Item* head;
    Item* create(const T& value) {
        Item *temp = new Item;
        temp->data = value;
        temp->next = nullptr;
        return temp;
    }
    void addHead(const T& value) {
        if (head) {
            Item* temp = create(value);
            temp->next = head;
            head = temp;
        } else {
            head = create(value);
        }
    }

 public:
    TPQueue(): head(nullptr) {}
    void push(const T& value) {
        if (!head) {
            addHead(value);
        } else if ((*head).data.prior < value.prior) {
            addHead(value);
        } else {
            Item* temp = head;
            while (temp) {
                if ((*temp).data.prior > value.prior) {
                    temp = temp->next;
                } else if ((*temp).data.prior == value.prior) {
                    Item* temp_new = create(value);
                    temp_new->next = temp->next;
                    temp->next = temp_new;
                    break;
                } else {
                    Item* temp_new = create((* temp).data);
                    temp_new->next = temp->next;
                    (* temp).data = value;
                    temp->next = temp_new;
                    break;
                }
            }
        }
    }
    const T pop() {
        T data;
        if (!(head->next)) {
            data = head->data;
        } else {
            Item* temp = head->next;
            data = head->data;
            delete head;
            head = temp;
        }
        return data;
    }
};

};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
