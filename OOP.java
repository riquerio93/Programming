class Animal {
    protected int id;
    protected String Name = "";
    protected boolean Aggressive;
    private String animalType = "";

    public Animal() {}

    public Animal(Animal a) {}

    public void setName(String name) {
        System.out.println("Setting Animal name to: " + name);
        this.Name = name;
    }

    public void setID(int id) {
        this.id = id;
    }

}

class Dog extends Animal {
    private String Breed;
    private boolean houseTrained;

    public Dog() {}

    public Dog(String name) {
        this.Name = name;
    }

    public void setName(String name) {
        System.out.println("Setting Dog's name to: " + name);
        this.Name = name;
    }

    public int getID() {
        return id;
    }
}

class Snake extends Animal {
    private String Breed;
    public boolean Venomous;

    public Snake() {}
    
    public Snake(String name) {
        this.Name = name;
    }
    
    public Snake(String name, boolean venomous) {
        this.Name = name;
        this.Venomous = venomous;
    }

    public String isVenomous() {
        if (Venomous)
            return "True";
        return "False";
    }

    public void setName(String name) {
        System.out.println("Setting Snake's name to: " + name);
        this.Name = name;
    }

    public int getID() {
        return id;
    }
}

 class Main {
    public static void main(String[] args) {
        Animal someAnimal = new Animal();
        Animal clonedAnimal = new Animal(someAnimal);
        Dog myEmptyDog = new Dog();
        Dog myNamedDog = new Dog("Sparky");
        Snake unknownSnake = new Snake();
        Snake meanSnake = new Snake("Mamba");
        Snake happySnake = new Snake("Noodle", false);

        someAnimal.setName("Bart");
        System.out.println(someAnimal.Name);
        clonedAnimal.setName("Lisa");
        System.out.println(clonedAnimal.Name);
        System.out.println(someAnimal.Name);

        System.out.println(myNamedDog.Name);
        System.out.println(myEmptyDog.Name);
        myEmptyDog.setName("Maggie");
        System.out.println(myEmptyDog.Name);

        unknownSnake.setName("Python");
        System.out.println("Is the unknown snake named " + unknownSnake.Name + " Venomous?: " + unknownSnake.isVenomous());
		meanSnake.Venomous = true;
        System.out.println("Is the mean snake named " + meanSnake.Name + " Venomous?: " + meanSnake.isVenomous());
        System.out.println("Is the happy snake named " + happySnake.Name + " Venomous?: " + happySnake.isVenomous());
    }
}