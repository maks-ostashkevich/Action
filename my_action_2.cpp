/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <memory>

// using namespace std;

class WrapperInterface
{
public:
    virtual void operator()()
    {
        
    }
};

template<typename T>
class Wrapper : public WrapperInterface
{
public:
    Wrapper(T ptr) : ptr(ptr) // T* ptr
    {
        
    }
    
    void operator()()
    {
        ptr(); // (*ptr)();
    }
    
private:
    T ptr; // T* ptr;
};

class Action
{
public:
    template<typename T>
    Action(T val)
    {
        wi = std::make_shared<Wrapper<T>>(val);
    }
    
    Action(const Action& action)
    {
        wi = action.wi;
    }
    
    template<typename T>
    Action& operator=(T val) // there should be a link
    {
        wi = std::make_shared<Wrapper<T>>(val);
        return *this;
    }
    
    void operator()()
    {
        (*wi)();
    }
private:
    std::shared_ptr<WrapperInterface> wi;
};

void function()
{
	std::cout<<1<<std::endl;
}
struct Functor
{
	std::string s; // String
	void operator()()
	{
	    std::cout<<s<<std::endl; 
	}
};

int main()
{
    Action action=function;
	action(); //1
	
	// /*
	action = Functor{"qqq"};
	action();//qqq
	
	// /*
	Action action2=action;
	action=Functor{"www"};
	
	// /*
	action2();//qqq
	// /*
	action();//www
	// */
	
	return 0;
}