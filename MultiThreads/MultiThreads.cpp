/*-------1.在独立的线程中运行Hello Thread World----------------------*/
#include <iostream>
#include <thread> //---管理线程的函数和类在<thread>中声明
#include <vector>
#include <string>

/**
 * @brief threadInitialFunc()
 * 每个线程都必须有一个初始函数（Initial function），新线程的执行从初始函数开始执行。
 * 对于新创建的线程，在std::thread对象的构造函数中指定其初始函数。
 * 对于主线程，其初始函数为main().
*/
void threadInitialFunc(){
    std::cout << "Hello Thread world!\n";//<<endl;
}

void vectorTest()
{
    std::vector<std::string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    for (const std::string& word : msg)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

int main(){
    /*
        这里在主线程中创建了一个新的线程t，主线程始于main(),线程t的初始函数为threadInitialFunc()
        注意：当指定的入口函数返回时，该线程就会退出。
    */
    std::thread myTh(threadInitialFunc);
    myTh.join();
    vectorTest();
}
/*------------------------------------------------------------------*/

