/*
 * author: Lin, Kuan-You
 * date: 4/26/2021
 * 2021 NYU Tandon Bridge Homework 15 Question 1

DoublyLinkedList and Input file, Please refer to the documentation.
*/

#include <iostream>
#include <string>
#include <fstream>

template<class T>
class DoublyLinkedList;
template<class T>
class Node;

class Employee{
private:
    std::string id;
    double hourly_pay_rate;
    std::string name;
    double total_pay;

public:
    Employee():
        id("000"), hourly_pay_rate(0), name("None"), total_pay{0}{
    }
    Employee(std::string& id, double& hpr, std::string& name):
        id(id), hourly_pay_rate(hpr), name(name), total_pay{0}{
        // intentionally leave blank
    }
    std::string get_name() const{
        return name;
    }
    double get_pay() const{
        return total_pay;
    }
    void add_pay(double hour){
        total_pay += hour * hourly_pay_rate;
    }
    bool operator==(const Employee& rhs) const{
        return (id == rhs.id);
    }
    bool operator>=(const Employee& rhs) const{
        return (total_pay >= rhs.total_pay);
    }
    bool operator<=(const Employee& rhs) const{
        return (total_pay <= rhs.total_pay);
    }
    bool operator>(const Employee& rhs) const{
        return (total_pay > rhs.total_pay);
    }
    bool operator<(const Employee& rhs) const{
        return (total_pay < rhs.total_pay);
    }
    friend std::ostream& operator<<(std::ostream& outs, const Employee &rhs);
};

template <class T>
class Node{
    T data;
    Node<T>* next;
    Node<T>* prev;
public:
    Node(const T& data = T(), Node<T>* next = nullptr, Node<T>* prev = nullptr) :
        data(data), next(next), prev(prev) {
        // intentionally leave blank
    }
    bool operator==(const Node<T>& rhs) const{
        return (data == rhs.data);
    }
    friend class DoublyLinkedList<T>;
};


template <class T>
class DoublyLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
public:
    DoublyLinkedList(){
        head = new Node<T>(T(), new Node<T>);
        tail = head->next;
        tail->prev = head;
        size = 0;
    }
    ~DoublyLinkedList() {
        clear();
        delete head;
        delete tail;
    }
    bool empty() const{
        return (size == 0);
    };
    size_t get_size() const{
        return size;
    }
    T remove(Node<T>* &deletee) {
        Node<T>* temp = deletee;
        T delete_data = deletee->data;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        size--;
        return delete_data;
    }
    void clear(){
        while (!empty())
            remove(head->next);
    }
    T pop(){
        return remove(tail->prev);
    }
    T pop_front(){
        return remove(head->next);
    }
    T pop_max(){
        Node<T> *biggest = head->next;
        Node<T> *iterator = head->next;
        while(iterator != tail){
            if(iterator->data > biggest->data){
                biggest = iterator;
            }
            iterator = iterator->next;
        }
        T temp = biggest->data;
        remove(biggest);
        return temp;
    }

    void insert(T& data, Node<T>* &location){
        Node<T>* temp = location->next;
        location->next = new Node<T> (data, temp, temp->prev);
        temp->prev = location->next;
        size++;
    }
    void append(T data){
        insert(data,tail->prev);
    }
    void append_front(T data){
        insert(data, head);
    }
    void find_and_write(T target, double hour){
        Node<T> *iterator = head->next;
        int num{0};
        while(num != size){
            if(iterator->data == target){
                iterator->data.add_pay(hour);
                break;
            } else{
                iterator = iterator->next;
                num++;
            }
        }
    }
};


void openInputFile(std::ifstream& inFile) {
    std::string filename;
    std::cout << "Please enter the file name: ";
    std::cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        std::cout << "Error in the file name" << std::endl;
        std::cout << "Please enter the file name again: ";
        std::cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

std::ostream& operator<<(std::ostream& outs, const Employee &rhs){
    outs << rhs.get_name() << ", $" << rhs.get_pay() << std::endl;
    return outs;
}

int main() {
    DoublyLinkedList<Employee> DLL;
    std::ifstream file1;
    std::ifstream file2;
    std::cout << "The name book, the first file" << std::endl;
    openInputFile(file1);
    std::string id;
    while(file1 >> id){
        double hpr;
        file1 >> hpr;
        std::string name;
        std::getline(file1, name);

        Employee temp(id, hpr, name);
        DLL.append(temp);
    }

    std::cout << std::endl;
    std::cout << "The timesheet, the second file" << std::endl;
    openInputFile(file2);
    while(file2 >> id){
        double hour;
        file2 >> hour;

        double temp_hpr{0};
        std::string temp_name{"Dummy"};
        Employee temp(id, temp_hpr, temp_name);
        DLL.find_and_write(temp, hour);
    }

    std::cout << "*********Payroll Information********\n";
    while(!DLL.empty()){
        std::cout << DLL.pop_max();
    }
    std::cout << "*********End payroll**************\n";
    return 0;
}