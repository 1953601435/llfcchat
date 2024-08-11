#ifndef SINGLETON_H
#define SINGLETON_H
#include<global.h>
template <typename T>
class Singleton//单例类，做基类使用,回收调用智能指针析构，从而是T的析构，(Httpmgr)析构要公有
{
protected://子类能调用
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;
    Singleton&operator = (const Singleton<T>&st)=delete;
    static std::shared_ptr<T> _instance;    //所有的都返回一个实例，用静态
public:
    //初始化一次(static，只在第一次调用时)
    static std::shared_ptr<T>GetInstance(){//直接写多重检测有风险
        static std::once_flag s_flag;
        std::call_once(s_flag,[&](){//调用初始化true,第二次就不会
            _instance = std::shared_ptr<T>(new T);
        });
        return _instance;//T类型，Singleton的成员，析构时智能指针析构
    }

    void PrintAddress(){
        std::cout<<_instance.get()<<std::endl;
    }
    ~Singleton(){
        std::cout<<"this is singleton destruct"<<std::endl;
    }
};
template<typename T>
std::shared_ptr<T> Singleton<T>::_instance=nullptr;//初始化空指针



#endif // SINGLETON_H
