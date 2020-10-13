#include "mtb_data_translator.h"
#include <iostream>
#include <memory>
//#include <thread>
//#include <mutex>


int main(int argc, char * argv [])
{
    auto data_translator = std::make_unique<DataTranslator>();
    data_translator->run(argc, argv);

    return 0;
}

// End of the file





//std::mutex m1;
//std::mutex m2;
//int a = 100;
//void w1()
//{
//    m1.lock();
//    m2.lock();
//    a = 1 + a;
//    m2.unlock();
//    m1.unlock();

//}
//void w2()
//{
//    m1.lock();
//    a = a + 100;
//    m1.unlock();
//}
//    std::thread t1(w1);
//    std::thread t2(w2);

//    t1.join();
//    t2.join();




//#include <thread>

//class ThreadTest
//{
//public:
//    ThreadTest():
//    work_flag_(true)
//    {
//    }

//    ~ThreadTest() = default;

//    void operator() ()
//    {
//        std::cout << "work starts.." << std::endl;

//        while (work_flag_)
//        {
//            std::this_thread::sleep_for(std::chrono::milliseconds(200));
//            std::cout << " flag = " << work_flag_ << std::endl;
//        }

//        std::cout << "work ends." << std::endl;
//    }

//    void conclude_work()
//    {
//        std::cout << "Conclude work" << std::endl;
//        work_flag_ = false;
//        std::cout << " flag = " << work_flag_ << std::endl;
//    }

//private:
//    bool work_flag_;
//};

//int main()
//{
//    ThreadTest tworker;

//    std::thread t1(std::ref(tworker));

//    std::this_thread::sleep_for(std::chrono::milliseconds(400));
//    std::cout << "main wakes up " << std::endl;

//    tworker.conclude_work();

//    t1.join();

//    return 0;
//}











//#include <thread>
//#include <mutex>
//#include <condition_variable>

//class ThreadWorker
//{

//public:
//    void operator() ()
//    {

//    }

//};

