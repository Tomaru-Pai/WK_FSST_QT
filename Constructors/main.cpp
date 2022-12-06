#include <QCoreApplication>
#include <iostream>

using std::cout;
using std::endl;

class Empty
{
    // compiler generated
    // Default constructor
    // Copy Constructor
    //
};

class Dummy
{
public:
    Dummy()
    {
        cout<<"Dummy: Dummy Constructor called!"<<endl;
    }
    ~Dummy()
    {
        cout<<"Dummy: Destructor called!"<<endl;

    }
};

class Base
{
public:
    Base() : m_member{0}, m_dummy{new Dummy}
    {
        cout<<"Base: Default Contructor called!"<<endl;
    }

    explicit Base(int param)
    {
        cout<<"Base: Param Contructor called!"<<endl;
        m_member = param;
        m_dummy = new Dummy;
    }

    // Copy Constructor
    Base(const Base& other) : m_member{other.m_member}, m_dummy{new Dummy}
    {
        cout<<"Base: Copy Contructor called!"<<endl;
    }

    // Assignment Constructor
    Base& operator = (const Base& other)
    {
        cout<<"Base: Assignment Contructor called!"<<endl;
        m_member = other.m_member;
        delete m_dummy;
        m_dummy = new Dummy;

        return *this;
    }

    virtual void doSomething(int x) const = 0;

    ~Base()
    {
        cout<<"Base: Destructor called!"<<endl;
        delete m_dummy;
    }

private:
    int m_member;
    Dummy* m_dummy; // Bei Dummy* uninitialisiert
};

class Exception
{
public:
    Exception(int type, const std::string& msg) :
        m_type{type}, m_message(msg)
    {}

    std::string getMessage() const
    {
        return m_message;
    }

    static const int DIV_BY_ZERO = 1;

private:
    int m_type;
    std::string m_message;
};

class Derived : public Base
{
public:
    Derived()
    {
        cout<<"Derived: Contructor called!"<<endl;
    }

    Derived(int param) : Base{param}
    {

    }

    ~Derived()
    {
        cout<<"Derived: Destructor called!"<<endl;
    }

    void doSomething(int x) const override
    {
        // ...
        // ERROR
        if (x == 0)
        {
            Exception ex(Exception::DIV_BY_ZERO, "Division by Zero!");
            throw ex;
        }
    }
};

int main(int argc, char *argv[])
{
    {
        Derived an_object;
        Derived another_object(77);

        Derived noa_object = an_object; // Funktioniert ohne copy constructor nicht.
        another_object = an_object; // Funktioniert ohne assignment constructor nicht.
        // Alle Copien danach sind abgesichtert durch copy und assignment.
    }

    cout << "=========================="<<endl;

    {
        Derived a_derived_object;
        try {
            a_derived_object.doSomething(0);
        }  catch (Exception& ex) {
            // Handle error
            std::cout << "Error occured: " << ex.getMessage() << std::endl;
        }

    }

    return 0;
}


/*
 * Wir machen einen Vanilla Server
 * Die frage stellt sich nur ob wir ihn moderieren wollen oder nicht
 * also ob hacks "erlaubt" sind etc.
 * Xray ist eh net so schlimm tbh
 * ich denke eher über item doupen oder PVP Hacks wie fly etc. gegen die können wir was machen.
 *
 *
 *
 *
 * */
