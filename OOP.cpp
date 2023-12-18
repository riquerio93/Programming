/**********
KEY OBJECT ORIENTATED PROGRAMMING (OOP) CONCEPTS:

ClASSES:
A structure that holds attributes consisting of methods
and variables. When we use a class in our main method, we consider each
instance of that class an "object"

Class Test{}

main(){
    Test t;
    Test myTest;
}

The above showcases 2 objects being created of the class "Test".
**************************

INHERITANCE:
A parent/child relationship among classes. Attributes that belong to a class
may be "inherited" by another class. This allows us to reuse key attributes from a parent class
without re-creating them within a related child class.
**************************

ABSTRACTION:
The general process of protecting and hiding data, while displaying only essential data.
We can use access modifiers such as "public", "private", and "protected" in order to help us
achieve abstraction. 
**************************

ENCAPSULATION:
The application of data abstraction. Whereas abstraction uses access modifiers to hide and/or display data.
Encapsulation combines that data into a single hidden or accessible component.

Encapsulation and Abstraction essentially go hand in hand.
**************************

OVERLOAD:
2 methods with the same names. But use different parameters

void func(int a)

void func(int a, int b)
**************************

OVERRIDE: 
2 methods with the same names and same parameters within inherited classes
may "override" the parent's method. Use of keyword virtual is needed for an override

class Parent:
virtual void func(int a)

class Child:
void func(int a)

unless explicity coded to do so otherwise, in this scenario, usage of "func" will
be from the child.

**************************
POLYMORPHISM:

The combination of all of the above.
This occurs when we have many classes that are related to each other via inheritance.
Uses overriden methods and/or inherited attributes to perform different tasks.
**************************/

#include <iostream>

using namespace std;

/******
PARENT CLASS NAMED "ANIMAL"
Is used as a parent for attribute inheritance for 2 following classes
"dog" and "snake"
******/

class Animal
{
    /******
    the public attributes of the animal class
    "public" meaning any other classes or functions may access these attributes
    ******/
    public:
        Animal();   //Constructor 
        Animal(const Animal& a);  //Copy Constructor
        ~Animal(); //Destructor
        
        //a virtual function can be overriden by a child class.
        virtual void setName(string Name) { 
            cout << "Setting Animal name to: " << Name << endl;
            this->Name = Name;
        }
        
        void setID(int id) { this->id = id; } 
        string Name = "";
        bool Aggressive;
        
    /******
    the private attributes of the animal class
    "private" meaning NO other classes or functions may access these attributes
    except for the animal class itself
    ******/
    
    private:
        string animalType = "";
        
    /******
    the protected attributes of the animal class
    "protected" meaning NO other classes or functions may access these attributes
    except for the animal class itself AND child classes. In this case, both the 
    dog and snake classes may access them, since the two are child classes of Animal.
    ******/
    
    protected:
        int id;
};

/*****
The Constructor to the animal class.
Whenever we create a new object of the animal class, this is automatically called (used)

Since there are no parameters, we consider this the default or the empty constructor. 
*****/
Animal::Animal(){}  

/*****
The Copy Constructor to the animal class.
We can use this to create a new object, or a "clone" of an object of the animal class that already exists.

However, since there are no parameters and no real body of code, we're not doing much with it.
*****/
Animal::Animal(const Animal& a){} 

/*****
The Destructor to the animal class.
Whenever we end our program, this deletes the object(s) associated to it's class.
This is useful to free up memory whenever we finish with our object.

Note: We can also explicity call the Destructor before we end the program using "delete"

However, since there are no parameters and no real body of code, we're not doing much with it.
*****/
Animal::~Animal(){} 


/*****
Dog Class, child of the parent "Animal" class.
The dog class implicitly inherits all public and protected attributes of its parent.
But does not inerhit the private attributes of its parent.
*****/

class Dog: public Animal
{
    public:
        Dog(); //default empty constructor
        Dog(string Name); //constructor overload with a parameter 
        
        //This function overides the parent's "setName" function since the parent is virtual
        void setName(string Name) { 
            cout << "Setting Dog's name to: " << Name << endl;;
            this->Name = Name;
        }
        
        int getID() { return id; }
        bool houseTrained;
    private:
        string Breed;

};

//Initalization of the dog constructor
Dog::Dog(){}

//Initalization of the dog constructor with parameter. If given a name, automatically set the "name" variable
Dog::Dog(string Name)
{
    this->Name = Name;
}

class Snake: public Animal
{
    public:
        Snake();
        Snake(string Name, bool Venomous);
		string isVenomous();
		
		void setName(string Name) { 
            cout << "Setting Snake's name to: " << Name << endl;;
            this->Name = Name;
        }
		
        int getID() { return id; }
        bool Venomous;
    private:
        string Breed;
};

Snake::Snake(){}

//Initalization of the snake constructor with parameter. If given a name, automatically set the "name" variable
//Note: The venomous parameter is optional. If not given automatically set it to true.
Snake::Snake(string Name, bool Venomous = true)
{
    this->Name = Name;
    this->Venomous = Venomous;

}

string Snake::isVenomous()
{
    if(Venomous)
		return "True";
	
	return "False";
}

int main()
{
    Animal someAnimal;  //Animal object, using default constructor
    Animal clonedAnimal(someAnimal); //Animal object, using copy constructor, referencing "someAnimal" object.
    Dog myEmptyDog;  //Dog object
    Dog myNamedDog("Sparky");  //dog object using overloaded constructor with name parameter
    Snake unknownSnake;
    Snake meanSnake("Mamba"); //Snake object, NOT using optional parameter
    Snake happySnake("Noodle", false); //snake object, using optional parameter
	
	someAnimal.setName("Bart");    //Setting the "someAnimal" object's name using setName method
	cout << someAnimal.Name << endl;  //display someAnimal's name.
	clonedAnimal.setName("Lisa");     //Setting the cloned object's name 
	
	//notice how even though "clonedAnimal" is a copy of someAnimal, they are still 2 distinct and separate objects, thus different names
	cout << clonedAnimal.Name << endl;   
	cout << someAnimal.Name << endl;    
	
	cout << myNamedDog.Name << endl; //display myNamedDog with given name from constructor
	cout << myEmptyDog.Name << endl;
	
	//notice how we're using an Inherited method from the Animal class. With setName. 
	//through polymorphism, we altered the output sentence a little.
	myEmptyDog.setName("Maggie");
	cout << myEmptyDog.Name << endl;
	
	//Another demonstration of polymorphism. Snake class is using same Inherited method from Animal
	//but also has its own unique version.
	unknownSnake.setName("Python");
	cout << "Is the unknown snake named " << unknownSnake.Name << " Venomous?: " << unknownSnake.isVenomous() << endl; 
	cout << "Is the mean snake named " << meanSnake.Name << " Venomous?: " << meanSnake.isVenomous() << endl;
	cout << "Is the happy snake named " << happySnake.Name << " Venomous?: " << happySnake.isVenomous() << endl;
	
    return 0;
}