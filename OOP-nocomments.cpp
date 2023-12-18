#include <iostream>

using namespace std;

class Animal
{
    
    public:
        Animal();   
        Animal(const Animal& a);  
        ~Animal(); 
        
        virtual void setName(string Name) { 
            cout << "Setting Animal name to: " << Name << endl;
            this->Name = Name;
        }
        
        void setID(int id) { this->id = id; } 
        string Name = "";
        bool Aggressive;
        
    private:
        string animalType = "";
         
    protected:
        int id;
};


Animal::Animal(){}  
Animal::Animal(const Animal& a){} 
Animal::~Animal(){} 


class Dog: public Animal
{
    public:
        Dog(); 
        Dog(string Name); 
        
        void setName(string Name) { 
            cout << "Setting Dog's name to: " << Name << endl;
            this->Name = Name;
        }
        
        int getID() { return id; }
        bool houseTrained;
		
    private:
        string Breed;

};


Dog::Dog(){}
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
    Animal someAnimal;  
    Animal clonedAnimal(someAnimal); 
    Dog myEmptyDog;  
    Dog myNamedDog("Sparky");  
    Snake unknownSnake;
    Snake meanSnake("Mamba"); 
    Snake happySnake("Noodle", false); 
	
	someAnimal.setName("Bart");    
	cout << someAnimal.Name << endl;
	clonedAnimal.setName("Lisa");
	cout << clonedAnimal.Name << endl;
	cout << someAnimal.Name << endl;
	
	cout << myNamedDog.Name << endl;
	cout << myEmptyDog.Name << endl;
	myEmptyDog.setName("Maggie");
	cout << myEmptyDog.Name << endl;
	
	unknownSnake.setName("Python");
	cout << "Is the unknown snake named " << unknownSnake.Name << " Venomous?: " << unknownSnake.isVenomous() << endl; 
	cout << "Is the mean snake named " << meanSnake.Name << " Venomous?: " << meanSnake.isVenomous() << endl;
	cout << "Is the happy snake named " << happySnake.Name << " Venomous?: " << happySnake.isVenomous() << endl; 
    
    return 0;
}