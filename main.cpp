#include <iostream>



using namespace std;


struct Elem
{
    int value;
    Elem* next;
};




class Iterator
{
private:
    Elem* current;

public:

    void next(Elem* head)
    {
        if (head->next == NULL)
            current = head;
        if (current == NULL)
            current = head;

        if (hasNext()) {
            current = current->next;
            cout << current->value << endl;
        }
        else
        {
            cout << "It's the last node. ";
            current = head;
        }
    }

    bool hasNext()
    {
        if (current->next != NULL)
            return true;
        else return false;
    }

};


class List
{
private:
    Elem* head;
public:
    List()
    {
        head = NULL;
    }

    void iterator()
    {
        Iterator i;
        i.next(head);
    }

    void add(int val)
    {
        Elem* element = new Elem;
        element->value = val;
        element->next = NULL;
        if(head == NULL)
            head = element;
        else
        {
            Elem* current = head;

            while(current->next) {
                current = current->next;
            }
            current->next = element;
        }
    }



    void del(int n){
        Elem* current = head;
        int flag = 0;
        Elem* previous = head;
        bool del_head;

        if (n == current->value){
            del_head = true;
            head = current->next;
            delete current;
        }

        while (current){
            if (n == current->value || del_head){
                flag = 1;
                break;
            }
            current = current->next;
        }
        if (flag == 0){
            cout <<"No match found"<<endl;
        }   else{
            while(previous->next != current) {
                previous = previous->next;
            }
            if (!del_head) {
                previous->next = current->next;
                delete current;
            }
        }
    }


    //Для удаления только головы списка
    void remove()
    {
        Elem* current = head;
        head = current->next;
        delete current;
    }


    void insert(int n, int val){
        int count = 0;
        Elem* current = head;
        bool flag;

        while (current){
            if ( n == 0){
                flag = true;
                Elem* elem = new Elem;
                head = elem;
                elem->value = val;
                elem->next = current;
                break;
            }
            count++;
            if (count == n){
                flag = true;
                Elem* elem = new Elem;
                elem->value = val;
                elem->next = current->next;
                current->next = elem;
                break;
            }
            current = current->next;
        }
        if (!flag) {
            cout << "Can't make insert - incorrect index";
        }
    }


    void getList()
    {
        Elem *current = head;
        while(current)
        {
            cout << current->value << endl;
            current = current->next;
        }
    }
};



class Queue
{
public:

    void push(List tr, int val)
    {
        tr.add(val);
    }

    void remove(List ptr)
    {
        ptr.remove();
    }

};


int main()
{
    List elem;

    elem.add(5889);
    elem.add(462);
    elem.add(8942);
    elem.add(5562);
    elem.add(265178);


//    elem.getList();
//
//    elem.del(462);
//    cout<<endl;
//
//    elem.insert(4,55);
//
//    cout<<endl;
//    elem.getList();
//
//    cout <<endl;
//    elem.insert(0, 10456);
//    elem.getList();
//
//    cout<<endl;





//    elem.iterator();
//    elem.iterator();
//    elem.iterator();
//    elem.iterator();
//    elem.iterator();
//    elem.iterator();

    Queue list;

    list.push(elem,12);

    list.push(elem, 55);

    cout << endl;



    cout << endl;

    elem.remove();

    //elem.remove();

    elem.getList();

    return 0;
}
