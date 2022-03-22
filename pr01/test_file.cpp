#include <iostream>
#include <vector>
#include <numeric>
class Task
{
protected:
    int cpuNum;
    int size;

public:
    Task(int cpuNum, int size) {
        this->cpuNum = cpuNum;
        this->size = size;
    }

    // На каком ядре процессора выполняется задача
    int getCPU() const {
        return cpuNum;
    }

    // Оценка сложности задачи (в попугаях)
    int getSize() const {
        return size;
    }
};

class Analyzer
{
public:
    std::vector < std::vector <int> > cores;
    // Создать анализатор для системы с numCores ядер
    Analyzer(int numCores) {
        std::vector < std::vector <int> > cores(numCores);

        //std::vector < std::vector <int> > cores(numCores, std::vector <int> core);
    };

    // Проанализировать текущие задачи
    void analyze(const std::vector<Task>& tasks){
        for(auto i = 0; i<tasks.size(); ++i){
            cores[tasks[i].getCPU()].push_back(tasks[i].getSize());
        };
    };

    // Сообщить общую нагрузку на заданное ядро
    int getLoadForCPU(int cpuNum){
        return std::accumulate(cores[cpuNum].begin(), cores[cpuNum].end(), 0);
    };
};


int main()
{
    int numberOfCores = 4;
    std::vector<Task> data = { {0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5} };
    Analyzer a(numberOfCores);
    a.analyze(data);
    for(int i = 0; i < numberOfCores; i++)
        std::cout << a.cores.data() << std::endl;
    for(int i = 0; i < numberOfCores; i++)
        std::cout << a.getLoadForCPU(i) << std::endl;
    return 0;
}
