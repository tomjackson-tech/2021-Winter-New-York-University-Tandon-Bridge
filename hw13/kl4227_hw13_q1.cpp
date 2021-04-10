/*
 * author: Lin, Kuan-You
 * date: 4/10/2021
 * 2021 NYU Tandon Bridge Homework 13 Question 1

Predator-Prey Environment, Please refer to the documentation.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

int NUMBER_DOODLEBUG = 20;
int NUMBER_ANT = 100;
int MATRIX_X = 20;
int MATRIX_Y = 20;

int ANT_TIME_TO_BREED = 3;
int DOODLEBUG_TIME_TO_BREED = 8;
class Organism{
protected:
    int age;
    bool tired;
    int x_position;
    int y_position;
    int offspring_x;
    int offspring_y;

public:
    Organism(int x, int y):x_position{x}, y_position{y}, age{0}, tired{false}, offspring_x{0}, offspring_y{0}{
        // blank
    }
    int get_x() const{
        return x_position;
    }
    int get_offspring_x() const{
        return offspring_x;
    };
    int get_offspring_y() const{
        return offspring_y;
    };
    int get_y() const{
        return y_position;
    }
    virtual void toggle_tired() = 0;
    bool get_tired() const{
        return tired;
    }
    virtual char get_type() const = 0;
    virtual bool demise() const = 0;
    virtual bool breed(std::vector<std::vector<Organism*>> const &matrix) = 0;
    void reset_breed(){
        offspring_x = 0;
        offspring_y = 0;
    };
    virtual void print() const = 0;
    virtual bool move(std::vector<std::vector<Organism*>> const &matrix) = 0;
    friend std::ostream& operator<<(std::ostream& outs, const Organism& organism);
};


class Ant : public Organism{
private:
    char type;
public:
    Ant(int x, int y): Organism(x, y), type{'A'}{
        // blank
    };
    bool move(std::vector<std::vector<Organism*>> const &matrix) override;
    char get_type() const override{
        return Ant::type;
    }
    bool demise() const override{
        return false;
    }
    void print() const override{
        std::cout << 'o';
    }

    bool breed(std::vector<std::vector<Organism*>> const &matrix) override{
        if(age >= ANT_TIME_TO_BREED){
            std::vector<int> try_case;
            while(try_case.size() < 4){
                int move = rand() % 4;
                while(std::find(try_case.begin(), try_case.end(), move) != try_case.end()){
                    move = rand() % 4;
                }
                int temp_y = y_position;
                int temp_x = x_position;
                switch(move){
                    case 0:
                        temp_x += 1;
                        break;
                    case 1:
                        temp_x -= 1;
                        break;
                    case 2:
                        temp_y += 1;
                        break;
                    case 3:
                        temp_y -= 1;
                        break;
                    default:
                        break;
                }
                // see if the move is off grid
                if((temp_x < 20) and (temp_x >= 0) and (temp_y < 20) and (temp_y >= 0)){
                    // see if the grid is empty
                    if(matrix[temp_x][temp_y] -> get_type() == 'E'){
                        offspring_x = temp_x;
                        offspring_y = temp_y;
                        std::cout << "Breed an ant in the position: (" << temp_x << ", " << temp_y << ")" << std::endl;
                        age = 0;
                        return true;
                    } else {
                        try_case.push_back(move);
                    }
                }
                try_case.push_back(move);
            }
            return false;
        }
    }

    void toggle_tired() override{
        if(tired){
            tired = false;
        } else {
            tired = true;
        }
    }
};


class Doodlebug : public Organism{
private:
    char type;
    int starve;
public:
    Doodlebug(int x, int y): Organism(x, y), type{'D'}, starve{0}{
        // blank
    };
    bool move(std::vector<std::vector<Organism*>> const &matrix) override;
    char get_type() const override{
        return Doodlebug::type;
    }
    bool demise() const override{
        if(starve >= 3){
            std::cout << "Starve to death in the position: (" << x_position << ", " << y_position << ")" << std::endl;
            return true;
        }
        return false;
    }
    void print() const override{
        std::cout << 'X';
    }
    void toggle_tired() override{
        if(tired){
            tired = false;
        } else {
            tired = true;
        }
    }
    bool breed(std::vector<std::vector<Organism*>> const &matrix) override{
        if(age >= DOODLEBUG_TIME_TO_BREED){
            std::vector<int> try_case;
            while(try_case.size() < 4){
                int move = rand() % 4;
                while(std::find(try_case.begin(), try_case.end(), move) != try_case.end()){
                    move = rand() % 4;
                }
                int temp_y = y_position;
                int temp_x = x_position;
                switch(move){
                    case 0:
                        temp_x += 1;
                        break;
                    case 1:
                        temp_x -= 1;
                        break;
                    case 2:
                        temp_y += 1;
                        break;
                    case 3:
                        temp_y -= 1;
                        break;
                    default:
                        break;
                }
                // see if the move is off grid
                if((temp_x < 20) and (temp_x >= 0) and (temp_y < 20) and (temp_y >= 0)){
                    // see if the grid is empty
                    if(matrix[temp_x][temp_y] -> get_type() == 'E'){
                        offspring_x = temp_x;
                        offspring_y = temp_y;
                        age = 0;
                        std::cout << "Breed a doodlebug in the position: (" << temp_x << ", " << temp_y << ")" << std::endl;
                        return true;
                    } else {
                        try_case.push_back(move);
                    }
                }
                try_case.push_back(move);
            }
            return false;
        }
    }
};

class Empty : public Organism{
private:
    char type;
public:
    Empty(int x, int y): Organism(x, y), type{'E'}{
        // blank
    };
    bool move(std::vector<std::vector<Organism*>> const &matrix) override{
        return false;
    }
    char get_type() const override{
        return Empty::type;
    }
    bool demise() const override{
        return false;
    }
    void print() const override{
        std::cout << '-';
    }
    void toggle_tired() override{
        // blank
    }
    bool breed(std::vector<std::vector<Organism*>> const &matrix) override{
        return false;
    }
};


std::ostream& operator<<(std::ostream& outs, const Organism& organism){
    organism.print();
    return outs;
}

bool Ant::move(std::vector<std::vector<Organism*>> const &matrix){
    if(tired){
        return false;
    } else {
        age += 1;
    }
    int move = rand() % 4;
    int temp_y = y_position;
    int temp_x = x_position;
    switch(move){
        case 0:
            temp_x += 1;
            break;
        case 1:
            temp_x -= 1;
            break;
        case 2:
            temp_y += 1;
            break;
        case 3:
            temp_y -= 1;
            break;
        default:
            break;
    }
    // see if the move is off grid
    if((temp_x < 20) and (temp_x >= 0) and (temp_y < 20) and (temp_y >= 0)){
        // see if the grid is empty
        if(matrix[temp_x][temp_y] -> get_type() == 'E'){
            x_position = temp_x;
            y_position = temp_y;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool Doodlebug::move(std::vector<std::vector<Organism*>> const &matrix){
    age += 1;
    starve += 1;
    int move = rand() % 4;
    int temp_y = y_position;
    int temp_x = x_position;
    switch(move){
        case 0:
            temp_x += 1;
            break;
        case 1:
            temp_x -= 1;
            break;
        case 2:
            temp_y += 1;
            break;
        case 3:
            temp_y -= 1;
            break;
        default:
            break;
    }
    // see if the move is off grid
    if((temp_x < 20) and (temp_x >= 0) and (temp_y < 20) and (temp_y >= 0)){
        // see if the grid has another doodlebug
        if(matrix[temp_x][temp_y] -> get_type() != 'D'){
            // eat an ant!
            if(matrix[temp_x][temp_y] -> get_type() == 'A'){
                std::cout << "Eat an ant in the position: (" << temp_x << ", " << temp_y << ")" << std::endl;
                starve = 0;
            }
            x_position = temp_x;
            y_position = temp_y;
            return true;
        } else {
            return false;
        }
    }
    return false;
}



std::vector<int> randNumSequence(int arrSize, int max){
    // generate a vector containing arrSize unique numbers ranging from 0 to max (exclusive)
    std::vector<int> sequence;
    while (sequence.size() < arrSize){
        int temp = rand() % max;
        if (std::find(sequence.begin(), sequence.end(), temp) == sequence.end()){
            sequence.push_back(temp);
        }
    }
    return sequence;
}

void printMatrix(std::vector<std::vector<Organism*>> matrix, int x_bound, int y_bound){
    int ant_counter{0};
    int doodlebug_counter{0};
    int empty_counter{0};

    int y_ruler{0};
    std::cout << std::endl << "  Environment Snapshot" << std::endl;
    std::cout << "  ";
    for (int y = 0; y < y_bound; y++){
        std::cout << (y_ruler % 10);
        y_ruler++;
    }
    std::cout << " [Y]" << std::endl;
    std::cout << "_______________________" << std::endl;
    int x_ruler{0};
    for (int x = 0; x < x_bound; x++) {
        std::cout << (x_ruler % 10) << "| ";
        x_ruler++;
        for (int y = 0; y < y_bound; y++) {
            std::cout << *matrix[x][y];
            char type = matrix[x][y] -> get_type();
            switch (type){
                case 'A':
                    ant_counter += 1;
                    break;
                case 'D':
                    doodlebug_counter += 1;
                    break;
                case 'E':
                    empty_counter += 1;
                    break;
                default:
                    break;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "[X]" << std::endl << std::endl;

    if((ant_counter+doodlebug_counter+empty_counter) != (x_bound*y_bound)){
        std::cout << "Environment Output Error: Sum Error" << std::endl;
        exit(1);
    } else {
        std::cout << "Total Number of Ants (prey) in the environment: " << ant_counter << std::endl;
        std::cout << "Total Number of Doodlebugs (predator) in the environment: " << doodlebug_counter << std::endl;
        std::cout << "==================================Generation End==================================" << std::endl;
    }

}


int main() {
    int generation{1};
    srand(time(nullptr));
    // initialize environment with empty
    std::vector<std::vector<Organism*>> matrix;
    for(int x = 0; x < MATRIX_X; x++){
        std::vector<Organism*> temp;
        for(int y = 0; y < MATRIX_Y; y++){
            auto ptr = new Empty(x, y);
            temp.push_back(ptr);
        }
        matrix.push_back(temp);
    }

    // implant prey and predator
    std::vector<int> position_arr = randNumSequence(NUMBER_ANT + NUMBER_DOODLEBUG, MATRIX_X * MATRIX_Y);
    for(int i = 0; i < position_arr.size(); i++){
        int x = position_arr[i] / MATRIX_X;
        int y = position_arr[i] % MATRIX_X;
        if (i < NUMBER_DOODLEBUG) {
            delete matrix[x][y];
            matrix[x][y] = new Doodlebug(x, y);
        } else {
            delete matrix[x][y];
            matrix[x][y] = new Ant(x, y);
        }
    }
    std::cout << "==================================Generation "<< generation << " Start==================================" << std::endl;
    printMatrix(matrix, MATRIX_X, MATRIX_Y);

    while(true){
        std::cout << "Please enter [E] to exit or anything to continue: " << std::endl;
        std::string instruction;
        std::getline(std::cin, instruction);
        if(instruction == "E"){
            break;
        }
        generation += 1;
        std::cout << "==================================Generation "<< generation << " Start==================================" << std::endl;
        for(int x = 0; x < MATRIX_X; x++){
            for(int y = 0; y < MATRIX_Y; y++){
                if(not matrix[x][y] -> get_tired()){
                    // doing the move
                    int temp_x = x;
                    int temp_y = y;
                    if(matrix[temp_x][temp_y] -> move(matrix)){
                        int new_x = matrix[temp_x][temp_y] -> get_x();
                        int new_y = matrix[temp_x][temp_y] -> get_y();
                        delete matrix[new_x][new_y];
                        matrix[new_x][new_y] = matrix[temp_x][temp_y];
                        matrix[temp_x][temp_y] = new Empty(temp_x, temp_y);
                        temp_x = new_x;
                        temp_y = new_y;
                    }
                    // doing the demise
                    if(matrix[temp_x][temp_y] -> demise()){
                        delete matrix[temp_x][temp_y];
                        matrix[temp_x][temp_y] = new Empty(temp_x, temp_y);
                    }
                    // doing the breed
                    if(matrix[temp_x][temp_y] -> breed(matrix)){
                        int off_x = matrix[temp_x][temp_y] -> get_offspring_x();
                        int off_y = matrix[temp_x][temp_y] -> get_offspring_y();
                        delete matrix[off_x][off_y];
                        switch(matrix[temp_x][temp_y] -> get_type()){
                            case 'A':
                                matrix[off_x][off_y] = new Ant(off_x, off_y);
                                break;
                            case 'D':
                                matrix[off_x][off_y] = new Doodlebug(off_x, off_y);
                                break;
                            default:
                                break;
                        }
                        matrix[temp_x][temp_y] -> reset_breed();
                    }
                    // the creature is then tired
                    matrix[temp_x][temp_y]->toggle_tired();
                }
            }
        }

        // renew status
        for(int x = 0; x < MATRIX_X; x++) {
            for (int y = 0; y < MATRIX_Y; y++) {
                matrix[x][y]->toggle_tired();
            }
        }
        printMatrix(matrix, MATRIX_X, MATRIX_Y);
    }
    return 0;
}