/*
 * author: Lin, Kuan-You
 * date: 5/7/2021
 * 2021 NYU Tandon Bridge Homework 16 Question 2

Array Queue Implementation, Please refer to the documentation.
*/


#include <iostream>
#include <vector>

template <class T>
class arrayQueue{
private:
    std::vector<T> container{0, 0, 0, 0, 0, 0};
    int front_pos = 0;
    int back_pos = -1;
    size_t curr_size = 0;
public:
    void enqueue(T new_data){
        if (container.size() > curr_size){
            back_pos = ++back_pos % container.size();
            container[back_pos] = new_data;
        } else {
            container.insert(container.begin()+back_pos+1, new_data);
            back_pos++;
            if (front_pos >= back_pos) front_pos++;
        }
        curr_size++;
    }

    T dequeue(){
        if (curr_size > 0){
            T out = container[front_pos];
            front_pos = ++front_pos % container.size();
            curr_size--;
            return out;
        }
    }

    T front() const{
        if (curr_size > 0) return container[front_pos];
    }

    T back() const{
        if (curr_size > 0) return container[back_pos];
    }

    size_t size() const{
        return curr_size;
    }

    bool empty() const{
        return (curr_size == 0);
    }

    void clear(){
        container = {0, 0, 0, 0, 0, 0};
        curr_size = 0;
        front_pos = 0, back_pos = -1;
    }
};

int main() {
    arrayQueue<int> d;
    std::cout << "Test 1: " << std::endl;
    for (int i = 0; i < 5; i++){
        d.enqueue(i);
    }
    while(d.size() > 0){
        std::cout << d.dequeue() << std::endl;
    }
    d.clear();

    std::cout << "Test 2: " << std::endl;
    for (int i = 0; i < 100; i++){
        d.enqueue(i);
    }
    while(d.size() > 0){
        std::cout << d.dequeue() << std::endl;
    }
    d.clear();

    std::cout << "Test 3: " << std::endl;
    for (int i = 0; i < 10; i++){
        d.enqueue(i);
    }
    while(d.size() > 4){
        std::cout << d.dequeue() << std::endl;
    }
    for (int i = 0; i < 6; i++){
        d.enqueue(i);
    }
    while(d.size() > 0){
        std::cout << d.dequeue() << std::endl;
    }
    d.clear();

    std::cout << "Test 4: " << std::endl;
    for (int i = 0; i < 3; i++){
        d.enqueue(i);
    }
    for (int i = 3; i < 10; i++){
        d.enqueue(i);
    }
    while(d.size() > 0){
        std::cout << d.dequeue() << std::endl;
    }
    d.clear();



    return 0;
}