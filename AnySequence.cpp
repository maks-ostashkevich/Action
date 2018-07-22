/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory> // utility

using namespace std;

class Sequence
{
public:
	Sequence(double currVal, double change);
	double Next();
private:
	double startVal, currVal, change;
	// double startVal, number;
};

Sequence::Sequence(double currVal, double change) : startVal(currVal), currVal(currVal), change(change)
{
	
}

double Sequence::Next()
{
	double retVal = currVal;
	currVal += change;
	return retVal;
}

class WrapperInterface
{
public:
    // double Next();
    
    /*
    double Next()
    {
        return -1000; // works just this function, not the inherited function
    }
    */
    
    virtual double Next()
    {
        return 0;
    }
};

template<typename T>
class Wrapper : public WrapperInterface
{
public:
    Wrapper(T& obj) : objReference(obj) // const 
    {
        
    }

    double Next() // T
    {
        return objReference.Next();
    }
    
private:
    T& objReference; // ? const
};

class Action
{
public:
    template<typename T>
    Action(T& obj)
    {
        wi = std::make_shared<Wrapper<T>>(obj);
    }
    
    // template<typename T>
    double Next()
    {
        return wi->Next();
    }
    
private:
    std::shared_ptr<WrapperInterface> wi;
};

int main()
{
    Sequence s(0, 1);
    Action newAction(s);

    std::cout << newAction.Next() << std::endl;
    std::cout << newAction.Next() << std::endl;
    std::cout << newAction.Next() << std::endl;
    std::cout << newAction.Next() << std::endl;

    return 0;
}

/*
void function()
{
	std::cout<<1<<std::endl;
}
struct Functor
{
	std::string String;
	void operator()()
	{
		std::cout<<String<<std::endl;
	}
};

class Action
{
	...
};

int main()
{
	Action action=function;
	action();//1
	action=Functor{"qqq"};
	action();//qqq
	Action action2=action;
	action=Functor{"www"};
	action2();//qqq
	action();//www
	return 0;
}

*/